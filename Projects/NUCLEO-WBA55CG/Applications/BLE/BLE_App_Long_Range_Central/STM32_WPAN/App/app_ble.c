/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_ble.c
  * @author  MCD Application Team
  * @brief   BLE Application
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "ble.h"
#include "app_ble.h"
#include "host_stack_if.h"
#include "ll_sys_if.h"
#include "stm32_seq.h"
#include "otp.h"
#include "stm32_timer.h"
#include "stm_list.h"
#include "advanced_memory_manager.h"
#include "blestack.h"
#include "nvm.h"
#include "simple_nvm_arbiter.h"
#include "gatt_client_app.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32wbaxx_nucleo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct
{
  uint8_t  Identifier;
  uint16_t L2CAP_Length;
  uint16_t Interval_Min;
  uint16_t Interval_Max;
  uint16_t Latency;
  uint16_t Timeout_Multiplier;
} APP_BLE_p2p_Conn_Update_req_t;
/* USER CODE END PTD */

/* Security parameters structure */
typedef struct
{
  /* IO capability of the device */
  uint8_t ioCapability;

  /**
   * Authentication requirement of the device
   * Man In the Middle protection required?
   */
  uint8_t mitm_mode;

  /* Bonding mode of the device */
  uint8_t bonding_mode;

  /**
   * this variable indicates whether to use a fixed pin
   * during the pairing process or a passkey has to be
   * requested to the application during the pairing process
   * 0 implies use fixed pin and 1 implies request for passkey
   */
  uint8_t Use_Fixed_Pin;

  /* Minimum encryption key size requirement */
  uint8_t encryptionKeySizeMin;

  /* Maximum encryption key size requirement */
  uint8_t encryptionKeySizeMax;

  /**
   * fixed pin to be used in the pairing process if
   * Use_Fixed_Pin is set to 1
   */
  uint32_t Fixed_Pin;

  /**
   * this flag indicates whether the host has to initiate
   * the security, wait for pairing or does not have any security
   * requirements.
   * 0x00 : no security required
   * 0x01 : host should initiate security by sending the slave security
   *        request command
   * 0x02 : host need not send the clave security request but it
   * has to wait for paiirng to complete before doing any other
   * processing
   */
  uint8_t initiateSecurity;
  /* USER CODE BEGIN tSecurityParams*/

  /* USER CODE END tSecurityParams */
}SecurityParams_t;

/* Global context contains all BLE common variables. */
typedef struct
{
  /* Security requirements of the host */
  SecurityParams_t bleSecurityParam;

  /* GAP service handle */
  uint16_t gapServiceHandle;

  /* Device name characteristic handle */
  uint16_t devNameCharHandle;

  /* Appearance characteristic handle */
  uint16_t appearanceCharHandle;

  /**
   * connection handle of the current active connection
   * When not in connection, the handle is set to 0xFFFF
   */
  uint16_t connectionHandle;

  /* USER CODE BEGIN BleGlobalContext_t*/

  /* USER CODE END BleGlobalContext_t */
}BleGlobalContext_t;

typedef struct
{
  BleGlobalContext_t BleApplicationContext_legacy;
  APP_BLE_ConnStatus_t Device_Connection_Status;
  /* USER CODE BEGIN PTD_1*/
  uint8_t deviceServerFound;
  uint8_t a_deviceServerBdAddr[BD_ADDR_SIZE];
  uint8_t a_deviceServerExtendedBdAddr[BD_ADDR_SIZE];
  uint8_t deviceServerExtendedAddressType;
  /* Led Timeout timerID */
  UTIL_TIMER_Object_t SwitchOffGPIO_timer_Id;
  /* USER CODE END PTD_1 */
}BleApplicationContext_t;

/* Private defines -----------------------------------------------------------*/
/* GATT buffer size (in bytes)*/
#define BLE_GATT_BUF_SIZE \
          BLE_TOTAL_BUFFER_SIZE_GATT(CFG_BLE_NUM_GATT_ATTRIBUTES, \
                                     CFG_BLE_NUM_GATT_SERVICES, \
                                     CFG_BLE_ATT_VALUE_ARRAY_SIZE)

#define MBLOCK_COUNT              (BLE_MBLOCKS_CALC(PREP_WRITE_LIST_SIZE, \
                                                    CFG_BLE_ATT_MTU_MAX, \
                                                    CFG_BLE_NUM_LINK) \
                                   + CFG_BLE_MBLOCK_COUNT_MARGIN)

#define BLE_DYN_ALLOC_SIZE \
        (BLE_TOTAL_BUFFER_SIZE(CFG_BLE_NUM_LINK, MBLOCK_COUNT))

/* USER CODE BEGIN PD */
#define L_BUFF_SIZE 256
#define LED_ON_TIMEOUT_MS              (5)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
static void Start_extended_scanning(void);
static void Stop_extended_scanning(void);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
static tListNode BleAsynchEventQueue;

static const uint8_t a_MBdAddr[BD_ADDR_SIZE] =
{
  (uint8_t)((CFG_BD_ADDRESS & 0x0000000000FF)),
  (uint8_t)((CFG_BD_ADDRESS & 0x00000000FF00) >> 8),
  (uint8_t)((CFG_BD_ADDRESS & 0x000000FF0000) >> 16),
  (uint8_t)((CFG_BD_ADDRESS & 0x0000FF000000) >> 24),
  (uint8_t)((CFG_BD_ADDRESS & 0x00FF00000000) >> 32),
  (uint8_t)((CFG_BD_ADDRESS & 0xFF0000000000) >> 40)
};

static uint8_t a_BdAddrUdn[BD_ADDR_SIZE];

/* Identity root key used to derive IRK and DHK(Legacy) */
static const uint8_t a_BLE_CfgIrValue[16] = CFG_BLE_IR;

/* Encryption root key used to derive LTK(Legacy) and CSRK */
static const uint8_t a_BLE_CfgErValue[16] = CFG_BLE_ER;
static BleApplicationContext_t bleAppContext;

GATT_CLIENT_APP_ConnHandle_Notif_evt_t clientHandleNotification;

static const char a_GapDeviceName[] = {  'S', 'T', 'M', '3', '2', 'W', 'B', 'A' }; /* Gap Device Name */

uint64_t buffer_nvm[CFG_BLEPLAT_NVM_MAX_SIZE] = {0};

static AMM_VirtualMemoryCallbackFunction_t APP_BLE_ResumeFlowProcessCb;

/* Host stack init variables */
static uint32_t buffer[DIVC(BLE_DYN_ALLOC_SIZE, 4)];
static uint32_t gatt_buffer[DIVC(BLE_GATT_BUF_SIZE, 4)];
static BleStack_init_t pInitParams;

/* USER CODE BEGIN PV */
APP_BLE_p2p_Conn_Update_req_t APP_BLE_p2p_Conn_Update_req;
char l_buff[L_BUFF_SIZE];
uint16_t l_buff_pos;
volatile uint8_t display_filter = 0;
volatile uint8_t scan_running = 0;
/* USER CODE END PV */

/* Global variables ----------------------------------------------------------*/

/* USER CODE BEGIN GV */

/* USER CODE END GV */

/* Private function prototypes -----------------------------------------------*/
static void BleStack_Process_BG(void);
static void Ble_UserEvtRx(void);
static void BLE_ResumeFlowProcessCallback(void);
static void Ble_Hci_Gap_Gatt_Init(void);
static const uint8_t* BleGetBdAddress(void);
static void gap_cmd_resp_wait(void);
static void gap_cmd_resp_release(void);
static void BLE_NvmCallback (SNVMA_Callback_Status_t);
static uint8_t  HOST_BLE_Init(void);
/* USER CODE BEGIN PFP */
static uint8_t analyse_ext_adv_report(hci_le_extended_advertising_report_event_rp0 *p_ext_adv_report);
static void connectRequestExt(void);
static void Switch_OFF_GPIO(void *arg);
/* USER CODE END PFP */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */
uint8_t toggle_flag = 0;
/* USER CODE END EV */

