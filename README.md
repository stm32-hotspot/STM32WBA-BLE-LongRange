# STM32WBA Long Range Connection 

Long range or LE coded feature is a way to extend BLE range up to 1,6 km or more.

Advertising extension feature is the way to activate advertising Primary (and secondary) PHY with new parameters values in HCI and ACI commands.
Based on BLE_p2pClient_Ext and BLE_p2pServer_Ext applications, two new applications have been developed to demonstrate the feature and to provide range measurements: BLE_App_Long_Range_Central and BLE_App_Long_Range_Peripheral.    
Two applications are included in the example.      

## Setup
These applications are running on two **NUCLEO-WBA55CGA boards**. 
Applications functionalities are derived from BLE_p2pClient and BLE_p2pServer applications. 
Once connected, the Server can receive message from the Client and send notification to it.  

At startup the BLE connection is established.
 - The peripheral device starts advertising.
 - B1 on central device starts scan and automatically connects to the peripheral (use of FW_ID_P2P_SERVER_LONG_RANGE).

## Application description
These applications are based on P2P server and P2P client from STM32CubeWBA package v1.2.0.   

On peripheral: 
- B1 sends a notification message toward connected Client device.
- B2 toggles LE coded PHY options (S=2 or S=8) only from peripheral to central. If S=8, red led is ON. 

On central:
- B1 write a message toward connected Server device. 
- B2 toggles LE coded PHY options (S=2 or S=8) only from central to peripheral. If S=8, red led is ON.

Change in PHY Coded option (S2 or S8) is not notified to remote device.

## Troubleshooting

**Caution** : Issues and the pull-requests are **not supported** to submit problems or suggestions related to the software delivered in this repository. The STM32WBA-BLE-Long-Range example is being delivered as-is, and not necessarily supported by ST.

**For any other question** related to the product, the hardware performance or characteristics, the tools, the environment, you can submit it to the **ST Community** on the STM32 MCUs related [page](https://community.st.com/s/topic/0TO0X000000BSqSWAW/stm32-mcus).