/* Functions Definition ------------------------------------------------------*/
void APP_BLE_Init(void)
{
  /* USER CODE BEGIN APP_BLE_Init_1 */

  /* USER CODE END APP_BLE_Init_1 */

  LST_init_head(&BleAsynchEventQueue);

  UTIL_SEQ_RegTask(1U << CFG_TASK_BLE_HOST, UTIL_SEQ_RFU, BleStack_Process_BG);
  UTIL_SEQ_RegTask(1U << CFG_TASK_HCI_ASYNCH_EVT_ID, UTIL_SEQ_RFU, Ble_UserEvtRx);

  /* NVM emulation in RAM initialization */
  NVM_Init(buffer_nvm, 0, CFG_BLEPLAT_NVM_MAX_SIZE);

  /* First register the APP BLE buffer */
  SNVMA_Register (APP_BLE_NvmBuffer,
                  (uint32_t *)buffer_nvm,
                  (CFG_BLEPLAT_NVM_MAX_SIZE * 2));

  /* Realize a restore */
  SNVMA_Restore (APP_BLE_NvmBuffer);
  /* USER CODE BEGIN APP_BLE_Init_Buffers */

  /* USER CODE END APP_BLE_Init_Buffers */

  /* Check consistency */
  if (NVM_Get (NVM_FIRST, 0xFF, 0, 0, 0) != NVM_EOF)
  {
    NVM_Discard (NVM_ALL);
  }

  /* Initialize the BLE Host */
  if (HOST_BLE_Init() == 0u)
  {
    /* Initialization of HCI & GATT & GAP layer */
    Ble_Hci_Gap_Gatt_Init();

    /* Initialization of the BLE Services */
    SVCCTL_Init();

    /**
     * Initialize GATT Client Application
     */
    GATT_CLIENT_APP_Init();
  }
  /* USER CODE BEGIN APP_BLE_Init_2 */
  UTIL_SEQ_RegTask( 1u << CFG_TASK_CONN_REQ_EXT_DEV_ID, UTIL_SEQ_RFU, connectRequestExt);

  /* Create timer to handle the Led Switch OFF */
  UTIL_TIMER_Create(&(bleAppContext.SwitchOffGPIO_timer_Id),
                  0,
                  (UTIL_TIMER_Mode_t)hw_ts_SingleShot,
                  &Switch_OFF_GPIO,
                  0);
  tBleStatus ret = BLE_STATUS_INVALID_PARAMS;
  ret = aci_hal_set_radio_activity_mask(0x0028);
  if (ret != BLE_STATUS_SUCCESS)
  {
    APP_DBG_MSG("  Fail   : aci_hal_set_radio_activity_mask command, result: 0x%2X\n", ret);
  }
  else
  {
    APP_DBG_MSG("  Success: aci_hal_set_radio_activity_mask command\n\r");
  }    
  /* USER CODE END APP_BLE_Init_2 */

  return;
}

SVCCTL_UserEvtFlowStatus_t SVCCTL_App_Notification(void *p_Pckt)
{
  tBleStatus ret = BLE_STATUS_ERROR;
  hci_event_pckt    *p_event_pckt;
  evt_le_meta_event *p_meta_evt;
  evt_blecore_aci   *p_blecore_evt;

  p_event_pckt = (hci_event_pckt*) ((hci_uart_pckt *) p_Pckt)->data;
  UNUSED(ret);
  /* USER CODE BEGIN SVCCTL_App_Notification */

  /* USER CODE END SVCCTL_App_Notification */

  switch (p_event_pckt->evt)
  {
    case HCI_DISCONNECTION_COMPLETE_EVT_CODE:
    {
      hci_disconnection_complete_event_rp0 *p_disconnection_complete_event;
      p_disconnection_complete_event = (hci_disconnection_complete_event_rp0 *) p_event_pckt->data;
      if (p_disconnection_complete_event->Connection_Handle == bleAppContext.BleApplicationContext_legacy.connectionHandle)
      {
        bleAppContext.BleApplicationContext_legacy.connectionHandle = 0;
        bleAppContext.Device_Connection_Status = APP_BLE_IDLE;
        LOG_INFO_APP(">>== HCI_DISCONNECTION_COMPLETE_EVT_CODE\n");
        LOG_INFO_APP("     - Connection Handle:   0x%02X\n     - Reason:    0x%02X\n",
                    p_disconnection_complete_event->Connection_Handle,
                    p_disconnection_complete_event->Reason);

        /* USER CODE BEGIN EVT_DISCONN_COMPLETE_2 */

        /* USER CODE END EVT_DISCONN_COMPLETE_2 */
      }
      gap_cmd_resp_release();

      /* USER CODE BEGIN EVT_DISCONN_COMPLETE_1 */

      /* USER CODE END EVT_DISCONN_COMPLETE_1 */
      break; /* HCI_DISCONNECTION_COMPLETE_EVT_CODE */
    }

    case HCI_LE_META_EVT_CODE:
    {
      p_meta_evt = (evt_le_meta_event*) p_event_pckt->data;
      /* USER CODE BEGIN EVT_LE_META_EVENT */

      /* USER CODE END EVT_LE_META_EVENT */
      switch (p_meta_evt->subevent)
      {
        case HCI_LE_CONNECTION_UPDATE_COMPLETE_SUBEVT_CODE:
        {
          uint16_t conn_interval_us = 0;
          hci_le_connection_update_complete_event_rp0 *p_conn_update_complete;
          p_conn_update_complete = (hci_le_connection_update_complete_event_rp0 *) p_meta_evt->data;
          conn_interval_us = p_conn_update_complete->Conn_Interval * 1250;
          LOG_INFO_APP(">>== HCI_LE_CONNECTION_UPDATE_COMPLETE_SUBEVT_CODE\n");
          LOG_INFO_APP("     - Connection Interval:   %d.%02d ms\n     - Connection latency:    %d\n     - Supervision Timeout:   %d ms\n",
                       conn_interval_us / 1000,
                       (conn_interval_us%1000) / 10,
                       p_conn_update_complete->Conn_Latency,
                       p_conn_update_complete->Supervision_Timeout*10);
          UNUSED(p_conn_update_complete);

          /* USER CODE BEGIN EVT_LE_CONN_UPDATE_COMPLETE */

          /* USER CODE END EVT_LE_CONN_UPDATE_COMPLETE */
          break;
        }
        case HCI_LE_PHY_UPDATE_COMPLETE_SUBEVT_CODE:
        {
          hci_le_phy_update_complete_event_rp0 *p_le_phy_update_complete;
          p_le_phy_update_complete = (hci_le_phy_update_complete_event_rp0*)p_meta_evt->data;
          UNUSED(p_le_phy_update_complete);

          gap_cmd_resp_release();

          /* USER CODE BEGIN EVT_LE_PHY_UPDATE_COMPLETE */
          APP_DBG_MSG(">>== HCI_LE_PHY_UPDATE_COMPLETE_SUBEVT_CODE\n");
          /* USER CODE END EVT_LE_PHY_UPDATE_COMPLETE */
          break;
        }
        case HCI_LE_ENHANCED_CONNECTION_COMPLETE_SUBEVT_CODE:
        {
          uint16_t conn_interval_us = 0;
          hci_le_enhanced_connection_complete_event_rp0 *p_enhanced_conn_complete;
          p_enhanced_conn_complete = (hci_le_enhanced_connection_complete_event_rp0 *) p_meta_evt->data;
          conn_interval_us = p_enhanced_conn_complete->Conn_Interval * 1250;
          LOG_INFO_APP(">>== HCI_LE_ENHANCED_CONNECTION_COMPLETE_SUBEVT_CODE - Connection handle: 0x%04X\n", p_enhanced_conn_complete->Connection_Handle);
          LOG_INFO_APP("     - Connection established with @:%02x:%02x:%02x:%02x:%02x:%02x\n",
                      p_enhanced_conn_complete->Peer_Address[5],
                      p_enhanced_conn_complete->Peer_Address[4],
                      p_enhanced_conn_complete->Peer_Address[3],
                      p_enhanced_conn_complete->Peer_Address[2],
                      p_enhanced_conn_complete->Peer_Address[1],
                      p_enhanced_conn_complete->Peer_Address[0]);
          LOG_INFO_APP("     - Connection Interval:   %d.%02d ms\n     - Connection latency:    %d\n     - Supervision Timeout:   %d ms\n",
                      conn_interval_us / 1000,
                      (conn_interval_us%1000) / 10,
                      p_enhanced_conn_complete->Conn_Latency,
                      p_enhanced_conn_complete->Supervision_Timeout * 10
                     );

          if (bleAppContext.Device_Connection_Status == APP_BLE_LP_CONNECTING)
          {
            /* Connection as client */
            bleAppContext.Device_Connection_Status = APP_BLE_CONNECTED_CLIENT;
          }
          else
          {
            /* Connection as server */
            bleAppContext.Device_Connection_Status = APP_BLE_CONNECTED_SERVER;
          }
          bleAppContext.BleApplicationContext_legacy.connectionHandle = p_enhanced_conn_complete->Connection_Handle;

          /* USER CODE BEGIN HCI_EVT_LE_ENHANCED_CONN_COMPLETE */

          GATT_CLIENT_APP_Set_Conn_Handle(0, p_enhanced_conn_complete->Connection_Handle);
          
          /* Discover services */
          if (bleAppContext.Device_Connection_Status == APP_BLE_CONNECTED_CLIENT)
          {
            UTIL_SEQ_SetTask(1U << CFG_TASK_DISCOVER_SERVICES_ID, CFG_SEQ_PRIO_0);
          }
          /* USER CODE END HCI_EVT_LE_ENHANCED_CONN_COMPLETE */
          break; /* HCI_LE_ENHANCED_CONNECTION_COMPLETE_SUBEVT_CODE */
        }
        case HCI_LE_CONNECTION_COMPLETE_SUBEVT_CODE:
        {
          uint16_t conn_interval_us = 0;
          hci_le_connection_complete_event_rp0 *p_conn_complete;
          p_conn_complete = (hci_le_connection_complete_event_rp0 *) p_meta_evt->data;
          conn_interval_us = p_conn_complete->Conn_Interval * 1250;
          LOG_INFO_APP(">>== HCI_LE_CONNECTION_COMPLETE_SUBEVT_CODE - Connection handle: 0x%04X\n", p_conn_complete->Connection_Handle);
          LOG_INFO_APP("     - Connection established with @:%02x:%02x:%02x:%02x:%02x:%02x\n",
                      p_conn_complete->Peer_Address[5],
                      p_conn_complete->Peer_Address[4],
                      p_conn_complete->Peer_Address[3],
                      p_conn_complete->Peer_Address[2],
                      p_conn_complete->Peer_Address[1],
                      p_conn_complete->Peer_Address[0]);
          LOG_INFO_APP("     - Connection Interval:   %d.%02d ms\n     - Connection latency:    %d\n     - Supervision Timeout:   %d ms\n",
                      conn_interval_us / 1000,
                      (conn_interval_us%1000) / 10,
                      p_conn_complete->Conn_Latency,
                      p_conn_complete->Supervision_Timeout * 10
                     );

          if (bleAppContext.Device_Connection_Status == APP_BLE_LP_CONNECTING)
          {
            /* Connection as client */
            bleAppContext.Device_Connection_Status = APP_BLE_CONNECTED_CLIENT;
          }
          else
          {
            /* Connection as server */
            bleAppContext.Device_Connection_Status = APP_BLE_CONNECTED_SERVER;
          }
          bleAppContext.BleApplicationContext_legacy.connectionHandle = p_conn_complete->Connection_Handle;

          GATT_CLIENT_APP_Set_Conn_Handle(0, p_conn_complete->Connection_Handle);

          /* USER CODE BEGIN HCI_EVT_LE_CONN_COMPLETE */
          /* Discover services */
          if (bleAppContext.Device_Connection_Status == APP_BLE_CONNECTED_CLIENT)
          {
            UTIL_SEQ_SetTask(1U << CFG_TASK_DISCOVER_SERVICES_ID, CFG_SEQ_PRIO_0);
          }
          /* USER CODE END HCI_EVT_LE_CONN_COMPLETE */
          break; /* HCI_LE_CONNECTION_COMPLETE_SUBEVT_CODE */
        }
        case HCI_LE_ADVERTISING_REPORT_SUBEVT_CODE:
        {
          hci_le_advertising_report_event_rp0 *p_adv_report;
          p_adv_report = (hci_le_advertising_report_event_rp0 *) p_meta_evt->data;
          UNUSED(p_adv_report);
          /* USER CODE BEGIN HCI_EVT_LE_ADVERTISING_REPORT */

          /* USER CODE END HCI_EVT_LE_ADVERTISING_REPORT */
          break; /* HCI_LE_ADVERTISING_REPORT_SUBEVT_CODE */
        }
        case HCI_LE_EXTENDED_ADVERTISING_REPORT_SUBEVT_CODE:
        {
          hci_le_extended_advertising_report_event_rp0 *p_ext_adv_report;
          p_ext_adv_report = (hci_le_extended_advertising_report_event_rp0 *) p_meta_evt->data;
          UNUSED(p_ext_adv_report);
          /* USER CODE BEGIN HCI_LE_EXTENDED_ADVERTISING_REPORT_SUBEVT_CODE */
          
          analyse_ext_adv_report(p_ext_adv_report);

          /* USER CODE END HCI_LE_EXTENDED_ADVERTISING_REPORT_SUBEVT_CODE */
          break; /* HCI_LE_EXTENDED_ADVERTISING_REPORT_SUBEVT_CODE */
        }
        /* USER CODE BEGIN SUBEVENT */

        /* USER CODE END SUBEVENT */
        default:
        {
          /* USER CODE BEGIN SUBEVENT_DEFAULT */

          /* USER CODE END SUBEVENT_DEFAULT */
          break;
        }
      }

      /* USER CODE BEGIN META_EVT */

      /* USER CODE END META_EVT */
    }
    break; /* HCI_LE_META_EVT_CODE */

    case HCI_VENDOR_SPECIFIC_DEBUG_EVT_CODE:
    {
      p_blecore_evt = (evt_blecore_aci*) p_event_pckt->data;
      /* USER CODE BEGIN EVT_VENDOR */

      /* USER CODE END EVT_VENDOR */
      switch (p_blecore_evt->ecode)
      {
        /* USER CODE BEGIN ECODE */

        /* USER CODE END ECODE */
        case ACI_L2CAP_CONNECTION_UPDATE_REQ_VSEVT_CODE:
        {
          aci_l2cap_connection_update_req_event_rp0 *p_l2cap_conn_update_req;
          uint8_t req_resp = 0x01;
          p_l2cap_conn_update_req = (aci_l2cap_connection_update_req_event_rp0 *) p_blecore_evt->data;
          UNUSED(p_l2cap_conn_update_req);

          /* USER CODE BEGIN EVT_L2CAP_CONNECTION_UPDATE_REQ */

          /* USER CODE END EVT_L2CAP_CONNECTION_UPDATE_REQ */

          ret = aci_l2cap_connection_parameter_update_resp(p_l2cap_conn_update_req->Connection_Handle,
                                                           p_l2cap_conn_update_req->Interval_Min,
                                                           p_l2cap_conn_update_req->Interval_Max,
                                                           p_l2cap_conn_update_req->Latency,
                                                           p_l2cap_conn_update_req->Timeout_Multiplier,
                                                           CONN_CE_LENGTH_MS(10),
                                                           CONN_CE_LENGTH_MS(10),
                                                           p_l2cap_conn_update_req->Identifier,
                                                           req_resp);
          if(ret != BLE_STATUS_SUCCESS)
          {
            LOG_INFO_APP("  Fail   : aci_l2cap_connection_parameter_update_resp command\n");
          }
          else
          {
            LOG_INFO_APP("  Success: aci_l2cap_connection_parameter_update_resp command\n");
          }

          break;
        }
        case ACI_GAP_PROC_COMPLETE_VSEVT_CODE:
        {
          aci_gap_proc_complete_event_rp0 *p_gap_proc_complete;
          p_gap_proc_complete = (aci_gap_proc_complete_event_rp0*) p_blecore_evt->data;
          UNUSED(p_gap_proc_complete);

          LOG_INFO_APP(">>== ACI_GAP_PROC_COMPLETE_VSEVT_CODE\n");
          /* USER CODE BEGIN EVT_GAP_PROCEDURE_COMPLETE */
          if ((p_gap_proc_complete->Procedure_Code == GAP_GENERAL_DISCOVERY_PROC) &&
              (p_gap_proc_complete->Status == 0x00))
          {
            APP_DBG_MSG("-- GAP_GENERAL_DISCOVERY_PROC completed\n");

            BSP_LED_Off(LED_BLUE);
            
            if(bleAppContext.Device_Connection_Status != APP_BLE_CONNECTED_CLIENT)
            {
              UTIL_SEQ_SetTask(1u << CFG_TASK_CONN_REQ_EXT_DEV_ID, CFG_SEQ_PRIO_0);
            }
            else
            {
              APP_DBG_MSG("==>> Device already connected\n");
            }
          }
          /* USER CODE END EVT_GAP_PROCEDURE_COMPLETE */
          break; /* ACI_GAP_PROC_COMPLETE_VSEVT_CODE */
        }
        case ACI_HAL_END_OF_RADIO_ACTIVITY_VSEVT_CODE:
        {
          /* USER CODE BEGIN RADIO_ACTIVITY_EVENT*/
          BSP_LED_On(LED_GREEN);
          UTIL_TIMER_StartWithPeriod(&bleAppContext.SwitchOffGPIO_timer_Id, LED_ON_TIMEOUT_MS);
          /* USER CODE END RADIO_ACTIVITY_EVENT*/
          break; /* ACI_HAL_END_OF_RADIO_ACTIVITY_VSEVT_CODE */
        }
        /* USER CODE BEGIN ECODE_1 */

        /* USER CODE END ECODE_1 */
        default:
        {
          /* USER CODE BEGIN ECODE_DEFAULT*/

          /* USER CODE END ECODE_DEFAULT*/
          break;
        }
      }
      /* USER CODE BEGIN EVT_VENDOR_1 */

      /* USER CODE END EVT_VENDOR_1 */
    }
    break; /* HCI_VENDOR_SPECIFIC_DEBUG_EVT_CODE */
    /* USER CODE BEGIN EVENT_PCKT */

    /* USER CODE END EVENT_PCKT */
    default:
    {
      /* USER CODE BEGIN EVENT_PCKT_DEFAULT*/

      /* USER CODE END EVENT_PCKT_DEFAULT*/
      break;
    }
  }
  /* USER CODE BEGIN SVCCTL_App_Notification_1 */

  /* USER CODE END SVCCTL_App_Notification_1 */

  return (SVCCTL_UserEvtFlowEnable);
}

APP_BLE_ConnStatus_t APP_BLE_Get_Client_Connection_Status(uint16_t Connection_Handle)
{
  APP_BLE_ConnStatus_t conn_status;

  if (bleAppContext.BleApplicationContext_legacy.connectionHandle == Connection_Handle)
  {
    conn_status = bleAppContext.Device_Connection_Status;
  }
  else
  {
    conn_status = APP_BLE_IDLE;
  }

  return conn_status;
}

void APP_BLE_Procedure_Gap_General(ProcGapGeneralId_t ProcGapGeneralId)
{
  tBleStatus status;
  uint8_t phy_tx, phy_rx;

  switch(ProcGapGeneralId)
  {
    case PROC_GAP_GEN_PHY_TOGGLE:
    {
      status = hci_le_read_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, &phy_tx, &phy_rx);
      if (status != BLE_STATUS_SUCCESS)
      {
        LOG_INFO_APP("hci_le_read_phy failure: reason=0x%02X\n",status);
      }
      else
      {
        LOG_INFO_APP("==>> hci_le_read_phy - Success\n");
        LOG_INFO_APP("==>> PHY Param  TX= %d, RX= %d\n", phy_tx, phy_rx);
        if ((phy_tx == HCI_TX_PHY_LE_2M) && (phy_rx == HCI_RX_PHY_LE_2M))
        {
          LOG_INFO_APP("==>> hci_le_set_phy PHY Param  TX= %d, RX= %d - ", HCI_TX_PHY_LE_1M, HCI_RX_PHY_LE_1M);
          status = hci_le_set_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, 0, HCI_TX_PHYS_LE_1M_PREF, HCI_RX_PHYS_LE_1M_PREF, 0);
          if (status != BLE_STATUS_SUCCESS)
          {
            LOG_INFO_APP("Fail\n");
          }
          else
          {
            LOG_INFO_APP("Success\n");
            gap_cmd_resp_wait();/* waiting for HCI_LE_PHY_UPDATE_COMPLETE_SUBEVT_CODE */
          }
        }
        else
        {
          LOG_INFO_APP("==>> hci_le_set_phy PHY Param  TX= %d, RX= %d - ", HCI_TX_PHYS_LE_2M_PREF, HCI_RX_PHYS_LE_2M_PREF);
          status = hci_le_set_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, 0, HCI_TX_PHYS_LE_2M_PREF, HCI_RX_PHYS_LE_2M_PREF, 0);
          if (status != BLE_STATUS_SUCCESS)
          {
            LOG_INFO_APP("Fail\n");
          }
          else
          {
            LOG_INFO_APP("Success\n");
            gap_cmd_resp_wait();/* waiting for HCI_LE_PHY_UPDATE_COMPLETE_SUBEVT_CODE */
          }
        }
      }
      break;
    }/* PROC_GAP_GEN_PHY_TOGGLE */
    case PROC_GAP_GEN_CONN_TERMINATE:
    {
      status = aci_gap_terminate(bleAppContext.BleApplicationContext_legacy.connectionHandle, HCI_REMOTE_USER_TERMINATED_CONNECTION_ERR_CODE);
      if (status != BLE_STATUS_SUCCESS)
      {
         LOG_INFO_APP("aci_gap_terminate failure: reason=0x%02X\n", status);
      }
      else
      {
        LOG_INFO_APP("==>> aci_gap_terminate : Success\n");
      }
      gap_cmd_resp_wait();/* waiting for HCI_DISCONNECTION_COMPLETE_EVT_CODE */
      break;
    }/* PROC_GAP_GEN_CONN_TERMINATE */
    case PROC_GATT_EXCHANGE_CONFIG:
    {
      status = aci_gatt_exchange_config(bleAppContext.BleApplicationContext_legacy.connectionHandle);
      if (status != BLE_STATUS_SUCCESS)
      {
        LOG_INFO_APP("aci_gatt_exchange_config failure: reason=0x%02X\n", status);
      }
      else
      {
        LOG_INFO_APP("==>> aci_gatt_exchange_config : Success\n");
      }
      break;
    }
    /* USER CODE BEGIN GAP_GENERAL */
    case PROC_GAP_GEN_LE_CODED_PHY_TOGGLE:
    {
      status = hci_le_read_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, &phy_tx, &phy_rx);
      if (status != BLE_STATUS_SUCCESS)
      {
        APP_DBG_MSG("hci_le_read_phy failure: reason=0x%02X\n",status);
      }
      else
      {
        APP_DBG_MSG("==>> hci_le_read_phy - Success\n");
        APP_DBG_MSG("==>> PHY Param  TX= %d, RX= %d\n", phy_tx, phy_rx);
        if ((phy_tx == HCI_TX_PHY_LE_CODED) && (phy_rx == HCI_TX_PHY_LE_CODED))
        {
          if (toggle_flag == 0)
          {
            APP_DBG_MSG("==>> hci_le_set_phy PHY Param  TX= %d, RX= %d - S = 2 ", HCI_TX_PHY_LE_CODED, HCI_TX_PHY_LE_CODED);
            status = hci_le_set_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, 0, HCI_TX_PHYS_LE_CODED_PREF, HCI_TX_PHYS_LE_CODED_PREF, 1);
            if (status != BLE_STATUS_SUCCESS)
            {
              APP_DBG_MSG("Fail\n");
            }
            else
            {
              BSP_LED_Off(LED_RED);
              APP_DBG_MSG("Success\n");
            }
          }
          else
          {
            APP_DBG_MSG("==>> hci_le_set_phy PHY Param  TX= %d, RX= %d - S = 8 ", HCI_TX_PHY_LE_CODED, HCI_TX_PHY_LE_CODED);
            status = hci_le_set_phy(bleAppContext.BleApplicationContext_legacy.connectionHandle, 0, HCI_TX_PHYS_LE_CODED_PREF, HCI_TX_PHYS_LE_CODED_PREF, 2);
            if (status != BLE_STATUS_SUCCESS)
            {
              APP_DBG_MSG("Fail\n");
            }
            else
            {
              BSP_LED_On(LED_RED);
              APP_DBG_MSG("Success\n");
            }
          }
        }
      }
      break;
    }/* PROC_GAP_GEN_LE_CODED_PHY_TOGGLE */
    /* USER CODE END GAP_GENERAL */
    default:
      break;
  }
  return;
}

void APP_BLE_Procedure_Gap_Central(ProcGapCentralId_t ProcGapCentralId)
{
  tBleStatus status;
  uint32_t paramA, paramB, paramC, paramD;

  UNUSED(paramA);
  UNUSED(paramB);
  UNUSED(paramC);
  UNUSED(paramD);

  /* First set parameters before calling ACI APIs, only if needed */
  switch(ProcGapCentralId)
  {
    case PROC_GAP_CENTRAL_SCAN_START:
    {
      paramA = SCAN_INT_MS(500);
      paramB = SCAN_WIN_MS(500);
      paramC = APP_BLE_SCANNING;

      break;
    }/* PROC_GAP_CENTRAL_SCAN_START */
    case PROC_GAP_CENTRAL_SCAN_TERMINATE:
    {
      paramA = 1;
      paramB = 1;
      paramC = APP_BLE_IDLE;

      break;
    }/* PROC_GAP_CENTRAL_SCAN_TERMINATE */
    default:
      break;
  }

  /* Call ACI APIs */
  switch(ProcGapCentralId)
  {
    case PROC_GAP_CENTRAL_SCAN_START:
    {
      status = aci_gap_start_general_discovery_proc(paramA, paramB, GAP_PUBLIC_ADDR, 0);

      if (status != BLE_STATUS_SUCCESS)
      {
        LOG_INFO_APP("aci_gap_start_general_discovery_proc - fail, result: 0x%02X\n", status);
      }
      else
      {
        bleAppContext.Device_Connection_Status = (APP_BLE_ConnStatus_t)paramC;
        LOG_INFO_APP("==>> aci_gap_start_general_discovery_proc - Success\n");
      }

      break;
    }/* PROC_GAP_CENTRAL_SCAN_START */
    case PROC_GAP_CENTRAL_SCAN_TERMINATE:
    {
      status = aci_gap_terminate_gap_proc(GAP_GENERAL_DISCOVERY_PROC);
      if (status != BLE_STATUS_SUCCESS)
      {
        LOG_INFO_APP("aci_gap_terminate_gap_proc - fail, result: 0x%02X\n",status);
      }
      else
      {
        bleAppContext.Device_Connection_Status = (APP_BLE_ConnStatus_t)paramC;
        LOG_INFO_APP("==>> aci_gap_terminate_gap_proc - Success\n");
      }
      break;
    }/* PROC_GAP_CENTRAL_SCAN_TERMINATE */

    default:
      break;
  }
  return;
}

/* USER CODE BEGIN FD*/
void APP_BLE_Procedure_Gap_Central_Ext(ProcGapCentralIdExt_t ProcGapCentralId_Ext)
{
  uint32_t paramA, paramB, paramC, paramD;

  UNUSED(paramA);
  UNUSED(paramB);
  UNUSED(paramC);
  UNUSED(paramD);

  /* First set parameters before calling ACI APIs, only if needed */
  switch(ProcGapCentralId_Ext)
  {
    case PROC_GAP_CENTRAL_SCAN_EXT_START:
    {
      paramA = SCAN_INT_MS(500);
      paramB = SCAN_WIN_MS(500);
      paramC = APP_BLE_SCANNING;

      break;
    }/* PROC_GAP_CENTRAL_SCAN_START */
    case PROC_GAP_CENTRAL_SCAN_EXT_TERMINATE:
    {
      paramA = 1;
      paramB = 1;
      paramC = APP_BLE_IDLE;

      break;
    }/* PROC_GAP_CENTRAL_SCAN_TERMINATE */
    default:
      break;
  }

  /* Call ACI APIs */
  switch(ProcGapCentralId_Ext)
  {
    case PROC_GAP_CENTRAL_SCAN_EXT_START:
    {
      Start_extended_scanning();
      break;
    }/* PROC_GAP_CENTRAL_SCAN_START */
    case PROC_GAP_CENTRAL_SCAN_EXT_TERMINATE:
    {
      Stop_extended_scanning();
      break;
    }/* PROC_GAP_CENTRAL_SCAN_TERMINATE */

    default:
      break;
  }
  return;
}

static void Start_extended_scanning(void){
  tBleStatus status;
  const Scan_Param_Phy_t scan_parameters = { 0, SCAN_INT_MS(500), 20 };
  
  status = aci_gap_ext_start_scan(0,
                                  GAP_GENERAL_DISCOVERY_PROC,
                                  CFG_BD_ADDRESS_TYPE,
                                  0x00, 0x03E8, 0x03E8, 0x02,
                                  HCI_INIT_PHYS_SCAN_CONN_LE_CODED,
                                  (const Scan_Param_Phy_t*) &scan_parameters);
  
  if (status != BLE_STATUS_SUCCESS) 
  {
    APP_DBG_MSG("aci_gap_ext_start_scan - fail, result: 0x%02X\n", status);
  } 
  else
  {
    APP_DBG_MSG("==>> aci_gap_ext_start_scan - Success\n");
  }
}

static void Stop_extended_scanning(void){
	tBleStatus status;
	status = hci_le_set_extended_scan_enable(0, 2, 1, 1);
	if (status != BLE_STATUS_SUCCESS) {
		APP_DBG_MSG("hci_le_set_extended_scan_enable DISABLE - fail, result: 0x%02X\n", status);
	} else {
		bleAppContext.Device_Connection_Status = (APP_BLE_ConnStatus_t) APP_BLE_IDLE;
		APP_DBG_MSG("==>> hci_le_set_extended_scan_enable DISABLE - Success\n");
	}
}
/* USER CODE END FD*/

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/
uint8_t HOST_BLE_Init(void)
{
  tBleStatus return_status = BLE_STATUS_FAILED;

  pInitParams.numAttrRecord           = CFG_BLE_NUM_GATT_ATTRIBUTES;
  pInitParams.numAttrServ             = CFG_BLE_NUM_GATT_SERVICES;
  pInitParams.attrValueArrSize        = CFG_BLE_ATT_VALUE_ARRAY_SIZE;
  pInitParams.prWriteListSize         = CFG_BLE_ATTR_PREPARE_WRITE_VALUE_SIZE;
  pInitParams.attMtu                  = CFG_BLE_ATT_MTU_MAX;
  pInitParams.max_coc_nbr             = CFG_BLE_COC_NBR_MAX;
  pInitParams.max_coc_mps             = CFG_BLE_COC_MPS_MAX;
  pInitParams.max_coc_initiator_nbr   = CFG_BLE_COC_INITIATOR_NBR_MAX;
  pInitParams.numOfLinks              = CFG_BLE_NUM_LINK;
  pInitParams.mblockCount             = CFG_BLE_MBLOCK_COUNT;
  pInitParams.bleStartRamAddress      = (uint8_t*)buffer;
  pInitParams.total_buffer_size       = BLE_DYN_ALLOC_SIZE;
  pInitParams.bleStartRamAddress_GATT = (uint8_t*)gatt_buffer;
  pInitParams.total_buffer_size_GATT  = BLE_GATT_BUF_SIZE;
  pInitParams.options                 = CFG_BLE_OPTIONS;
  pInitParams.debug                   = 0U;
/* USER CODE BEGIN HOST_BLE_Init_Params */

/* USER CODE END HOST_BLE_Init_Params */
  return_status = BleStack_Init(&pInitParams);
/* USER CODE BEGIN HOST_BLE_Init */

/* USER CODE END HOST_BLE_Init */
  return ((uint8_t)return_status);
}

static void Ble_Hci_Gap_Gatt_Init(void)
{
  uint8_t role;
  uint16_t gap_service_handle, gap_dev_name_char_handle, gap_appearance_char_handle;
  const uint8_t *p_bd_addr;
  uint16_t a_appearance[1] = {CFG_GAP_APPEARANCE};
  tBleStatus ret = BLE_STATUS_INVALID_PARAMS;

  /* USER CODE BEGIN Ble_Hci_Gap_Gatt_Init*/

  /* USER CODE END Ble_Hci_Gap_Gatt_Init*/

  LOG_INFO_APP("==>> Start Ble_Hci_Gap_Gatt_Init function\n");

  /* Write the BD Address */
  p_bd_addr = BleGetBdAddress();
  ret = aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET,
                                  CONFIG_DATA_PUBADDR_LEN,
                                  (uint8_t*) p_bd_addr);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_hal_write_config_data command - CONFIG_DATA_PUBADDR_OFFSET, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_hal_write_config_data command - CONFIG_DATA_PUBADDR_OFFSET\n");
    LOG_INFO_APP("  Public Bluetooth Address: %02x:%02x:%02x:%02x:%02x:%02x\n",p_bd_addr[5],p_bd_addr[4],p_bd_addr[3],p_bd_addr[2],p_bd_addr[1],p_bd_addr[0]);
  }

  /* Write Identity root key used to derive IRK and DHK(Legacy) */
  ret = aci_hal_write_config_data(CONFIG_DATA_IR_OFFSET, CONFIG_DATA_IR_LEN, (uint8_t*)a_BLE_CfgIrValue);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_hal_write_config_data command - CONFIG_DATA_IR_OFFSET, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_hal_write_config_data command - CONFIG_DATA_IR_OFFSET\n");
  }

  /* Write Encryption root key used to derive LTK and CSRK */
  ret = aci_hal_write_config_data(CONFIG_DATA_ER_OFFSET, CONFIG_DATA_ER_LEN, (uint8_t*)a_BLE_CfgErValue);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_hal_write_config_data command - CONFIG_DATA_ER_OFFSET, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_hal_write_config_data command - CONFIG_DATA_ER_OFFSET\n");
  }

  /* Set Transmission RF Power. */
  ret = aci_hal_set_tx_power_level(1, CFG_TX_POWER);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_hal_set_tx_power_level command, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_hal_set_tx_power_level command\n");
  }

  /* Initialize GATT interface */
  ret = aci_gatt_init();
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_gatt_init command, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_gatt_init command\n");
  }

  /* Initialize GAP interface */
  role = 0U;
  role |= GAP_CENTRAL_ROLE;

  /* USER CODE BEGIN Role_Mngt*/

  /* USER CODE END Role_Mngt */

  if (role > 0)
  {
    ret = aci_gap_init(role,
                       CFG_PRIVACY,
                       sizeof(a_GapDeviceName),
                       &gap_service_handle,
                       &gap_dev_name_char_handle,
                       &gap_appearance_char_handle);

    if (ret != BLE_STATUS_SUCCESS)
    {
      LOG_INFO_APP("  Fail   : aci_gap_init command, result: 0x%02X\n", ret);
    }
    else
    {
      LOG_INFO_APP("  Success: aci_gap_init command\n");
    }

    ret = aci_gatt_update_char_value(gap_service_handle,
                                     gap_dev_name_char_handle,
                                     0,
                                     sizeof(a_GapDeviceName),
                                     (uint8_t *) a_GapDeviceName);
    if (ret != BLE_STATUS_SUCCESS)
    {
      LOG_INFO_APP("  Fail   : aci_gatt_update_char_value - Device Name, result: 0x%02X\n", ret);
    }
    else
    {
      LOG_INFO_APP("  Success: aci_gatt_update_char_value - Device Name\n");
    }

    ret = aci_gatt_update_char_value(gap_service_handle,
                                     gap_appearance_char_handle,
                                     0,
                                     sizeof(a_appearance),
                                     (uint8_t *)&a_appearance);
    if (ret != BLE_STATUS_SUCCESS)
    {
      LOG_INFO_APP("  Fail   : aci_gatt_update_char_value - Appearance, result: 0x%02X\n", ret);
    }
    else
    {
      LOG_INFO_APP("  Success: aci_gatt_update_char_value - Appearance\n");
    }
  }
  else
  {
    LOG_ERROR_APP("GAP role cannot be null\n");
  }

  /* Initialize Default PHY */
  ret = hci_le_set_default_phy(CFG_PHY_PREF, CFG_PHY_PREF_TX, CFG_PHY_PREF_RX);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : hci_le_set_default_phy command, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: hci_le_set_default_phy command\n");
  }

  /* Initialize IO capability */
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.ioCapability = CFG_IO_CAPABILITY;
  ret = aci_gap_set_io_capability(bleAppContext.BleApplicationContext_legacy.bleSecurityParam.ioCapability);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_gap_set_io_capability command, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_gap_set_io_capability command\n");
  }

  /* Initialize authentication */
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.mitm_mode             = CFG_MITM_PROTECTION;
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.encryptionKeySizeMin  = CFG_ENCRYPTION_KEY_SIZE_MIN;
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.encryptionKeySizeMax  = CFG_ENCRYPTION_KEY_SIZE_MAX;
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.Use_Fixed_Pin         = CFG_USED_FIXED_PIN;
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.Fixed_Pin             = CFG_FIXED_PIN;
  bleAppContext.BleApplicationContext_legacy.bleSecurityParam.bonding_mode          = CFG_BONDING_MODE;
  /* USER CODE BEGIN Ble_Hci_Gap_Gatt_Init_1*/

  /* USER CODE END Ble_Hci_Gap_Gatt_Init_1*/

  ret = aci_gap_set_authentication_requirement(bleAppContext.BleApplicationContext_legacy.bleSecurityParam.bonding_mode,
                                               bleAppContext.BleApplicationContext_legacy.bleSecurityParam.mitm_mode,
                                               CFG_SC_SUPPORT,
                                               CFG_KEYPRESS_NOTIFICATION_SUPPORT,
                                               bleAppContext.BleApplicationContext_legacy.bleSecurityParam.encryptionKeySizeMin,
                                               bleAppContext.BleApplicationContext_legacy.bleSecurityParam.encryptionKeySizeMax,
                                               bleAppContext.BleApplicationContext_legacy.bleSecurityParam.Use_Fixed_Pin,
                                               bleAppContext.BleApplicationContext_legacy.bleSecurityParam.Fixed_Pin,
                                               CFG_BD_ADDRESS_TYPE);
  if (ret != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_gap_set_authentication_requirement command, result: 0x%02X\n", ret);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_gap_set_authentication_requirement command\n");
  }

  /* Initialize whitelist */
  if (bleAppContext.BleApplicationContext_legacy.bleSecurityParam.bonding_mode)
  {
    ret = aci_gap_configure_whitelist();
    if (ret != BLE_STATUS_SUCCESS)
    {
      LOG_INFO_APP("  Fail   : aci_gap_configure_whitelist command, result: 0x%02X\n", ret);
    }
    else
    {
      LOG_INFO_APP("  Success: aci_gap_configure_whitelist command\n");
    }
  }

  LOG_INFO_APP("==>> End Ble_Hci_Gap_Gatt_Init function\n");

  return;
}

static void Ble_UserEvtRx( void)
{
  SVCCTL_UserEvtFlowStatus_t svctl_return_status;
  BleEvtPacket_t *phcievt;

  LST_remove_head ( &BleAsynchEventQueue, (tListNode **)&phcievt );

  svctl_return_status = SVCCTL_UserEvtRx((void *)&(phcievt->evtserial));

  if (svctl_return_status != SVCCTL_UserEvtFlowDisable)
  {
    AMM_Free((uint32_t *)phcievt);
  }
  else
  {
    LST_insert_head ( &BleAsynchEventQueue, (tListNode *)phcievt );
  }

  if ((LST_is_empty(&BleAsynchEventQueue) == FALSE) && (svctl_return_status != SVCCTL_UserEvtFlowDisable) )
  {
    UTIL_SEQ_SetTask(1U << CFG_TASK_HCI_ASYNCH_EVT_ID, CFG_SEQ_PRIO_0);
  }

  /* set the BG_BleStack_Process task for scheduling */
  UTIL_SEQ_SetTask(1U << CFG_TASK_BLE_HOST, CFG_SEQ_PRIO_0);

}

static const uint8_t* BleGetBdAddress(void)
{
  OTP_Data_s *p_otp_addr = NULL;
  const uint8_t *p_bd_addr;
  uint32_t udn;
  uint32_t company_id;
  uint32_t device_id;

  udn = LL_FLASH_GetUDN();

  if (udn != 0xFFFFFFFF)
  {
    company_id = LL_FLASH_GetSTCompanyID();
    device_id = LL_FLASH_GetDeviceID();

    /**
     * Public Address with the ST company ID
     * bit[47:24] : 24bits (OUI) equal to the company ID
     * bit[23:16] : Device ID.
     * bit[15:0] : The last 16bits from the UDN
     * Note: In order to use the Public Address in a final product, a dedicated
     * 24bits company ID (OUI) shall be bought.
     */
    a_BdAddrUdn[0] = (uint8_t)(udn & 0x000000FF);
    a_BdAddrUdn[1] = (uint8_t)((udn & 0x0000FF00) >> 8);
    a_BdAddrUdn[2] = (uint8_t)device_id;
    a_BdAddrUdn[3] = (uint8_t)(company_id & 0x000000FF);
    a_BdAddrUdn[4] = (uint8_t)((company_id & 0x0000FF00) >> 8);
    a_BdAddrUdn[5] = (uint8_t)((company_id & 0x00FF0000) >> 16);

    p_bd_addr = (const uint8_t *)a_BdAddrUdn;
  }
  else
  {
    OTP_Read(0, &p_otp_addr);
    if (p_otp_addr)
    {
      p_bd_addr = (uint8_t*)(p_otp_addr->bd_address);
    }
    else
    {
      p_bd_addr = a_MBdAddr;
    }
  }

  return p_bd_addr;
}

static void BleStack_Process_BG(void)
{
  if (BleStack_Process( ) == 0x0)
  {
    BleStackCB_Process( );
  }
}

static void gap_cmd_resp_release(void)
{
  UTIL_SEQ_SetEvt(1U << CFG_IDLEEVT_PROC_GAP_COMPLETE);
  return;
}

static void gap_cmd_resp_wait(void)
{
  UTIL_SEQ_WaitEvt(1U << CFG_IDLEEVT_PROC_GAP_COMPLETE);
  return;
}

/**
  * @brief  Notify the LL to resume the flow process
  * @param  None
  * @retval None
  */
static void BLE_ResumeFlowProcessCallback(void)
{
  /* Receive any events from the LL. */
  change_state_options_t notify_options;

  notify_options.combined_value = 0x0F;

  ll_intf_chng_evnt_hndlr_state( notify_options );
}

static void BLE_NvmCallback (SNVMA_Callback_Status_t CbkStatus)
{
  if (CbkStatus != SNVMA_OPERATION_COMPLETE)
  {
    /* Retry the write operation */
    SNVMA_Write (APP_BLE_NvmBuffer,
                 BLE_NvmCallback);
  }
}

/* USER CODE BEGIN FD_LOCAL_FUNCTION */
static uint8_t analyse_ext_adv_report(hci_le_extended_advertising_report_event_rp0 *p_ext_adv_report)
{
  uint8_t status;
  
  if ((display_filter != 0) && HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0010))
  {
    status = 1;
  }
  else
  {
    status = 0;
    
    l_buff_pos = 0;
    memset(&l_buff[l_buff_pos], 0, L_BUFF_SIZE);          

    l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, 
                            "%02X:%02X:%02X:%02X:%02X:%02X | "
                            ,p_ext_adv_report->Address[5], p_ext_adv_report->Address[4]
                            ,p_ext_adv_report->Address[3] ,p_ext_adv_report->Address[2]
                            ,p_ext_adv_report->Address[1] ,p_ext_adv_report->Address[0]);
   
    if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0010))
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE, "LEGACY   |");
    }
    else
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE, "EXTENDED |");
    }
    
    l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "%4d | ",(int8_t)p_ext_adv_report->RSSI );
              
    if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0001))
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "CONN |");
    }
    else
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "     |");
    }
    
    if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0002))
    {
      if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0008))
      {
        l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "SCAN RSP |");
      }
      else
      {
        l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "SCAN     |");
      }
    }
    else
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "         |");
    }
    
    l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "%3d | ",p_ext_adv_report->Data_Length );
    
    if (p_ext_adv_report->Advertising_SID != 0xFF)
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "%2d | ",p_ext_adv_report->Advertising_SID );
    }
    
    if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0020))
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "more data   | ");
    }
    else if (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0040))
    {
      l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "trunc data | ");
    }
    else
    {
      /* Nothing to do */
    }          

    if( !(HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0010)) && /* extended */
        (HAL_IS_BIT_SET(p_ext_adv_report->Event_Type, 0x0001)) )   /* connectable */
    {
      uint8_t i, adtype, adlength;
      
      i = 0;
      while ( i < p_ext_adv_report->Data_Length )
      {
        adlength = p_ext_adv_report->Data[i];
        adtype = p_ext_adv_report->Data[i + 1];
        
        if ( adtype == AD_TYPE_MANUFACTURER_SPECIFIC_DATA )
        {
          if ( (adlength >= 7) && 
               (p_ext_adv_report->Data[i + 4] == 0x02) && /* blueST v2*/
               (p_ext_adv_report->Data[i + 6] == FW_ID_P2P_SERVER_LONG_RANGE))   /* p2pServer Long Range application */
          {
            l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "Long Range p2pServer detected, address recorded to connect. | ");

            bleAppContext.a_deviceServerExtendedBdAddr[0] = p_ext_adv_report->Address[0];
            bleAppContext.a_deviceServerExtendedBdAddr[1] = p_ext_adv_report->Address[1];
            bleAppContext.a_deviceServerExtendedBdAddr[2] = p_ext_adv_report->Address[2];
            bleAppContext.a_deviceServerExtendedBdAddr[3] = p_ext_adv_report->Address[3];
            bleAppContext.a_deviceServerExtendedBdAddr[4] = p_ext_adv_report->Address[4];
            bleAppContext.a_deviceServerExtendedBdAddr[5] = p_ext_adv_report->Address[5];
            bleAppContext.deviceServerExtendedAddressType = p_ext_adv_report->Address_Type;
            
            APP_DBG_MSG("     - Found Device @:%02x:%02x:%02x:%02x:%02x:%02x\n",
                      bleAppContext.a_deviceServerExtendedBdAddr[5],
                      bleAppContext.a_deviceServerExtendedBdAddr[4],
                      bleAppContext.a_deviceServerExtendedBdAddr[3],
                      bleAppContext.a_deviceServerExtendedBdAddr[2],
                      bleAppContext.a_deviceServerExtendedBdAddr[1],
                      bleAppContext.a_deviceServerExtendedBdAddr[0]);
            
            APP_DBG_MSG("Address type %d",bleAppContext.deviceServerExtendedAddressType);
            
            BSP_LED_On(LED_BLUE);

            bleAppContext.deviceServerFound = 0x01;
            if (bleAppContext.deviceServerFound == 1)
              aci_gap_terminate_gap_proc(GAP_GENERAL_DISCOVERY_PROC);
          }
        }
        i += adlength + 1;
      }
    }

    l_buff_pos += snprintf(&l_buff[l_buff_pos], L_BUFF_SIZE - l_buff_pos, "\n");
   
    APP_DBG_MSG("%s",l_buff);
  }
    
  return status;
}

static void connectRequestExt(void)
{
  tBleStatus result;
  Init_Param_Phy_t Init_Param_Phy[3];
  Init_Param_Phy[0].Scan_Interval       = SCAN_INT_MS(500);
  Init_Param_Phy[0].Scan_Window         = SCAN_WIN_MS(500);
  Init_Param_Phy[0].Conn_Interval_Min   = CONN_INT_MS(20);
  Init_Param_Phy[0].Conn_Interval_Max   = CONN_INT_MS(30);
  Init_Param_Phy[0].Conn_Latency        = 0;
  Init_Param_Phy[0].Supervision_Timeout = CONN_SUP_TIMEOUT_MS(5000);
  Init_Param_Phy[0].Min_CE_Length       = CONN_CE_LENGTH_MS(10);
  Init_Param_Phy[0].Max_CE_Length       = CONN_CE_LENGTH_MS(10);

  BSP_LED_Off(LED_BLUE);
  if (bleAppContext.deviceServerFound != 0x00)
  {
    APP_DBG_MSG("aci_gap_ext_create_connection\n");

    result = aci_gap_ext_create_connection(0x00, GAP_DIRECT_CONNECTION_ESTABLISHMENT_PROC,
                                       GAP_PUBLIC_ADDR,
                                       bleAppContext.deviceServerExtendedAddressType, 
                                       &bleAppContext.a_deviceServerExtendedBdAddr[0],
                                       0xFF, 0xFF, 0,
                                       HCI_INIT_PHYS_SCAN_CONN_LE_CODED,
                                       Init_Param_Phy);
    
    if (result == BLE_STATUS_SUCCESS)
    {
      bleAppContext.Device_Connection_Status = APP_BLE_LP_CONNECTING;
    }
    else
    {
      APP_DBG_MSG("==>> GAP Ext Create connection Failed , result: 0x%02x\n", result);
      bleAppContext.Device_Connection_Status = APP_BLE_IDLE;
    }
  }

  return;
}

uint8_t connection_update(void)
{
  tBleStatus result;
  Init_Param_Phy_t Init_Param_Phy[3];
  Init_Param_Phy[0].Scan_Interval       = SCAN_INT_MS(500);
  Init_Param_Phy[0].Scan_Window         = SCAN_WIN_MS(500);
  Init_Param_Phy[0].Conn_Interval_Min   = CONN_INT_MS(50);
  Init_Param_Phy[0].Conn_Interval_Max   = CONN_INT_MS(50);
  Init_Param_Phy[0].Conn_Latency        = 0;
  Init_Param_Phy[0].Supervision_Timeout = CONN_SUP_TIMEOUT_MS(5000);
  Init_Param_Phy[0].Min_CE_Length       = CONN_CE_LENGTH_MS(10);
  Init_Param_Phy[0].Max_CE_Length       = CONN_CE_LENGTH_MS(10);
  
  result = aci_gap_start_connection_update(bleAppContext.BleApplicationContext_legacy.connectionHandle,
                                           Init_Param_Phy[0].Conn_Interval_Min, Init_Param_Phy[0].Conn_Interval_Max,
                                           Init_Param_Phy[0].Conn_Latency,
                                           Init_Param_Phy[0].Supervision_Timeout,
                                           Init_Param_Phy[0].Min_CE_Length, Init_Param_Phy[0].Max_CE_Length);
  if (result == BLE_STATUS_SUCCESS)
  {
  }
  else
  {
    APP_DBG_MSG("==>> connection update Failed , result: 0x%02x\n", result);
  }
  
  return result;
}

/* USER CODE END FD_LOCAL_FUNCTION */

/*************************************************************
 *
 * WRAP FUNCTIONS
 *
 *************************************************************/

tBleStatus BLECB_Indication( const uint8_t* data,
                          uint16_t length,
                          const uint8_t* ext_data,
                          uint16_t ext_length )
{
  uint8_t status = BLE_STATUS_FAILED;
  BleEvtPacket_t *phcievt;
  uint16_t total_length = (length+ext_length);

  UNUSED(ext_data);

  if (data[0] == HCI_EVENT_PKT_TYPE)
  {
    APP_BLE_ResumeFlowProcessCb.Callback = BLE_ResumeFlowProcessCallback;
    if (AMM_Alloc (CFG_AMM_VIRTUAL_APP_BLE,
                   DIVC((sizeof(BleEvtPacketHeader_t) + total_length), sizeof (uint32_t)),
                   (uint32_t **)&phcievt,
                   &APP_BLE_ResumeFlowProcessCb) != AMM_ERROR_OK)
    {
      LOG_INFO_APP("Alloc failed\n");
      status = BLE_STATUS_FAILED;
    }
    else if (phcievt != (BleEvtPacket_t *)0 )
    {
      phcievt->evtserial.type = HCI_EVENT_PKT_TYPE;
      phcievt->evtserial.evt.evtcode = data[1];
      phcievt->evtserial.evt.plen  = data[2];
      memcpy( (void*)&phcievt->evtserial.evt.payload, &data[3], data[2]);
      LST_insert_tail(&BleAsynchEventQueue, (tListNode *)phcievt);
      UTIL_SEQ_SetTask(1U << CFG_TASK_HCI_ASYNCH_EVT_ID, CFG_SEQ_PRIO_0);
      status = BLE_STATUS_SUCCESS;
    }
  }
  else if (data[0] == HCI_ACLDATA_PKT_TYPE)
  {
    status = BLE_STATUS_SUCCESS;
  }
  return status;
}

void NVMCB_Store( const uint32_t* ptr, uint32_t size )
{
  UNUSED(ptr);
  UNUSED(size);

  /* Call SNVMA for storing - Without callback */
  SNVMA_Write (APP_BLE_NvmBuffer,
               BLE_NvmCallback);
}

/* USER CODE BEGIN FD_WRAP_FUNCTIONS */
#if (CFG_BUTTON_SUPPORTED == 1)
void APPE_Button1Action(void)
{
  if (bleAppContext.Device_Connection_Status != APP_BLE_CONNECTED_CLIENT)
  {
    if (scan_running == 1)
    {
      APP_BLE_Procedure_Gap_Central_Ext(PROC_GAP_CENTRAL_SCAN_EXT_TERMINATE);
      scan_running = 0;
    }
    else
    {
      APP_BLE_Procedure_Gap_Central_Ext(PROC_GAP_CENTRAL_SCAN_EXT_START);
    }
  }
  else
  {
    UTIL_SEQ_SetTask( 1u << CFG_TASK_P2PC_WRITE_CHAR_ID, CFG_SEQ_PRIO_0);
  }

  return;
}

void APPE_Button2Action(void)
{  
  toggle_flag = !toggle_flag;
  if (bleAppContext.Device_Connection_Status != APP_BLE_CONNECTED_CLIENT)
  {
  }
  else
  {
    APP_BLE_Procedure_Gap_General(PROC_GAP_GEN_LE_CODED_PHY_TOGGLE);
  }
  return;
}

#endif

static void Switch_OFF_GPIO(void *arg)
{
  BSP_LED_Off(LED_GREEN);
  return;
}
/* USER CODE END FD_WRAP_FUNCTIONS */
