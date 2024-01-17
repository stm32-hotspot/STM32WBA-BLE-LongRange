/**
  ******************************************************************************
  * @file    stm32wba50xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32WBA50xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
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
#ifndef STM32WBA50xx_H
#define STM32WBA50xx_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ST
  * @{
  */

/** @addtogroup STM32WBA50xx
  * @{
  */

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */
typedef enum
{
/* =======================================  ARM Cortex-M33 Specific Interrupt Numbers  ======================================= */
  Reset_IRQn                = -15,    /*!< -15 Reset Vector, invoked on Power up and warm reset              */
  NonMaskableInt_IRQn       = -14,    /*!< -14 Non maskable Interrupt, cannot be stopped or preempted        */
  HardFault_IRQn            = -13,    /*!< -13 Hard Fault, all classes of Fault                              */
  MemoryManagement_IRQn     = -12,    /*!< -12 Memory Management, MPU mismatch, including Access Violation
                                               and No Match                                                  */
  BusFault_IRQn             = -11,    /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                               related Fault                                                 */
  UsageFault_IRQn           = -10,    /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn          =  -9,    /*!< -9  Secure Fault                                                  */
  SVCall_IRQn               =  -5,    /*!< -5  System Service Call via SVC instruction                       */
  DebugMonitor_IRQn         =  -4,    /*!< -4  Debug Monitor                                                 */
  PendSV_IRQn               =  -2,    /*!< -2  Pendable request for system service                           */
  SysTick_IRQn              =  -1,    /*!< -1  System Tick Timer                                             */

/* ===========================================  STM32WBA50xx Specific Interrupt Numbers  ====================================== */
  WWDG_IRQn                 = 0,      /*!< Window WatchDog interrupt                                         */
  PVD_IRQn                  = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  RTC_IRQn                  = 2,      /*!< RTC non-secure interrupt                                          */
  TAMP_IRQn                 = 4,      /*!< Tamper global interrupt                                           */
  RAMCFG_IRQn               = 5,      /*!< RAMCFG global interrupt                                           */
  FLASH_IRQn                = 6,      /*!< FLASH non-secure global interrupt                                 */
  RCC_IRQn                  = 9,      /*!< RCC non secure global interrupt                                   */
  EXTI0_IRQn                = 11,     /*!< EXTI Line0 interrupt                                              */
  EXTI1_IRQn                = 12,     /*!< EXTI Line1 interrupt                                              */
  EXTI2_IRQn                = 13,     /*!< EXTI Line2 interrupt                                              */
  EXTI3_IRQn                = 14,     /*!< EXTI Line3 interrupt                                              */
  EXTI4_IRQn                = 15,     /*!< EXTI Line4 interrupt                                              */
  EXTI5_IRQn                = 16,     /*!< EXTI Line5 interrupt                                              */
  EXTI6_IRQn                = 17,     /*!< EXTI Line6 interrupt                                              */
  EXTI7_IRQn                = 18,     /*!< EXTI Line7 interrupt                                              */
  EXTI8_IRQn                = 19,     /*!< EXTI Line8 interrupt                                              */
  EXTI9_IRQn                = 20,     /*!< EXTI Line9 interrupt                                              */
  EXTI10_IRQn               = 21,     /*!< EXTI Line10 interrupt                                             */
  EXTI11_IRQn               = 22,     /*!< EXTI Line11 interrupt                                             */
  EXTI12_IRQn               = 23,     /*!< EXTI Line12 interrupt                                             */
  EXTI13_IRQn               = 24,     /*!< EXTI Line13 interrupt                                             */
  EXTI14_IRQn               = 25,     /*!< EXTI Line14 interrupt                                             */
  EXTI15_IRQn               = 26,     /*!< EXTI Line15 interrupt                                             */
  IWDG_IRQn                 = 27,     /*!< IWDG global interrupt                                             */
  GPDMA1_Channel0_IRQn      = 29,     /*!< GPDMA1 Channel 0 global interrupt                                 */
  GPDMA1_Channel1_IRQn      = 30,     /*!< GPDMA1 Channel 1 global interrupt                                 */
  GPDMA1_Channel2_IRQn      = 31,     /*!< GPDMA1 Channel 2 global interrupt                                 */
  GPDMA1_Channel3_IRQn      = 32,     /*!< GPDMA1 Channel 3 global interrupt                                 */
  GPDMA1_Channel4_IRQn      = 33,     /*!< GPDMA1 Channel 4 global interrupt                                 */
  GPDMA1_Channel5_IRQn      = 34,     /*!< GPDMA1 Channel 5 global interrupt                                 */
  GPDMA1_Channel6_IRQn      = 35,     /*!< GPDMA1 Channel 6 global interrupt                                 */
  GPDMA1_Channel7_IRQn      = 36,     /*!< GPDMA1 Channel 7 global interrupt                                 */
  TIM1_BRK_IRQn             = 37,     /*!< TIM1 Break interrupt                                              */
  TIM1_UP_IRQn              = 38,     /*!< TIM1 Update interrupt                                             */
  TIM1_TRG_COM_IRQn         = 39,     /*!< TIM1 Trigger and Commutation interrupt                            */
  TIM1_CC_IRQn              = 40,     /*!< TIM1 Capture Compare interrupt                                    */
  TIM2_IRQn                 = 41,     /*!< TIM2 global interrupt                                             */
  USART1_IRQn               = 46,     /*!< USART1 global interrupt                                           */
  LPUART1_IRQn              = 48,     /*!< LPUART1 global interrupt                                          */
  LPTIM1_IRQn               = 49,     /*!< LPTIM1 global interrupt                                           */
  TIM16_IRQn                = 51,     /*!< TIM16 global interrupt                                            */
  I2C3_EV_IRQn              = 54,     /*!< I2C3 Event interrupt                                              */
  I2C3_ER_IRQn              = 55,     /*!< I2C3 Error interrupt                                              */
  TSC_IRQn                  = 57,     /*!< Touch Sense Controller global interrupt                           */
  AES_IRQn                  = 58,     /*!< AES global interrupt                                              */
  RNG_IRQn                  = 59,     /*!< RNG global interrupt                                              */
  FPU_IRQn                  = 60,     /*!< FPU global interrupt                                              */
  HASH_IRQn                 = 61,     /*!< HASH global interrupt                                             */
  PKA_IRQn                  = 62,     /*!< PKA global interrupt                                              */
  SPI3_IRQn                 = 63,     /*!< SPI3 global interrupt                                             */
  ICACHE_IRQn               = 64,     /*!< Instruction cache global interrupt                                */
  ADC4_IRQn                 = 65,     /*!< ADC4 global interrupt                                             */
  RADIO_IRQn                = 66,     /*!< 2.4GHz RADIO global interrupt                                     */
  WKUP_IRQn                 = 67,     /*!< PWR global WKUP pin interrupt                                     */
  HSEM_IRQn                 = 68,     /*!< HSEM non-secure global interrupt                                  */
} IRQn_Type;


/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */
/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* --------  Configuration of the STM32WBAxx System On Chip ------ */

/* --------  Configuration of the Cortex-M33 Processor and Core Peripherals  ------ */
#define __CM33_REV                0x0000U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          4U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */

/** @} */ /* End of group Configuration_of_CMSIS */

#include <core_cm33.h>                   /*!< ARM Cortex-M33 processor and core peripherals */
#include "system_stm32wbaxx.h"           /*!< system_stm32wbaxx System */


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */
/** @addtogroup STM32WBAxx_peripherals
  * @{
  */

/**
  * @brief Analog to Digital Converter (ADC)
  */
typedef struct
{
  __IO uint32_t ISR;          /*!< ADC interrupt and status register,             Address offset: 0x00 */
  __IO uint32_t IER;          /*!< ADC interrupt enable register,                 Address offset: 0x04 */
  __IO uint32_t CR;           /*!< ADC control register,                          Address offset: 0x08 */
  __IO uint32_t CFGR1;        /*!< ADC configuration register 1,                  Address offset: 0x0C */
  __IO uint32_t CFGR2;        /*!< ADC configuration register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR;         /*!< ADC sampling time register,                    Address offset: 0x14 */
       uint32_t RESERVED0[2]; /*!< Reserved,                                      Address offset: 0x18-0x1C */
  __IO uint32_t AWD1TR;       /*!< ADC analog watchdog 1 threshold register,      Address offset: 0x20 */
  __IO uint32_t AWD2TR;       /*!< ADC watchdog threshold register,               Address offset: 0x24 */
  __IO uint32_t CHSELR;       /*!< ADC channel select register,                   Address offset: 0x28 */
  __IO uint32_t AWD3TR;       /*!< ADC watchdog threshold register,               Address offset: 0x02C */
       uint32_t RESERVED1[4]; /*!< Reserved,                                      Address offset: 0x30-0x3C */
  __IO uint32_t DR;           /*!< ADC group regular data register,               Address offset: 0x40 */
  __IO uint32_t PWRR;         /*!< ADC power register,                            Address offset: 0x44 */
       uint32_t RESERVED2[22];/*!< Reserved,                                      Address offset: 0x48-0x9C */
  __IO uint32_t AWD2CR;       /*!< ADC analog watchdog 2 configuration register,  Address offset: 0xA0 */
  __IO uint32_t AWD3CR;       /*!< ADC analog watchdog 3 configuration register,  Address offset: 0xA4 */
       uint32_t RESERVED3[7]; /*!< Reserved,                                      Address offset: 0xA8-0xC0 */
  __IO uint32_t CALFACT;      /*!< ADC Calibration factor register,               Address offset: 0xC4 */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CCR;          /*!< ADC common configuration register,             Address offset: 0x308 */
} ADC_Common_TypeDef;

/**
  * @brief CRC calculation unit
  */
typedef struct
{
  __IO uint32_t DR;             /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint32_t IDR;            /*!< CRC Independent data register,               Address offset: 0x04 */
  __IO uint32_t CR;             /*!< CRC Control register,                        Address offset: 0x08 */
       uint32_t RESERVED0;      /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;           /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;            /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief AES hardware accelerator
  */
typedef struct
{
  __IO uint32_t CR;          /*!< AES control register,                        Address offset: 0x00 */
  __IO uint32_t SR;          /*!< AES status register,                         Address offset: 0x04 */
  __IO uint32_t DINR;        /*!< AES data input register,                     Address offset: 0x08 */
  __IO uint32_t DOUTR;       /*!< AES data output register,                    Address offset: 0x0C */
  __IO uint32_t KEYR0;       /*!< AES key register 0,                          Address offset: 0x10 */
  __IO uint32_t KEYR1;       /*!< AES key register 1,                          Address offset: 0x14 */
  __IO uint32_t KEYR2;       /*!< AES key register 2,                          Address offset: 0x18 */
  __IO uint32_t KEYR3;       /*!< AES key register 3,                          Address offset: 0x1C */
  __IO uint32_t IVR0;        /*!< AES initialization vector register 0,        Address offset: 0x20 */
  __IO uint32_t IVR1;        /*!< AES initialization vector register 1,        Address offset: 0x24 */
  __IO uint32_t IVR2;        /*!< AES initialization vector register 2,        Address offset: 0x28 */
  __IO uint32_t IVR3;        /*!< AES initialization vector register 3,        Address offset: 0x2C */
  __IO uint32_t KEYR4;       /*!< AES key register 4,                          Address offset: 0x30 */
  __IO uint32_t KEYR5;       /*!< AES key register 5,                          Address offset: 0x34 */
  __IO uint32_t KEYR6;       /*!< AES key register 6,                          Address offset: 0x38 */
  __IO uint32_t KEYR7;       /*!< AES key register 7,                          Address offset: 0x3C */
  __IO uint32_t SUSP0R;      /*!< AES Suspend register 0,                      Address offset: 0x40 */
  __IO uint32_t SUSP1R;      /*!< AES Suspend register 1,                      Address offset: 0x44 */
  __IO uint32_t SUSP2R;      /*!< AES Suspend register 2,                      Address offset: 0x48 */
  __IO uint32_t SUSP3R;      /*!< AES Suspend register 3,                      Address offset: 0x4C */
  __IO uint32_t SUSP4R;      /*!< AES Suspend register 4,                      Address offset: 0x50 */
  __IO uint32_t SUSP5R;      /*!< AES Suspend register 5,                      Address offset: 0x54 */
  __IO uint32_t SUSP6R;      /*!< AES Suspend register 6,                      Address offset: 0x58 */
  __IO uint32_t SUSP7R;      /*!< AES Suspend register 7,                      Address offset: 0x5C */
       uint32_t RESERVED1[168];/*!< Reserved,                                  Address offset: 0x60 -- 0x2FC */
  __IO uint32_t IER;         /*!< AES Interrupt Enable Register,               Address offset: 0x300 */
  __IO uint32_t ISR;         /*!< AES Interrupt Status Register,               Address offset: 0x304 */
  __IO uint32_t ICR;         /*!< AES Interrupt Clear Register,                Address offset: 0x308 */
} AES_TypeDef;

/**
  * @brief Debug MCU
  */
typedef struct
{
  __IO uint32_t IDCODE;      /*!< MCU device ID code,                 Address offset: 0x00 */
  __IO uint32_t SCR;         /*!< Debug MCU status and configuration register,   Address offset: 0x04 */
  __IO uint32_t APB1LFZR;    /*!< Debug MCU APB1 freeze register 1,   Address offset: 0x08 */
  __IO uint32_t APB1HFZR;    /*!< Debug MCU APB1 freeze register 2,   Address offset: 0x0C */
  __IO uint32_t APB2FZR;     /*!< Debug MCU APB2 freeze register,     Address offset: 0x10 */
       uint32_t RESERVED1[4];/*!< Reserved,                                    0x14 - 0x20 */
  __IO uint32_t APB7FZR;     /*!< Debug MCU APB7 freeze register,     Address offset: 0x24 */
  __IO uint32_t AHB1FZR;     /*!< Debug MCU AHB1 freeze register,     Address offset: 0x28 */
} DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
       uint32_t RESERVED1[3]; /*!< Reserved,                                        Address offset: 0x00 - 0x8  */
  __IO uint32_t MISR;         /*!< DMA non secure masked interrupt status register, Address offset: 0x0C  */
       uint32_t RESERVED2[1]; /*!< Reserved,                                        Address offset: 0x10  */
} DMA_TypeDef;

typedef struct
{
  __IO uint32_t CLBAR;         /*!< DMA channel x linked-list base address register, Address offset: 0x50 + (x * 0x80) */
       uint32_t RESERVED1[2];  /*!< Reserved 1,                                      Address offset: 0x54 -- 0x58      */
  __IO uint32_t CFCR;          /*!< DMA channel x flag clear register,               Address offset: 0x5C + (x * 0x80) */
  __IO uint32_t CSR;           /*!< DMA channel x flag status register,              Address offset: 0x60 + (x * 0x80) */
  __IO uint32_t CCR;           /*!< DMA channel x control register,                  Address offset: 0x64 + (x * 0x80) */
       uint32_t RESERVED2[10]; /*!< Reserved 2,                                      Address offset: 0x68 -- 0x8C      */
  __IO uint32_t CTR1;          /*!< DMA channel x transfer register 1,               Address offset: 0x90 + (x * 0x80) */
  __IO uint32_t CTR2;          /*!< DMA channel x transfer register 2,               Address offset: 0x94 + (x * 0x80) */
  __IO uint32_t CBR1;          /*!< DMA channel x block register 1,                  Address offset: 0x98 + (x * 0x80) */
  __IO uint32_t CSAR;          /*!< DMA channel x source address register,           Address offset: 0x9C + (x * 0x80) */
  __IO uint32_t CDAR;          /*!< DMA channel x destination address register,      Address offset: 0xA0 + (x * 0x80) */
       uint32_t RESERVED3[10]; /*!< Reserved 3,                                      Address offset: 0xA4 -- 0xC8      */
  __IO uint32_t CLLR;          /*!< DMA channel x linked-list address register,      Address offset: 0xCC + (x * 0x80) */
} DMA_Channel_TypeDef;

/**
  * @brief Asynch Interrupt/Event Controller (EXTI)
  */
typedef struct
{
  __IO uint32_t RTSR1;          /*!< EXTI Rising Trigger Selection Register 1,        Address offset:   0x00 */
  __IO uint32_t FTSR1;          /*!< EXTI Falling Trigger Selection Register 1,       Address offset:   0x04 */
  __IO uint32_t SWIER1;         /*!< EXTI Software Interrupt event Register 1,        Address offset:   0x08 */
  __IO uint32_t RPR1;           /*!< EXTI Rising Pending Register 1,                  Address offset:   0x0C */
  __IO uint32_t FPR1;           /*!< EXTI Falling Pending Register 1,                 Address offset:   0x10 */
       uint32_t RESERVED1[19];  /*!< Reserved 1,                                                0x14 -- 0x5C */
  __IO uint32_t EXTICR[4];      /*!< EXIT External Interrupt Configuration Register,            0x60 -- 0x6C */
       uint32_t RESERVED2[4];   /*!< Reserved 2,                                                0x70 -- 0x7C */
  __IO uint32_t IMR1;           /*!< EXTI Interrupt Mask Register 1,                  Address offset:   0x80 */
  __IO uint32_t EMR1;           /*!< EXTI Event Mask Register 1,                      Address offset:   0x84 */
} EXTI_TypeDef;

/**
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;              /*!< FLASH access control register,                      Address offset: 0x00 */
       uint32_t RESERVED0;        /*!< RESERVED1,                                          Address offset: 0x04 */
  __IO uint32_t NSKEYR;           /*!< FLASH non-secure key register,                      Address offset: 0x08 */
       uint32_t RESERVED1;        /*!< Reserved1,                                          Address offset: 0x0C */
  __IO uint32_t OPTKEYR;          /*!< FLASH option key register,                          Address offset: 0x10 */
       uint32_t RESERVED2;        /*!< Reserved2,                                          Address offset: 0x14 */
  __IO uint32_t PDKEYR;           /*!< FLASH Bank power-down key register,                 Address offset: 0x18 */
       uint32_t RESERVED3;        /*!< Reserved3,                                          Address offset: 0x1C */
  __IO uint32_t NSSR;             /*!< FLASH non-secure status register,                   Address offset: 0x20 */
       uint32_t RESERVED4;        /*!< Reserved4,                                          Address offset: 0x24 */
  __IO uint32_t NSCR1;            /*!< FLASH non-secure control register,                  Address offset: 0x28 */
       uint32_t RESERVED5;        /*!< Reserved5,                                          Address offset: 0x2C */
  __IO uint32_t ECCR;             /*!< FLASH ECC register,                                 Address offset: 0x30 */
  __IO uint32_t OPSR;             /*!< FLASH OPSR register,                                Address offset: 0x34 */
  __IO uint32_t NSCR2;            /*!< FLASH non-secure control register,                  Address offset: 0x38 */
       uint32_t RESERVED6;        /*!< Reserved6,                                          Address offset: 0x3C */
  __IO uint32_t OPTR;             /*!< FLASH option control register,                      Address offset: 0x40 */
  __IO uint32_t NSBOOTADD0R;      /*!< FLASH non-secure boot address 0 register,           Address offset: 0x44 */
  __IO uint32_t NSBOOTADD1R;      /*!< FLASH non-secure boot address 1 register,           Address offset: 0x48 */
       uint32_t RESERVED7[3];     /*!< Reserved7,                                          Address offset: 0x4C-0x54 */
  __IO uint32_t WRPAR;            /*!< FLASH WRP area A address register,                  Address offset: 0x58 */
  __IO uint32_t WRPBR;            /*!< FLASH WRP area B address register,                  Address offset: 0x5C */
       uint32_t RESERVED8[4];     /*!< Reserved3,                                          Address offset: 0x60-0x6C */
  __IO uint32_t OEM1KEYR1;        /*!< FLASH OEM1 key register 1,                          Address offset: 0x70 */
  __IO uint32_t OEM1KEYR2;        /*!< FLASH OEM1 key register 2,                          Address offset: 0x74 */
  __IO uint32_t OEM2KEYR1;        /*!< FLASH OEM2 key register 1,                          Address offset: 0x78 */
  __IO uint32_t OEM2KEYR2;        /*!< FLASH OEM2 key register 2,                          Address offset: 0x7C */
} FLASH_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
  __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
       uint32_t RESERVED1;   /*!< RESERVED1,                             Address offset: 0x2C      */
} GPIO_TypeDef;

/**
  * @brief HASH
  */
typedef struct
{
  __IO uint32_t CR;               /*!< HASH control register,          Address offset: 0x00        */
  __IO uint32_t DIN;              /*!< HASH data input register,       Address offset: 0x04        */
  __IO uint32_t STR;              /*!< HASH start register,            Address offset: 0x08        */
  __IO uint32_t HR[5];            /*!< HASH digest registers,          Address offset: 0x0C-0x1C   */
  __IO uint32_t IMR;              /*!< HASH interrupt enable register, Address offset: 0x20        */
  __IO uint32_t SR;               /*!< HASH status register,           Address offset: 0x24        */
       uint32_t RESERVED0[52];    /*!< Reserved,                       Address offset: 0x28-0xF4   */
  __IO uint32_t CSR[54];          /*!< HASH context swap registers,    Address offset: 0x0F8-0x1CC */
} HASH_TypeDef;

/**
  * @brief HASH_DIGEST
  */
typedef struct
{
  __IO uint32_t HR[8];     /*!< HASH digest registers,          Address offset: 0x310-0x32C */
} HASH_DIGEST_TypeDef;

/**
  * @brief HW Semaphore HSEM
  */
typedef struct
{
  __IO uint32_t R[16];      /*!< HSEM 2-step write lock and read back registers, Address offset: 00h-3Ch   */
   uint32_t  Reserved1[16]; /*!< Reserved                                        Address offset: 40h-7Ch   */
  __IO uint32_t RLR[16];    /*!< HSEM 1-step read lock registers,                Address offset: 80h-BCh   */
   uint32_t  Reserved2[16]; /*!< Reserved                                        Address offset: C0h-FCh   */
  __IO uint32_t IER;        /*!< HSEM interrupt enable register,                 Address offset: 100h      */
  __IO uint32_t ICR;        /*!< HSEM interrupt clear register,                  Address offset: 104h      */
  __IO uint32_t ISR;        /*!< HSEM interrupt status register,                 Address offset: 108h      */
  __IO uint32_t MISR;       /*!< HSEM masked interrupt status register,          Address offset: 10Ch      */
   uint32_t  Reserved3[72]; /*!< Reserved                                        Address offset: 110h-22Ch */
  __IO uint32_t CR;         /*!< HSEM Semaphore clear register,                  Address offset: 230h      */
  __IO uint32_t KEYR;       /*!< HSEM Semaphore clear key register,              Address offset: 234h      */
} HSEM_TypeDef;

typedef struct
{
  __IO uint32_t IER;        /*!< HSEM interrupt enable register,                 Address offset:   0h      */
  __IO uint32_t ICR;        /*!< HSEM interrupt clear register,                  Address offset:   4h      */
  __IO uint32_t ISR;        /*!< HSEM interrupt status register,                 Address offset:   8h      */
  __IO uint32_t MISR;       /*!< HSEM masked interrupt status register,          Address offset:   Ch      */
} HSEM_Common_TypeDef;

/**
  * @brief Instruction Cache
  */
typedef struct
{
  __IO uint32_t CR;             /*!< ICACHE control register,                Address offset: 0x00 */
  __IO uint32_t SR;             /*!< ICACHE status register,                 Address offset: 0x04 */
  __IO uint32_t IER;            /*!< ICACHE interrupt enable register,       Address offset: 0x08 */
  __IO uint32_t FCR;            /*!< ICACHE Flag clear register,             Address offset: 0x0C */
  __IO uint32_t HMONR;          /*!< ICACHE hit monitor register,            Address offset: 0x10 */
  __IO uint32_t MMONR;          /*!< ICACHE miss monitor register,           Address offset: 0x14 */
       uint32_t RESERVED1[2];   /*!< Reserved,                               Address offset: 0x018-0x01C */
  __IO uint32_t CRR0;           /*!< ICACHE region 0 configuration register, Address offset: 0x20 */
  __IO uint32_t CRR1;           /*!< ICACHE region 1 configuration register, Address offset: 0x24 */
  __IO uint32_t CRR2;           /*!< ICACHE region 2 configuration register, Address offset: 0x28 */
  __IO uint32_t CRR3;           /*!< ICACHE region 3 configuration register, Address offset: 0x2C */
} ICACHE_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< I2C Control register 1,                         Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< I2C Control register 2,                         Address offset: 0x04 */
  __IO uint32_t OAR1;        /*!< I2C Own address 1 register,                     Address offset: 0x08 */
  __IO uint32_t OAR2;        /*!< I2C Own address 2 register,                     Address offset: 0x0C */
  __IO uint32_t TIMINGR;     /*!< I2C Timing register,                            Address offset: 0x10 */
  __IO uint32_t TIMEOUTR;    /*!< I2C Timeout register,                           Address offset: 0x14 */
  __IO uint32_t ISR;         /*!< I2C Interrupt and status register,              Address offset: 0x18 */
  __IO uint32_t ICR;         /*!< I2C Interrupt clear register,                   Address offset: 0x1C */
  __IO uint32_t PECR;        /*!< I2C PEC register,                               Address offset: 0x20 */
  __IO uint32_t RXDR;        /*!< I2C Receive data register,                      Address offset: 0x24 */
  __IO uint32_t TXDR;        /*!< I2C Transmit data register,                     Address offset: 0x28 */
  __IO uint32_t AUTOCR;      /*!< I2C Autonomous mode control register,           Address offset: 0x2C */
} I2C_TypeDef;

/**
  * @brief IWDG
  */
typedef struct
{
  __IO uint32_t KR;            /*!< IWDG Key register,          Address offset: 0x00 */
  __IO uint32_t PR;            /*!< IWDG Prescaler register,    Address offset: 0x04 */
  __IO uint32_t RLR;           /*!< IWDG Reload register,       Address offset: 0x08 */
  __IO uint32_t SR;            /*!< IWDG Status register,       Address offset: 0x0C */
  __IO uint32_t WINR;          /*!< IWDG Window register,       Address offset: 0x10 */
  __IO uint32_t EWCR;          /*!< IWDG Early Wakeup register, Address offset: 0x14 */
} IWDG_TypeDef;

/**
  * @brief LPTIMER
  */
typedef struct
{
  __IO uint32_t ISR;            /*!< LPTIM Interrupt and Status register,    Address offset: 0x00 */
  __IO uint32_t ICR;            /*!< LPTIM Interrupt Clear register,         Address offset: 0x04 */
  __IO uint32_t DIER;           /*!< LPTIM Interrupt Enable register,        Address offset: 0x08 */
  __IO uint32_t CFGR;           /*!< LPTIM Configuration register,           Address offset: 0x0C */
  __IO uint32_t CR;             /*!< LPTIM Control register,                 Address offset: 0x10 */
  __IO uint32_t CCR1;           /*!< LPTIM Capture/Compare register 1,       Address offset: 0x14 */
  __IO uint32_t ARR;            /*!< LPTIM Autoreload register,              Address offset: 0x18 */
  __IO uint32_t CNT;            /*!< LPTIM Counter register,                 Address offset: 0x1C */
  __IO uint32_t RESERVED0;      /*!< Reserved,                               Address offset: 0x20 */
  __IO uint32_t CFGR2;          /*!< LPTIM Configuration register 2,         Address offset: 0x24 */
  __IO uint32_t RCR;            /*!< LPTIM Repetition register,              Address offset: 0x28 */
  __IO uint32_t CCMR1;          /*!< LPTIM Capture/Compare mode register,    Address offset: 0x2C */
  __IO uint32_t RESERVED1;      /*!< Reserved,                               Address offset: 0x30 */
  __IO uint32_t CCR2;           /*!< LPTIM Capture/Compare register 2,       Address offset: 0x34 */
} LPTIM_TypeDef;

/**
  * @brief PKA
  */
typedef struct
{
  __IO uint32_t CR;            /*!< PKA control register,             Address offset: 0x00 */
  __IO uint32_t SR;            /*!< PKA status register,              Address offset: 0x04 */
  __IO uint32_t CLRFR;         /*!< PKA clear flag register,          Address offset: 0x08 */
  uint32_t Reserved[253];      /*!< Reserved memory area              Address offset: 0x0C  -> 0x03FC */
  __IO uint32_t RAM[1334];     /*!< PKA RAM                           Address offset: 0x400 -> 0x18D4 */
} PKA_TypeDef;

/**
  * @brief Power Control
  */
typedef struct
{
  __IO uint32_t CR1;           /*!< PWR power control register 1,                        Address offset: 0x00 */
  __IO uint32_t CR2;           /*!< PWR power control register 2,                        Address offset: 0x04 */
  __IO uint32_t CR3;           /*!< PWR power control register 3,                        Address offset: 0x08 */
  __IO uint32_t VOSR;          /*!< PWR voltage scaling register,                        Address offset: 0x0C */
  __IO uint32_t SVMCR;         /*!< PWR supply voltage monitoring control register,      Address offset: 0x10 */
  __IO uint32_t WUCR1;         /*!< PWR wakeup control register 1,                       Address offset: 0x14 */
  __IO uint32_t WUCR2;         /*!< PWR wakeup control register 2,                       Address offset: 0x18 */
  __IO uint32_t WUCR3;         /*!< PWR wakeup control register 3,                       Address offset: 0x1C */
  __IO uint32_t RESERVED0[2];  /*!< Reserved,                                            Address offset: 0x20 -- 0x24 */
  __IO uint32_t DBPR;          /*!< PWR disable backup domain register,                  Address offset: 0x28 */
       uint32_t RESERVED1[3];  /*!< Reserved,                                            Address offset: 0x2C -- 0x34 */
  __IO uint32_t SR;            /*!< PWR status register,                                 Address offset: 0x38 */
  __IO uint32_t SVMSR;         /*!< PWR supply voltage monitoring status register,       Address offset: 0x3C */
       uint32_t RESERVED2;     /*!< Reserved,                                            Address offset: 0x40 */
  __IO uint32_t WUSR;          /*!< PWR wakeup status register,                          Address offset: 0x44 */
  __IO uint32_t WUSCR;         /*!< PWR wakeup status clear register,                    Address offset: 0x48 */
  __IO uint32_t APCR;          /*!< PWR apply pull configuration register,               Address offset: 0x4C */
  __IO uint32_t IORETENRA;     /*!< PWR Port A IO retention in Standby register,         Address offset: 0x50 */
  __IO uint32_t IORETRA;       /*!< PWR Port A IO retention status in Standby register,  Address offset: 0x54 */
  __IO uint32_t IORETENRB;     /*!< PWR Port B IO retention in Standby register,         Address offset: 0x58 */
  __IO uint32_t IORETRB;       /*!< PWR Port B IO retention status in Standby register,  Address offset: 0x5C */
  __IO uint32_t IORETENRC;     /*!< PWR Port C IO retention in Standby register,         Address offset: 0x60 */
  __IO uint32_t IORETRC;       /*!< PWR Port C IO retention status in Standby register,  Address offset: 0x64 */
       uint32_t RESERVED3[8];  /*!< Reserved,                                            Address offset: 0x68 -- 0x84 */
  __IO uint32_t IORETENRH;     /*!< PWR Port H IO retention in Standby register,         Address offset: 0x88 */
  __IO uint32_t IORETRH;       /*!< PWR Port H IO retention status in Standby register,  Address offset: 0x8C */
       uint32_t RESERVED4[28]; /*!< Reserved,                                            Address offset: 0x90 -- 0xFC */
  __IO uint32_t RADIOSCR;      /*!< PWR 2.4 GHZ radio status and control register,       Address offset: 0x100 */
} PWR_TypeDef;

/**
  * @brief SRAMs configuration controller
  */
typedef struct
{
  __IO uint32_t CR;           /*!< Control Register,                  Address offset: 0x00 */
  __IO uint32_t IER;          /*!< Interrupt enable register,         Address offset: 0x04 */
  __IO uint32_t ISR;          /*!< Interrupt status register,         Address offset: 0x08 */
  uint32_t      RESERVED0;    /*!< Reserved,                          Address offset: 0x0C */
  __IO uint32_t PEAR;         /*!< Parity error address register,     Address offset: 0x10 */
  __IO uint32_t ICR;          /*!< Interrupt clear register,          Address offset: 0x14 */
  __IO uint32_t WPR1;         /*!< Write protection register 1,       Address offset: 0x18 */
  __IO uint32_t WPR2;         /*!< Write protection register 2,       Address offset: 0x1C */
  uint32_t      RESERVED1[2]; /*!< Reserved,                          Address offset: 0x20 -- 0x24 */
  __IO uint32_t ERKEYR;       /*!< Erase key register,                Address offset: 0x28 */
}RAMCFG_TypeDef;

/**
  * @brief Reset and Clock Control
  */
typedef struct
{
  __IO uint32_t CR;             /*!< RCC clock control register                             Address offset: 0x000 */
  uint32_t      RESERVED0[3];   /*!< Reserved                                                      0x004 -- 0x00C */
  __IO uint32_t ICSCR3;         /*!< RCC internal clock sources calibration register 3      Address offset: 0x010 */
  uint32_t      RESERVED1[2];   /*!< Reserved                                                      0x014 -- 0x018 */
  __IO uint32_t CFGR1;          /*!< RCC clock configuration register 1                     Address offset: 0x01C */
  __IO uint32_t CFGR2;          /*!< RCC clock configuration register 2                     Address offset: 0x020 */
  __IO uint32_t CFGR3;          /*!< RCC clock configuration register 3                     Address offset: 0x024 */
  __IO uint32_t PLL1CFGR;       /*!< PLL1 Configuration Register                            Address offset: 0x028 */
  uint32_t      RESERVED2[2];   /*!< Reserved                                                      0x02C -- 0x030 */
  __IO uint32_t PLL1DIVR;       /*!< PLL1 Dividers Configuration Register                   Address offset: 0x034 */
  __IO uint32_t PLL1FRACR;      /*!< PLL1 Fractional Divider Configuration Register         Address offset: 0x038 */
  uint32_t      RESERVED3[5];   /*!< Reserved                                                      0x03C -- 0x04C */
  __IO uint32_t CIER;           /*!< Clock Interrupt Enable Register                        Address offset: 0x050 */
  __IO uint32_t CIFR;           /*!< Clock Interrupt Flag Register                          Address offset: 0x054 */
  __IO uint32_t CICR;           /*!< Clock Interrupt Clear Register                         Address offset: 0x058 */
  uint32_t      RESERVED4;      /*!< Reserved                                               Address offset: 0x05C */
  __IO uint32_t AHB1RSTR;       /*!< AHB1 Peripherals Reset Register                        Address offset: 0x060 */
  __IO uint32_t AHB2RSTR;       /*!< AHB2 Peripherals Reset Register                        Address offset: 0x064 */
  uint32_t      RESERVED5;      /*!< Reserved                                               Address offset: 0x068 */
  __IO uint32_t AHB4RSTR;       /*!< AHB4 Peripherals Reset Register                        Address offset: 0x06C */
  __IO uint32_t AHB5RSTR;       /*!< AHB5 Peripherals Reset Register                        Address offset: 0x070 */
  __IO uint32_t APB1RSTR1;      /*!< APB1 Peripherals Reset Low Register                    Address offset: 0x074 */
  __IO uint32_t APB1RSTR2;      /*!< APB1 Peripherals Reset High Register                   Address offset: 0x078 */
  __IO uint32_t APB2RSTR;       /*!< APB2 Peripherals Reset Register                        Address offset: 0x07C */
  __IO uint32_t APB7RSTR;       /*!< APB7 Peripherals Reset Register                        Address offset: 0x080 */
  uint32_t      RESERVED6;      /*!< Reserved                                               Address offset: 0x084 */
  __IO uint32_t AHB1ENR;        /*!< AHB1 Peripherals Clock Enable Register                 Address offset: 0x088 */
  __IO uint32_t AHB2ENR;        /*!< AHB2 Peripherals Clock Enable Register                 Address offset: 0x08C */
  uint32_t      RESERVED7;      /*!< Reserved                                               Address offset: 0x090 */
  __IO uint32_t AHB4ENR;        /*!< AHB4 Peripherals Clock Enable Register                 Address offset: 0x094 */
  __IO uint32_t AHB5ENR;        /*!< AHB5 Peripherals Clock Enable Register                 Address offset: 0x098 */
  __IO uint32_t APB1ENR1;       /*!< APB1 Peripherals Clock Enable Low Register             Address offset: 0x09C */
  __IO uint32_t APB1ENR2;       /*!< APB1 Peripherals Clock Enable High Register            Address offset: 0x0A0 */
  __IO uint32_t APB2ENR;        /*!< APB2 Peripherals Clock Enable Register                 Address offset: 0x0A4 */
  __IO uint32_t APB7ENR;        /*!< APB7 Peripherals Clock Enable Register                 Address offset: 0x0A8 */
  uint32_t      RESERVED8;      /*!< Reserved                                               Address offset: 0x0AC */
  __IO uint32_t AHB1SMENR;      /*!< AHB1 Peripherals Clock Low Power Enable Register       Address offset: 0x0B0 */
  __IO uint32_t AHB2SMENR;      /*!< AHB2 Peripherals Clock Low Power Enable Register       Address offset: 0x0B4 */
  uint32_t      RESERVED9;      /*!< Reserved                                               Address offset: 0x0B8 */
  __IO uint32_t AHB4SMENR;      /*!< AHB4 Peripherals Clock Low Power Enable Register       Address offset: 0x0BC */
  __IO uint32_t AHB5SMENR;      /*!< AHB5 Peripherals Clock Low Power Enable Register       Address offset: 0x0C0 */
  __IO uint32_t APB1SMENR1;     /*!< APB1 Peripherals Clock Low Power Enable Low Register   Address offset: 0x0C4 */
  __IO uint32_t APB1SMENR2;     /*!< APB1 Peripherals Clock Low Power Enable High Register  Address offset: 0x0C8 */
  __IO uint32_t APB2SMENR;      /*!< APB2 Peripherals Clock Low Power Enable Register       Address offset: 0x0CC */
  __IO uint32_t APB7SMENR;      /*!< APB7 Peripherals Clock Low Power Enable Register       Address offset: 0x0D0 */
  uint32_t      RESERVED10[3];  /*!< Reserved                                                      0x0D4 -- 0x0DC */
  __IO uint32_t CCIPR1;         /*!< IPs Clocks Configuration Register 1                    Address offset: 0x0E0 */
  __IO uint32_t CCIPR2;         /*!< IPs Clocks Configuration Register 2                    Address offset: 0x0E4 */
  __IO uint32_t CCIPR3;         /*!< IPs Clocks Configuration Register 3                    Address offset: 0x0E8 */
  uint32_t      RESERVED11;     /*!< Reserved,                                              Address offset: 0x0EC */
  __IO uint32_t BDCR1;          /*!< Backup Domain Control Register 1                       Address offset: 0x0F0 */
  __IO uint32_t CSR;            /*!< V33 Clock Control & Status Register                    Address offset: 0x0F4 */
  __IO uint32_t BDCR2;          /*!< Backup Domain Control Register 2                       Address offset: 0x0F8 */
  uint32_t      RESERVED12[5];  /*!< Reserved                                                     0x0FC -- 0x010C */
  __IO uint32_t SECCFGR;        /*!< RCC secure configuration register                      Address offset: 0x110 */
  __IO uint32_t PRIVCFGR;       /*!< RCC privilege configuration register                   Address offset: 0x114 */
  uint32_t      RESERVED13[58]; /*!< Reserved                                                      0x118 -- 0x1FC */
  __IO uint32_t CFGR4;          /*!< RCC clock configuration register 4                     Address offset: 0x200 */
  uint32_t      RESERVED15;     /*!< Reserved                                               Address offset: 0x204 */
  __IO uint32_t RADIOENR;       /*!< RCC RADIO peripheral clock enable register             Address offset: 0x208 */
  uint32_t      RESERVED16;     /*!< Reserved                                               Address offset: 0x20C */
  __IO uint32_t ECSCR1;         /*!< RCC external clock sources calibration register 1      Address offset: 0x210 */
} RCC_TypeDef;

/**
  * @brief RNG
  */
typedef struct
{
  __IO uint32_t CR;    /*!< RNG control register, Address offset: 0x00 */
  __IO uint32_t SR;    /*!< RNG status register,  Address offset: 0x04 */
  __IO uint32_t DR;    /*!< RNG data register,    Address offset: 0x08 */
  uint32_t RESERVED;
  __IO uint32_t HTCR;  /*!< RNG health test configuration register, Address offset: 0x10 */
} RNG_TypeDef;

/*
* @brief RTC Specific device feature definitions
*/
#define RTC_BKP_NB         32U
#define RTC_BACKUP_NB      RTC_BKP_NB

#define RTC_TAMP_NB        3U

/**
  * @brief Real-Time Clock
  */
typedef struct
{
  __IO uint32_t TR;          /*!< RTC time register,                              Address offset: 0x00 */
  __IO uint32_t DR;          /*!< RTC date register,                              Address offset: 0x04 */
  __IO uint32_t SSR;         /*!< RTC sub second register,                        Address offset: 0x08 */
  __IO uint32_t ICSR;        /*!< RTC initialization control and status register, Address offset: 0x0C */
  __IO uint32_t PRER;        /*!< RTC prescaler register,                         Address offset: 0x10 */
  __IO uint32_t WUTR;        /*!< RTC wakeup timer register,                      Address offset: 0x14 */
  __IO uint32_t CR;          /*!< RTC control register,                           Address offset: 0x18 */
       uint32_t RESERVED0[2];/*!< Reserved,                                       Address offset: 0x1C-0x20 */
  __IO uint32_t WPR;         /*!< RTC write protection register,                  Address offset: 0x24 */
  __IO uint32_t CALR;        /*!< RTC calibration register,                       Address offset: 0x28 */
  __IO uint32_t SHIFTR;      /*!< RTC shift control register,                     Address offset: 0x2C */
  __IO uint32_t TSTR;        /*!< RTC time stamp time register,                   Address offset: 0x30 */
  __IO uint32_t TSDR;        /*!< RTC time stamp date register,                   Address offset: 0x34 */
  __IO uint32_t TSSSR;       /*!< RTC time-stamp sub second register,             Address offset: 0x38 */
       uint32_t RESERVED1;   /*!< Reserved,                                       Address offset: 0x3C */
  __IO uint32_t ALRMAR;      /*!< RTC alarm A register,                           Address offset: 0x40 */
  __IO uint32_t ALRMASSR;    /*!< RTC alarm A sub second register,                Address offset: 0x44 */
  __IO uint32_t ALRMBR;      /*!< RTC alarm B register,                           Address offset: 0x48 */
  __IO uint32_t ALRMBSSR;    /*!< RTC alarm B sub second register,                Address offset: 0x4C */
  __IO uint32_t SR;          /*!< RTC Status register,                            Address offset: 0x50 */
  __IO uint32_t MISR;        /*!< RTC masked interrupt status register,           Address offset: 0x54 */
       uint32_t RESERVED2;   /*!< Reserved,                                       Address offset: 0x58 */
  __IO uint32_t SCR;         /*!< RTC status Clear register,                      Address offset: 0x5C */
       uint32_t RESERVED3[4];/*!< Reserved,                                       Address offset: 0x58 */
  __IO uint32_t ALRABINR;    /*!< RTC alarm A binary mode register,               Address offset: 0x70 */
  __IO uint32_t ALRBBINR;    /*!< RTC alarm B binary mode register,               Address offset: 0x74 */
} RTC_TypeDef;

/**
  * @brief SPI
  */
typedef struct
{
  __IO uint32_t CR1;           /*!< SPI/I2S Control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;           /*!< SPI Control register 2,                          Address offset: 0x04 */
  __IO uint32_t CFG1;          /*!< SPI Configuration register 1,                    Address offset: 0x08 */
  __IO uint32_t CFG2;          /*!< SPI Configuration register 2,                    Address offset: 0x0C */
  __IO uint32_t IER;           /*!< SPI Interrupt Enable register,                   Address offset: 0x10 */
  __IO uint32_t SR;            /*!< SPI Status register,                             Address offset: 0x14 */
  __IO uint32_t IFCR;          /*!< SPI Interrupt/Status Flags Clear register,       Address offset: 0x18 */
  __IO uint32_t AUTOCR;        /*!< SPI Autonomous Mode Control register,            Address offset: 0x1C */
  __IO uint32_t TXDR;          /*!< SPI Transmit data register,                      Address offset: 0x20 */
  uint32_t      RESERVED1[3];  /*!< Reserved, 0x24-0x2C                                                   */
  __IO uint32_t RXDR;          /*!< SPI/I2S data register,                           Address offset: 0x30 */
  uint32_t      RESERVED2[3];  /*!< Reserved, 0x34-0x3C                                                   */
  __IO uint32_t CRCPOLY;       /*!< SPI CRC Polynomial register,                     Address offset: 0x40 */
  __IO uint32_t TXCRC;         /*!< SPI Transmitter CRC register,                    Address offset: 0x44 */
  __IO uint32_t RXCRC;         /*!< SPI Receiver CRC register,                       Address offset: 0x48 */
  __IO uint32_t UDRDR;         /*!< SPI Underrun data register,                      Address offset: 0x4C */
} SPI_TypeDef;

/**
  * @brief System configuration controller
  */
typedef struct
{
  __IO uint32_t SECCFGR;      /*!< SYSCFG secure configuration register,            Address offset: 0x00 */
  __IO uint32_t CFGR1;        /*!< SYSCFG configuration register 1,                 Address offset: 0x04 */
  __IO uint32_t FPUIMR;       /*!< SYSCFG FPU interrupt mask register,              Address offset: 0x08 */
  __IO uint32_t CNSLCKR;      /*!< SYSCFG CPU non-secure lock register,             Address offset: 0x0C */
  __IO uint32_t CSLCKR;       /*!< SYSCFG CPU secure lock register,                 Address offset: 0x10 */
  __IO uint32_t CFGR2;        /*!< SYSCFG configuration register 2,                 Address offset: 0x14 */
  __IO uint32_t MESR;         /*!< SYSCFG Memory Erase Status register,             Address offset: 0x18 */
  __IO uint32_t CCCSR;        /*!< SYSCFG Conpensaion Cell Control&Status register, Address offset: 0x1C */
  __IO uint32_t CCVR;         /*!< SYSCFG Conpensaion Cell value register,          Address offset: 0x20 */
  __IO uint32_t CCCR;         /*!< SYSCFG Conpensaion Cell Code register,           Address offset: 0x24 */
       uint32_t RESERVED1;    /*!< RESERVED1,                                       Address offset: 0x28 */
  __IO uint32_t RSSCMDR;      /*!< SYSCFG RSS command mode register,                Address offset: 0x2C */
} SYSCFG_TypeDef;

/**
  * @brief Tamper and backup registers
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< TAMP configuration register 1,                    Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TAMP configuration register 2,                    Address offset: 0x04 */
  __IO uint32_t CR3;         /*!< TAMP configuration register 3,                    Address offset: 0x08 */
  __IO uint32_t FLTCR;       /*!< TAMP filter control register,                     Address offset: 0x0C */
  __IO uint32_t ATCR1;       /*!< TAMP filter control register 1                    Address offset: 0x10 */
  __IO uint32_t ATSEEDR;     /*!< TAMP active tamper seed register,                 Address offset: 0x14 */
  __IO uint32_t ATOR;        /*!< TAMP active tamper output register,               Address offset: 0x18 */
  __IO uint32_t ATCR2;       /*!< TAMP filter control register 2,                   Address offset: 0x1C */
       uint32_t RESERVED0[3];/*!< Reserved,                                         Address offset: 0x20-0x28 */
  __IO uint32_t IER;         /*!< TAMP interrupt enable register,                   Address offset: 0x2C */
  __IO uint32_t SR;          /*!< TAMP status register,                             Address offset: 0x30 */
  __IO uint32_t MISR;        /*!< TAMP masked interrupt status register,            Address offset: 0x34 */
       uint32_t RESERVED1;   /*!< Reserved,                                         Address offset: 0x38 */
  __IO uint32_t SCR;         /*!< TAMP status clear register,                       Address offset: 0x3C */
  __IO uint32_t COUNT1R;     /*!< TAMP monotonic counter 1 register,                Address offset: 0x40 */
       uint32_t RESERVED2[47];/*!< Reserved,                                        Address offset: 0x58 -- 0xFC */
  __IO uint32_t BKP0R;       /*!< TAMP backup register 0,                   Address offset: 0x100 */
  __IO uint32_t BKP1R;       /*!< TAMP backup register 1,                   Address offset: 0x104 */
  __IO uint32_t BKP2R;       /*!< TAMP backup register 2,                   Address offset: 0x108 */
  __IO uint32_t BKP3R;       /*!< TAMP backup register 3,                   Address offset: 0x10C */
  __IO uint32_t BKP4R;       /*!< TAMP backup register 4,                   Address offset: 0x110 */
  __IO uint32_t BKP5R;       /*!< TAMP backup register 5,                   Address offset: 0x114 */
  __IO uint32_t BKP6R;       /*!< TAMP backup register 6,                   Address offset: 0x118 */
  __IO uint32_t BKP7R;       /*!< TAMP backup register 7,                   Address offset: 0x11C */
  __IO uint32_t BKP8R;       /*!< TAMP backup register 8,                   Address offset: 0x120 */
  __IO uint32_t BKP9R;       /*!< TAMP backup register 9,                   Address offset: 0x124 */
  __IO uint32_t BKP10R;      /*!< TAMP backup register 10,                  Address offset: 0x128 */
  __IO uint32_t BKP11R;      /*!< TAMP backup register 11,                  Address offset: 0x12C */
  __IO uint32_t BKP12R;      /*!< TAMP backup register 12,                  Address offset: 0x130 */
  __IO uint32_t BKP13R;      /*!< TAMP backup register 13,                  Address offset: 0x134 */
  __IO uint32_t BKP14R;      /*!< TAMP backup register 14,                  Address offset: 0x138 */
  __IO uint32_t BKP15R;      /*!< TAMP backup register 15,                  Address offset: 0x13C */
  __IO uint32_t BKP16R;      /*!< TAMP backup register 16,                  Address offset: 0x140 */
  __IO uint32_t BKP17R;      /*!< TAMP backup register 17,                  Address offset: 0x144 */
  __IO uint32_t BKP18R;      /*!< TAMP backup register 18,                  Address offset: 0x148 */
  __IO uint32_t BKP19R;      /*!< TAMP backup register 19,                  Address offset: 0x14C */
  __IO uint32_t BKP20R;      /*!< TAMP backup register 20,                  Address offset: 0x150 */
  __IO uint32_t BKP21R;      /*!< TAMP backup register 21,                  Address offset: 0x154 */
  __IO uint32_t BKP22R;      /*!< TAMP backup register 22,                  Address offset: 0x158 */
  __IO uint32_t BKP23R;      /*!< TAMP backup register 23,                  Address offset: 0x15C */
  __IO uint32_t BKP24R;      /*!< TAMP backup register 24,                  Address offset: 0x160 */
  __IO uint32_t BKP25R;      /*!< TAMP backup register 25,                  Address offset: 0x164 */
  __IO uint32_t BKP26R;      /*!< TAMP backup register 26,                  Address offset: 0x168 */
  __IO uint32_t BKP27R;      /*!< TAMP backup register 27,                  Address offset: 0x16C */
  __IO uint32_t BKP28R;      /*!< TAMP backup register 28,                  Address offset: 0x170 */
  __IO uint32_t BKP29R;      /*!< TAMP backup register 29,                  Address offset: 0x174 */
  __IO uint32_t BKP30R;      /*!< TAMP backup register 30,                  Address offset: 0x178 */
  __IO uint32_t BKP31R;      /*!< TAMP backup register 31,                  Address offset: 0x17C */
} TAMP_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,        Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                            Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
  __IO uint32_t CCR5;        /*!< TIM capture/compare register 5,           Address offset: 0x48 */
  __IO uint32_t CCR6;        /*!< TIM capture/compare register 6,           Address offset: 0x4C */
  __IO uint32_t CCMR3;       /*!< TIM capture/compare mode register 3,      Address offset: 0x50 */
  __IO uint32_t DTR2;        /*!< TIM deadtime register 2,                  Address offset: 0x54 */
  __IO uint32_t ECR;         /*!< TIM encoder control register,             Address offset: 0x58 */
  __IO uint32_t TISEL;       /*!< TIM Input Selection register,             Address offset: 0x5C */
  __IO uint32_t AF1;         /*!< TIM alternate function option register 1, Address offset: 0x60 */
  __IO uint32_t AF2;         /*!< TIM alternate function option register 2, Address offset: 0x64 */
  __IO uint32_t OR;          /*!< TIM option register,                      Address offset: 0x68 */
       uint32_t RESERVED0[220];/*!< Reserved,                               Address offset: 0x68-0x3D8 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,                 Address offset: 0x3DC */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,        Address offset: 0x3E0 */
} TIM_TypeDef;

/**
  * @brief TSC
  */
typedef struct
{
  __IO uint32_t CR;            /*!< TSC Control register,                            Address offset: 0x00 */
  __IO uint32_t IER;           /*!< TSC Interrupt Enable register,                   Address offset: 0x04 */
  __IO uint32_t ICR;           /*!< TSC Interrupt Control register,                  Address offset: 0x08 */
  __IO uint32_t ISR;           /*!< TSC Interrupt Status register,                   Address offset: 0x0C */
  __IO uint32_t IOHCR;         /*!< TSC I/O hysteresis control register,             Address offset: 0x10 */
  uint32_t      RESERVED0;     /*!< Reserved,                                        Address offset: 0x14 */
  __IO uint32_t IOASCR;        /*!< TSC I/O analog switch control register,          Address offset: 0x18 */
  uint32_t      RESERVED1;     /*!< Reserved,                                        Address offset: 0x1C */
  __IO uint32_t IOSCR;         /*!< TSC I/O sampling control register,               Address offset: 0x20 */
  uint32_t      RESERVED2;     /*!< Reserved,                                        Address offset: 0x24 */
  __IO uint32_t IOCCR;         /*!< TSC I/O channel control register,                Address offset: 0x28 */
  uint32_t      RESERVED3;     /*!< Reserved,                                        Address offset: 0x2C */
  __IO uint32_t IOGCSR;        /*!< TSC I/O group control status register,           Address offset: 0x30 */
  __IO uint32_t IOGXCR[6];     /*!< TSC I/O group x counter register,                Address offset: 0x34-48 */
} TSC_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< USART Control register 1,                 Address offset: 0x00  */
  __IO uint32_t CR2;         /*!< USART Control register 2,                 Address offset: 0x04  */
  __IO uint32_t CR3;         /*!< USART Control register 3,                 Address offset: 0x08  */
  __IO uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x0C  */
  __IO uint32_t GTPR;        /*!< USART Guard time and prescaler register,  Address offset: 0x10  */
  __IO uint32_t RTOR;        /*!< USART Receiver Time Out register,         Address offset: 0x14  */
  __IO uint32_t RQR;         /*!< USART Request register,                   Address offset: 0x18  */
  __IO uint32_t ISR;         /*!< USART Interrupt and status register,      Address offset: 0x1C  */
  __IO uint32_t ICR;         /*!< USART Interrupt flag Clear register,      Address offset: 0x20  */
  __IO uint32_t RDR;         /*!< USART Receive Data register,              Address offset: 0x24  */
  __IO uint32_t TDR;         /*!< USART Transmit Data register,             Address offset: 0x28  */
  __IO uint32_t PRESC;       /*!< USART Prescaler register,                 Address offset: 0x2C  */
  __IO uint32_t AUTOCR;      /*!< USART Autonomous mode control register    Address offset: 0x30  */
} USART_TypeDef;

/**
  * @brief WWDG
  */
typedef struct
{
  __IO uint32_t CR;          /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;         /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;          /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;

/*@}*/ /* end of group STM32WBA50xx_Peripherals */

/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
/** @addtogroup STM32WBAxx_Peripheral_peripheralAddr
  * @{
  */

/* Flash, Peripheral and internal SRAMs base addresses - Non secure */
#define FLASH_BASE_NS                   0x08000000UL  /*!< FLASH non-secure base address                      */
#define SYSTEM_FLASH_BASE_NS            0x0BF88000UL  /*!< System FLASH non-secure base address               */
#define SRAM1_BASE_NS                   0x20000000UL  /*!< SRAM1 non-secure base address                      */
#define SRAM2_BASE_NS                   0x20010000UL  /*!< SRAM2 non-secure base address                      */
#define SRAM6_BASE_NS                   0x48028000UL  /*!< 2.4 GHz RADIO TXRX SRAM non-secure base address    */
#define SEQSRAM_BASE_NS                 0x48021000UL  /*!< SRAM Sequence / retention non-secure base address  */
#define PERIPH_BASE_NS                  0x40000000UL  /*!< Peripheral non-secure base address                 */
#define DBGMCU_BASE                     0xE0044000UL  /*!< Debug MCU registers base address                   */

/*!< Memory sizes */
/* Internal Flash size */
#define FLASH_SIZE                      ((((*((uint16_t *)FLASHSIZE_BASE)) == 0xFFFFU)) ? 0x100000U : \
                                         ((((*((uint16_t *)FLASHSIZE_BASE)) == 0x0000U)) ? 0x100000U : \
                                           (((uint32_t)(*((uint16_t *)FLASHSIZE_BASE)) & (0xFFFFU)) << 10U)))

/* Internal SRAMs size */
#define SRAM1_SIZE                      0x00004000UL  /*!< SRAM1 = 16 Kbytes */
#define SRAM2_SIZE                      0x0000C000UL  /*!< SRAM2 = 48 Kbytes */
#define SRAM6_SIZE                      0x00004000UL  /*!< 2.4 GHz RADIO TXRX SRAM 16 Kbytes   */
#define SEQSRAM_SIZE                    0x00000200UL  /*!< SRAM Sequence / retention 512 bytes */

/*!< OTP, Engineering bytes, Option bytes defines */
#define FLASH_OTP_BASE                  (SYSTEM_FLASH_BASE_NS + 0x00008000UL)
#define FLASH_OTP_SIZE                  0x00000200U  /*!< 512 bytes OTP (one-time programmable)          */

#define FLASH_ENGY_BASE                 (SYSTEM_FLASH_BASE_NS + 0x00008500UL)
#define PACKAGE_BASE                    (FLASH_ENGY_BASE)                 /*!< Package data register base address     */
#define UID_BASE                        (FLASH_ENGY_BASE + 0x00000200UL)  /*!< Unique device ID register base address */
#define FLASHSIZE_BASE                  (FLASH_ENGY_BASE + 0x000002A0UL)  /*!< Flash size data register base address  */
#define UID64_BASE                      (FLASH_ENGY_BASE + 0x00000500UL)  /*!< 64-bit Unique device Identification    */

/* Peripheral memory map - Non secure */
#define APB1PERIPH_BASE_NS              PERIPH_BASE_NS
#define APB2PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x00010000UL)
#define AHB1PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x00020000UL)
#define AHB2PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x02020000UL)
#define APB7PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x06000000UL)
#define AHB4PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x06020000UL)
#define AHB5PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x08020000UL)

/*!< APB1 Non secure peripherals */
#define TIM2_BASE_NS                    APB1PERIPH_BASE_NS
#define WWDG_BASE_NS                    (APB1PERIPH_BASE_NS + 0x2C00UL)
#define IWDG_BASE_NS                    (APB1PERIPH_BASE_NS + 0x3000UL)

/*!< APB2 Non secure peripherals */
#define TIM1_BASE_NS                    (APB2PERIPH_BASE_NS + 0x2C00UL)
#define USART1_BASE_NS                  (APB2PERIPH_BASE_NS + 0x3800UL)
#define TIM16_BASE_NS                   (APB2PERIPH_BASE_NS + 0x4400UL)

/*!< AHB1 Non secure peripherals */
#define GPDMA1_BASE_NS                  AHB1PERIPH_BASE_NS
#define FLASH_R_BASE_NS                 (AHB1PERIPH_BASE_NS + 0x02000UL)
#define CRC_BASE_NS                     (AHB1PERIPH_BASE_NS + 0x03000UL)
#define TSC_BASE_NS                     (AHB1PERIPH_BASE_NS + 0x04000UL)
#define RAMCFG_BASE_NS                  (AHB1PERIPH_BASE_NS + 0x06000UL)
#define ICACHE_BASE_NS                  (AHB1PERIPH_BASE_NS + 0x10400UL)

#define GPDMA1_Channel0_BASE_NS         (GPDMA1_BASE_NS + 0x0050UL)
#define GPDMA1_Channel1_BASE_NS         (GPDMA1_BASE_NS + 0x00D0UL)
#define GPDMA1_Channel2_BASE_NS         (GPDMA1_BASE_NS + 0x0150UL)
#define GPDMA1_Channel3_BASE_NS         (GPDMA1_BASE_NS + 0x01D0UL)
#define GPDMA1_Channel4_BASE_NS         (GPDMA1_BASE_NS + 0x0250UL)
#define GPDMA1_Channel5_BASE_NS         (GPDMA1_BASE_NS + 0x02D0UL)
#define GPDMA1_Channel6_BASE_NS         (GPDMA1_BASE_NS + 0x0350UL)
#define GPDMA1_Channel7_BASE_NS         (GPDMA1_BASE_NS + 0x03D0UL)

#define RAMCFG_SRAM1_BASE_NS            (RAMCFG_BASE_NS)
#define RAMCFG_SRAM2_BASE_NS            (RAMCFG_BASE_NS + 0x0040UL)
#define RAMCFG_SRAM6_BASE_NS            (RAMCFG_BASE_NS + 0x0140UL)

/*!< AHB2 Non secure peripherals */
#define GPIOA_BASE_NS                   AHB2PERIPH_BASE_NS
#define GPIOB_BASE_NS                   (AHB2PERIPH_BASE_NS + 0x00400UL)
#define GPIOC_BASE_NS                   (AHB2PERIPH_BASE_NS + 0x00800UL)
#define GPIOH_BASE_NS                   (AHB2PERIPH_BASE_NS + 0x01C00UL)
#define AES_BASE_NS                     (AHB2PERIPH_BASE_NS + 0xA0000UL)
#define HASH_BASE_NS                    (AHB2PERIPH_BASE_NS + 0xA0400UL)
#define HASH_DIGEST_BASE_NS             (AHB2PERIPH_BASE_NS + 0xA0710UL)
#define RNG_BASE_NS                     (AHB2PERIPH_BASE_NS + 0xA0800UL)
#define HSEM_BASE_NS                    (AHB2PERIPH_BASE_NS + 0xA1C00UL)
#define PKA_BASE_NS                     (AHB2PERIPH_BASE_NS + 0xA2000UL)
#define PKA_RAM_BASE_NS                 (AHB2PERIPH_BASE_NS + 0xA2400UL)

/*!< APB7 Non secure peripherals */
#define SYSCFG_BASE_NS                  (APB7PERIPH_BASE_NS + 0x0400UL)
#define SPI3_BASE_NS                    (APB7PERIPH_BASE_NS + 0x2000UL)
#define LPUART1_BASE_NS                 (APB7PERIPH_BASE_NS + 0x2400UL)
#define I2C3_BASE_NS                    (APB7PERIPH_BASE_NS + 0x2800UL)
#define LPTIM1_BASE_NS                  (APB7PERIPH_BASE_NS + 0x4400UL)
#define RTC_BASE_NS                     (APB7PERIPH_BASE_NS + 0x7800UL)
#define TAMP_BASE_NS                    (APB7PERIPH_BASE_NS + 0x7C00UL)

/*!< AHB4 Non secure peripherals */
#define PWR_BASE_NS                     (AHB4PERIPH_BASE_NS + 0x0800UL)
#define RCC_BASE_NS                     (AHB4PERIPH_BASE_NS + 0x0C00UL)
#define ADC4_BASE_NS                    (AHB4PERIPH_BASE_NS + 0x1000UL)
#define ADC4_COMMON_BASE_NS             (AHB4PERIPH_BASE_NS + 0x1308UL)
#define EXTI_BASE_NS                    (AHB4PERIPH_BASE_NS + 0x2000UL)

/*!< AHB5 Non secure peripherals */
#define RADIO_BASE_NS                   AHB5PERIPH_BASE_NS


/** @} */ /* End of group STM32WBAxx_Peripheral_peripheralAddr */
/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */
/** @addtogroup STM32WBAxx_Peripheral_declaration
  * @{
  */
#define DBGMCU                          ((DBGMCU_TypeDef *) DBGMCU_BASE)

#define ADC4_NS                         ((ADC_TypeDef *) ADC4_BASE_NS)
#define ADC4_COMMON_NS                  ((ADC_Common_TypeDef *) ADC4_COMMON_BASE_NS)
#define AES_NS                          ((AES_TypeDef *) AES_BASE_NS)
#define CRC_NS                          ((CRC_TypeDef *) CRC_BASE_NS)
#define EXTI_NS                         ((EXTI_TypeDef *) EXTI_BASE_NS)
#define FLASH_NS                        ((FLASH_TypeDef *) FLASH_R_BASE_NS)
#define GPDMA1_NS                       ((DMA_TypeDef *) GPDMA1_BASE_NS)
#define GPDMA1_Channel0_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel0_BASE_NS)
#define GPDMA1_Channel1_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel1_BASE_NS)
#define GPDMA1_Channel2_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel2_BASE_NS)
#define GPDMA1_Channel3_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel3_BASE_NS)
#define GPDMA1_Channel4_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel4_BASE_NS)
#define GPDMA1_Channel5_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel5_BASE_NS)
#define GPDMA1_Channel6_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel6_BASE_NS)
#define GPDMA1_Channel7_NS              ((DMA_Channel_TypeDef *) GPDMA1_Channel7_BASE_NS)
#define GPIOA_NS                        ((GPIO_TypeDef *) GPIOA_BASE_NS)
#define GPIOB_NS                        ((GPIO_TypeDef *) GPIOB_BASE_NS)
#define GPIOC_NS                        ((GPIO_TypeDef *) GPIOC_BASE_NS)
#define GPIOH_NS                        ((GPIO_TypeDef *) GPIOH_BASE_NS)
#define HASH_NS                         ((HASH_TypeDef *) HASH_BASE_NS)
#define HASH_DIGEST_NS                  ((HASH_DIGEST_TypeDef *) HASH_DIGEST_BASE_NS)
#define HSEM_NS                         ((HSEM_TypeDef *) HSEM_BASE_NS)
#define HSEM_COMMON_NS                  ((HSEM_Common_TypeDef *) (HSEM_BASE_NS + 0x100U))
#define I2C3_NS                         ((I2C_TypeDef *) I2C3_BASE_NS)
#define ICACHE_NS                       ((ICACHE_TypeDef *) ICACHE_BASE_NS)
#define IWDG_NS                         ((IWDG_TypeDef *) IWDG_BASE_NS)
#define LPTIM1_NS                       ((LPTIM_TypeDef *) LPTIM1_BASE_NS)
#define LPUART1_NS                      ((USART_TypeDef *) LPUART1_BASE_NS)
#define PKA_NS                          ((PKA_TypeDef *) PKA_BASE_NS)
#define PWR_NS                          ((PWR_TypeDef *) PWR_BASE_NS)
#define RAMCFG_SRAM1_NS                 ((RAMCFG_TypeDef *) RAMCFG_SRAM1_BASE_NS)
#define RAMCFG_SRAM2_NS                 ((RAMCFG_TypeDef *) RAMCFG_SRAM2_BASE_NS)
#define RAMCFG_SRAM6_NS                 ((RAMCFG_TypeDef *) RAMCFG_SRAM6_BASE_NS)
#define RCC_NS                          ((RCC_TypeDef *) RCC_BASE_NS)
#define RNG_NS                          ((RNG_TypeDef *) RNG_BASE_NS)
#define RTC_NS                          ((RTC_TypeDef *) RTC_BASE_NS)
#define SPI3_NS                         ((SPI_TypeDef *) SPI3_BASE_NS)
#define SYSCFG_NS                       ((SYSCFG_TypeDef *) SYSCFG_BASE_NS)
#define TAMP_NS                         ((TAMP_TypeDef *) TAMP_BASE_NS)
#define TIM1_NS                         ((TIM_TypeDef *) TIM1_BASE_NS)
#define TIM2_NS                         ((TIM_TypeDef *) TIM2_BASE_NS)
#define TIM16_NS                        ((TIM_TypeDef *) TIM16_BASE_NS)
#define TSC_NS                          ((TSC_TypeDef *) TSC_BASE_NS)
#define USART1_NS                       ((USART_TypeDef *) USART1_BASE_NS)
#define WWDG_NS                         ((WWDG_TypeDef *) WWDG_BASE_NS)

/*!< Memory base addresses for Non secure peripherals */
#define FLASH_BASE                      FLASH_BASE_NS
#define SRAM1_BASE                      SRAM1_BASE_NS
#define SRAM2_BASE                      SRAM2_BASE_NS
#define SRAM6_BASE                      SRAM6_BASE_NS
#define SEQSRAM_BASE                    SEQSRAM_BASE_NS

/*!< Instance aliases and base addresses for Non secure peripherals */
#define ADC4                            ADC4_NS
#define ADC4_BASE                       ADC4_BASE_NS
#define ADC4_COMMON                     ADC4_COMMON_NS
#define ADC4_COMMON_BASE                ADC4_COMMON_BASE_NS
#define AES                             AES_NS
#define AES_BASE                        AES_BASE_NS
#define CRC                             CRC_NS
#define CRC_BASE                        CRC_BASE_NS
#define EXTI                            EXTI_NS
#define EXTI_BASE                       EXTI_BASE_NS
#define FLASH                           FLASH_NS
#define FLASH_R_BASE                    FLASH_R_BASE_NS
#define GPDMA1                          GPDMA1_NS
#define GPDMA1_BASE                     GPDMA1_BASE_NS
#define GPDMA1_Channel0                 GPDMA1_Channel0_NS
#define GPDMA1_Channel0_BASE            GPDMA1_Channel0_BASE_NS
#define GPDMA1_Channel1                 GPDMA1_Channel1_NS
#define GPDMA1_Channel1_BASE            GPDMA1_Channel1_BASE_NS
#define GPDMA1_Channel2                 GPDMA1_Channel2_NS
#define GPDMA1_Channel2_BASE            GPDMA1_Channel2_BASE_NS
#define GPDMA1_Channel3                 GPDMA1_Channel3_NS
#define GPDMA1_Channel3_BASE            GPDMA1_Channel3_BASE_NS
#define GPDMA1_Channel4                 GPDMA1_Channel4_NS
#define GPDMA1_Channel4_BASE            GPDMA1_Channel4_BASE_NS
#define GPDMA1_Channel5                 GPDMA1_Channel5_NS
#define GPDMA1_Channel5_BASE            GPDMA1_Channel5_BASE_NS
#define GPDMA1_Channel6                 GPDMA1_Channel6_NS
#define GPDMA1_Channel6_BASE            GPDMA1_Channel6_BASE_NS
#define GPDMA1_Channel7                 GPDMA1_Channel7_NS
#define GPDMA1_Channel7_BASE            GPDMA1_Channel7_BASE_NS
#define GPIOA                           GPIOA_NS
#define GPIOA_BASE                      GPIOA_BASE_NS
#define GPIOB                           GPIOB_NS
#define GPIOB_BASE                      GPIOB_BASE_NS
#define GPIOC                           GPIOC_NS
#define GPIOC_BASE                      GPIOC_BASE_NS
#define GPIOH                           GPIOH_NS
#define GPIOH_BASE                      GPIOH_BASE_NS
#define HASH                            HASH_NS
#define HASH_BASE                       HASH_BASE_NS
#define HASH_DIGEST                     HASH_DIGEST_NS
#define HASH_DIGEST_BASE                HASH_DIGEST_BASE_NS
#define HSEM                            HSEM_NS
#define HSEM_BASE                       HSEM_BASE_NS
#define HSEM_COMMON                     HSEM_COMMON_NS
#define I2C3                            I2C3_NS
#define I2C3_BASE                       I2C3_BASE_NS
#define ICACHE                          ICACHE_NS
#define ICACHE_BASE                     ICACHE_BASE_NS
#define IWDG                            IWDG_NS
#define IWDG_BASE                       IWDG_BASE_NS
#define LPTIM1                          LPTIM1_NS
#define LPTIM1_BASE                     LPTIM1_BASE_NS
#define LPUART1                         LPUART1_NS
#define LPUART1_BASE                    LPUART1_BASE_NS
#define PKA                             PKA_NS
#define PKA_BASE                        PKA_BASE_NS
#define PKA_RAM_BASE                    PKA_RAM_BASE_NS
#define PWR                             PWR_NS
#define PWR_BASE                        PWR_BASE_NS
#define RADIO_BASE                      RADIO_BASE_NS
#define RAMCFG_SRAM1                    RAMCFG_SRAM1_NS
#define RAMCFG_SRAM1_BASE               RAMCFG_SRAM1_BASE_NS
#define RAMCFG_SRAM2                    RAMCFG_SRAM2_NS
#define RAMCFG_SRAM2_BASE               RAMCFG_SRAM2_BASE_NS
#define RAMCFG_SRAM6                    RAMCFG_SRAM6_NS
#define RAMCFG_SRAM6_BASE               RAMCFG_SRAM6_BASE_NS
#define RCC                             RCC_NS
#define RCC_BASE                        RCC_BASE_NS
#define RNG                             RNG_NS
#define RNG_BASE                        RNG_BASE_NS
#define RTC                             RTC_NS
#define RTC_BASE                        RTC_BASE_NS
#define SPI3                            SPI3_NS
#define SPI3_BASE                       SPI3_BASE_NS
#define SYSCFG                          SYSCFG_NS
#define SYSCFG_BASE                     SYSCFG_BASE_NS
#define TAMP                            TAMP_NS
#define TAMP_BASE                       TAMP_BASE_NS
#define TIM1                            TIM1_NS
#define TIM1_BASE                       TIM1_BASE_NS
#define TIM2                            TIM2_NS
#define TIM2_BASE                       TIM2_BASE_NS
#define TIM16                           TIM16_NS
#define TIM16_BASE                      TIM16_BASE_NS
#define TSC                             TSC_NS
#define TSC_BASE                        TSC_BASE_NS
#define USART1                          USART1_NS
#define USART1_BASE                     USART1_BASE_NS
#define WWDG                            WWDG_NS
#define WWDG_BASE                       WWDG_BASE_NS


/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Hardware_Constant_Definition
  * @{
  */
#define LSI_STARTUP_TIME                16000U /*!< LSI Maximum startup time in us : 4 cycles @ 250 Hz = 16 ms */
/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_ISR register  *******************/
#define ADC_ISR_ADRDY_Pos              (0U)
#define ADC_ISR_ADRDY_Msk              (0x1UL << ADC_ISR_ADRDY_Pos)            /*!< 0x00000001 */
#define ADC_ISR_ADRDY                  ADC_ISR_ADRDY_Msk                       /*!< ADC ready flag */
#define ADC_ISR_EOSMP_Pos              (1U)
#define ADC_ISR_EOSMP_Msk              (0x1UL << ADC_ISR_EOSMP_Pos)            /*!< 0x00000002 */
#define ADC_ISR_EOSMP                  ADC_ISR_EOSMP_Msk                       /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos                (2U)
#define ADC_ISR_EOC_Msk                (0x1UL << ADC_ISR_EOC_Pos)              /*!< 0x00000004 */
#define ADC_ISR_EOC                    ADC_ISR_EOC_Msk                         /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos                (3U)
#define ADC_ISR_EOS_Msk                (0x1UL << ADC_ISR_EOS_Pos)              /*!< 0x00000008 */
#define ADC_ISR_EOS                    ADC_ISR_EOS_Msk                         /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos                (4U)
#define ADC_ISR_OVR_Msk                (0x1UL << ADC_ISR_OVR_Pos)              /*!< 0x00000010 */
#define ADC_ISR_OVR                    ADC_ISR_OVR_Msk                         /*!< ADC group regular overrun flag */
#define ADC_ISR_AWD1_Pos               (7U)
#define ADC_ISR_AWD1_Msk               (0x1UL << ADC_ISR_AWD1_Pos)             /*!< 0x00000080 */
#define ADC_ISR_AWD1                   ADC_ISR_AWD1_Msk                        /*!< ADC analog watchdog 1 flag */
#define ADC_ISR_AWD2_Pos               (8U)
#define ADC_ISR_AWD2_Msk               (0x1UL << ADC_ISR_AWD2_Pos)             /*!< 0x00000100 */
#define ADC_ISR_AWD2                   ADC_ISR_AWD2_Msk                        /*!< ADC analog watchdog 2 flag */
#define ADC_ISR_AWD3_Pos               (9U)
#define ADC_ISR_AWD3_Msk               (0x1UL << ADC_ISR_AWD3_Pos)             /*!< 0x00000200 */
#define ADC_ISR_AWD3                   ADC_ISR_AWD3_Msk                        /*!< ADC analog watchdog 3 flag */
#define ADC_ISR_EOCAL_Pos              (11U)
#define ADC_ISR_EOCAL_Msk              (0x1UL << ADC_ISR_EOCAL_Pos)            /*!< 0x00000800 */
#define ADC_ISR_EOCAL                  ADC_ISR_EOCAL_Msk                       /*!< ADC end of calibration flag */
#define ADC_ISR_LDORDY_Pos             (12U)
#define ADC_ISR_LDORDY_Msk             (0x1UL << ADC_ISR_LDORDY_Pos)           /*!< 0x00001000 */
#define ADC_ISR_LDORDY                 ADC_ISR_LDORDY_Msk                      /*!< ADC internal voltage regulator ready flag */

/********************  Bit definition for ADC_IER register  *******************/
#define ADC_IER_ADRDYIE_Pos            (0U)
#define ADC_IER_ADRDYIE_Msk            (0x1UL << ADC_IER_ADRDYIE_Pos)          /*!< 0x00000001 */
#define ADC_IER_ADRDYIE                ADC_IER_ADRDYIE_Msk                     /*!< ADC ready interrupt */
#define ADC_IER_EOSMPIE_Pos            (1U)
#define ADC_IER_EOSMPIE_Msk            (0x1UL << ADC_IER_EOSMPIE_Pos)          /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                ADC_IER_EOSMPIE_Msk                     /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos              (2U)
#define ADC_IER_EOCIE_Msk              (0x1UL << ADC_IER_EOCIE_Pos)            /*!< 0x00000004 */
#define ADC_IER_EOCIE                  ADC_IER_EOCIE_Msk                       /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos              (3U)
#define ADC_IER_EOSIE_Msk              (0x1UL << ADC_IER_EOSIE_Pos)            /*!< 0x00000008 */
#define ADC_IER_EOSIE                  ADC_IER_EOSIE_Msk                       /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos              (4U)
#define ADC_IER_OVRIE_Msk              (0x1UL << ADC_IER_OVRIE_Pos)            /*!< 0x00000010 */
#define ADC_IER_OVRIE                  ADC_IER_OVRIE_Msk                       /*!< ADC group regular overrun interrupt */
#define ADC_IER_AWD1IE_Pos             (7U)
#define ADC_IER_AWD1IE_Msk             (0x1UL << ADC_IER_AWD1IE_Pos)           /*!< 0x00000080 */
#define ADC_IER_AWD1IE                 ADC_IER_AWD1IE_Msk                      /*!< ADC analog watchdog 1 interrupt */
#define ADC_IER_AWD2IE_Pos             (8U)
#define ADC_IER_AWD2IE_Msk             (0x1UL << ADC_IER_AWD2IE_Pos)           /*!< 0x00000100 */
#define ADC_IER_AWD2IE                 ADC_IER_AWD2IE_Msk                      /*!< ADC analog watchdog 2 interrupt */
#define ADC_IER_AWD3IE_Pos             (9U)
#define ADC_IER_AWD3IE_Msk             (0x1UL << ADC_IER_AWD3IE_Pos)           /*!< 0x00000200 */
#define ADC_IER_AWD3IE                 ADC_IER_AWD3IE_Msk                      /*!< ADC analog watchdog 3 interrupt */
#define ADC_IER_EOCALIE_Pos            (11U)
#define ADC_IER_EOCALIE_Msk            (0x1UL << ADC_IER_EOCALIE_Pos)          /*!< 0x00000800 */
#define ADC_IER_EOCALIE                ADC_IER_EOCALIE_Msk                     /*!< ADC end of calibration interrupt */
#define ADC_IER_LDORDYIE_Pos           (12U)
#define ADC_IER_LDORDYIE_Msk           (0x1UL << ADC_IER_LDORDYIE_Pos)         /*!< 0x00001000 */
#define ADC_IER_LDORDYIE               ADC_IER_LDORDYIE_Msk                    /*!< ADC Voltage Regulator Ready interrupt source */

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos                (0U)
#define ADC_CR_ADEN_Msk                (0x1UL << ADC_CR_ADEN_Pos)              /*!< 0x00000001 */
#define ADC_CR_ADEN                    ADC_CR_ADEN_Msk                         /*!< ADC enable */
#define ADC_CR_ADDIS_Pos               (1U)
#define ADC_CR_ADDIS_Msk               (0x1UL << ADC_CR_ADDIS_Pos)             /*!< 0x00000002 */
#define ADC_CR_ADDIS                   ADC_CR_ADDIS_Msk                        /*!< ADC disable */
#define ADC_CR_ADSTART_Pos             (2U)
#define ADC_CR_ADSTART_Msk             (0x1UL << ADC_CR_ADSTART_Pos)           /*!< 0x00000004 */
#define ADC_CR_ADSTART                 ADC_CR_ADSTART_Msk                      /*!< ADC group regular conversion start */
#define ADC_CR_ADSTP_Pos               (4U)
#define ADC_CR_ADSTP_Msk               (0x1UL << ADC_CR_ADSTP_Pos)             /*!< 0x00000010 */
#define ADC_CR_ADSTP                   ADC_CR_ADSTP_Msk                        /*!< ADC group regular conversion stop */
#define ADC_CR_ADVREGEN_Pos            (28U)
#define ADC_CR_ADVREGEN_Msk            (0x1UL << ADC_CR_ADVREGEN_Pos)          /*!< 0x10000000 */
#define ADC_CR_ADVREGEN                ADC_CR_ADVREGEN_Msk                     /*!< ADC voltage regulator enable */
#define ADC_CR_ADCAL_Pos               (31U)
#define ADC_CR_ADCAL_Msk               (0x1UL << ADC_CR_ADCAL_Pos)             /*!< 0x80000000 */
#define ADC_CR_ADCAL                   ADC_CR_ADCAL_Msk                        /*!< ADC calibration */

/********************  Bit definition for ADC_CFGR1 register  *****************/
#define ADC_CFGR1_DMAEN_Pos            (0U)
#define ADC_CFGR1_DMAEN_Msk            (0x1UL << ADC_CFGR1_DMAEN_Pos)          /*!< 0x00000001 */
#define ADC_CFGR1_DMAEN                ADC_CFGR1_DMAEN_Msk                     /*!< ADC DMA transfer enable */
#define ADC_CFGR1_DMACFG_Pos           (1U)
#define ADC_CFGR1_DMACFG_Msk           (0x1UL << ADC_CFGR1_DMACFG_Pos)         /*!< 0x00000002 */
#define ADC_CFGR1_DMACFG               ADC_CFGR1_DMACFG_Msk                    /*!< ADC DMA transfer configuration */

#define ADC_CFGR1_RES_Pos              (2U)
#define ADC_CFGR1_RES_Msk              (0x3UL << ADC_CFGR1_RES_Pos)            /*!< 0x0000000C */
#define ADC_CFGR1_RES                  ADC_CFGR1_RES_Msk                       /*!< ADC Data resolution */
#define ADC_CFGR1_RES_0                (0x1UL << ADC_CFGR1_RES_Pos)            /*!< 0x00000004 */
#define ADC_CFGR1_RES_1                (0x2UL << ADC_CFGR1_RES_Pos)            /*!< 0x00000008 */

#define ADC_CFGR1_SCANDIR_Pos          (4U)
#define ADC_CFGR1_SCANDIR_Msk          (0x1UL << ADC_CFGR1_SCANDIR_Pos)        /*!< 0x00000010 */
#define ADC_CFGR1_SCANDIR              ADC_CFGR1_SCANDIR_Msk                   /*!< ADC group regular sequencer scan direction */
#define ADC_CFGR1_ALIGN_Pos            (5U)
#define ADC_CFGR1_ALIGN_Msk            (0x1UL << ADC_CFGR1_ALIGN_Pos)          /*!< 0x00000020 */
#define ADC_CFGR1_ALIGN                ADC_CFGR1_ALIGN_Msk                     /*!< ADC data alignment */

#define ADC_CFGR1_EXTSEL_Pos           (6U)
#define ADC_CFGR1_EXTSEL_Msk           (0x7UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x000001C0 */
#define ADC_CFGR1_EXTSEL               ADC_CFGR1_EXTSEL_Msk                    /*!< ADC group regular external trigger source */
#define ADC_CFGR1_EXTSEL_0             (0x1UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000040 */
#define ADC_CFGR1_EXTSEL_1             (0x2UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000080 */
#define ADC_CFGR1_EXTSEL_2             (0x4UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000100 */

#define ADC_CFGR1_EXTEN_Pos            (10U)
#define ADC_CFGR1_EXTEN_Msk            (0x3UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000C00 */
#define ADC_CFGR1_EXTEN                ADC_CFGR1_EXTEN_Msk                     /*!< ADC group regular external trigger polarity */
#define ADC_CFGR1_EXTEN_0              (0x1UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000400 */
#define ADC_CFGR1_EXTEN_1              (0x2UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000800 */

#define ADC_CFGR1_OVRMOD_Pos           (12U)
#define ADC_CFGR1_OVRMOD_Msk           (0x1UL << ADC_CFGR1_OVRMOD_Pos)         /*!< 0x00001000 */
#define ADC_CFGR1_OVRMOD               ADC_CFGR1_OVRMOD_Msk                    /*!< ADC group regular overrun configuration */
#define ADC_CFGR1_CONT_Pos             (13U)
#define ADC_CFGR1_CONT_Msk             (0x1UL << ADC_CFGR1_CONT_Pos)           /*!< 0x00002000 */
#define ADC_CFGR1_CONT                 ADC_CFGR1_CONT_Msk                      /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR1_WAIT_Pos             (14U)
#define ADC_CFGR1_WAIT_Msk             (0x1UL << ADC_CFGR1_WAIT_Pos)           /*!< 0x00004000 */
#define ADC_CFGR1_WAIT                 ADC_CFGR1_WAIT_Msk                      /*!< ADC low power auto wait */
#define ADC_CFGR1_DISCEN_Pos           (16U)
#define ADC_CFGR1_DISCEN_Msk           (0x1UL << ADC_CFGR1_DISCEN_Pos)         /*!< 0x00010000 */
#define ADC_CFGR1_DISCEN               ADC_CFGR1_DISCEN_Msk                    /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CFGR1_CHSELRMOD_Pos        (21U)
#define ADC_CFGR1_CHSELRMOD_Msk        (0x1UL << ADC_CFGR1_CHSELRMOD_Pos)      /*!< 0x00200000 */
#define ADC_CFGR1_CHSELRMOD            ADC_CFGR1_CHSELRMOD_Msk                 /*!< ADC group regular sequencer mode */

#define ADC_CFGR1_AWD1SGL_Pos          (22U)
#define ADC_CFGR1_AWD1SGL_Msk          (0x1UL << ADC_CFGR1_AWD1SGL_Pos)        /*!< 0x00400000 */
#define ADC_CFGR1_AWD1SGL              ADC_CFGR1_AWD1SGL_Msk                   /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR1_AWD1EN_Pos           (23U)
#define ADC_CFGR1_AWD1EN_Msk           (0x1UL << ADC_CFGR1_AWD1EN_Pos)         /*!< 0x00800000 */
#define ADC_CFGR1_AWD1EN               ADC_CFGR1_AWD1EN_Msk                    /*!< ADC analog watchdog 1 enable on scope ADC group regular */

#define ADC_CFGR1_AWD1CH_Pos           (26U)
#define ADC_CFGR1_AWD1CH_Msk           (0x1FUL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x7C000000 */
#define ADC_CFGR1_AWD1CH               ADC_CFGR1_AWD1CH_Msk                    /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR1_AWD1CH_0             (0x01UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x04000000 */
#define ADC_CFGR1_AWD1CH_1             (0x02UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x08000000 */
#define ADC_CFGR1_AWD1CH_2             (0x04UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x10000000 */
#define ADC_CFGR1_AWD1CH_3             (0x08UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x20000000 */
#define ADC_CFGR1_AWD1CH_4             (0x10UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x40000000 */

/********************  Bit definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_OVSE_Pos             (0U)
#define ADC_CFGR2_OVSE_Msk             (0x1UL << ADC_CFGR2_OVSE_Pos)           /*!< 0x00000001 */
#define ADC_CFGR2_OVSE                 ADC_CFGR2_OVSE_Msk                      /*!< ADC oversampler enable on scope ADC group regular */

#define ADC_CFGR2_OVSR_Pos             (2U)
#define ADC_CFGR2_OVSR_Msk             (0x7UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x0000001C */
#define ADC_CFGR2_OVSR                 ADC_CFGR2_OVSR_Msk                      /*!< ADC oversampling ratio */
#define ADC_CFGR2_OVSR_0               (0x1UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000004 */
#define ADC_CFGR2_OVSR_1               (0x2UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000008 */
#define ADC_CFGR2_OVSR_2               (0x4UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000010 */

#define ADC_CFGR2_OVSS_Pos             (5U)
#define ADC_CFGR2_OVSS_Msk             (0xFUL << ADC_CFGR2_OVSS_Pos)           /*!< 0x000001E0 */
#define ADC_CFGR2_OVSS                 ADC_CFGR2_OVSS_Msk                      /*!< ADC oversampling shift */
#define ADC_CFGR2_OVSS_0               (0x1UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000020 */
#define ADC_CFGR2_OVSS_1               (0x2UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000040 */
#define ADC_CFGR2_OVSS_2               (0x4UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000080 */
#define ADC_CFGR2_OVSS_3               (0x8UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000100 */

#define ADC_CFGR2_TOVS_Pos             (9U)
#define ADC_CFGR2_TOVS_Msk             (0x1UL << ADC_CFGR2_TOVS_Pos)           /*!< 0x00000200 */
#define ADC_CFGR2_TOVS                 ADC_CFGR2_TOVS_Msk                      /*!< ADC oversampling discontinuous mode (triggered mode) for ADC group regular */

#define ADC_CFGR2_LFTRIG_Pos           (29U)
#define ADC_CFGR2_LFTRIG_Msk           (0x1UL << ADC_CFGR2_LFTRIG_Pos)         /*!< 0x20000000 */
#define ADC_CFGR2_LFTRIG               ADC_CFGR2_LFTRIG_Msk                    /*!< ADC low frequency trigger mode */

/********************  Bit definition for ADC_SMPR register  ******************/
#define ADC_SMPR_SMP1_Pos              (0U)
#define ADC_SMPR_SMP1_Msk              (0x7UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000007 */
#define ADC_SMPR_SMP1                  ADC_SMPR_SMP1_Msk                       /*!< ADC group of channels sampling time 1 */
#define ADC_SMPR_SMP1_0                (0x1UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000001 */
#define ADC_SMPR_SMP1_1                (0x2UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000002 */
#define ADC_SMPR_SMP1_2                (0x4UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000004 */

#define ADC_SMPR_SMP2_Pos              (4U)
#define ADC_SMPR_SMP2_Msk              (0x7UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000070 */
#define ADC_SMPR_SMP2                  ADC_SMPR_SMP2_Msk                       /*!< ADC group of channels sampling time 2 */
#define ADC_SMPR_SMP2_0                (0x1UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000010 */
#define ADC_SMPR_SMP2_1                (0x2UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000020 */
#define ADC_SMPR_SMP2_2                (0x4UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000040 */

#define ADC_SMPR_SMPSEL_Pos            (8U)
#define ADC_SMPR_SMPSEL_Msk            (0x3FFFFUL << ADC_SMPR_SMPSEL_Pos)      /*!< 0x03FFFF00 */
#define ADC_SMPR_SMPSEL                ADC_SMPR_SMPSEL_Msk                     /*!< ADC all channels sampling time selection */
#define ADC_SMPR_SMPSEL0_Pos           (8U)
#define ADC_SMPR_SMPSEL0_Msk           (0x1UL << ADC_SMPR_SMPSEL0_Pos)         /*!< 0x00000100 */
#define ADC_SMPR_SMPSEL0               ADC_SMPR_SMPSEL0_Msk                    /*!< ADC channel 0 sampling time selection */
#define ADC_SMPR_SMPSEL1_Pos           (9U)
#define ADC_SMPR_SMPSEL1_Msk           (0x1UL << ADC_SMPR_SMPSEL1_Pos)         /*!< 0x00000200 */
#define ADC_SMPR_SMPSEL1               ADC_SMPR_SMPSEL1_Msk                    /*!< ADC channel 1 sampling time selection */
#define ADC_SMPR_SMPSEL2_Pos           (10U)
#define ADC_SMPR_SMPSEL2_Msk           (0x1UL << ADC_SMPR_SMPSEL2_Pos)         /*!< 0x00000400 */
#define ADC_SMPR_SMPSEL2               ADC_SMPR_SMPSEL2_Msk                    /*!< ADC channel 2 sampling time selection */
#define ADC_SMPR_SMPSEL3_Pos           (11U)
#define ADC_SMPR_SMPSEL3_Msk           (0x1UL << ADC_SMPR_SMPSEL3_Pos)         /*!< 0x00000800 */
#define ADC_SMPR_SMPSEL3               ADC_SMPR_SMPSEL3_Msk                    /*!< ADC channel 3 sampling time selection */
#define ADC_SMPR_SMPSEL4_Pos           (12U)
#define ADC_SMPR_SMPSEL4_Msk           (0x1UL << ADC_SMPR_SMPSEL4_Pos)         /*!< 0x00001000 */
#define ADC_SMPR_SMPSEL4               ADC_SMPR_SMPSEL4_Msk                    /*!< ADC channel 4 sampling time selection */
#define ADC_SMPR_SMPSEL5_Pos           (13U)
#define ADC_SMPR_SMPSEL5_Msk           (0x1UL << ADC_SMPR_SMPSEL5_Pos)         /*!< 0x00002000 */
#define ADC_SMPR_SMPSEL5               ADC_SMPR_SMPSEL5_Msk                    /*!< ADC channel 5 sampling time selection */
#define ADC_SMPR_SMPSEL6_Pos           (14U)
#define ADC_SMPR_SMPSEL6_Msk           (0x1UL << ADC_SMPR_SMPSEL6_Pos)         /*!< 0x00004000 */
#define ADC_SMPR_SMPSEL6               ADC_SMPR_SMPSEL6_Msk                    /*!< ADC channel 6 sampling time selection */
#define ADC_SMPR_SMPSEL7_Pos           (15U)
#define ADC_SMPR_SMPSEL7_Msk           (0x1UL << ADC_SMPR_SMPSEL7_Pos)         /*!< 0x00008000 */
#define ADC_SMPR_SMPSEL7               ADC_SMPR_SMPSEL7_Msk                    /*!< ADC channel 7 sampling time selection */
#define ADC_SMPR_SMPSEL8_Pos           (16U)
#define ADC_SMPR_SMPSEL8_Msk           (0x1UL << ADC_SMPR_SMPSEL8_Pos)         /*!< 0x00010000 */
#define ADC_SMPR_SMPSEL8               ADC_SMPR_SMPSEL8_Msk                    /*!< ADC channel 8 sampling time selection */
#define ADC_SMPR_SMPSEL9_Pos           (17U)
#define ADC_SMPR_SMPSEL9_Msk           (0x1UL << ADC_SMPR_SMPSEL9_Pos)         /*!< 0x00020000 */
#define ADC_SMPR_SMPSEL9               ADC_SMPR_SMPSEL9_Msk                    /*!< ADC channel 9 sampling time selection */
#define ADC_SMPR_SMPSEL10_Pos          (18U)
#define ADC_SMPR_SMPSEL10_Msk          (0x1UL << ADC_SMPR_SMPSEL10_Pos)        /*!< 0x00040000 */
#define ADC_SMPR_SMPSEL10              ADC_SMPR_SMPSEL10_Msk                   /*!< ADC channel 10 sampling time selection */
#define ADC_SMPR_SMPSEL11_Pos          (19U)
#define ADC_SMPR_SMPSEL11_Msk          (0x1UL << ADC_SMPR_SMPSEL11_Pos)        /*!< 0x00080000 */
#define ADC_SMPR_SMPSEL11              ADC_SMPR_SMPSEL11_Msk                   /*!< ADC channel 11 sampling time selection */
#define ADC_SMPR_SMPSEL12_Pos          (20U)
#define ADC_SMPR_SMPSEL12_Msk          (0x1UL << ADC_SMPR_SMPSEL12_Pos)        /*!< 0x00100000 */
#define ADC_SMPR_SMPSEL12              ADC_SMPR_SMPSEL12_Msk                   /*!< ADC channel 12 sampling time selection */
#define ADC_SMPR_SMPSEL13_Pos          (21U)
#define ADC_SMPR_SMPSEL13_Msk          (0x1UL << ADC_SMPR_SMPSEL13_Pos)        /*!< 0x00200000 */
#define ADC_SMPR_SMPSEL13              ADC_SMPR_SMPSEL13_Msk                   /*!< ADC channel 13 sampling time selection */
#define ADC_SMPR_SMPSEL14_Pos          (22U)
#define ADC_SMPR_SMPSEL14_Msk          (0x1UL << ADC_SMPR_SMPSEL14_Pos)        /*!< 0x00400000 */
#define ADC_SMPR_SMPSEL14              ADC_SMPR_SMPSEL14_Msk                   /*!< ADC channel 14 sampling time selection */
#define ADC_SMPR_SMPSEL15_Pos          (23U)
#define ADC_SMPR_SMPSEL15_Msk          (0x1UL << ADC_SMPR_SMPSEL15_Pos)        /*!< 0x00800000 */
#define ADC_SMPR_SMPSEL15              ADC_SMPR_SMPSEL15_Msk                   /*!< ADC channel 15 sampling time selection */
#define ADC_SMPR_SMPSEL16_Pos          (24U)
#define ADC_SMPR_SMPSEL16_Msk          (0x1UL << ADC_SMPR_SMPSEL16_Pos)        /*!< 0x01000000 */
#define ADC_SMPR_SMPSEL16              ADC_SMPR_SMPSEL16_Msk                   /*!< ADC channel 16 sampling time selection */
#define ADC_SMPR_SMPSEL17_Pos          (25U)
#define ADC_SMPR_SMPSEL17_Msk          (0x1UL << ADC_SMPR_SMPSEL17_Pos)        /*!< 0x02000000 */
#define ADC_SMPR_SMPSEL17              ADC_SMPR_SMPSEL17_Msk                   /*!< ADC channel 17 sampling time selection */

/********************  Bit definition for ADC_AWD1TR register  *******************/
#define ADC_AWD1TR_LT1_Pos             (0U)
#define ADC_AWD1TR_LT1_Msk             (0xFFFUL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000FFF */
#define ADC_AWD1TR_LT1                 ADC_AWD1TR_LT1_Msk                      /*!< ADC analog watchdog 1 threshold low */
#define ADC_AWD1TR_LT1_0               (0x001UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000001 */
#define ADC_AWD1TR_LT1_1               (0x002UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000002 */
#define ADC_AWD1TR_LT1_2               (0x004UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000004 */
#define ADC_AWD1TR_LT1_3               (0x008UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000008 */
#define ADC_AWD1TR_LT1_4               (0x010UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000010 */
#define ADC_AWD1TR_LT1_5               (0x020UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000020 */
#define ADC_AWD1TR_LT1_6               (0x040UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000040 */
#define ADC_AWD1TR_LT1_7               (0x080UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000080 */
#define ADC_AWD1TR_LT1_8               (0x100UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000100 */
#define ADC_AWD1TR_LT1_9               (0x200UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000200 */
#define ADC_AWD1TR_LT1_10              (0x400UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000400 */
#define ADC_AWD1TR_LT1_11              (0x800UL << ADC_AWD1TR_LT1_Pos)         /*!< 0x00000800 */

#define ADC_AWD1TR_HT1_Pos             (16U)
#define ADC_AWD1TR_HT1_Msk             (0xFFFUL << ADC_AWD1TR_HT1_Pos)         /*!< 0x0FFF0000 */
#define ADC_AWD1TR_HT1                 ADC_AWD1TR_HT1_Msk                      /*!< ADC Analog watchdog 1 threshold high */
#define ADC_AWD1TR_HT1_0               (0x001UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00010000 */
#define ADC_AWD1TR_HT1_1               (0x002UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00020000 */
#define ADC_AWD1TR_HT1_2               (0x004UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00040000 */
#define ADC_AWD1TR_HT1_3               (0x008UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00080000 */
#define ADC_AWD1TR_HT1_4               (0x010UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00100000 */
#define ADC_AWD1TR_HT1_5               (0x020UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00200000 */
#define ADC_AWD1TR_HT1_6               (0x040UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00400000 */
#define ADC_AWD1TR_HT1_7               (0x080UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x00800000 */
#define ADC_AWD1TR_HT1_8               (0x100UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x01000000 */
#define ADC_AWD1TR_HT1_9               (0x200UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x02000000 */
#define ADC_AWD1TR_HT1_10              (0x400UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x04000000 */
#define ADC_AWD1TR_HT1_11              (0x800UL << ADC_AWD1TR_HT1_Pos)         /*!< 0x08000000 */

/********************  Bit definition for ADC_AWDTR2 register  *******************/
#define ADC_AWD2TR_LT2_Pos             (0U)
#define ADC_AWD2TR_LT2_Msk             (0xFFFUL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000FFF */
#define ADC_AWD2TR_LT2                 ADC_AWD2TR_LT2_Msk                      /*!< ADC analog watchdog 2 threshold low */
#define ADC_AWD2TR_LT2_0               (0x001UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000001 */
#define ADC_AWD2TR_LT2_1               (0x002UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000002 */
#define ADC_AWD2TR_LT2_2               (0x004UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000004 */
#define ADC_AWD2TR_LT2_3               (0x008UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000008 */
#define ADC_AWD2TR_LT2_4               (0x010UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000010 */
#define ADC_AWD2TR_LT2_5               (0x020UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000020 */
#define ADC_AWD2TR_LT2_6               (0x040UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000040 */
#define ADC_AWD2TR_LT2_7               (0x080UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000080 */
#define ADC_AWD2TR_LT2_8               (0x100UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000100 */
#define ADC_AWD2TR_LT2_9               (0x200UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000200 */
#define ADC_AWD2TR_LT2_10              (0x400UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000400 */
#define ADC_AWD2TR_LT2_11              (0x800UL << ADC_AWD2TR_LT2_Pos)         /*!< 0x00000800 */

#define ADC_AWD2TR_HT2_Pos             (16U)
#define ADC_AWD2TR_HT2_Msk             (0xFFFUL << ADC_AWD2TR_HT2_Pos)         /*!< 0x0FFF0000 */
#define ADC_AWD2TR_HT2                 ADC_AWD2TR_HT2_Msk                      /*!< ADC analog watchdog 2 threshold high */
#define ADC_AWD2TR_HT2_0               (0x001UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00010000 */
#define ADC_AWD2TR_HT2_1               (0x002UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00020000 */
#define ADC_AWD2TR_HT2_2               (0x004UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00040000 */
#define ADC_AWD2TR_HT2_3               (0x008UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00080000 */
#define ADC_AWD2TR_HT2_4               (0x010UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00100000 */
#define ADC_AWD2TR_HT2_5               (0x020UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00200000 */
#define ADC_AWD2TR_HT2_6               (0x040UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00400000 */
#define ADC_AWD2TR_HT2_7               (0x080UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x00800000 */
#define ADC_AWD2TR_HT2_8               (0x100UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x01000000 */
#define ADC_AWD2TR_HT2_9               (0x200UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x02000000 */
#define ADC_AWD2TR_HT2_10              (0x400UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x04000000 */
#define ADC_AWD2TR_HT2_11              (0x800UL << ADC_AWD2TR_HT2_Pos)         /*!< 0x08000000 */

/********************  Bit definition for ADC_CHSELR register  ****************/
#define ADC_CHSELR_CHSEL_Pos           (0U)
#define ADC_CHSELR_CHSEL_Msk           (0x3FFFFUL << ADC_CHSELR_CHSEL_Pos)     /*!< 0x0003FFFF */
#define ADC_CHSELR_CHSEL               ADC_CHSELR_CHSEL_Msk                    /*!< ADC group regular sequencer channels, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL17_Pos         (17U)
#define ADC_CHSELR_CHSEL17_Msk         (0x1UL << ADC_CHSELR_CHSEL17_Pos)       /*!< 0x00020000 */
#define ADC_CHSELR_CHSEL17             ADC_CHSELR_CHSEL17_Msk                  /*!< ADC group regular sequencer channel 17, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL16_Pos         (16U)
#define ADC_CHSELR_CHSEL16_Msk         (0x1UL << ADC_CHSELR_CHSEL16_Pos)       /*!< 0x00010000 */
#define ADC_CHSELR_CHSEL16             ADC_CHSELR_CHSEL16_Msk                  /*!< ADC group regular sequencer channel 16, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL15_Pos         (15U)
#define ADC_CHSELR_CHSEL15_Msk         (0x1UL << ADC_CHSELR_CHSEL15_Pos)       /*!< 0x00008000 */
#define ADC_CHSELR_CHSEL15             ADC_CHSELR_CHSEL15_Msk                  /*!< ADC group regular sequencer channel 15, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL14_Pos         (14U)
#define ADC_CHSELR_CHSEL14_Msk         (0x1UL << ADC_CHSELR_CHSEL14_Pos)       /*!< 0x00004000 */
#define ADC_CHSELR_CHSEL14             ADC_CHSELR_CHSEL14_Msk                  /*!< ADC group regular sequencer channel 14, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL13_Pos         (13U)
#define ADC_CHSELR_CHSEL13_Msk         (0x1UL << ADC_CHSELR_CHSEL13_Pos)       /*!< 0x00002000 */
#define ADC_CHSELR_CHSEL13             ADC_CHSELR_CHSEL13_Msk                  /*!< ADC group regular sequencer channel 13, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL12_Pos         (12U)
#define ADC_CHSELR_CHSEL12_Msk         (0x1UL << ADC_CHSELR_CHSEL12_Pos)       /*!< 0x00001000 */
#define ADC_CHSELR_CHSEL12             ADC_CHSELR_CHSEL12_Msk                  /*!< ADC group regular sequencer channel 12, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL11_Pos         (11U)
#define ADC_CHSELR_CHSEL11_Msk         (0x1UL << ADC_CHSELR_CHSEL11_Pos)       /*!< 0x00000800 */
#define ADC_CHSELR_CHSEL11             ADC_CHSELR_CHSEL11_Msk                  /*!< ADC group regular sequencer channel 11, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL10_Pos         (10U)
#define ADC_CHSELR_CHSEL10_Msk         (0x1UL << ADC_CHSELR_CHSEL10_Pos)       /*!< 0x00000400 */
#define ADC_CHSELR_CHSEL10             ADC_CHSELR_CHSEL10_Msk                  /*!< ADC group regular sequencer channel 10, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL9_Pos          (9U)
#define ADC_CHSELR_CHSEL9_Msk          (0x1UL << ADC_CHSELR_CHSEL9_Pos)        /*!< 0x00000200 */
#define ADC_CHSELR_CHSEL9              ADC_CHSELR_CHSEL9_Msk                   /*!< ADC group regular sequencer channel 9, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL8_Pos          (8U)
#define ADC_CHSELR_CHSEL8_Msk          (0x1UL << ADC_CHSELR_CHSEL8_Pos)        /*!< 0x00000100 */
#define ADC_CHSELR_CHSEL8              ADC_CHSELR_CHSEL8_Msk                   /*!< ADC group regular sequencer channel 8, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL7_Pos          (7U)
#define ADC_CHSELR_CHSEL7_Msk          (0x1UL << ADC_CHSELR_CHSEL7_Pos)        /*!< 0x00000080 */
#define ADC_CHSELR_CHSEL7              ADC_CHSELR_CHSEL7_Msk                   /*!< ADC group regular sequencer channel 7, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL6_Pos          (6U)
#define ADC_CHSELR_CHSEL6_Msk          (0x1UL << ADC_CHSELR_CHSEL6_Pos)        /*!< 0x00000040 */
#define ADC_CHSELR_CHSEL6              ADC_CHSELR_CHSEL6_Msk                   /*!< ADC group regular sequencer channel 6, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL5_Pos          (5U)
#define ADC_CHSELR_CHSEL5_Msk          (0x1UL << ADC_CHSELR_CHSEL5_Pos)        /*!< 0x00000020 */
#define ADC_CHSELR_CHSEL5              ADC_CHSELR_CHSEL5_Msk                   /*!< ADC group regular sequencer channel 5, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL4_Pos          (4U)
#define ADC_CHSELR_CHSEL4_Msk          (0x1UL << ADC_CHSELR_CHSEL4_Pos)        /*!< 0x00000010 */
#define ADC_CHSELR_CHSEL4              ADC_CHSELR_CHSEL4_Msk                   /*!< ADC group regular sequencer channel 4, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL3_Pos          (3U)
#define ADC_CHSELR_CHSEL3_Msk          (0x1UL << ADC_CHSELR_CHSEL3_Pos)        /*!< 0x00000008 */
#define ADC_CHSELR_CHSEL3              ADC_CHSELR_CHSEL3_Msk                   /*!< ADC group regular sequencer channel 3, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL2_Pos          (2U)
#define ADC_CHSELR_CHSEL2_Msk          (0x1UL << ADC_CHSELR_CHSEL2_Pos)        /*!< 0x00000004 */
#define ADC_CHSELR_CHSEL2              ADC_CHSELR_CHSEL2_Msk                   /*!< ADC group regular sequencer channel 2, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL1_Pos          (1U)
#define ADC_CHSELR_CHSEL1_Msk          (0x1UL << ADC_CHSELR_CHSEL1_Pos)        /*!< 0x00000002 */
#define ADC_CHSELR_CHSEL1              ADC_CHSELR_CHSEL1_Msk                   /*!< ADC group regular sequencer channel 1, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL0_Pos          (0U)
#define ADC_CHSELR_CHSEL0_Msk          (0x1UL << ADC_CHSELR_CHSEL0_Pos)        /*!< 0x00000001 */
#define ADC_CHSELR_CHSEL0              ADC_CHSELR_CHSEL0_Msk                   /*!< ADC group regular sequencer channel 0, available when ADC_CFGR1_CHSELRMOD is reset */

#define ADC_CHSELR_SQ_ALL_Pos          (0U)
#define ADC_CHSELR_SQ_ALL_Msk          (0xFFFFFFFFUL << ADC_CHSELR_SQ_ALL_Pos) /*!< 0xFFFFFFFF */
#define ADC_CHSELR_SQ_ALL              ADC_CHSELR_SQ_ALL_Msk                   /*!< ADC group regular sequencer all ranks, available when ADC_CFGR1_CHSELRMOD is set */

#define ADC_CHSELR_SQ8_Pos             (28U)
#define ADC_CHSELR_SQ8_Msk             (0xFUL << ADC_CHSELR_SQ8_Pos)           /*!< 0xF0000000 */
#define ADC_CHSELR_SQ8                 ADC_CHSELR_SQ8_Msk                      /*!< ADC group regular sequencer rank 8, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ8_0               (0x1UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x10000000 */
#define ADC_CHSELR_SQ8_1               (0x2UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x20000000 */
#define ADC_CHSELR_SQ8_2               (0x4UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x40000000 */
#define ADC_CHSELR_SQ8_3               (0x8UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x80000000 */

#define ADC_CHSELR_SQ7_Pos             (24U)
#define ADC_CHSELR_SQ7_Msk             (0xFUL << ADC_CHSELR_SQ7_Pos)           /*!< 0x0F000000 */
#define ADC_CHSELR_SQ7                 ADC_CHSELR_SQ7_Msk                      /*!< ADC group regular sequencer rank 7, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ7_0               (0x1UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x01000000 */
#define ADC_CHSELR_SQ7_1               (0x2UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x02000000 */
#define ADC_CHSELR_SQ7_2               (0x4UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x04000000 */
#define ADC_CHSELR_SQ7_3               (0x8UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x08000000 */

#define ADC_CHSELR_SQ6_Pos             (20U)
#define ADC_CHSELR_SQ6_Msk             (0xFUL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00F00000 */
#define ADC_CHSELR_SQ6                 ADC_CHSELR_SQ6_Msk                      /*!< ADC group regular sequencer rank 6, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ6_0               (0x1UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00100000 */
#define ADC_CHSELR_SQ6_1               (0x2UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00200000 */
#define ADC_CHSELR_SQ6_2               (0x4UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00400000 */
#define ADC_CHSELR_SQ6_3               (0x8UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00800000 */

#define ADC_CHSELR_SQ5_Pos             (16U)
#define ADC_CHSELR_SQ5_Msk             (0xFUL << ADC_CHSELR_SQ5_Pos)           /*!< 0x000F0000 */
#define ADC_CHSELR_SQ5                 ADC_CHSELR_SQ5_Msk                      /*!< ADC group regular sequencer rank 5, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ5_0               (0x1UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00010000 */
#define ADC_CHSELR_SQ5_1               (0x2UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00020000 */
#define ADC_CHSELR_SQ5_2               (0x4UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00040000 */
#define ADC_CHSELR_SQ5_3               (0x8UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00080000 */

#define ADC_CHSELR_SQ4_Pos             (12U)
#define ADC_CHSELR_SQ4_Msk             (0xFUL << ADC_CHSELR_SQ4_Pos)           /*!< 0x0000F000 */
#define ADC_CHSELR_SQ4                 ADC_CHSELR_SQ4_Msk                      /*!< ADC group regular sequencer rank 4, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ4_0               (0x1UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00001000 */
#define ADC_CHSELR_SQ4_1               (0x2UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00002000 */
#define ADC_CHSELR_SQ4_2               (0x4UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00004000 */
#define ADC_CHSELR_SQ4_3               (0x8UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00008000 */

#define ADC_CHSELR_SQ3_Pos             (8U)
#define ADC_CHSELR_SQ3_Msk             (0xFUL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000F00 */
#define ADC_CHSELR_SQ3                 ADC_CHSELR_SQ3_Msk                      /*!< ADC group regular sequencer rank 3, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ3_0               (0x1UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000100 */
#define ADC_CHSELR_SQ3_1               (0x2UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000200 */
#define ADC_CHSELR_SQ3_2               (0x4UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000400 */
#define ADC_CHSELR_SQ3_3               (0x8UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000800 */

#define ADC_CHSELR_SQ2_Pos             (4U)
#define ADC_CHSELR_SQ2_Msk             (0xFUL << ADC_CHSELR_SQ2_Pos)           /*!< 0x000000F0 */
#define ADC_CHSELR_SQ2                 ADC_CHSELR_SQ2_Msk                      /*!< ADC group regular sequencer rank 2, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ2_0               (0x1UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000010 */
#define ADC_CHSELR_SQ2_1               (0x2UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000020 */
#define ADC_CHSELR_SQ2_2               (0x4UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000040 */
#define ADC_CHSELR_SQ2_3               (0x8UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000080 */

#define ADC_CHSELR_SQ1_Pos             (0U)
#define ADC_CHSELR_SQ1_Msk             (0xFUL << ADC_CHSELR_SQ1_Pos)           /*!< 0x0000000F */
#define ADC_CHSELR_SQ1                 ADC_CHSELR_SQ1_Msk                      /*!< ADC group regular sequencer rank 1, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ1_0               (0x1UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000001 */
#define ADC_CHSELR_SQ1_1               (0x2UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000002 */
#define ADC_CHSELR_SQ1_2               (0x4UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000004 */
#define ADC_CHSELR_SQ1_3               (0x8UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000008 */

/********************  Bit definition for ADC_AWD3TR register  *******************/
#define ADC_AWD3TR_LT3_Pos             (0U)
#define ADC_AWD3TR_LT3_Msk             (0xFFFUL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000FFF */
#define ADC_AWD3TR_LT3                 ADC_AWD3TR_LT3_Msk                      /*!< ADC analog watchdog 3 threshold low */
#define ADC_AWD3TR_LT3_0               (0x001UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000001 */
#define ADC_AWD3TR_LT3_1               (0x002UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000002 */
#define ADC_AWD3TR_LT3_2               (0x004UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000004 */
#define ADC_AWD3TR_LT3_3               (0x008UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000008 */
#define ADC_AWD3TR_LT3_4               (0x010UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000010 */
#define ADC_AWD3TR_LT3_5               (0x020UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000020 */
#define ADC_AWD3TR_LT3_6               (0x040UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000040 */
#define ADC_AWD3TR_LT3_7               (0x080UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000080 */
#define ADC_AWD3TR_LT3_8               (0x100UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000100 */
#define ADC_AWD3TR_LT3_9               (0x200UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000200 */
#define ADC_AWD3TR_LT3_10              (0x400UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000400 */
#define ADC_AWD3TR_LT3_11              (0x800UL << ADC_AWD3TR_LT3_Pos)         /*!< 0x00000800 */

#define ADC_AWD3TR_HT3_Pos             (16U)
#define ADC_AWD3TR_HT3_Msk             (0xFFFUL << ADC_AWD3TR_HT3_Pos)         /*!< 0x0FFF0000 */
#define ADC_AWD3TR_HT3                 ADC_AWD3TR_HT3_Msk                      /*!< ADC analog watchdog 3 threshold high */
#define ADC_AWD3TR_HT3_0               (0x001UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00010000 */
#define ADC_AWD3TR_HT3_1               (0x002UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00020000 */
#define ADC_AWD3TR_HT3_2               (0x004UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00040000 */
#define ADC_AWD3TR_HT3_3               (0x008UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00080000 */
#define ADC_AWD3TR_HT3_4               (0x010UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00100000 */
#define ADC_AWD3TR_HT3_5               (0x020UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00200000 */
#define ADC_AWD3TR_HT3_6               (0x040UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00400000 */
#define ADC_AWD3TR_HT3_7               (0x080UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x00800000 */
#define ADC_AWD3TR_HT3_8               (0x100UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x01000000 */
#define ADC_AWD3TR_HT3_9               (0x200UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x02000000 */
#define ADC_AWD3TR_HT3_10              (0x400UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x04000000 */
#define ADC_AWD3TR_HT3_11              (0x800UL << ADC_AWD3TR_HT3_Pos)         /*!< 0x08000000 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos                (0U)
#define ADC_DR_DATA_Msk                (0xFFFFUL << ADC_DR_DATA_Pos)           /*!< 0x0000FFFF */
#define ADC_DR_DATA                    ADC_DR_DATA_Msk                         /*!< ADC group regular conversion data */

/********************  Bit definition for ADC_PWRR register  ******************/
#define ADC_PWRR_AUTOFF_Pos            (0U)
#define ADC_PWRR_AUTOFF_Msk            (0x1UL << ADC_PWRR_AUTOFF_Pos)          /*!< 0x00000001 */
#define ADC_PWRR_AUTOFF                ADC_PWRR_AUTOFF_Msk                     /*!< ADC auto-off mode */
#define ADC_PWRR_DPD_Pos               (1U)
#define ADC_PWRR_DPD_Msk               (0x1UL << ADC_PWRR_DPD_Pos)             /*!< 0x00000002 */
#define ADC_PWRR_DPD                   ADC_PWRR_DPD_Msk                        /*!< ADC deep power down mode */

/********************  Bit definition for ADC_AWD2CR register  ****************/
#define ADC_AWD2CR_AWD2CH_Pos          (0U)
#define ADC_AWD2CR_AWD2CH_Msk          (0x3FFFFUL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x0003FFFF */
#define ADC_AWD2CR_AWD2CH              ADC_AWD2CR_AWD2CH_Msk                   /*!< ADC analog watchdog 2 monitored channel selection */
#define ADC_AWD2CR_AWD2CH_0            (0x00001UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000001 */
#define ADC_AWD2CR_AWD2CH_1            (0x00002UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000002 */
#define ADC_AWD2CR_AWD2CH_2            (0x00004UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000004 */
#define ADC_AWD2CR_AWD2CH_3            (0x00008UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000008 */
#define ADC_AWD2CR_AWD2CH_4            (0x00010UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000010 */
#define ADC_AWD2CR_AWD2CH_5            (0x00020UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000020 */
#define ADC_AWD2CR_AWD2CH_6            (0x00040UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000040 */
#define ADC_AWD2CR_AWD2CH_7            (0x00080UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000080 */
#define ADC_AWD2CR_AWD2CH_8            (0x00100UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000100 */
#define ADC_AWD2CR_AWD2CH_9            (0x00200UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000200 */
#define ADC_AWD2CR_AWD2CH_10           (0x00400UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000400 */
#define ADC_AWD2CR_AWD2CH_11           (0x00800UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000800 */
#define ADC_AWD2CR_AWD2CH_12           (0x01000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00001000 */
#define ADC_AWD2CR_AWD2CH_13           (0x02000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00002000 */
#define ADC_AWD2CR_AWD2CH_14           (0x04000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00004000 */
#define ADC_AWD2CR_AWD2CH_15           (0x08000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00008000 */
#define ADC_AWD2CR_AWD2CH_16           (0x10000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00010000 */
#define ADC_AWD2CR_AWD2CH_17           (0x20000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00020000 */

/********************  Bit definition for ADC_AWD3CR register  ****************/
#define ADC_AWD3CR_AWD3CH_Pos          (0U)
#define ADC_AWD3CR_AWD3CH_Msk          (0x3FFFFUL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x0003FFFF */
#define ADC_AWD3CR_AWD3CH              ADC_AWD3CR_AWD3CH_Msk                   /*!< ADC analog watchdog 3 monitored channel selection */
#define ADC_AWD3CR_AWD3CH_0            (0x00001UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000001 */
#define ADC_AWD3CR_AWD3CH_1            (0x00002UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000002 */
#define ADC_AWD3CR_AWD3CH_2            (0x00004UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000004 */
#define ADC_AWD3CR_AWD3CH_3            (0x00008UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000008 */
#define ADC_AWD3CR_AWD3CH_4            (0x00010UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000010 */
#define ADC_AWD3CR_AWD3CH_5            (0x00020UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000020 */
#define ADC_AWD3CR_AWD3CH_6            (0x00040UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000040 */
#define ADC_AWD3CR_AWD3CH_7            (0x00080UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000080 */
#define ADC_AWD3CR_AWD3CH_8            (0x00100UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000100 */
#define ADC_AWD3CR_AWD3CH_9            (0x00200UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000200 */
#define ADC_AWD3CR_AWD3CH_10           (0x00400UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000400 */
#define ADC_AWD3CR_AWD3CH_11           (0x00800UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000800 */
#define ADC_AWD3CR_AWD3CH_12           (0x01000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00001000 */
#define ADC_AWD3CR_AWD3CH_13           (0x02000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00002000 */
#define ADC_AWD3CR_AWD3CH_14           (0x04000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00004000 */
#define ADC_AWD3CR_AWD3CH_15           (0x08000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00008000 */
#define ADC_AWD3CR_AWD3CH_16           (0x10000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00010000 */
#define ADC_AWD3CR_AWD3CH_17           (0x20000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00020000 */

/********************  Bit definition for ADC_CALFACT register  ***************/
#define ADC_CALFACT_CALFACT_Pos        (0U)
#define ADC_CALFACT_CALFACT_Msk        (0x7FUL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x0000007F */
#define ADC_CALFACT_CALFACT            ADC_CALFACT_CALFACT_Msk                 /*!< ADC calibration factor in single-ended mode */
#define ADC_CALFACT_CALFACT_0          (0x01UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000001 */
#define ADC_CALFACT_CALFACT_1          (0x02UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000002 */
#define ADC_CALFACT_CALFACT_2          (0x04UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000004 */
#define ADC_CALFACT_CALFACT_3          (0x08UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000008 */
#define ADC_CALFACT_CALFACT_4          (0x10UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000010 */
#define ADC_CALFACT_CALFACT_5          (0x20UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000020 */
#define ADC_CALFACT_CALFACT_6          (0x40UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000040 */

/*************************  ADC Common registers  *****************************/
/********************  Bit definition for ADC_CCR register  *******************/
#define ADC_CCR_PRESC_Pos              (18U)
#define ADC_CCR_PRESC_Msk              (0xFUL << ADC_CCR_PRESC_Pos)            /*!< 0x003C0000 */
#define ADC_CCR_PRESC                  ADC_CCR_PRESC_Msk                       /*!< ADC common clock prescaler */
#define ADC_CCR_PRESC_0                (0x1UL << ADC_CCR_PRESC_Pos)            /*!< 0x00040000 */
#define ADC_CCR_PRESC_1                (0x2UL << ADC_CCR_PRESC_Pos)            /*!< 0x00080000 */
#define ADC_CCR_PRESC_2                (0x4UL << ADC_CCR_PRESC_Pos)            /*!< 0x00100000 */
#define ADC_CCR_PRESC_3                (0x8UL << ADC_CCR_PRESC_Pos)            /*!< 0x00200000 */

#define ADC_CCR_VREFEN_Pos             (22U)
#define ADC_CCR_VREFEN_Msk             (0x1UL << ADC_CCR_VREFEN_Pos)           /*!< 0x00400000 */
#define ADC_CCR_VREFEN                 ADC_CCR_VREFEN_Msk                      /*!< ADC internal path to VrefInt enable */
#define ADC_CCR_TSEN_Pos               (23U)
#define ADC_CCR_TSEN_Msk               (0x1UL << ADC_CCR_TSEN_Pos)             /*!< 0x00800000 */
#define ADC_CCR_TSEN                   ADC_CCR_TSEN_Msk                        /*!< ADC internal path to temperature sensor enable */


/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos                       (0U)
#define CRC_DR_DR_Msk                       (0xFFFFFFFFUL << CRC_DR_DR_Pos)         /*!< 0xFFFFFFFF */
#define CRC_DR_DR                           CRC_DR_DR_Msk                           /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos                     (0U)
#define CRC_IDR_IDR_Msk                     (0xFFFFFFFFUL << CRC_IDR_IDR_Pos)       /*!< 0xFFFFFFFF */
#define CRC_IDR_IDR                         CRC_IDR_IDR_Msk                         /*!< General-purpose 32-bits data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos                    (0U)
#define CRC_CR_RESET_Msk                    (0x1UL << CRC_CR_RESET_Pos)             /*!< 0x00000001 */
#define CRC_CR_RESET                        CRC_CR_RESET_Msk                        /*!< RESET the CRC computation unit bit */
#define CRC_CR_POLYSIZE_Pos                 (3U)
#define CRC_CR_POLYSIZE_Msk                 (0x3UL << CRC_CR_POLYSIZE_Pos)          /*!< 0x00000018 */
#define CRC_CR_POLYSIZE                     CRC_CR_POLYSIZE_Msk                     /*!< Polynomial size bits */
#define CRC_CR_POLYSIZE_0                   (0x1UL << CRC_CR_POLYSIZE_Pos)          /*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1                   (0x2UL << CRC_CR_POLYSIZE_Pos)          /*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos                   (5U)
#define CRC_CR_REV_IN_Msk                   (0x3UL << CRC_CR_REV_IN_Pos)            /*!< 0x00000060 */
#define CRC_CR_REV_IN                       CRC_CR_REV_IN_Msk                       /*!< REV_IN Reverse Input Data bits */
#define CRC_CR_REV_IN_0                     (0x1UL << CRC_CR_REV_IN_Pos)            /*!< 0x00000020 */
#define CRC_CR_REV_IN_1                     (0x2UL << CRC_CR_REV_IN_Pos)            /*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos                  (7U)
#define CRC_CR_REV_OUT_Msk                  (0x1UL << CRC_CR_REV_OUT_Pos)           /*!< 0x00000080 */
#define CRC_CR_REV_OUT                      CRC_CR_REV_OUT_Msk                      /*!< REV_OUT Reverse Output Data bits */

/*******************  Bit definition for CRC_INIT register  *******************/
#define CRC_INIT_INIT_Pos                   (0U)
#define CRC_INIT_INIT_Msk                   (0xFFFFFFFFUL << CRC_INIT_INIT_Pos)     /*!< 0xFFFFFFFF */
#define CRC_INIT_INIT                       CRC_INIT_INIT_Msk                       /*!< Initial CRC value bits */

/*******************  Bit definition for CRC_POL register  ********************/
#define CRC_POL_POL_Pos                     (0U)
#define CRC_POL_POL_Msk                     (0xFFFFFFFFUL << CRC_POL_POL_Pos)       /*!< 0xFFFFFFFF */
#define CRC_POL_POL                         CRC_POL_POL_Msk                         /*!< Coefficients of the polynomial */


/******************************************************************************/
/*                                                                            */
/*                       Advanced Encryption Standard (AES)                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for AES_CR register  *********************/
#define AES_CR_EN_Pos                       (0U)
#define AES_CR_EN_Msk                       (0x1UL << AES_CR_EN_Pos)                /*!< 0x00000001 */
#define AES_CR_EN                           AES_CR_EN_Msk                           /*!< AES Enable */
#define AES_CR_DATATYPE_Pos                 (1U)
#define AES_CR_DATATYPE_Msk                 (0x3UL << AES_CR_DATATYPE_Pos)          /*!< 0x00000006 */
#define AES_CR_DATATYPE                     AES_CR_DATATYPE_Msk                     /*!< Data type selection */
#define AES_CR_DATATYPE_0                   (0x1UL << AES_CR_DATATYPE_Pos)          /*!< 0x00000002 */
#define AES_CR_DATATYPE_1                   (0x2UL << AES_CR_DATATYPE_Pos)          /*!< 0x00000004 */
#define AES_CR_MODE_Pos                     (3U)
#define AES_CR_MODE_Msk                     (0x3UL << AES_CR_MODE_Pos)              /*!< 0x00000018 */
#define AES_CR_MODE                         AES_CR_MODE_Msk                         /*!< AES Mode Of Operation */
#define AES_CR_MODE_0                       (0x1UL << AES_CR_MODE_Pos)              /*!< 0x00000008 */
#define AES_CR_MODE_1                       (0x2UL << AES_CR_MODE_Pos)              /*!< 0x00000010 */
#define AES_CR_CHMOD_Pos                    (5U)
#define AES_CR_CHMOD_Msk                    (0x803UL << AES_CR_CHMOD_Pos)           /*!< 0x00010060 */
#define AES_CR_CHMOD                        AES_CR_CHMOD_Msk                        /*!< AES Chaining Mode */
#define AES_CR_CHMOD_0                      (0x001UL << AES_CR_CHMOD_Pos)           /*!< 0x00000020 */
#define AES_CR_CHMOD_1                      (0x002UL << AES_CR_CHMOD_Pos)           /*!< 0x00000040 */
#define AES_CR_CHMOD_2                      (0x800UL << AES_CR_CHMOD_Pos)           /*!< 0x00010000 */
#define AES_CR_DMAINEN_Pos                  (11U)
#define AES_CR_DMAINEN_Msk                  (0x1UL << AES_CR_DMAINEN_Pos)           /*!< 0x00000800 */
#define AES_CR_DMAINEN                      AES_CR_DMAINEN_Msk                      /*!< Enable data input phase DMA management  */
#define AES_CR_DMAOUTEN_Pos                 (12U)
#define AES_CR_DMAOUTEN_Msk                 (0x1UL << AES_CR_DMAOUTEN_Pos)          /*!< 0x00001000 */
#define AES_CR_DMAOUTEN                     AES_CR_DMAOUTEN_Msk                     /*!< Enable data output phase DMA management */
#define AES_CR_GCMPH_Pos                    (13U)
#define AES_CR_GCMPH_Msk                    (0x3UL << AES_CR_GCMPH_Pos)             /*!< 0x00006000 */
#define AES_CR_GCMPH                        AES_CR_GCMPH_Msk                        /*!< GCM Phase */
#define AES_CR_GCMPH_0                      (0x1UL << AES_CR_GCMPH_Pos)             /*!< 0x00002000 */
#define AES_CR_GCMPH_1                      (0x2UL << AES_CR_GCMPH_Pos)             /*!< 0x00004000 */
#define AES_CR_KEYSIZE_Pos                  (18U)
#define AES_CR_KEYSIZE_Msk                  (0x1UL << AES_CR_KEYSIZE_Pos)           /*!< 0x00040000 */
#define AES_CR_KEYSIZE                      AES_CR_KEYSIZE_Msk                      /*!< Key size selection */
#define AES_CR_NPBLB_Pos                    (20U)
#define AES_CR_NPBLB_Msk                    (0xFUL << AES_CR_NPBLB_Pos)             /*!< 0x00F00000 */
#define AES_CR_NPBLB                        AES_CR_NPBLB_Msk                        /*!< Number of padding bytes in payload last block */
#define AES_CR_NPBLB_0                      (0x1UL << AES_CR_NPBLB_Pos)             /*!< 0x00100000 */
#define AES_CR_NPBLB_1                      (0x2UL << AES_CR_NPBLB_Pos)             /*!< 0x00200000 */
#define AES_CR_NPBLB_2                      (0x4UL << AES_CR_NPBLB_Pos)             /*!< 0x00400000 */
#define AES_CR_NPBLB_3                      (0x8UL << AES_CR_NPBLB_Pos)             /*!< 0x00800000 */
#define AES_CR_KMOD_Pos                     (24U)
#define AES_CR_KMOD_Msk                     (0x3UL << AES_CR_KMOD_Pos)              /*!< 0x03000000 */
#define AES_CR_KMOD                         AES_CR_KMOD_Msk                         /*!< Key mode selection */
#define AES_CR_KMOD_0                       (0x1UL << AES_CR_KMOD_Pos)              /*!< 0x01000000 */
#define AES_CR_KMOD_1                       (0x2UL << AES_CR_KMOD_Pos)              /*!< 0x02000000 */
#define AES_CR_IPRST_Pos                    (31U)
#define AES_CR_IPRST_Msk                    (0x1UL << AES_CR_IPRST_Pos)             /*!< 0x80000000 */
#define AES_CR_IPRST                        AES_CR_IPRST_Msk                        /*!< AES IP software reset */


/*******************  Bit definition for AES_SR register  *********************/
#define AES_SR_CCF_Pos                      (0U)
#define AES_SR_CCF_Msk                      (0x1UL << AES_SR_CCF_Pos)               /*!< 0x00000001 */
#define AES_SR_CCF                          AES_SR_CCF_Msk                          /*!< Computation Complete Flag */
#define AES_SR_RDERR_Pos                    (1U)
#define AES_SR_RDERR_Msk                    (0x1UL << AES_SR_RDERR_Pos)             /*!< 0x00000002 */
#define AES_SR_RDERR                        AES_SR_RDERR_Msk                        /*!< Read Error Flag */
#define AES_SR_WRERR_Pos                    (2U)
#define AES_SR_WRERR_Msk                    (0x1UL << AES_SR_WRERR_Pos)             /*!< 0x00000004 */
#define AES_SR_WRERR                        AES_SR_WRERR_Msk                        /*!< Write Error Flag */
#define AES_SR_BUSY_Pos                     (3U)
#define AES_SR_BUSY_Msk                     (0x1UL << AES_SR_BUSY_Pos)              /*!< 0x00000008 */
#define AES_SR_BUSY                         AES_SR_BUSY_Msk                         /*!< Busy Flag */
#define AES_SR_KEYVALID_Pos                 (7U)
#define AES_SR_KEYVALID_Msk                 (0x1UL << AES_SR_KEYVALID_Pos)          /*!< 0x00000080 */
#define AES_SR_KEYVALID                     AES_SR_KEYVALID_Msk                     /*!< Key Valid Flag */

/*******************  Bit definition for AES_DINR register  *******************/
#define AES_DINR_Pos                        (0U)
#define AES_DINR_Msk                        (0xFFFFFFFFUL << AES_DINR_Pos)          /*!< 0xFFFFFFFF */
#define AES_DINR                            AES_DINR_Msk                            /*!< AES Data Input Register */

/*******************  Bit definition for AES_DOUTR register  ******************/
#define AES_DOUTR_Pos                       (0U)
#define AES_DOUTR_Msk                       (0xFFFFFFFFUL << AES_DOUTR_Pos)         /*!< 0xFFFFFFFF */
#define AES_DOUTR                           AES_DOUTR_Msk                           /*!< AES Data Output Register */

/*******************  Bit definition for AES_KEYR0 register  ******************/
#define AES_KEYR0_Pos                       (0U)
#define AES_KEYR0_Msk                       (0xFFFFFFFFUL << AES_KEYR0_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR0                           AES_KEYR0_Msk                           /*!< AES Key Register 0 */

/*******************  Bit definition for AES_KEYR1 register  ******************/
#define AES_KEYR1_Pos                       (0U)
#define AES_KEYR1_Msk                       (0xFFFFFFFFUL << AES_KEYR1_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR1                           AES_KEYR1_Msk                           /*!< AES Key Register 1 */

/*******************  Bit definition for AES_KEYR2 register  ******************/
#define AES_KEYR2_Pos                       (0U)
#define AES_KEYR2_Msk                       (0xFFFFFFFFUL << AES_KEYR2_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR2                           AES_KEYR2_Msk                           /*!< AES Key Register 2 */

/*******************  Bit definition for AES_KEYR3 register  ******************/
#define AES_KEYR3_Pos                       (0U)
#define AES_KEYR3_Msk                       (0xFFFFFFFFUL << AES_KEYR3_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR3                           AES_KEYR3_Msk                           /*!< AES Key Register 3 */

/*******************  Bit definition for AES_KEYR4 register  ******************/
#define AES_KEYR4_Pos                       (0U)
#define AES_KEYR4_Msk                       (0xFFFFFFFFUL << AES_KEYR4_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR4                           AES_KEYR4_Msk                           /*!< AES Key Register 4 */

/*******************  Bit definition for AES_KEYR5 register  ******************/
#define AES_KEYR5_Pos                       (0U)
#define AES_KEYR5_Msk                       (0xFFFFFFFFUL << AES_KEYR5_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR5                           AES_KEYR5_Msk                           /*!< AES Key Register 5 */

/*******************  Bit definition for AES_KEYR6 register  ******************/
#define AES_KEYR6_Pos                       (0U)
#define AES_KEYR6_Msk                       (0xFFFFFFFFUL << AES_KEYR6_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR6                           AES_KEYR6_Msk                           /*!< AES Key Register 6 */

/*******************  Bit definition for AES_KEYR7 register  ******************/
#define AES_KEYR7_Pos                       (0U)
#define AES_KEYR7_Msk                       (0xFFFFFFFFUL << AES_KEYR7_Pos)         /*!< 0xFFFFFFFF */
#define AES_KEYR7                           AES_KEYR7_Msk                           /*!< AES Key Register 7 */

/*******************  Bit definition for AES_IVR0 register   ******************/
#define AES_IVR0_Pos                        (0U)
#define AES_IVR0_Msk                        (0xFFFFFFFFUL << AES_IVR0_Pos)          /*!< 0xFFFFFFFF */
#define AES_IVR0                            AES_IVR0_Msk                            /*!< AES Initialization Vector Register 0 */

/*******************  Bit definition for AES_IVR1 register   ******************/
#define AES_IVR1_Pos                        (0U)
#define AES_IVR1_Msk                        (0xFFFFFFFFUL << AES_IVR1_Pos)          /*!< 0xFFFFFFFF */
#define AES_IVR1                            AES_IVR1_Msk                            /*!< AES Initialization Vector Register 1 */

/*******************  Bit definition for AES_IVR2 register   ******************/
#define AES_IVR2_Pos                        (0U)
#define AES_IVR2_Msk                        (0xFFFFFFFFUL << AES_IVR2_Pos)          /*!< 0xFFFFFFFF */
#define AES_IVR2                            AES_IVR2_Msk                            /*!< AES Initialization Vector Register 2 */

/*******************  Bit definition for AES_IVR3 register   ******************/
#define AES_IVR3_Pos                        (0U)
#define AES_IVR3_Msk                        (0xFFFFFFFFUL << AES_IVR3_Pos)          /*!< 0xFFFFFFFF */
#define AES_IVR3                            AES_IVR3_Msk                            /*!< AES Initialization Vector Register 3 */

/*******************  Bit definition for AES_SUSP0R register  ******************/
#define AES_SUSP0R_Pos                      (0U)
#define AES_SUSP0R_Msk                      (0xFFFFFFFFUL << AES_SUSP0R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP0R                          AES_SUSP0R_Msk                          /*!< AES Suspend registers 0 */

/*******************  Bit definition for AES_SUSP1R register  ******************/
#define AES_SUSP1R_Pos                      (0U)
#define AES_SUSP1R_Msk                      (0xFFFFFFFFUL << AES_SUSP1R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP1R                          AES_SUSP1R_Msk                          /*!< AES Suspend registers 1 */

/*******************  Bit definition for AES_SUSP2R register  ******************/
#define AES_SUSP2R_Pos                      (0U)
#define AES_SUSP2R_Msk                      (0xFFFFFFFFUL << AES_SUSP2R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP2R                          AES_SUSP2R_Msk                          /*!< AES Suspend registers 2 */

/*******************  Bit definition for AES_SUSP3R register  ******************/
#define AES_SUSP3R_Pos                      (0U)
#define AES_SUSP3R_Msk                      (0xFFFFFFFFUL << AES_SUSP3R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP3R                          AES_SUSP3R_Msk                          /*!< AES Suspend registers 3 */

/*******************  Bit definition for AES_SUSP4R register  ******************/
#define AES_SUSP4R_Pos                      (0U)
#define AES_SUSP4R_Msk                      (0xFFFFFFFFUL << AES_SUSP4R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP4R                          AES_SUSP4R_Msk                          /*!< AES Suspend registers 4 */

/*******************  Bit definition for AES_SUSP5R register  ******************/
#define AES_SUSP5R_Pos                      (0U)
#define AES_SUSP5R_Msk                      (0xFFFFFFFFUL << AES_SUSP5R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP5R                          AES_SUSP5R_Msk                          /*!< AES Suspend registers 5 */

/*******************  Bit definition for AES_SUSP6R register  ******************/
#define AES_SUSP6R_Pos                      (0U)
#define AES_SUSP6R_Msk                      (0xFFFFFFFFUL << AES_SUSP6R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP6R                          AES_SUSP6R_Msk                          /*!< AES Suspend registers 6 */

/*******************  Bit definition for AES_SUSP7R register  ******************/
#define AES_SUSP7R_Pos                      (0U)
#define AES_SUSP7R_Msk                      (0xFFFFFFFFUL << AES_SUSP7R_Pos)        /*!< 0xFFFFFFFF */
#define AES_SUSP7R                          AES_SUSP7R_Msk                          /*!< AES Suspend registers 7 */

/*******************  Bit definition for AES_IER register     ******************/
#define AES_IER_CCFIE_Pos                   (0U)
#define AES_IER_CCFIE_Msk                   (0x1UL << AES_IER_CCFIE_Pos)            /*!< 0x00000001 */
#define AES_IER_CCFIE                       AES_IER_CCFIE_Msk                       /*!< Computation complete flag interrupt enable */
#define AES_IER_RWEIE_Pos                   (1U)
#define AES_IER_RWEIE_Msk                   (0x1UL << AES_IER_RWEIE_Pos)            /*!< 0x00000002 */
#define AES_IER_RWEIE                       AES_IER_RWEIE_Msk                       /*!< Read or write error Interrupt Enable */
#define AES_IER_KEIE_Pos                    (2U)
#define AES_IER_KEIE_Msk                    (0x1UL << AES_IER_KEIE_Pos)             /*!< 0x00000004 */
#define AES_IER_KEIE                        AES_IER_KEIE_Msk                        /*!< Key error interrupt enable */
#define AES_IER_RNGEIE_Pos                  (3U)
#define AES_IER_RNGEIE_Msk                  (0x1UL << AES_IER_RNGEIE_Pos)           /*!< 0x00000008 */
#define AES_IER_RNGEIE                      AES_IER_RNGEIE_Msk                      /*!< SAES Rng error interrupt enable */

/*******************  Bit definition for AES_ISR register     ******************/
#define AES_ISR_CCF_Pos                     (0U)
#define AES_ISR_CCF_Msk                     (0x1UL << AES_ISR_CCF_Pos)              /*!< 0x00000001 */
#define AES_ISR_CCF                         AES_ISR_CCF_Msk                         /*!< Computation complete flag */
#define AES_ISR_RWEIF_Pos                   (1U)
#define AES_ISR_RWEIF_Msk                   (0x1UL << AES_ISR_RWEIF_Pos)            /*!< 0x00000002 */
#define AES_ISR_RWEIF                       AES_ISR_RWEIF_Msk                       /*!< Read or write error Interrupt flag */
#define AES_ISR_KEIF_Pos                    (2U)
#define AES_ISR_KEIF_Msk                    (0x1UL << AES_ISR_KEIF_Pos)             /*!< 0x00000004 */
#define AES_ISR_KEIF                        AES_ISR_KEIF_Msk                        /*!< Key error interrupt flag */
#define AES_ISR_RNGEIF_Pos                  (3U)
#define AES_ISR_RNGEIF_Msk                  (0x1UL << AES_ISR_RNGEIF_Pos)           /*!< 0x00000008 */
#define AES_ISR_RNGEIF                      AES_ISR_RNGEIF_Msk                      /*!< SAES Rng error interrupt flag */

/*******************  Bit definition for AES_ICR register     ******************/
#define AES_ICR_CCF_Pos                     (0U)
#define AES_ICR_CCF_Msk                     (0x1UL << AES_ICR_CCF_Pos)              /*!< 0x00000001 */
#define AES_ICR_CCF                         AES_ICR_CCF_Msk                         /*!< Computation complete flag clear */
#define AES_ICR_RWEIF_Pos                   (1U)
#define AES_ICR_RWEIF_Msk                   (0x1UL << AES_ICR_RWEIF_Pos)            /*!< 0x00000002 */
#define AES_ICR_RWEIF                       AES_ICR_RWEIF_Msk                       /*!< Read or write error Interrupt flag clear */
#define AES_ICR_KEIF_Pos                    (2U)
#define AES_ICR_KEIF_Msk                    (0x1UL << AES_ICR_KEIF_Pos)             /*!< 0x00000004 */
#define AES_ICR_KEIF                        AES_ICR_KEIF_Msk                        /*!< Key error interrupt flag clear */
#define AES_ICR_RNGEIF_Pos                  (3U)
#define AES_ICR_RNGEIF_Msk                  (0x1UL << AES_ICR_RNGEIF_Pos)           /*!< 0x00000008 */
#define AES_ICR_RNGEIF                      AES_ICR_RNGEIF_Msk                      /*!< SAES Rng error interrupt flag clear */

/******************************************************************************/
/*                                                                            */
/*                                 Debug MCU                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID_Pos            (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk            (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos)   /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                DBGMCU_IDCODE_DEV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_Pos            (16U)
#define DBGMCU_IDCODE_REV_ID_Msk            (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos)  /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                DBGMCU_IDCODE_REV_ID_Msk

/********************  Bit definition for DBGMCU_SCR register  *****************/
#define DBGMCU_SCR_DBG_STOP_Pos             (1U)
#define DBGMCU_SCR_DBG_STOP_Msk             (0x1UL << DBGMCU_SCR_DBG_STOP_Pos)      /*!< 0x00000002 */
#define DBGMCU_SCR_DBG_STOP                 DBGMCU_SCR_DBG_STOP_Msk
#define DBGMCU_SCR_DBG_STANDBY_Pos          (2U)
#define DBGMCU_SCR_DBG_STANDBY_Msk          (0x1UL << DBGMCU_SCR_DBG_STANDBY_Pos)   /*!< 0x00000004 */
#define DBGMCU_SCR_DBG_STANDBY              DBGMCU_SCR_DBG_STANDBY_Msk
#define DBGMCU_SCR_DBG_LPMS_Pos             (16U)
#define DBGMCU_SCR_DBG_LPMS_Msk             (0x7UL << DBGMCU_SCR_DBG_LPMS_Pos)      /*!< 0x00070000 */
#define DBGMCU_SCR_DBG_LPMS                 DBGMCU_SCR_DBG_LPMS_Msk
#define DBGMCU_SCR_DBG_LPMS_0               (0x1UL << DBGMCU_SCR_DBG_LPMS_Pos)
#define DBGMCU_SCR_DBG_LPMS_1               (0x2UL << DBGMCU_SCR_DBG_LPMS_Pos)
#define DBGMCU_SCR_DBG_LPMS_2               (0x4UL << DBGMCU_SCR_DBG_LPMS_Pos)
#define DBGMCU_SCR_DBG_STOPF_Pos            (19U)
#define DBGMCU_SCR_DBG_STOPF_Msk            (0x1UL << DBGMCU_SCR_DBG_STOPF_Pos)     /*!< 0x00080000 */
#define DBGMCU_SCR_DBG_STOPF                DBGMCU_SCR_DBG_STOPF_Msk
#define DBGMCU_SCR_DBG_SBF_Pos              (20U)
#define DBGMCU_SCR_DBG_SBF_Msk              (0x1UL << DBGMCU_SCR_DBG_SBF_Pos)       /*!< 0x00100000 */
#define DBGMCU_SCR_DBG_SBF                  DBGMCU_SCR_DBG_SBF_Msk
#define DBGMCU_SCR_DBG_CS_Pos               (24U)
#define DBGMCU_SCR_DBG_CS_Msk               (0x1UL << DBGMCU_SCR_DBG_CS_Pos)        /*!< 0x01000000 */
#define DBGMCU_SCR_DBG_CS                   DBGMCU_SCR_DBG_CS_Msk
#define DBGMCU_SCR_DBG_CDS_Pos              (25U)
#define DBGMCU_SCR_DBG_CDS_Msk              (0x1UL << DBGMCU_SCR_DBG_CDS_Pos)       /*!< 0x02000000 */
#define DBGMCU_SCR_DBG_CDS                  DBGMCU_SCR_DBG_CDS_Msk

/********************  Bit definition for DBGMCU_APB1LFZR register  ***********/
#define DBGMCU_APB1LFZR_DBG_TIM2_STOP_Pos   (0U)
#define DBGMCU_APB1LFZR_DBG_TIM2_STOP_Msk   (0x1UL << DBGMCU_APB1LFZR_DBG_TIM2_STOP_Pos)
#define DBGMCU_APB1LFZR_DBG_TIM2_STOP       DBGMCU_APB1LFZR_DBG_TIM2_STOP_Msk
#define DBGMCU_APB1LFZR_DBG_WWDG_STOP_Pos   (11U)
#define DBGMCU_APB1LFZR_DBG_WWDG_STOP_Msk   (0x1UL << DBGMCU_APB1LFZR_DBG_WWDG_STOP_Pos)
#define DBGMCU_APB1LFZR_DBG_WWDG_STOP       DBGMCU_APB1LFZR_DBG_WWDG_STOP_Msk
#define DBGMCU_APB1LFZR_DBG_IWDG_STOP_Pos   (12U)
#define DBGMCU_APB1LFZR_DBG_IWDG_STOP_Msk   (0x1UL << DBGMCU_APB1LFZR_DBG_IWDG_STOP_Pos)
#define DBGMCU_APB1LFZR_DBG_IWDG_STOP       DBGMCU_APB1LFZR_DBG_IWDG_STOP_Msk

/********************  Bit definition for DBGMCU_APB2FZR register  ***********/
#define DBGMCU_APB2FZR_DBG_TIM1_STOP_Pos    (11U)
#define DBGMCU_APB2FZR_DBG_TIM1_STOP_Msk    (0x1UL << DBGMCU_APB2FZR_DBG_TIM1_STOP_Pos)
#define DBGMCU_APB2FZR_DBG_TIM1_STOP        DBGMCU_APB2FZR_DBG_TIM1_STOP_Msk
#define DBGMCU_APB2FZR_DBG_TIM16_STOP_Pos   (17U)
#define DBGMCU_APB2FZR_DBG_TIM16_STOP_Msk   (0x1UL << DBGMCU_APB2FZR_DBG_TIM16_STOP_Pos)
#define DBGMCU_APB2FZR_DBG_TIM16_STOP       DBGMCU_APB2FZR_DBG_TIM16_STOP_Msk

/********************  Bit definition for DBGMCU_APB7FZR register  ***********/
#define DBGMCU_APB7FZR_DBG_I2C3_STOP_Pos    (10U)
#define DBGMCU_APB7FZR_DBG_I2C3_STOP_Msk    (0x1UL << DBGMCU_APB7FZR_DBG_I2C3_STOP_Pos)
#define DBGMCU_APB7FZR_DBG_I2C3_STOP        DBGMCU_APB7FZR_DBG_I2C3_STOP_Msk
#define DBGMCU_APB7FZR_DBG_LPTIM1_STOP_Pos  (17U)
#define DBGMCU_APB7FZR_DBG_LPTIM1_STOP_Msk  (0x1UL << DBGMCU_APB7FZR_DBG_LPTIM1_STOP_Pos)
#define DBGMCU_APB7FZR_DBG_LPTIM1_STOP      DBGMCU_APB7FZR_DBG_LPTIM1_STOP_Msk
#define DBGMCU_APB7FZR_DBG_RTC_STOP_Pos     (30U)
#define DBGMCU_APB7FZR_DBG_RTC_STOP_Msk     (0x1UL << DBGMCU_APB7FZR_DBG_RTC_STOP_Pos)
#define DBGMCU_APB7FZR_DBG_RTC_STOP         DBGMCU_APB7FZR_DBG_RTC_STOP_Msk

/********************  Bit definition for DBGMCU_AHB1FZR register  ***********/
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH0_STOP_Pos  (0U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH0_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH0_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH0_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH0_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH1_STOP_Pos  (1U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH1_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH1_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH1_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH1_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH2_STOP_Pos  (2U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH2_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH2_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH2_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH2_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH3_STOP_Pos  (3U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH3_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH3_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH3_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH3_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH4_STOP_Pos  (4U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH4_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH4_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH4_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH4_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH5_STOP_Pos  (5U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH5_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH5_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH5_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH5_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH6_STOP_Pos  (6U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH6_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH6_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH6_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH6_STOP_Msk
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH7_STOP_Pos  (7U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH7_STOP_Msk  (0x1UL << DBGMCU_AHB1FZR_DBG_GPDMA1_CH7_STOP_Pos)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_CH7_STOP      DBGMCU_AHB1FZR_DBG_GPDMA1_CH7_STOP_Msk


/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_MISR register  ****************/
#define DMA_MISR_MIS0_Pos                   (0U)
#define DMA_MISR_MIS0_Msk                   (0x1UL << DMA_MISR_MIS0_Pos)            /*!< 0x00000001 */
#define DMA_MISR_MIS0                       DMA_MISR_MIS0_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 0 */
#define DMA_MISR_MIS1_Pos                   (1U)
#define DMA_MISR_MIS1_Msk                   (0x1UL << DMA_MISR_MIS1_Pos)            /*!< 0x00000002 */
#define DMA_MISR_MIS1                       DMA_MISR_MIS1_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 1 */
#define DMA_MISR_MIS2_Pos                   (2U)
#define DMA_MISR_MIS2_Msk                   (0x1UL << DMA_MISR_MIS2_Pos)            /*!< 0x00000004 */
#define DMA_MISR_MIS2                       DMA_MISR_MIS2_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 2 */
#define DMA_MISR_MIS3_Pos                   (3U)
#define DMA_MISR_MIS3_Msk                   (0x1UL << DMA_MISR_MIS3_Pos)            /*!< 0x00000008 */
#define DMA_MISR_MIS3                       DMA_MISR_MIS3_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 3 */
#define DMA_MISR_MIS4_Pos                   (4U)
#define DMA_MISR_MIS4_Msk                   (0x1UL << DMA_MISR_MIS4_Pos)            /*!< 0x00000010 */
#define DMA_MISR_MIS4                       DMA_MISR_MIS4_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 4 */
#define DMA_MISR_MIS5_Pos                   (5U)
#define DMA_MISR_MIS5_Msk                   (0x1UL << DMA_MISR_MIS5_Pos)            /*!< 0x00000020 */
#define DMA_MISR_MIS5                       DMA_MISR_MIS5_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 5 */
#define DMA_MISR_MIS6_Pos                   (6U)
#define DMA_MISR_MIS6_Msk                   (0x1UL << DMA_MISR_MIS6_Pos)            /*!< 0x00000040 */
#define DMA_MISR_MIS6                       DMA_MISR_MIS6_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 6 */
#define DMA_MISR_MIS7_Pos                   (7U)
#define DMA_MISR_MIS7_Msk                   (0x1UL << DMA_MISR_MIS7_Pos)            /*!< 0x00000080 */
#define DMA_MISR_MIS7                       DMA_MISR_MIS7_Msk                       /*!< Masked Interrupt State of Non-Secure Channel 7 */

/*******************  Bit definition for DMA_SMISR register  ****************/
#define DMA_SMISR_MIS0_Pos                  (0U)
#define DMA_SMISR_MIS0_Msk                  (0x1UL << DMA_SMISR_MIS0_Pos)           /*!< 0x00000001 */
#define DMA_SMISR_MIS0                      DMA_SMISR_MIS0_Msk                      /*!< Masked Interrupt State of Secure Channel 0 */
#define DMA_SMISR_MIS1_Pos                  (1U)
#define DMA_SMISR_MIS1_Msk                  (0x1UL << DMA_SMISR_MIS1_Pos)           /*!< 0x00000002 */
#define DMA_SMISR_MIS1                      DMA_SMISR_MIS1_Msk                      /*!< Masked Interrupt State of Secure Channel 1 */
#define DMA_SMISR_MIS2_Pos                  (2U)
#define DMA_SMISR_MIS2_Msk                  (0x1UL << DMA_SMISR_MIS2_Pos)           /*!< 0x00000004 */
#define DMA_SMISR_MIS2                      DMA_SMISR_MIS2_Msk                      /*!< Masked Interrupt State of Secure Channel 2 */
#define DMA_SMISR_MIS3_Pos                  (3U)
#define DMA_SMISR_MIS3_Msk                  (0x1UL << DMA_SMISR_MIS3_Pos)           /*!< 0x00000008 */
#define DMA_SMISR_MIS3                      DMA_SMISR_MIS3_Msk                      /*!< Masked Interrupt State of Secure Channel 3 */
#define DMA_SMISR_MIS4_Pos                  (4U)
#define DMA_SMISR_MIS4_Msk                  (0x1UL << DMA_SMISR_MIS4_Pos)           /*!< 0x00000010 */
#define DMA_SMISR_MIS4                      DMA_SMISR_MIS4_Msk                      /*!< Masked Interrupt State of Secure Channel 4 */
#define DMA_SMISR_MIS5_Pos                  (5U)
#define DMA_SMISR_MIS5_Msk                  (0x1UL << DMA_SMISR_MIS5_Pos)           /*!< 0x00000020 */
#define DMA_SMISR_MIS5                      DMA_SMISR_MIS5_Msk                      /*!< Masked Interrupt State of Secure Channel 5 */
#define DMA_SMISR_MIS6_Pos                  (6U)
#define DMA_SMISR_MIS6_Msk                  (0x1UL << DMA_SMISR_MIS6_Pos)           /*!< 0x00000040 */
#define DMA_SMISR_MIS6                      DMA_SMISR_MIS6_Msk                      /*!< Masked Interrupt State of Secure Channel 6 */
#define DMA_SMISR_MIS7_Pos                  (7U)
#define DMA_SMISR_MIS7_Msk                  (0x1UL << DMA_SMISR_MIS7_Pos)           /*!< 0x00000080 */
#define DMA_SMISR_MIS7                      DMA_SMISR_MIS7_Msk                      /*!< Masked Interrupt State of Secure Channel 7 */

/*******************  Bit definition for DMA_CLBAR register  ****************/
#define DMA_CLBAR_LBA_Pos                   (16U)
#define DMA_CLBAR_LBA_Msk                   (0xFFFFUL << DMA_CLBAR_LBA_Pos)         /*!< 0xFFFF0000 */
#define DMA_CLBAR_LBA                       DMA_CLBAR_LBA_Msk                       /*!< Linked-list Base Address of DMA channel x */

/*******************  Bit definition for DMA_CFCR register  *******************/
#define DMA_CFCR_TCF_Pos                    (8U)
#define DMA_CFCR_TCF_Msk                    (0x1UL << DMA_CFCR_TCF_Pos)             /*!< 0x00000100 */
#define DMA_CFCR_TCF                        DMA_CFCR_TCF_Msk                        /*!< Transfer complete flag clear */
#define DMA_CFCR_HTF_Pos                    (9U)
#define DMA_CFCR_HTF_Msk                    (0x1UL << DMA_CFCR_HTF_Pos)             /*!< 0x00000200 */
#define DMA_CFCR_HTF                        DMA_CFCR_HTF_Msk                        /*!< Half transfer complete flag clear */
#define DMA_CFCR_DTEF_Pos                   (10U)
#define DMA_CFCR_DTEF_Msk                   (0x1UL << DMA_CFCR_DTEF_Pos)            /*!< 0x00000400 */
#define DMA_CFCR_DTEF                       DMA_CFCR_DTEF_Msk                       /*!< Data transfer error flag clear */
#define DMA_CFCR_ULEF_Pos                   (11U)
#define DMA_CFCR_ULEF_Msk                   (0x1UL << DMA_CFCR_ULEF_Pos)            /*!< 0x00000800 */
#define DMA_CFCR_ULEF                       DMA_CFCR_ULEF_Msk                       /*!< Update linked-list item error flag clear */
#define DMA_CFCR_USEF_Pos                   (12U)
#define DMA_CFCR_USEF_Msk                   (0x1UL << DMA_CFCR_USEF_Pos)            /*!< 0x00001000 */
#define DMA_CFCR_USEF                       DMA_CFCR_USEF_Msk                       /*!< User setting error flag clear */
#define DMA_CFCR_SUSPF_Pos                  (13U)
#define DMA_CFCR_SUSPF_Msk                  (0x1UL << DMA_CFCR_SUSPF_Pos)           /*!< 0x00002000 */
#define DMA_CFCR_SUSPF                      DMA_CFCR_SUSPF_Msk                      /*!< Completed suspension flag clear */
#define DMA_CFCR_TOF_Pos                    (14U)
#define DMA_CFCR_TOF_Msk                    (0x1UL << DMA_CFCR_TOF_Pos)             /*!< 0x00004000 */
#define DMA_CFCR_TOF                        DMA_CFCR_TOF_Msk                        /*!< Trigger overrun flag clear */

/*******************  Bit definition for DMA_CSR register  *******************/
#define DMA_CSR_IDLEF_Pos                   (0U)
#define DMA_CSR_IDLEF_Msk                   (0x1UL << DMA_CSR_IDLEF_Pos)            /*!< 0x00000001 */
#define DMA_CSR_IDLEF                       DMA_CSR_IDLEF_Msk                       /*!< Idle flag */
#define DMA_CSR_TCF_Pos                     (8U)
#define DMA_CSR_TCF_Msk                     (0x1UL << DMA_CSR_TCF_Pos)              /*!< 0x00000100 */
#define DMA_CSR_TCF                         DMA_CSR_TCF_Msk                         /*!< Transfer complete flag */
#define DMA_CSR_HTF_Pos                     (9U)
#define DMA_CSR_HTF_Msk                     (0x1UL << DMA_CSR_HTF_Pos)              /*!< 0x00000200 */
#define DMA_CSR_HTF                         DMA_CSR_HTF_Msk                         /*!< Half transfer complete flag */
#define DMA_CSR_DTEF_Pos                    (10U)
#define DMA_CSR_DTEF_Msk                    (0x1UL << DMA_CSR_DTEF_Pos)             /*!< 0x00000400 */
#define DMA_CSR_DTEF                        DMA_CSR_DTEF_Msk                        /*!< Data transfer error flag */
#define DMA_CSR_ULEF_Pos                    (11U)
#define DMA_CSR_ULEF_Msk                    (0x1UL << DMA_CSR_ULEF_Pos)             /*!< 0x00000800 */
#define DMA_CSR_ULEF                        DMA_CSR_ULEF_Msk                        /*!< Update linked-list item error flag */
#define DMA_CSR_USEF_Pos                    (12U)
#define DMA_CSR_USEF_Msk                    (0x1UL << DMA_CSR_USEF_Pos)             /*!< 0x00001000 */
#define DMA_CSR_USEF                        DMA_CSR_USEF_Msk                        /*!< User setting error flag */
#define DMA_CSR_SUSPF_Pos                   (13U)
#define DMA_CSR_SUSPF_Msk                   (0x1UL << DMA_CSR_SUSPF_Pos)            /*!< 0x00002000 */
#define DMA_CSR_SUSPF                       DMA_CSR_SUSPF_Msk                       /*!< User setting error flag */
#define DMA_CSR_TOF_Pos                     (14U)
#define DMA_CSR_TOF_Msk                     (0x1UL << DMA_CSR_TOF_Pos)              /*!< 0x00004000 */
#define DMA_CSR_TOF                         DMA_CSR_TOF_Msk                         /*!< Trigger overrun event flag */
#define DMA_CSR_FIFOL_Pos                   (16U)
#define DMA_CSR_FIFOL_Msk                   (0xFFUL << DMA_CSR_FIFOL_Pos)           /*!< 0x00FF0000 */
#define DMA_CSR_FIFOL                       DMA_CSR_FIFOL_Msk                       /*!< Monitored FIFO level in bytes */

/*******************  Bit definition for DMA_CCR register  ********************/
#define DMA_CCR_EN_Pos                      (0U)
#define DMA_CCR_EN_Msk                      (0x1UL << DMA_CCR_EN_Pos)               /*!< 0x00000001 */
#define DMA_CCR_EN                          DMA_CCR_EN_Msk                          /*!< Channel enable */
#define DMA_CCR_RESET_Pos                   (1U)
#define DMA_CCR_RESET_Msk                   (0x1UL << DMA_CCR_RESET_Pos)            /*!< 0x00000002 */
#define DMA_CCR_RESET                       DMA_CCR_RESET_Msk                       /*!< Channel reset */
#define DMA_CCR_SUSP_Pos                    (2U)
#define DMA_CCR_SUSP_Msk                    (0x1UL << DMA_CCR_SUSP_Pos)             /*!< 0x00000004 */
#define DMA_CCR_SUSP                        DMA_CCR_SUSP_Msk                        /*!< Channel suspend */
#define DMA_CCR_TCIE_Pos                    (8U)
#define DMA_CCR_TCIE_Msk                    (0x1UL << DMA_CCR_TCIE_Pos)             /*!< 0x00000100 */
#define DMA_CCR_TCIE                        DMA_CCR_TCIE_Msk                        /*!< Transfer complete interrupt enable */
#define DMA_CCR_HTIE_Pos                    (9U)
#define DMA_CCR_HTIE_Msk                    (0x1UL << DMA_CCR_HTIE_Pos)             /*!< 0x00000200 */
#define DMA_CCR_HTIE                        DMA_CCR_HTIE_Msk                        /*!< Half transfer complete interrupt enable */
#define DMA_CCR_DTEIE_Pos                   (10U)
#define DMA_CCR_DTEIE_Msk                   (0x1UL << DMA_CCR_DTEIE_Pos)            /*!< 0x00000400 */
#define DMA_CCR_DTEIE                       DMA_CCR_DTEIE_Msk                       /*!< Data transfer error interrupt enable */
#define DMA_CCR_ULEIE_Pos                   (11U)
#define DMA_CCR_ULEIE_Msk                   (0x1UL << DMA_CCR_ULEIE_Pos)            /*!< 0x00000800 */
#define DMA_CCR_ULEIE                       DMA_CCR_ULEIE_Msk                       /*!< Update linked-list item error interrupt enable */
#define DMA_CCR_USEIE_Pos                   (12U)
#define DMA_CCR_USEIE_Msk                   (0x1UL << DMA_CCR_USEIE_Pos)            /*!< 0x00001000 */
#define DMA_CCR_USEIE                       DMA_CCR_USEIE_Msk                       /*!< User setting error interrupt enable */
#define DMA_CCR_SUSPIE_Pos                  (13U)
#define DMA_CCR_SUSPIE_Msk                  (0x1UL << DMA_CCR_SUSPIE_Pos)           /*!< 0x00002000 */
#define DMA_CCR_SUSPIE                      DMA_CCR_SUSPIE_Msk                      /*!< Completed suspension interrupt enable */
#define DMA_CCR_TOIE_Pos                    (14U)
#define DMA_CCR_TOIE_Msk                    (0x1UL << DMA_CCR_TOIE_Pos)             /*!< 0x00004000 */
#define DMA_CCR_TOIE                        DMA_CCR_TOIE_Msk                        /*!< Trigger overrun interrupt enable */
#define DMA_CCR_LSM_Pos                     (16U)
#define DMA_CCR_LSM_Msk                     (0x1UL << DMA_CCR_LSM_Pos)              /*!< 0x00010000 */
#define DMA_CCR_LSM                         DMA_CCR_LSM_Msk                         /*!< Link step mode */
#define DMA_CCR_LAP_Pos                     (17U)
#define DMA_CCR_LAP_Msk                     (0x1UL << DMA_CCR_LAP_Pos)              /*!< 0x00020000 */
#define DMA_CCR_LAP                         DMA_CCR_LAP_Msk                         /*!< Linked-list allocated port */
#define DMA_CCR_PRIO_Pos                    (22U)
#define DMA_CCR_PRIO_Msk                    (0x3UL << DMA_CCR_PRIO_Pos)             /*!< 0x00C00000 */
#define DMA_CCR_PRIO                        DMA_CCR_PRIO_Msk                        /*!< Priority level */
#define DMA_CCR_PRIO_0                      (0x1UL << DMA_CCR_PRIO_Pos)             /*!< 0x00400000 */
#define DMA_CCR_PRIO_1                      (0x2UL << DMA_CCR_PRIO_Pos)             /*!< 0x00800000 */

/*******************  Bit definition for DMA_CTR1 register  *******************/
#define DMA_CTR1_SDW_LOG2_Pos               (0U)
#define DMA_CTR1_SDW_LOG2_Msk               (0x3UL << DMA_CTR1_SDW_LOG2_Pos)        /*!< 0x00000003 */
#define DMA_CTR1_SDW_LOG2                   DMA_CTR1_SDW_LOG2_Msk                   /*!< Binary logarithm of the source data width of a burst */
#define DMA_CTR1_SDW_LOG2_0                 (0x1UL << DMA_CTR1_SDW_LOG2_Pos)        /*!< Bit 0 */
#define DMA_CTR1_SDW_LOG2_1                 (0x2UL << DMA_CTR1_SDW_LOG2_Pos)        /*!< Bit 1 */
#define DMA_CTR1_SINC_Pos                   (3U)
#define DMA_CTR1_SINC_Msk                   (0x1UL << DMA_CTR1_SINC_Pos)            /*!< 0x00000008 */
#define DMA_CTR1_SINC                       DMA_CTR1_SINC_Msk                       /*!< Source incrementing burst */
#define DMA_CTR1_SBL_1_Pos                  (4U)
#define DMA_CTR1_SBL_1_Msk                  (0x3FUL << DMA_CTR1_SBL_1_Pos)          /*!< 0x000003F0 */
#define DMA_CTR1_SBL_1                      DMA_CTR1_SBL_1_Msk                      /*!< Source burst length minus 1 */
#define DMA_CTR1_PAM_Pos                    (11U)
#define DMA_CTR1_PAM_Msk                    (0x3UL << DMA_CTR1_PAM_Pos)             /*!< 0x0001800 */
#define DMA_CTR1_PAM                        DMA_CTR1_PAM_Msk                        /*!< Padding / alignment mode */
#define DMA_CTR1_PAM_0                      (0x1UL << DMA_CTR1_PAM_Pos)             /*!< Bit 0 */
#define DMA_CTR1_PAM_1                      (0x2UL << DMA_CTR1_PAM_Pos)             /*!< Bit 1 */
#define DMA_CTR1_SBX_Pos                    (13U)
#define DMA_CTR1_SBX_Msk                    (0x1UL << DMA_CTR1_SBX_Pos)             /*!< 0x00002000 */
#define DMA_CTR1_SBX                        DMA_CTR1_SBX_Msk                        /*!< Source byte exchange within the unaligned half-word of each source word */
#define DMA_CTR1_SAP_Pos                    (14U)
#define DMA_CTR1_SAP_Msk                    (0x1UL << DMA_CTR1_SAP_Pos)             /*!< 0x00004000 */
#define DMA_CTR1_SAP                        DMA_CTR1_SAP_Msk                        /*!< Source allocated port */
#define DMA_CTR1_SSEC_Pos                   (15U)
#define DMA_CTR1_SSEC_Msk                   (0x1UL << DMA_CTR1_SSEC_Pos)            /*!< 0x00008000 */
#define DMA_CTR1_SSEC                       DMA_CTR1_SSEC_Msk                       /*!< Security attribute of the DMA transfer from the source */
#define DMA_CTR1_DDW_LOG2_Pos               (16U)
#define DMA_CTR1_DDW_LOG2_Msk               (0x3UL << DMA_CTR1_DDW_LOG2_Pos)        /*!< 0x00030000 */
#define DMA_CTR1_DDW_LOG2                   DMA_CTR1_DDW_LOG2_Msk                   /*!< Binary logarithm of the destination data width of a burst */
#define DMA_CTR1_DDW_LOG2_0                 (0x1UL << DMA_CTR1_DDW_LOG2_Pos)        /*!< Bit 0 */
#define DMA_CTR1_DDW_LOG2_1                 (0x2UL << DMA_CTR1_DDW_LOG2_Pos)        /*!< Bit 1 */
#define DMA_CTR1_DINC_Pos                   (19U)
#define DMA_CTR1_DINC_Msk                   (0x1UL << DMA_CTR1_DINC_Pos)            /*!< 0x00080000 */
#define DMA_CTR1_DINC                       DMA_CTR1_DINC_Msk                       /*!< Destination incrementing burst */
#define DMA_CTR1_DBL_1_Pos                  (20U)
#define DMA_CTR1_DBL_1_Msk                  (0x3FUL << DMA_CTR1_DBL_1_Pos)          /*!< 0x03F00000 */
#define DMA_CTR1_DBL_1                      DMA_CTR1_DBL_1_Msk                      /*!< Destination burst length minus 1 */
#define DMA_CTR1_DBX_Pos                    (26U)
#define DMA_CTR1_DBX_Msk                    (0x1UL << DMA_CTR1_DBX_Pos)             /*!< 0x04000000 */
#define DMA_CTR1_DBX                        DMA_CTR1_DBX_Msk                        /*!< Destination byte exchange */
#define DMA_CTR1_DHX_Pos                    (27U)
#define DMA_CTR1_DHX_Msk                    (0x1UL << DMA_CTR1_DHX_Pos)             /*!< 0x08000000 */
#define DMA_CTR1_DHX                        DMA_CTR1_DHX_Msk                        /*!< Destination half-word exchange */
#define DMA_CTR1_DAP_Pos                    (30U)
#define DMA_CTR1_DAP_Msk                    (0x1UL << DMA_CTR1_DAP_Pos)             /*!< 0x40000000 */
#define DMA_CTR1_DAP                        DMA_CTR1_DAP_Msk                        /*!< Destination allocated port */
#define DMA_CTR1_DSEC_Pos                   (31U)
#define DMA_CTR1_DSEC_Msk                   (0x1UL << DMA_CTR1_DSEC_Pos)            /*!< 0x80000000 */
#define DMA_CTR1_DSEC                       DMA_CTR1_DSEC_Msk                       /*!< Security attribute of the DMA transfer from the destination */

/******************  Bit definition for DMA_CTR2 register  *******************/
#define DMA_CTR2_REQSEL_Pos                 (0U)
#define DMA_CTR2_REQSEL_Msk                 (0x3FUL << DMA_CTR2_REQSEL_Pos)         /*!< 0x0000003F */
#define DMA_CTR2_REQSEL                     DMA_CTR2_REQSEL_Msk                     /*!< DMA hardware request selection */
#define DMA_CTR2_SWREQ_Pos                  (9U)
#define DMA_CTR2_SWREQ_Msk                  (0x1UL << DMA_CTR2_SWREQ_Pos)           /*!< 0x00000100 */
#define DMA_CTR2_SWREQ                      DMA_CTR2_SWREQ_Msk                      /*!< Software request */
#define DMA_CTR2_DREQ_Pos                   (10U)
#define DMA_CTR2_DREQ_Msk                   (0x1UL << DMA_CTR2_DREQ_Pos)            /*!< 0x00000100 */
#define DMA_CTR2_DREQ                       DMA_CTR2_DREQ_Msk                       /*!< Destination hardware request */
#define DMA_CTR2_BREQ_Pos                   (11U)
#define DMA_CTR2_BREQ_Msk                   (0x1UL << DMA_CTR2_BREQ_Pos)            /*!< 0x00000200 */
#define DMA_CTR2_BREQ                       DMA_CTR2_BREQ_Msk                       /*!< Block hardware request */
#define DMA_CTR2_TRIGM_Pos                  (14U)
#define DMA_CTR2_TRIGM_Msk                  (0x3UL << DMA_CTR2_TRIGM_Pos)           /*!< 0x0000C000 */
#define DMA_CTR2_TRIGM                      DMA_CTR2_TRIGM_Msk                      /*!< Trigger mode */
#define DMA_CTR2_TRIGM_0                    (0x1UL << DMA_CTR2_TRIGM_Pos)           /*!< Bit 0 */
#define DMA_CTR2_TRIGM_1                    (0x2UL << DMA_CTR2_TRIGM_Pos)           /*!< Bit 1 */
#define DMA_CTR2_TRIGSEL_Pos                (16U)
#define DMA_CTR2_TRIGSEL_Msk                (0x1FUL << DMA_CTR2_TRIGSEL_Pos)        /*!< 0x001F0000 */
#define DMA_CTR2_TRIGSEL                    DMA_CTR2_TRIGSEL_Msk                    /*!< Trigger event input selection */
#define DMA_CTR2_TRIGPOL_Pos                (24U)
#define DMA_CTR2_TRIGPOL_Msk                (0x3UL << DMA_CTR2_TRIGPOL_Pos)         /*!< 0x03000000 */
#define DMA_CTR2_TRIGPOL                    DMA_CTR2_TRIGPOL_Msk                    /*!< Trigger event polarity */
#define DMA_CTR2_TRIGPOL_0                  (0x1UL << DMA_CTR2_TRIGPOL_Pos)         /*!< Bit 0 */
#define DMA_CTR2_TRIGPOL_1                  (0x2UL << DMA_CTR2_TRIGPOL_Pos)         /*!< Bit 1 */
#define DMA_CTR2_TCEM_Pos                   (30U)
#define DMA_CTR2_TCEM_Msk                   (0x3UL << DMA_CTR2_TCEM_Pos)            /*!< 0xC0000000 */
#define DMA_CTR2_TCEM                       DMA_CTR2_TCEM_Msk                       /*!< Transfer complete event mode */
#define DMA_CTR2_TCEM_0                     (0x1UL << DMA_CTR2_TCEM_Pos)            /*!< Bit 0 */
#define DMA_CTR2_TCEM_1                     (0x2UL << DMA_CTR2_TCEM_Pos)            /*!< Bit 1 */

/******************  Bit definition for DMA_CBR1 register  *******************/
#define DMA_CBR1_BNDT_Pos                   (0U)
#define DMA_CBR1_BNDT_Msk                   (0xFFFFUL << DMA_CBR1_BNDT_Pos)         /*!< 0x0000FFFF */
#define DMA_CBR1_BNDT                       DMA_CBR1_BNDT_Msk                       /*!< Block number of data bytes to transfer from the source */

/******************  Bit definition for DMA_CSAR register  ********************/
#define DMA_CSAR_SA_Pos                     (0U)
#define DMA_CSAR_SA_Msk                     (0xFFFFFFFFUL << DMA_CSAR_SA_Pos)       /*!< 0xFFFFFFFF */
#define DMA_CSAR_SA                         DMA_CSAR_SA_Msk                         /*!< Source Address */

/******************  Bit definition for DMA_CDAR register  *******************/
#define DMA_CDAR_DA_Pos                     (0U)
#define DMA_CDAR_DA_Msk                     (0xFFFFFFFFUL << DMA_CDAR_DA_Pos)       /*!< 0xFFFFFFFF */
#define DMA_CDAR_DA                         DMA_CDAR_DA_Msk                         /*!< Destination address */

/******************  Bit definition for DMA_CLLR register  *******************/
#define DMA_CLLR_LA_Pos                     (2U)
#define DMA_CLLR_LA_Msk                     (0x3FFFUL << DMA_CLLR_LA_Pos)           /*!< 0x0000FFFC */
#define DMA_CLLR_LA                         DMA_CLLR_LA_Msk                         /*!< Pointer to the next linked-list data structure */
#define DMA_CLLR_ULL_Pos                    (16U)
#define DMA_CLLR_ULL_Msk                    (0x1UL << DMA_CLLR_ULL_Pos)             /*!< 0x00010000 */
#define DMA_CLLR_ULL                        DMA_CLLR_ULL_Msk                        /*!< Update link address register from memory */
#define DMA_CLLR_UDA_Pos                    (27U)
#define DMA_CLLR_UDA_Msk                    (0x1UL << DMA_CLLR_UDA_Pos)             /*!< 0x08000000 */
#define DMA_CLLR_UDA                        DMA_CLLR_UDA_Msk                        /*!< Update destination address register from SRAM */
#define DMA_CLLR_USA_Pos                    (28U)
#define DMA_CLLR_USA_Msk                    (0x1UL << DMA_CLLR_USA_Pos)             /*!< 0x10000000 */
#define DMA_CLLR_USA                        DMA_CLLR_USA_Msk                        /*!< Update source address register from SRAM */
#define DMA_CLLR_UB1_Pos                    (29U)
#define DMA_CLLR_UB1_Msk                    (0x1UL << DMA_CLLR_UB1_Pos)             /*!< 0x20000000 */
#define DMA_CLLR_UB1                        DMA_CLLR_UB1_Msk                        /*!< Update block register 1 from SRAM */
#define DMA_CLLR_UT2_Pos                    (30U)
#define DMA_CLLR_UT2_Msk                    (0x1UL << DMA_CLLR_UT2_Pos)             /*!< 0x40000000 */
#define DMA_CLLR_UT2                        DMA_CLLR_UT2_Msk                        /*!< Update transfer register 2 from SRAM */
#define DMA_CLLR_UT1_Pos                    (31U)
#define DMA_CLLR_UT1_Msk                    (0x1UL << DMA_CLLR_UT1_Pos)             /*!< 0x80000000 */
#define DMA_CLLR_UT1                        DMA_CLLR_UT1_Msk                        /*!< Update transfer register 1 from SRAM */

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for EXTI_RTSR1 register  ******************/
#define EXTI_RTSR1_RT0_Pos                  (0U)
#define EXTI_RTSR1_RT0_Msk                  (0x1UL << EXTI_RTSR1_RT0_Pos)           /*!< 0x00000001 */
#define EXTI_RTSR1_RT0                      EXTI_RTSR1_RT0_Msk                      /*!< Rising trigger configuration for input line 0 */
#define EXTI_RTSR1_RT1_Pos                  (1U)
#define EXTI_RTSR1_RT1_Msk                  (0x1UL << EXTI_RTSR1_RT1_Pos)           /*!< 0x00000002 */
#define EXTI_RTSR1_RT1                      EXTI_RTSR1_RT1_Msk                      /*!< Rising trigger configuration for input line 1 */
#define EXTI_RTSR1_RT2_Pos                  (2U)
#define EXTI_RTSR1_RT2_Msk                  (0x1UL << EXTI_RTSR1_RT2_Pos)           /*!< 0x00000004 */
#define EXTI_RTSR1_RT2                      EXTI_RTSR1_RT2_Msk                      /*!< Rising trigger configuration for input line 2 */
#define EXTI_RTSR1_RT3_Pos                  (3U)
#define EXTI_RTSR1_RT3_Msk                  (0x1UL << EXTI_RTSR1_RT3_Pos)           /*!< 0x00000008 */
#define EXTI_RTSR1_RT3                      EXTI_RTSR1_RT3_Msk                      /*!< Rising trigger configuration for input line 3 */
#define EXTI_RTSR1_RT4_Pos                  (4U)
#define EXTI_RTSR1_RT4_Msk                  (0x1UL << EXTI_RTSR1_RT4_Pos)           /*!< 0x00000010 */
#define EXTI_RTSR1_RT4                      EXTI_RTSR1_RT4_Msk                      /*!< Rising trigger configuration for input line 4 */
#define EXTI_RTSR1_RT5_Pos                  (5U)
#define EXTI_RTSR1_RT5_Msk                  (0x1UL << EXTI_RTSR1_RT5_Pos)           /*!< 0x00000020 */
#define EXTI_RTSR1_RT5                      EXTI_RTSR1_RT5_Msk                      /*!< Rising trigger configuration for input line 5 */
#define EXTI_RTSR1_RT6_Pos                  (6U)
#define EXTI_RTSR1_RT6_Msk                  (0x1UL << EXTI_RTSR1_RT6_Pos)           /*!< 0x00000040 */
#define EXTI_RTSR1_RT6                      EXTI_RTSR1_RT6_Msk                      /*!< Rising trigger configuration for input line 6 */
#define EXTI_RTSR1_RT7_Pos                  (7U)
#define EXTI_RTSR1_RT7_Msk                  (0x1UL << EXTI_RTSR1_RT7_Pos)           /*!< 0x00000080 */
#define EXTI_RTSR1_RT7                      EXTI_RTSR1_RT7_Msk                      /*!< Rising trigger configuration for input line 7 */
#define EXTI_RTSR1_RT8_Pos                  (8U)
#define EXTI_RTSR1_RT8_Msk                  (0x1UL << EXTI_RTSR1_RT8_Pos)           /*!< 0x00000100 */
#define EXTI_RTSR1_RT8                      EXTI_RTSR1_RT8_Msk                      /*!< Rising trigger configuration for input line 8 */
#define EXTI_RTSR1_RT9_Pos                  (9U)
#define EXTI_RTSR1_RT9_Msk                  (0x1UL << EXTI_RTSR1_RT9_Pos)           /*!< 0x00000200 */
#define EXTI_RTSR1_RT9                      EXTI_RTSR1_RT9_Msk                      /*!< Rising trigger configuration for input line 9 */
#define EXTI_RTSR1_RT12_Pos                 (12U)
#define EXTI_RTSR1_RT12_Msk                 (0x1UL << EXTI_RTSR1_RT12_Pos)          /*!< 0x00001000 */
#define EXTI_RTSR1_RT12                     EXTI_RTSR1_RT12_Msk                     /*!< Rising trigger configuration for input line 12 */
#define EXTI_RTSR1_RT13_Pos                 (13U)
#define EXTI_RTSR1_RT13_Msk                 (0x1UL << EXTI_RTSR1_RT13_Pos)          /*!< 0x00002000 */
#define EXTI_RTSR1_RT13                     EXTI_RTSR1_RT13_Msk                     /*!< Rising trigger configuration for input line 13 */
#define EXTI_RTSR1_RT14_Pos                 (14U)
#define EXTI_RTSR1_RT14_Msk                 (0x1UL << EXTI_RTSR1_RT14_Pos)          /*!< 0x00004000 */
#define EXTI_RTSR1_RT14                     EXTI_RTSR1_RT14_Msk                     /*!< Rising trigger configuration for input line 14 */
#define EXTI_RTSR1_RT15_Pos                 (15U)
#define EXTI_RTSR1_RT15_Msk                 (0x1UL << EXTI_RTSR1_RT15_Pos)          /*!< 0x00008000 */
#define EXTI_RTSR1_RT15                     EXTI_RTSR1_RT15_Msk                     /*!< Rising trigger configuration for input line 15 */
#define EXTI_RTSR1_RT18_Pos                 (18U)
#define EXTI_RTSR1_RT18_Msk                 (0x1UL << EXTI_RTSR1_RT18_Pos)          /*!< 0x00040000 */
#define EXTI_RTSR1_RT18                     EXTI_RTSR1_RT18_Msk                     /*!< Rising trigger configuration for input line 18 */

/******************  Bit definition for EXTI_FTSR1 register  ******************/
#define EXTI_FTSR1_FT0_Pos                  (0U)
#define EXTI_FTSR1_FT0_Msk                  (0x1UL << EXTI_FTSR1_FT0_Pos)           /*!< 0x00000001 */
#define EXTI_FTSR1_FT0                      EXTI_FTSR1_FT0_Msk                      /*!< Falling trigger configuration for input line 0 */
#define EXTI_FTSR1_FT1_Pos                  (1U)
#define EXTI_FTSR1_FT1_Msk                  (0x1UL << EXTI_FTSR1_FT1_Pos)           /*!< 0x00000002 */
#define EXTI_FTSR1_FT1                      EXTI_FTSR1_FT1_Msk                      /*!< Falling trigger configuration for input line 1 */
#define EXTI_FTSR1_FT2_Pos                  (2U)
#define EXTI_FTSR1_FT2_Msk                  (0x1UL << EXTI_FTSR1_FT2_Pos)           /*!< 0x00000004 */
#define EXTI_FTSR1_FT2                      EXTI_FTSR1_FT2_Msk                      /*!< Falling trigger configuration for input line 2 */
#define EXTI_FTSR1_FT3_Pos                  (3U)
#define EXTI_FTSR1_FT3_Msk                  (0x1UL << EXTI_FTSR1_FT3_Pos)           /*!< 0x00000008 */
#define EXTI_FTSR1_FT3                      EXTI_FTSR1_FT3_Msk                      /*!< Falling trigger configuration for input line 3 */
#define EXTI_FTSR1_FT4_Pos                  (4U)
#define EXTI_FTSR1_FT4_Msk                  (0x1UL << EXTI_FTSR1_FT4_Pos)           /*!< 0x00000010 */
#define EXTI_FTSR1_FT4                      EXTI_FTSR1_FT4_Msk                      /*!< Falling trigger configuration for input line 4 */
#define EXTI_FTSR1_FT5_Pos                  (5U)
#define EXTI_FTSR1_FT5_Msk                  (0x1UL << EXTI_FTSR1_FT5_Pos)           /*!< 0x00000020 */
#define EXTI_FTSR1_FT5                      EXTI_FTSR1_FT5_Msk                      /*!< Falling trigger configuration for input line 5 */
#define EXTI_FTSR1_FT6_Pos                  (6U)
#define EXTI_FTSR1_FT6_Msk                  (0x1UL << EXTI_FTSR1_FT6_Pos)           /*!< 0x00000040 */
#define EXTI_FTSR1_FT6                      EXTI_FTSR1_FT6_Msk                      /*!< Falling trigger configuration for input line 6 */
#define EXTI_FTSR1_FT7_Pos                  (7U)
#define EXTI_FTSR1_FT7_Msk                  (0x1UL << EXTI_FTSR1_FT7_Pos)           /*!< 0x00000080 */
#define EXTI_FTSR1_FT7                      EXTI_FTSR1_FT7_Msk                      /*!< Falling trigger configuration for input line 7 */
#define EXTI_FTSR1_FT8_Pos                  (8U)
#define EXTI_FTSR1_FT8_Msk                  (0x1UL << EXTI_FTSR1_FT8_Pos)           /*!< 0x00000100 */
#define EXTI_FTSR1_FT8                      EXTI_FTSR1_FT8_Msk                      /*!< Falling trigger configuration for input line 8 */
#define EXTI_FTSR1_FT9_Pos                  (9U)
#define EXTI_FTSR1_FT9_Msk                  (0x1UL << EXTI_FTSR1_FT9_Pos)           /*!< 0x00000200 */
#define EXTI_FTSR1_FT9                      EXTI_FTSR1_FT9_Msk                      /*!< Falling trigger configuration for input line 9 */
#define EXTI_FTSR1_FT12_Pos                 (12U)
#define EXTI_FTSR1_FT12_Msk                 (0x1UL << EXTI_FTSR1_FT12_Pos)          /*!< 0x00001000 */
#define EXTI_FTSR1_FT12                     EXTI_FTSR1_FT12_Msk                     /*!< Falling trigger configuration for input line 12 */
#define EXTI_FTSR1_FT13_Pos                 (13U)
#define EXTI_FTSR1_FT13_Msk                 (0x1UL << EXTI_FTSR1_FT13_Pos)          /*!< 0x00002000 */
#define EXTI_FTSR1_FT13                     EXTI_FTSR1_FT13_Msk                     /*!< Falling trigger configuration for input line 13 */
#define EXTI_FTSR1_FT14_Pos                 (14U)
#define EXTI_FTSR1_FT14_Msk                 (0x1UL << EXTI_FTSR1_FT14_Pos)          /*!< 0x00004000 */
#define EXTI_FTSR1_FT14                     EXTI_FTSR1_FT14_Msk                     /*!< Falling trigger configuration for input line 14 */
#define EXTI_FTSR1_FT15_Pos                 (15U)
#define EXTI_FTSR1_FT15_Msk                 (0x1UL << EXTI_FTSR1_FT15_Pos)          /*!< 0x00008000 */
#define EXTI_FTSR1_FT15                     EXTI_FTSR1_FT15_Msk                     /*!< Falling trigger configuration for input line 15 */
#define EXTI_FTSR1_FT18_Pos                 (18U)
#define EXTI_FTSR1_FT18_Msk                 (0x1UL << EXTI_FTSR1_FT18_Pos)          /*!< 0x00040000 */
#define EXTI_FTSR1_FT18                     EXTI_FTSR1_FT18_Msk                     /*!< Falling trigger configuration for input line 18 */

/******************  Bit definition for EXTI_SWIER1 register  *****************/
#define EXTI_SWIER1_SWI0_Pos                (0U)
#define EXTI_SWIER1_SWI0_Msk                (0x1UL << EXTI_SWIER1_SWI0_Pos)         /*!< 0x00000001 */
#define EXTI_SWIER1_SWI0                    EXTI_SWIER1_SWI0_Msk                    /*!< Software Interrupt on line 0 */
#define EXTI_SWIER1_SWI1_Pos                (1U)
#define EXTI_SWIER1_SWI1_Msk                (0x1UL << EXTI_SWIER1_SWI1_Pos)         /*!< 0x00000002 */
#define EXTI_SWIER1_SWI1                    EXTI_SWIER1_SWI1_Msk                    /*!< Software Interrupt on line 1 */
#define EXTI_SWIER1_SWI2_Pos                (2U)
#define EXTI_SWIER1_SWI2_Msk                (0x1UL << EXTI_SWIER1_SWI2_Pos)         /*!< 0x00000004 */
#define EXTI_SWIER1_SWI2                    EXTI_SWIER1_SWI2_Msk                    /*!< Software Interrupt on line 2 */
#define EXTI_SWIER1_SWI3_Pos                (3U)
#define EXTI_SWIER1_SWI3_Msk                (0x1UL << EXTI_SWIER1_SWI3_Pos)         /*!< 0x00000008 */
#define EXTI_SWIER1_SWI3                    EXTI_SWIER1_SWI3_Msk                    /*!< Software Interrupt on line 3 */
#define EXTI_SWIER1_SWI4_Pos                (4U)
#define EXTI_SWIER1_SWI4_Msk                (0x1UL << EXTI_SWIER1_SWI4_Pos)         /*!< 0x00000010 */
#define EXTI_SWIER1_SWI4                    EXTI_SWIER1_SWI4_Msk                    /*!< Software Interrupt on line 4 */
#define EXTI_SWIER1_SWI5_Pos                (5U)
#define EXTI_SWIER1_SWI5_Msk                (0x1UL << EXTI_SWIER1_SWI5_Pos)         /*!< 0x00000020 */
#define EXTI_SWIER1_SWI5                    EXTI_SWIER1_SWI5_Msk                    /*!< Software Interrupt on line 5 */
#define EXTI_SWIER1_SWI6_Pos                (6U)
#define EXTI_SWIER1_SWI6_Msk                (0x1UL << EXTI_SWIER1_SWI6_Pos)         /*!< 0x00000040 */
#define EXTI_SWIER1_SWI6                    EXTI_SWIER1_SWI6_Msk                    /*!< Software Interrupt on line 6 */
#define EXTI_SWIER1_SWI7_Pos                (7U)
#define EXTI_SWIER1_SWI7_Msk                (0x1UL << EXTI_SWIER1_SWI7_Pos)         /*!< 0x00000080 */
#define EXTI_SWIER1_SWI7                    EXTI_SWIER1_SWI7_Msk                    /*!< Software Interrupt on line 7 */
#define EXTI_SWIER1_SWI8_Pos                (8U)
#define EXTI_SWIER1_SWI8_Msk                (0x1UL << EXTI_SWIER1_SWI8_Pos)         /*!< 0x00000100 */
#define EXTI_SWIER1_SWI8                    EXTI_SWIER1_SWI8_Msk                    /*!< Software Interrupt on line 8 */
#define EXTI_SWIER1_SWI9_Pos                (9U)
#define EXTI_SWIER1_SWI9_Msk                (0x1UL << EXTI_SWIER1_SWI9_Pos)         /*!< 0x00000200 */
#define EXTI_SWIER1_SWI9                    EXTI_SWIER1_SWI9_Msk                    /*!< Software Interrupt on line 9 */
#define EXTI_SWIER1_SWI12_Pos               (12U)
#define EXTI_SWIER1_SWI12_Msk               (0x1UL << EXTI_SWIER1_SWI12_Pos)        /*!< 0x00001000 */
#define EXTI_SWIER1_SWI12                   EXTI_SWIER1_SWI12_Msk                   /*!< Software Interrupt on line 12 */
#define EXTI_SWIER1_SWI13_Pos               (13U)
#define EXTI_SWIER1_SWI13_Msk               (0x1UL << EXTI_SWIER1_SWI13_Pos)        /*!< 0x00002000 */
#define EXTI_SWIER1_SWI13                   EXTI_SWIER1_SWI13_Msk                   /*!< Software Interrupt on line 13 */
#define EXTI_SWIER1_SWI14_Pos               (14U)
#define EXTI_SWIER1_SWI14_Msk               (0x1UL << EXTI_SWIER1_SWI14_Pos)        /*!< 0x00004000 */
#define EXTI_SWIER1_SWI14                   EXTI_SWIER1_SWI14_Msk                   /*!< Software Interrupt on line 14 */
#define EXTI_SWIER1_SWI15_Pos               (15U)
#define EXTI_SWIER1_SWI15_Msk               (0x1UL << EXTI_SWIER1_SWI15_Pos)        /*!< 0x00008000 */
#define EXTI_SWIER1_SWI15                   EXTI_SWIER1_SWI15_Msk                   /*!< Software Interrupt on line 15 */
#define EXTI_SWIER1_SWI18_Pos               (18U)
#define EXTI_SWIER1_SWI18_Msk               (0x1UL << EXTI_SWIER1_SWI18_Pos)        /*!< 0x00040000 */
#define EXTI_SWIER1_SWI18                   EXTI_SWIER1_SWI18_Msk                   /*!< Software Interrupt on line 18 */

/*******************  Bit definition for EXTI_RPR1 register  ******************/
#define EXTI_RPR1_RPIF0_Pos                 (0U)
#define EXTI_RPR1_RPIF0_Msk                 (0x1UL << EXTI_RPR1_RPIF0_Pos)          /*!< 0x00000001 */
#define EXTI_RPR1_RPIF0                     EXTI_RPR1_RPIF0_Msk                     /*!< Rising Pending Interrupt Flag on line 0 */
#define EXTI_RPR1_RPIF1_Pos                 (1U)
#define EXTI_RPR1_RPIF1_Msk                 (0x1UL << EXTI_RPR1_RPIF1_Pos)          /*!< 0x00000002 */
#define EXTI_RPR1_RPIF1                     EXTI_RPR1_RPIF1_Msk                     /*!< Rising Pending Interrupt Flag on line 1 */
#define EXTI_RPR1_RPIF2_Pos                 (2U)
#define EXTI_RPR1_RPIF2_Msk                 (0x1UL << EXTI_RPR1_RPIF2_Pos)          /*!< 0x00000004 */
#define EXTI_RPR1_RPIF2                     EXTI_RPR1_RPIF2_Msk                     /*!< Rising Pending Interrupt Flag on line 2 */
#define EXTI_RPR1_RPIF3_Pos                 (3U)
#define EXTI_RPR1_RPIF3_Msk                 (0x1UL << EXTI_RPR1_RPIF3_Pos)          /*!< 0x00000008 */
#define EXTI_RPR1_RPIF3                     EXTI_RPR1_RPIF3_Msk                     /*!< Rising Pending Interrupt Flag on line 3 */
#define EXTI_RPR1_RPIF4_Pos                 (4U)
#define EXTI_RPR1_RPIF4_Msk                 (0x1UL << EXTI_RPR1_RPIF4_Pos)          /*!< 0x00000010 */
#define EXTI_RPR1_RPIF4                     EXTI_RPR1_RPIF4_Msk                     /*!< Rising Pending Interrupt Flag on line 4 */
#define EXTI_RPR1_RPIF5_Pos                 (5U)
#define EXTI_RPR1_RPIF5_Msk                 (0x1UL << EXTI_RPR1_RPIF5_Pos)          /*!< 0x00000020 */
#define EXTI_RPR1_RPIF5                     EXTI_RPR1_RPIF5_Msk                     /*!< Rising Pending Interrupt Flag on line 5 */
#define EXTI_RPR1_RPIF6_Pos                 (6U)
#define EXTI_RPR1_RPIF6_Msk                 (0x1UL << EXTI_RPR1_RPIF6_Pos)          /*!< 0x00000040 */
#define EXTI_RPR1_RPIF6                     EXTI_RPR1_RPIF6_Msk                     /*!< Rising Pending Interrupt Flag on line 6 */
#define EXTI_RPR1_RPIF7_Pos                 (7U)
#define EXTI_RPR1_RPIF7_Msk                 (0x1UL << EXTI_RPR1_RPIF7_Pos)          /*!< 0x00000080 */
#define EXTI_RPR1_RPIF7                     EXTI_RPR1_RPIF7_Msk                     /*!< Rising Pending Interrupt Flag on line 7 */
#define EXTI_RPR1_RPIF8_Pos                 (8U)
#define EXTI_RPR1_RPIF8_Msk                 (0x1UL << EXTI_RPR1_RPIF8_Pos)          /*!< 0x00000100 */
#define EXTI_RPR1_RPIF8                     EXTI_RPR1_RPIF8_Msk                     /*!< Rising Pending Interrupt Flag on line 8 */
#define EXTI_RPR1_RPIF9_Pos                 (9U)
#define EXTI_RPR1_RPIF9_Msk                 (0x1UL << EXTI_RPR1_RPIF9_Pos)          /*!< 0x00000200 */
#define EXTI_RPR1_RPIF9                     EXTI_RPR1_RPIF9_Msk                     /*!< Rising Pending Interrupt Flag on line 9 */
#define EXTI_RPR1_RPIF12_Pos                (12U)
#define EXTI_RPR1_RPIF12_Msk                (0x1UL << EXTI_RPR1_RPIF12_Pos)         /*!< 0x00001000 */
#define EXTI_RPR1_RPIF12                    EXTI_RPR1_RPIF12_Msk                    /*!< Rising Pending Interrupt Flag on line 12 */
#define EXTI_RPR1_RPIF13_Pos                (13U)
#define EXTI_RPR1_RPIF13_Msk                (0x1UL << EXTI_RPR1_RPIF13_Pos)         /*!< 0x00002000 */
#define EXTI_RPR1_RPIF13                    EXTI_RPR1_RPIF13_Msk                    /*!< Rising Pending Interrupt Flag on line 13 */
#define EXTI_RPR1_RPIF14_Pos                (14U)
#define EXTI_RPR1_RPIF14_Msk                (0x1UL << EXTI_RPR1_RPIF14_Pos)         /*!< 0x00004000 */
#define EXTI_RPR1_RPIF14                    EXTI_RPR1_RPIF14_Msk                    /*!< Rising Pending Interrupt Flag on line 14 */
#define EXTI_RPR1_RPIF15_Pos                (15U)
#define EXTI_RPR1_RPIF15_Msk                (0x1UL << EXTI_RPR1_RPIF15_Pos)         /*!< 0x00008000 */
#define EXTI_RPR1_RPIF15                    EXTI_RPR1_RPIF15_Msk                    /*!< Rising Pending Interrupt Flag on line 15 */
#define EXTI_RPR1_RPIF18_Pos                (18U)
#define EXTI_RPR1_RPIF18_Msk                (0x1UL << EXTI_RPR1_RPIF18_Pos)         /*!< 0x00040000 */
#define EXTI_RPR1_RPIF18                    EXTI_RPR1_RPIF18_Msk                    /*!< Rising Pending Interrupt Flag on line 18 */

/*******************  Bit definition for EXTI_FPR1 register  ******************/
#define EXTI_FPR1_FPIF0_Pos                 (0U)
#define EXTI_FPR1_FPIF0_Msk                 (0x1UL << EXTI_FPR1_FPIF0_Pos)          /*!< 0x00000001 */
#define EXTI_FPR1_FPIF0                     EXTI_FPR1_FPIF0_Msk                     /*!< Falling Pending Interrupt Flag on line 0 */
#define EXTI_FPR1_FPIF1_Pos                 (1U)
#define EXTI_FPR1_FPIF1_Msk                 (0x1UL << EXTI_FPR1_FPIF1_Pos)          /*!< 0x00000002 */
#define EXTI_FPR1_FPIF1                     EXTI_FPR1_FPIF1_Msk                     /*!< Falling Pending Interrupt Flag on line 1 */
#define EXTI_FPR1_FPIF2_Pos                 (2U)
#define EXTI_FPR1_FPIF2_Msk                 (0x1UL << EXTI_FPR1_FPIF2_Pos)          /*!< 0x00000004 */
#define EXTI_FPR1_FPIF2                     EXTI_FPR1_FPIF2_Msk                     /*!< Falling Pending Interrupt Flag on line 2 */
#define EXTI_FPR1_FPIF3_Pos                 (3U)
#define EXTI_FPR1_FPIF3_Msk                 (0x1UL << EXTI_FPR1_FPIF3_Pos)          /*!< 0x00000008 */
#define EXTI_FPR1_FPIF3                     EXTI_FPR1_FPIF3_Msk                     /*!< Falling Pending Interrupt Flag on line 3 */
#define EXTI_FPR1_FPIF4_Pos                 (4U)
#define EXTI_FPR1_FPIF4_Msk                 (0x1UL << EXTI_FPR1_FPIF4_Pos)          /*!< 0x00000010 */
#define EXTI_FPR1_FPIF4                     EXTI_FPR1_FPIF4_Msk                     /*!< Falling Pending Interrupt Flag on line 4 */
#define EXTI_FPR1_FPIF5_Pos                 (5U)
#define EXTI_FPR1_FPIF5_Msk                 (0x1UL << EXTI_FPR1_FPIF5_Pos)          /*!< 0x00000020 */
#define EXTI_FPR1_FPIF5                     EXTI_FPR1_FPIF5_Msk                     /*!< Falling Pending Interrupt Flag on line 5 */
#define EXTI_FPR1_FPIF6_Pos                 (6U)
#define EXTI_FPR1_FPIF6_Msk                 (0x1UL << EXTI_FPR1_FPIF6_Pos)          /*!< 0x00000040 */
#define EXTI_FPR1_FPIF6                     EXTI_FPR1_FPIF6_Msk                     /*!< Falling Pending Interrupt Flag on line 6 */
#define EXTI_FPR1_FPIF7_Pos                 (7U)
#define EXTI_FPR1_FPIF7_Msk                 (0x1UL << EXTI_FPR1_FPIF7_Pos)          /*!< 0x00000080 */
#define EXTI_FPR1_FPIF7                     EXTI_FPR1_FPIF7_Msk                     /*!< Falling Pending Interrupt Flag on line 7 */
#define EXTI_FPR1_FPIF8_Pos                 (8U)
#define EXTI_FPR1_FPIF8_Msk                 (0x1UL << EXTI_FPR1_FPIF8_Pos)          /*!< 0x00000100 */
#define EXTI_FPR1_FPIF8                     EXTI_FPR1_FPIF8_Msk                     /*!< Falling Pending Interrupt Flag on line 8 */
#define EXTI_FPR1_FPIF9_Pos                 (9U)
#define EXTI_FPR1_FPIF9_Msk                 (0x1UL << EXTI_FPR1_FPIF9_Pos)          /*!< 0x00000200 */
#define EXTI_FPR1_FPIF9                     EXTI_FPR1_FPIF9_Msk                     /*!< Falling Pending Interrupt Flag on line 9 */
#define EXTI_FPR1_FPIF12_Pos                (12U)
#define EXTI_FPR1_FPIF12_Msk                (0x1UL << EXTI_FPR1_FPIF12_Pos)         /*!< 0x00001000 */
#define EXTI_FPR1_FPIF12                    EXTI_FPR1_FPIF12_Msk                    /*!< Falling Pending Interrupt Flag on line 12 */
#define EXTI_FPR1_FPIF13_Pos                (13U)
#define EXTI_FPR1_FPIF13_Msk                (0x1UL << EXTI_FPR1_FPIF13_Pos)         /*!< 0x00002000 */
#define EXTI_FPR1_FPIF13                    EXTI_FPR1_FPIF13_Msk                    /*!< Falling Pending Interrupt Flag on line 13 */
#define EXTI_FPR1_FPIF14_Pos                (14U)
#define EXTI_FPR1_FPIF14_Msk                (0x1UL << EXTI_FPR1_FPIF14_Pos)         /*!< 0x00004000 */
#define EXTI_FPR1_FPIF14                    EXTI_FPR1_FPIF14_Msk                    /*!< Falling Pending Interrupt Flag on line 14 */
#define EXTI_FPR1_FPIF15_Pos                (15U)
#define EXTI_FPR1_FPIF15_Msk                (0x1UL << EXTI_FPR1_FPIF15_Pos)         /*!< 0x00008000 */
#define EXTI_FPR1_FPIF15                    EXTI_FPR1_FPIF15_Msk                    /*!< Falling Pending Interrupt Flag on line 15 */
#define EXTI_FPR1_FPIF18_Pos                (18U)
#define EXTI_FPR1_FPIF18_Msk                (0x1UL << EXTI_FPR1_FPIF18_Pos)         /*!< 0x00040000 */
#define EXTI_FPR1_FPIF18                    EXTI_FPR1_FPIF18_Msk                    /*!< Falling Pending Interrupt Flag on line 18 */

/*****************  Bit definition for EXTI_EXTICR1 register  **************/
#define EXTI_EXTICR1_EXTI0_Pos              (0U)
#define EXTI_EXTICR1_EXTI0_Msk              (0xFFUL << EXTI_EXTICR1_EXTI0_Pos)      /*!< 0x000000FF */
#define EXTI_EXTICR1_EXTI0                  EXTI_EXTICR1_EXTI0_Msk                  /*!< EXTI 0 configuration */
#define EXTI_EXTICR1_EXTI0_0                (0x1UL << EXTI_EXTICR1_EXTI0_Pos)       /*!< 0x00000001 */
#define EXTI_EXTICR1_EXTI0_1                (0x2UL << EXTI_EXTICR1_EXTI0_Pos)       /*!< 0x00000002 */
#define EXTI_EXTICR1_EXTI0_2                (0x4UL << EXTI_EXTICR1_EXTI0_Pos)       /*!< 0x00000004 */
#define EXTI_EXTICR1_EXTI0_3                (0x8UL << EXTI_EXTICR1_EXTI0_Pos)       /*!< 0x00000008 */
#define EXTI_EXTICR1_EXTI0_4                (0x10UL << EXTI_EXTICR1_EXTI0_Pos)      /*!< 0x00000010 */
#define EXTI_EXTICR1_EXTI0_5                (0x20UL << EXTI_EXTICR1_EXTI0_Pos)      /*!< 0x00000020 */
#define EXTI_EXTICR1_EXTI0_6                (0x40UL << EXTI_EXTICR1_EXTI0_Pos)      /*!< 0x00000040 */
#define EXTI_EXTICR1_EXTI0_7                (0x80UL << EXTI_EXTICR1_EXTI0_Pos)      /*!< 0x00000080 */
#define EXTI_EXTICR1_EXTI1_Pos              (8U)
#define EXTI_EXTICR1_EXTI1_Msk              (0xFFUL << EXTI_EXTICR1_EXTI1_Pos)      /*!< 0x0000FF00 */
#define EXTI_EXTICR1_EXTI1                  EXTI_EXTICR1_EXTI1_Msk                  /*!< EXTI 1 configuration */
#define EXTI_EXTICR1_EXTI1_0                (0x1UL << EXTI_EXTICR1_EXTI1_Pos)       /*!< 0x00000100 */
#define EXTI_EXTICR1_EXTI1_1                (0x2UL << EXTI_EXTICR1_EXTI1_Pos)       /*!< 0x00000200 */
#define EXTI_EXTICR1_EXTI1_2                (0x4UL << EXTI_EXTICR1_EXTI1_Pos)       /*!< 0x00000400 */
#define EXTI_EXTICR1_EXTI1_3                (0x8UL << EXTI_EXTICR1_EXTI1_Pos)       /*!< 0x00000800 */
#define EXTI_EXTICR1_EXTI1_4                (0x10UL << EXTI_EXTICR1_EXTI1_Pos)      /*!< 0x00001000 */
#define EXTI_EXTICR1_EXTI1_5                (0x20UL << EXTI_EXTICR1_EXTI1_Pos)      /*!< 0x00002000 */
#define EXTI_EXTICR1_EXTI1_6                (0x40UL << EXTI_EXTICR1_EXTI1_Pos)      /*!< 0x00004000 */
#define EXTI_EXTICR1_EXTI1_7                (0x80UL << EXTI_EXTICR1_EXTI1_Pos)      /*!< 0x00008000 */
#define EXTI_EXTICR1_EXTI2_Pos              (16U)
#define EXTI_EXTICR1_EXTI2_Msk              (0xFFUL << EXTI_EXTICR1_EXTI2_Pos)      /*!< 0x00FF0000 */
#define EXTI_EXTICR1_EXTI2                  EXTI_EXTICR1_EXTI2_Msk                  /*!< EXTI 2 configuration */
#define EXTI_EXTICR1_EXTI2_0                (0x1UL << EXTI_EXTICR1_EXTI2_Pos)       /*!< 0x00010000 */
#define EXTI_EXTICR1_EXTI2_1                (0x2UL << EXTI_EXTICR1_EXTI2_Pos)       /*!< 0x00020000 */
#define EXTI_EXTICR1_EXTI2_2                (0x4UL << EXTI_EXTICR1_EXTI2_Pos)       /*!< 0x00040000 */
#define EXTI_EXTICR1_EXTI2_3                (0x8UL << EXTI_EXTICR1_EXTI2_Pos)       /*!< 0x00080000 */
#define EXTI_EXTICR1_EXTI2_4                (0x10UL << EXTI_EXTICR1_EXTI2_Pos)      /*!< 0x00100000 */
#define EXTI_EXTICR1_EXTI2_5                (0x20UL << EXTI_EXTICR1_EXTI2_Pos)      /*!< 0x00200000 */
#define EXTI_EXTICR1_EXTI2_6                (0x40UL << EXTI_EXTICR1_EXTI2_Pos)      /*!< 0x00400000 */
#define EXTI_EXTICR1_EXTI2_7                (0x80UL << EXTI_EXTICR1_EXTI2_Pos)      /*!< 0x00800000 */
#define EXTI_EXTICR1_EXTI3_Pos              (24U)
#define EXTI_EXTICR1_EXTI3_Msk              (0xFFUL << EXTI_EXTICR1_EXTI3_Pos)      /*!< 0xFF000000 */
#define EXTI_EXTICR1_EXTI3                  EXTI_EXTICR1_EXTI3_Msk                  /*!< EXTI 3 configuration */
#define EXTI_EXTICR1_EXTI3_0                (0x1UL << EXTI_EXTICR1_EXTI3_Pos)       /*!< 0x01000000 */
#define EXTI_EXTICR1_EXTI3_1                (0x2UL << EXTI_EXTICR1_EXTI3_Pos)       /*!< 0x02000000 */
#define EXTI_EXTICR1_EXTI3_2                (0x4UL << EXTI_EXTICR1_EXTI3_Pos)       /*!< 0x04000000 */
#define EXTI_EXTICR1_EXTI3_3                (0x8UL << EXTI_EXTICR1_EXTI3_Pos)       /*!< 0x08000000 */
#define EXTI_EXTICR1_EXTI3_4                (0x10UL << EXTI_EXTICR1_EXTI3_Pos)      /*!< 0x10000000 */
#define EXTI_EXTICR1_EXTI3_5                (0x20UL << EXTI_EXTICR1_EXTI3_Pos)      /*!< 0x20000000 */
#define EXTI_EXTICR1_EXTI3_6                (0x40UL << EXTI_EXTICR1_EXTI3_Pos)      /*!< 0x40000000 */
#define EXTI_EXTICR1_EXTI3_7                (0x80UL << EXTI_EXTICR1_EXTI3_Pos)      /*!< 0x80000000 */

/*****************  Bit definition for EXTI_EXTICR2 register  **************/
#define EXTI_EXTICR2_EXTI4_Pos              (0U)
#define EXTI_EXTICR2_EXTI4_Msk              (0xFFUL << EXTI_EXTICR2_EXTI4_Pos)      /*!< 0x000000FF */
#define EXTI_EXTICR2_EXTI4                  EXTI_EXTICR2_EXTI4_Msk                  /*!< EXTI 4 configuration */
#define EXTI_EXTICR2_EXTI4_0                (0x1UL << EXTI_EXTICR2_EXTI4_Pos)       /*!< 0x00000001 */
#define EXTI_EXTICR2_EXTI4_1                (0x2UL << EXTI_EXTICR2_EXTI4_Pos)       /*!< 0x00000002 */
#define EXTI_EXTICR2_EXTI4_2                (0x4UL << EXTI_EXTICR2_EXTI4_Pos)       /*!< 0x00000004 */
#define EXTI_EXTICR2_EXTI4_3                (0x8UL << EXTI_EXTICR2_EXTI4_Pos)       /*!< 0x00000008 */
#define EXTI_EXTICR2_EXTI4_4                (0x10UL << EXTI_EXTICR2_EXTI4_Pos)      /*!< 0x00000010 */
#define EXTI_EXTICR2_EXTI4_5                (0x20UL << EXTI_EXTICR2_EXTI4_Pos)      /*!< 0x00000020 */
#define EXTI_EXTICR2_EXTI4_6                (0x40UL << EXTI_EXTICR2_EXTI4_Pos)      /*!< 0x00000040 */
#define EXTI_EXTICR2_EXTI4_7                (0x80UL << EXTI_EXTICR2_EXTI4_Pos)      /*!< 0x00000080 */
#define EXTI_EXTICR2_EXTI5_Pos              (8U)
#define EXTI_EXTICR2_EXTI5_Msk              (0xFFUL << EXTI_EXTICR2_EXTI5_Pos)      /*!< 0x0000FF00 */
#define EXTI_EXTICR2_EXTI5                  EXTI_EXTICR2_EXTI5_Msk                  /*!< EXTI 5 configuration */
#define EXTI_EXTICR2_EXTI5_0                (0x1UL << EXTI_EXTICR2_EXTI5_Pos)       /*!< 0x00000100 */
#define EXTI_EXTICR2_EXTI5_1                (0x2UL << EXTI_EXTICR2_EXTI5_Pos)       /*!< 0x00000200 */
#define EXTI_EXTICR2_EXTI5_2                (0x4UL << EXTI_EXTICR2_EXTI5_Pos)       /*!< 0x00000400 */
#define EXTI_EXTICR2_EXTI5_3                (0x8UL << EXTI_EXTICR2_EXTI5_Pos)       /*!< 0x00000800 */
#define EXTI_EXTICR2_EXTI5_4                (0x10UL << EXTI_EXTICR2_EXTI5_Pos)      /*!< 0x00001000 */
#define EXTI_EXTICR2_EXTI5_5                (0x20UL << EXTI_EXTICR2_EXTI5_Pos)      /*!< 0x00002000 */
#define EXTI_EXTICR2_EXTI5_6                (0x40UL << EXTI_EXTICR2_EXTI5_Pos)      /*!< 0x00004000 */
#define EXTI_EXTICR2_EXTI5_7                (0x80UL << EXTI_EXTICR2_EXTI5_Pos)      /*!< 0x00008000 */
#define EXTI_EXTICR2_EXTI6_Pos              (16U)
#define EXTI_EXTICR2_EXTI6_Msk              (0xFFUL << EXTI_EXTICR2_EXTI6_Pos)      /*!< 0x00FF0000 */
#define EXTI_EXTICR2_EXTI6                  EXTI_EXTICR2_EXTI6_Msk                  /*!< EXTI 6 configuration */
#define EXTI_EXTICR2_EXTI6_0                (0x1UL << EXTI_EXTICR2_EXTI6_Pos)       /*!< 0x00010000 */
#define EXTI_EXTICR2_EXTI6_1                (0x2UL << EXTI_EXTICR2_EXTI6_Pos)       /*!< 0x00020000 */
#define EXTI_EXTICR2_EXTI6_2                (0x4UL << EXTI_EXTICR2_EXTI6_Pos)       /*!< 0x00040000 */
#define EXTI_EXTICR2_EXTI6_3                (0x8UL << EXTI_EXTICR2_EXTI6_Pos)       /*!< 0x00080000 */
#define EXTI_EXTICR2_EXTI6_4                (0x10UL << EXTI_EXTICR2_EXTI6_Pos)      /*!< 0x00100000 */
#define EXTI_EXTICR2_EXTI6_5                (0x20UL << EXTI_EXTICR2_EXTI6_Pos)      /*!< 0x00200000 */
#define EXTI_EXTICR2_EXTI6_6                (0x40UL << EXTI_EXTICR2_EXTI6_Pos)      /*!< 0x00400000 */
#define EXTI_EXTICR2_EXTI6_7                (0x80UL << EXTI_EXTICR2_EXTI6_Pos)      /*!< 0x00800000 */
#define EXTI_EXTICR2_EXTI7_Pos              (24U)
#define EXTI_EXTICR2_EXTI7_Msk              (0xFFUL << EXTI_EXTICR2_EXTI7_Pos)      /*!< 0xFF000000 */
#define EXTI_EXTICR2_EXTI7                  EXTI_EXTICR2_EXTI7_Msk                  /*!< EXTI 7 configuration */
#define EXTI_EXTICR2_EXTI7_0                (0x1UL << EXTI_EXTICR2_EXTI7_Pos)       /*!< 0x01000000 */
#define EXTI_EXTICR2_EXTI7_1                (0x2UL << EXTI_EXTICR2_EXTI7_Pos)       /*!< 0x02000000 */
#define EXTI_EXTICR2_EXTI7_2                (0x4UL << EXTI_EXTICR2_EXTI7_Pos)       /*!< 0x04000000 */
#define EXTI_EXTICR2_EXTI7_3                (0x8UL << EXTI_EXTICR2_EXTI7_Pos)       /*!< 0x08000000 */
#define EXTI_EXTICR2_EXTI7_4                (0x10UL << EXTI_EXTICR2_EXTI7_Pos)      /*!< 0x10000000 */
#define EXTI_EXTICR2_EXTI7_5                (0x20UL << EXTI_EXTICR2_EXTI7_Pos)      /*!< 0x20000000 */
#define EXTI_EXTICR2_EXTI7_6                (0x40UL << EXTI_EXTICR2_EXTI7_Pos)      /*!< 0x40000000 */
#define EXTI_EXTICR2_EXTI7_7                (0x80UL << EXTI_EXTICR2_EXTI7_Pos)      /*!< 0x80000000 */

/*****************  Bit definition for EXTI_EXTICR3 register  **************/
#define EXTI_EXTICR3_EXTI8_Pos              (0U)
#define EXTI_EXTICR3_EXTI8_Msk              (0xFFUL << EXTI_EXTICR3_EXTI8_Pos)      /*!< 0x000000FF */
#define EXTI_EXTICR3_EXTI8                  EXTI_EXTICR3_EXTI8_Msk                  /*!< EXTI 8 configuration */
#define EXTI_EXTICR3_EXTI8_0                (0x1UL << EXTI_EXTICR3_EXTI8_Pos)       /*!< 0x00000001 */
#define EXTI_EXTICR3_EXTI8_1                (0x2UL << EXTI_EXTICR3_EXTI8_Pos)       /*!< 0x00000002 */
#define EXTI_EXTICR3_EXTI8_2                (0x4UL << EXTI_EXTICR3_EXTI8_Pos)       /*!< 0x00000004 */
#define EXTI_EXTICR3_EXTI8_3                (0x8UL << EXTI_EXTICR3_EXTI8_Pos)       /*!< 0x00000008 */
#define EXTI_EXTICR3_EXTI8_4                (0x10UL << EXTI_EXTICR3_EXTI8_Pos)      /*!< 0x00000010 */
#define EXTI_EXTICR3_EXTI8_5                (0x20UL << EXTI_EXTICR3_EXTI8_Pos)      /*!< 0x00000020 */
#define EXTI_EXTICR3_EXTI8_6                (0x40UL << EXTI_EXTICR3_EXTI8_Pos)      /*!< 0x00000040 */
#define EXTI_EXTICR3_EXTI8_7                (0x80UL << EXTI_EXTICR3_EXTI8_Pos)      /*!< 0x00000080 */
#define EXTI_EXTICR3_EXTI9_Pos              (8U)
#define EXTI_EXTICR3_EXTI9_Msk              (0xFFUL << EXTI_EXTICR3_EXTI9_Pos)      /*!< 0x0000FF00 */
#define EXTI_EXTICR3_EXTI9                  EXTI_EXTICR3_EXTI9_Msk                  /*!< EXTI 9 configuration */
#define EXTI_EXTICR3_EXTI9_0                (0x1UL << EXTI_EXTICR3_EXTI9_Pos)       /*!< 0x00000100 */
#define EXTI_EXTICR3_EXTI9_1                (0x2UL << EXTI_EXTICR3_EXTI9_Pos)       /*!< 0x00000200 */
#define EXTI_EXTICR3_EXTI9_2                (0x4UL << EXTI_EXTICR3_EXTI9_Pos)       /*!< 0x00000400 */
#define EXTI_EXTICR3_EXTI9_3                (0x8UL << EXTI_EXTICR3_EXTI9_Pos)       /*!< 0x00000800 */
#define EXTI_EXTICR3_EXTI9_4                (0x10UL << EXTI_EXTICR3_EXTI9_Pos)      /*!< 0x00001000 */
#define EXTI_EXTICR3_EXTI9_5                (0x20UL << EXTI_EXTICR3_EXTI9_Pos)      /*!< 0x00002000 */
#define EXTI_EXTICR3_EXTI9_6                (0x40UL << EXTI_EXTICR3_EXTI9_Pos)      /*!< 0x00004000 */
#define EXTI_EXTICR3_EXTI9_7                (0x80UL << EXTI_EXTICR3_EXTI9_Pos)      /*!< 0x00008000 */

/*****************  Bit definition for EXTI_EXTICR4 register  **************/
#define EXTI_EXTICR4_EXTI12_Pos             (0U)
#define EXTI_EXTICR4_EXTI12_Msk             (0xFFUL << EXTI_EXTICR4_EXTI12_Pos)      /*!< 0x000000FF */
#define EXTI_EXTICR4_EXTI12                 EXTI_EXTICR4_EXTI12_Msk                  /*!< EXTI 12 configuration */
#define EXTI_EXTICR4_EXTI12_0               (0x1UL << EXTI_EXTICR4_EXTI12_Pos)       /*!< 0x00000001 */
#define EXTI_EXTICR4_EXTI12_1               (0x2UL << EXTI_EXTICR4_EXTI12_Pos)       /*!< 0x00000002 */
#define EXTI_EXTICR4_EXTI12_2               (0x4UL << EXTI_EXTICR4_EXTI12_Pos)       /*!< 0x00000004 */
#define EXTI_EXTICR4_EXTI12_3               (0x8UL << EXTI_EXTICR4_EXTI12_Pos)       /*!< 0x00000008 */
#define EXTI_EXTICR4_EXTI12_4               (0x10UL << EXTI_EXTICR4_EXTI12_Pos)      /*!< 0x00000010 */
#define EXTI_EXTICR4_EXTI12_5               (0x20UL << EXTI_EXTICR4_EXTI12_Pos)      /*!< 0x00000020 */
#define EXTI_EXTICR4_EXTI12_6               (0x40UL << EXTI_EXTICR4_EXTI12_Pos)      /*!< 0x00000040 */
#define EXTI_EXTICR4_EXTI12_7               (0x80UL << EXTI_EXTICR4_EXTI12_Pos)      /*!< 0x00000080 */
#define EXTI_EXTICR4_EXTI13_Pos             (8U)
#define EXTI_EXTICR4_EXTI13_Msk             (0xFFUL << EXTI_EXTICR4_EXTI13_Pos)      /*!< 0x0000FF00 */
#define EXTI_EXTICR4_EXTI13                 EXTI_EXTICR4_EXTI13_Msk                  /*!< EXTI 13 configuration */
#define EXTI_EXTICR4_EXTI13_0               (0x1UL << EXTI_EXTICR4_EXTI13_Pos)       /*!< 0x00000100 */
#define EXTI_EXTICR4_EXTI13_1               (0x2UL << EXTI_EXTICR4_EXTI13_Pos)       /*!< 0x00000200 */
#define EXTI_EXTICR4_EXTI13_2               (0x4UL << EXTI_EXTICR4_EXTI13_Pos)       /*!< 0x00000400 */
#define EXTI_EXTICR4_EXTI13_3               (0x8UL << EXTI_EXTICR4_EXTI13_Pos)       /*!< 0x00000800 */
#define EXTI_EXTICR4_EXTI13_4               (0x10UL << EXTI_EXTICR4_EXTI13_Pos)      /*!< 0x00001000 */
#define EXTI_EXTICR4_EXTI13_5               (0x20UL << EXTI_EXTICR4_EXTI13_Pos)      /*!< 0x00002000 */
#define EXTI_EXTICR4_EXTI13_6               (0x40UL << EXTI_EXTICR4_EXTI13_Pos)      /*!< 0x00004000 */
#define EXTI_EXTICR4_EXTI13_7               (0x80UL << EXTI_EXTICR4_EXTI13_Pos)      /*!< 0x00008000 */
#define EXTI_EXTICR4_EXTI14_Pos             (16U)
#define EXTI_EXTICR4_EXTI14_Msk             (0xFFUL << EXTI_EXTICR4_EXTI14_Pos)      /*!< 0x00FF0000 */
#define EXTI_EXTICR4_EXTI14                 EXTI_EXTICR4_EXTI14_Msk                  /*!< EXTI 14 configuration */
#define EXTI_EXTICR4_EXTI14_0               (0x1UL << EXTI_EXTICR4_EXTI14_Pos)       /*!< 0x00010000 */
#define EXTI_EXTICR4_EXTI14_1               (0x2UL << EXTI_EXTICR4_EXTI14_Pos)       /*!< 0x00020000 */
#define EXTI_EXTICR4_EXTI14_2               (0x4UL << EXTI_EXTICR4_EXTI14_Pos)       /*!< 0x00040000 */
#define EXTI_EXTICR4_EXTI14_3               (0x8UL << EXTI_EXTICR4_EXTI14_Pos)       /*!< 0x00080000 */
#define EXTI_EXTICR4_EXTI14_4               (0x10UL << EXTI_EXTICR4_EXTI14_Pos)      /*!< 0x00100000 */
#define EXTI_EXTICR4_EXTI14_5               (0x20UL << EXTI_EXTICR4_EXTI14_Pos)      /*!< 0x00200000 */
#define EXTI_EXTICR4_EXTI14_6               (0x40UL << EXTI_EXTICR4_EXTI14_Pos)      /*!< 0x00400000 */
#define EXTI_EXTICR4_EXTI14_7               (0x80UL << EXTI_EXTICR4_EXTI14_Pos)      /*!< 0x00800000 */
#define EXTI_EXTICR4_EXTI15_Pos             (24U)
#define EXTI_EXTICR4_EXTI15_Msk             (0xFFUL << EXTI_EXTICR4_EXTI15_Pos)      /*!< 0xFF000000 */
#define EXTI_EXTICR4_EXTI15                 EXTI_EXTICR4_EXTI15_Msk                  /*!< EXTI 15 configuration */
#define EXTI_EXTICR4_EXTI15_0               (0x1UL << EXTI_EXTICR4_EXTI15_Pos)       /*!< 0x01000000 */
#define EXTI_EXTICR4_EXTI15_1               (0x2UL << EXTI_EXTICR4_EXTI15_Pos)       /*!< 0x02000000 */
#define EXTI_EXTICR4_EXTI15_2               (0x4UL << EXTI_EXTICR4_EXTI15_Pos)       /*!< 0x04000000 */
#define EXTI_EXTICR4_EXTI15_3               (0x8UL << EXTI_EXTICR4_EXTI15_Pos)       /*!< 0x08000000 */
#define EXTI_EXTICR4_EXTI15_4               (0x10UL << EXTI_EXTICR4_EXTI15_Pos)      /*!< 0x10000000 */
#define EXTI_EXTICR4_EXTI15_5               (0x20UL << EXTI_EXTICR4_EXTI15_Pos)      /*!< 0x20000000 */
#define EXTI_EXTICR4_EXTI15_6               (0x40UL << EXTI_EXTICR4_EXTI15_Pos)      /*!< 0x40000000 */
#define EXTI_EXTICR4_EXTI15_7               (0x80UL << EXTI_EXTICR4_EXTI15_Pos)      /*!< 0x80000000 */

/*******************  Bit definition for EXTI_IMR1 register  ******************/
#define EXTI_IMR1_IM0_Pos                   (0U)
#define EXTI_IMR1_IM0_Msk                   (0x1UL << EXTI_IMR1_IM0_Pos)            /*!< 0x00000001 */
#define EXTI_IMR1_IM0                       EXTI_IMR1_IM0_Msk                       /*!< Interrupt Mask on line 0 */
#define EXTI_IMR1_IM1_Pos                   (1U)
#define EXTI_IMR1_IM1_Msk                   (0x1UL << EXTI_IMR1_IM1_Pos)            /*!< 0x00000002 */
#define EXTI_IMR1_IM1                       EXTI_IMR1_IM1_Msk                       /*!< Interrupt Mask on line 1 */
#define EXTI_IMR1_IM2_Pos                   (2U)
#define EXTI_IMR1_IM2_Msk                   (0x1UL << EXTI_IMR1_IM2_Pos)            /*!< 0x00000004 */
#define EXTI_IMR1_IM2                       EXTI_IMR1_IM2_Msk                       /*!< Interrupt Mask on line 2 */
#define EXTI_IMR1_IM3_Pos                   (3U)
#define EXTI_IMR1_IM3_Msk                   (0x1UL << EXTI_IMR1_IM3_Pos)            /*!< 0x00000008 */
#define EXTI_IMR1_IM3                       EXTI_IMR1_IM3_Msk                       /*!< Interrupt Mask on line 3 */
#define EXTI_IMR1_IM4_Pos                   (4U)
#define EXTI_IMR1_IM4_Msk                   (0x1UL << EXTI_IMR1_IM4_Pos)            /*!< 0x00000010 */
#define EXTI_IMR1_IM4                       EXTI_IMR1_IM4_Msk                       /*!< Interrupt Mask on line 4 */
#define EXTI_IMR1_IM5_Pos                   (5U)
#define EXTI_IMR1_IM5_Msk                   (0x1UL << EXTI_IMR1_IM5_Pos)            /*!< 0x00000020 */
#define EXTI_IMR1_IM5                       EXTI_IMR1_IM5_Msk                       /*!< Interrupt Mask on line 5 */
#define EXTI_IMR1_IM6_Pos                   (6U)
#define EXTI_IMR1_IM6_Msk                   (0x1UL << EXTI_IMR1_IM6_Pos)            /*!< 0x00000040 */
#define EXTI_IMR1_IM6                       EXTI_IMR1_IM6_Msk                       /*!< Interrupt Mask on line 6 */
#define EXTI_IMR1_IM7_Pos                   (7U)
#define EXTI_IMR1_IM7_Msk                   (0x1UL << EXTI_IMR1_IM7_Pos)            /*!< 0x00000080 */
#define EXTI_IMR1_IM7                       EXTI_IMR1_IM7_Msk                       /*!< Interrupt Mask on line 7 */
#define EXTI_IMR1_IM8_Pos                   (8U)
#define EXTI_IMR1_IM8_Msk                   (0x1UL << EXTI_IMR1_IM8_Pos)            /*!< 0x00000100 */
#define EXTI_IMR1_IM8                       EXTI_IMR1_IM8_Msk                       /*!< Interrupt Mask on line 8 */
#define EXTI_IMR1_IM9_Pos                   (9U)
#define EXTI_IMR1_IM9_Msk                   (0x1UL << EXTI_IMR1_IM9_Pos)            /*!< 0x00000200 */
#define EXTI_IMR1_IM9                       EXTI_IMR1_IM9_Msk                       /*!< Interrupt Mask on line 9 */
#define EXTI_IMR1_IM12_Pos                  (12U)
#define EXTI_IMR1_IM12_Msk                  (0x1UL << EXTI_IMR1_IM12_Pos)           /*!< 0x00001000 */
#define EXTI_IMR1_IM12                      EXTI_IMR1_IM12_Msk                      /*!< Interrupt Mask on line 12 */
#define EXTI_IMR1_IM13_Pos                  (13U)
#define EXTI_IMR1_IM13_Msk                  (0x1UL << EXTI_IMR1_IM13_Pos)           /*!< 0x00002000 */
#define EXTI_IMR1_IM13                      EXTI_IMR1_IM13_Msk                      /*!< Interrupt Mask on line 13 */
#define EXTI_IMR1_IM14_Pos                  (14U)
#define EXTI_IMR1_IM14_Msk                  (0x1UL << EXTI_IMR1_IM14_Pos)           /*!< 0x00004000 */
#define EXTI_IMR1_IM14                      EXTI_IMR1_IM14_Msk                      /*!< Interrupt Mask on line 14 */
#define EXTI_IMR1_IM15_Pos                  (15U)
#define EXTI_IMR1_IM15_Msk                  (0x1UL << EXTI_IMR1_IM15_Pos)           /*!< 0x00008000 */
#define EXTI_IMR1_IM15                      EXTI_IMR1_IM15_Msk                      /*!< Interrupt Mask on line 15 */
#define EXTI_IMR1_IM18_Pos                  (18U)
#define EXTI_IMR1_IM18_Msk                  (0x1UL << EXTI_IMR1_IM18_Pos)           /*!< 0x00040000 */
#define EXTI_IMR1_IM18                      EXTI_IMR1_IM18_Msk                      /*!< Interrupt Mask on line 18 */

/*******************  Bit definition for EXTI_EMR1 register  ******************/
#define EXTI_EMR1_EM0_Pos                   (0U)
#define EXTI_EMR1_EM0_Msk                   (0x1UL << EXTI_EMR1_EM0_Pos)            /*!< 0x00000001 */
#define EXTI_EMR1_EM0                       EXTI_EMR1_EM0_Msk                       /*!< Event Mask on line 0 */
#define EXTI_EMR1_EM1_Pos                   (1U)
#define EXTI_EMR1_EM1_Msk                   (0x1UL << EXTI_EMR1_EM1_Pos)            /*!< 0x00000002 */
#define EXTI_EMR1_EM1                       EXTI_EMR1_EM1_Msk                       /*!< Event Mask on line 1 */
#define EXTI_EMR1_EM2_Pos                   (2U)
#define EXTI_EMR1_EM2_Msk                   (0x1UL << EXTI_EMR1_EM2_Pos)            /*!< 0x00000004 */
#define EXTI_EMR1_EM2                       EXTI_EMR1_EM2_Msk                       /*!< Event Mask on line 2 */
#define EXTI_EMR1_EM3_Pos                   (3U)
#define EXTI_EMR1_EM3_Msk                   (0x1UL << EXTI_EMR1_EM3_Pos)            /*!< 0x00000008 */
#define EXTI_EMR1_EM3                       EXTI_EMR1_EM3_Msk                       /*!< Event Mask on line 3 */
#define EXTI_EMR1_EM4_Pos                   (4U)
#define EXTI_EMR1_EM4_Msk                   (0x1UL << EXTI_EMR1_EM4_Pos)            /*!< 0x00000010 */
#define EXTI_EMR1_EM4                       EXTI_EMR1_EM4_Msk                       /*!< Event Mask on line 4 */
#define EXTI_EMR1_EM5_Pos                   (5U)
#define EXTI_EMR1_EM5_Msk                   (0x1UL << EXTI_EMR1_EM5_Pos)            /*!< 0x00000020 */
#define EXTI_EMR1_EM5                       EXTI_EMR1_EM5_Msk                       /*!< Event Mask on line 5 */
#define EXTI_EMR1_EM6_Pos                   (6U)
#define EXTI_EMR1_EM6_Msk                   (0x1UL << EXTI_EMR1_EM6_Pos)            /*!< 0x00000040 */
#define EXTI_EMR1_EM6                       EXTI_EMR1_EM6_Msk                       /*!< Event Mask on line 6 */
#define EXTI_EMR1_EM7_Pos                   (7U)
#define EXTI_EMR1_EM7_Msk                   (0x1UL << EXTI_EMR1_EM7_Pos)            /*!< 0x00000080 */
#define EXTI_EMR1_EM7                       EXTI_EMR1_EM7_Msk                       /*!< Event Mask on line 7 */
#define EXTI_EMR1_EM8_Pos                   (8U)
#define EXTI_EMR1_EM8_Msk                   (0x1UL << EXTI_EMR1_EM8_Pos)            /*!< 0x00000100 */
#define EXTI_EMR1_EM8                       EXTI_EMR1_EM8_Msk                       /*!< Event Mask on line 8 */
#define EXTI_EMR1_EM9_Pos                   (9U)
#define EXTI_EMR1_EM9_Msk                   (0x1UL << EXTI_EMR1_EM9_Pos)            /*!< 0x00000200 */
#define EXTI_EMR1_EM9                       EXTI_EMR1_EM9_Msk                       /*!< Event Mask on line 9 */
#define EXTI_EMR1_EM12_Pos                  (12U)
#define EXTI_EMR1_EM12_Msk                  (0x1UL << EXTI_EMR1_EM12_Pos)           /*!< 0x00001000 */
#define EXTI_EMR1_EM12                      EXTI_EMR1_EM12_Msk                      /*!< Event Mask on line 12 */
#define EXTI_EMR1_EM13_Pos                  (13U)
#define EXTI_EMR1_EM13_Msk                  (0x1UL << EXTI_EMR1_EM13_Pos)           /*!< 0x00002000 */
#define EXTI_EMR1_EM13                      EXTI_EMR1_EM13_Msk                      /*!< Event Mask on line 13 */
#define EXTI_EMR1_EM14_Pos                  (14U)
#define EXTI_EMR1_EM14_Msk                  (0x1UL << EXTI_EMR1_EM14_Pos)           /*!< 0x00004000 */
#define EXTI_EMR1_EM14                      EXTI_EMR1_EM14_Msk                      /*!< Event Mask on line 14 */
#define EXTI_EMR1_EM15_Pos                  (15U)
#define EXTI_EMR1_EM15_Msk                  (0x1UL << EXTI_EMR1_EM15_Pos)           /*!< 0x00008000 */
#define EXTI_EMR1_EM15                      EXTI_EMR1_EM15_Msk                      /*!< Event Mask on line 15 */
#define EXTI_EMR1_EM18_Pos                  (18U)
#define EXTI_EMR1_EM18_Msk                  (0x1UL << EXTI_EMR1_EM18_Pos)           /*!< 0x00040000 */
#define EXTI_EMR1_EM18                      EXTI_EMR1_EM18_Msk                      /*!< Event Mask on line 18 */


/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
#define FLASH_LATENCY_DEFAULT               FLASH_ACR_LATENCY_0                     /* FLASH Latency 1 Wait State */

/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos               (0U)
#define FLASH_ACR_LATENCY_Msk               (0xFUL << FLASH_ACR_LATENCY_Pos)        /*!< 0x0000000F */
#define FLASH_ACR_LATENCY                   FLASH_ACR_LATENCY_Msk                   /*!< Latency    */
#define FLASH_ACR_LATENCY_0                 (0x1UL << FLASH_ACR_LATENCY_Pos)        /*!< 0x00000001 */
#define FLASH_ACR_LATENCY_1                 (0x2UL << FLASH_ACR_LATENCY_Pos)        /*!< 0x00000002 */
#define FLASH_ACR_LATENCY_2                 (0x4UL << FLASH_ACR_LATENCY_Pos)        /*!< 0x00000004 */
#define FLASH_ACR_LATENCY_3                 (0x8UL << FLASH_ACR_LATENCY_Pos)        /*!< 0x00000008 */
#define FLASH_ACR_PRFTEN_Pos                (8U)
#define FLASH_ACR_PRFTEN_Msk                (0x1UL << FLASH_ACR_PRFTEN_Pos)         /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN                    FLASH_ACR_PRFTEN_Msk                    /*!< Prefetch enable */
#define FLASH_ACR_LPM_Pos                   (11U)
#define FLASH_ACR_LPM_Msk                   (0x1UL << FLASH_ACR_LPM_Pos)            /*!< 0x00000800 */
#define FLASH_ACR_LPM                       FLASH_ACR_LPM_Msk                       /*!< Low-Power read mode */
#define FLASH_ACR_PDREQ_Pos                 (12U)
#define FLASH_ACR_PDREQ_Msk                 (0x1UL << FLASH_ACR_PDREQ_Pos)          /*!< 0x00001000 */
#define FLASH_ACR_PDREQ                     FLASH_ACR_PDREQ_Msk                     /*!< Flash power-down mode request */
#define FLASH_ACR_SLEEP_PD_Pos              (14U)
#define FLASH_ACR_SLEEP_PD_Msk              (0x1UL << FLASH_ACR_SLEEP_PD_Pos)       /*!< 0x00004000 */
#define FLASH_ACR_SLEEP_PD                  FLASH_ACR_SLEEP_PD_Msk                  /*!< Flash power-down mode during sleep */

/******************  Bits definition for FLASH_NSKEYR register  *****************/
#define FLASH_NSKEYR_NSKEY_Pos              (0U)
#define FLASH_NSKEYR_NSKEY_Msk              (0xFFFFFFFFUL << FLASH_NSKEYR_NSKEY_Pos)    /*!< 0xFFFFFFFFF */
#define FLASH_NSKEYR_NSKEY                  FLASH_NSKEYR_NSKEY_Msk                      /*!< Flash memory non-secure key */


/******************  Bits definition for FLASH_OPTKEYR register  *****************/
#define FLASH_OPTKEYR_OPTKEY_Pos            (0U)
#define FLASH_OPTKEYR_OPTKEY_Msk            (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEY                FLASH_OPTKEYR_OPTKEY_Msk                    /*!< Option byte key */

/******************  Bits definition for FLASH_PDKEYR register  *****************/
#define FLASH_PDKEYR_PDKEY_Pos              (0U)
#define FLASH_PDKEYR_PDKEY_Msk              (0xFFFFFFFFUL << FLASH_PDKEYR_PDKEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_PDKEYR_PDKEY                  FLASH_PDKEYR_PDKEY_Msk                    /*!< Flash power-down key */

/******************  Bits definition for FLASH_NSSR register  *****************/
#define FLASH_NSSR_EOP_Pos                  (0U)
#define FLASH_NSSR_EOP_Msk                  (0x1UL << FLASH_NSSR_EOP_Pos)           /*!< 0x00000001 */
#define FLASH_NSSR_EOP                      FLASH_NSSR_EOP_Msk                      /*!< Non-secure end of operation */
#define FLASH_NSSR_OPERR_Pos                (1U)
#define FLASH_NSSR_OPERR_Msk                (0x1UL << FLASH_NSSR_OPERR_Pos)         /*!< 0x00000002 */
#define FLASH_NSSR_OPERR                    FLASH_NSSR_OPERR_Msk                    /*!< Non-secure operation error */
#define FLASH_NSSR_PROGERR_Pos              (3U)
#define FLASH_NSSR_PROGERR_Msk              (0x1UL << FLASH_NSSR_PROGERR_Pos)       /*!< 0x00000008 */
#define FLASH_NSSR_PROGERR                  FLASH_NSSR_PROGERR_Msk                  /*!< Non-secure programming error */
#define FLASH_NSSR_WRPERR_Pos               (4U)
#define FLASH_NSSR_WRPERR_Msk               (0x1UL << FLASH_NSSR_WRPERR_Pos)        /*!< 0x00000010 */
#define FLASH_NSSR_WRPERR                   FLASH_NSSR_WRPERR_Msk                   /*!< Non-secure write protection error */
#define FLASH_NSSR_PGAERR_Pos               (5U)
#define FLASH_NSSR_PGAERR_Msk               (0x1UL << FLASH_NSSR_PGAERR_Pos)        /*!< 0x00000020 */
#define FLASH_NSSR_PGAERR                   FLASH_NSSR_PGAERR_Msk                   /*!< Non-secure programming alignment error */
#define FLASH_NSSR_SIZERR_Pos               (6U)
#define FLASH_NSSR_SIZERR_Msk               (0x1UL << FLASH_NSSR_SIZERR_Pos)        /*!< 0x00000040 */
#define FLASH_NSSR_SIZERR                   FLASH_NSSR_SIZERR_Msk                   /*!< Non-secure size error */
#define FLASH_NSSR_PGSERR_Pos               (7U)
#define FLASH_NSSR_PGSERR_Msk               (0x1UL << FLASH_NSSR_PGSERR_Pos)        /*!< 0x00000080 */
#define FLASH_NSSR_PGSERR                   FLASH_NSSR_PGSERR_Msk                   /*!< Non-secure programming sequence error */
#define FLASH_NSSR_OPTWERR_Pos              (13U)
#define FLASH_NSSR_OPTWERR_Msk              (0x1UL << FLASH_NSSR_OPTWERR_Pos)       /*!< 0x00002000 */
#define FLASH_NSSR_OPTWERR                  FLASH_NSSR_OPTWERR_Msk                  /*!< Option write error */
#define FLASH_NSSR_BSY_Pos                  (16U)
#define FLASH_NSSR_BSY_Msk                  (0x1UL << FLASH_NSSR_BSY_Pos)           /*!< 0x00010000 */
#define FLASH_NSSR_BSY                      FLASH_NSSR_BSY_Msk                      /*!< Non-secure busy */
#define FLASH_NSSR_WDW_Pos                  (17U)
#define FLASH_NSSR_WDW_Msk                  (0x1UL << FLASH_NSSR_WDW_Pos)           /*!< 0x00020000 */
#define FLASH_NSSR_WDW                      FLASH_NSSR_WDW_Msk                      /*!< Non-secure wait data to write */
#define FLASH_NSSR_OEM1LOCK_Pos             (18U)
#define FLASH_NSSR_OEM1LOCK_Msk             (0x1UL << FLASH_NSSR_OEM1LOCK_Pos)      /*!< 0x00040000 */
#define FLASH_NSSR_OEM1LOCK                 FLASH_NSSR_OEM1LOCK_Msk                 /*!< OEM1 lock */
#define FLASH_NSSR_OEM2LOCK_Pos             (19U)
#define FLASH_NSSR_OEM2LOCK_Msk             (0x1UL << FLASH_NSSR_OEM2LOCK_Pos)      /*!< 0x00080000 */
#define FLASH_NSSR_OEM2LOCK                 FLASH_NSSR_OEM2LOCK_Msk                 /*!< OEM2 lock */
#define FLASH_NSSR_PD_Pos                   (20U)
#define FLASH_NSSR_PD_Msk                   (0x1UL << FLASH_NSSR_PD_Pos)            /*!< 0x00100000 */
#define FLASH_NSSR_PD                       FLASH_NSSR_PD_Msk                       /*!< Flash in power-down mode */


/******************  Bits definition for FLASH_NSCR1 register  *****************/
#define FLASH_NSCR1_PG_Pos                  (0U)
#define FLASH_NSCR1_PG_Msk                  (0x1UL << FLASH_NSCR1_PG_Pos)           /*!< 0x00000001 */
#define FLASH_NSCR1_PG                      FLASH_NSCR1_PG_Msk                      /*!< Non-secure Programming */
#define FLASH_NSCR1_PER_Pos                 (1U)
#define FLASH_NSCR1_PER_Msk                 (0x1UL << FLASH_NSCR1_PER_Pos)          /*!< 0x00000002 */
#define FLASH_NSCR1_PER                     FLASH_NSCR1_PER_Msk                     /*!< Non-secure Page Erase */
#define FLASH_NSCR1_MER_Pos                 (2U)
#define FLASH_NSCR1_MER_Msk                 (0x1UL << FLASH_NSCR1_MER_Pos)          /*!< 0x00000004 */
#define FLASH_NSCR1_MER                     FLASH_NSCR1_MER_Msk                     /*!< Non-secure Mass Erase */
#define FLASH_NSCR1_PNB_Pos                 (3U)
#define FLASH_NSCR1_PNB_Msk                 (0x3FUL << FLASH_NSCR1_PNB_Pos)         /*!< 0x000001F8 */
#define FLASH_NSCR1_PNB                     FLASH_NSCR1_PNB_Msk                     /*!< Non-secure Page Number selection */
#define FLASH_NSCR1_BWR_Pos                 (14U)
#define FLASH_NSCR1_BWR_Msk                 (0x1UL << FLASH_NSCR1_BWR_Pos)          /*!< 0x00004000 */
#define FLASH_NSCR1_BWR                     FLASH_NSCR1_BWR_Msk                     /*!< Non-secure Burst Write Programming mode */
#define FLASH_NSCR1_STRT_Pos                (16U)
#define FLASH_NSCR1_STRT_Msk                (0x1UL << FLASH_NSCR1_STRT_Pos)         /*!< 0x00010000 */
#define FLASH_NSCR1_STRT                    FLASH_NSCR1_STRT_Msk                    /*!< Non-secure Start */
#define FLASH_NSCR1_OPTSTRT_Pos             (17U)
#define FLASH_NSCR1_OPTSTRT_Msk             (0x1UL << FLASH_NSCR1_OPTSTRT_Pos)      /*!< 0x00020000 */
#define FLASH_NSCR1_OPTSTRT                 FLASH_NSCR1_OPTSTRT_Msk                 /*!< Option Modification Start */
#define FLASH_NSCR1_EOPIE_Pos               (24U)
#define FLASH_NSCR1_EOPIE_Msk               (0x1UL << FLASH_NSCR1_EOPIE_Pos)        /*!< 0x01000000 */
#define FLASH_NSCR1_EOPIE                   FLASH_NSCR1_EOPIE_Msk                   /*!< Non-secure End of operation interrupt enable */
#define FLASH_NSCR1_ERRIE_Pos               (25U)
#define FLASH_NSCR1_ERRIE_Msk               (0x1UL << FLASH_NSCR1_ERRIE_Pos)        /*!< 0x02000000 */
#define FLASH_NSCR1_ERRIE                   FLASH_NSCR1_ERRIE_Msk                   /*!< Non-secure error interrupt enable */
#define FLASH_NSCR1_OBL_LAUNCH_Pos          (27U)
#define FLASH_NSCR1_OBL_LAUNCH_Msk          (0x1UL << FLASH_NSCR1_OBL_LAUNCH_Pos)   /*!< 0x08000000 */
#define FLASH_NSCR1_OBL_LAUNCH              FLASH_NSCR1_OBL_LAUNCH_Msk              /*!< Force the option byte loading */
#define FLASH_NSCR1_OPTLOCK_Pos             (30U)
#define FLASH_NSCR1_OPTLOCK_Msk             (0x1UL << FLASH_NSCR1_OPTLOCK_Pos)      /*!< 0x40000000 */
#define FLASH_NSCR1_OPTLOCK                 FLASH_NSCR1_OPTLOCK_Msk                 /*!< Option Lock */
#define FLASH_NSCR1_LOCK_Pos                (31U)
#define FLASH_NSCR1_LOCK_Msk                (0x1UL << FLASH_NSCR1_LOCK_Pos)         /*!< 0x80000000 */
#define FLASH_NSCR1_LOCK                    FLASH_NSCR1_LOCK_Msk                    /*!< Non-secure Lock */


/*******************  Bits definition for FLASH_ECCR register  ***************/
#define FLASH_ECCR_ADDR_ECC_Pos             (0U)
#define FLASH_ECCR_ADDR_ECC_Msk             (0x7FFFFUL << FLASH_ECCR_ADDR_ECC_Pos)  /*!< 0x0007FFFF */
#define FLASH_ECCR_ADDR_ECC                 FLASH_ECCR_ADDR_ECC_Msk                 /*!< ECC fail address */
#define FLASH_ECCR_SYSF_ECC_Pos             (22U)
#define FLASH_ECCR_SYSF_ECC_Msk             (0x1UL << FLASH_ECCR_SYSF_ECC_Pos)      /*!< 0x00400000 */
#define FLASH_ECCR_SYSF_ECC                 FLASH_ECCR_SYSF_ECC_Msk                 /*!< System Flash ECC fail */
#define FLASH_ECCR_ECCIE_Pos                (24U)
#define FLASH_ECCR_ECCIE_Msk                (0x1UL << FLASH_ECCR_ECCIE_Pos)         /*!< 0x01000000 */
#define FLASH_ECCR_ECCIE                    FLASH_ECCR_ECCIE_Msk                    /*!< ECC correction interrupt enable */
#define FLASH_ECCR_ECCC_Pos                 (30U)
#define FLASH_ECCR_ECCC_Msk                 (0x1UL << FLASH_ECCR_ECCC_Pos)          /*!< 0x40000000 */
#define FLASH_ECCR_ECCC                     FLASH_ECCR_ECCC_Msk                     /*!< ECC correction */
#define FLASH_ECCR_ECCD_Pos                 (31U)
#define FLASH_ECCR_ECCD_Msk                 (0x1UL << FLASH_ECCR_ECCD_Pos)          /*!< 0x80000000 */
#define FLASH_ECCR_ECCD                     FLASH_ECCR_ECCD_Msk                     /*!< ECC detection */

/*******************  Bits definition for FLASH_OPSR register  ***************/
#define FLASH_OPSR_ADDR_OP_Pos              (0U)
#define FLASH_OPSR_ADDR_OP_Msk              (0x7FFFFUL << FLASH_OPSR_ADDR_OP_Pos)   /*!< 0x0007FFFF */
#define FLASH_OPSR_ADDR_OP                  FLASH_OPSR_ADDR_OP_Msk                  /*!< Interrupted operation address */
#define FLASH_OPSR_SYSF_OP_Pos              (22U)
#define FLASH_OPSR_SYSF_OP_Msk              (0x1UL << FLASH_OPSR_SYSF_OP_Pos)       /*!< 0x00400000 */
#define FLASH_OPSR_SYSF_OP                  FLASH_OPSR_SYSF_OP_Msk                  /*!< Operation in system Flash memory interrupted */
#define FLASH_OPSR_CODE_OP_Pos              (29U)
#define FLASH_OPSR_CODE_OP_Msk              (0x7UL << FLASH_OPSR_CODE_OP_Pos)       /*!< 0x07000000 */
#define FLASH_OPSR_CODE_OP                  FLASH_OPSR_CODE_OP_Msk                  /*!<  Flash memory operation code */
#define FLASH_OPSR_CODE_OP_0                (0x1UL << FLASH_OPSR_CODE_OP_Pos)       /*!< 0x01000000 */
#define FLASH_OPSR_CODE_OP_1                (0x2UL << FLASH_OPSR_CODE_OP_Pos)       /*!< 0x02000000 */
#define FLASH_OPSR_CODE_OP_2                (0x4UL << FLASH_OPSR_CODE_OP_Pos)       /*!< 0x04000000 */

/*******************  Bits definition for FLASH_NSCR2 register  ***************/
#define FLASH_NSCR2_PS_Pos                  (0U)
#define FLASH_NSCR2_PS_Msk                  (0x1UL << FLASH_NSCR2_PS_Pos)           /*!< 0x00000001 */
#define FLASH_NSCR2_PS                      FLASH_NSCR2_PS_Msk                      /*!< Program suspend request */
#define FLASH_NSCR2_ES_Pos                  (1U)
#define FLASH_NSCR2_ES_Msk                  (0x1UL << FLASH_NSCR2_ES_Pos)           /*!< 0x00000002 */
#define FLASH_NSCR2_ES                      FLASH_NSCR2_ES_Msk                      /*!< Erase suspend request */

/*******************  Bits definition for FLASH_OPTR register  ***************/
#define FLASH_OPTR_RDP_Pos                  (0U)
#define FLASH_OPTR_RDP_Msk                  (0xFFUL << FLASH_OPTR_RDP_Pos)          /*!< 0x000000FF */
#define FLASH_OPTR_RDP                      FLASH_OPTR_RDP_Msk                      /*!< Readout protection level */
#define FLASH_OPTR_BOR_LEV_Pos              (8U)
#define FLASH_OPTR_BOR_LEV_Msk              (0x7UL << FLASH_OPTR_BOR_LEV_Pos)       /*!< 0x00000700 */
#define FLASH_OPTR_BOR_LEV                  FLASH_OPTR_BOR_LEV_Msk                  /*!< BOR reset Level */
#define FLASH_OPTR_BOR_LEV_0                (0x1UL << FLASH_OPTR_BOR_LEV_Pos)       /*!< 0x00000100 */
#define FLASH_OPTR_BOR_LEV_1                (0x2UL << FLASH_OPTR_BOR_LEV_Pos)       /*!< 0x00000200 */
#define FLASH_OPTR_BOR_LEV_2                (0x4UL << FLASH_OPTR_BOR_LEV_Pos)       /*!< 0x00000400 */
#define FLASH_OPTR_nRST_STOP_Pos            (12U)
#define FLASH_OPTR_nRST_STOP_Msk            (0x1UL << FLASH_OPTR_nRST_STOP_Pos)     /*!< 0x00001000 */
#define FLASH_OPTR_nRST_STOP                FLASH_OPTR_nRST_STOP_Msk                /*!< nRST_STOP */
#define FLASH_OPTR_nRST_STDBY_Pos           (13U)
#define FLASH_OPTR_nRST_STDBY_Msk           (0x1UL << FLASH_OPTR_nRST_STDBY_Pos)    /*!< 0x00002000 */
#define FLASH_OPTR_nRST_STDBY               FLASH_OPTR_nRST_STDBY_Msk               /*!< nRST_STDBY */
#define FLASH_OPTR_SRAM1_RST_Pos            (15U)
#define FLASH_OPTR_SRAM1_RST_Msk            (0x1UL << FLASH_OPTR_SRAM1_RST_Pos)     /*!< 0x00008000 */
#define FLASH_OPTR_SRAM1_RST                FLASH_OPTR_SRAM1_RST_Msk                /*!< SRAM1 erase upon system reset */
#define FLASH_OPTR_IWDG_SW_Pos              (16U)
#define FLASH_OPTR_IWDG_SW_Msk              (0x1UL << FLASH_OPTR_IWDG_SW_Pos)       /*!< 0x00010000 */
#define FLASH_OPTR_IWDG_SW                  FLASH_OPTR_IWDG_SW_Msk                  /*!< Independent watchdog selection */
#define FLASH_OPTR_IWDG_STOP_Pos            (17U)
#define FLASH_OPTR_IWDG_STOP_Msk            (0x1UL << FLASH_OPTR_IWDG_STOP_Pos)     /*!< 0x00020000 */
#define FLASH_OPTR_IWDG_STOP                FLASH_OPTR_IWDG_STOP_Msk                /*!< Independent watchdog counter freeze in Stop mode */
#define FLASH_OPTR_IWDG_STDBY_Pos           (18U)
#define FLASH_OPTR_IWDG_STDBY_Msk           (0x1UL << FLASH_OPTR_IWDG_STDBY_Pos)    /*!< 0x00040000 */
#define FLASH_OPTR_IWDG_STDBY               FLASH_OPTR_IWDG_STDBY_Msk               /*!< Independent watchdog counter freeze in Standby mode */
#define FLASH_OPTR_WWDG_SW_Pos              (19U)
#define FLASH_OPTR_WWDG_SW_Msk              (0x1UL << FLASH_OPTR_WWDG_SW_Pos)       /*!< 0x00080000 */
#define FLASH_OPTR_WWDG_SW                  FLASH_OPTR_WWDG_SW_Msk                  /*!< Window watchdog selection */
#define FLASH_OPTR_SRAM2_PE_Pos             (24U)
#define FLASH_OPTR_SRAM2_PE_Msk             (0x1UL << FLASH_OPTR_SRAM2_PE_Pos)      /*!< 0x01000000 */
#define FLASH_OPTR_SRAM2_PE                 FLASH_OPTR_SRAM2_PE_Msk                 /*!< SRAM2 ECC detection and correction enable*/
#define FLASH_OPTR_SRAM2_RST_Pos            (25U)
#define FLASH_OPTR_SRAM2_RST_Msk            (0x1UL << FLASH_OPTR_SRAM2_RST_Pos)     /*!< 0x02000000 */
#define FLASH_OPTR_SRAM2_RST                FLASH_OPTR_SRAM2_RST_Msk                /*!< SRAM2 erase when system reset */
#define FLASH_OPTR_nSWBOOT0_Pos             (26U)
#define FLASH_OPTR_nSWBOOT0_Msk             (0x1UL << FLASH_OPTR_nSWBOOT0_Pos)      /*!< 0x04000000 */
#define FLASH_OPTR_nSWBOOT0                 FLASH_OPTR_nSWBOOT0_Msk                 /*!< Software BOOT0 */
#define FLASH_OPTR_nBOOT0_Pos               (27U)
#define FLASH_OPTR_nBOOT0_Msk               (0x1UL << FLASH_OPTR_nBOOT0_Pos)        /*!< 0x08000000 */
#define FLASH_OPTR_nBOOT0                   FLASH_OPTR_nBOOT0_Msk                   /*!< nBOOT0 option bit */

/****************  Bits definition for FLASH_NSBOOTADD0R register  ************/
#define FLASH_NSBOOTADD0R_NSBOOTADD0_Pos    (7U)
#define FLASH_NSBOOTADD0R_NSBOOTADD0_Msk    (0x1FFFFFFUL << FLASH_NSBOOTADD0R_NSBOOTADD0_Pos) /*!< 0xFFFFFF80 */
#define FLASH_NSBOOTADD0R_NSBOOTADD0        FLASH_NSBOOTADD0R_NSBOOTADD0_Msk        /*!< Non-secure boot address 0 */

/****************  Bits definition for FLASH_NSBOOTADD1R register  ************/
#define FLASH_NSBOOTADD1R_NSBOOTADD1_Pos    (7U)
#define FLASH_NSBOOTADD1R_NSBOOTADD1_Msk    (0x1FFFFFFUL << FLASH_NSBOOTADD1R_NSBOOTADD1_Pos) /*!< 0xFFFFFF80 */
#define FLASH_NSBOOTADD1R_NSBOOTADD1        FLASH_NSBOOTADD1R_NSBOOTADD1_Msk        /*!< Non-secure boot address 1 */

/******************  Bits definition for FLASH_WRPAR register  ***************/
#define FLASH_WRPAR_WRPA_PSTRT_Pos          (0U)
#define FLASH_WRPAR_WRPA_PSTRT_Msk          (0x3FUL << FLASH_WRPAR_WRPA_PSTRT_Pos) /*!< 0x0000003F */
#define FLASH_WRPAR_WRPA_PSTRT              FLASH_WRPAR_WRPA_PSTRT_Msk            /*!< WPR first area A start page */
#define FLASH_WRPAR_WRPA_PEND_Pos           (16U)
#define FLASH_WRPAR_WRPA_PEND_Msk           (0x3FUL << FLASH_WRPAR_WRPA_PEND_Pos) /*!< 0x003F0000 */
#define FLASH_WRPAR_WRPA_PEND               FLASH_WRPAR_WRPA_PEND_Msk             /*!< WPR first area A end page */
#define FLASH_WRPAR_UNLOCK_Pos              (31U)
#define FLASH_WRPAR_UNLOCK_Msk              (0x1UL << FLASH_WRPAR_UNLOCK_Pos)      /*!< 0x80000000 */
#define FLASH_WRPAR_UNLOCK                  FLASH_WRPAR_UNLOCK_Msk                 /*!< WPR first area A unlock */

/******************  Bits definition for FLASH_WRPBR register  ***************/
#define FLASH_WRPBR_WRPB_PSTRT_Pos          (0U)
#define FLASH_WRPBR_WRPB_PSTRT_Msk          (0x3FUL << FLASH_WRPBR_WRPB_PSTRT_Pos) /*!< 0x0000003F */
#define FLASH_WRPBR_WRPB_PSTRT              FLASH_WRPBR_WRPB_PSTRT_Msk            /*!< WPR second area B start page */
#define FLASH_WRPBR_WRPB_PEND_Pos           (16U)
#define FLASH_WRPBR_WRPB_PEND_Msk           (0x3FUL << FLASH_WRPBR_WRPB_PEND_Pos) /*!< 0x003F0000 */
#define FLASH_WRPBR_WRPB_PEND               FLASH_WRPBR_WRPB_PEND_Msk             /*!< WPR second area B end page */
#define FLASH_WRPBR_UNLOCK_Pos              (31U)
#define FLASH_WRPBR_UNLOCK_Msk              (0x1UL << FLASH_WRPBR_UNLOCK_Pos)      /*!< 0x80000000 */
#define FLASH_WRPBR_UNLOCK                  FLASH_WRPBR_UNLOCK_Msk                 /*!< WPR first area B unlock */

/******************  Bits definition for FLASH_OEM1KEYR1 register  *****************/
#define FLASH_OEM1KEYR1_OEM1KEY_Pos         (0U)
#define FLASH_OEM1KEYR1_OEM1KEY_Msk         (0xFFFFFFFFUL << FLASH_OEM1KEYR1_OEM1KEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_OEM1KEYR1_OEM1KEY             FLASH_OEM1KEYR1_OEM1KEY_Msk                    /*!< OEM1 least significant bytes key */

/******************  Bits definition for FLASH_OEM1KEYR2 register  *****************/
#define FLASH_OEM1KEYR2_OEM1KEY_Pos         (0U)
#define FLASH_OEM1KEYR2_OEM1KEY_Msk         (0xFFFFFFFFUL << FLASH_OEM1KEYR2_OEM1KEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_OEM1KEYR2_OEM1KEY             FLASH_OEM1KEYR2_OEM1KEY_Msk                    /*!< OEM1 most significant bytes key */

/******************  Bits definition for FLASH_OEM2KEYR1 register  *****************/
#define FLASH_OEM2KEYR1_OEM2KEY_Pos         (0U)
#define FLASH_OEM2KEYR1_OEM2KEY_Msk         (0xFFFFFFFFUL << FLASH_OEM2KEYR1_OEM2KEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_OEM2KEYR1_OEM2KEY             FLASH_OEM2KEYR1_OEM2KEY_Msk                    /*!< OEM2 least significant bytes key */

/******************  Bits definition for FLASH_OEM2KEYR2 register  *****************/
#define FLASH_OEM2KEYR2_OEM2KEY_Pos         (0U)
#define FLASH_OEM2KEYR2_OEM2KEY_Msk         (0xFFFFFFFFUL << FLASH_OEM2KEYR2_OEM2KEY_Pos)  /*!< 0xFFFFFFFFF */
#define FLASH_OEM2KEYR2_OEM2KEY             FLASH_OEM2KEYR2_OEM2KEY_Msk                    /*!< OEM2 most significant bytes key */

/******************************************************************************/
/*                                                                            */
/*                       General Purpose IOs (GPIO)                           */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODE0_Pos                (0U)
#define GPIO_MODER_MODE0_Msk                (0x3UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000003 */
#define GPIO_MODER_MODE0                    GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE0_0                  (0x1UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1                  (0x2UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos                (2U)
#define GPIO_MODER_MODE1_Msk                (0x3UL << GPIO_MODER_MODE1_Pos)         /*!< 0x0000000C */
#define GPIO_MODER_MODE1                    GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE1_0                  (0x1UL << GPIO_MODER_MODE1_Pos)         /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1                  (0x2UL << GPIO_MODER_MODE1_Pos)         /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos                (4U)
#define GPIO_MODER_MODE2_Msk                (0x3UL << GPIO_MODER_MODE2_Pos)         /*!< 0x00000030 */
#define GPIO_MODER_MODE2                    GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE2_0                  (0x1UL << GPIO_MODER_MODE2_Pos)         /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1                  (0x2UL << GPIO_MODER_MODE2_Pos)         /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos                (6U)
#define GPIO_MODER_MODE3_Msk                (0x3UL << GPIO_MODER_MODE3_Pos)         /*!< 0x000000C0 */
#define GPIO_MODER_MODE3                    GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE3_0                  (0x1UL << GPIO_MODER_MODE3_Pos)         /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1                  (0x2UL << GPIO_MODER_MODE3_Pos)         /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos                (8U)
#define GPIO_MODER_MODE4_Msk                (0x3UL << GPIO_MODER_MODE4_Pos)         /*!< 0x00000300 */
#define GPIO_MODER_MODE4                    GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE4_0                  (0x1UL << GPIO_MODER_MODE4_Pos)         /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1                  (0x2UL << GPIO_MODER_MODE4_Pos)         /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos                (10U)
#define GPIO_MODER_MODE5_Msk                (0x3UL << GPIO_MODER_MODE5_Pos)         /*!< 0x00000C00 */
#define GPIO_MODER_MODE5                    GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE5_0                  (0x1UL << GPIO_MODER_MODE5_Pos)         /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1                  (0x2UL << GPIO_MODER_MODE5_Pos)         /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos                (12U)
#define GPIO_MODER_MODE6_Msk                (0x3UL << GPIO_MODER_MODE6_Pos)         /*!< 0x00003000 */
#define GPIO_MODER_MODE6                    GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE6_0                  (0x1UL << GPIO_MODER_MODE6_Pos)         /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1                  (0x2UL << GPIO_MODER_MODE6_Pos)         /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos                (14U)
#define GPIO_MODER_MODE7_Msk                (0x3UL << GPIO_MODER_MODE7_Pos)         /*!< 0x0000C000 */
#define GPIO_MODER_MODE7                    GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE7_0                  (0x1UL << GPIO_MODER_MODE7_Pos)         /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1                  (0x2UL << GPIO_MODER_MODE7_Pos)         /*!< 0x00008000 */
#define GPIO_MODER_MODE8_Pos                (16U)
#define GPIO_MODER_MODE8_Msk                (0x3UL << GPIO_MODER_MODE8_Pos)         /*!< 0x00030000 */
#define GPIO_MODER_MODE8                    GPIO_MODER_MODE8_Msk
#define GPIO_MODER_MODE8_0                  (0x1UL << GPIO_MODER_MODE8_Pos)         /*!< 0x00010000 */
#define GPIO_MODER_MODE8_1                  (0x2UL << GPIO_MODER_MODE8_Pos)         /*!< 0x00020000 */
#define GPIO_MODER_MODE9_Pos                (18U)
#define GPIO_MODER_MODE9_Msk                (0x3UL << GPIO_MODER_MODE9_Pos)         /*!< 0x000C0000 */
#define GPIO_MODER_MODE9                    GPIO_MODER_MODE9_Msk
#define GPIO_MODER_MODE9_0                  (0x1UL << GPIO_MODER_MODE9_Pos)         /*!< 0x00040000 */
#define GPIO_MODER_MODE9_1                  (0x2UL << GPIO_MODER_MODE9_Pos)         /*!< 0x00080000 */
#define GPIO_MODER_MODE10_Pos               (20U)
#define GPIO_MODER_MODE10_Msk               (0x3UL << GPIO_MODER_MODE10_Pos)        /*!< 0x00300000 */
#define GPIO_MODER_MODE10                   GPIO_MODER_MODE10_Msk
#define GPIO_MODER_MODE10_0                 (0x1UL << GPIO_MODER_MODE10_Pos)        /*!< 0x00100000 */
#define GPIO_MODER_MODE10_1                 (0x2UL << GPIO_MODER_MODE10_Pos)        /*!< 0x00200000 */
#define GPIO_MODER_MODE11_Pos               (22U)
#define GPIO_MODER_MODE11_Msk               (0x3UL << GPIO_MODER_MODE11_Pos)        /*!< 0x00C00000 */
#define GPIO_MODER_MODE11                   GPIO_MODER_MODE11_Msk
#define GPIO_MODER_MODE11_0                 (0x1UL << GPIO_MODER_MODE11_Pos)        /*!< 0x00400000 */
#define GPIO_MODER_MODE11_1                 (0x2UL << GPIO_MODER_MODE11_Pos)        /*!< 0x00800000 */
#define GPIO_MODER_MODE12_Pos               (24U)
#define GPIO_MODER_MODE12_Msk               (0x3UL << GPIO_MODER_MODE12_Pos)        /*!< 0x03000000 */
#define GPIO_MODER_MODE12                   GPIO_MODER_MODE12_Msk
#define GPIO_MODER_MODE12_0                 (0x1UL << GPIO_MODER_MODE12_Pos)        /*!< 0x01000000 */
#define GPIO_MODER_MODE12_1                 (0x2UL << GPIO_MODER_MODE12_Pos)        /*!< 0x02000000 */
#define GPIO_MODER_MODE13_Pos               (26U)
#define GPIO_MODER_MODE13_Msk               (0x3UL << GPIO_MODER_MODE13_Pos)        /*!< 0x0C000000 */
#define GPIO_MODER_MODE13                   GPIO_MODER_MODE13_Msk
#define GPIO_MODER_MODE13_0                 (0x1UL << GPIO_MODER_MODE13_Pos)        /*!< 0x04000000 */
#define GPIO_MODER_MODE13_1                 (0x2UL << GPIO_MODER_MODE13_Pos)        /*!< 0x08000000 */
#define GPIO_MODER_MODE14_Pos               (28U)
#define GPIO_MODER_MODE14_Msk               (0x3UL << GPIO_MODER_MODE14_Pos)        /*!< 0x30000000 */
#define GPIO_MODER_MODE14                   GPIO_MODER_MODE14_Msk
#define GPIO_MODER_MODE14_0                 (0x1UL << GPIO_MODER_MODE14_Pos)        /*!< 0x10000000 */
#define GPIO_MODER_MODE14_1                 (0x2UL << GPIO_MODER_MODE14_Pos)        /*!< 0x20000000 */
#define GPIO_MODER_MODE15_Pos               (30U)
#define GPIO_MODER_MODE15_Msk               (0x3UL << GPIO_MODER_MODE15_Pos)        /*!< 0xC0000000 */
#define GPIO_MODER_MODE15                   GPIO_MODER_MODE15_Msk
#define GPIO_MODER_MODE15_0                 (0x1UL << GPIO_MODER_MODE15_Pos)        /*!< 0x40000000 */
#define GPIO_MODER_MODE15_1                 (0x2UL << GPIO_MODER_MODE15_Pos)        /*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT0_Pos                 (0U)
#define GPIO_OTYPER_OT0_Msk                 (0x1UL << GPIO_OTYPER_OT0_Pos)          /*!< 0x00000001 */
#define GPIO_OTYPER_OT0                     GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos                 (1U)
#define GPIO_OTYPER_OT1_Msk                 (0x1UL << GPIO_OTYPER_OT1_Pos)          /*!< 0x00000002 */
#define GPIO_OTYPER_OT1                     GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos                 (2U)
#define GPIO_OTYPER_OT2_Msk                 (0x1UL << GPIO_OTYPER_OT2_Pos)          /*!< 0x00000004 */
#define GPIO_OTYPER_OT2                     GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos                 (3U)
#define GPIO_OTYPER_OT3_Msk                 (0x1UL << GPIO_OTYPER_OT3_Pos)          /*!< 0x00000008 */
#define GPIO_OTYPER_OT3                     GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos                 (4U)
#define GPIO_OTYPER_OT4_Msk                 (0x1UL << GPIO_OTYPER_OT4_Pos)          /*!< 0x00000010 */
#define GPIO_OTYPER_OT4                     GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos                 (5U)
#define GPIO_OTYPER_OT5_Msk                 (0x1UL << GPIO_OTYPER_OT5_Pos)          /*!< 0x00000020 */
#define GPIO_OTYPER_OT5                     GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos                 (6U)
#define GPIO_OTYPER_OT6_Msk                 (0x1UL << GPIO_OTYPER_OT6_Pos)          /*!< 0x00000040 */
#define GPIO_OTYPER_OT6                     GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos                 (7U)
#define GPIO_OTYPER_OT7_Msk                 (0x1UL << GPIO_OTYPER_OT7_Pos)          /*!< 0x00000080 */
#define GPIO_OTYPER_OT7                     GPIO_OTYPER_OT7_Msk
#define GPIO_OTYPER_OT8_Pos                 (8U)
#define GPIO_OTYPER_OT8_Msk                 (0x1UL << GPIO_OTYPER_OT8_Pos)          /*!< 0x00000100 */
#define GPIO_OTYPER_OT8                     GPIO_OTYPER_OT8_Msk
#define GPIO_OTYPER_OT9_Pos                 (9U)
#define GPIO_OTYPER_OT9_Msk                 (0x1UL << GPIO_OTYPER_OT9_Pos)          /*!< 0x00000200 */
#define GPIO_OTYPER_OT9                     GPIO_OTYPER_OT9_Msk
#define GPIO_OTYPER_OT10_Pos                (10U)
#define GPIO_OTYPER_OT10_Msk                (0x1UL << GPIO_OTYPER_OT10_Pos)         /*!< 0x00000400 */
#define GPIO_OTYPER_OT10                    GPIO_OTYPER_OT10_Msk
#define GPIO_OTYPER_OT11_Pos                (11U)
#define GPIO_OTYPER_OT11_Msk                (0x1UL << GPIO_OTYPER_OT11_Pos)         /*!< 0x00000800 */
#define GPIO_OTYPER_OT11                    GPIO_OTYPER_OT11_Msk
#define GPIO_OTYPER_OT12_Pos                (12U)
#define GPIO_OTYPER_OT12_Msk                (0x1UL << GPIO_OTYPER_OT12_Pos)         /*!< 0x00001000 */
#define GPIO_OTYPER_OT12                    GPIO_OTYPER_OT12_Msk
#define GPIO_OTYPER_OT13_Pos                (13U)
#define GPIO_OTYPER_OT13_Msk                (0x1UL << GPIO_OTYPER_OT13_Pos)         /*!< 0x00002000 */
#define GPIO_OTYPER_OT13                    GPIO_OTYPER_OT13_Msk
#define GPIO_OTYPER_OT14_Pos                (14U)
#define GPIO_OTYPER_OT14_Msk                (0x1UL << GPIO_OTYPER_OT14_Pos)         /*!< 0x00004000 */
#define GPIO_OTYPER_OT14                    GPIO_OTYPER_OT14_Msk
#define GPIO_OTYPER_OT15_Pos                (15U)
#define GPIO_OTYPER_OT15_Msk                (0x1UL << GPIO_OTYPER_OT15_Pos)         /*!< 0x00008000 */
#define GPIO_OTYPER_OT15                    GPIO_OTYPER_OT15_Msk

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDR_OSPEED0_Pos            (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)     /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0                GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_0              (0x1UL << GPIO_OSPEEDR_OSPEED0_Pos)     /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1              (0x2UL << GPIO_OSPEEDR_OSPEED0_Pos)     /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos            (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)     /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1                GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_0              (0x1UL << GPIO_OSPEEDR_OSPEED1_Pos)     /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1              (0x2UL << GPIO_OSPEEDR_OSPEED1_Pos)     /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos            (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)     /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2                GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_0              (0x1UL << GPIO_OSPEEDR_OSPEED2_Pos)     /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1              (0x2UL << GPIO_OSPEEDR_OSPEED2_Pos)     /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos            (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)     /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3                GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_0              (0x1UL << GPIO_OSPEEDR_OSPEED3_Pos)     /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1              (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos)     /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos            (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)     /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4                GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_0              (0x1UL << GPIO_OSPEEDR_OSPEED4_Pos)     /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1              (0x2UL << GPIO_OSPEEDR_OSPEED4_Pos)     /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos            (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)     /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5                GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_0              (0x1UL << GPIO_OSPEEDR_OSPEED5_Pos)     /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1              (0x2UL << GPIO_OSPEEDR_OSPEED5_Pos)     /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos            (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)     /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6                GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_0              (0x1UL << GPIO_OSPEEDR_OSPEED6_Pos)     /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1              (0x2UL << GPIO_OSPEEDR_OSPEED6_Pos)     /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos            (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)     /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7                GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_0              (0x1UL << GPIO_OSPEEDR_OSPEED7_Pos)     /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1              (0x2UL << GPIO_OSPEEDR_OSPEED7_Pos)     /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEED8_Pos            (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)     /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEED8                GPIO_OSPEEDR_OSPEED8_Msk
#define GPIO_OSPEEDR_OSPEED8_0              (0x1UL << GPIO_OSPEEDR_OSPEED8_Pos)     /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEED8_1              (0x2UL << GPIO_OSPEEDR_OSPEED8_Pos)     /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEED9_Pos            (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk            (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)     /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEED9                GPIO_OSPEEDR_OSPEED9_Msk
#define GPIO_OSPEEDR_OSPEED9_0              (0x1UL << GPIO_OSPEEDR_OSPEED9_Pos)     /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEED9_1              (0x2UL << GPIO_OSPEEDR_OSPEED9_Pos)     /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEED10_Pos           (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)    /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEED10               GPIO_OSPEEDR_OSPEED10_Msk
#define GPIO_OSPEEDR_OSPEED10_0             (0x1UL << GPIO_OSPEEDR_OSPEED10_Pos)    /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEED10_1             (0x2UL << GPIO_OSPEEDR_OSPEED10_Pos)    /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEED11_Pos           (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)    /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEED11               GPIO_OSPEEDR_OSPEED11_Msk
#define GPIO_OSPEEDR_OSPEED11_0             (0x1UL << GPIO_OSPEEDR_OSPEED11_Pos)    /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEED11_1             (0x2UL << GPIO_OSPEEDR_OSPEED11_Pos)    /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEED12_Pos           (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)    /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEED12               GPIO_OSPEEDR_OSPEED12_Msk
#define GPIO_OSPEEDR_OSPEED12_0             (0x1UL << GPIO_OSPEEDR_OSPEED12_Pos)    /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEED12_1             (0x2UL << GPIO_OSPEEDR_OSPEED12_Pos)    /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEED13_Pos           (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)    /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEED13               GPIO_OSPEEDR_OSPEED13_Msk
#define GPIO_OSPEEDR_OSPEED13_0             (0x1UL << GPIO_OSPEEDR_OSPEED13_Pos)    /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEED13_1             (0x2UL << GPIO_OSPEEDR_OSPEED13_Pos)    /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEED14_Pos           (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)    /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEED14               GPIO_OSPEEDR_OSPEED14_Msk
#define GPIO_OSPEEDR_OSPEED14_0             (0x1UL << GPIO_OSPEEDR_OSPEED14_Pos)    /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEED14_1             (0x2UL << GPIO_OSPEEDR_OSPEED14_Pos)    /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEED15_Pos           (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk           (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)    /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEED15               GPIO_OSPEEDR_OSPEED15_Msk
#define GPIO_OSPEEDR_OSPEED15_0             (0x1UL << GPIO_OSPEEDR_OSPEED15_Pos)    /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEED15_1             (0x2UL << GPIO_OSPEEDR_OSPEED15_Pos)    /*!< 0x80000000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPD0_Pos                (0U)
#define GPIO_PUPDR_PUPD0_Msk                (0x3UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0                    GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_0                  (0x1UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1                  (0x2UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos                (2U)
#define GPIO_PUPDR_PUPD1_Msk                (0x3UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1                    GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_0                  (0x1UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1                  (0x2UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos                (4U)
#define GPIO_PUPDR_PUPD2_Msk                (0x3UL << GPIO_PUPDR_PUPD2_Pos)         /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2                    GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_0                  (0x1UL << GPIO_PUPDR_PUPD2_Pos)         /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1                  (0x2UL << GPIO_PUPDR_PUPD2_Pos)         /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos                (6U)
#define GPIO_PUPDR_PUPD3_Msk                (0x3UL << GPIO_PUPDR_PUPD3_Pos)         /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3                    GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_0                  (0x1UL << GPIO_PUPDR_PUPD3_Pos)         /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1                  (0x2UL << GPIO_PUPDR_PUPD3_Pos)         /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos                (8U)
#define GPIO_PUPDR_PUPD4_Msk                (0x3UL << GPIO_PUPDR_PUPD4_Pos)         /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4                    GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_0                  (0x1UL << GPIO_PUPDR_PUPD4_Pos)         /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1                  (0x2UL << GPIO_PUPDR_PUPD4_Pos)         /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos                (10U)
#define GPIO_PUPDR_PUPD5_Msk                (0x3UL << GPIO_PUPDR_PUPD5_Pos)         /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5                    GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_0                  (0x1UL << GPIO_PUPDR_PUPD5_Pos)         /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1                  (0x2UL << GPIO_PUPDR_PUPD5_Pos)         /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos                (12U)
#define GPIO_PUPDR_PUPD6_Msk                (0x3UL << GPIO_PUPDR_PUPD6_Pos)         /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6                    GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_0                  (0x1UL << GPIO_PUPDR_PUPD6_Pos)         /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1                  (0x2UL << GPIO_PUPDR_PUPD6_Pos)         /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos                (14U)
#define GPIO_PUPDR_PUPD7_Msk                (0x3UL << GPIO_PUPDR_PUPD7_Pos)         /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7                    GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_0                  (0x1UL << GPIO_PUPDR_PUPD7_Pos)         /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1                  (0x2UL << GPIO_PUPDR_PUPD7_Pos)         /*!< 0x00008000 */
#define GPIO_PUPDR_PUPD8_Pos                (16U)
#define GPIO_PUPDR_PUPD8_Msk                (0x3UL << GPIO_PUPDR_PUPD8_Pos)         /*!< 0x00030000 */
#define GPIO_PUPDR_PUPD8                    GPIO_PUPDR_PUPD8_Msk
#define GPIO_PUPDR_PUPD8_0                  (0x1UL << GPIO_PUPDR_PUPD8_Pos)         /*!< 0x00010000 */
#define GPIO_PUPDR_PUPD8_1                  (0x2UL << GPIO_PUPDR_PUPD8_Pos)         /*!< 0x00020000 */
#define GPIO_PUPDR_PUPD9_Pos                (18U)
#define GPIO_PUPDR_PUPD9_Msk                (0x3UL << GPIO_PUPDR_PUPD9_Pos)         /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPD9                    GPIO_PUPDR_PUPD9_Msk
#define GPIO_PUPDR_PUPD9_0                  (0x1UL << GPIO_PUPDR_PUPD9_Pos)         /*!< 0x00040000 */
#define GPIO_PUPDR_PUPD9_1                  (0x2UL << GPIO_PUPDR_PUPD9_Pos)         /*!< 0x00080000 */
#define GPIO_PUPDR_PUPD10_Pos               (20U)
#define GPIO_PUPDR_PUPD10_Msk               (0x3UL << GPIO_PUPDR_PUPD10_Pos)        /*!< 0x00300000 */
#define GPIO_PUPDR_PUPD10                   GPIO_PUPDR_PUPD10_Msk
#define GPIO_PUPDR_PUPD10_0                 (0x1UL << GPIO_PUPDR_PUPD10_Pos)        /*!< 0x00100000 */
#define GPIO_PUPDR_PUPD10_1                 (0x2UL << GPIO_PUPDR_PUPD10_Pos)        /*!< 0x00200000 */
#define GPIO_PUPDR_PUPD11_Pos               (22U)
#define GPIO_PUPDR_PUPD11_Msk               (0x3UL << GPIO_PUPDR_PUPD11_Pos)        /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPD11                   GPIO_PUPDR_PUPD11_Msk
#define GPIO_PUPDR_PUPD11_0                 (0x1UL << GPIO_PUPDR_PUPD11_Pos)        /*!< 0x00400000 */
#define GPIO_PUPDR_PUPD11_1                 (0x2UL << GPIO_PUPDR_PUPD11_Pos)        /*!< 0x00800000 */
#define GPIO_PUPDR_PUPD12_Pos               (24U)
#define GPIO_PUPDR_PUPD12_Msk               (0x3UL << GPIO_PUPDR_PUPD12_Pos)        /*!< 0x03000000 */
#define GPIO_PUPDR_PUPD12                   GPIO_PUPDR_PUPD12_Msk
#define GPIO_PUPDR_PUPD12_0                 (0x1UL << GPIO_PUPDR_PUPD12_Pos)        /*!< 0x01000000 */
#define GPIO_PUPDR_PUPD12_1                 (0x2UL << GPIO_PUPDR_PUPD12_Pos)        /*!< 0x02000000 */
#define GPIO_PUPDR_PUPD13_Pos               (26U)
#define GPIO_PUPDR_PUPD13_Msk               (0x3UL << GPIO_PUPDR_PUPD13_Pos)        /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPD13                   GPIO_PUPDR_PUPD13_Msk
#define GPIO_PUPDR_PUPD13_0                 (0x1UL << GPIO_PUPDR_PUPD13_Pos)        /*!< 0x04000000 */
#define GPIO_PUPDR_PUPD13_1                 (0x2UL << GPIO_PUPDR_PUPD13_Pos)        /*!< 0x08000000 */
#define GPIO_PUPDR_PUPD14_Pos               (28U)
#define GPIO_PUPDR_PUPD14_Msk               (0x3UL << GPIO_PUPDR_PUPD14_Pos)        /*!< 0x30000000 */
#define GPIO_PUPDR_PUPD14                   GPIO_PUPDR_PUPD14_Msk
#define GPIO_PUPDR_PUPD14_0                 (0x1UL << GPIO_PUPDR_PUPD14_Pos)        /*!< 0x10000000 */
#define GPIO_PUPDR_PUPD14_1                 (0x2UL << GPIO_PUPDR_PUPD14_Pos)        /*!< 0x20000000 */
#define GPIO_PUPDR_PUPD15_Pos               (30U)
#define GPIO_PUPDR_PUPD15_Msk               (0x3UL << GPIO_PUPDR_PUPD15_Pos)        /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPD15                   GPIO_PUPDR_PUPD15_Msk
#define GPIO_PUPDR_PUPD15_0                 (0x1UL << GPIO_PUPDR_PUPD15_Pos)        /*!< 0x40000000 */
#define GPIO_PUPDR_PUPD15_1                 (0x2UL << GPIO_PUPDR_PUPD15_Pos)        /*!< 0x80000000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos                    (0U)
#define GPIO_IDR_ID0_Msk                    (0x1UL << GPIO_IDR_ID0_Pos)             /*!< 0x00000001 */
#define GPIO_IDR_ID0                        GPIO_IDR_ID0_Msk
#define GPIO_IDR_ID1_Pos                    (1U)
#define GPIO_IDR_ID1_Msk                    (0x1UL << GPIO_IDR_ID1_Pos)             /*!< 0x00000002 */
#define GPIO_IDR_ID1                        GPIO_IDR_ID1_Msk
#define GPIO_IDR_ID2_Pos                    (2U)
#define GPIO_IDR_ID2_Msk                    (0x1UL << GPIO_IDR_ID2_Pos)             /*!< 0x00000004 */
#define GPIO_IDR_ID2                        GPIO_IDR_ID2_Msk
#define GPIO_IDR_ID3_Pos                    (3U)
#define GPIO_IDR_ID3_Msk                    (0x1UL << GPIO_IDR_ID3_Pos)             /*!< 0x00000008 */
#define GPIO_IDR_ID3                        GPIO_IDR_ID3_Msk
#define GPIO_IDR_ID4_Pos                    (4U)
#define GPIO_IDR_ID4_Msk                    (0x1UL << GPIO_IDR_ID4_Pos)             /*!< 0x00000010 */
#define GPIO_IDR_ID4                        GPIO_IDR_ID4_Msk
#define GPIO_IDR_ID5_Pos                    (5U)
#define GPIO_IDR_ID5_Msk                    (0x1UL << GPIO_IDR_ID5_Pos)             /*!< 0x00000020 */
#define GPIO_IDR_ID5                        GPIO_IDR_ID5_Msk
#define GPIO_IDR_ID6_Pos                    (6U)
#define GPIO_IDR_ID6_Msk                    (0x1UL << GPIO_IDR_ID6_Pos)             /*!< 0x00000040 */
#define GPIO_IDR_ID6                        GPIO_IDR_ID6_Msk
#define GPIO_IDR_ID7_Pos                    (7U)
#define GPIO_IDR_ID7_Msk                    (0x1UL << GPIO_IDR_ID7_Pos)             /*!< 0x00000080 */
#define GPIO_IDR_ID7                        GPIO_IDR_ID7_Msk
#define GPIO_IDR_ID8_Pos                    (8U)
#define GPIO_IDR_ID8_Msk                    (0x1UL << GPIO_IDR_ID8_Pos)             /*!< 0x00000100 */
#define GPIO_IDR_ID8                        GPIO_IDR_ID8_Msk
#define GPIO_IDR_ID9_Pos                    (9U)
#define GPIO_IDR_ID9_Msk                    (0x1UL << GPIO_IDR_ID9_Pos)             /*!< 0x00000200 */
#define GPIO_IDR_ID9                        GPIO_IDR_ID9_Msk
#define GPIO_IDR_ID10_Pos                   (10U)
#define GPIO_IDR_ID10_Msk                   (0x1UL << GPIO_IDR_ID10_Pos)            /*!< 0x00000400 */
#define GPIO_IDR_ID10                       GPIO_IDR_ID10_Msk
#define GPIO_IDR_ID11_Pos                   (11U)
#define GPIO_IDR_ID11_Msk                   (0x1UL << GPIO_IDR_ID11_Pos)            /*!< 0x00000800 */
#define GPIO_IDR_ID11                       GPIO_IDR_ID11_Msk
#define GPIO_IDR_ID12_Pos                   (12U)
#define GPIO_IDR_ID12_Msk                   (0x1UL << GPIO_IDR_ID12_Pos)            /*!< 0x00001000 */
#define GPIO_IDR_ID12                       GPIO_IDR_ID12_Msk
#define GPIO_IDR_ID13_Pos                   (13U)
#define GPIO_IDR_ID13_Msk                   (0x1UL << GPIO_IDR_ID13_Pos)            /*!< 0x00002000 */
#define GPIO_IDR_ID13                       GPIO_IDR_ID13_Msk
#define GPIO_IDR_ID14_Pos                   (14U)
#define GPIO_IDR_ID14_Msk                   (0x1UL << GPIO_IDR_ID14_Pos)            /*!< 0x00004000 */
#define GPIO_IDR_ID14                       GPIO_IDR_ID14_Msk
#define GPIO_IDR_ID15_Pos                   (15U)
#define GPIO_IDR_ID15_Msk                   (0x1UL << GPIO_IDR_ID15_Pos)            /*!< 0x00008000 */
#define GPIO_IDR_ID15                       GPIO_IDR_ID15_Msk

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos                    (0U)
#define GPIO_ODR_OD0_Msk                    (0x1UL << GPIO_ODR_OD0_Pos)             /*!< 0x00000001 */
#define GPIO_ODR_OD0                        GPIO_ODR_OD0_Msk
#define GPIO_ODR_OD1_Pos                    (1U)
#define GPIO_ODR_OD1_Msk                    (0x1UL << GPIO_ODR_OD1_Pos)             /*!< 0x00000002 */
#define GPIO_ODR_OD1                        GPIO_ODR_OD1_Msk
#define GPIO_ODR_OD2_Pos                    (2U)
#define GPIO_ODR_OD2_Msk                    (0x1UL << GPIO_ODR_OD2_Pos)             /*!< 0x00000004 */
#define GPIO_ODR_OD2                        GPIO_ODR_OD2_Msk
#define GPIO_ODR_OD3_Pos                    (3U)
#define GPIO_ODR_OD3_Msk                    (0x1UL << GPIO_ODR_OD3_Pos)             /*!< 0x00000008 */
#define GPIO_ODR_OD3                        GPIO_ODR_OD3_Msk
#define GPIO_ODR_OD4_Pos                    (4U)
#define GPIO_ODR_OD4_Msk                    (0x1UL << GPIO_ODR_OD4_Pos)             /*!< 0x00000010 */
#define GPIO_ODR_OD4                        GPIO_ODR_OD4_Msk
#define GPIO_ODR_OD5_Pos                    (5U)
#define GPIO_ODR_OD5_Msk                    (0x1UL << GPIO_ODR_OD5_Pos)             /*!< 0x00000020 */
#define GPIO_ODR_OD5                        GPIO_ODR_OD5_Msk
#define GPIO_ODR_OD6_Pos                    (6U)
#define GPIO_ODR_OD6_Msk                    (0x1UL << GPIO_ODR_OD6_Pos)             /*!< 0x00000040 */
#define GPIO_ODR_OD6                        GPIO_ODR_OD6_Msk
#define GPIO_ODR_OD7_Pos                    (7U)
#define GPIO_ODR_OD7_Msk                    (0x1UL << GPIO_ODR_OD7_Pos)             /*!< 0x00000080 */
#define GPIO_ODR_OD7                        GPIO_ODR_OD7_Msk
#define GPIO_ODR_OD8_Pos                    (8U)
#define GPIO_ODR_OD8_Msk                    (0x1UL << GPIO_ODR_OD8_Pos)             /*!< 0x00000100 */
#define GPIO_ODR_OD8                        GPIO_ODR_OD8_Msk
#define GPIO_ODR_OD9_Pos                    (9U)
#define GPIO_ODR_OD9_Msk                    (0x1UL << GPIO_ODR_OD9_Pos)             /*!< 0x00000200 */
#define GPIO_ODR_OD9                        GPIO_ODR_OD9_Msk
#define GPIO_ODR_OD10_Pos                   (10U)
#define GPIO_ODR_OD10_Msk                   (0x1UL << GPIO_ODR_OD10_Pos)            /*!< 0x00000400 */
#define GPIO_ODR_OD10                       GPIO_ODR_OD10_Msk
#define GPIO_ODR_OD11_Pos                   (11U)
#define GPIO_ODR_OD11_Msk                   (0x1UL << GPIO_ODR_OD11_Pos)            /*!< 0x00000800 */
#define GPIO_ODR_OD11                       GPIO_ODR_OD11_Msk
#define GPIO_ODR_OD12_Pos                   (12U)
#define GPIO_ODR_OD12_Msk                   (0x1UL << GPIO_ODR_OD12_Pos)            /*!< 0x00001000 */
#define GPIO_ODR_OD12                       GPIO_ODR_OD12_Msk
#define GPIO_ODR_OD13_Pos                   (13U)
#define GPIO_ODR_OD13_Msk                   (0x1UL << GPIO_ODR_OD13_Pos)            /*!< 0x00002000 */
#define GPIO_ODR_OD13                       GPIO_ODR_OD13_Msk
#define GPIO_ODR_OD14_Pos                   (14U)
#define GPIO_ODR_OD14_Msk                   (0x1UL << GPIO_ODR_OD14_Pos)            /*!< 0x00004000 */
#define GPIO_ODR_OD14                       GPIO_ODR_OD14_Msk
#define GPIO_ODR_OD15_Pos                   (15U)
#define GPIO_ODR_OD15_Msk                   (0x1UL << GPIO_ODR_OD15_Pos)            /*!< 0x00008000 */
#define GPIO_ODR_OD15                       GPIO_ODR_OD15_Msk

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS0_Pos                   (0U)
#define GPIO_BSRR_BS0_Msk                   (0x1UL << GPIO_BSRR_BS0_Pos)            /*!< 0x00000001 */
#define GPIO_BSRR_BS0                       GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos                   (1U)
#define GPIO_BSRR_BS1_Msk                   (0x1UL << GPIO_BSRR_BS1_Pos)            /*!< 0x00000002 */
#define GPIO_BSRR_BS1                       GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos                   (2U)
#define GPIO_BSRR_BS2_Msk                   (0x1UL << GPIO_BSRR_BS2_Pos)            /*!< 0x00000004 */
#define GPIO_BSRR_BS2                       GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos                   (3U)
#define GPIO_BSRR_BS3_Msk                   (0x1UL << GPIO_BSRR_BS3_Pos)            /*!< 0x00000008 */
#define GPIO_BSRR_BS3                       GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos                   (4U)
#define GPIO_BSRR_BS4_Msk                   (0x1UL << GPIO_BSRR_BS4_Pos)            /*!< 0x00000010 */
#define GPIO_BSRR_BS4                       GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos                   (5U)
#define GPIO_BSRR_BS5_Msk                   (0x1UL << GPIO_BSRR_BS5_Pos)            /*!< 0x00000020 */
#define GPIO_BSRR_BS5                       GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos                   (6U)
#define GPIO_BSRR_BS6_Msk                   (0x1UL << GPIO_BSRR_BS6_Pos)            /*!< 0x00000040 */
#define GPIO_BSRR_BS6                       GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos                   (7U)
#define GPIO_BSRR_BS7_Msk                   (0x1UL << GPIO_BSRR_BS7_Pos)            /*!< 0x00000080 */
#define GPIO_BSRR_BS7                       GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BS8_Pos                   (8U)
#define GPIO_BSRR_BS8_Msk                   (0x1UL << GPIO_BSRR_BS8_Pos)            /*!< 0x00000100 */
#define GPIO_BSRR_BS8                       GPIO_BSRR_BS8_Msk
#define GPIO_BSRR_BS9_Pos                   (9U)
#define GPIO_BSRR_BS9_Msk                   (0x1UL << GPIO_BSRR_BS9_Pos)            /*!< 0x00000200 */
#define GPIO_BSRR_BS9                       GPIO_BSRR_BS9_Msk
#define GPIO_BSRR_BS10_Pos                  (10U)
#define GPIO_BSRR_BS10_Msk                  (0x1UL << GPIO_BSRR_BS10_Pos)           /*!< 0x00000400 */
#define GPIO_BSRR_BS10                      GPIO_BSRR_BS10_Msk
#define GPIO_BSRR_BS11_Pos                  (11U)
#define GPIO_BSRR_BS11_Msk                  (0x1UL << GPIO_BSRR_BS11_Pos)           /*!< 0x00000800 */
#define GPIO_BSRR_BS11                      GPIO_BSRR_BS11_Msk
#define GPIO_BSRR_BS12_Pos                  (12U)
#define GPIO_BSRR_BS12_Msk                  (0x1UL << GPIO_BSRR_BS12_Pos)           /*!< 0x00001000 */
#define GPIO_BSRR_BS12                      GPIO_BSRR_BS12_Msk
#define GPIO_BSRR_BS13_Pos                  (13U)
#define GPIO_BSRR_BS13_Msk                  (0x1UL << GPIO_BSRR_BS13_Pos)           /*!< 0x00002000 */
#define GPIO_BSRR_BS13                      GPIO_BSRR_BS13_Msk
#define GPIO_BSRR_BS14_Pos                  (14U)
#define GPIO_BSRR_BS14_Msk                  (0x1UL << GPIO_BSRR_BS14_Pos)           /*!< 0x00004000 */
#define GPIO_BSRR_BS14                      GPIO_BSRR_BS14_Msk
#define GPIO_BSRR_BS15_Pos                  (15U)
#define GPIO_BSRR_BS15_Msk                  (0x1UL << GPIO_BSRR_BS15_Pos)           /*!< 0x00008000 */
#define GPIO_BSRR_BS15                      GPIO_BSRR_BS15_Msk
#define GPIO_BSRR_BR0_Pos                   (16U)
#define GPIO_BSRR_BR0_Msk                   (0x1UL << GPIO_BSRR_BR0_Pos)            /*!< 0x00010000 */
#define GPIO_BSRR_BR0                       GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos                   (17U)
#define GPIO_BSRR_BR1_Msk                   (0x1UL << GPIO_BSRR_BR1_Pos)            /*!< 0x00020000 */
#define GPIO_BSRR_BR1                       GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos                   (18U)
#define GPIO_BSRR_BR2_Msk                   (0x1UL << GPIO_BSRR_BR2_Pos)            /*!< 0x00040000 */
#define GPIO_BSRR_BR2                       GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos                   (19U)
#define GPIO_BSRR_BR3_Msk                   (0x1UL << GPIO_BSRR_BR3_Pos)            /*!< 0x00080000 */
#define GPIO_BSRR_BR3                       GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos                   (20U)
#define GPIO_BSRR_BR4_Msk                   (0x1UL << GPIO_BSRR_BR4_Pos)            /*!< 0x00100000 */
#define GPIO_BSRR_BR4                       GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos                   (21U)
#define GPIO_BSRR_BR5_Msk                   (0x1UL << GPIO_BSRR_BR5_Pos)            /*!< 0x00200000 */
#define GPIO_BSRR_BR5                       GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos                   (22U)
#define GPIO_BSRR_BR6_Msk                   (0x1UL << GPIO_BSRR_BR6_Pos)            /*!< 0x00400000 */
#define GPIO_BSRR_BR6                       GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos                   (23U)
#define GPIO_BSRR_BR7_Msk                   (0x1UL << GPIO_BSRR_BR7_Pos)            /*!< 0x00800000 */
#define GPIO_BSRR_BR7                       GPIO_BSRR_BR7_Msk
#define GPIO_BSRR_BR8_Pos                   (24U)
#define GPIO_BSRR_BR8_Msk                   (0x1UL << GPIO_BSRR_BR8_Pos)            /*!< 0x01000000 */
#define GPIO_BSRR_BR8                       GPIO_BSRR_BR8_Msk
#define GPIO_BSRR_BR9_Pos                   (25U)
#define GPIO_BSRR_BR9_Msk                   (0x1UL << GPIO_BSRR_BR9_Pos)            /*!< 0x02000000 */
#define GPIO_BSRR_BR9                       GPIO_BSRR_BR9_Msk
#define GPIO_BSRR_BR10_Pos                  (26U)
#define GPIO_BSRR_BR10_Msk                  (0x1UL << GPIO_BSRR_BR10_Pos)           /*!< 0x04000000 */
#define GPIO_BSRR_BR10                      GPIO_BSRR_BR10_Msk
#define GPIO_BSRR_BR11_Pos                  (27U)
#define GPIO_BSRR_BR11_Msk                  (0x1UL << GPIO_BSRR_BR11_Pos)           /*!< 0x08000000 */
#define GPIO_BSRR_BR11                      GPIO_BSRR_BR11_Msk
#define GPIO_BSRR_BR12_Pos                  (28U)
#define GPIO_BSRR_BR12_Msk                  (0x1UL << GPIO_BSRR_BR12_Pos)           /*!< 0x10000000 */
#define GPIO_BSRR_BR12                      GPIO_BSRR_BR12_Msk
#define GPIO_BSRR_BR13_Pos                  (29U)
#define GPIO_BSRR_BR13_Msk                  (0x1UL << GPIO_BSRR_BR13_Pos)           /*!< 0x20000000 */
#define GPIO_BSRR_BR13                      GPIO_BSRR_BR13_Msk
#define GPIO_BSRR_BR14_Pos                  (30U)
#define GPIO_BSRR_BR14_Msk                  (0x1UL << GPIO_BSRR_BR14_Pos)           /*!< 0x40000000 */
#define GPIO_BSRR_BR14                      GPIO_BSRR_BR14_Msk
#define GPIO_BSRR_BR15_Pos                  (31U)
#define GPIO_BSRR_BR15_Msk                  (0x1UL << GPIO_BSRR_BR15_Pos)           /*!< 0x80000000 */
#define GPIO_BSRR_BR15                      GPIO_BSRR_BR15_Msk

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos                  (0U)
#define GPIO_LCKR_LCK0_Msk                  (0x1UL << GPIO_LCKR_LCK0_Pos)           /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                      GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos                  (1U)
#define GPIO_LCKR_LCK1_Msk                  (0x1UL << GPIO_LCKR_LCK1_Pos)           /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                      GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos                  (2U)
#define GPIO_LCKR_LCK2_Msk                  (0x1UL << GPIO_LCKR_LCK2_Pos)           /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                      GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos                  (3U)
#define GPIO_LCKR_LCK3_Msk                  (0x1UL << GPIO_LCKR_LCK3_Pos)           /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                      GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos                  (4U)
#define GPIO_LCKR_LCK4_Msk                  (0x1UL << GPIO_LCKR_LCK4_Pos)           /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                      GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos                  (5U)
#define GPIO_LCKR_LCK5_Msk                  (0x1UL << GPIO_LCKR_LCK5_Pos)           /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                      GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos                  (6U)
#define GPIO_LCKR_LCK6_Msk                  (0x1UL << GPIO_LCKR_LCK6_Pos)           /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                      GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos                  (7U)
#define GPIO_LCKR_LCK7_Msk                  (0x1UL << GPIO_LCKR_LCK7_Pos)           /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                      GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos                  (8U)
#define GPIO_LCKR_LCK8_Msk                  (0x1UL << GPIO_LCKR_LCK8_Pos)           /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                      GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos                  (9U)
#define GPIO_LCKR_LCK9_Msk                  (0x1UL << GPIO_LCKR_LCK9_Pos)           /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                      GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos                 (10U)
#define GPIO_LCKR_LCK10_Msk                 (0x1UL << GPIO_LCKR_LCK10_Pos)          /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                     GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos                 (11U)
#define GPIO_LCKR_LCK11_Msk                 (0x1UL << GPIO_LCKR_LCK11_Pos)          /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                     GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos                 (12U)
#define GPIO_LCKR_LCK12_Msk                 (0x1UL << GPIO_LCKR_LCK12_Pos)          /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                     GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos                 (13U)
#define GPIO_LCKR_LCK13_Msk                 (0x1UL << GPIO_LCKR_LCK13_Pos)          /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                     GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos                 (14U)
#define GPIO_LCKR_LCK14_Msk                 (0x1UL << GPIO_LCKR_LCK14_Pos)          /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                     GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos                 (15U)
#define GPIO_LCKR_LCK15_Msk                 (0x1UL << GPIO_LCKR_LCK15_Pos)          /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                     GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos                  (16U)
#define GPIO_LCKR_LCKK_Msk                  (0x1UL << GPIO_LCKR_LCKK_Pos)           /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                      GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFSEL0_Pos                (0U)
#define GPIO_AFRL_AFSEL0_Msk                (0xFUL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0                    GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL0_0                  (0x1UL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x00000001 */
#define GPIO_AFRL_AFSEL0_1                  (0x2UL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x00000002 */
#define GPIO_AFRL_AFSEL0_2                  (0x4UL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x00000004 */
#define GPIO_AFRL_AFSEL0_3                  (0x8UL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x00000008 */
#define GPIO_AFRL_AFSEL1_Pos                (4U)
#define GPIO_AFRL_AFSEL1_Msk                (0xFUL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1                    GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL1_0                  (0x1UL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x00000010 */
#define GPIO_AFRL_AFSEL1_1                  (0x2UL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x00000020 */
#define GPIO_AFRL_AFSEL1_2                  (0x4UL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x00000040 */
#define GPIO_AFRL_AFSEL1_3                  (0x8UL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x00000080 */
#define GPIO_AFRL_AFSEL2_Pos                (8U)
#define GPIO_AFRL_AFSEL2_Msk                (0xFUL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2                    GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL2_0                  (0x1UL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000100 */
#define GPIO_AFRL_AFSEL2_1                  (0x2UL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000200 */
#define GPIO_AFRL_AFSEL2_2                  (0x4UL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000400 */
#define GPIO_AFRL_AFSEL2_3                  (0x8UL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000800 */
#define GPIO_AFRL_AFSEL3_Pos                (12U)
#define GPIO_AFRL_AFSEL3_Msk                (0xFUL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3                    GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL3_0                  (0x1UL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x00001000 */
#define GPIO_AFRL_AFSEL3_1                  (0x2UL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x00002000 */
#define GPIO_AFRL_AFSEL3_2                  (0x4UL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x00004000 */
#define GPIO_AFRL_AFSEL3_3                  (0x8UL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x00008000 */
#define GPIO_AFRL_AFSEL4_Pos                (16U)
#define GPIO_AFRL_AFSEL4_Msk                (0xFUL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4                    GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL4_0                  (0x1UL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x00010000 */
#define GPIO_AFRL_AFSEL4_1                  (0x2UL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x00020000 */
#define GPIO_AFRL_AFSEL4_2                  (0x4UL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x00040000 */
#define GPIO_AFRL_AFSEL4_3                  (0x8UL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x00080000 */
#define GPIO_AFRL_AFSEL5_Pos                (20U)
#define GPIO_AFRL_AFSEL5_Msk                (0xFUL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5                    GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL5_0                  (0x1UL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00100000 */
#define GPIO_AFRL_AFSEL5_1                  (0x2UL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00200000 */
#define GPIO_AFRL_AFSEL5_2                  (0x4UL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00400000 */
#define GPIO_AFRL_AFSEL5_3                  (0x8UL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00800000 */
#define GPIO_AFRL_AFSEL6_Pos                (24U)
#define GPIO_AFRL_AFSEL6_Msk                (0xFUL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6                    GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL6_0                  (0x1UL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x01000000 */
#define GPIO_AFRL_AFSEL6_1                  (0x2UL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x02000000 */
#define GPIO_AFRL_AFSEL6_2                  (0x4UL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x04000000 */
#define GPIO_AFRL_AFSEL6_3                  (0x8UL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x08000000 */
#define GPIO_AFRL_AFSEL7_Pos                (28U)
#define GPIO_AFRL_AFSEL7_Msk                (0xFUL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7                    GPIO_AFRL_AFSEL7_Msk
#define GPIO_AFRL_AFSEL7_0                  (0x1UL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0x10000000 */
#define GPIO_AFRL_AFSEL7_1                  (0x2UL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0x20000000 */
#define GPIO_AFRL_AFSEL7_2                  (0x4UL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0x40000000 */
#define GPIO_AFRL_AFSEL7_3                  (0x8UL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0x80000000 */

/****************** Bit definition for GPIO_AFRH register *********************/
#define GPIO_AFRH_AFSEL8_Pos                (0U)
#define GPIO_AFRH_AFSEL8_Msk                (0xFUL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x0000000F */
#define GPIO_AFRH_AFSEL8                    GPIO_AFRH_AFSEL8_Msk
#define GPIO_AFRH_AFSEL8_0                  (0x1UL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x00000001 */
#define GPIO_AFRH_AFSEL8_1                  (0x2UL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x00000002 */
#define GPIO_AFRH_AFSEL8_2                  (0x4UL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x00000004 */
#define GPIO_AFRH_AFSEL8_3                  (0x8UL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x00000008 */
#define GPIO_AFRH_AFSEL9_Pos                (4U)
#define GPIO_AFRH_AFSEL9_Msk                (0xFUL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x000000F0 */
#define GPIO_AFRH_AFSEL9                    GPIO_AFRH_AFSEL9_Msk
#define GPIO_AFRH_AFSEL9_0                  (0x1UL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x00000010 */
#define GPIO_AFRH_AFSEL9_1                  (0x2UL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x00000020 */
#define GPIO_AFRH_AFSEL9_2                  (0x4UL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x00000040 */
#define GPIO_AFRH_AFSEL9_3                  (0x8UL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x00000080 */
#define GPIO_AFRH_AFSEL10_Pos               (8U)
#define GPIO_AFRH_AFSEL10_Msk               (0xFUL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000F00 */
#define GPIO_AFRH_AFSEL10                   GPIO_AFRH_AFSEL10_Msk
#define GPIO_AFRH_AFSEL10_0                 (0x1UL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000100 */
#define GPIO_AFRH_AFSEL10_1                 (0x2UL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000200 */
#define GPIO_AFRH_AFSEL10_2                 (0x4UL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000400 */
#define GPIO_AFRH_AFSEL10_3                 (0x8UL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000800 */
#define GPIO_AFRH_AFSEL11_Pos               (12U)
#define GPIO_AFRH_AFSEL11_Msk               (0xFUL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x0000F000 */
#define GPIO_AFRH_AFSEL11                   GPIO_AFRH_AFSEL11_Msk
#define GPIO_AFRH_AFSEL11_0                 (0x1UL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x00001000 */
#define GPIO_AFRH_AFSEL11_1                 (0x2UL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x00002000 */
#define GPIO_AFRH_AFSEL11_2                 (0x4UL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x00004000 */
#define GPIO_AFRH_AFSEL11_3                 (0x8UL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x00008000 */
#define GPIO_AFRH_AFSEL12_Pos               (16U)
#define GPIO_AFRH_AFSEL12_Msk               (0xFUL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x000F0000 */
#define GPIO_AFRH_AFSEL12                   GPIO_AFRH_AFSEL12_Msk
#define GPIO_AFRH_AFSEL12_0                 (0x1UL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x00010000 */
#define GPIO_AFRH_AFSEL12_1                 (0x2UL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x00020000 */
#define GPIO_AFRH_AFSEL12_2                 (0x4UL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x00040000 */
#define GPIO_AFRH_AFSEL12_3                 (0x8UL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x00080000 */
#define GPIO_AFRH_AFSEL13_Pos               (20U)
#define GPIO_AFRH_AFSEL13_Msk               (0xFUL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00F00000 */
#define GPIO_AFRH_AFSEL13                   GPIO_AFRH_AFSEL13_Msk
#define GPIO_AFRH_AFSEL13_0                 (0x1UL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00100000 */
#define GPIO_AFRH_AFSEL13_1                 (0x2UL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00200000 */
#define GPIO_AFRH_AFSEL13_2                 (0x4UL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00400000 */
#define GPIO_AFRH_AFSEL13_3                 (0x8UL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00800000 */
#define GPIO_AFRH_AFSEL14_Pos               (24U)
#define GPIO_AFRH_AFSEL14_Msk               (0xFUL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x0F000000 */
#define GPIO_AFRH_AFSEL14                   GPIO_AFRH_AFSEL14_Msk
#define GPIO_AFRH_AFSEL14_0                 (0x1UL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x01000000 */
#define GPIO_AFRH_AFSEL14_1                 (0x2UL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x02000000 */
#define GPIO_AFRH_AFSEL14_2                 (0x4UL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x04000000 */
#define GPIO_AFRH_AFSEL14_3                 (0x8UL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x08000000 */
#define GPIO_AFRH_AFSEL15_Pos               (28U)
#define GPIO_AFRH_AFSEL15_Msk               (0xFUL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0xF0000000 */
#define GPIO_AFRH_AFSEL15                   GPIO_AFRH_AFSEL15_Msk
#define GPIO_AFRH_AFSEL15_0                 (0x1UL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0x10000000 */
#define GPIO_AFRH_AFSEL15_1                 (0x2UL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0x20000000 */
#define GPIO_AFRH_AFSEL15_2                 (0x4UL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0x40000000 */
#define GPIO_AFRH_AFSEL15_3                 (0x8UL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0x80000000 */

/******************  Bits definition for GPIO_BRR register  ******************/
#define GPIO_BRR_BR0_Pos                    (0U)
#define GPIO_BRR_BR0_Msk                    (0x1UL << GPIO_BRR_BR0_Pos)             /*!< 0x00000001 */
#define GPIO_BRR_BR0                        GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos                    (1U)
#define GPIO_BRR_BR1_Msk                    (0x1UL << GPIO_BRR_BR1_Pos)             /*!< 0x00000002 */
#define GPIO_BRR_BR1                        GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos                    (2U)
#define GPIO_BRR_BR2_Msk                    (0x1UL << GPIO_BRR_BR2_Pos)             /*!< 0x00000004 */
#define GPIO_BRR_BR2                        GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos                    (3U)
#define GPIO_BRR_BR3_Msk                    (0x1UL << GPIO_BRR_BR3_Pos)             /*!< 0x00000008 */
#define GPIO_BRR_BR3                        GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos                    (4U)
#define GPIO_BRR_BR4_Msk                    (0x1UL << GPIO_BRR_BR4_Pos)             /*!< 0x00000010 */
#define GPIO_BRR_BR4                        GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos                    (5U)
#define GPIO_BRR_BR5_Msk                    (0x1UL << GPIO_BRR_BR5_Pos)             /*!< 0x00000020 */
#define GPIO_BRR_BR5                        GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos                    (6U)
#define GPIO_BRR_BR6_Msk                    (0x1UL << GPIO_BRR_BR6_Pos)             /*!< 0x00000040 */
#define GPIO_BRR_BR6                        GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos                    (7U)
#define GPIO_BRR_BR7_Msk                    (0x1UL << GPIO_BRR_BR7_Pos)             /*!< 0x00000080 */
#define GPIO_BRR_BR7                        GPIO_BRR_BR7_Msk
#define GPIO_BRR_BR8_Pos                    (8U)
#define GPIO_BRR_BR8_Msk                    (0x1UL << GPIO_BRR_BR8_Pos)             /*!< 0x00000100 */
#define GPIO_BRR_BR8                        GPIO_BRR_BR8_Msk
#define GPIO_BRR_BR9_Pos                    (9U)
#define GPIO_BRR_BR9_Msk                    (0x1UL << GPIO_BRR_BR9_Pos)             /*!< 0x00000200 */
#define GPIO_BRR_BR9                        GPIO_BRR_BR9_Msk
#define GPIO_BRR_BR10_Pos                   (10U)
#define GPIO_BRR_BR10_Msk                   (0x1UL << GPIO_BRR_BR10_Pos)            /*!< 0x00000400 */
#define GPIO_BRR_BR10                       GPIO_BRR_BR10_Msk
#define GPIO_BRR_BR11_Pos                   (11U)
#define GPIO_BRR_BR11_Msk                   (0x1UL << GPIO_BRR_BR11_Pos)            /*!< 0x00000800 */
#define GPIO_BRR_BR11                       GPIO_BRR_BR11_Msk
#define GPIO_BRR_BR12_Pos                   (12U)
#define GPIO_BRR_BR12_Msk                   (0x1UL << GPIO_BRR_BR12_Pos)            /*!< 0x00001000 */
#define GPIO_BRR_BR12                       GPIO_BRR_BR12_Msk
#define GPIO_BRR_BR13_Pos                   (13U)
#define GPIO_BRR_BR13_Msk                   (0x1UL << GPIO_BRR_BR13_Pos)            /*!< 0x00002000 */
#define GPIO_BRR_BR13                       GPIO_BRR_BR13_Msk
#define GPIO_BRR_BR14_Pos                   (14U)
#define GPIO_BRR_BR14_Msk                   (0x1UL << GPIO_BRR_BR14_Pos)            /*!< 0x00004000 */
#define GPIO_BRR_BR14                       GPIO_BRR_BR14_Msk
#define GPIO_BRR_BR15_Pos                   (15U)
#define GPIO_BRR_BR15_Msk                   (0x1UL << GPIO_BRR_BR15_Pos)            /*!< 0x00008000 */
#define GPIO_BRR_BR15                       GPIO_BRR_BR15_Msk


/******************************************************************************/
/*                                                                            */
/*                                    HASH                                    */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for HASH_CR register  ********************/
#define HASH_CR_INIT_Pos                    (2U)
#define HASH_CR_INIT_Msk                    (0x1UL << HASH_CR_INIT_Pos)             /*!< 0x00000004 */
#define HASH_CR_INIT                        HASH_CR_INIT_Msk
#define HASH_CR_DMAE_Pos                    (3U)
#define HASH_CR_DMAE_Msk                    (0x1UL << HASH_CR_DMAE_Pos)             /*!< 0x00000008 */
#define HASH_CR_DMAE                        HASH_CR_DMAE_Msk
#define HASH_CR_DATATYPE_Pos                (4U)
#define HASH_CR_DATATYPE_Msk                (0x3UL << HASH_CR_DATATYPE_Pos)         /*!< 0x00000030 */
#define HASH_CR_DATATYPE                    HASH_CR_DATATYPE_Msk
#define HASH_CR_DATATYPE_0                  (0x1UL << HASH_CR_DATATYPE_Pos)         /*!< 0x00000010 */
#define HASH_CR_DATATYPE_1                  (0x2UL << HASH_CR_DATATYPE_Pos)         /*!< 0x00000020 */
#define HASH_CR_MODE_Pos                    (6U)
#define HASH_CR_MODE_Msk                    (0x1UL << HASH_CR_MODE_Pos)             /*!< 0x00000040 */
#define HASH_CR_MODE                        HASH_CR_MODE_Msk
#define HASH_CR_NBW_Pos                     (8U)
#define HASH_CR_NBW_Msk                     (0xFUL << HASH_CR_NBW_Pos)              /*!< 0x00000F00 */
#define HASH_CR_NBW                         HASH_CR_NBW_Msk
#define HASH_CR_NBW_0                       (0x1UL << HASH_CR_NBW_Pos)              /*!< 0x00000100 */
#define HASH_CR_NBW_1                       (0x2UL << HASH_CR_NBW_Pos)              /*!< 0x00000200 */
#define HASH_CR_NBW_2                       (0x4UL << HASH_CR_NBW_Pos)              /*!< 0x00000400 */
#define HASH_CR_NBW_3                       (0x8UL << HASH_CR_NBW_Pos)              /*!< 0x00000800 */
#define HASH_CR_DINNE_Pos                   (12U)
#define HASH_CR_DINNE_Msk                   (0x1UL << HASH_CR_DINNE_Pos)            /*!< 0x00001000 */
#define HASH_CR_DINNE                       HASH_CR_DINNE_Msk
#define HASH_CR_MDMAT_Pos                   (13U)
#define HASH_CR_MDMAT_Msk                   (0x1UL << HASH_CR_MDMAT_Pos)            /*!< 0x00002000 */
#define HASH_CR_MDMAT                       HASH_CR_MDMAT_Msk
#define HASH_CR_LKEY_Pos                    (16U)
#define HASH_CR_LKEY_Msk                    (0x1UL << HASH_CR_LKEY_Pos)             /*!< 0x00010000 */
#define HASH_CR_LKEY                        HASH_CR_LKEY_Msk
#define HASH_CR_ALGO_Pos                    (17U)
#define HASH_CR_ALGO_Msk                    (0x3UL << HASH_CR_ALGO_Pos)             /*!< 0x00040080 */
#define HASH_CR_ALGO                        HASH_CR_ALGO_Msk
#define HASH_CR_ALGO_0                      (0x1UL << HASH_CR_ALGO_Pos)             /*!< 0x00000080 */
#define HASH_CR_ALGO_1                      (0x2UL << HASH_CR_ALGO_Pos)             /*!< 0x00040000 */

/******************  Bits definition for HASH_STR register  *******************/
#define HASH_STR_NBLW_Pos                   (0U)
#define HASH_STR_NBLW_Msk                   (0x1FUL << HASH_STR_NBLW_Pos)           /*!< 0x0000001F */
#define HASH_STR_NBLW                       HASH_STR_NBLW_Msk
#define HASH_STR_NBLW_0                     (0x01UL << HASH_STR_NBLW_Pos)           /*!< 0x00000001 */
#define HASH_STR_NBLW_1                     (0x02UL << HASH_STR_NBLW_Pos)           /*!< 0x00000002 */
#define HASH_STR_NBLW_2                     (0x04UL << HASH_STR_NBLW_Pos)           /*!< 0x00000004 */
#define HASH_STR_NBLW_3                     (0x08UL << HASH_STR_NBLW_Pos)           /*!< 0x00000008 */
#define HASH_STR_NBLW_4                     (0x10UL << HASH_STR_NBLW_Pos)           /*!< 0x00000010 */
#define HASH_STR_DCAL_Pos                   (8U)
#define HASH_STR_DCAL_Msk                   (0x1UL << HASH_STR_DCAL_Pos)            /*!< 0x00000100 */
#define HASH_STR_DCAL                       HASH_STR_DCAL_Msk

/******************  Bits definition for HASH_IMR register  *******************/
#define HASH_IMR_DINIE_Pos                  (0U)
#define HASH_IMR_DINIE_Msk                  (0x1UL << HASH_IMR_DINIE_Pos)           /*!< 0x00000001 */
#define HASH_IMR_DINIE                      HASH_IMR_DINIE_Msk
#define HASH_IMR_DCIE_Pos                   (1U)
#define HASH_IMR_DCIE_Msk                   (0x1UL << HASH_IMR_DCIE_Pos)            /*!< 0x00000002 */
#define HASH_IMR_DCIE                       HASH_IMR_DCIE_Msk

/******************  Bits definition for HASH_SR register  ********************/
#define HASH_SR_DINIS_Pos                   (0U)
#define HASH_SR_DINIS_Msk                   (0x1UL << HASH_SR_DINIS_Pos)            /*!< 0x00000001 */
#define HASH_SR_DINIS                       HASH_SR_DINIS_Msk
#define HASH_SR_DCIS_Pos                    (1U)
#define HASH_SR_DCIS_Msk                    (0x1UL << HASH_SR_DCIS_Pos)             /*!< 0x00000002 */
#define HASH_SR_DCIS                        HASH_SR_DCIS_Msk
#define HASH_SR_DMAS_Pos                    (2U)
#define HASH_SR_DMAS_Msk                    (0x1UL << HASH_SR_DMAS_Pos)             /*!< 0x00000004 */
#define HASH_SR_DMAS                        HASH_SR_DMAS_Msk
#define HASH_SR_BUSY_Pos                    (3U)
#define HASH_SR_BUSY_Msk                    (0x1UL << HASH_SR_BUSY_Pos)             /*!< 0x00000008 */
#define HASH_SR_BUSY                        HASH_SR_BUSY_Msk
#define HASH_SR_NBWE_Pos                    (16U)
#define HASH_SR_NBWE_Msk                    (0xFUL << HASH_SR_NBWE_Pos)             /*!< 0x000F0000 */
#define HASH_SR_NBWE                        HASH_SR_NBWE_Msk
#define HASH_SR_NBWE_0                      (0x01UL << HASH_SR_NBWE_Pos)            /*!< 0x00010000 */
#define HASH_SR_NBWE_1                      (0x02UL << HASH_SR_NBWE_Pos)            /*!< 0x00020000 */
#define HASH_SR_NBWE_2                      (0x04UL << HASH_SR_NBWE_Pos)            /*!< 0x00040000 */
#define HASH_SR_NBWE_3                      (0x08UL << HASH_SR_NBWE_Pos)            /*!< 0x00080000 */
#define HASH_SR_DINNE_Pos                   (15U)
#define HASH_SR_DINNE_Msk                   (0x1UL << HASH_SR_DINNE_Pos)            /*!< 0x00008000 */
#define HASH_SR_DINNE                       HASH_SR_DINNE_Msk
#define HASH_SR_NBWP_Pos                    (9U)
#define HASH_SR_NBWP_Msk                    (0xFUL << HASH_SR_NBWP_Pos)             /*!< 0x000F0000 */
#define HASH_SR_NBWP                        HASH_SR_NBWP_Msk
#define HASH_SR_NBWP_0                      (0x01UL << HASH_SR_NBWP_Pos)            /*!< 0x000O0200 */
#define HASH_SR_NBWP_1                      (0x02UL << HASH_SR_NBWP_Pos)            /*!< 0x00000400 */
#define HASH_SR_NBWP_2                      (0x04UL << HASH_SR_NBWP_Pos)            /*!< 0x00000800 */
#define HASH_SR_NBWP_3                      (0x08UL << HASH_SR_NBWP_Pos)            /*!< 0x00001000 */


/******************************************************************************/
/*                                                                            */
/*                        HSEM HW Semaphore                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for HSEM_R register  ********************/
#define HSEM_R_PROCID_Pos        (0U)
#define HSEM_R_PROCID_Msk        (0xFFUL << HSEM_R_PROCID_Pos)                 /*!< 0x000000FF */
#define HSEM_R_PROCID            HSEM_R_PROCID_Msk                             /*!<Semaphore ProcessID */
#define HSEM_R_LOCKID_Pos        (8U)
#define HSEM_R_LOCKID_Msk        (0xFUL << HSEM_R_LOCKID_Pos)                  /*!< 0x00000F00 */
#define HSEM_R_LOCKID            HSEM_R_LOCKID_Msk                             /*!<Semaphore LockID. */
#define HSEM_R_LOCK_Pos          (31U)
#define HSEM_R_LOCK_Msk          (0x1UL << HSEM_R_LOCK_Pos)                    /*!< 0x80000000 */
#define HSEM_R_LOCK              HSEM_R_LOCK_Msk                               /*!<Lock indication. */

/********************  Bit definition for HSEM_RLR register  ******************/
#define HSEM_RLR_PROCID_Pos      (0U)
#define HSEM_RLR_PROCID_Msk      (0xFFUL << HSEM_RLR_PROCID_Pos)               /*!< 0x000000FF */
#define HSEM_RLR_PROCID          HSEM_RLR_PROCID_Msk                           /*!<Semaphore ProcessID */
#define HSEM_RLR_LOCKID_Pos      (8U)
#define HSEM_RLR_LOCKID_Msk      (0xFUL << HSEM_RLR_COREID_Pos)                /*!< 0x00000F00 */
#define HSEM_RLR_LOCKID          HSEM_RLR_COREID_Msk                           /*!<Semaphore CoreID. */
#define HSEM_RLR_LOCK_Pos        (31U)
#define HSEM_RLR_LOCK_Msk        (0x1UL << HSEM_RLR_LOCK_Pos)                  /*!< 0x80000000 */
#define HSEM_RLR_LOCK            HSEM_RLR_LOCK_Msk                             /*!<Lock indication. */

/********************  Bit definition for HSEM_IER register  ****************/
#define HSEM_IER_ISE0_Pos      (0U)
#define HSEM_IER_ISE0_Msk      (0x1UL << HSEM_IER_ISE0_Pos)                /*!< 0x00000001 */
#define HSEM_IER_ISE0          HSEM_IER_ISE0_Msk                           /*!<semaphore 0 interrupt enable bit.  */
#define HSEM_IER_ISE1_Pos      (1U)
#define HSEM_IER_ISE1_Msk      (0x1UL << HSEM_IER_ISE1_Pos)                /*!< 0x00000002 */
#define HSEM_IER_ISE1          HSEM_IER_ISE1_Msk                           /*!<semaphore 1 interrupt enable bit.  */
#define HSEM_IER_ISE2_Pos      (2U)
#define HSEM_IER_ISE2_Msk      (0x1UL << HSEM_IER_ISE2_Pos)                /*!< 0x00000004 */
#define HSEM_IER_ISE2          HSEM_IER_ISE2_Msk                           /*!<semaphore 2 interrupt enable bit.  */
#define HSEM_IER_ISE3_Pos      (3U)
#define HSEM_IER_ISE3_Msk      (0x1UL << HSEM_IER_ISE3_Pos)                /*!< 0x00000008 */
#define HSEM_IER_ISE3          HSEM_IER_ISE3_Msk                           /*!<semaphore 3 interrupt enable bit.  */
#define HSEM_IER_ISE4_Pos      (4U)
#define HSEM_IER_ISE4_Msk      (0x1UL << HSEM_IER_ISE4_Pos)                /*!< 0x00000010 */
#define HSEM_IER_ISE4          HSEM_IER_ISE4_Msk                           /*!<semaphore 4 interrupt enable bit.  */
#define HSEM_IER_ISE5_Pos      (5U)
#define HSEM_IER_ISE5_Msk      (0x1UL << HSEM_IER_ISE5_Pos)                /*!< 0x00000020 */
#define HSEM_IER_ISE5          HSEM_IER_ISE5_Msk                           /*!<semaphore 5 interrupt enable bit.  */
#define HSEM_IER_ISE6_Pos      (6U)
#define HSEM_IER_ISE6_Msk      (0x1UL << HSEM_IER_ISE6_Pos)                /*!< 0x00000040 */
#define HSEM_IER_ISE6          HSEM_IER_ISE6_Msk                           /*!<semaphore 6 interrupt enable bit.  */
#define HSEM_IER_ISE7_Pos      (7U)
#define HSEM_IER_ISE7_Msk      (0x1UL << HSEM_IER_ISE7_Pos)                /*!< 0x00000080 */
#define HSEM_IER_ISE7          HSEM_IER_ISE7_Msk                           /*!<semaphore 7 interrupt enable bit.  */
#define HSEM_IER_ISE8_Pos      (8U)
#define HSEM_IER_ISE8_Msk      (0x1UL << HSEM_IER_ISE8_Pos)                /*!< 0x00000100 */
#define HSEM_IER_ISE8          HSEM_IER_ISE8_Msk                           /*!<semaphore 8 interrupt enable bit.  */
#define HSEM_IER_ISE9_Pos      (9U)
#define HSEM_IER_ISE9_Msk      (0x1UL << HSEM_IER_ISE9_Pos)                /*!< 0x00000200 */
#define HSEM_IER_ISE9          HSEM_IER_ISE9_Msk                           /*!<semaphore 9 interrupt enable bit.  */
#define HSEM_IER_ISE10_Pos     (10U)
#define HSEM_IER_ISE10_Msk     (0x1UL << HSEM_IER_ISE10_Pos)               /*!< 0x00000400 */
#define HSEM_IER_ISE10         HSEM_IER_ISE10_Msk                          /*!<semaphore 10 interrupt enable bit. */
#define HSEM_IER_ISE11_Pos     (11U)
#define HSEM_IER_ISE11_Msk     (0x1UL << HSEM_IER_ISE11_Pos)               /*!< 0x00000800 */
#define HSEM_IER_ISE11         HSEM_IER_ISE11_Msk                          /*!<semaphore 11 interrupt enable bit. */
#define HSEM_IER_ISE12_Pos     (12U)
#define HSEM_IER_ISE12_Msk     (0x1UL << HSEM_IER_ISE12_Pos)               /*!< 0x00001000 */
#define HSEM_IER_ISE12         HSEM_IER_ISE12_Msk                          /*!<semaphore 12 interrupt enable bit. */
#define HSEM_IER_ISE13_Pos     (13U)
#define HSEM_IER_ISE13_Msk     (0x1UL << HSEM_IER_ISE13_Pos)               /*!< 0x00002000 */
#define HSEM_IER_ISE13         HSEM_IER_ISE13_Msk                          /*!<semaphore 13 interrupt enable bit. */
#define HSEM_IER_ISE14_Pos     (14U)
#define HSEM_IER_ISE14_Msk     (0x1UL << HSEM_IER_ISE14_Pos)               /*!< 0x00004000 */
#define HSEM_IER_ISE14         HSEM_IER_ISE14_Msk                          /*!<semaphore 14 interrupt enable bit. */
#define HSEM_IER_ISE15_Pos     (15U)
#define HSEM_IER_ISE15_Msk     (0x1UL << HSEM_IER_ISE15_Pos)               /*!< 0x00008000 */
#define HSEM_IER_ISE15         HSEM_IER_ISE15_Msk                          /*!<semaphore 15 interrupt enable bit. */

/********************  Bit definition for HSEM_ICR register  *****************/
#define HSEM_ICR_ISC0_Pos      (0U)
#define HSEM_ICR_ISC0_Msk      (0x1UL << HSEM_ICR_ISC0_Pos)                /*!< 0x00000001 */
#define HSEM_ICR_ISC0          HSEM_ICR_ISC0_Msk                           /*!<semaphore 0 interrupt clear bit.  */
#define HSEM_ICR_ISC1_Pos      (1U)
#define HSEM_ICR_ISC1_Msk      (0x1UL << HSEM_ICR_ISC1_Pos)                /*!< 0x00000002 */
#define HSEM_ICR_ISC1          HSEM_ICR_ISC1_Msk                           /*!<semaphore 1 interrupt clear bit.  */
#define HSEM_ICR_ISC2_Pos      (2U)
#define HSEM_ICR_ISC2_Msk      (0x1UL << HSEM_ICR_ISC2_Pos)                /*!< 0x00000004 */
#define HSEM_ICR_ISC2          HSEM_ICR_ISC2_Msk                           /*!<semaphore 2 interrupt clear bit.  */
#define HSEM_ICR_ISC3_Pos      (3U)
#define HSEM_ICR_ISC3_Msk      (0x1UL << HSEM_ICR_ISC3_Pos)                /*!< 0x00000008 */
#define HSEM_ICR_ISC3          HSEM_ICR_ISC3_Msk                           /*!<semaphore 3 interrupt clear bit.  */
#define HSEM_ICR_ISC4_Pos      (4U)
#define HSEM_ICR_ISC4_Msk      (0x1UL << HSEM_ICR_ISC4_Pos)                /*!< 0x00000010 */
#define HSEM_ICR_ISC4          HSEM_ICR_ISC4_Msk                           /*!<semaphore 4 interrupt clear bit.  */
#define HSEM_ICR_ISC5_Pos      (5U)
#define HSEM_ICR_ISC5_Msk      (0x1UL << HSEM_ICR_ISC5_Pos)                /*!< 0x00000020 */
#define HSEM_ICR_ISC5          HSEM_ICR_ISC5_Msk                           /*!<semaphore 5 interrupt clear bit.  */
#define HSEM_ICR_ISC6_Pos      (6U)
#define HSEM_ICR_ISC6_Msk      (0x1UL << HSEM_ICR_ISC6_Pos)                /*!< 0x00000040 */
#define HSEM_ICR_ISC6          HSEM_ICR_ISC6_Msk                           /*!<semaphore 6 interrupt clear bit.  */
#define HSEM_ICR_ISC7_Pos      (7U)
#define HSEM_ICR_ISC7_Msk      (0x1UL << HSEM_ICR_ISC7_Pos)                /*!< 0x00000080 */
#define HSEM_ICR_ISC7          HSEM_ICR_ISC7_Msk                           /*!<semaphore 7 interrupt clear bit.  */
#define HSEM_ICR_ISC8_Pos      (8U)
#define HSEM_ICR_ISC8_Msk      (0x1UL << HSEM_ICR_ISC8_Pos)                /*!< 0x00000100 */
#define HSEM_ICR_ISC8          HSEM_ICR_ISC8_Msk                           /*!<semaphore 8 interrupt clear bit.  */
#define HSEM_ICR_ISC9_Pos      (9U)
#define HSEM_ICR_ISC9_Msk      (0x1UL << HSEM_ICR_ISC9_Pos)                /*!< 0x00000200 */
#define HSEM_ICR_ISC9          HSEM_ICR_ISC9_Msk                           /*!<semaphore 9 interrupt clear bit.  */
#define HSEM_ICR_ISC10_Pos     (10U)
#define HSEM_ICR_ISC10_Msk     (0x1UL << HSEM_ICR_ISC10_Pos)               /*!< 0x00000400 */
#define HSEM_ICR_ISC10         HSEM_ICR_ISC10_Msk                          /*!<semaphore 10 interrupt clear bit. */
#define HSEM_ICR_ISC11_Pos     (11U)
#define HSEM_ICR_ISC11_Msk     (0x1UL << HSEM_ICR_ISC11_Pos)               /*!< 0x00000800 */
#define HSEM_ICR_ISC11         HSEM_ICR_ISC11_Msk                          /*!<semaphore 11 interrupt clear bit. */
#define HSEM_ICR_ISC12_Pos     (12U)
#define HSEM_ICR_ISC12_Msk     (0x1UL << HSEM_ICR_ISC12_Pos)               /*!< 0x00001000 */
#define HSEM_ICR_ISC12         HSEM_ICR_ISC12_Msk                          /*!<semaphore 12 interrupt clear bit. */
#define HSEM_ICR_ISC13_Pos     (13U)
#define HSEM_ICR_ISC13_Msk     (0x1UL << HSEM_ICR_ISC13_Pos)               /*!< 0x00002000 */
#define HSEM_ICR_ISC13         HSEM_ICR_ISC13_Msk                          /*!<semaphore 13 interrupt clear bit. */
#define HSEM_ICR_ISC14_Pos     (14U)
#define HSEM_ICR_ISC14_Msk     (0x1UL << HSEM_ICR_ISC14_Pos)               /*!< 0x00004000 */
#define HSEM_ICR_ISC14         HSEM_ICR_ISC14_Msk                          /*!<semaphore 14 interrupt clear bit. */
#define HSEM_ICR_ISC15_Pos     (15U)
#define HSEM_ICR_ISC15_Msk     (0x1UL << HSEM_ICR_ISC15_Pos)               /*!< 0x00008000 */
#define HSEM_ICR_ISC15         HSEM_ICR_ISC15_Msk                          /*!<semaphore 15 interrupt clear bit. */

/********************  Bit definition for HSEM_ISR register  *****************/
#define HSEM_ISR_ISF0_Pos      (0U)
#define HSEM_ISR_ISF0_Msk      (0x1UL << HSEM_ISR_ISF0_Pos)                /*!< 0x00000001 */
#define HSEM_ISR_ISF0          HSEM_ISR_ISF0_Msk                           /*!<semaphore 0 interrupt status bit.  */
#define HSEM_ISR_ISF1_Pos      (1U)
#define HSEM_ISR_ISF1_Msk      (0x1UL << HSEM_ISR_ISF1_Pos)                /*!< 0x00000002 */
#define HSEM_ISR_ISF1          HSEM_ISR_ISF1_Msk                           /*!<semaphore 1 interrupt status bit.  */
#define HSEM_ISR_ISF2_Pos      (2U)
#define HSEM_ISR_ISF2_Msk      (0x1UL << HSEM_ISR_ISF2_Pos)                /*!< 0x00000004 */
#define HSEM_ISR_ISF2          HSEM_ISR_ISF2_Msk                           /*!<semaphore 2 interrupt status bit.  */
#define HSEM_ISR_ISF3_Pos      (3U)
#define HSEM_ISR_ISF3_Msk      (0x1UL << HSEM_ISR_ISF3_Pos)                /*!< 0x00000008 */
#define HSEM_ISR_ISF3          HSEM_ISR_ISF3_Msk                           /*!<semaphore 3 interrupt status bit.  */
#define HSEM_ISR_ISF4_Pos      (4U)
#define HSEM_ISR_ISF4_Msk      (0x1UL << HSEM_ISR_ISF4_Pos)                /*!< 0x00000010 */
#define HSEM_ISR_ISF4          HSEM_ISR_ISF4_Msk                           /*!<semaphore 4 interrupt status bit.  */
#define HSEM_ISR_ISF5_Pos      (5U)
#define HSEM_ISR_ISF5_Msk      (0x1UL << HSEM_ISR_ISF5_Pos)                /*!< 0x00000020 */
#define HSEM_ISR_ISF5          HSEM_ISR_ISF5_Msk                           /*!<semaphore 5 interrupt status bit.  */
#define HSEM_ISR_ISF6_Pos      (6U)
#define HSEM_ISR_ISF6_Msk      (0x1UL << HSEM_ISR_ISF6_Pos)                /*!< 0x00000040 */
#define HSEM_ISR_ISF6          HSEM_ISR_ISF6_Msk                           /*!<semaphore 6 interrupt status bit.  */
#define HSEM_ISR_ISF7_Pos      (7U)
#define HSEM_ISR_ISF7_Msk      (0x1UL << HSEM_ISR_ISF7_Pos)                /*!< 0x00000080 */
#define HSEM_ISR_ISF7          HSEM_ISR_ISF7_Msk                           /*!<semaphore 7 interrupt status bit.  */
#define HSEM_ISR_ISF8_Pos      (8U)
#define HSEM_ISR_ISF8_Msk      (0x1UL << HSEM_ISR_ISF8_Pos)                /*!< 0x00000100 */
#define HSEM_ISR_ISF8          HSEM_ISR_ISF8_Msk                           /*!<semaphore 8 interrupt status bit.  */
#define HSEM_ISR_ISF9_Pos      (9U)
#define HSEM_ISR_ISF9_Msk      (0x1UL << HSEM_ISR_ISF9_Pos)                /*!< 0x00000200 */
#define HSEM_ISR_ISF9          HSEM_ISR_ISF9_Msk                           /*!<semaphore 9 interrupt status bit.  */
#define HSEM_ISR_ISF10_Pos     (10U)
#define HSEM_ISR_ISF10_Msk     (0x1UL << HSEM_ISR_ISF10_Pos)               /*!< 0x00000400 */
#define HSEM_ISR_ISF10         HSEM_ISR_ISF10_Msk                          /*!<semaphore 10 interrupt status bit. */
#define HSEM_ISR_ISF11_Pos     (11U)
#define HSEM_ISR_ISF11_Msk     (0x1UL << HSEM_ISR_ISF11_Pos)               /*!< 0x00000800 */
#define HSEM_ISR_ISF11         HSEM_ISR_ISF11_Msk                          /*!<semaphore 11 interrupt status bit. */
#define HSEM_ISR_ISF12_Pos     (12U)
#define HSEM_ISR_ISF12_Msk     (0x1UL << HSEM_ISR_ISF12_Pos)               /*!< 0x00001000 */
#define HSEM_ISR_ISF12         HSEM_ISR_ISF12_Msk                          /*!<semaphore 12 interrupt status bit. */
#define HSEM_ISR_ISF13_Pos     (13U)
#define HSEM_ISR_ISF13_Msk     (0x1UL << HSEM_ISR_ISF13_Pos)               /*!< 0x00002000 */
#define HSEM_ISR_ISF13         HSEM_ISR_ISF13_Msk                          /*!<semaphore 13 interrupt status bit. */
#define HSEM_ISR_ISF14_Pos     (14U)
#define HSEM_ISR_ISF14_Msk     (0x1UL << HSEM_ISR_ISF14_Pos)               /*!< 0x00004000 */
#define HSEM_ISR_ISF14         HSEM_ISR_ISF14_Msk                          /*!<semaphore 14 interrupt status bit. */
#define HSEM_ISR_ISF15_Pos     (15U)
#define HSEM_ISR_ISF15_Msk     (0x1UL << HSEM_ISR_ISF15_Pos)               /*!< 0x00008000 */
#define HSEM_ISR_ISF15         HSEM_ISR_ISF15_Msk                          /*!<semaphore 15 interrupt status bit. */

/********************  Bit definition for HSEM_MISR register  *****************/
#define HSEM_MISR_MISF0_Pos     (0U)
#define HSEM_MISR_MISF0_Msk     (0x1UL << HSEM_MISR_MISF0_Pos)               /*!< 0x00000001 */
#define HSEM_MISR_MISF0         HSEM_MISR_MISF0_Msk                          /*!<semaphore 0 interrupt masked status bit.  */
#define HSEM_MISR_MISF1_Pos     (1U)
#define HSEM_MISR_MISF1_Msk     (0x1UL << HSEM_MISR_MISF1_Pos)               /*!< 0x00000002 */
#define HSEM_MISR_MISF1         HSEM_MISR_MISF1_Msk                          /*!<semaphore 1 interrupt masked status bit.  */
#define HSEM_MISR_MISF2_Pos     (2U)
#define HSEM_MISR_MISF2_Msk     (0x1UL << HSEM_MISR_MISF2_Pos)               /*!< 0x00000004 */
#define HSEM_MISR_MISF2         HSEM_MISR_MISF2_Msk                          /*!<semaphore 2 interrupt masked status bit.  */
#define HSEM_MISR_MISF3_Pos     (3U)
#define HSEM_MISR_MISF3_Msk     (0x1UL << HSEM_MISR_MISF3_Pos)               /*!< 0x00000008 */
#define HSEM_MISR_MISF3         HSEM_MISR_MISF3_Msk                          /*!<semaphore 3 interrupt masked status bit.  */
#define HSEM_MISR_MISF4_Pos     (4U)
#define HSEM_MISR_MISF4_Msk     (0x1UL << HSEM_MISR_MISF4_Pos)               /*!< 0x00000010 */
#define HSEM_MISR_MISF4         HSEM_MISR_MISF4_Msk                          /*!<semaphore 4 interrupt masked status bit.  */
#define HSEM_MISR_MISF5_Pos     (5U)
#define HSEM_MISR_MISF5_Msk     (0x1UL << HSEM_MISR_MISF5_Pos)               /*!< 0x00000020 */
#define HSEM_MISR_MISF5         HSEM_MISR_MISF5_Msk                          /*!<semaphore 5 interrupt masked status bit.  */
#define HSEM_MISR_MISF6_Pos     (6U)
#define HSEM_MISR_MISF6_Msk     (0x1UL << HSEM_MISR_MISF6_Pos)               /*!< 0x00000040 */
#define HSEM_MISR_MISF6         HSEM_MISR_MISF6_Msk                          /*!<semaphore 6 interrupt masked status bit.  */
#define HSEM_MISR_MISF7_Pos     (7U)
#define HSEM_MISR_MISF7_Msk     (0x1UL << HSEM_MISR_MISF7_Pos)               /*!< 0x00000080 */
#define HSEM_MISR_MISF7         HSEM_MISR_MISF7_Msk                          /*!<semaphore 7 interrupt masked status bit.  */
#define HSEM_MISR_MISF8_Pos     (8U)
#define HSEM_MISR_MISF8_Msk     (0x1UL << HSEM_MISR_MISF8_Pos)               /*!< 0x00000100 */
#define HSEM_MISR_MISF8         HSEM_MISR_MISF8_Msk                          /*!<semaphore 8 interrupt masked status bit.  */
#define HSEM_MISR_MISF9_Pos     (9U)
#define HSEM_MISR_MISF9_Msk     (0x1UL << HSEM_MISR_MISF9_Pos)               /*!< 0x00000200 */
#define HSEM_MISR_MISF9         HSEM_MISR_MISF9_Msk                          /*!<semaphore 9 interrupt masked status bit.  */
#define HSEM_MISR_MISF10_Pos    (10U)
#define HSEM_MISR_MISF10_Msk    (0x1UL << HSEM_MISR_MISF10_Pos)              /*!< 0x00000400 */
#define HSEM_MISR_MISF10        HSEM_MISR_MISF10_Msk                         /*!<semaphore 10 interrupt masked status bit. */
#define HSEM_MISR_MISF11_Pos    (11U)
#define HSEM_MISR_MISF11_Msk    (0x1UL << HSEM_MISR_MISF11_Pos)              /*!< 0x00000800 */
#define HSEM_MISR_MISF11        HSEM_MISR_MISF11_Msk                         /*!<semaphore 11 interrupt masked status bit. */
#define HSEM_MISR_MISF12_Pos    (12U)
#define HSEM_MISR_MISF12_Msk    (0x1UL << HSEM_MISR_MISF12_Pos)              /*!< 0x00001000 */
#define HSEM_MISR_MISF12        HSEM_MISR_MISF12_Msk                         /*!<semaphore 12 interrupt masked status bit. */
#define HSEM_MISR_MISF13_Pos    (13U)
#define HSEM_MISR_MISF13_Msk    (0x1UL << HSEM_MISR_MISF13_Pos)              /*!< 0x00002000 */
#define HSEM_MISR_MISF13        HSEM_MISR_MISF13_Msk                         /*!<semaphore 13 interrupt masked status bit. */
#define HSEM_MISR_MISF14_Pos    (14U)
#define HSEM_MISR_MISF14_Msk    (0x1UL << HSEM_MISR_MISF14_Pos)              /*!< 0x00004000 */
#define HSEM_MISR_MISF14        HSEM_MISR_MISF14_Msk                         /*!<semaphore 14 interrupt masked status bit. */
#define HSEM_MISR_MISF15_Pos    (15U)
#define HSEM_MISR_MISF15_Msk    (0x1UL << HSEM_MISR_MISF15_Pos)              /*!< 0x00008000 */
#define HSEM_MISR_MISF15        HSEM_MISR_MISF15_Msk                         /*!<semaphore 15 interrupt masked status bit. */

/********************  Bit definition for HSEM_CR register  *****************/
#define HSEM_CR_LOCKID_Pos       (8U)
#define HSEM_CR_LOCKID_Msk       (0xFUL << HSEM_CR_LOCKID_Pos)                 /*!< 0x00000F00 */
#define HSEM_CR_LOCKID           HSEM_CR_LOCKID_Msk                            /*!<LOCKID of semaphores to be cleared. */
#define HSEM_CR_LOCKID_CPU1      (0x2U << HSEM_CR_LOCKID_Pos)
#define HSEM_CR_LOCKID_CURRENT   HSEM_CR_LOCKID_CPU1
#define HSEM_CR_KEY_Pos          (16U)
#define HSEM_CR_KEY_Msk          (0xFFFFUL << HSEM_CR_KEY_Pos)                 /*!< 0xFFFF0000 */
#define HSEM_CR_KEY              HSEM_CR_KEY_Msk                               /*!<semaphores clear key. */

/********************  Bit definition for HSEM_KEYR register  *****************/
#define HSEM_KEYR_KEY_Pos        (16U)
#define HSEM_KEYR_KEY_Msk        (0xFFFFUL << HSEM_KEYR_KEY_Pos)               /*!< 0xFFFF0000 */
#define HSEM_KEYR_KEY            HSEM_KEYR_KEY_Msk                             /*!<semaphores clear key. */


/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface (I2C)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)               /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                          /*!< Peripheral enable */
#define I2C_CR1_TXIE_Pos                    (1U)
#define I2C_CR1_TXIE_Msk                    (0x1UL << I2C_CR1_TXIE_Pos)             /*!< 0x00000002 */
#define I2C_CR1_TXIE                        I2C_CR1_TXIE_Msk                        /*!< TX interrupt enable */
#define I2C_CR1_RXIE_Pos                    (2U)
#define I2C_CR1_RXIE_Msk                    (0x1UL << I2C_CR1_RXIE_Pos)             /*!< 0x00000004 */
#define I2C_CR1_RXIE                        I2C_CR1_RXIE_Msk                        /*!< RX interrupt enable */
#define I2C_CR1_ADDRIE_Pos                  (3U)
#define I2C_CR1_ADDRIE_Msk                  (0x1UL << I2C_CR1_ADDRIE_Pos)           /*!< 0x00000008 */
#define I2C_CR1_ADDRIE                      I2C_CR1_ADDRIE_Msk                      /*!< Address match interrupt enable */
#define I2C_CR1_NACKIE_Pos                  (4U)
#define I2C_CR1_NACKIE_Msk                  (0x1UL << I2C_CR1_NACKIE_Pos)           /*!< 0x00000010 */
#define I2C_CR1_NACKIE                      I2C_CR1_NACKIE_Msk                      /*!< NACK received interrupt enable */
#define I2C_CR1_STOPIE_Pos                  (5U)
#define I2C_CR1_STOPIE_Msk                  (0x1UL << I2C_CR1_STOPIE_Pos)           /*!< 0x00000020 */
#define I2C_CR1_STOPIE                      I2C_CR1_STOPIE_Msk                      /*!< STOP detection interrupt enable */
#define I2C_CR1_TCIE_Pos                    (6U)
#define I2C_CR1_TCIE_Msk                    (0x1UL << I2C_CR1_TCIE_Pos)             /*!< 0x00000040 */
#define I2C_CR1_TCIE                        I2C_CR1_TCIE_Msk                        /*!< Transfer complete interrupt enable */
#define I2C_CR1_ERRIE_Pos                   (7U)
#define I2C_CR1_ERRIE_Msk                   (0x1UL << I2C_CR1_ERRIE_Pos)            /*!< 0x00000080 */
#define I2C_CR1_ERRIE                       I2C_CR1_ERRIE_Msk                       /*!< Errors interrupt enable */
#define I2C_CR1_DNF_Pos                     (8U)
#define I2C_CR1_DNF_Msk                     (0xFUL << I2C_CR1_DNF_Pos)              /*!< 0x00000F00 */
#define I2C_CR1_DNF                         I2C_CR1_DNF_Msk                         /*!< Digital noise filter */
#define I2C_CR1_ANFOFF_Pos                  (12U)
#define I2C_CR1_ANFOFF_Msk                  (0x1UL << I2C_CR1_ANFOFF_Pos)           /*!< 0x00001000 */
#define I2C_CR1_ANFOFF                      I2C_CR1_ANFOFF_Msk                      /*!< Analog noise filter OFF */
#define I2C_CR1_TXDMAEN_Pos                 (14U)
#define I2C_CR1_TXDMAEN_Msk                 (0x1UL << I2C_CR1_TXDMAEN_Pos)          /*!< 0x00004000 */
#define I2C_CR1_TXDMAEN                     I2C_CR1_TXDMAEN_Msk                     /*!< DMA transmission requests enable */
#define I2C_CR1_RXDMAEN_Pos                 (15U)
#define I2C_CR1_RXDMAEN_Msk                 (0x1UL << I2C_CR1_RXDMAEN_Pos)          /*!< 0x00008000 */
#define I2C_CR1_RXDMAEN                     I2C_CR1_RXDMAEN_Msk                     /*!< DMA reception requests enable */
#define I2C_CR1_SBC_Pos                     (16U)
#define I2C_CR1_SBC_Msk                     (0x1UL << I2C_CR1_SBC_Pos)              /*!< 0x00010000 */
#define I2C_CR1_SBC                         I2C_CR1_SBC_Msk                         /*!< Slave byte control */
#define I2C_CR1_NOSTRETCH_Pos               (17U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)        /*!< 0x00020000 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk                   /*!< Clock stretching disable */
#define I2C_CR1_WUPEN_Pos                   (18U)
#define I2C_CR1_WUPEN_Msk                   (0x1UL << I2C_CR1_WUPEN_Pos)            /*!< 0x00040000 */
#define I2C_CR1_WUPEN                       I2C_CR1_WUPEN_Msk                       /*!< Wakeup from STOP enable */
#define I2C_CR1_GCEN_Pos                    (19U)
#define I2C_CR1_GCEN_Msk                    (0x1UL << I2C_CR1_GCEN_Pos)             /*!< 0x00080000 */
#define I2C_CR1_GCEN                        I2C_CR1_GCEN_Msk                        /*!< General call enable */
#define I2C_CR1_SMBHEN_Pos                  (20U)
#define I2C_CR1_SMBHEN_Msk                  (0x1UL << I2C_CR1_SMBHEN_Pos)           /*!< 0x00100000 */
#define I2C_CR1_SMBHEN                      I2C_CR1_SMBHEN_Msk                      /*!< SMBus host address enable */
#define I2C_CR1_SMBDEN_Pos                  (21U)
#define I2C_CR1_SMBDEN_Msk                  (0x1UL << I2C_CR1_SMBDEN_Pos)           /*!< 0x00200000 */
#define I2C_CR1_SMBDEN                      I2C_CR1_SMBDEN_Msk                      /*!< SMBus device default address enable */
#define I2C_CR1_ALERTEN_Pos                 (22U)
#define I2C_CR1_ALERTEN_Msk                 (0x1UL << I2C_CR1_ALERTEN_Pos)          /*!< 0x00400000 */
#define I2C_CR1_ALERTEN                     I2C_CR1_ALERTEN_Msk                     /*!< SMBus alert enable */
#define I2C_CR1_PECEN_Pos                   (23U)
#define I2C_CR1_PECEN_Msk                   (0x1UL << I2C_CR1_PECEN_Pos)            /*!< 0x00800000 */
#define I2C_CR1_PECEN                       I2C_CR1_PECEN_Msk                       /*!< PEC enable */
#define I2C_CR1_FMP_Pos                     (24U)
#define I2C_CR1_FMP_Msk                     (0x1UL << I2C_CR1_FMP_Pos)              /*!< 0x01000000 */
#define I2C_CR1_FMP                         I2C_CR1_FMP_Msk                         /*!< Fast-mode Plus 20 mA drive enable */
#define I2C_CR1_ADDRACLR_Pos                (30U)
#define I2C_CR1_ADDRACLR_Msk                (0x1UL << I2C_CR1_ADDRACLR_Pos)         /*!< 0x40000000 */
#define I2C_CR1_ADDRACLR                    I2C_CR1_ADDRACLR_Msk                    /*!< ADDRACLR enable */
#define I2C_CR1_STOPFACLR_Pos               (30U)
#define I2C_CR1_STOPFACLR_Msk               (0x1UL << I2C_CR1_STOPFACLR_Pos)        /*!< 0x80000000 */
#define I2C_CR1_STOPFACLR                   I2C_CR1_STOPFACLR_Msk                   /*!< STOPFACLR enable */

/******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_SADD_Pos                    (0U)
#define I2C_CR2_SADD_Msk                    (0x3FFUL << I2C_CR2_SADD_Pos)           /*!< 0x000003FF */
#define I2C_CR2_SADD                        I2C_CR2_SADD_Msk                        /*!< Slave address (master mode) */
#define I2C_CR2_RD_WRN_Pos                  (10U)
#define I2C_CR2_RD_WRN_Msk                  (0x1UL << I2C_CR2_RD_WRN_Pos)           /*!< 0x00000400 */
#define I2C_CR2_RD_WRN                      I2C_CR2_RD_WRN_Msk                      /*!< Transfer direction (master mode) */
#define I2C_CR2_ADD10_Pos                   (11U)
#define I2C_CR2_ADD10_Msk                   (0x1UL << I2C_CR2_ADD10_Pos)            /*!< 0x00000800 */
#define I2C_CR2_ADD10                       I2C_CR2_ADD10_Msk                       /*!< 10-bit addressing mode (master mode) */
#define I2C_CR2_HEAD10R_Pos                 (12U)
#define I2C_CR2_HEAD10R_Msk                 (0x1UL << I2C_CR2_HEAD10R_Pos)          /*!< 0x00001000 */
#define I2C_CR2_HEAD10R                     I2C_CR2_HEAD10R_Msk                     /*!< 10-bit address header only read direction (master mode) */
#define I2C_CR2_START_Pos                   (13U)
#define I2C_CR2_START_Msk                   (0x1UL << I2C_CR2_START_Pos)            /*!< 0x00002000 */
#define I2C_CR2_START                       I2C_CR2_START_Msk                       /*!< START generation */
#define I2C_CR2_STOP_Pos                    (14U)
#define I2C_CR2_STOP_Msk                    (0x1UL << I2C_CR2_STOP_Pos)             /*!< 0x00004000 */
#define I2C_CR2_STOP                        I2C_CR2_STOP_Msk                        /*!< STOP generation (master mode) */
#define I2C_CR2_NACK_Pos                    (15U)
#define I2C_CR2_NACK_Msk                    (0x1UL << I2C_CR2_NACK_Pos)             /*!< 0x00008000 */
#define I2C_CR2_NACK                        I2C_CR2_NACK_Msk                        /*!< NACK generation (slave mode) */
#define I2C_CR2_NBYTES_Pos                  (16U)
#define I2C_CR2_NBYTES_Msk                  (0xFFUL << I2C_CR2_NBYTES_Pos)          /*!< 0x00FF0000 */
#define I2C_CR2_NBYTES                      I2C_CR2_NBYTES_Msk                      /*!< Number of bytes */
#define I2C_CR2_RELOAD_Pos                  (24U)
#define I2C_CR2_RELOAD_Msk                  (0x1UL << I2C_CR2_RELOAD_Pos)           /*!< 0x01000000 */
#define I2C_CR2_RELOAD                      I2C_CR2_RELOAD_Msk                      /*!< NBYTES reload mode */
#define I2C_CR2_AUTOEND_Pos                 (25U)
#define I2C_CR2_AUTOEND_Msk                 (0x1UL << I2C_CR2_AUTOEND_Pos)          /*!< 0x02000000 */
#define I2C_CR2_AUTOEND                     I2C_CR2_AUTOEND_Msk                     /*!< Automatic end mode (master mode) */
#define I2C_CR2_PECBYTE_Pos                 (26U)
#define I2C_CR2_PECBYTE_Msk                 (0x1UL << I2C_CR2_PECBYTE_Pos)          /*!< 0x04000000 */
#define I2C_CR2_PECBYTE                     I2C_CR2_PECBYTE_Msk                     /*!< Packet error checking byte */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define I2C_OAR1_OA1_Pos                    (0U)
#define I2C_OAR1_OA1_Msk                    (0x3FFUL << I2C_OAR1_OA1_Pos)           /*!< 0x000003FF */
#define I2C_OAR1_OA1                        I2C_OAR1_OA1_Msk                        /*!< Interface own address 1 */
#define I2C_OAR1_OA1MODE_Pos                (10U)
#define I2C_OAR1_OA1MODE_Msk                (0x1UL << I2C_OAR1_OA1MODE_Pos)         /*!< 0x00000400 */
#define I2C_OAR1_OA1MODE                    I2C_OAR1_OA1MODE_Msk                    /*!< Own address 1 10-bit mode */
#define I2C_OAR1_OA1EN_Pos                  (15U)
#define I2C_OAR1_OA1EN_Msk                  (0x1UL << I2C_OAR1_OA1EN_Pos)           /*!< 0x00008000 */
#define I2C_OAR1_OA1EN                      I2C_OAR1_OA1EN_Msk                      /*!< Own address 1 enable */

/*******************  Bit definition for I2C_OAR2 register  ******************/
#define I2C_OAR2_OA2_Pos                    (1U)
#define I2C_OAR2_OA2_Msk                    (0x7FUL << I2C_OAR2_OA2_Pos)            /*!< 0x000000FE */
#define I2C_OAR2_OA2                        I2C_OAR2_OA2_Msk                        /*!< Interface own address 2 */
#define I2C_OAR2_OA2MSK_Pos                 (8U)
#define I2C_OAR2_OA2MSK_Msk                 (0x7UL << I2C_OAR2_OA2MSK_Pos)          /*!< 0x00000700 */
#define I2C_OAR2_OA2MSK                     I2C_OAR2_OA2MSK_Msk                     /*!< Own address 2 masks */
#define I2C_OAR2_OA2NOMASK                  (0x00000000UL)                          /*!< No mask                                        */
#define I2C_OAR2_OA2MASK01_Pos              (8U)
#define I2C_OAR2_OA2MASK01_Msk              (0x1UL << I2C_OAR2_OA2MASK01_Pos)       /*!< 0x00000100 */
#define I2C_OAR2_OA2MASK01                  I2C_OAR2_OA2MASK01_Msk                  /*!< OA2[1] is masked, Only OA2[7:2] are compared   */
#define I2C_OAR2_OA2MASK02_Pos              (9U)
#define I2C_OAR2_OA2MASK02_Msk              (0x1UL << I2C_OAR2_OA2MASK02_Pos)       /*!< 0x00000200 */
#define I2C_OAR2_OA2MASK02                  I2C_OAR2_OA2MASK02_Msk                  /*!< OA2[2:1] is masked, Only OA2[7:3] are compared */
#define I2C_OAR2_OA2MASK03_Pos              (8U)
#define I2C_OAR2_OA2MASK03_Msk              (0x3UL << I2C_OAR2_OA2MASK03_Pos)       /*!< 0x00000300 */
#define I2C_OAR2_OA2MASK03                  I2C_OAR2_OA2MASK03_Msk                  /*!< OA2[3:1] is masked, Only OA2[7:4] are compared */
#define I2C_OAR2_OA2MASK04_Pos              (10U)
#define I2C_OAR2_OA2MASK04_Msk              (0x1UL << I2C_OAR2_OA2MASK04_Pos)       /*!< 0x00000400 */
#define I2C_OAR2_OA2MASK04                  I2C_OAR2_OA2MASK04_Msk                  /*!< OA2[4:1] is masked, Only OA2[7:5] are compared */
#define I2C_OAR2_OA2MASK05_Pos              (8U)
#define I2C_OAR2_OA2MASK05_Msk              (0x5UL << I2C_OAR2_OA2MASK05_Pos)       /*!< 0x00000500 */
#define I2C_OAR2_OA2MASK05                  I2C_OAR2_OA2MASK05_Msk                  /*!< OA2[5:1] is masked, Only OA2[7:6] are compared */
#define I2C_OAR2_OA2MASK06_Pos              (9U)
#define I2C_OAR2_OA2MASK06_Msk              (0x3UL << I2C_OAR2_OA2MASK06_Pos)       /*!< 0x00000600 */
#define I2C_OAR2_OA2MASK06                  I2C_OAR2_OA2MASK06_Msk                  /*!< OA2[6:1] is masked, Only OA2[7] are compared   */
#define I2C_OAR2_OA2MASK07_Pos              (8U)
#define I2C_OAR2_OA2MASK07_Msk              (0x7UL << I2C_OAR2_OA2MASK07_Pos)       /*!< 0x00000700 */
#define I2C_OAR2_OA2MASK07                  I2C_OAR2_OA2MASK07_Msk                  /*!< OA2[7:1] is masked, No comparison is done      */
#define I2C_OAR2_OA2EN_Pos                  (15U)
#define I2C_OAR2_OA2EN_Msk                  (0x1UL << I2C_OAR2_OA2EN_Pos)           /*!< 0x00008000 */
#define I2C_OAR2_OA2EN                      I2C_OAR2_OA2EN_Msk                      /*!< Own address 2 enable */

/*******************  Bit definition for I2C_TIMINGR register *******************/
#define I2C_TIMINGR_SCLL_Pos                (0U)
#define I2C_TIMINGR_SCLL_Msk                (0xFFUL << I2C_TIMINGR_SCLL_Pos)        /*!< 0x000000FF */
#define I2C_TIMINGR_SCLL                    I2C_TIMINGR_SCLL_Msk                    /*!< SCL low period (master mode) */
#define I2C_TIMINGR_SCLH_Pos                (8U)
#define I2C_TIMINGR_SCLH_Msk                (0xFFUL << I2C_TIMINGR_SCLH_Pos)        /*!< 0x0000FF00 */
#define I2C_TIMINGR_SCLH                    I2C_TIMINGR_SCLH_Msk                    /*!< SCL high period (master mode) */
#define I2C_TIMINGR_SDADEL_Pos              (16U)
#define I2C_TIMINGR_SDADEL_Msk              (0xFUL << I2C_TIMINGR_SDADEL_Pos)       /*!< 0x000F0000 */
#define I2C_TIMINGR_SDADEL                  I2C_TIMINGR_SDADEL_Msk                  /*!< Data hold time */
#define I2C_TIMINGR_SCLDEL_Pos              (20U)
#define I2C_TIMINGR_SCLDEL_Msk              (0xFUL << I2C_TIMINGR_SCLDEL_Pos)       /*!< 0x00F00000 */
#define I2C_TIMINGR_SCLDEL                  I2C_TIMINGR_SCLDEL_Msk                  /*!< Data setup time */
#define I2C_TIMINGR_PRESC_Pos               (28U)
#define I2C_TIMINGR_PRESC_Msk               (0xFUL << I2C_TIMINGR_PRESC_Pos)        /*!< 0xF0000000 */
#define I2C_TIMINGR_PRESC                   I2C_TIMINGR_PRESC_Msk                   /*!< Timings prescaler */

/******************* Bit definition for I2C_TIMEOUTR register *******************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos           (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk           (0xFFFUL << I2C_TIMEOUTR_TIMEOUTA_Pos)  /*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA               I2C_TIMEOUTR_TIMEOUTA_Msk               /*!< Bus timeout A */
#define I2C_TIMEOUTR_TIDLE_Pos              (12U)
#define I2C_TIMEOUTR_TIDLE_Msk              (0x1UL << I2C_TIMEOUTR_TIDLE_Pos)       /*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE                  I2C_TIMEOUTR_TIDLE_Msk                  /*!< Idle clock timeout detection */
#define I2C_TIMEOUTR_TIMOUTEN_Pos           (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk           (0x1UL << I2C_TIMEOUTR_TIMOUTEN_Pos)    /*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMOUTEN               I2C_TIMEOUTR_TIMOUTEN_Msk               /*!< Clock timeout enable */
#define I2C_TIMEOUTR_TIMEOUTB_Pos           (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk           (0xFFFUL << I2C_TIMEOUTR_TIMEOUTB_Pos)  /*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB               I2C_TIMEOUTR_TIMEOUTB_Msk               /*!< Bus timeout B*/
#define I2C_TIMEOUTR_TEXTEN_Pos             (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk             (0x1UL << I2C_TIMEOUTR_TEXTEN_Pos)      /*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN                 I2C_TIMEOUTR_TEXTEN_Msk                 /*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  *********************/
#define I2C_ISR_TXE_Pos                     (0U)
#define I2C_ISR_TXE_Msk                     (0x1UL << I2C_ISR_TXE_Pos)              /*!< 0x00000001 */
#define I2C_ISR_TXE                         I2C_ISR_TXE_Msk                         /*!< Transmit data register empty */
#define I2C_ISR_TXIS_Pos                    (1U)
#define I2C_ISR_TXIS_Msk                    (0x1UL << I2C_ISR_TXIS_Pos)             /*!< 0x00000002 */
#define I2C_ISR_TXIS                        I2C_ISR_TXIS_Msk                        /*!< Transmit interrupt status */
#define I2C_ISR_RXNE_Pos                    (2U)
#define I2C_ISR_RXNE_Msk                    (0x1UL << I2C_ISR_RXNE_Pos)             /*!< 0x00000004 */
#define I2C_ISR_RXNE                        I2C_ISR_RXNE_Msk                        /*!< Receive data register not empty */
#define I2C_ISR_ADDR_Pos                    (3U)
#define I2C_ISR_ADDR_Msk                    (0x1UL << I2C_ISR_ADDR_Pos)             /*!< 0x00000008 */
#define I2C_ISR_ADDR                        I2C_ISR_ADDR_Msk                        /*!< Address matched (slave mode)*/
#define I2C_ISR_NACKF_Pos                   (4U)
#define I2C_ISR_NACKF_Msk                   (0x1UL << I2C_ISR_NACKF_Pos)            /*!< 0x00000010 */
#define I2C_ISR_NACKF                       I2C_ISR_NACKF_Msk                       /*!< NACK received flag */
#define I2C_ISR_STOPF_Pos                   (5U)
#define I2C_ISR_STOPF_Msk                   (0x1UL << I2C_ISR_STOPF_Pos)            /*!< 0x00000020 */
#define I2C_ISR_STOPF                       I2C_ISR_STOPF_Msk                       /*!< STOP detection flag */
#define I2C_ISR_TC_Pos                      (6U)
#define I2C_ISR_TC_Msk                      (0x1UL << I2C_ISR_TC_Pos)               /*!< 0x00000040 */
#define I2C_ISR_TC                          I2C_ISR_TC_Msk                          /*!< Transfer complete (master mode) */
#define I2C_ISR_TCR_Pos                     (7U)
#define I2C_ISR_TCR_Msk                     (0x1UL << I2C_ISR_TCR_Pos)              /*!< 0x00000080 */
#define I2C_ISR_TCR                         I2C_ISR_TCR_Msk                         /*!< Transfer complete reload */
#define I2C_ISR_BERR_Pos                    (8U)
#define I2C_ISR_BERR_Msk                    (0x1UL << I2C_ISR_BERR_Pos)             /*!< 0x00000100 */
#define I2C_ISR_BERR                        I2C_ISR_BERR_Msk                        /*!< Bus error */
#define I2C_ISR_ARLO_Pos                    (9U)
#define I2C_ISR_ARLO_Msk                    (0x1UL << I2C_ISR_ARLO_Pos)             /*!< 0x00000200 */
#define I2C_ISR_ARLO                        I2C_ISR_ARLO_Msk                        /*!< Arbitration lost */
#define I2C_ISR_OVR_Pos                     (10U)
#define I2C_ISR_OVR_Msk                     (0x1UL << I2C_ISR_OVR_Pos)              /*!< 0x00000400 */
#define I2C_ISR_OVR                         I2C_ISR_OVR_Msk                         /*!< Overrun/Underrun */
#define I2C_ISR_PECERR_Pos                  (11U)
#define I2C_ISR_PECERR_Msk                  (0x1UL << I2C_ISR_PECERR_Pos)           /*!< 0x00000800 */
#define I2C_ISR_PECERR                      I2C_ISR_PECERR_Msk                      /*!< PEC error in reception */
#define I2C_ISR_TIMEOUT_Pos                 (12U)
#define I2C_ISR_TIMEOUT_Msk                 (0x1UL << I2C_ISR_TIMEOUT_Pos)          /*!< 0x00001000 */
#define I2C_ISR_TIMEOUT                     I2C_ISR_TIMEOUT_Msk                     /*!< Timeout or Tlow detection flag */
#define I2C_ISR_ALERT_Pos                   (13U)
#define I2C_ISR_ALERT_Msk                   (0x1UL << I2C_ISR_ALERT_Pos)            /*!< 0x00002000 */
#define I2C_ISR_ALERT                       I2C_ISR_ALERT_Msk                       /*!< SMBus alert */
#define I2C_ISR_BUSY_Pos                    (15U)
#define I2C_ISR_BUSY_Msk                    (0x1UL << I2C_ISR_BUSY_Pos)             /*!< 0x00008000 */
#define I2C_ISR_BUSY                        I2C_ISR_BUSY_Msk                        /*!< Bus busy */
#define I2C_ISR_DIR_Pos                     (16U)
#define I2C_ISR_DIR_Msk                     (0x1UL << I2C_ISR_DIR_Pos)              /*!< 0x00010000 */
#define I2C_ISR_DIR                         I2C_ISR_DIR_Msk                         /*!< Transfer direction (slave mode) */
#define I2C_ISR_ADDCODE_Pos                 (17U)
#define I2C_ISR_ADDCODE_Msk                 (0x7FUL << I2C_ISR_ADDCODE_Pos)         /*!< 0x00FE0000 */
#define I2C_ISR_ADDCODE                     I2C_ISR_ADDCODE_Msk                     /*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  *********************/
#define I2C_ICR_ADDRCF_Pos                  (3U)
#define I2C_ICR_ADDRCF_Msk                  (0x1UL << I2C_ICR_ADDRCF_Pos)           /*!< 0x00000008 */
#define I2C_ICR_ADDRCF                      I2C_ICR_ADDRCF_Msk                      /*!< Address matched clear flag */
#define I2C_ICR_NACKCF_Pos                  (4U)
#define I2C_ICR_NACKCF_Msk                  (0x1UL << I2C_ICR_NACKCF_Pos)           /*!< 0x00000010 */
#define I2C_ICR_NACKCF                      I2C_ICR_NACKCF_Msk                      /*!< NACK clear flag */
#define I2C_ICR_STOPCF_Pos                  (5U)
#define I2C_ICR_STOPCF_Msk                  (0x1UL << I2C_ICR_STOPCF_Pos)           /*!< 0x00000020 */
#define I2C_ICR_STOPCF                      I2C_ICR_STOPCF_Msk                      /*!< STOP detection clear flag */
#define I2C_ICR_BERRCF_Pos                  (8U)
#define I2C_ICR_BERRCF_Msk                  (0x1UL << I2C_ICR_BERRCF_Pos)           /*!< 0x00000100 */
#define I2C_ICR_BERRCF                      I2C_ICR_BERRCF_Msk                      /*!< Bus error clear flag */
#define I2C_ICR_ARLOCF_Pos                  (9U)
#define I2C_ICR_ARLOCF_Msk                  (0x1UL << I2C_ICR_ARLOCF_Pos)           /*!< 0x00000200 */
#define I2C_ICR_ARLOCF                      I2C_ICR_ARLOCF_Msk                      /*!< Arbitration lost clear flag */
#define I2C_ICR_OVRCF_Pos                   (10U)
#define I2C_ICR_OVRCF_Msk                   (0x1UL << I2C_ICR_OVRCF_Pos)            /*!< 0x00000400 */
#define I2C_ICR_OVRCF                       I2C_ICR_OVRCF_Msk                       /*!< Overrun/Underrun clear flag */
#define I2C_ICR_PECCF_Pos                   (11U)
#define I2C_ICR_PECCF_Msk                   (0x1UL << I2C_ICR_PECCF_Pos)            /*!< 0x00000800 */
#define I2C_ICR_PECCF                       I2C_ICR_PECCF_Msk                       /*!< PAC error clear flag */
#define I2C_ICR_TIMOUTCF_Pos                (12U)
#define I2C_ICR_TIMOUTCF_Msk                (0x1UL << I2C_ICR_TIMOUTCF_Pos)         /*!< 0x00001000 */
#define I2C_ICR_TIMOUTCF                    I2C_ICR_TIMOUTCF_Msk                    /*!< Timeout clear flag */
#define I2C_ICR_ALERTCF_Pos                 (13U)
#define I2C_ICR_ALERTCF_Msk                 (0x1UL << I2C_ICR_ALERTCF_Pos)          /*!< 0x00002000 */
#define I2C_ICR_ALERTCF                     I2C_ICR_ALERTCF_Msk                     /*!< Alert clear flag */

/******************  Bit definition for I2C_PECR register  *********************/
#define I2C_PECR_PEC_Pos                    (0U)
#define I2C_PECR_PEC_Msk                    (0xFFUL << I2C_PECR_PEC_Pos)            /*!< 0x000000FF */
#define I2C_PECR_PEC                        I2C_PECR_PEC_Msk                        /*!< PEC register */

/******************  Bit definition for I2C_RXDR register  *********************/
#define I2C_RXDR_RXDATA_Pos                 (0U)
#define I2C_RXDR_RXDATA_Msk                 (0xFFUL << I2C_RXDR_RXDATA_Pos)         /*!< 0x000000FF */
#define I2C_RXDR_RXDATA                     I2C_RXDR_RXDATA_Msk                     /*!< 8-bit receive data */

/******************  Bit definition for I2C_TXDR register  *********************/
#define I2C_TXDR_TXDATA_Pos                 (0U)
#define I2C_TXDR_TXDATA_Msk                 (0xFFUL << I2C_TXDR_TXDATA_Pos)         /*!< 0x000000FF */
#define I2C_TXDR_TXDATA                     I2C_TXDR_TXDATA_Msk                     /*!< 8-bit transmit data */

/******************  Bit definition for I2C_AUTOCR register  ********************/
#define I2C_AUTOCR_TCDMAEN_Pos              (6U)
#define I2C_AUTOCR_TCDMAEN_Msk              (0x1UL << I2C_AUTOCR_TCDMAEN_Pos)       /*!< 0x00000040 */
#define I2C_AUTOCR_TCDMAEN                  I2C_AUTOCR_TCDMAEN_Msk                  /*!< DMA request enable on Transfer Complete event */
#define I2C_AUTOCR_TCRDMAEN_Pos             (7U)
#define I2C_AUTOCR_TCRDMAEN_Msk             (0x1UL << I2C_AUTOCR_TCRDMAEN_Pos)      /*!< 0x00000080 */
#define I2C_AUTOCR_TCRDMAEN                 I2C_AUTOCR_TCRDMAEN_Msk                 /*!< DMA request enable on Transfer Complete Reload event */
#define I2C_AUTOCR_TRIGSEL_Pos              (16U)
#define I2C_AUTOCR_TRIGSEL_Msk              (0xFUL << I2C_AUTOCR_TRIGSEL_Pos)       /*!< 0x000F0000 */
#define I2C_AUTOCR_TRIGSEL                  I2C_AUTOCR_TRIGSEL_Msk                  /*!< Trigger selection */
#define I2C_AUTOCR_TRIGPOL_Pos              (20U)
#define I2C_AUTOCR_TRIGPOL_Msk              (0x1UL << I2C_AUTOCR_TRIGPOL_Pos)       /*!< 0x000100000 */
#define I2C_AUTOCR_TRIGPOL                  I2C_AUTOCR_TRIGPOL_Msk                  /*!< Trigger polarity */
#define I2C_AUTOCR_TRIGEN_Pos               (21U)
#define I2C_AUTOCR_TRIGEN_Msk               (0x1UL << I2C_AUTOCR_TRIGEN_Pos)        /*!< 0x000200000 */
#define I2C_AUTOCR_TRIGEN                   I2C_AUTOCR_TRIGEN_Msk                   /*!< Trigger enable */


/******************************************************************************/
/*                                                                            */
/*                                 ICACHE                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for ICACHE_CR register  *******************/
#define ICACHE_CR_EN_Pos                    (0U)
#define ICACHE_CR_EN_Msk                    (0x1UL << ICACHE_CR_EN_Pos)             /*!< 0x00000001 */
#define ICACHE_CR_EN                        ICACHE_CR_EN_Msk                        /*!< Enable */
#define ICACHE_CR_CACHEINV_Pos              (1U)
#define ICACHE_CR_CACHEINV_Msk              (0x1UL << ICACHE_CR_CACHEINV_Pos)       /*!< 0x00000002 */
#define ICACHE_CR_CACHEINV                  ICACHE_CR_CACHEINV_Msk                  /*!< Cache invalidation */
#define ICACHE_CR_WAYSEL_Pos                (2U)
#define ICACHE_CR_WAYSEL_Msk                (0x1UL << ICACHE_CR_WAYSEL_Pos)         /*!< 0x00000004 */
#define ICACHE_CR_WAYSEL                    ICACHE_CR_WAYSEL_Msk                    /*!< Ways selection */
#define ICACHE_CR_HITMEN_Pos                (16U)
#define ICACHE_CR_HITMEN_Msk                (0x1UL << ICACHE_CR_HITMEN_Pos)         /*!< 0x00010000 */
#define ICACHE_CR_HITMEN                    ICACHE_CR_HITMEN_Msk                    /*!< Hit monitor enable */
#define ICACHE_CR_MISSMEN_Pos               (17U)
#define ICACHE_CR_MISSMEN_Msk               (0x1UL << ICACHE_CR_MISSMEN_Pos)        /*!< 0x00020000 */
#define ICACHE_CR_MISSMEN                   ICACHE_CR_MISSMEN_Msk                   /*!< Miss monitor enable */
#define ICACHE_CR_HITMRST_Pos               (18U)
#define ICACHE_CR_HITMRST_Msk               (0x1UL << ICACHE_CR_HITMRST_Pos)        /*!< 0x00040000 */
#define ICACHE_CR_HITMRST                   ICACHE_CR_HITMRST_Msk                   /*!< Hit monitor reset */
#define ICACHE_CR_MISSMRST_Pos              (19U)
#define ICACHE_CR_MISSMRST_Msk              (0x1UL << ICACHE_CR_MISSMRST_Pos)       /*!< 0x00080000 */
#define ICACHE_CR_MISSMRST                  ICACHE_CR_MISSMRST_Msk                  /*!< Miss monitor reset */

/******************  Bit definition for ICACHE_SR register  *******************/
#define ICACHE_SR_BUSYF_Pos                 (0U)
#define ICACHE_SR_BUSYF_Msk                 (0x1UL << ICACHE_SR_BUSYF_Pos)          /*!< 0x00000001 */
#define ICACHE_SR_BUSYF                     ICACHE_SR_BUSYF_Msk                     /*!< Busy flag */
#define ICACHE_SR_BSYENDF_Pos               (1U)
#define ICACHE_SR_BSYENDF_Msk               (0x1UL << ICACHE_SR_BSYENDF_Pos)        /*!< 0x00000002 */
#define ICACHE_SR_BSYENDF                   ICACHE_SR_BSYENDF_Msk                   /*!< Busy end flag */
#define ICACHE_SR_ERRF_Pos                  (2U)
#define ICACHE_SR_ERRF_Msk                  (0x1UL << ICACHE_SR_ERRF_Pos)           /*!< 0x00000004 */
#define ICACHE_SR_ERRF                      ICACHE_SR_ERRF_Msk                      /*!< Cache error flag */

/******************  Bit definition for ICACHE_IER register  ******************/
#define ICACHE_IER_BSYENDIE_Pos             (1U)
#define ICACHE_IER_BSYENDIE_Msk             (0x1UL << ICACHE_IER_BSYENDIE_Pos)      /*!< 0x00000002 */
#define ICACHE_IER_BSYENDIE                 ICACHE_IER_BSYENDIE_Msk                 /*!< Busy end interrupt enable */
#define ICACHE_IER_ERRIE_Pos                (2U)
#define ICACHE_IER_ERRIE_Msk                (0x1UL << ICACHE_IER_ERRIE_Pos)         /*!< 0x00000004 */
#define ICACHE_IER_ERRIE                    ICACHE_IER_ERRIE_Msk                    /*!< Cache error interrupt enable */

/******************  Bit definition for ICACHE_FCR register  ******************/
#define ICACHE_FCR_CBSYENDF_Pos             (1U)
#define ICACHE_FCR_CBSYENDF_Msk             (0x1UL << ICACHE_FCR_CBSYENDF_Pos)      /*!< 0x00000002 */
#define ICACHE_FCR_CBSYENDF                 ICACHE_FCR_CBSYENDF_Msk                 /*!< Busy end flag clear */
#define ICACHE_FCR_CERRF_Pos                (2U)
#define ICACHE_FCR_CERRF_Msk                (0x1UL << ICACHE_FCR_CERRF_Pos)         /*!< 0x00000004 */
#define ICACHE_FCR_CERRF                    ICACHE_FCR_CERRF_Msk                    /*!< Cache error flag clear */

/******************  Bit definition for ICACHE_HMONR register  ****************/
#define ICACHE_HMONR_HITMON_Pos             (0U)
#define ICACHE_HMONR_HITMON_Msk             (0xFFFFFFFFUL << ICACHE_HMONR_HITMON_Pos) /*!< 0xFFFFFFFF */
#define ICACHE_HMONR_HITMON                 ICACHE_HMONR_HITMON_Msk                 /*!< Cache hit monitor register */

/******************  Bit definition for ICACHE_MMONR register  ****************/
#define ICACHE_MMONR_MISSMON_Pos            (0U)
#define ICACHE_MMONR_MISSMON_Msk            (0xFFFFUL << ICACHE_MMONR_MISSMON_Pos)  /*!< 0x0000FFFF */
#define ICACHE_MMONR_MISSMON                ICACHE_MMONR_MISSMON_Msk                /*!< Cache miss monitor register */

/******************  Bit definition for ICACHE_CRRx register  *****************/
#define ICACHE_CRRx_BASEADDR_Pos            (0U)
#define ICACHE_CRRx_BASEADDR_Msk            (0xFFUL << ICACHE_CRRx_BASEADDR_Pos)    /*!< 0x000000FF */
#define ICACHE_CRRx_BASEADDR                ICACHE_CRRx_BASEADDR_Msk                /*!< Base address of region X to remap */
#define ICACHE_CRRx_RSIZE_Pos               (9U)
#define ICACHE_CRRx_RSIZE_Msk               (0x7UL << ICACHE_CRRx_RSIZE_Pos)        /*!< 0x00000E00 */
#define ICACHE_CRRx_RSIZE                   ICACHE_CRRx_RSIZE_Msk                   /*!< Region X size */
#define ICACHE_CRRx_RSIZE_0                 (0x1UL << ICACHE_CRRx_RSIZE_Pos)        /*!< 0x00000200 */
#define ICACHE_CRRx_RSIZE_1                 (0x2UL << ICACHE_CRRx_RSIZE_Pos)        /*!< 0x00000400 */
#define ICACHE_CRRx_RSIZE_2                 (0x4UL << ICACHE_CRRx_RSIZE_Pos)        /*!< 0x00000800 */
#define ICACHE_CRRx_REN_Pos                 (15U)
#define ICACHE_CRRx_REN_Msk                 (0x1UL << ICACHE_CRRx_REN_Pos)          /*!< 0x00008000 */
#define ICACHE_CRRx_REN                     ICACHE_CRRx_REN_Msk                     /*!< Region X enable */
#define ICACHE_CRRx_REMAPADDR_Pos           (16U)
#define ICACHE_CRRx_REMAPADDR_Msk           (0x7FFUL << ICACHE_CRRx_REMAPADDR_Pos)  /*!< 0x07FF0000 */
#define ICACHE_CRRx_REMAPADDR               ICACHE_CRRx_REMAPADDR_Msk               /*!< Remap address of Region X to be remapped */
#define ICACHE_CRRx_MSTSEL_Pos              (28U)
#define ICACHE_CRRx_MSTSEL_Msk              (0x1UL << ICACHE_CRRx_MSTSEL_Pos)       /*!< 0x10000000 */
#define ICACHE_CRRx_MSTSEL                  ICACHE_CRRx_MSTSEL_Msk                  /*!< Region X AHB cache master selection */
#define ICACHE_CRRx_HBURST_Pos              (31U)
#define ICACHE_CRRx_HBURST_Msk              (0x1UL << ICACHE_CRRx_HBURST_Pos)       /*!< 0x80000000 */
#define ICACHE_CRRx_HBURST                  ICACHE_CRRx_HBURST_Msk                  /*!< Region X output burst type */


/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos                     (0U)
#define IWDG_KR_KEY_Msk                     (0xFFFFUL << IWDG_KR_KEY_Pos)           /*!< 0x0000FFFF */
#define IWDG_KR_KEY                         IWDG_KR_KEY_Msk                         /*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos                      (0U)
#define IWDG_PR_PR_Msk                      (0xFUL << IWDG_PR_PR_Pos)               /*!< 0x0000000F */
#define IWDG_PR_PR                          IWDG_PR_PR_Msk                          /*!<PR[3:0] (Prescaler divider)         */
#define IWDG_PR_PR_0                        (0x1UL << IWDG_PR_PR_Pos)               /*!< 0x00000001 */
#define IWDG_PR_PR_1                        (0x2UL << IWDG_PR_PR_Pos)               /*!< 0x00000002 */
#define IWDG_PR_PR_2                        (0x4UL << IWDG_PR_PR_Pos)               /*!< 0x00000004 */
#define IWDG_PR_PR_3                        (0x8UL << IWDG_PR_PR_Pos)               /*!< 0x00000008 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos                     (0U)
#define IWDG_RLR_RL_Msk                     (0xFFFUL << IWDG_RLR_RL_Pos)            /*!< 0x00000FFF */
#define IWDG_RLR_RL                         IWDG_RLR_RL_Msk                         /*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos                     (0U)
#define IWDG_SR_PVU_Msk                     (0x1UL << IWDG_SR_PVU_Pos)              /*!< 0x00000001 */
#define IWDG_SR_PVU                         IWDG_SR_PVU_Msk                         /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos                     (1U)
#define IWDG_SR_RVU_Msk                     (0x1UL << IWDG_SR_RVU_Pos)              /*!< 0x00000002 */
#define IWDG_SR_RVU                         IWDG_SR_RVU_Msk                         /*!< Watchdog counter reload value update */
#define IWDG_SR_WVU_Pos                     (2U)
#define IWDG_SR_WVU_Msk                     (0x1UL << IWDG_SR_WVU_Pos)              /*!< 0x00000004 */
#define IWDG_SR_WVU                         IWDG_SR_WVU_Msk                         /*!< Watchdog counter window value update */
#define IWDG_SR_EWU_Pos                     (3U)
#define IWDG_SR_EWU_Msk                     (0x1UL << IWDG_SR_EWU_Pos)              /*!< 0x00000008 */
#define IWDG_SR_EWU                         IWDG_SR_EWU_Msk                         /*!< Watchdog interrupt comparator value update */
#define IWDG_SR_ONF_Pos                     (8U)
#define IWDG_SR_ONF_Msk                     (0x1UL << IWDG_SR_ONF_Pos)              /*!< 0x000001000 */
#define IWDG_SR_ONF                         IWDG_SR_ONF_Msk                         /*!< Watchdog enable status bit */
#define IWDG_SR_EWIF_Pos                    (14U)
#define IWDG_SR_EWIF_Msk                    (0x1UL << IWDG_SR_EWIF_Pos)             /*!< 0x00000100 */
#define IWDG_SR_EWIF                        IWDG_SR_EWIF_Msk                        /*!< Watchdog early interrupt flag */

/******************  Bit definition for IWDG_WINR register  *******************/
#define IWDG_WINR_WIN_Pos                   (0U)
#define IWDG_WINR_WIN_Msk                   (0xFFFUL << IWDG_WINR_WIN_Pos)          /*!< 0x00000FFF */
#define IWDG_WINR_WIN                       IWDG_WINR_WIN_Msk                       /*!< Watchdog counter window value */

/******************  Bit definition for IWDG_EWCR register  *******************/
#define IWDG_EWCR_EWIT_Pos                  (0U)
#define IWDG_EWCR_EWIT_Msk                  (0xFFFUL << IWDG_EWCR_EWIT_Pos)         /*!< 0x00000FFF */
#define IWDG_EWCR_EWIT                      IWDG_EWCR_EWIT_Msk                      /*!< Watchdog early wakeup comparator value */
#define IWDG_EWCR_EWIC_Pos                  (14U)
#define IWDG_EWCR_EWIC_Msk                  (0x1UL << IWDG_EWCR_EWIC_Pos)           /*!< 0x00000FFF */
#define IWDG_EWCR_EWIC                      IWDG_EWCR_EWIC_Msk                      /*!< Watchdog early wakeup comparator value */
#define IWDG_EWCR_EWIE_Pos                  (15U)
#define IWDG_EWCR_EWIE_Msk                  (0x1UL << IWDG_EWCR_EWIE_Pos)           /*!< 0x00000FFF */
#define IWDG_EWCR_EWIE                      IWDG_EWCR_EWIE_Msk                      /*!< Watchdog early wakeup comparator value */


/******************************************************************************/
/*                                                                            */
/*                         Low Power Timer (LPTIM)                            */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for LPTIM_ISR register  *******************/
#define LPTIM_ISR_CC1IF_Pos                 (0U)
#define LPTIM_ISR_CC1IF_Msk                 (0x1UL << LPTIM_ISR_CC1IF_Pos)          /*!< 0x00000001 */
#define LPTIM_ISR_CC1IF                     LPTIM_ISR_CC1IF_Msk                     /*!< Capture/Compare 1 interrupt flag */
#define LPTIM_ISR_ARRM_Pos                  (1U)
#define LPTIM_ISR_ARRM_Msk                  (0x1UL << LPTIM_ISR_ARRM_Pos)           /*!< 0x00000002 */
#define LPTIM_ISR_ARRM                      LPTIM_ISR_ARRM_Msk                      /*!< Autoreload match */
#define LPTIM_ISR_EXTTRIG_Pos               (2U)
#define LPTIM_ISR_EXTTRIG_Msk               (0x1UL << LPTIM_ISR_EXTTRIG_Pos)        /*!< 0x00000004 */
#define LPTIM_ISR_EXTTRIG                   LPTIM_ISR_EXTTRIG_Msk                   /*!< External trigger edge event */
#define LPTIM_ISR_CMP1OK_Pos                (3U)
#define LPTIM_ISR_CMP1OK_Msk                (0x1UL << LPTIM_ISR_CMP1OK_Pos)         /*!< 0x00000008 */
#define LPTIM_ISR_CMP1OK                    LPTIM_ISR_CMP1OK_Msk                    /*!< Compare register 1 update OK */
#define LPTIM_ISR_ARROK_Pos                 (4U)
#define LPTIM_ISR_ARROK_Msk                 (0x1UL << LPTIM_ISR_ARROK_Pos)          /*!< 0x00000010 */
#define LPTIM_ISR_ARROK                     LPTIM_ISR_ARROK_Msk                     /*!< Autoreload register update OK */
#define LPTIM_ISR_UP_Pos                    (5U)
#define LPTIM_ISR_UP_Msk                    (0x1UL << LPTIM_ISR_UP_Pos)             /*!< 0x00000020 */
#define LPTIM_ISR_UP                        LPTIM_ISR_UP_Msk                        /*!< Counter direction change down to up */
#define LPTIM_ISR_DOWN_Pos                  (6U)
#define LPTIM_ISR_DOWN_Msk                  (0x1UL << LPTIM_ISR_DOWN_Pos)           /*!< 0x00000040 */
#define LPTIM_ISR_DOWN                      LPTIM_ISR_DOWN_Msk                      /*!< Counter direction change up to down */
#define LPTIM_ISR_UE_Pos                    (7U)
#define LPTIM_ISR_UE_Msk                    (0x1UL << LPTIM_ISR_UE_Pos)             /*!< 0x00000080 */
#define LPTIM_ISR_UE                        LPTIM_ISR_UE_Msk                        /*!< Update event */
#define LPTIM_ISR_REPOK_Pos                 (8U)
#define LPTIM_ISR_REPOK_Msk                 (0x1UL << LPTIM_ISR_REPOK_Pos)          /*!< 0x00000100 */
#define LPTIM_ISR_REPOK                     LPTIM_ISR_REPOK_Msk                     /*!< Repetition register update OK */
#define LPTIM_ISR_CC2IF_Pos                 (9U)
#define LPTIM_ISR_CC2IF_Msk                 (0x1UL << LPTIM_ISR_CC2IF_Pos)          /*!< 0x00000200 */
#define LPTIM_ISR_CC2IF                     LPTIM_ISR_CC2IF_Msk                     /*!< Capture/Compare 2 interrupt flag */
#define LPTIM_ISR_CC1OF_Pos                 (12U)
#define LPTIM_ISR_CC1OF_Msk                 (0x1UL << LPTIM_ISR_CC1OF_Pos)          /*!< 0x00001000 */
#define LPTIM_ISR_CC1OF                     LPTIM_ISR_CC1OF_Msk                     /*!< Capture/Compare 1 over-capture flag */
#define LPTIM_ISR_CC2OF_Pos                 (13U)
#define LPTIM_ISR_CC2OF_Msk                 (0x1UL << LPTIM_ISR_CC2OF_Pos)          /*!< 0x00002000 */
#define LPTIM_ISR_CC2OF                     LPTIM_ISR_CC2OF_Msk                     /*!< Capture/Compare 2 over-capture flag */
#define LPTIM_ISR_CMP2OK_Pos                (19U)
#define LPTIM_ISR_CMP2OK_Msk                (0x1UL << LPTIM_ISR_CMP2OK_Pos)         /*!< 0x00080000 */
#define LPTIM_ISR_CMP2OK                    LPTIM_ISR_CMP2OK_Msk                    /*!< Compare register 2 update OK */
#define LPTIM_ISR_DIEROK_Pos                (24U)
#define LPTIM_ISR_DIEROK_Msk                (0x1UL << LPTIM_ISR_DIEROK_Pos)         /*!< 0x01000000 */
#define LPTIM_ISR_DIEROK                    LPTIM_ISR_DIEROK_Msk                    /*!< DMA & interrupt enable update OK */

/******************  Bit definition for LPTIM_ICR register  *******************/
#define LPTIM_ICR_CC1CF_Pos                 (0U)
#define LPTIM_ICR_CC1CF_Msk                 (0x1UL << LPTIM_ICR_CC1CF_Pos)          /*!< 0x00000001 */
#define LPTIM_ICR_CC1CF                     LPTIM_ICR_CC1CF_Msk                     /*!< Capture/Compare 1 clear flag  */
#define LPTIM_ICR_ARRMCF_Pos                (1U)
#define LPTIM_ICR_ARRMCF_Msk                (0x1UL << LPTIM_ICR_ARRMCF_Pos)         /*!< 0x00000002 */
#define LPTIM_ICR_ARRMCF                    LPTIM_ICR_ARRMCF_Msk                    /*!< Autoreload match clear flag */
#define LPTIM_ICR_EXTTRIGCF_Pos             (2U)
#define LPTIM_ICR_EXTTRIGCF_Msk             (0x1UL << LPTIM_ICR_EXTTRIGCF_Pos)      /*!< 0x00000004 */
#define LPTIM_ICR_EXTTRIGCF                 LPTIM_ICR_EXTTRIGCF_Msk                 /*!< External trigger edge event clear flag */
#define LPTIM_ICR_CMP1OKCF_Pos              (3U)
#define LPTIM_ICR_CMP1OKCF_Msk              (0x1UL << LPTIM_ICR_CMP1OKCF_Pos)       /*!< 0x00000008 */
#define LPTIM_ICR_CMP1OKCF                  LPTIM_ICR_CMP1OKCF_Msk                  /*!< Compare register 1 update OK clear flag */
#define LPTIM_ICR_ARROKCF_Pos               (4U)
#define LPTIM_ICR_ARROKCF_Msk               (0x1UL << LPTIM_ICR_ARROKCF_Pos)        /*!< 0x00000010 */
#define LPTIM_ICR_ARROKCF                   LPTIM_ICR_ARROKCF_Msk                   /*!< Autoreload register update OK clear flag */
#define LPTIM_ICR_UPCF_Pos                  (5U)
#define LPTIM_ICR_UPCF_Msk                  (0x1UL << LPTIM_ICR_UPCF_Pos)           /*!< 0x00000020 */
#define LPTIM_ICR_UPCF                      LPTIM_ICR_UPCF_Msk                      /*!< Counter direction change down to up clear flag */
#define LPTIM_ICR_DOWNCF_Pos                (6U)
#define LPTIM_ICR_DOWNCF_Msk                (0x1UL << LPTIM_ICR_DOWNCF_Pos)         /*!< 0x00000040 */
#define LPTIM_ICR_DOWNCF                    LPTIM_ICR_DOWNCF_Msk                    /*!< Counter direction change up to down clear flag */
#define LPTIM_ICR_UECF_Pos                  (7U)
#define LPTIM_ICR_UECF_Msk                  (0x1UL << LPTIM_ICR_UECF_Pos)           /*!< 0x00000080 */
#define LPTIM_ICR_UECF                      LPTIM_ICR_UECF_Msk                      /*!< Update event clear flag */
#define LPTIM_ICR_REPOKCF_Pos               (8U)
#define LPTIM_ICR_REPOKCF_Msk               (0x1UL << LPTIM_ICR_REPOKCF_Pos)        /*!< 0x00000100 */
#define LPTIM_ICR_REPOKCF                   LPTIM_ICR_REPOKCF_Msk                   /*!< Repetition register update OK clear flag */
#define LPTIM_ICR_CC2CF_Pos                 (9U)
#define LPTIM_ICR_CC2CF_Msk                 (0x1UL << LPTIM_ICR_CC2CF_Pos)          /*!< 0x00000200 */
#define LPTIM_ICR_CC2CF                     LPTIM_ICR_CC2CF_Msk                     /*!< Capture/Compare 2 clear flag  */
#define LPTIM_ICR_CC1OCF_Pos                (12U)
#define LPTIM_ICR_CC1OCF_Msk                (0x1UL << LPTIM_ICR_CC1OCF_Pos)         /*!< 0x00001000 */
#define LPTIM_ICR_CC1OCF                    LPTIM_ICR_CC1OCF_Msk                    /*!< Capture/Compare 1 over-capture clear flag */
#define LPTIM_ICR_CC2OCF_Pos                (13U)
#define LPTIM_ICR_CC2OCF_Msk                (0x1UL << LPTIM_ICR_CC2OCF_Pos)         /*!< 0x00002000 */
#define LPTIM_ICR_CC2OCF                    LPTIM_ICR_CC2OCF_Msk                    /*!< Capture/Compare 2 over-capture clear flag */
#define LPTIM_ICR_CMP2OKCF_Pos              (19U)
#define LPTIM_ICR_CMP2OKCF_Msk              (0x1UL << LPTIM_ICR_CMP2OKCF_Pos)       /*!< 0x00080000 */
#define LPTIM_ICR_CMP2OKCF                  LPTIM_ICR_CMP2OKCF_Msk                  /*!< Compare register 2 update OK clear flag */
#define LPTIM_ICR_DIEROKCF_Pos              (24U)
#define LPTIM_ICR_DIEROKCF_Msk              (0x1UL << LPTIM_ICR_DIEROKCF_Pos)       /*!< 0x01000000 */
#define LPTIM_ICR_DIEROKCF                  LPTIM_ICR_DIEROKCF_Msk                  /*!< DMA & interrupt enable update OK clear flag */

/******************  Bit definition for LPTIM_DIER register *******************/
#define LPTIM_DIER_CC1IE_Pos                (0U)
#define LPTIM_DIER_CC1IE_Msk                (0x1UL << LPTIM_DIER_CC1IE_Pos)         /*!< 0x00000001 */
#define LPTIM_DIER_CC1IE                    LPTIM_DIER_CC1IE_Msk                    /*!< Compare/Compare interrupt enable */
#define LPTIM_DIER_ARRMIE_Pos               (1U)
#define LPTIM_DIER_ARRMIE_Msk               (0x1UL << LPTIM_DIER_ARRMIE_Pos)        /*!< 0x00000002 */
#define LPTIM_DIER_ARRMIE                   LPTIM_DIER_ARRMIE_Msk                   /*!< Autoreload match interrupt enable */
#define LPTIM_DIER_EXTTRIGIE_Pos            (2U)
#define LPTIM_DIER_EXTTRIGIE_Msk            (0x1UL << LPTIM_DIER_EXTTRIGIE_Pos)     /*!< 0x00000004 */
#define LPTIM_DIER_EXTTRIGIE                LPTIM_DIER_EXTTRIGIE_Msk                /*!< External trigger edge event interrupt enable */
#define LPTIM_DIER_CMP1OKIE_Pos             (3U)
#define LPTIM_DIER_CMP1OKIE_Msk             (0x1UL << LPTIM_DIER_CMP1OKIE_Pos)      /*!< 0x00000008 */
#define LPTIM_DIER_CMP1OKIE                 LPTIM_DIER_CMP1OKIE_Msk                 /*!< Compare register 1 update OK interrupt enable */
#define LPTIM_DIER_ARROKIE_Pos              (4U)
#define LPTIM_DIER_ARROKIE_Msk              (0x1UL << LPTIM_DIER_ARROKIE_Pos)       /*!< 0x00000010 */
#define LPTIM_DIER_ARROKIE                  LPTIM_DIER_ARROKIE_Msk                  /*!< Autoreload register update OK interrupt enable */
#define LPTIM_DIER_UPIE_Pos                 (5U)
#define LPTIM_DIER_UPIE_Msk                 (0x1UL << LPTIM_DIER_UPIE_Pos)          /*!< 0x00000020 */
#define LPTIM_DIER_UPIE                     LPTIM_DIER_UPIE_Msk                     /*!< Counter direction change down to up interrupt enable */
#define LPTIM_DIER_DOWNIE_Pos               (6U)
#define LPTIM_DIER_DOWNIE_Msk               (0x1UL << LPTIM_DIER_DOWNIE_Pos)        /*!< 0x00000040 */
#define LPTIM_DIER_DOWNIE                   LPTIM_DIER_DOWNIE_Msk                   /*!< Counter direction change up to down interrupt enable */
#define LPTIM_DIER_UEIE_Pos                 (7U)
#define LPTIM_DIER_UEIE_Msk                 (0x1UL << LPTIM_DIER_UEIE_Pos)          /*!< 0x00000080 */
#define LPTIM_DIER_UEIE                     LPTIM_DIER_UEIE_Msk                     /*!< Update event interrupt enable */
#define LPTIM_DIER_REPOKIE_Pos              (8U)
#define LPTIM_DIER_REPOKIE_Msk              (0x1UL << LPTIM_DIER_REPOKIE_Pos)       /*!< 0x00000100 */
#define LPTIM_DIER_REPOKIE                  LPTIM_DIER_REPOKIE_Msk                  /*!< Repetition register update OK interrupt enable */
#define LPTIM_DIER_CC2IE_Pos                (9U)
#define LPTIM_DIER_CC2IE_Msk                (0x1UL << LPTIM_DIER_CC2IE_Pos)         /*!< 0x00000200 */
#define LPTIM_DIER_CC2IE                    LPTIM_DIER_CC2IE_Msk                    /*!< Capture/Compare 2 interrupt interrupt enable */
#define LPTIM_DIER_CC1OIE_Pos               (12U)
#define LPTIM_DIER_CC1OIE_Msk               (0x1UL << LPTIM_DIER_CC1OIE_Pos)        /*!< 0x00001000 */
#define LPTIM_DIER_CC1OIE                   LPTIM_DIER_CC1OIE_Msk                   /*!< Capture/Compare 1 over-capture interrupt enable */
#define LPTIM_DIER_CC2OIE_Pos               (13U)
#define LPTIM_DIER_CC2OIE_Msk               (0x1UL << LPTIM_DIER_CC2OIE_Pos)        /*!< 0x00002000 */
#define LPTIM_DIER_CC2OIE                   LPTIM_DIER_CC2OIE_Msk                   /*!< Capture/Compare 2 over-capture interrupt enable */
#define LPTIM_DIER_CC1DE_Pos                (16U)
#define LPTIM_DIER_CC1DE_Msk                (0x1UL << LPTIM_DIER_CC1DE_Pos)         /*!< 0x00010000 */
#define LPTIM_DIER_CC1DE                    LPTIM_DIER_CC1DE_Msk                    /*!< Capture/Compare 1 DMA request enable */
#define LPTIM_DIER_CMP2OKIE_Pos             (19U)
#define LPTIM_DIER_CMP2OKIE_Msk             (0x1UL << LPTIM_DIER_CMP2OKIE_Pos)      /*!< 0x00080000 */
#define LPTIM_DIER_CMP2OKIE                 LPTIM_DIER_CMP2OKIE_Msk                 /*!< Compare register 2 update OK interrupt enable */
#define LPTIM_DIER_UEDE_Pos                 (23U)
#define LPTIM_DIER_UEDE_Msk                 (0x1UL << LPTIM_DIER_UEDE_Pos)          /*!< 0x00800000 */
#define LPTIM_DIER_UEDE                     LPTIM_DIER_UEDE_Msk                     /*!< Update event DMA request enable */
#define LPTIM_DIER_CC2DE_Pos                (25U)
#define LPTIM_DIER_CC2DE_Msk                (0x1UL << LPTIM_DIER_CC2DE_Pos)         /*!< 0x02000000 */
#define LPTIM_DIER_CC2DE                    LPTIM_DIER_CC2DE_Msk                    /*!< Capture/Compare 2 DMA request enable */

/******************  Bit definition for LPTIM_CFGR register *******************/
#define LPTIM_CFGR_CKSEL_Pos                (0U)
#define LPTIM_CFGR_CKSEL_Msk                (0x1UL << LPTIM_CFGR_CKSEL_Pos)         /*!< 0x00000001 */
#define LPTIM_CFGR_CKSEL                    LPTIM_CFGR_CKSEL_Msk                    /*!< Clock selector */
#define LPTIM_CFGR_CKPOL_Pos                (1U)
#define LPTIM_CFGR_CKPOL_Msk                (0x3UL << LPTIM_CFGR_CKPOL_Pos)         /*!< 0x00000006 */
#define LPTIM_CFGR_CKPOL                    LPTIM_CFGR_CKPOL_Msk                    /*!< CKPOL[1:0] bits (Clock polarity) */
#define LPTIM_CFGR_CKPOL_0                  (0x1UL << LPTIM_CFGR_CKPOL_Pos)         /*!< 0x00000002 */
#define LPTIM_CFGR_CKPOL_1                  (0x2UL << LPTIM_CFGR_CKPOL_Pos)         /*!< 0x00000004 */
#define LPTIM_CFGR_CKFLT_Pos                (3U)
#define LPTIM_CFGR_CKFLT_Msk                (0x3UL << LPTIM_CFGR_CKFLT_Pos)         /*!< 0x00000018 */
#define LPTIM_CFGR_CKFLT                    LPTIM_CFGR_CKFLT_Msk                    /*!< CKFLT[1:0] bits (Configurable digital filter for external clock) */
#define LPTIM_CFGR_CKFLT_0                  (0x1UL << LPTIM_CFGR_CKFLT_Pos)         /*!< 0x00000008 */
#define LPTIM_CFGR_CKFLT_1                  (0x2UL << LPTIM_CFGR_CKFLT_Pos)         /*!< 0x00000010 */
#define LPTIM_CFGR_TRGFLT_Pos               (6U)
#define LPTIM_CFGR_TRGFLT_Msk               (0x3UL << LPTIM_CFGR_TRGFLT_Pos)        /*!< 0x000000C0 */
#define LPTIM_CFGR_TRGFLT                   LPTIM_CFGR_TRGFLT_Msk                   /*!< TRGFLT[1:0] bits (Configurable digital filter for trigger) */
#define LPTIM_CFGR_TRGFLT_0                 (0x1UL << LPTIM_CFGR_TRGFLT_Pos)        /*!< 0x00000040 */
#define LPTIM_CFGR_TRGFLT_1                 (0x2UL << LPTIM_CFGR_TRGFLT_Pos)        /*!< 0x00000080 */
#define LPTIM_CFGR_PRESC_Pos                (9U)
#define LPTIM_CFGR_PRESC_Msk                (0x7UL << LPTIM_CFGR_PRESC_Pos)         /*!< 0x00000E00 */
#define LPTIM_CFGR_PRESC                    LPTIM_CFGR_PRESC_Msk                    /*!< PRESC[2:0] bits (Clock prescaler) */
#define LPTIM_CFGR_PRESC_0                  (0x1UL << LPTIM_CFGR_PRESC_Pos)         /*!< 0x00000200 */
#define LPTIM_CFGR_PRESC_1                  (0x2UL << LPTIM_CFGR_PRESC_Pos)         /*!< 0x00000400 */
#define LPTIM_CFGR_PRESC_2                  (0x4UL << LPTIM_CFGR_PRESC_Pos)         /*!< 0x00000800 */
#define LPTIM_CFGR_TRIGSEL_Pos              (13U)
#define LPTIM_CFGR_TRIGSEL_Msk              (0x7UL << LPTIM_CFGR_TRIGSEL_Pos)       /*!< 0x0000E000 */
#define LPTIM_CFGR_TRIGSEL                  LPTIM_CFGR_TRIGSEL_Msk                  /*!< TRIGSEL[2:0]] bits (Trigger selector) */
#define LPTIM_CFGR_TRIGSEL_0                (0x1UL << LPTIM_CFGR_TRIGSEL_Pos)       /*!< 0x00002000 */
#define LPTIM_CFGR_TRIGSEL_1                (0x2UL << LPTIM_CFGR_TRIGSEL_Pos)       /*!< 0x00004000 */
#define LPTIM_CFGR_TRIGSEL_2                (0x4UL << LPTIM_CFGR_TRIGSEL_Pos)       /*!< 0x00008000 */
#define LPTIM_CFGR_TRIGEN_Pos               (17U)
#define LPTIM_CFGR_TRIGEN_Msk               (0x3UL << LPTIM_CFGR_TRIGEN_Pos)        /*!< 0x00060000 */
#define LPTIM_CFGR_TRIGEN                   LPTIM_CFGR_TRIGEN_Msk                   /*!< TRIGEN[1:0] bits (Trigger enable and polarity) */
#define LPTIM_CFGR_TRIGEN_0                 (0x1UL << LPTIM_CFGR_TRIGEN_Pos)        /*!< 0x00020000 */
#define LPTIM_CFGR_TRIGEN_1                 (0x2UL << LPTIM_CFGR_TRIGEN_Pos)        /*!< 0x00040000 */
#define LPTIM_CFGR_TIMOUT_Pos               (19U)
#define LPTIM_CFGR_TIMOUT_Msk               (0x1UL << LPTIM_CFGR_TIMOUT_Pos)        /*!< 0x00080000 */
#define LPTIM_CFGR_TIMOUT                   LPTIM_CFGR_TIMOUT_Msk                   /*!< Timout enable */
#define LPTIM_CFGR_WAVE_Pos                 (20U)
#define LPTIM_CFGR_WAVE_Msk                 (0x1UL << LPTIM_CFGR_WAVE_Pos)          /*!< 0x00100000 */
#define LPTIM_CFGR_WAVE                     LPTIM_CFGR_WAVE_Msk                     /*!< Waveform shape */
#define LPTIM_CFGR_PRELOAD_Pos              (22U)
#define LPTIM_CFGR_PRELOAD_Msk              (0x1UL << LPTIM_CFGR_PRELOAD_Pos)       /*!< 0x00400000 */
#define LPTIM_CFGR_PRELOAD                  LPTIM_CFGR_PRELOAD_Msk                  /*!< Reg update mode */
#define LPTIM_CFGR_COUNTMODE_Pos            (23U)
#define LPTIM_CFGR_COUNTMODE_Msk            (0x1UL << LPTIM_CFGR_COUNTMODE_Pos)     /*!< 0x00800000 */
#define LPTIM_CFGR_COUNTMODE                LPTIM_CFGR_COUNTMODE_Msk                /*!< Counter mode enable */
#define LPTIM_CFGR_ENC_Pos                  (24U)
#define LPTIM_CFGR_ENC_Msk                  (0x1UL << LPTIM_CFGR_ENC_Pos)           /*!< 0x01000000 */
#define LPTIM_CFGR_ENC                      LPTIM_CFGR_ENC_Msk                      /*!< Encoder mode enable */

/******************  Bit definition for LPTIM_CR register  ********************/
#define LPTIM_CR_ENABLE_Pos                 (0U)
#define LPTIM_CR_ENABLE_Msk                 (0x1UL << LPTIM_CR_ENABLE_Pos)          /*!< 0x00000001 */
#define LPTIM_CR_ENABLE                     LPTIM_CR_ENABLE_Msk                     /*!< LPTIMer enable */
#define LPTIM_CR_SNGSTRT_Pos                (1U)
#define LPTIM_CR_SNGSTRT_Msk                (0x1UL << LPTIM_CR_SNGSTRT_Pos)         /*!< 0x00000002 */
#define LPTIM_CR_SNGSTRT                    LPTIM_CR_SNGSTRT_Msk                    /*!< Timer start in single mode */
#define LPTIM_CR_CNTSTRT_Pos                (2U)
#define LPTIM_CR_CNTSTRT_Msk                (0x1UL << LPTIM_CR_CNTSTRT_Pos)         /*!< 0x00000004 */
#define LPTIM_CR_CNTSTRT                    LPTIM_CR_CNTSTRT_Msk                    /*!< Timer start in continuous mode */
#define LPTIM_CR_COUNTRST_Pos               (3U)
#define LPTIM_CR_COUNTRST_Msk               (0x1UL << LPTIM_CR_COUNTRST_Pos)        /*!< 0x00000008 */
#define LPTIM_CR_COUNTRST                   LPTIM_CR_COUNTRST_Msk                   /*!< Timer Counter reset in synchronous mode*/
#define LPTIM_CR_RSTARE_Pos                 (4U)
#define LPTIM_CR_RSTARE_Msk                 (0x1UL << LPTIM_CR_RSTARE_Pos)          /*!< 0x00000010 */
#define LPTIM_CR_RSTARE                     LPTIM_CR_RSTARE_Msk                     /*!< Timer Counter reset after read enable (asynchronously)*/


/******************  Bit definition for LPTIM_CCR1 register  ******************/
#define LPTIM_CCR1_CCR1_Pos                 (0U)
#define LPTIM_CCR1_CCR1_Msk                 (0xFFFFUL << LPTIM_CCR1_CCR1_Pos)       /*!< 0x0000FFFF */
#define LPTIM_CCR1_CCR1                     LPTIM_CCR1_CCR1_Msk                     /*!< Compare register 1 */

/******************  Bit definition for LPTIM_ARR register  *******************/
#define LPTIM_ARR_ARR_Pos                   (0U)
#define LPTIM_ARR_ARR_Msk                   (0xFFFFUL << LPTIM_ARR_ARR_Pos)         /*!< 0x0000FFFF */
#define LPTIM_ARR_ARR                       LPTIM_ARR_ARR_Msk                       /*!< Auto reload register */

/******************  Bit definition for LPTIM_CNT register  *******************/
#define LPTIM_CNT_CNT_Pos                   (0U)
#define LPTIM_CNT_CNT_Msk                   (0xFFFFUL << LPTIM_CNT_CNT_Pos)         /*!< 0x0000FFFF */
#define LPTIM_CNT_CNT                       LPTIM_CNT_CNT_Msk                       /*!< Counter register */

/******************  Bit definition for LPTIM_CFGR2 register  *****************/
#define LPTIM_CFGR2_IN1SEL_Pos              (0U)
#define LPTIM_CFGR2_IN1SEL_Msk              (0x3UL << LPTIM_CFGR2_IN1SEL_Pos)       /*!< 0x00000003 */
#define LPTIM_CFGR2_IN1SEL                  LPTIM_CFGR2_IN1SEL_Msk                  /*!< IN1SEL[1:0] bits (Remap selection) */
#define LPTIM_CFGR2_IN1SEL_0                (0x1UL << LPTIM_CFGR2_IN1SEL_Pos)       /*!< 0x00000001 */
#define LPTIM_CFGR2_IN1SEL_1                (0x2UL << LPTIM_CFGR2_IN1SEL_Pos)       /*!< 0x00000002 */
#define LPTIM_CFGR2_IN2SEL_Pos              (4U)
#define LPTIM_CFGR2_IN2SEL_Msk              (0x3UL << LPTIM_CFGR2_IN2SEL_Pos)       /*!< 0x00000030 */
#define LPTIM_CFGR2_IN2SEL                  LPTIM_CFGR2_IN2SEL_Msk                  /*!< IN2SEL[5:4] bits (Remap selection) */
#define LPTIM_CFGR2_IN2SEL_0                (0x1UL << LPTIM_CFGR2_IN2SEL_Pos)       /*!< 0x00000010 */
#define LPTIM_CFGR2_IN2SEL_1                (0x2UL << LPTIM_CFGR2_IN2SEL_Pos)       /*!< 0x00000020 */
#define LPTIM_CFGR2_IC1SEL_Pos              (16U)
#define LPTIM_CFGR2_IC1SEL_Msk              (0x3UL << LPTIM_CFGR2_IC1SEL_Pos)       /*!< 0x00000003 */
#define LPTIM_CFGR2_IC1SEL                  LPTIM_CFGR2_IC1SEL_Msk                  /*!< IC1SEL[17:16] bits */
#define LPTIM_CFGR2_IC1SEL_0                (0x1UL << LPTIM_CFGR2_IC1SEL_Pos)       /*!< 0x00010000 */
#define LPTIM_CFGR2_IC1SEL_1                (0x2UL << LPTIM_CFGR2_IC1SEL_Pos)       /*!< 0x00020000 */
#define LPTIM_CFGR2_IC2SEL_Pos              (20U)
#define LPTIM_CFGR2_IC2SEL_Msk              (0x3UL << LPTIM_CFGR2_IC2SEL_Pos)       /*!< 0x00000030 */
#define LPTIM_CFGR2_IC2SEL                  LPTIM_CFGR2_IC2SEL_Msk                  /*!< IC2SEL[21:20] bits */
#define LPTIM_CFGR2_IC2SEL_0                (0x1UL << LPTIM_CFGR2_IC2SEL_Pos)       /*!< 0x00100000 */
#define LPTIM_CFGR2_IC2SEL_1                (0x2UL << LPTIM_CFGR2_IC2SEL_Pos)       /*!< 0x00200000 */

/******************  Bit definition for LPTIM_RCR register  *******************/
#define LPTIM_RCR_REP_Pos                   (0U)
#define LPTIM_RCR_REP_Msk                   (0xFFUL << LPTIM_RCR_REP_Pos)           /*!< 0x000000FF */
#define LPTIM_RCR_REP                       LPTIM_RCR_REP_Msk                       /*!< Repetition register value */

/*****************  Bit definition for LPTIM_CCMR1 register  ******************/
#define LPTIM_CCMR1_CC1SEL_Pos              (0U)
#define LPTIM_CCMR1_CC1SEL_Msk              (0x1UL << LPTIM_CCMR1_CC1SEL_Pos)       /*!< 0x00000001 */
#define LPTIM_CCMR1_CC1SEL                  LPTIM_CCMR1_CC1SEL_Msk                  /*!< Capture/Compare 1 selection */
#define LPTIM_CCMR1_CC1E_Pos                (1U)
#define LPTIM_CCMR1_CC1E_Msk                (0x1UL << LPTIM_CCMR1_CC1E_Pos)         /*!< 0x00000002 */
#define LPTIM_CCMR1_CC1E                    LPTIM_CCMR1_CC1E_Msk                    /*!< Capture/Compare 1 output enable */
#define LPTIM_CCMR1_CC1P_Pos                (2U)
#define LPTIM_CCMR1_CC1P_Msk                (0x3UL << LPTIM_CCMR1_CC1P_Pos)         /*!< 0x0000000C */
#define LPTIM_CCMR1_CC1P                    LPTIM_CCMR1_CC1P_Msk                    /*!< Capture/Compare 1 output polarity */
#define LPTIM_CCMR1_CC1P_0                  (0x1UL << LPTIM_CCMR1_CC1P_Pos)         /*!< 0x00000004 */
#define LPTIM_CCMR1_CC1P_1                  (0x2UL << LPTIM_CCMR1_CC1P_Pos)         /*!< 0x00000008 */
#define LPTIM_CCMR1_IC1PSC_Pos              (8U)
#define LPTIM_CCMR1_IC1PSC_Msk              (0x3UL << LPTIM_CCMR1_IC1PSC_Pos)       /*!< 0x00000300 */
#define LPTIM_CCMR1_IC1PSC                  LPTIM_CCMR1_IC1PSC_Msk                  /*!< Input capture 1 prescaler */
#define LPTIM_CCMR1_IC1PSC_0                (0x1UL << LPTIM_CCMR1_IC1PSC_Pos)       /*!< 0x00000100 */
#define LPTIM_CCMR1_IC1PSC_1                (0x2UL << LPTIM_CCMR1_IC1PSC_Pos)       /*!< 0x00000200 */
#define LPTIM_CCMR1_IC1F_Pos                (12U)
#define LPTIM_CCMR1_IC1F_Msk                (0x3UL << LPTIM_CCMR1_IC1F_Pos)         /*!< 0x00003000 */
#define LPTIM_CCMR1_IC1F                    LPTIM_CCMR1_IC1F_Msk                    /*!< Input capture 1 filter */
#define LPTIM_CCMR1_IC1F_0                  (0x1UL << LPTIM_CCMR1_IC1F_Pos)         /*!< 0x00001000 */
#define LPTIM_CCMR1_IC1F_1                  (0x2UL << LPTIM_CCMR1_IC1F_Pos)         /*!< 0x00002000 */
#define LPTIM_CCMR1_CC2SEL_Pos              (16U)
#define LPTIM_CCMR1_CC2SEL_Msk              (0x1UL << LPTIM_CCMR1_CC2SEL_Pos)       /*!< 0x00010000 */
#define LPTIM_CCMR1_CC2SEL                  LPTIM_CCMR1_CC2SEL_Msk                  /*!< Capture/Compare 2 selection */
#define LPTIM_CCMR1_CC2E_Pos                (17U)
#define LPTIM_CCMR1_CC2E_Msk                (0x1UL << LPTIM_CCMR1_CC2E_Pos)         /*!< 0x00020000 */
#define LPTIM_CCMR1_CC2E                    LPTIM_CCMR1_CC2E_Msk                    /*!< Capture/Compare 2 output enable */
#define LPTIM_CCMR1_CC2P_Pos                (18U)
#define LPTIM_CCMR1_CC2P_Msk                (0x3UL << LPTIM_CCMR1_CC2P_Pos)         /*!< 0x000C0000 */
#define LPTIM_CCMR1_CC2P                    LPTIM_CCMR1_CC2P_Msk                    /*!< Capture/Compare 2 output polarity */
#define LPTIM_CCMR1_CC2P_0                  (0x1UL << LPTIM_CCMR1_CC2P_Pos)         /*!< 0x00040000 */
#define LPTIM_CCMR1_CC2P_1                  (0x2UL << LPTIM_CCMR1_CC2P_Pos)         /*!< 0x00080000 */
#define LPTIM_CCMR1_IC2PSC_Pos              (24U)
#define LPTIM_CCMR1_IC2PSC_Msk              (0x3UL << LPTIM_CCMR1_IC2PSC_Pos)       /*!< 0x03000000 */
#define LPTIM_CCMR1_IC2PSC                  LPTIM_CCMR1_IC2PSC_Msk                  /*!< Input capture 2 prescaler */
#define LPTIM_CCMR1_IC2PSC_0                (0x1UL << LPTIM_CCMR1_IC2PSC_Pos)       /*!< 0x01000000 */
#define LPTIM_CCMR1_IC2PSC_1                (0x2UL << LPTIM_CCMR1_IC2PSC_Pos)       /*!< 0x02000000 */
#define LPTIM_CCMR1_IC2F_Pos                (28U)
#define LPTIM_CCMR1_IC2F_Msk                (0x3UL << LPTIM_CCMR1_IC2F_Pos)         /*!< 0x30000000 */
#define LPTIM_CCMR1_IC2F                    LPTIM_CCMR1_IC2F_Msk                    /*!< Input capture 2 filter */
#define LPTIM_CCMR1_IC2F_0                  (0x1UL << LPTIM_CCMR1_IC2F_Pos)         /*!< 0x10000000 */
#define LPTIM_CCMR1_IC2F_1                  (0x2UL << LPTIM_CCMR1_IC2F_Pos)         /*!< 0x20000000 */

/******************  Bit definition for LPTIM_CCR2 register  ******************/
#define LPTIM_CCR2_CCR2_Pos                 (0U)
#define LPTIM_CCR2_CCR2_Msk                 (0xFFFFUL << LPTIM_CCR2_CCR2_Pos)       /*!< 0x0000FFFF */
#define LPTIM_CCR2_CCR2                     LPTIM_CCR2_CCR2_Msk                     /*!< Compare register 2 */


/******************************************************************************/
/*                                                                            */
/*                       Public Key Accelerator (PKA)                         */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for PKA_CR register  *********************/
#define PKA_CR_EN_Pos                       (0U)
#define PKA_CR_EN_Msk                       (0x1UL << PKA_CR_EN_Pos)                /*!< 0x00000001 */
#define PKA_CR_EN                           PKA_CR_EN_Msk                           /*!< PKA enable */
#define PKA_CR_START_Pos                    (1U)
#define PKA_CR_START_Msk                    (0x1UL << PKA_CR_START_Pos)             /*!< 0x00000002 */
#define PKA_CR_START                        PKA_CR_START_Msk                        /*!< Start operation */
#define PKA_CR_MODE_Pos                     (8U)
#define PKA_CR_MODE_Msk                     (0x3FUL << PKA_CR_MODE_Pos)             /*!< 0x00003F00 */
#define PKA_CR_MODE                         PKA_CR_MODE_Msk                         /*!< MODE[5:0] PKA operation code */
#define PKA_CR_MODE_0                       (0x01UL << PKA_CR_MODE_Pos)             /*!< 0x00000100 */
#define PKA_CR_MODE_1                       (0x02UL << PKA_CR_MODE_Pos)             /*!< 0x00000200 */
#define PKA_CR_MODE_2                       (0x04UL << PKA_CR_MODE_Pos)             /*!< 0x00000400 */
#define PKA_CR_MODE_3                       (0x08UL << PKA_CR_MODE_Pos)             /*!< 0x00000800 */
#define PKA_CR_MODE_4                       (0x10UL << PKA_CR_MODE_Pos)             /*!< 0x00001000 */
#define PKA_CR_MODE_5                       (0x20UL << PKA_CR_MODE_Pos)             /*!< 0x00002000 */
#define PKA_CR_PROCENDIE_Pos                (17U)
#define PKA_CR_PROCENDIE_Msk                (0x1UL << PKA_CR_PROCENDIE_Pos)         /*!< 0x00020000 */
#define PKA_CR_PROCENDIE                    PKA_CR_PROCENDIE_Msk                    /*!< End of operation interrupt enable */
#define PKA_CR_RAMERRIE_Pos                 (19U)
#define PKA_CR_RAMERRIE_Msk                 (0x1UL << PKA_CR_RAMERRIE_Pos)          /*!< 0x00080000 */
#define PKA_CR_RAMERRIE                     PKA_CR_RAMERRIE_Msk                     /*!< RAM error interrupt enable */
#define PKA_CR_ADDRERRIE_Pos                (20U)
#define PKA_CR_ADDRERRIE_Msk                (0x1UL << PKA_CR_ADDRERRIE_Pos)         /*!< 0x00100000 */
#define PKA_CR_ADDRERRIE                    PKA_CR_ADDRERRIE_Msk                    /*!< Address error interrupt enable */
#define PKA_CR_OPERRIE_Pos                  (21U)
#define PKA_CR_OPERRIE_Msk                  (0x1UL << PKA_CR_OPERRIE_Pos)           /*!< 0x00200000 */
#define PKA_CR_OPERRIE                      PKA_CR_OPERRIE_Msk                      /*!< Operation Error interrupt enable */

/*******************  Bit definition for PKA_SR register  *********************/
#define PKA_SR_INITOK_Pos                   (0U)
#define PKA_SR_INITOK_Msk                   (0x1UL << PKA_SR_INITOK_Pos)            /*!< 0x00000001 */
#define PKA_SR_INITOK                       PKA_SR_INITOK_Msk                       /*!< PKA initialisation flag */
#define PKA_SR_BUSY_Pos                     (16U)
#define PKA_SR_BUSY_Msk                     (0x1UL << PKA_SR_BUSY_Pos)              /*!< 0x00010000 */
#define PKA_SR_BUSY                         PKA_SR_BUSY_Msk                         /*!< PKA operation is in progress */
#define PKA_SR_PROCENDF_Pos                 (17U)
#define PKA_SR_PROCENDF_Msk                 (0x1UL << PKA_SR_PROCENDF_Pos)          /*!< 0x00020000 */
#define PKA_SR_PROCENDF                     PKA_SR_PROCENDF_Msk                     /*!< PKA end of operation flag */
#define PKA_SR_RAMERRF_Pos                  (19U)
#define PKA_SR_RAMERRF_Msk                  (0x1UL << PKA_SR_RAMERRF_Pos)           /*!< 0x00080000 */
#define PKA_SR_RAMERRF                      PKA_SR_RAMERRF_Msk                      /*!< PKA RAM error flag */
#define PKA_SR_ADDRERRF_Pos                 (20U)
#define PKA_SR_ADDRERRF_Msk                 (0x1UL << PKA_SR_ADDRERRF_Pos)          /*!< 0x00100000 */
#define PKA_SR_ADDRERRF                     PKA_SR_ADDRERRF_Msk                     /*!< Address error flag */
#define PKA_SR_OPERRF_Pos                   (21U)
#define PKA_SR_OPERRF_Msk                   (0x1UL << PKA_SR_OPERRF_Pos)            /*!< 0x00200000 */
#define PKA_SR_OPERRF                       PKA_SR_OPERRF_Msk                       /*!< PKA operation Error flag*/

/*******************  Bit definition for PKA_CLRFR register  ******************/
#define PKA_CLRFR_PROCENDFC_Pos             (17U)
#define PKA_CLRFR_PROCENDFC_Msk             (0x1UL << PKA_CLRFR_PROCENDFC_Pos)      /*!< 0x00020000 */
#define PKA_CLRFR_PROCENDFC                 PKA_CLRFR_PROCENDFC_Msk                 /*!< Clear PKA end of operation flag */
#define PKA_CLRFR_RAMERRFC_Pos              (19U)
#define PKA_CLRFR_RAMERRFC_Msk              (0x1UL << PKA_CLRFR_RAMERRFC_Pos)       /*!< 0x00080000 */
#define PKA_CLRFR_RAMERRFC                  PKA_CLRFR_RAMERRFC_Msk                  /*!< Clear PKA RAM error flag */
#define PKA_CLRFR_ADDRERRFC_Pos             (20U)
#define PKA_CLRFR_ADDRERRFC_Msk             (0x1UL << PKA_CLRFR_ADDRERRFC_Pos)      /*!< 0x00100000 */
#define PKA_CLRFR_ADDRERRFC                 PKA_CLRFR_ADDRERRFC_Msk                 /*!< Clear address error flag */
#define PKA_CLRFR_OPERRFC_Pos               (21U)
#define PKA_CLRFR_OPERRFC_Msk               (0x1UL << PKA_CLRFR_OPERRFC_Pos)        /*!< 0x00200000 */
#define PKA_CLRFR_OPERRFC                   PKA_CLRFR_OPERRFC_Msk                   /*!< Clear PKA operation Error flag*/

/*******************  Bits definition for PKA RAM  *************************/
#define PKA_RAM_OFFSET                                 (0x0400UL)                          /*!< PKA RAM address offset */

/* Compute Montgomery parameter input data */
#define PKA_MONTGOMERY_PARAM_IN_MOD_NB_BITS            ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus number of bits */
#define PKA_MONTGOMERY_PARAM_IN_MODULUS                ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus */

/* Compute Montgomery parameter output data */
#define PKA_MONTGOMERY_PARAM_OUT_PARAMETER             ((0x0620UL - PKA_RAM_OFFSET)>>2)    /*!< Output Montgomery parameter */

/* Compute modular exponentiation input data */
#define PKA_MODULAR_EXP_IN_EXP_NB_BITS                 ((0x0400UL - PKA_RAM_OFFSET)>>2)    /*!< Input exponent number of bits */
#define PKA_MODULAR_EXP_IN_OP_NB_BITS                  ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_MODULAR_EXP_IN_MONTGOMERY_PARAM            ((0x0620UL - PKA_RAM_OFFSET)>>2)    /*!< Input storage area for Montgomery parameter */
#define PKA_MODULAR_EXP_IN_EXPONENT_BASE               ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input base of the exponentiation */
#define PKA_MODULAR_EXP_IN_EXPONENT                    ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Input exponent to process */
#define PKA_MODULAR_EXP_IN_MODULUS                     ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus */
#define PKA_MODULAR_EXP_PROTECT_IN_EXPONENT_BASE       ((0x16C8UL - PKA_RAM_OFFSET)>>2)    /*!< Input base of the protected exponentiation */
#define PKA_MODULAR_EXP_PROTECT_IN_EXPONENT            ((0x14B8UL - PKA_RAM_OFFSET)>>2)    /*!< Input exponent to process protected exponentiation*/
#define PKA_MODULAR_EXP_PROTECT_IN_MODULUS             ((0x0838UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus to process protected exponentiation */
#define PKA_MODULAR_EXP_PROTECT_IN_PHI                 ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input phi to process protected exponentiation */

/* Compute modular exponentiation output data */
#define PKA_MODULAR_EXP_OUT_RESULT                     ((0x0838UL - PKA_RAM_OFFSET)>>2)    /*!< Output result of the exponentiation */
#define PKA_MODULAR_EXP_OUT_ERROR                      ((0x1298UL - PKA_RAM_OFFSET)>>2)    /*!< Output error of the exponentiation */
#define PKA_MODULAR_EXP_OUT_MONTGOMERY_PARAM           ((0x0620UL - PKA_RAM_OFFSET)>>2)    /*!< Output storage area for Montgomery parameter */
#define PKA_MODULAR_EXP_OUT_EXPONENT_BASE              ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Output base of the exponentiation */

/* Compute ECC scalar multiplication input data */
#define PKA_ECC_SCALAR_MUL_IN_EXP_NB_BITS              ((0x0400UL - PKA_RAM_OFFSET)>>2)    /*!< Input curve prime order n number of bits */
#define PKA_ECC_SCALAR_MUL_IN_OP_NB_BITS               ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus number of bits */
#define PKA_ECC_SCALAR_MUL_IN_A_COEFF_SIGN             ((0x0410UL - PKA_RAM_OFFSET)>>2)    /*!< Input sign of the 'a' coefficient */
#define PKA_ECC_SCALAR_MUL_IN_A_COEFF                  ((0x0418UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'a' coefficient */
#define PKA_ECC_SCALAR_MUL_IN_B_COEFF                  ((0x0520UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'b' coefficient */
#define PKA_ECC_SCALAR_MUL_IN_MOD_GF                   ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_ECC_SCALAR_MUL_IN_K                        ((0x12A0UL - PKA_RAM_OFFSET)>>2)    /*!< Input 'k' of KP */
#define PKA_ECC_SCALAR_MUL_IN_INITIAL_POINT_X          ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P X coordinate */
#define PKA_ECC_SCALAR_MUL_IN_INITIAL_POINT_Y          ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Y coordinate */
#define PKA_ECC_SCALAR_MUL_IN_N_PRIME_ORDER            ((0x0F88UL - PKA_RAM_OFFSET)>>2)    /*!< Input prime order n */

/* Compute ECC scalar multiplication output data */
#define PKA_ECC_SCALAR_MUL_OUT_RESULT_X                ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Output result X coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_RESULT_Y                ((0x05D0UL - PKA_RAM_OFFSET)>>2)    /*!< Output result Y coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_ERROR                   ((0x0680UL - PKA_RAM_OFFSET)>>2)    /*!< Output result error */

/* Point check input data */
#define PKA_POINT_CHECK_IN_MOD_NB_BITS                 ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus number of bits */
#define PKA_POINT_CHECK_IN_A_COEFF_SIGN                ((0x0410UL - PKA_RAM_OFFSET)>>2)    /*!< Input sign of the 'a' coefficient */
#define PKA_POINT_CHECK_IN_A_COEFF                     ((0x0418UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'a' coefficient */
#define PKA_POINT_CHECK_IN_B_COEFF                     ((0x0520UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'b' coefficient */
#define PKA_POINT_CHECK_IN_MOD_GF                      ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_POINT_CHECK_IN_INITIAL_POINT_X             ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P X coordinate */
#define PKA_POINT_CHECK_IN_INITIAL_POINT_Y             ((0x05D0UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Y coordinate */
#define PKA_POINT_CHECK_IN_MONTGOMERY_PARAM            ((0x04C8UL - PKA_RAM_OFFSET)>>2)    /*!< Input storage area for Montgomery parameter */

/* Point check output data */
#define PKA_POINT_CHECK_OUT_ERROR                      ((0x0680UL - PKA_RAM_OFFSET)>>2)    /*!< Output error */

/* ECDSA signature input data */
#define PKA_ECDSA_SIGN_IN_ORDER_NB_BITS                ((0x0400UL - PKA_RAM_OFFSET)>>2)    /*!< Input order number of bits */
#define PKA_ECDSA_SIGN_IN_MOD_NB_BITS                  ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus number of bits */
#define PKA_ECDSA_SIGN_IN_A_COEFF_SIGN                 ((0x0410UL - PKA_RAM_OFFSET)>>2)    /*!< Input sign of the 'a' coefficient */
#define PKA_ECDSA_SIGN_IN_A_COEFF                      ((0x0418UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'a' coefficient */
#define PKA_ECDSA_SIGN_IN_B_COEFF                      ((0x0520UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'b' coefficient */
#define PKA_ECDSA_SIGN_IN_MOD_GF                       ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_ECDSA_SIGN_IN_K                            ((0x12A0UL - PKA_RAM_OFFSET)>>2)    /*!< Input k value of the ECDSA */
#define PKA_ECDSA_SIGN_IN_INITIAL_POINT_X              ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P X coordinate */
#define PKA_ECDSA_SIGN_IN_INITIAL_POINT_Y              ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Y coordinate */
#define PKA_ECDSA_SIGN_IN_HASH_E                       ((0x0FE8UL - PKA_RAM_OFFSET)>>2)    /*!< Input e, hash of the message */
#define PKA_ECDSA_SIGN_IN_PRIVATE_KEY_D                ((0x0F28UL - PKA_RAM_OFFSET)>>2)    /*!< Input d, private key */
#define PKA_ECDSA_SIGN_IN_ORDER_N                      ((0x0F88UL - PKA_RAM_OFFSET)>>2)    /*!< Input n, order of the curve */

/* ECDSA signature output data */
#define PKA_ECDSA_SIGN_OUT_ERROR                       ((0x0FE0UL - PKA_RAM_OFFSET)>>2)    /*!< Output error */
#define PKA_ECDSA_SIGN_OUT_SIGNATURE_R                 ((0x0730UL - PKA_RAM_OFFSET)>>2)    /*!< Output signature r */
#define PKA_ECDSA_SIGN_OUT_SIGNATURE_S                 ((0x0788UL - PKA_RAM_OFFSET)>>2)    /*!< Output signature s */
#define PKA_ECDSA_SIGN_OUT_FINAL_POINT_X               ((0x1400UL - PKA_RAM_OFFSET)>>2)    /*!< Extended output result point X coordinate */
#define PKA_ECDSA_SIGN_OUT_FINAL_POINT_Y               ((0x1458UL - PKA_RAM_OFFSET)>>2)    /*!< Extended output result point Y coordinate */


/* ECDSA verification input data */
#define PKA_ECDSA_VERIF_IN_ORDER_NB_BITS               ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input order number of bits */
#define PKA_ECDSA_VERIF_IN_MOD_NB_BITS                 ((0x04C8UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus number of bits */
#define PKA_ECDSA_VERIF_IN_A_COEFF_SIGN                ((0x0468UL - PKA_RAM_OFFSET)>>2)    /*!< Input sign of the 'a' coefficient */
#define PKA_ECDSA_VERIF_IN_A_COEFF                     ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve 'a' coefficient */
#define PKA_ECDSA_VERIF_IN_MOD_GF                      ((0x04D0UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_ECDSA_VERIF_IN_INITIAL_POINT_X             ((0x0678UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P X coordinate */
#define PKA_ECDSA_VERIF_IN_INITIAL_POINT_Y             ((0x06D0UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Y coordinate */
#define PKA_ECDSA_VERIF_IN_PUBLIC_KEY_POINT_X          ((0x12F8UL - PKA_RAM_OFFSET)>>2)    /*!< Input public key point X coordinate */
#define PKA_ECDSA_VERIF_IN_PUBLIC_KEY_POINT_Y          ((0x1350UL - PKA_RAM_OFFSET)>>2)    /*!< Input public key point Y coordinate */
#define PKA_ECDSA_VERIF_IN_SIGNATURE_R                 ((0x10E0UL - PKA_RAM_OFFSET)>>2)    /*!< Input r, part of the signature */
#define PKA_ECDSA_VERIF_IN_SIGNATURE_S                 ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input s, part of the signature */
#define PKA_ECDSA_VERIF_IN_HASH_E                      ((0x13A8UL - PKA_RAM_OFFSET)>>2)    /*!< Input e, hash of the message */
#define PKA_ECDSA_VERIF_IN_ORDER_N                     ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input n, order of the curve */

/* ECDSA verification output data */
#define PKA_ECDSA_VERIF_OUT_RESULT                     ((0x05D0UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* RSA CRT exponentiation input data */
#define PKA_RSA_CRT_EXP_IN_MOD_NB_BITS                 ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operands number of bits */
#define PKA_RSA_CRT_EXP_IN_DP_CRT                      ((0x0730UL - PKA_RAM_OFFSET)>>2)    /*!< Input Dp CRT parameter */
#define PKA_RSA_CRT_EXP_IN_DQ_CRT                      ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Input Dq CRT parameter */
#define PKA_RSA_CRT_EXP_IN_QINV_CRT                    ((0x0948UL - PKA_RAM_OFFSET)>>2)    /*!< Input qInv CRT parameter */
#define PKA_RSA_CRT_EXP_IN_PRIME_P                     ((0x0B60UL - PKA_RAM_OFFSET)>>2)    /*!< Input Prime p */
#define PKA_RSA_CRT_EXP_IN_PRIME_Q                     ((0x1088UL - PKA_RAM_OFFSET)>>2)    /*!< Input Prime q */
#define PKA_RSA_CRT_EXP_IN_EXPONENT_BASE               ((0x12A0UL - PKA_RAM_OFFSET)>>2)    /*!< Input base of the exponentiation */

/* RSA CRT exponentiation output data */
#define PKA_RSA_CRT_EXP_OUT_RESULT                     ((0x0838UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Modular reduction input data */
#define PKA_MODULAR_REDUC_IN_OP_LENGTH                 ((0x0400UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand length */
#define PKA_MODULAR_REDUC_IN_MOD_LENGTH                ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus length */
#define PKA_MODULAR_REDUC_IN_OPERAND                   ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand */
#define PKA_MODULAR_REDUC_IN_MODULUS                   ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus */

/* Modular reduction output data */
#define PKA_MODULAR_REDUC_OUT_RESULT                   ((0xE78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Arithmetic addition input data */
#define PKA_ARITHMETIC_ADD_IN_OP_NB_BITS               ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_ARITHMETIC_ADD_IN_OP1                      ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_ARITHMETIC_ADD_IN_OP2                      ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */

/* Arithmetic addition output data */
#define PKA_ARITHMETIC_ADD_OUT_RESULT                  ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Arithmetic subtraction input data */
#define PKA_ARITHMETIC_SUB_IN_OP_NB_BITS               ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_ARITHMETIC_SUB_IN_OP1                      ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_ARITHMETIC_SUB_IN_OP2                      ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */

/* Arithmetic subtraction output data */
#define PKA_ARITHMETIC_SUB_OUT_RESULT                  ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Arithmetic multiplication input data */
#define PKA_ARITHMETIC_MUL_NB_BITS                     ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_ARITHMETIC_MUL_IN_OP1                      ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_ARITHMETIC_MUL_IN_OP2                      ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */

/* Arithmetic multiplication output data */
#define PKA_ARITHMETIC_MUL_OUT_RESULT                  ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Comparison input data */
#define PKA_COMPARISON_IN_OP_NB_BITS                   ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_COMPARISON_IN_OP1                          ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_COMPARISON_IN_OP2                          ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */

/* Comparison output data */
#define PKA_COMPARISON_OUT_RESULT                      ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Modular addition input data */
#define PKA_MODULAR_ADD_NB_BITS                        ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_MODULAR_ADD_IN_OP1                         ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_MODULAR_ADD_IN_OP2                         ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */
#define PKA_MODULAR_ADD_IN_OP3_MOD                     ((0x1088UL - PKA_RAM_OFFSET)>>2)   /*!< Input operand op3 (modulus) */

/* Modular addition output data */
#define PKA_MODULAR_ADD_OUT_RESULT                     ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Modular inversion input data */
#define PKA_MODULAR_INV_NB_BITS                        ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_MODULAR_INV_IN_OP1                         ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_MODULAR_INV_IN_OP2_MOD                     ((0x0C68UL - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 (modulus) */

/* Modular inversion output data */
#define PKA_MODULAR_INV_OUT_RESULT                     ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Modular subtraction input data */
#define PKA_MODULAR_SUB_IN_OP_NB_BITS                  ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_MODULAR_SUB_IN_OP1                         ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_MODULAR_SUB_IN_OP2                         ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */
#define PKA_MODULAR_SUB_IN_OP3_MOD                     ((0x1088UL - PKA_RAM_OFFSET)>>2)   /*!< Input operand op3 */

/* Modular subtraction output data */
#define PKA_MODULAR_SUB_OUT_RESULT                     ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Montgomery multiplication input data */
#define PKA_MONTGOMERY_MUL_IN_OP_NB_BITS               ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_MONTGOMERY_MUL_IN_OP1                      ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_MONTGOMERY_MUL_IN_OP2                      ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */
#define PKA_MONTGOMERY_MUL_IN_OP3_MOD                  ((0x1088UL - PKA_RAM_OFFSET)>>2)   /*!< Input modulus */

/* Montgomery multiplication output data */
#define PKA_MONTGOMERY_MUL_OUT_RESULT                  ((0x0E78UL - PKA_RAM_OFFSET)>>2)    /*!< Output result */

/* Generic Arithmetic input data */
#define PKA_ARITHMETIC_ALL_OPS_NB_BITS                 ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand number of bits */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP1                  ((0x0A50UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op1 */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP2                  ((0x0C68UL - PKA_RAM_OFFSET)>>2)    /*!< Input operand op2 */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP3                  ((0x1088UL - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Generic Arithmetic output data */
#define PKA_ARITHMETIC_ALL_OPS_OUT_RESULT              ((0x0E78UL - PKA_RAM_OFFSET)>>2)   /*!< Output result for arithmetic operations */

/* Compute ECC complete addition input data */
#define PKA_ECC_COMPLETE_ADD_IN_MOD_NB_BITS            ((0x0408UL - PKA_RAM_OFFSET)>>2)   /*!< Input Modulus number of bits */
#define PKA_ECC_COMPLETE_ADD_IN_A_COEFF_SIGN           ((0x0410UL - PKA_RAM_OFFSET)>>2)   /*!< Input sign of the 'a' coefficient */
#define PKA_ECC_COMPLETE_ADD_IN_A_COEFF                ((0x0418UL - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve '|a|' coefficient */
#define PKA_ECC_COMPLETE_ADD_IN_MOD_P                  ((0x0470UL - PKA_RAM_OFFSET)>>2)   /*!< Input modulus GF(p) */
#define PKA_ECC_COMPLETE_ADD_IN_POINT1_X               ((0x0628UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P X coordinate */
#define PKA_ECC_COMPLETE_ADD_IN_POINT1_Y               ((0x0680UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Y coordinate */
#define PKA_ECC_COMPLETE_ADD_IN_POINT1_Z               ((0x06D8UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Z coordinate */
#define PKA_ECC_COMPLETE_ADD_IN_POINT2_X               ((0x0730UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point Q X coordinate */
#define PKA_ECC_COMPLETE_ADD_IN_POINT2_Y               ((0x0788UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point Q Y coordinate */
#define PKA_ECC_COMPLETE_ADD_IN_POINT2_Z               ((0x07E0UL - PKA_RAM_OFFSET)>>2)   /*!< Input initial point Q Z coordinate */

/* Compute ECC complete addition output data */
#define PKA_ECC_COMPLETE_ADD_OUT_RESULT_X              ((0x0D60UL - PKA_RAM_OFFSET)>>2)   /*!< Output result X coordinate */
#define PKA_ECC_COMPLETE_ADD_OUT_RESULT_Y              ((0x0DB8UL - PKA_RAM_OFFSET)>>2)   /*!< Output result Y coordinate */
#define PKA_ECC_COMPLETE_ADD_OUT_RESULT_Z              ((0x0E10UL - PKA_RAM_OFFSET)>>2)   /*!< Output result Z coordinate */

/* Compute ECC double base ladder input data */
#define PKA_ECC_DOUBLE_LADDER_IN_PRIME_ORDER_NB_BITS   ((0x0400UL - PKA_RAM_OFFSET)>>2)    /*!< Input n, order of the curve */
#define PKA_ECC_DOUBLE_LADDER_IN_MOD_NB_BITS           ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input Modulus number of bits */
#define PKA_ECC_DOUBLE_LADDER_IN_A_COEFF_SIGN          ((0x0410UL - PKA_RAM_OFFSET)>>2)    /*!< Input sign of the 'a' coefficient */
#define PKA_ECC_DOUBLE_LADDER_IN_A_COEFF               ((0x0418UL - PKA_RAM_OFFSET)>>2)    /*!< Input ECC curve '|a|' coefficient */
#define PKA_ECC_DOUBLE_LADDER_IN_MOD_P                 ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_ECC_DOUBLE_LADDER_IN_K_INTEGER             ((0x0520UL - PKA_RAM_OFFSET)>>2)    /*!< Input 'k' integer coefficient */
#define PKA_ECC_DOUBLE_LADDER_IN_M_INTEGER             ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Input 'm' integer coefficient */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT1_X              ((0x0628UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P X coordinate */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT1_Y              ((0x0680UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Y coordinate */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT1_Z              ((0x06D8UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point P Z coordinate */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT2_X              ((0x0730UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point Q X coordinate */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT2_Y              ((0x0788UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point Q Y coordinate */
#define PKA_ECC_DOUBLE_LADDER_IN_POINT2_Z              ((0x07E0UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial point Q Z coordinate */

/* Compute ECC double base ladder output data */
#define PKA_ECC_DOUBLE_LADDER_OUT_RESULT_X             ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Output result X coordinate (affine coordinate) */
#define PKA_ECC_DOUBLE_LADDER_OUT_RESULT_Y             ((0x05D0UL - PKA_RAM_OFFSET)>>2)    /*!< Output result Y coordinate (affine coordinate) */
#define PKA_ECC_DOUBLE_LADDER_OUT_ERROR                ((0x0520UL - PKA_RAM_OFFSET)>>2)    /*!< Output result error */

/* Compute ECC projective to affine conversion input data */
#define PKA_ECC_PROJECTIVE_AFF_IN_MOD_NB_BITS          ((0x0408UL - PKA_RAM_OFFSET)>>2)    /*!< Input Modulus number of bits */
#define PKA_ECC_PROJECTIVE_AFF_IN_MOD_P                ((0x0470UL - PKA_RAM_OFFSET)>>2)    /*!< Input modulus GF(p) */
#define PKA_ECC_PROJECTIVE_AFF_IN_POINT_X              ((0x0D60UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial projective point P X coordinate */
#define PKA_ECC_PROJECTIVE_AFF_IN_POINT_Y              ((0x0DB8UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial projective point P Y coordinate */
#define PKA_ECC_PROJECTIVE_AFF_IN_POINT_Z              ((0x0E10UL - PKA_RAM_OFFSET)>>2)    /*!< Input initial projective point P Z coordinate */
#define PKA_ECC_PROJECTIVE_AFF_IN_MONTGOMERY_PARAM_R2  ((0x04C8UL - PKA_RAM_OFFSET)>>2)    /*!< Input storage area for Montgomery parameter */

/* Compute ECC projective to affine conversion output data */
#define PKA_ECC_PROJECTIVE_AFF_OUT_RESULT_X            ((0x0578UL - PKA_RAM_OFFSET)>>2)    /*!< Output result x affine coordinate */
#define PKA_ECC_PROJECTIVE_AFF_OUT_RESULT_Y            ((0x05D0UL - PKA_RAM_OFFSET)>>2)    /*!< Output result y affine coordinate */
#define PKA_ECC_PROJECTIVE_AFF_OUT_ERROR               ((0x0680UL - PKA_RAM_OFFSET)>>2)    /*!< Output result error */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR1 register  *******************/
#define PWR_CR1_LPMS_Pos                    (0U)
#define PWR_CR1_LPMS_Msk                    (0x7UL << PWR_CR1_LPMS_Pos)             /*!< 0x00000007 */
#define PWR_CR1_LPMS                        PWR_CR1_LPMS_Msk                        /*!< LPMS[2:0] Low-power mode selection field */
#define PWR_CR1_LPMS_0                      (0x1UL << PWR_CR1_LPMS_Pos)             /*!< 0x00000001 */
#define PWR_CR1_LPMS_1                      (0x2UL << PWR_CR1_LPMS_Pos)             /*!< 0x00000002 */
#define PWR_CR1_LPMS_2                      (0x4UL << PWR_CR1_LPMS_Pos)             /*!< 0x00000004 */
#define PWR_CR1_R2RSB1_Pos                  (5U)
#define PWR_CR1_R2RSB1_Msk                  (0x1UL << PWR_CR1_R2RSB1_Pos)           /*!< 0x00000020 */
#define PWR_CR1_R2RSB1                      PWR_CR1_R2RSB1_Msk                      /*!< SRAM2 Retention in Standby */
#define PWR_CR1_ULPMEN_Pos                  (7U)
#define PWR_CR1_ULPMEN_Msk                  (0x1UL << PWR_CR1_ULPMEN_Pos)           /*!< 0x00000080 */
#define PWR_CR1_ULPMEN                      PWR_CR1_ULPMEN_Msk                      /*!< BOR ultra-low power mode in Standby/Shutdown */
#define PWR_CR1_RADIORSB_Pos                (9U)
#define PWR_CR1_RADIORSB_Msk                (0x1UL << PWR_CR1_RADIORSB_Pos)         /*!< 0x00000200 */
#define PWR_CR1_RADIORSB                    PWR_CR1_RADIORSB_Msk                    /*!< 2.4GHz RADIO SRAMs (TXRX and Sequence) and Sleep clock retention in Standby mode */
#define PWR_CR1_R1RSB1_Pos                  (12U)
#define PWR_CR1_R1RSB1_Msk                  (0x1UL << PWR_CR1_R1RSB1_Pos)            /*!< 0x00001000 */
#define PWR_CR1_R1RSB1                      PWR_CR1_R1RSB1_Msk                       /*!< SRAM1 Page 1 Retention in Standby */

/********************  Bit definition for PWR_CR2 register  *******************/
#define PWR_CR2_SRAM1PDS1_Pos               (0U)
#define PWR_CR2_SRAM1PDS1_Msk               (0x1UL << PWR_CR2_SRAM1PDS1_Pos)        /*!< 0x00000001 */
#define PWR_CR2_SRAM1PDS1                   PWR_CR2_SRAM1PDS1_Msk                   /*!< SRAM1 Page 1 power-down in Stop modes */
#define PWR_CR2_SRAM2PDS1_Pos               (4U)
#define PWR_CR2_SRAM2PDS1_Msk               (0x1UL << PWR_CR2_SRAM2PDS1_Pos)        /*!< 0x00000010 */
#define PWR_CR2_SRAM2PDS1                   PWR_CR2_SRAM2PDS1_Msk                   /*!< SRAM2 power-down in Stop modes */
#define PWR_CR2_ICRAMPDS_Pos                (8U)
#define PWR_CR2_ICRAMPDS_Msk                (0x1UL << PWR_CR2_ICRAMPDS_Pos)         /*!< 0x00000100 */
#define PWR_CR2_ICRAMPDS                    PWR_CR2_ICRAMPDS_Msk                    /*!< ICACHE SRAM power-down in Stop modes */
#define PWR_CR2_FLASHFWU_Pos                (14U)
#define PWR_CR2_FLASHFWU_Msk                (0x1UL << PWR_CR2_FLASHFWU_Pos)         /*!< 0x00004000 */
#define PWR_CR2_FLASHFWU                    PWR_CR2_FLASHFWU_Msk                    /*!< Flash low-power mode in Stop modes */

/********************  Bit definition for PWR_CR3 register  *******************/
#define PWR_CR3_FSTEN_Pos                   (2U)
#define PWR_CR3_FSTEN_Msk                   (0x1UL << PWR_CR3_FSTEN_Pos)            /*!< 0x00000004 */
#define PWR_CR3_FSTEN                       PWR_CR3_FSTEN_Msk                       /*!< Fast soft start */

/*******************  Bit definition for PWR_VOSR register  *******************/
#define PWR_VOSR_VOSRDY_Pos                 (15U)
#define PWR_VOSR_VOSRDY_Msk                 (0x1UL << PWR_VOSR_VOSRDY_Pos)          /*!< 0x00008000 */
#define PWR_VOSR_VOSRDY                     PWR_VOSR_VOSRDY_Msk                     /*!< Ready bit for VCORE voltage scaling output selection */
#define PWR_VOSR_VOS_Pos                    (16U)
#define PWR_VOSR_VOS_Msk                    (0x1UL << PWR_VOSR_VOS_Pos)             /*!< 0x00010000 */
#define PWR_VOSR_VOS                        PWR_VOSR_VOS_Msk                        /*!< Voltage scaling range selection */

/*******************  Bit definition for PWR_SVMCR register  ******************/
#define PWR_SVMCR_PVDE_Pos                  (4U)
#define PWR_SVMCR_PVDE_Msk                  (0x1UL << PWR_SVMCR_PVDE_Pos)           /*!< 0x00000010 */
#define PWR_SVMCR_PVDE                      PWR_SVMCR_PVDE_Msk                      /*!< Power voltage detector enable */
#define PWR_SVMCR_PVDLS_Pos                 (5U)
#define PWR_SVMCR_PVDLS_Msk                 (0x7UL << PWR_SVMCR_PVDLS_Pos)          /*!< 0x000000E0 */
#define PWR_SVMCR_PVDLS                     PWR_SVMCR_PVDLS_Msk                     /*!< PVDLS[2:0] Power voltage detector level selection field  */
#define PWR_SVMCR_PVDLS_0                   (0x1UL << PWR_SVMCR_PVDLS_Pos)          /*!< 0x00000020 */
#define PWR_SVMCR_PVDLS_1                   (0x2UL << PWR_SVMCR_PVDLS_Pos)          /*!< 0x00000040 */
#define PWR_SVMCR_PVDLS_2                   (0x4UL << PWR_SVMCR_PVDLS_Pos)          /*!< 0x00000080 */

/*******************  Bit definition for PWR_WUCR1 register  ******************/
#define PWR_WUCR1_WUPEN1_Pos                (0U)
#define PWR_WUCR1_WUPEN1_Msk                (0x1UL << PWR_WUCR1_WUPEN1_Pos)         /*!< 0x00000001 */
#define PWR_WUCR1_WUPEN1                    PWR_WUCR1_WUPEN1_Msk                    /*!< Wakeup pin WKUP1 enable */
#define PWR_WUCR1_WUPEN3_Pos                (2U)
#define PWR_WUCR1_WUPEN3_Msk                (0x1UL << PWR_WUCR1_WUPEN3_Pos)         /*!< 0x00000004 */
#define PWR_WUCR1_WUPEN3                    PWR_WUCR1_WUPEN3_Msk                    /*!< Wakeup pin WKUP3 enable */
#define PWR_WUCR1_WUPEN4_Pos                (3U)
#define PWR_WUCR1_WUPEN4_Msk                (0x1UL << PWR_WUCR1_WUPEN4_Pos)         /*!< 0x00000008 */
#define PWR_WUCR1_WUPEN4                    PWR_WUCR1_WUPEN4_Msk                    /*!< Wakeup pin WKUP4 enable */
#define PWR_WUCR1_WUPEN6_Pos                (5U)
#define PWR_WUCR1_WUPEN6_Msk                (0x1UL << PWR_WUCR1_WUPEN6_Pos)         /*!< 0x00000020 */
#define PWR_WUCR1_WUPEN6                    PWR_WUCR1_WUPEN6_Msk                    /*!< Wakeup pin WKUP6 enable */
#define PWR_WUCR1_WUPEN7_Pos                (6U)
#define PWR_WUCR1_WUPEN7_Msk                (0x1UL << PWR_WUCR1_WUPEN7_Pos)         /*!< 0x00000040 */
#define PWR_WUCR1_WUPEN7                    PWR_WUCR1_WUPEN7_Msk                    /*!< Wakeup pin WKUP7 enable */
#define PWR_WUCR1_WUPEN8_Pos                (7U)
#define PWR_WUCR1_WUPEN8_Msk                (0x1UL << PWR_WUCR1_WUPEN8_Pos)         /*!< 0x00000080 */
#define PWR_WUCR1_WUPEN8                    PWR_WUCR1_WUPEN8_Msk                    /*!< Wakeup pin WKUP8 enable */

/*******************  Bit definition for PWR_WUCR2 register  ******************/
#define PWR_WUCR2_WUPP1_Pos                 (0U)
#define PWR_WUCR2_WUPP1_Msk                 (0x1UL << PWR_WUCR2_WUPP1_Pos)          /*!< 0x00000001 */
#define PWR_WUCR2_WUPP1                     PWR_WUCR2_WUPP1_Msk                     /*!< Wakeup pin WKUP1 polarity */
#define PWR_WUCR2_WUPP3_Pos                 (2U)
#define PWR_WUCR2_WUPP3_Msk                 (0x1UL << PWR_WUCR2_WUPP3_Pos)          /*!< 0x00000004 */
#define PWR_WUCR2_WUPP3                     PWR_WUCR2_WUPP3_Msk                     /*!< Wakeup pin WKUP3 polarity */
#define PWR_WUCR2_WUPP4_Pos                 (3U)
#define PWR_WUCR2_WUPP4_Msk                 (0x1UL << PWR_WUCR2_WUPP4_Pos)          /*!< 0x00000008 */
#define PWR_WUCR2_WUPP4                     PWR_WUCR2_WUPP4_Msk                     /*!< Wakeup pin WKUP4 polarity */
#define PWR_WUCR2_WUPP6_Pos                 (5U)
#define PWR_WUCR2_WUPP6_Msk                 (0x1UL << PWR_WUCR2_WUPP6_Pos)          /*!< 0x00000020 */
#define PWR_WUCR2_WUPP6                     PWR_WUCR2_WUPP6_Msk                     /*!< Wakeup pin WKUP6 polarity */
#define PWR_WUCR2_WUPP7_Pos                 (6U)
#define PWR_WUCR2_WUPP7_Msk                 (0x1UL << PWR_WUCR2_WUPP7_Pos)          /*!< 0x00000040 */
#define PWR_WUCR2_WUPP7                     PWR_WUCR2_WUPP7_Msk                     /*!< Wakeup pin WKUP7 polarity */
#define PWR_WUCR2_WUPP8_Pos                 (7U)
#define PWR_WUCR2_WUPP8_Msk                 (0x1UL << PWR_WUCR2_WUPP8_Pos)          /*!< 0x00000080 */
#define PWR_WUCR2_WUPP8                     PWR_WUCR2_WUPP8_Msk                     /*!< Wakeup pin WKUP8 polarity */

/*******************  Bit definition for PWR_WUCR3 register  ******************/
#define PWR_WUCR3_WUSEL1_Pos                (0U)
#define PWR_WUCR3_WUSEL1_Msk                (0x3UL << PWR_WUCR3_WUSEL1_Pos)         /*!< 0x00000003 */
#define PWR_WUCR3_WUSEL1                    PWR_WUCR3_WUSEL1_Msk                    /*!< Wakeup pin WKUP1 selection field */
#define PWR_WUCR3_WUSEL1_0                  (0x1UL << PWR_WUCR3_WUSEL1_Pos)         /*!< 0x00000001 */
#define PWR_WUCR3_WUSEL1_1                  (0x2UL << PWR_WUCR3_WUSEL1_Pos)         /*!< 0x00000002 */
#define PWR_WUCR3_WUSEL3_Pos                (4U)
#define PWR_WUCR3_WUSEL3_Msk                (0x3UL << PWR_WUCR3_WUSEL3_Pos)         /*!< 0x00000030 */
#define PWR_WUCR3_WUSEL3                    PWR_WUCR3_WUSEL3_Msk                    /*!< Wakeup pin WKUP3 selection field */
#define PWR_WUCR3_WUSEL3_0                  (0x1UL << PWR_WUCR3_WUSEL3_Pos)         /*!< 0x00000010 */
#define PWR_WUCR3_WUSEL3_1                  (0x2UL << PWR_WUCR3_WUSEL3_Pos)         /*!< 0x00000020 */
#define PWR_WUCR3_WUSEL4_Pos                (6U)
#define PWR_WUCR3_WUSEL4_Msk                (0x3UL << PWR_WUCR3_WUSEL4_Pos)         /*!< 0x000000C0 */
#define PWR_WUCR3_WUSEL4                    PWR_WUCR3_WUSEL4_Msk                    /*!< Wakeup pin WKUP4 selection field */
#define PWR_WUCR3_WUSEL4_0                  (0x1UL << PWR_WUCR3_WUSEL4_Pos)         /*!< 0x00000040 */
#define PWR_WUCR3_WUSEL4_1                  (0x2UL << PWR_WUCR3_WUSEL4_Pos)         /*!< 0x00000080 */
#define PWR_WUCR3_WUSEL6_Pos                (10U)
#define PWR_WUCR3_WUSEL6_Msk                (0x3UL << PWR_WUCR3_WUSEL6_Pos)         /*!< 0x00000C00 */
#define PWR_WUCR3_WUSEL6                    PWR_WUCR3_WUSEL6_Msk                    /*!< Wakeup pin WKUP6 selection field */
#define PWR_WUCR3_WUSEL6_0                  (0x1UL << PWR_WUCR3_WUSEL6_Pos)         /*!< 0x00000400 */
#define PWR_WUCR3_WUSEL6_1                  (0x2UL << PWR_WUCR3_WUSEL6_Pos)         /*!< 0x00000800 */
#define PWR_WUCR3_WUSEL7_Pos                (12U)
#define PWR_WUCR3_WUSEL7_Msk                (0x3UL << PWR_WUCR3_WUSEL7_Pos)         /*!< 0x00003000 */
#define PWR_WUCR3_WUSEL7                    PWR_WUCR3_WUSEL7_Msk                    /*!< Wakeup pin WKUP7 selection field */
#define PWR_WUCR3_WUSEL7_0                  (0x1UL << PWR_WUCR3_WUSEL7_Pos)         /*!< 0x00001000 */
#define PWR_WUCR3_WUSEL7_1                  (0x2UL << PWR_WUCR3_WUSEL7_Pos)         /*!< 0x00002000 */
#define PWR_WUCR3_WUSEL8_Pos                (14U)
#define PWR_WUCR3_WUSEL8_Msk                (0x3UL << PWR_WUCR3_WUSEL8_Pos)         /*!< 0x0000C000 */
#define PWR_WUCR3_WUSEL8                    PWR_WUCR3_WUSEL8_Msk                    /*!< Wakeup pin WKUP8 selection field */
#define PWR_WUCR3_WUSEL8_0                  (0x1UL << PWR_WUCR3_WUSEL8_Pos)         /*!< 0x00004000 */
#define PWR_WUCR3_WUSEL8_1                  (0x2UL << PWR_WUCR3_WUSEL8_Pos)         /*!< 0x00008000 */

/********************  Bit definition for PWR_DBPR register  ******************/
#define PWR_DBPR_DBP_Pos                    (0U)
#define PWR_DBPR_DBP_Msk                    (0x1UL << PWR_DBPR_DBP_Pos)             /*!< 0x00000001 */
#define PWR_DBPR_DBP                        PWR_DBPR_DBP_Msk                        /*!< Disable backup domain write protection */

/**********************  Bit definition for PWR_SR register  ******************/
#define PWR_SR_CSSF_Pos                     (0U)
#define PWR_SR_CSSF_Msk                     (0x1UL << PWR_SR_CSSF_Pos)              /*!< 0x00000001 */
#define PWR_SR_CSSF                         PWR_SR_CSSF_Msk                         /*!< Clear Stop and Standby/Shutdown flags */
#define PWR_SR_STOPF_Pos                    (1U)
#define PWR_SR_STOPF_Msk                    (0x1UL << PWR_SR_STOPF_Pos)             /*!< 0x00000002 */
#define PWR_SR_STOPF                        PWR_SR_STOPF_Msk                        /*!< Stop flag                             */
#define PWR_SR_SBF_Pos                      (2U)
#define PWR_SR_SBF_Msk                      (0x1UL << PWR_SR_SBF_Pos)               /*!< 0x00000004 */
#define PWR_SR_SBF                          PWR_SR_SBF_Msk                          /*!< Standby/Shutdown flag                 */

/********************  Bit definition for PWR_SVMSR register  *****************/
#define PWR_SVMSR_PVDO_Pos                  (4U)
#define PWR_SVMSR_PVDO_Msk                  (0x1UL << PWR_SVMSR_PVDO_Pos)           /*!< 0x00000010 */
#define PWR_SVMSR_PVDO                      PWR_SVMSR_PVDO_Msk                      /*!< VDD voltage detector output                       */
#define PWR_SVMSR_ACTVOSRDY_Pos             (15U)
#define PWR_SVMSR_ACTVOSRDY_Msk             (0x1UL << PWR_SVMSR_ACTVOSRDY_Pos)      /*!< 0x00008000 */
#define PWR_SVMSR_ACTVOSRDY                 PWR_SVMSR_ACTVOSRDY_Msk                 /*!< Voltage level ready for currently used VOS        */
#define PWR_SVMSR_ACTVOS_Pos                (16U)
#define PWR_SVMSR_ACTVOS_Msk                (0x1UL << PWR_SVMSR_ACTVOS_Pos)         /*!< 0x00010000 */
#define PWR_SVMSR_ACTVOS                    PWR_SVMSR_ACTVOS_Msk                    /*!< Voltage Output Scaling currently applied to VCORE */

/*********************  Bit definition for PWR_WUSR register  *****************/
#define PWR_WUSR_WUF1_Pos                   (0U)
#define PWR_WUSR_WUF1_Msk                   (0x1UL << PWR_WUSR_WUF1_Pos)            /*!< 0x00000001 */
#define PWR_WUSR_WUF1                       PWR_WUSR_WUF1_Msk                       /*!< Wakeup flag 1   */
#define PWR_WUSR_WUF3_Pos                   (2U)
#define PWR_WUSR_WUF3_Msk                   (0x1UL << PWR_WUSR_WUF3_Pos)            /*!< 0x00000004 */
#define PWR_WUSR_WUF3                       PWR_WUSR_WUF3_Msk                       /*!< Wakeup flag 3   */
#define PWR_WUSR_WUF4_Pos                   (3U)
#define PWR_WUSR_WUF4_Msk                   (0x1UL << PWR_WUSR_WUF4_Pos)            /*!< 0x00000008 */
#define PWR_WUSR_WUF4                       PWR_WUSR_WUF4_Msk                       /*!< Wakeup flag 4   */
#define PWR_WUSR_WUF6_Pos                   (5U)
#define PWR_WUSR_WUF6_Msk                   (0x1UL << PWR_WUSR_WUF6_Pos)            /*!< 0x00000020 */
#define PWR_WUSR_WUF6                       PWR_WUSR_WUF6_Msk                       /*!< Wakeup flag 6   */
#define PWR_WUSR_WUF7_Pos                   (6U)
#define PWR_WUSR_WUF7_Msk                   (0x1UL << PWR_WUSR_WUF7_Pos)            /*!< 0x00000040 */
#define PWR_WUSR_WUF7                       PWR_WUSR_WUF7_Msk                       /*!< Wakeup flag 7   */
#define PWR_WUSR_WUF8_Pos                   (7U)
#define PWR_WUSR_WUF8_Msk                   (0x1UL << PWR_WUSR_WUF8_Pos)            /*!< 0x00000080 */
#define PWR_WUSR_WUF8                       PWR_WUSR_WUF8_Msk                       /*!< Wakeup flag 8   */
#define PWR_WUSR_WUF_Pos                    (0U)
#define PWR_WUSR_WUF_Msk                    (0xFFUL << PWR_WUSR_WUF_Pos)            /*!< 0x000000FF */
#define PWR_WUSR_WUF                        PWR_WUSR_WUF_Msk                        /*!< all Wakeup flag */

/*********************  Bit definition for PWR_WUSCR register  ****************/
#define PWR_WUSCR_CWUF1_Pos                 (0U)
#define PWR_WUSCR_CWUF1_Msk                 (0x1UL << PWR_WUSCR_CWUF1_Pos)          /*!< 0x00000001*/
#define PWR_WUSCR_CWUF1                     PWR_WUSCR_CWUF1_Msk                     /*!< Wakeup clear flag 1   */
#define PWR_WUSCR_CWUF3_Pos                 (2U)
#define PWR_WUSCR_CWUF3_Msk                 (0x1UL << PWR_WUSCR_CWUF3_Pos)          /*!< 0x00000004 */
#define PWR_WUSCR_CWUF3                     PWR_WUSCR_CWUF3_Msk                     /*!< Wakeup clear flag 3   */
#define PWR_WUSCR_CWUF4_Pos                 (3U)
#define PWR_WUSCR_CWUF4_Msk                 (0x1UL << PWR_WUSCR_CWUF4_Pos)          /*!< 0x00000008 */
#define PWR_WUSCR_CWUF4                     PWR_WUSCR_CWUF4_Msk                     /*!< Wakeup clear flag 4   */
#define PWR_WUSCR_CWUF6_Pos                 (5U)
#define PWR_WUSCR_CWUF6_Msk                 (0x1UL << PWR_WUSCR_CWUF6_Pos)          /*!< 0x00000020 */
#define PWR_WUSCR_CWUF6                     PWR_WUSCR_CWUF6_Msk                     /*!< Wakeup clear flag 6   */
#define PWR_WUSCR_CWUF7_Pos                 (6U)
#define PWR_WUSCR_CWUF7_Msk                 (0x1UL << PWR_WUSCR_CWUF7_Pos)          /*!< 0x00000040 */
#define PWR_WUSCR_CWUF7                     PWR_WUSCR_CWUF7_Msk                     /*!< Wakeup clear flag 7   */
#define PWR_WUSCR_CWUF8_Pos                 (7U)
#define PWR_WUSCR_CWUF8_Msk                 (0x1UL << PWR_WUSCR_CWUF8_Pos)          /*!< 0x00000080 */
#define PWR_WUSCR_CWUF8                     PWR_WUSCR_CWUF8_Msk                     /*!< Wakeup clear flag 8   */
#define PWR_WUSCR_CWUF_Pos                  (0U)
#define PWR_WUSCR_CWUF_Msk                  (0xFFUL << PWR_WUSCR_CWUF1_Pos)         /*!< 0x000000FF */
#define PWR_WUSCR_CWUF                      PWR_WUSCR_CWUF_Msk                      /*!< all Wakeup clear flag */

/********************  Bit definition for PWR_IORETENRA register  *****************/
#define PWR_IORETENRA_EN0_Pos               (0U)
#define PWR_IORETENRA_EN0_Msk               (0x1UL << PWR_IORETENRA_EN0_Pos)           /*!< 0x00000001 */
#define PWR_IORETENRA_EN0                   PWR_IORETENRA_EN0_Msk                      /*!< Standby GPIO retention enable for PA0  */
#define PWR_IORETENRA_EN1_Pos               (1U)
#define PWR_IORETENRA_EN1_Msk               (0x1UL << PWR_IORETENRA_EN1_Pos)           /*!< 0x00000002 */
#define PWR_IORETENRA_EN1                   PWR_IORETENRA_EN1_Msk                      /*!< Standby GPIO retention enable for PA1  */
#define PWR_IORETENRA_EN2_Pos               (2U)
#define PWR_IORETENRA_EN2_Msk               (0x1UL << PWR_IORETENRA_EN2_Pos)           /*!< 0x00000004 */
#define PWR_IORETENRA_EN2                   PWR_IORETENRA_EN2_Msk                      /*!< Standby GPIO retention enable for PA2  */
#define PWR_IORETENRA_EN5_Pos               (5U)
#define PWR_IORETENRA_EN5_Msk               (0x1UL << PWR_IORETENRA_EN5_Pos)           /*!< 0x00000020 */
#define PWR_IORETENRA_EN5                   PWR_IORETENRA_EN5_Msk                      /*!< Standby GPIO retention enable for PA5  */
#define PWR_IORETENRA_EN6_Pos               (6U)
#define PWR_IORETENRA_EN6_Msk               (0x1UL << PWR_IORETENRA_EN6_Pos)           /*!< 0x00000040 */
#define PWR_IORETENRA_EN6                   PWR_IORETENRA_EN6_Msk                      /*!< Standby GPIO retention enable for PA6  */
#define PWR_IORETENRA_EN7_Pos               (7U)
#define PWR_IORETENRA_EN7_Msk               (0x1UL << PWR_IORETENRA_EN7_Pos)           /*!< 0x00000080 */
#define PWR_IORETENRA_EN7                   PWR_IORETENRA_EN7_Msk                      /*!< Standby GPIO retention enable for PA7  */
#define PWR_IORETENRA_EN8_Pos               (8U)
#define PWR_IORETENRA_EN8_Msk               (0x1UL << PWR_IORETENRA_EN8_Pos)           /*!< 0x00000100 */
#define PWR_IORETENRA_EN8                   PWR_IORETENRA_EN8_Msk                      /*!< Standby GPIO retention enable for PA8  */
#define PWR_IORETENRA_EN12_Pos              (12U)
#define PWR_IORETENRA_EN12_Msk              (0x1UL << PWR_IORETENRA_EN12_Pos)          /*!< 0x00001000 */
#define PWR_IORETENRA_EN12                  PWR_IORETENRA_EN12_Msk                     /*!< Standby GPIO retention enable for PA12 */
#define PWR_IORETENRA_EN13_Pos              (13U)
#define PWR_IORETENRA_EN13_Msk              (0x1UL << PWR_IORETENRA_EN13_Pos)          /*!< 0x00002000 */
#define PWR_IORETENRA_EN13                  PWR_IORETENRA_EN13_Msk                     /*!< Standby GPIO retention enable for PA13 */
#define PWR_IORETENRA_EN14_Pos              (14U)
#define PWR_IORETENRA_EN14_Msk              (0x1UL << PWR_IORETENRA_EN14_Pos)          /*!< 0x00004000 */
#define PWR_IORETENRA_EN14                  PWR_IORETENRA_EN14_Msk                     /*!< Standby GPIO retention enable for PA14 */
#define PWR_IORETENRA_EN15_Pos              (15U)
#define PWR_IORETENRA_EN15_Msk              (0x1UL << PWR_IORETENRA_EN15_Pos)          /*!< 0x00008000 */
#define PWR_IORETENRA_EN15                  PWR_IORETENRA_EN15_Msk                     /*!< Standby GPIO retention enable for PA15 */

/********************  Bit definition for PWR_IORETRA register  *****************/
#define PWR_IORETRA_RET0_Pos                (0U)
#define PWR_IORETRA_RET0_Msk                (0x1UL << PWR_IORETRA_RET0_Pos)            /*!< 0x00000001 */
#define PWR_IORETRA_RET0                    PWR_IORETRA_RET0_Msk                       /*!< Standby GPIO retention status for PA0  */
#define PWR_IORETRA_RET1_Pos                (1U)
#define PWR_IORETRA_RET1_Msk                (0x1UL << PWR_IORETRA_RET1_Pos)            /*!< 0x00000002 */
#define PWR_IORETRA_RET1                    PWR_IORETRA_RET1_Msk                       /*!< Standby GPIO retention status for PA1  */
#define PWR_IORETRA_RET2_Pos                (2U)
#define PWR_IORETRA_RET2_Msk                (0x1UL << PWR_IORETRA_RET2_Pos)            /*!< 0x00000004 */
#define PWR_IORETRA_RET2                    PWR_IORETRA_RET2_Msk                       /*!< Standby GPIO retention status for PA2  */
#define PWR_IORETRA_RET5_Pos                (5U)
#define PWR_IORETRA_RET5_Msk                (0x1UL << PWR_IORETRA_RET5_Pos)            /*!< 0x00000020 */
#define PWR_IORETRA_RET5                    PWR_IORETRA_RET5_Msk                       /*!< Standby GPIO retention status for PA5  */
#define PWR_IORETRA_RET6_Pos                (6U)
#define PWR_IORETRA_RET6_Msk                (0x1UL << PWR_IORETRA_RET6_Pos)            /*!< 0x00000040 */
#define PWR_IORETRA_RET6                    PWR_IORETRA_RET6_Msk                       /*!< Standby GPIO retention status for PA6  */
#define PWR_IORETRA_RET7_Pos                (7U)
#define PWR_IORETRA_RET7_Msk                (0x1UL << PWR_IORETRA_RET7_Pos)            /*!< 0x00000080 */
#define PWR_IORETRA_RET7                    PWR_IORETRA_RET7_Msk                       /*!< Standby GPIO retention status for PA7  */
#define PWR_IORETRA_RET8_Pos                (8U)
#define PWR_IORETRA_RET8_Msk                (0x1UL << PWR_IORETRA_RET8_Pos)            /*!< 0x00000100 */
#define PWR_IORETRA_RET8                    PWR_IORETRA_RET8_Msk                       /*!< Standby GPIO retention status for PA8  */
#define PWR_IORETRA_RET12_Pos               (12U)
#define PWR_IORETRA_RET12_Msk               (0x1UL << PWR_IORETRA_RET12_Pos)           /*!< 0x00001000 */
#define PWR_IORETRA_RET12                   PWR_IORETRA_RET12_Msk                      /*!< Standby GPIO retention status for PA12 */
#define PWR_IORETRA_RET13_Pos               (13U)
#define PWR_IORETRA_RET13_Msk               (0x1UL << PWR_IORETRA_RET13_Pos)           /*!< 0x00002000 */
#define PWR_IORETRA_RET13                   PWR_IORETRA_RET13_Msk                      /*!< Standby GPIO retention status for PA13 */
#define PWR_IORETRA_RET14_Pos               (14U)
#define PWR_IORETRA_RET14_Msk               (0x1UL << PWR_IORETRA_RET14_Pos)           /*!< 0x00004000 */
#define PWR_IORETRA_RET14                   PWR_IORETRA_RET14_Msk                      /*!< Standby GPIO retention status for PA14 */
#define PWR_IORETRA_RET15_Pos               (15U)
#define PWR_IORETRA_RET15_Msk               (0x1UL << PWR_IORETRA_RET15_Pos)           /*!< 0x00008000 */
#define PWR_IORETRA_RET15                   PWR_IORETRA_RET15_Msk                      /*!< Standby GPIO retention status for PA15 */

/********************  Bit definition for PWR_IORETENRB register  *****************/
#define PWR_IORETENRB_EN3_Pos               (3U)
#define PWR_IORETENRB_EN3_Msk               (0x1UL << PWR_IORETENRB_EN3_Pos)           /*!< 0x00000008 */
#define PWR_IORETENRB_EN3                   PWR_IORETENRB_EN3_Msk                      /*!< Standby GPIO retention enable for PB3  */
#define PWR_IORETENRB_EN4_Pos               (4U)
#define PWR_IORETENRB_EN4_Msk               (0x1UL << PWR_IORETENRB_EN4_Pos)           /*!< 0x00000010 */
#define PWR_IORETENRB_EN4                   PWR_IORETENRB_EN4_Msk                      /*!< Standby GPIO retention enable for PB4  */
#define PWR_IORETENRB_EN8_Pos               (8U)
#define PWR_IORETENRB_EN8_Msk               (0x1UL << PWR_IORETENRB_EN8_Pos)           /*!< 0x00000100 */
#define PWR_IORETENRB_EN8                   PWR_IORETENRB_EN8_Msk                      /*!< Standby GPIO retention enable for PB8  */
#define PWR_IORETENRB_EN9_Pos               (9U)
#define PWR_IORETENRB_EN9_Msk               (0x1UL << PWR_IORETENRB_EN9_Pos)           /*!< 0x00000200 */
#define PWR_IORETENRB_EN9                   PWR_IORETENRB_EN9_Msk                      /*!< Standby GPIO retention enable for PB9  */
#define PWR_IORETENRB_EN12_Pos              (12U)
#define PWR_IORETENRB_EN12_Msk              (0x1UL << PWR_IORETENRB_EN12_Pos)          /*!< 0x00001000 */
#define PWR_IORETENRB_EN12                  PWR_IORETENRB_EN12_Msk                     /*!< Standby GPIO retention enable for PB12 */
#define PWR_IORETENRB_EN15_Pos              (15U)
#define PWR_IORETENRB_EN15_Msk              (0x1UL << PWR_IORETENRB_EN15_Pos)          /*!< 0x00008000 */
#define PWR_IORETENRB_EN15                  PWR_IORETENRB_EN15_Msk                     /*!< Standby GPIO retention enable for PB15 */

/********************  Bit definition for PWR_IORETRB register  *****************/
#define PWR_IORETRB_RET3_Pos                (3U)
#define PWR_IORETRB_RET3_Msk                (0x1UL << PWR_IORETRB_RET3_Pos)            /*!< 0x00000008 */
#define PWR_IORETRB_RET3                    PWR_IORETRB_RET3_Msk                       /*!< Standby GPIO retention status for PB3  */
#define PWR_IORETRB_RET4_Pos                (4U)
#define PWR_IORETRB_RET4_Msk                (0x1UL << PWR_IORETRB_RET4_Pos)            /*!< 0x00000010 */
#define PWR_IORETRB_RET4                    PWR_IORETRB_RET4_Msk                       /*!< Standby GPIO retention status for PB4  */
#define PWR_IORETRB_RET8_Pos                (8U)
#define PWR_IORETRB_RET8_Msk                (0x1UL << PWR_IORETRB_RET8_Pos)            /*!< 0x00000100 */
#define PWR_IORETRB_RET8                    PWR_IORETRB_RET8_Msk                       /*!< Standby GPIO retention status for PB8  */
#define PWR_IORETRB_RET9_Pos                (9U)
#define PWR_IORETRB_RET9_Msk                (0x1UL << PWR_IORETRB_RET9_Pos)            /*!< 0x00000200 */
#define PWR_IORETRB_RET9                    PWR_IORETRB_RET9_Msk                       /*!< Standby GPIO retention status for PB9  */
#define PWR_IORETRB_RET12_Pos               (12U)
#define PWR_IORETRB_RET12_Msk               (0x1UL << PWR_IORETRB_RET12_Pos)           /*!< 0x00001000 */
#define PWR_IORETRB_RET12                   PWR_IORETRB_RET12_Msk                      /*!< Standby GPIO retention status for PB12 */
#define PWR_IORETRB_RET15_Pos               (15U)
#define PWR_IORETRB_RET15_Msk               (0x1UL << PWR_IORETRB_RET15_Pos)           /*!< 0x00008000 */
#define PWR_IORETRB_RET15                   PWR_IORETRB_RET15_Msk                      /*!< Standby GPIO retention status for PB15 */

/********************  Bit definition for PWR_IORETENRC register  *****************/
#define PWR_IORETENRC_EN14_Pos              (14U)
#define PWR_IORETENRC_EN14_Msk              (0x1UL << PWR_IORETENRC_EN14_Pos)          /*!< 0x00004000 */
#define PWR_IORETENRC_EN14                  PWR_IORETENRC_EN14_Msk                     /*!< Standby GPIO retention enable for PC14 */
#define PWR_IORETENRC_EN15_Pos              (15U)
#define PWR_IORETENRC_EN15_Msk              (0x1UL << PWR_IORETENRC_EN15_Pos)          /*!< 0x00008000 */
#define PWR_IORETENRC_EN15                  PWR_IORETENRC_EN15_Msk                     /*!< Standby GPIO retention enable for PC15 */

/********************  Bit definition for PWR_IORETRC register  *****************/
#define PWR_IORETRC_RET14_Pos               (14U)
#define PWR_IORETRC_RET14_Msk               (0x1UL << PWR_IORETRC_RET14_Pos)           /*!< 0x00004000 */
#define PWR_IORETRC_RET14                   PWR_IORETRC_RET14_Msk                      /*!< Standby GPIO retention status for PC14 */
#define PWR_IORETRC_RET15_Pos               (15U)
#define PWR_IORETRC_RET15_Msk               (0x1UL << PWR_IORETRC_RET15_Pos)           /*!< 0x00008000 */
#define PWR_IORETRC_RET15                   PWR_IORETRC_RET15_Msk                      /*!< Standby GPIO retention status for PC15 */

/********************  Bit definition for PWR_IORETENRH register  *****************/
#define PWR_IORETENRH_EN3_Pos               (3U)
#define PWR_IORETENRH_EN3_Msk               (0x1UL << PWR_IORETENRH_EN3_Pos)           /*!< 0x00000008 */
#define PWR_IORETENRH_EN3                   PWR_IORETENRH_EN3_Msk                      /*!< Standby GPIO retention enable for PH3 */

/********************  Bit definition for PWR_IORETRH register  *****************/
#define PWR_IORETRH_RET3_Pos                (3U)
#define PWR_IORETRH_RET3_Msk                (0x1UL << PWR_IORETRH_RET3_Pos)            /*!< 0x00000008 */
#define PWR_IORETRH_RET3                    PWR_IORETRH_RET3_Msk                       /*!< Standby GPIO retention status for PH3 */

/********************  Bit definition for PWR_RADIOSCR register  *****************/
#define PWR_RADIOSCR_MODE_Pos               (0U)
#define PWR_RADIOSCR_MODE_Msk               (0x3UL << PWR_RADIOSCR_MODE_Pos)            /*!< 0x00000003 */
#define PWR_RADIOSCR_MODE                   PWR_RADIOSCR_MODE_Msk                       /*!< 2.4 GHz RADIO operating mode */
#define PWR_RADIOSCR_MODE_0                 (0x1UL << PWR_RADIOSCR_MODE_Pos)            /*!< 0x00000001 */
#define PWR_RADIOSCR_MODE_1                 (0x2UL << PWR_RADIOSCR_MODE_Pos)            /*!< 0x00000002 */
#define PWR_RADIOSCR_PHYMODE_Pos            (2U)
#define PWR_RADIOSCR_PHYMODE_Msk            (0x1UL << PWR_RADIOSCR_PHYMODE_Pos)         /*!< 0x00000004 */
#define PWR_RADIOSCR_PHYMODE                PWR_RADIOSCR_PHYMODE_Msk                    /*!< 2.4 GHz RADIO PHY operating mode */
#define PWR_RADIOSCR_ENCMODE_Pos            (3U)
#define PWR_RADIOSCR_ENCMODE_Msk            (0x1UL << PWR_RADIOSCR_ENCMODE_Pos)         /*!< 0x00000008 */
#define PWR_RADIOSCR_ENCMODE                PWR_RADIOSCR_ENCMODE_Msk                    /*!< 2.4 GHz RADIO encryption function operating mode */
#define PWR_RADIOSCR_RFVDDHPA_Pos           (8U)
#define PWR_RADIOSCR_RFVDDHPA_Msk           (0x1FUL << PWR_RADIOSCR_RFVDDHPA_Pos)       /*!< 0x00001F00 */
#define PWR_RADIOSCR_RFVDDHPA               PWR_RADIOSCR_RFVDDHPA_Msk                   /*!< 2.4 GHz RADIO VDDHPA control word */
#define PWR_RADIOSCR_REGPARDYVDDRFPA_Pos    (15U)
#define PWR_RADIOSCR_REGPARDYVDDRFPA_Msk    (0x1UL << PWR_RADIOSCR_REGPARDYVDDRFPA_Pos) /*!< 0x00008000 */
#define PWR_RADIOSCR_REGPARDYVDDRFPA        PWR_RADIOSCR_REGPARDYVDDRFPA_Msk            /*!< Ready bit for VDDHPA voltage level when selecting VDDRFPA input */


/******************************************************************************/
/*                                                                            */
/*                      SRAMs configuration controller                        */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for RAMCFG_MxCR register  ******************/
#define RAMCFG_CR_ALE_Pos                   (4U)
#define RAMCFG_CR_ALE_Msk                   (0x1UL << RAMCFG_CR_ALE_Pos)              /*!< 0x00000010 */
#define RAMCFG_CR_ALE                       RAMCFG_CR_ALE_Msk                         /*!< Address Latching Enable */
#define RAMCFG_CR_SRAMER_Pos                (8U)
#define RAMCFG_CR_SRAMER_Msk                (0x1UL << RAMCFG_CR_SRAMER_Pos)           /*!< 0x00000100 */
#define RAMCFG_CR_SRAMER                    RAMCFG_CR_SRAMER_Msk                      /*!< Start Erase */
#define RAMCFG_CR_WSC_Pos                   (16U)
#define RAMCFG_CR_WSC_Msk                   (0x7UL << RAMCFG_CR_WSC_Pos)              /*!< 0x00070000 */
#define RAMCFG_CR_WSC                       RAMCFG_CR_WSC_Msk                         /*!< WSC[18:16] Wait State Configuration field */
#define RAMCFG_CR_WSC_0                     (0x1UL << RAMCFG_CR_WSC_Pos)              /*!< 0x00010000 */
#define RAMCFG_CR_WSC_1                     (0x2UL << RAMCFG_CR_WSC_Pos)              /*!< 0x00020000 */
#define RAMCFG_CR_WSC_2                     (0x4UL << RAMCFG_CR_WSC_Pos)              /*!< 0x00040000 */

/*******************  Bit definition for RAMCFG_MxISR register  ******************/
#define RAMCFG_ISR_PED_Pos                  (1U)
#define RAMCFG_ISR_PED_Msk                  (0x1UL << RAMCFG_ISR_PED_Pos)             /*!< 0x00000002 */
#define RAMCFG_ISR_PED                      RAMCFG_ISR_PED_Msk                        /*!< Parity error detected */
#define RAMCFG_ISR_SRAMBUSY_Pos             (8U)
#define RAMCFG_ISR_SRAMBUSY_Msk             (0x1UL << RAMCFG_ISR_SRAMBUSY_Pos)        /*!< 0x00000100 */
#define RAMCFG_ISR_SRAMBUSY                 RAMCFG_ISR_SRAMBUSY_Msk                   /*!< SRAM busy with erase operation */

/*****************  Bit definition for RAMCFG_MxERKEYR register  ***************/
#define RAMCFG_ERKEYR_ERASEKEY_Pos          (0U)
#define RAMCFG_ERKEYR_ERASEKEY_Msk          (0xFFUL << RAMCFG_ERKEYR_ERASEKEY_Pos)    /*!< 0x000000FF */
#define RAMCFG_ERKEYR_ERASEKEY              RAMCFG_ERKEYR_ERASEKEY_Msk                /*!< Erase write protection key */

/*******************  Bit definition for RAMCFG_MxIER register  ******************/
#define RAMCFG_IER_PEIE_Pos                 (1U)
#define RAMCFG_IER_PEIE_Msk                 (0x1UL << RAMCFG_IER_PEIE_Pos)            /*!< 0x00000001 */
#define RAMCFG_IER_PEIE                     RAMCFG_IER_PEIE_Msk                       /*!< Parity error interrupt enable */
#define RAMCFG_IER_PENMI_Pos                (3U)
#define RAMCFG_IER_PENMI_Msk                (0x1UL << RAMCFG_IER_PENMI_Pos)           /*!< 0x00000004 */
#define RAMCFG_IER_PENMI                    RAMCFG_IER_PENMI_Msk                      /*!< Parity error NMI */

/*******************  Bit definition for RAMCFG_MxPEAR register  ******************/
#define RAMCFG_PEAR_PEA_Pos                 (0U)
#define RAMCFG_PEAR_PEA_Msk                 (0xFFFFUL << RAMCFG_PEAR_PEA_Pos)         /*!< 0x0000FFFF */
#define RAMCFG_PEAR_PEA                     RAMCFG_PEAR_PEA_Msk                       /*!< Parity error SRAM word aligned address offset */
#define RAMCFG_PEAR_ID_Pos                  (24U)
#define RAMCFG_PEAR_ID_Msk                  (0xFUL << RAMCFG_PEAR_ID_Pos)             /*!< 0x0F000000 */
#define RAMCFG_PEAR_ID                      RAMCFG_PEAR_ID_Msk                        /*!< Parity error AHB bus master ID */
#define RAMCFG_PEAR_BYTE_Pos                (28U)
#define RAMCFG_PEAR_BYTE_Msk                (0xFUL << RAMCFG_PEAR_BYTE_Pos)           /*!< 0xF0000000 */
#define RAMCFG_PEAR_BYTE                    RAMCFG_PEAR_BYTE_Msk                      /*!< Byte parity error flag */

/*******************  Bit definition for RAMCFG_MxICR register  *****************/
#define RAMCFG_ICR_CPED_Pos                 (1U)
#define RAMCFG_ICR_CPED_Msk                 (0x1UL << RAMCFG_ICR_CPED_Pos)            /*!< 0x00000002 */
#define RAMCFG_ICR_CPED                     RAMCFG_ICR_CPED_Msk                       /*!< Clear parity error detect bit */

/******************  Bit definition for RAMCFG_MxWPR1 register  *****************/
#define RAMCFG_WPR1_P0WP_Pos                (0U)
#define RAMCFG_WPR1_P0WP_Msk                (0x1UL << RAMCFG_WPR1_P0WP_Pos)           /*!< 0x00000001 */
#define RAMCFG_WPR1_P0WP                    RAMCFG_WPR1_P0WP_Msk                      /*!< Write Protection Page 00 */
#define RAMCFG_WPR1_P1WP_Pos                (1U)
#define RAMCFG_WPR1_P1WP_Msk                (0x1UL << RAMCFG_WPR1_P1WP_Pos)           /*!< 0x00000002 */
#define RAMCFG_WPR1_P1WP                    RAMCFG_WPR1_P1WP_Msk                      /*!< Write Protection Page 01 */
#define RAMCFG_WPR1_P2WP_Pos                (2U)
#define RAMCFG_WPR1_P2WP_Msk                (0x1UL << RAMCFG_WPR1_P2WP_Pos)           /*!< 0x00000004 */
#define RAMCFG_WPR1_P2WP                    RAMCFG_WPR1_P2WP_Msk                      /*!< Write Protection Page 02 */
#define RAMCFG_WPR1_P3WP_Pos                (3U)
#define RAMCFG_WPR1_P3WP_Msk                (0x1UL << RAMCFG_WPR1_P3WP_Pos)           /*!< 0x00000008 */
#define RAMCFG_WPR1_P3WP                    RAMCFG_WPR1_P3WP_Msk                      /*!< Write Protection Page 03 */
#define RAMCFG_WPR1_P4WP_Pos                (4U)
#define RAMCFG_WPR1_P4WP_Msk                (0x1UL << RAMCFG_WPR1_P4WP_Pos)           /*!< 0x00000010 */
#define RAMCFG_WPR1_P4WP                    RAMCFG_WPR1_P4WP_Msk                      /*!< Write Protection Page 04 */
#define RAMCFG_WPR1_P5WP_Pos                (5U)
#define RAMCFG_WPR1_P5WP_Msk                (0x1UL << RAMCFG_WPR1_P5WP_Pos)           /*!< 0x00000020 */
#define RAMCFG_WPR1_P5WP                    RAMCFG_WPR1_P5WP_Msk                      /*!< Write Protection Page 05 */
#define RAMCFG_WPR1_P6WP_Pos                (6U)
#define RAMCFG_WPR1_P6WP_Msk                (0x1UL << RAMCFG_WPR1_P6WP_Pos)           /*!< 0x00000040 */
#define RAMCFG_WPR1_P6WP                    RAMCFG_WPR1_P6WP_Msk                      /*!< Write Protection Page 06 */
#define RAMCFG_WPR1_P7WP_Pos                (7U)
#define RAMCFG_WPR1_P7WP_Msk                (0x1UL << RAMCFG_WPR1_P7WP_Pos)           /*!< 0x00000080 */
#define RAMCFG_WPR1_P7WP                    RAMCFG_WPR1_P7WP_Msk                      /*!< Write Protection Page 07 */
#define RAMCFG_WPR1_P8WP_Pos                (8U)
#define RAMCFG_WPR1_P8WP_Msk                (0x1UL << RAMCFG_WPR1_P8WP_Pos)           /*!< 0x00000100 */
#define RAMCFG_WPR1_P8WP                    RAMCFG_WPR1_P8WP_Msk                      /*!< Write Protection Page 08 */
#define RAMCFG_WPR1_P9WP_Pos                (9U)
#define RAMCFG_WPR1_P9WP_Msk                (0x1UL << RAMCFG_WPR1_P9WP_Pos)           /*!< 0x00000200 */
#define RAMCFG_WPR1_P9WP                    RAMCFG_WPR1_P9WP_Msk                      /*!< Write Protection Page 09 */
#define RAMCFG_WPR1_P10WP_Pos               (10U)
#define RAMCFG_WPR1_P10WP_Msk               (0x1UL << RAMCFG_WPR1_P10WP_Pos)          /*!< 0x00000400 */
#define RAMCFG_WPR1_P10WP                   RAMCFG_WPR1_P10WP_Msk                     /*!< Write Protection Page 10 */
#define RAMCFG_WPR1_P11WP_Pos               (11U)
#define RAMCFG_WPR1_P11WP_Msk               (0x1UL << RAMCFG_WPR1_P11WP_Pos)          /*!< 0x00000800 */
#define RAMCFG_WPR1_P11WP                   RAMCFG_WPR1_P11WP_Msk                     /*!< Write Protection Page 11 */
#define RAMCFG_WPR1_P12WP_Pos               (12U)
#define RAMCFG_WPR1_P12WP_Msk               (0x1UL << RAMCFG_WPR1_P12WP_Pos)          /*!< 0x00001000 */
#define RAMCFG_WPR1_P12WP                   RAMCFG_WPR1_P12WP_Msk                     /*!< Write Protection Page 12 */
#define RAMCFG_WPR1_P13WP_Pos               (13U)
#define RAMCFG_WPR1_P13WP_Msk               (0x1UL << RAMCFG_WPR1_P13WP_Pos)          /*!< 0x00002000 */
#define RAMCFG_WPR1_P13WP                   RAMCFG_WPR1_P13WP_Msk                     /*!< Write Protection Page 13 */
#define RAMCFG_WPR1_P14WP_Pos               (14U)
#define RAMCFG_WPR1_P14WP_Msk               (0x1UL << RAMCFG_WPR1_P14WP_Pos)          /*!< 0x00004000 */
#define RAMCFG_WPR1_P14WP                   RAMCFG_WPR1_P14WP_Msk                     /*!< Write Protection Page 14 */
#define RAMCFG_WPR1_P15WP_Pos               (15U)
#define RAMCFG_WPR1_P15WP_Msk               (0x1UL << RAMCFG_WPR1_P15WP_Pos)          /*!< 0x00008000 */
#define RAMCFG_WPR1_P15WP                   RAMCFG_WPR1_P15WP_Msk                     /*!< Write Protection Page 15 */
#define RAMCFG_WPR1_P16WP_Pos               (16U)
#define RAMCFG_WPR1_P16WP_Msk               (0x1UL << RAMCFG_WPR1_P16WP_Pos)          /*!< 0x00010000 */
#define RAMCFG_WPR1_P16WP                   RAMCFG_WPR1_P16WP_Msk                     /*!< Write Protection Page 16 */
#define RAMCFG_WPR1_P17WP_Pos               (17U)
#define RAMCFG_WPR1_P17WP_Msk               (0x1UL << RAMCFG_WPR1_P17WP_Pos)          /*!< 0x00020000 */
#define RAMCFG_WPR1_P17WP                   RAMCFG_WPR1_P17WP_Msk                     /*!< Write Protection Page 17 */
#define RAMCFG_WPR1_P18WP_Pos               (18U)
#define RAMCFG_WPR1_P18WP_Msk               (0x1UL << RAMCFG_WPR1_P18WP_Pos)          /*!< 0x00040000 */
#define RAMCFG_WPR1_P18WP                   RAMCFG_WPR1_P18WP_Msk                     /*!< Write Protection Page 18 */
#define RAMCFG_WPR1_P19WP_Pos               (19U)
#define RAMCFG_WPR1_P19WP_Msk               (0x1UL << RAMCFG_WPR1_P19WP_Pos)          /*!< 0x00080000 */
#define RAMCFG_WPR1_P19WP                   RAMCFG_WPR1_P19WP_Msk                     /*!< Write Protection Page 19 */
#define RAMCFG_WPR1_P20WP_Pos               (20U)
#define RAMCFG_WPR1_P20WP_Msk               (0x1UL << RAMCFG_WPR1_P20WP_Pos)          /*!< 0x00100000 */
#define RAMCFG_WPR1_P20WP                   RAMCFG_WPR1_P20WP_Msk                     /*!< Write Protection Page 20 */
#define RAMCFG_WPR1_P21WP_Pos               (21U)
#define RAMCFG_WPR1_P21WP_Msk               (0x1UL << RAMCFG_WPR1_P21WP_Pos)          /*!< 0x00200000 */
#define RAMCFG_WPR1_P21WP                   RAMCFG_WPR1_P21WP_Msk                     /*!< Write Protection Page 21 */
#define RAMCFG_WPR1_P22WP_Pos               (22U)
#define RAMCFG_WPR1_P22WP_Msk               (0x1UL << RAMCFG_WPR1_P22WP_Pos)          /*!< 0x00400000 */
#define RAMCFG_WPR1_P22WP                   RAMCFG_WPR1_P22WP_Msk                     /*!< Write Protection Page 22 */
#define RAMCFG_WPR1_P23WP_Pos               (23U)
#define RAMCFG_WPR1_P23WP_Msk               (0x1UL << RAMCFG_WPR1_P23WP_Pos)          /*!< 0x00800000 */
#define RAMCFG_WPR1_P23WP                   RAMCFG_WPR1_P23WP_Msk                     /*!< Write Protection Page 23 */
#define RAMCFG_WPR1_P24WP_Pos               (24U)
#define RAMCFG_WPR1_P24WP_Msk               (0x1UL << RAMCFG_WPR1_P24WP_Pos)          /*!< 0x01000000 */
#define RAMCFG_WPR1_P24WP                   RAMCFG_WPR1_P24WP_Msk                     /*!< Write Protection Page 24 */
#define RAMCFG_WPR1_P25WP_Pos               (25U)
#define RAMCFG_WPR1_P25WP_Msk               (0x1UL << RAMCFG_WPR1_P25WP_Pos)          /*!< 0x02000000 */
#define RAMCFG_WPR1_P25WP                   RAMCFG_WPR1_P25WP_Msk                     /*!< Write Protection Page 25 */
#define RAMCFG_WPR1_P26WP_Pos               (26U)
#define RAMCFG_WPR1_P26WP_Msk               (0x1UL << RAMCFG_WPR1_P26WP_Pos)          /*!< 0x04000000 */
#define RAMCFG_WPR1_P26WP                   RAMCFG_WPR1_P26WP_Msk                     /*!< Write Protection Page 26 */
#define RAMCFG_WPR1_P27WP_Pos               (27U)
#define RAMCFG_WPR1_P27WP_Msk               (0x1UL << RAMCFG_WPR1_P27WP_Pos)          /*!< 0x08000000 */
#define RAMCFG_WPR1_P27WP                   RAMCFG_WPR1_P27WP_Msk                     /*!< Write Protection Page 27 */
#define RAMCFG_WPR1_P28WP_Pos               (28U)
#define RAMCFG_WPR1_P28WP_Msk               (0x1UL << RAMCFG_WPR1_P28WP_Pos)          /*!< 0x10000000 */
#define RAMCFG_WPR1_P28WP                   RAMCFG_WPR1_P28WP_Msk                     /*!< Write Protection Page 28 */
#define RAMCFG_WPR1_P29WP_Pos               (29U)
#define RAMCFG_WPR1_P29WP_Msk               (0x1UL << RAMCFG_WPR1_P29WP_Pos)          /*!< 0x20000000 */
#define RAMCFG_WPR1_P29WP                   RAMCFG_WPR1_P29WP_Msk                     /*!< Write Protection Page 29 */
#define RAMCFG_WPR1_P30WP_Pos               (30U)
#define RAMCFG_WPR1_P30WP_Msk               (0x1UL << RAMCFG_WPR1_P30WP_Pos)          /*!< 0x40000000 */
#define RAMCFG_WPR1_P30WP                   RAMCFG_WPR1_P30WP_Msk                     /*!< Write Protection Page 30 */
#define RAMCFG_WPR1_P31WP_Pos               (31U)
#define RAMCFG_WPR1_P31WP_Msk               (0x1UL << RAMCFG_WPR1_P31WP_Pos)          /*!< 0x80000000 */
#define RAMCFG_WPR1_P31WP                   RAMCFG_WPR1_P31WP_Msk                     /*!< Write Protection Page 31 */

/******************  Bit definition for RAMCFG_MxWPR2 register  ****************/
#define RAMCFG_WPR2_P32WP_Pos               (0U)
#define RAMCFG_WPR2_P32WP_Msk               (0x1UL << RAMCFG_WPR2_P32WP_Pos)          /*!< 0x00000001 */
#define RAMCFG_WPR2_P32WP                   RAMCFG_WPR2_P32WP_Msk                     /*!< Write Protection Page 32 */
#define RAMCFG_WPR2_P33WP_Pos               (1U)
#define RAMCFG_WPR2_P33WP_Msk               (0x1UL << RAMCFG_WPR2_P33WP_Pos)          /*!< 0x00000002 */
#define RAMCFG_WPR2_P33WP                   RAMCFG_WPR2_P33WP_Msk                     /*!< Write Protection Page 33 */
#define RAMCFG_WPR2_P34WP_Pos               (2U)
#define RAMCFG_WPR2_P34WP_Msk               (0x1UL << RAMCFG_WPR2_P34WP_Pos)          /*!< 0x00000004 */
#define RAMCFG_WPR2_P34WP                   RAMCFG_WPR2_P34WP_Msk                     /*!< Write Protection Page 34 */
#define RAMCFG_WPR2_P35WP_Pos               (3U)
#define RAMCFG_WPR2_P35WP_Msk               (0x1UL << RAMCFG_WPR2_P35WP_Pos)          /*!< 0x00000008 */
#define RAMCFG_WPR2_P35WP                   RAMCFG_WPR2_P35WP_Msk                     /*!< Write Protection Page 35 */
#define RAMCFG_WPR2_P36WP_Pos               (4U)
#define RAMCFG_WPR2_P36WP_Msk               (0x1UL << RAMCFG_WPR2_P36WP_Pos)          /*!< 0x00000010 */
#define RAMCFG_WPR2_P36WP                   RAMCFG_WPR2_P36WP_Msk                     /*!< Write Protection Page 36 */
#define RAMCFG_WPR2_P37WP_Pos               (5U)
#define RAMCFG_WPR2_P37WP_Msk               (0x1UL << RAMCFG_WPR2_P37WP_Pos)          /*!< 0x00000020 */
#define RAMCFG_WPR2_P37WP                   RAMCFG_WPR2_P37WP_Msk                     /*!< Write Protection Page 37 */
#define RAMCFG_WPR2_P38WP_Pos               (6U)
#define RAMCFG_WPR2_P38WP_Msk               (0x1UL << RAMCFG_WPR2_P38WP_Pos)          /*!< 0x00000040 */
#define RAMCFG_WPR2_P38WP                   RAMCFG_WPR2_P38WP_Msk                     /*!< Write Protection Page 38 */
#define RAMCFG_WPR2_P39WP_Pos               (7U)
#define RAMCFG_WPR2_P39WP_Msk               (0x1UL << RAMCFG_WPR2_P39WP_Pos)          /*!< 0x00000080 */
#define RAMCFG_WPR2_P39WP                   RAMCFG_WPR2_P39WP_Msk                     /*!< Write Protection Page 39 */
#define RAMCFG_WPR2_P40WP_Pos               (8U)
#define RAMCFG_WPR2_P40WP_Msk               (0x1UL << RAMCFG_WPR2_P40WP_Pos)          /*!< 0x00000100 */
#define RAMCFG_WPR2_P40WP                   RAMCFG_WPR2_P40WP_Msk                     /*!< Write Protection Page 40 */
#define RAMCFG_WPR2_P41WP_Pos               (9U)
#define RAMCFG_WPR2_P41WP_Msk               (0x1UL << RAMCFG_WPR2_P41WP_Pos)          /*!< 0x00000200 */
#define RAMCFG_WPR2_P41WP                   RAMCFG_WPR2_P41WP_Msk                     /*!< Write Protection Page 41 */
#define RAMCFG_WPR2_P42WP_Pos               (10U)
#define RAMCFG_WPR2_P42WP_Msk               (0x1UL << RAMCFG_WPR2_P42WP_Pos)          /*!< 0x00000400 */
#define RAMCFG_WPR2_P42WP                   RAMCFG_WPR2_P42WP_Msk                     /*!< Write Protection Page 42 */
#define RAMCFG_WPR2_P43WP_Pos               (11U)
#define RAMCFG_WPR2_P43WP_Msk               (0x1UL << RAMCFG_WPR2_P43WP_Pos)          /*!< 0x00000800 */
#define RAMCFG_WPR2_P43WP                   RAMCFG_WPR2_P43WP_Msk                     /*!< Write Protection Page 43 */
#define RAMCFG_WPR2_P44WP_Pos               (12U)
#define RAMCFG_WPR2_P44WP_Msk               (0x1UL << RAMCFG_WPR2_P44WP_Pos)          /*!< 0x00001000 */
#define RAMCFG_WPR2_P44WP                   RAMCFG_WPR2_P44WP_Msk                     /*!< Write Protection Page 44 */
#define RAMCFG_WPR2_P45WP_Pos               (13U)
#define RAMCFG_WPR2_P45WP_Msk               (0x1UL << RAMCFG_WPR2_P45WP_Pos)          /*!< 0x00002000 */
#define RAMCFG_WPR2_P45WP                   RAMCFG_WPR2_P45WP_Msk                     /*!< Write Protection Page 45 */
#define RAMCFG_WPR2_P46WP_Pos               (14U)
#define RAMCFG_WPR2_P46WP_Msk               (0x1UL << RAMCFG_WPR2_P46WP_Pos)          /*!< 0x00004000 */
#define RAMCFG_WPR2_P46WP                   RAMCFG_WPR2_P46WP_Msk                     /*!< Write Protection Page 46 */
#define RAMCFG_WPR2_P47WP_Pos               (15U)
#define RAMCFG_WPR2_P47WP_Msk               (0x1UL << RAMCFG_WPR2_P47WP_Pos)          /*!< 0x00008000 */
#define RAMCFG_WPR2_P47WP                   RAMCFG_WPR2_P47WP_Msk                     /*!< Write Protection Page 47 */
#define RAMCFG_WPR2_P48WP_Pos               (16U)
#define RAMCFG_WPR2_P48WP_Msk               (0x1UL << RAMCFG_WPR2_P48WP_Pos)          /*!< 0x00010000 */
#define RAMCFG_WPR2_P48WP                   RAMCFG_WPR2_P48WP_Msk                     /*!< Write Protection Page 48 */
#define RAMCFG_WPR2_P49WP_Pos               (17U)
#define RAMCFG_WPR2_P49WP_Msk               (0x1UL << RAMCFG_WPR2_P49WP_Pos)          /*!< 0x00020000 */
#define RAMCFG_WPR2_P49WP                   RAMCFG_WPR2_P49WP_Msk                     /*!< Write Protection Page 49 */
#define RAMCFG_WPR2_P50WP_Pos               (18U)
#define RAMCFG_WPR2_P50WP_Msk               (0x1UL << RAMCFG_WPR2_P50WP_Pos)          /*!< 0x00040000 */
#define RAMCFG_WPR2_P50WP                   RAMCFG_WPR2_P50WP_Msk                     /*!< Write Protection Page 50 */
#define RAMCFG_WPR2_P51WP_Pos               (19U)
#define RAMCFG_WPR2_P51WP_Msk               (0x1UL << RAMCFG_WPR2_P51WP_Pos)          /*!< 0x00080000 */
#define RAMCFG_WPR2_P51WP                   RAMCFG_WPR2_P51WP_Msk                     /*!< Write Protection Page 51 */
#define RAMCFG_WPR2_P52WP_Pos               (20U)
#define RAMCFG_WPR2_P52WP_Msk               (0x1UL << RAMCFG_WPR2_P52WP_Pos)          /*!< 0x00100000 */
#define RAMCFG_WPR2_P52WP                   RAMCFG_WPR2_P52WP_Msk                     /*!< Write Protection Page 52 */
#define RAMCFG_WPR2_P53WP_Pos               (21U)
#define RAMCFG_WPR2_P53WP_Msk               (0x1UL << RAMCFG_WPR2_P53WP_Pos)          /*!< 0x00200000 */
#define RAMCFG_WPR2_P53WP                   RAMCFG_WPR2_P53WP_Msk                     /*!< Write Protection Page 53 */
#define RAMCFG_WPR2_P54WP_Pos               (22U)
#define RAMCFG_WPR2_P54WP_Msk               (0x1UL << RAMCFG_WPR2_P54WP_Pos)          /*!< 0x00400000 */
#define RAMCFG_WPR2_P54WP                   RAMCFG_WPR2_P54WP_Msk                     /*!< Write Protection Page 54 */
#define RAMCFG_WPR2_P55WP_Pos               (23U)
#define RAMCFG_WPR2_P55WP_Msk               (0x1UL << RAMCFG_WPR2_P55WP_Pos)          /*!< 0x00800000 */
#define RAMCFG_WPR2_P55WP                   RAMCFG_WPR2_P55WP_Msk                     /*!< Write Protection Page 55 */
#define RAMCFG_WPR2_P56WP_Pos               (25U)
#define RAMCFG_WPR2_P56WP_Msk               (0x1UL << RAMCFG_WPR2_P56WP_Pos)          /*!< 0x01000000 */
#define RAMCFG_WPR2_P56WP                   RAMCFG_WPR2_P56WP_Msk                     /*!< Write Protection Page 56 */
#define RAMCFG_WPR2_P57WP_Pos               (26U)
#define RAMCFG_WPR2_P57WP_Msk               (0x1UL << RAMCFG_WPR2_P57WP_Pos)          /*!< 0x02000000 */
#define RAMCFG_WPR2_P57WP                   RAMCFG_WPR2_P57WP_Msk                     /*!< Write Protection Page 57 */
#define RAMCFG_WPR2_P58WP_Pos               (27U)
#define RAMCFG_WPR2_P58WP_Msk               (0x1UL << RAMCFG_WPR2_P58WP_Pos)          /*!< 0x04000000 */
#define RAMCFG_WPR2_P58WP                   RAMCFG_WPR2_P58WP_Msk                     /*!< Write Protection Page 58 */
#define RAMCFG_WPR2_P59WP_Pos               (28U)
#define RAMCFG_WPR2_P59WP_Msk               (0x1UL << RAMCFG_WPR2_P59WP_Pos)          /*!< 0x08000000 */
#define RAMCFG_WPR2_P59WP                   RAMCFG_WPR2_P59WP_Msk                     /*!< Write Protection Page 59 */
#define RAMCFG_WPR2_P60WP_Pos               (29U)
#define RAMCFG_WPR2_P60WP_Msk               (0x1UL << RAMCFG_WPR2_P60WP_Pos)          /*!< 0x10000000 */
#define RAMCFG_WPR2_P60WP                   RAMCFG_WPR2_P60WP_Msk                     /*!< Write Protection Page 60 */
#define RAMCFG_WPR2_P61WP_Pos               (30U)
#define RAMCFG_WPR2_P61WP_Msk               (0x1UL << RAMCFG_WPR2_P61WP_Pos)          /*!< 0x20000000 */
#define RAMCFG_WPR2_P61WP                   RAMCFG_WPR2_P61WP_Msk                     /*!< Write Protection Page 61 */
#define RAMCFG_WPR2_P62WP_Pos               (31U)
#define RAMCFG_WPR2_P62WP_Msk               (0x1UL << RAMCFG_WPR2_P62WP_Pos)          /*!< 0x40000000 */
#define RAMCFG_WPR2_P62WP                   RAMCFG_WPR2_P62WP_Msk                     /*!< Write Protection Page 62 */
#define RAMCFG_WPR2_P63WP_Pos               (31U)
#define RAMCFG_WPR2_P63WP_Msk               (0x1UL << RAMCFG_WPR2_P63WP_Pos)          /*!< 0x80000000 */
#define RAMCFG_WPR2_P63WP                   RAMCFG_WPR2_P63WP_Msk                     /*!< Write Protection Page 63 */


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                    (8U)
#define RCC_CR_HSION_Msk                    (0x1UL << RCC_CR_HSION_Pos)             /*!< 0x00000100 */
#define RCC_CR_HSION                        RCC_CR_HSION_Msk                        /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                 (9U)
#define RCC_CR_HSIKERON_Msk                 (0x1UL << RCC_CR_HSIKERON_Pos)          /*!< 0x00000200 */
#define RCC_CR_HSIKERON                     RCC_CR_HSIKERON_Msk                     /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                   (10U)
#define RCC_CR_HSIRDY_Msk                   (0x1UL << RCC_CR_HSIRDY_Pos)            /*!< 0x00000400 */
#define RCC_CR_HSIRDY                       RCC_CR_HSIRDY_Msk                       /*!< Internal High Speed oscillator (HSI16) clock ready flag */
#define RCC_CR_HSEON_Pos                    (16U)
#define RCC_CR_HSEON_Msk                    (0x1UL << RCC_CR_HSEON_Pos)             /*!< 0x00010000 */
#define RCC_CR_HSEON                        RCC_CR_HSEON_Msk                        /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                   (17U)
#define RCC_CR_HSERDY_Msk                   (0x1UL << RCC_CR_HSERDY_Pos)            /*!< 0x00020000 */
#define RCC_CR_HSERDY                       RCC_CR_HSERDY_Msk                       /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_HSECSSON_Pos                 (19U)
#define RCC_CR_HSECSSON_Msk                 (0x1UL << RCC_CR_HSECSSON_Pos)          /*!< 0x00080000 */
#define RCC_CR_HSECSSON                     RCC_CR_HSECSSON_Msk                     /*!< External High Speed oscillator (HSE) clock security system enable */
#define RCC_CR_HSEPRE_Pos                   (20U)
#define RCC_CR_HSEPRE_Msk                   (0x1UL << RCC_CR_HSEPRE_Pos)             /*!< 0x00080000 */
#define RCC_CR_HSEPRE                       RCC_CR_HSEPRE_Msk                        /*!< External High Speed oscillator (HSE) clock for sysclk prescaler */
#define RCC_CR_PLL1ON_Pos                   (24U)
#define RCC_CR_PLL1ON_Msk                   (0x1UL << RCC_CR_PLL1ON_Pos)            /*!< 0x01000000 */
#define RCC_CR_PLL1ON                       RCC_CR_PLL1ON_Msk                       /*!< System PLL1 clock enable */
#define RCC_CR_PLL1RDY_Pos                  (25U)
#define RCC_CR_PLL1RDY_Msk                  (0x1UL << RCC_CR_PLL1RDY_Pos)           /*!< 0x02000000 */
#define RCC_CR_PLL1RDY                      RCC_CR_PLL1RDY_Msk                      /*!< System PLL1 clock ready */

/********************  Bit definition for RCC_ICSCR3 register  ***************/
#define RCC_ICSCR3_HSICAL_Pos               (0U)
#define RCC_ICSCR3_HSICAL_Msk               (0xFFFUL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000FFF */
#define RCC_ICSCR3_HSICAL                   RCC_ICSCR3_HSICAL_Msk                   /*!< HSICAL[11:0] bits */
#define RCC_ICSCR3_HSICAL_0                 (0x01UL << RCC_ICSCR3_HSICAL_Pos)       /*!< 0x00000001 */
#define RCC_ICSCR3_HSICAL_1                 (0x002UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000002 */
#define RCC_ICSCR3_HSICAL_2                 (0x004UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000004 */
#define RCC_ICSCR3_HSICAL_3                 (0x008UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000008 */
#define RCC_ICSCR3_HSICAL_4                 (0x010UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000010 */
#define RCC_ICSCR3_HSICAL_5                 (0x020UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000020 */
#define RCC_ICSCR3_HSICAL_6                 (0x040UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000040 */
#define RCC_ICSCR3_HSICAL_7                 (0x080UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000080 */
#define RCC_ICSCR3_HSICAL_8                 (0x100UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000100 */
#define RCC_ICSCR3_HSICAL_9                 (0x200UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000200 */
#define RCC_ICSCR3_HSICAL_10                (0x400UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000400 */
#define RCC_ICSCR3_HSICAL_11                (0x800UL << RCC_ICSCR3_HSICAL_Pos)      /*!< 0x00000800 */
#define RCC_ICSCR3_HSITRIM_Pos              (16U)
#define RCC_ICSCR3_HSITRIM_Msk              (0x1FUL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x001F0000 */
#define RCC_ICSCR3_HSITRIM                  RCC_ICSCR3_HSITRIM_Msk                  /*!< HSITRIM[4:0] bits */
#define RCC_ICSCR3_HSITRIM_0                (0x01UL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x00010000 */
#define RCC_ICSCR3_HSITRIM_1                (0x02UL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x00020000 */
#define RCC_ICSCR3_HSITRIM_2                (0x04UL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x00040000 */
#define RCC_ICSCR3_HSITRIM_3                (0x08UL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x00080000 */
#define RCC_ICSCR3_HSITRIM_4                (0x10UL << RCC_ICSCR3_HSITRIM_Pos)      /*!< 0x00100000 */

/********************  Bit definition for RCC_CFGR1 register  *****************/
#define RCC_CFGR1_SW_Pos                    (0U)
#define RCC_CFGR1_SW_Msk                    (0x3UL << RCC_CFGR1_SW_Pos)             /*!< 0x00000003 */
#define RCC_CFGR1_SW                        RCC_CFGR1_SW_Msk                        /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR1_SW_0                      (0x1UL << RCC_CFGR1_SW_Pos)             /*!< 0x00000001 */
#define RCC_CFGR1_SW_1                      (0x2UL << RCC_CFGR1_SW_Pos)             /*!< 0x00000002 */
#define RCC_CFGR1_SWS_Pos                   (2U)
#define RCC_CFGR1_SWS_Msk                   (0x3UL << RCC_CFGR1_SWS_Pos)            /*!< 0x0000000C */
#define RCC_CFGR1_SWS                       RCC_CFGR1_SWS_Msk                       /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR1_SWS_0                     (0x1UL << RCC_CFGR1_SWS_Pos)            /*!< 0x00000004 */
#define RCC_CFGR1_SWS_1                     (0x2UL << RCC_CFGR1_SWS_Pos)            /*!< 0x00000008 */
#define RCC_CFGR1_MCOSEL_Pos                (24U)
#define RCC_CFGR1_MCOSEL_Msk                (0xFUL << RCC_CFGR1_MCOSEL_Pos)         /*!< 0x0F000000 */
#define RCC_CFGR1_MCOSEL                    RCC_CFGR1_MCOSEL_Msk                    /*!< MCOSEL[3:0] bits (Clock output selection) */
#define RCC_CFGR1_MCOSEL_0                  (0x1UL << RCC_CFGR1_MCOSEL_Pos)         /*!< 0x01000000 */
#define RCC_CFGR1_MCOSEL_1                  (0x2UL << RCC_CFGR1_MCOSEL_Pos)         /*!< 0x02000000 */
#define RCC_CFGR1_MCOSEL_2                  (0x4UL << RCC_CFGR1_MCOSEL_Pos)         /*!< 0x04000000 */
#define RCC_CFGR1_MCOSEL_3                  (0x8UL << RCC_CFGR1_MCOSEL_Pos)         /*!< 0x08000000 */
#define RCC_CFGR1_MCOPRE_Pos                (28U)
#define RCC_CFGR1_MCOPRE_Msk                (0x7UL << RCC_CFGR1_MCOPRE_Pos)         /*!< 0x70000000 */
#define RCC_CFGR1_MCOPRE                    RCC_CFGR1_MCOPRE_Msk                    /*!< MCO[220] (Prescaler) */
#define RCC_CFGR1_MCOPRE_0                  (0x1UL << RCC_CFGR1_MCOPRE_Pos)         /*!< 0x10000000 */
#define RCC_CFGR1_MCOPRE_1                  (0x2UL << RCC_CFGR1_MCOPRE_Pos)         /*!< 0x20000000 */
#define RCC_CFGR1_MCOPRE_2                  (0x4UL << RCC_CFGR1_MCOPRE_Pos)         /*!< 0x40000000 */

/********************  Bit definition for RCC_CFGR2 register  ******************/
#define RCC_CFGR2_HPRE_Pos                  (0U)
#define RCC_CFGR2_HPRE_Msk                  (0x7UL << RCC_CFGR2_HPRE_Pos)           /*!< 0x00000007 */
#define RCC_CFGR2_HPRE                      RCC_CFGR2_HPRE_Msk                      /*!< HPRE[2:0] bits (AHB prescaler) */
#define RCC_CFGR2_HPRE_0                    (0x1UL << RCC_CFGR2_HPRE_Pos)           /*!< 0x00000001 */
#define RCC_CFGR2_HPRE_1                    (0x2UL << RCC_CFGR2_HPRE_Pos)           /*!< 0x00000002 */
#define RCC_CFGR2_HPRE_2                    (0x4UL << RCC_CFGR2_HPRE_Pos)           /*!< 0x00000004 */
#define RCC_CFGR2_PPRE1_Pos                 (4U)
#define RCC_CFGR2_PPRE1_Msk                 (0x7UL << RCC_CFGR2_PPRE1_Pos)          /*!< 0x00000070 */
#define RCC_CFGR2_PPRE1                     RCC_CFGR2_PPRE1_Msk                     /*!< PPRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR2_PPRE1_0                   (0x1UL << RCC_CFGR2_PPRE1_Pos)          /*!< 0x00000010 */
#define RCC_CFGR2_PPRE1_1                   (0x2UL << RCC_CFGR2_PPRE1_Pos)          /*!< 0x00000020 */
#define RCC_CFGR2_PPRE1_2                   (0x4UL << RCC_CFGR2_PPRE1_Pos)          /*!< 0x00000040 */
#define RCC_CFGR2_PPRE2_Pos                 (8U)
#define RCC_CFGR2_PPRE2_Msk                 (0x7UL << RCC_CFGR2_PPRE2_Pos)          /*!< 0x00000700 */
#define RCC_CFGR2_PPRE2                     RCC_CFGR2_PPRE2_Msk                     /*!< PPRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR2_PPRE2_0                   (0x1UL << RCC_CFGR2_PPRE2_Pos)          /*!< 0x00000100 */
#define RCC_CFGR2_PPRE2_1                   (0x2UL << RCC_CFGR2_PPRE2_Pos)          /*!< 0x00000200 */
#define RCC_CFGR2_PPRE2_2                   (0x4UL << RCC_CFGR2_PPRE2_Pos)          /*!< 0x00000400 */

/********************  Bit definition for RCC_CFGR3 register  ******************/
#define RCC_CFGR3_PPRE7_Pos                 (4U)
#define RCC_CFGR3_PPRE7_Msk                 (0x7UL << RCC_CFGR3_PPRE7_Pos)          /*!< 0x00000070 */
#define RCC_CFGR3_PPRE7                     RCC_CFGR3_PPRE7_Msk                     /*!< PPRE7[2:0] bits (APB7 prescaler) */
#define RCC_CFGR3_PPRE7_0                   (0x1UL << RCC_CFGR3_PPRE7_Pos)          /*!< 0x00000010 */
#define RCC_CFGR3_PPRE7_1                   (0x2UL << RCC_CFGR3_PPRE7_Pos)          /*!< 0x00000020 */
#define RCC_CFGR3_PPRE7_2                   (0x4UL << RCC_CFGR3_PPRE7_Pos)          /*!< 0x00000040 */

/********************  Bit definition for RCC_PLL1CFGR register  ***************/
#define RCC_PLL1CFGR_PLL1SRC_Pos            (0U)
#define RCC_PLL1CFGR_PLL1SRC_Msk            (0x3UL << RCC_PLL1CFGR_PLL1SRC_Pos)     /*!< 0x00000003 */
#define RCC_PLL1CFGR_PLL1SRC                RCC_PLL1CFGR_PLL1SRC_Msk
#define RCC_PLL1CFGR_PLL1SRC_0              (0x1UL << RCC_PLL1CFGR_PLL1SRC_Pos)     /*!< 0x00000001 */
#define RCC_PLL1CFGR_PLL1SRC_1              (0x2UL << RCC_PLL1CFGR_PLL1SRC_Pos)     /*!< 0x00000002 */
#define RCC_PLL1CFGR_PLL1RGE_Pos            (2U)
#define RCC_PLL1CFGR_PLL1RGE_Msk            (0x3UL << RCC_PLL1CFGR_PLL1RGE_Pos)     /*!< 0x0000000C */
#define RCC_PLL1CFGR_PLL1RGE                RCC_PLL1CFGR_PLL1RGE_Msk
#define RCC_PLL1CFGR_PLL1RGE_0              (0x1UL << RCC_PLL1CFGR_PLL1RGE_Pos)     /*!< 0x00000004 */
#define RCC_PLL1CFGR_PLL1RGE_1              (0x2UL << RCC_PLL1CFGR_PLL1RGE_Pos)     /*!< 0x00000008 */
#define RCC_PLL1CFGR_PLL1FRACEN_Pos         (4U)
#define RCC_PLL1CFGR_PLL1FRACEN_Msk         (0x1UL << RCC_PLL1CFGR_PLL1FRACEN_Pos)  /*!< 0x00000010 */
#define RCC_PLL1CFGR_PLL1FRACEN             RCC_PLL1CFGR_PLL1FRACEN_Msk
#define RCC_PLL1CFGR_PLL1M_Pos              (8U)
#define RCC_PLL1CFGR_PLL1M_Msk              (0x7UL << RCC_PLL1CFGR_PLL1M_Pos)       /*!< 0x00000700 */
#define RCC_PLL1CFGR_PLL1M                  RCC_PLL1CFGR_PLL1M_Msk
#define RCC_PLL1CFGR_PLL1M_0                (0x01UL << RCC_PLL1CFGR_PLL1M_Pos)      /*!< 0x00000100 */
#define RCC_PLL1CFGR_PLL1M_1                (0x02UL << RCC_PLL1CFGR_PLL1M_Pos)      /*!< 0x00000200 */
#define RCC_PLL1CFGR_PLL1M_2                (0x04UL << RCC_PLL1CFGR_PLL1M_Pos)      /*!< 0x00000400 */
#define RCC_PLL1CFGR_PLL1PEN_Pos            (16U)
#define RCC_PLL1CFGR_PLL1PEN_Msk            (0x1UL << RCC_PLL1CFGR_PLL1PEN_Pos)     /*!< 0x00010000 */
#define RCC_PLL1CFGR_PLL1PEN                RCC_PLL1CFGR_PLL1PEN_Msk
#define RCC_PLL1CFGR_PLL1QEN_Pos            (17U)
#define RCC_PLL1CFGR_PLL1QEN_Msk            (0x1UL << RCC_PLL1CFGR_PLL1QEN_Pos)     /*!< 0x00020000 */
#define RCC_PLL1CFGR_PLL1QEN                RCC_PLL1CFGR_PLL1QEN_Msk
#define RCC_PLL1CFGR_PLL1REN_Pos            (18U)
#define RCC_PLL1CFGR_PLL1REN_Msk            (0x1UL << RCC_PLL1CFGR_PLL1REN_Pos)     /*!< 0x00040000 */
#define RCC_PLL1CFGR_PLL1REN                RCC_PLL1CFGR_PLL1REN_Msk
#define RCC_PLL1CFGR_PLL1RCLKPRE_Pos        (20U)
#define RCC_PLL1CFGR_PLL1RCLKPRE_Msk        (0x1UL << RCC_PLL1CFGR_PLL1RCLKPRE_Pos) /*!< 0x00100000 */
#define RCC_PLL1CFGR_PLL1RCLKPRE            RCC_PLL1CFGR_PLL1RCLKPRE_Msk
#define RCC_PLL1CFGR_PLL1RCLKPRESTEP_Pos    (21U)
#define RCC_PLL1CFGR_PLL1RCLKPRESTEP_Msk    (0x1UL << RCC_PLL1CFGR_PLL1RCLKPRESTEP_Pos) /*!< 0x00200000 */
#define RCC_PLL1CFGR_PLL1RCLKPRESTEP        RCC_PLL1CFGR_PLL1RCLKPRESTEP_Msk
#define RCC_PLL1CFGR_PLL1RCLKPRERDY_Pos     (22U)
#define RCC_PLL1CFGR_PLL1RCLKPRERDY_Msk     (0x1UL << RCC_PLL1CFGR_PLL1RCLKPRERDY_Pos)  /*!< 0x00400000 */
#define RCC_PLL1CFGR_PLL1RCLKPRERDY         RCC_PLL1CFGR_PLL1RCLKPRERDY_Msk

/********************  Bit definition for RCC_PLL1DIVR register  ***************/
#define RCC_PLL1DIVR_PLL1N_Pos              (0U)
#define RCC_PLL1DIVR_PLL1N_Msk              (0x1FFUL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x000001FF */
#define RCC_PLL1DIVR_PLL1N                  RCC_PLL1DIVR_PLL1N_Msk
#define RCC_PLL1DIVR_PLL1N_0                (0x001UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000001 */
#define RCC_PLL1DIVR_PLL1N_1                (0x002UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000002 */
#define RCC_PLL1DIVR_PLL1N_2                (0x004UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000004 */
#define RCC_PLL1DIVR_PLL1N_3                (0x008UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000008 */
#define RCC_PLL1DIVR_PLL1N_4                (0x010UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000010 */
#define RCC_PLL1DIVR_PLL1N_5                (0x020UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000020 */
#define RCC_PLL1DIVR_PLL1N_6                (0x040UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000040 */
#define RCC_PLL1DIVR_PLL1N_7                (0x080UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000080 */
#define RCC_PLL1DIVR_PLL1N_8                (0x100UL << RCC_PLL1DIVR_PLL1N_Pos)     /*!< 0x00000100 */
#define RCC_PLL1DIVR_PLL1P_Pos              (9U)
#define RCC_PLL1DIVR_PLL1P_Msk              (0x7FUL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x0000FE00 */
#define RCC_PLL1DIVR_PLL1P                  RCC_PLL1DIVR_PLL1P_Msk
#define RCC_PLL1DIVR_PLL1P_0                (0x01UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00000200 */
#define RCC_PLL1DIVR_PLL1P_1                (0x02UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00000400 */
#define RCC_PLL1DIVR_PLL1P_2                (0x04UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00000800 */
#define RCC_PLL1DIVR_PLL1P_3                (0x08UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00001000 */
#define RCC_PLL1DIVR_PLL1P_4                (0x10UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00002000 */
#define RCC_PLL1DIVR_PLL1P_5                (0x20UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00004000 */
#define RCC_PLL1DIVR_PLL1P_6                (0x40UL << RCC_PLL1DIVR_PLL1P_Pos)      /*!< 0x00008000 */
#define RCC_PLL1DIVR_PLL1Q_Pos              (16U)
#define RCC_PLL1DIVR_PLL1Q_Msk              (0x7FUL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x007F0000 */
#define RCC_PLL1DIVR_PLL1Q                  RCC_PLL1DIVR_PLL1Q_Msk
#define RCC_PLL1DIVR_PLL1Q_0                (0x01UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00010000 */
#define RCC_PLL1DIVR_PLL1Q_1                (0x02UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00020000 */
#define RCC_PLL1DIVR_PLL1Q_2                (0x04UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00040000 */
#define RCC_PLL1DIVR_PLL1Q_3                (0x08UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00080000 */
#define RCC_PLL1DIVR_PLL1Q_4                (0x10UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00100000 */
#define RCC_PLL1DIVR_PLL1Q_5                (0x20UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00200020 */
#define RCC_PLL1DIVR_PLL1Q_6                (0x40UL << RCC_PLL1DIVR_PLL1Q_Pos)      /*!< 0x00400000 */
#define RCC_PLL1DIVR_PLL1R_Pos              (24U)
#define RCC_PLL1DIVR_PLL1R_Msk              (0x7FUL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x7F000000 */
#define RCC_PLL1DIVR_PLL1R                  RCC_PLL1DIVR_PLL1R_Msk
#define RCC_PLL1DIVR_PLL1R_0                (0x01UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x01000000 */
#define RCC_PLL1DIVR_PLL1R_1                (0x02UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x02000000 */
#define RCC_PLL1DIVR_PLL1R_2                (0x04UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x04000000 */
#define RCC_PLL1DIVR_PLL1R_3                (0x08UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x08000000 */
#define RCC_PLL1DIVR_PLL1R_4                (0x10UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x10000000 */
#define RCC_PLL1DIVR_PLL1R_5                (0x20UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x20000000 */
#define RCC_PLL1DIVR_PLL1R_6                (0x40UL << RCC_PLL1DIVR_PLL1R_Pos)      /*!< 0x40000000 */

/********************  Bit definition for RCC_PLL1FRACR register  ***************/
#define RCC_PLL1FRACR_PLL1FRACN_Pos         (3U)
#define RCC_PLL1FRACR_PLL1FRACN_Msk         (0x1FFFUL << RCC_PLL1FRACR_PLL1FRACN_Pos) /*!< 0x0000FFF8 */
#define RCC_PLL1FRACR_PLL1FRACN             RCC_PLL1FRACR_PLL1FRACN_Msk

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSI1RDYIE_Pos              (0U)
#define RCC_CIER_LSI1RDYIE_Msk              (0x1UL << RCC_CIER_LSI1RDYIE_Pos)       /*!< 0x00000001 */
#define RCC_CIER_LSI1RDYIE                  RCC_CIER_LSI1RDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos               (1U)
#define RCC_CIER_LSERDYIE_Msk               (0x1UL << RCC_CIER_LSERDYIE_Pos)        /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                   RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos               (3U)
#define RCC_CIER_HSIRDYIE_Msk               (0x1UL << RCC_CIER_HSIRDYIE_Pos)        /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                   RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos               (4U)
#define RCC_CIER_HSERDYIE_Msk               (0x1UL << RCC_CIER_HSERDYIE_Pos)        /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                   RCC_CIER_HSERDYIE_Msk
#define RCC_CIER_PLL1RDYIE_Pos              (6U)
#define RCC_CIER_PLL1RDYIE_Msk              (0x1UL << RCC_CIER_PLL1RDYIE_Pos)       /*!< 0x00000040 */
#define RCC_CIER_PLL1RDYIE                  RCC_CIER_PLL1RDYIE_Msk

/********************  Bit definition for RCC_CIFR register  ****************/
#define RCC_CIFR_LSI1RDYF_Pos               (0U)
#define RCC_CIFR_LSI1RDYF_Msk               (0x1UL << RCC_CIFR_LSI1RDYF_Pos)        /*!< 0x00000001 */
#define RCC_CIFR_LSI1RDYF                   RCC_CIFR_LSI1RDYF_Msk
#define RCC_CIFR_LSERDYF_Pos                (1U)
#define RCC_CIFR_LSERDYF_Msk                (0x1UL << RCC_CIFR_LSERDYF_Pos)         /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                    RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos                (3U)
#define RCC_CIFR_HSIRDYF_Msk                (0x1UL << RCC_CIFR_HSIRDYF_Pos)         /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                    RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos                (4U)
#define RCC_CIFR_HSERDYF_Msk                (0x1UL << RCC_CIFR_HSERDYF_Pos)         /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                    RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_PLL1RDYF_Pos               (6U)
#define RCC_CIFR_PLL1RDYF_Msk               (0x1UL << RCC_CIFR_PLL1RDYF_Pos)        /*!< 0x00000040 */
#define RCC_CIFR_PLL1RDYF                   RCC_CIFR_PLL1RDYF_Msk
#define RCC_CIFR_HSECSSF_Pos                (10U)
#define RCC_CIFR_HSECSSF_Msk                (0x1UL << RCC_CIFR_HSECSSF_Pos)         /*!< 0x00000400 */
#define RCC_CIFR_HSECSSF                    RCC_CIFR_HSECSSF_Msk

/********************  Bit definition for RCC_CICR register  ****************/
#define RCC_CICR_LSI1RDYC_Pos               (0U)
#define RCC_CICR_LSI1RDYC_Msk               (0x1UL << RCC_CICR_LSI1RDYC_Pos)        /*!< 0x00000001 */
#define RCC_CICR_LSI1RDYC                   RCC_CICR_LSI1RDYC_Msk
#define RCC_CICR_LSERDYC_Pos                (1U)
#define RCC_CICR_LSERDYC_Msk                (0x1UL << RCC_CICR_LSERDYC_Pos)         /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                    RCC_CICR_LSERDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                (3U)
#define RCC_CICR_HSIRDYC_Msk                (0x1UL << RCC_CICR_HSIRDYC_Pos)         /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                    RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos                (4U)
#define RCC_CICR_HSERDYC_Msk                (0x1UL << RCC_CICR_HSERDYC_Pos)         /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                    RCC_CICR_HSERDYC_Msk
#define RCC_CICR_PLL1RDYC_Pos               (6U)
#define RCC_CICR_PLL1RDYC_Msk               (0x1UL << RCC_CICR_PLL1RDYC_Pos)        /*!< 0x00000040 */
#define RCC_CICR_PLL1RDYC                   RCC_CICR_PLL1RDYC_Msk
#define RCC_CICR_HSECSSC_Pos                (10U)
#define RCC_CICR_HSECSSC_Msk                (0x1UL << RCC_CICR_HSECSSC_Pos)         /*!< 0x00000400 */
#define RCC_CICR_HSECSSC                    RCC_CICR_HSECSSC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPDMA1RST_Pos          (0U)
#define RCC_AHB1RSTR_GPDMA1RST_Msk          (0x1UL << RCC_AHB1RSTR_GPDMA1RST_Pos)   /*!< 0x00000001 */
#define RCC_AHB1RSTR_GPDMA1RST              RCC_AHB1RSTR_GPDMA1RST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos             (12U)
#define RCC_AHB1RSTR_CRCRST_Msk             (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)      /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                 RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_TSCRST_Pos             (16U)
#define RCC_AHB1RSTR_TSCRST_Msk             (0x1UL << RCC_AHB1RSTR_TSCRST_Pos)      /*!< 0x00010000 */
#define RCC_AHB1RSTR_TSCRST                 RCC_AHB1RSTR_TSCRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_GPIOARST_Pos           (0U)
#define RCC_AHB2RSTR_GPIOARST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOARST_Pos)    /*!< 0x00000001 */
#define RCC_AHB2RSTR_GPIOARST               RCC_AHB2RSTR_GPIOARST_Msk
#define RCC_AHB2RSTR_GPIOBRST_Pos           (1U)
#define RCC_AHB2RSTR_GPIOBRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOBRST_Pos)    /*!< 0x00000002 */
#define RCC_AHB2RSTR_GPIOBRST               RCC_AHB2RSTR_GPIOBRST_Msk
#define RCC_AHB2RSTR_GPIOCRST_Pos           (2U)
#define RCC_AHB2RSTR_GPIOCRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOCRST_Pos)    /*!< 0x00000004 */
#define RCC_AHB2RSTR_GPIOCRST               RCC_AHB2RSTR_GPIOCRST_Msk
#define RCC_AHB2RSTR_GPIOHRST_Pos           (7U)
#define RCC_AHB2RSTR_GPIOHRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOHRST_Pos)    /*!< 0x00000080 */
#define RCC_AHB2RSTR_GPIOHRST               RCC_AHB2RSTR_GPIOHRST_Msk
#define RCC_AHB2RSTR_AESRST_Pos             (16U)
#define RCC_AHB2RSTR_AESRST_Msk             (0x1UL << RCC_AHB2RSTR_AESRST_Pos)      /*!< 0x00010000 */
#define RCC_AHB2RSTR_AESRST                 RCC_AHB2RSTR_AESRST_Msk
#define RCC_AHB2RSTR_HASHRST_Pos            (17U)
#define RCC_AHB2RSTR_HASHRST_Msk            (0x1UL << RCC_AHB2RSTR_HASHRST_Pos)     /*!< 0x00020000 */
#define RCC_AHB2RSTR_HASHRST                RCC_AHB2RSTR_HASHRST_Msk
#define RCC_AHB2RSTR_RNGRST_Pos             (18U)
#define RCC_AHB2RSTR_RNGRST_Msk             (0x1UL << RCC_AHB2RSTR_RNGRST_Pos)      /*!< 0x00040000 */
#define RCC_AHB2RSTR_RNGRST                 RCC_AHB2RSTR_RNGRST_Msk
#define RCC_AHB2RSTR_HSEMRST_Pos            (20U)
#define RCC_AHB2RSTR_HSEMRST_Msk            (0x1UL << RCC_AHB2RSTR_HSEMRST_Pos)     /*!< 0x00100000 */
#define RCC_AHB2RSTR_HSEMRST                RCC_AHB2RSTR_HSEMRST_Msk
#define RCC_AHB2RSTR_PKARST_Pos             (21U)
#define RCC_AHB2RSTR_PKARST_Msk             (0x1UL << RCC_AHB2RSTR_PKARST_Pos)      /*!< 0x00200000 */
#define RCC_AHB2RSTR_PKARST                 RCC_AHB2RSTR_PKARST_Msk

/********************  Bit definition for RCC_AHB4RSTR register  **************/
#define RCC_AHB4RSTR_ADC4RST_Pos            (5U)
#define RCC_AHB4RSTR_ADC4RST_Msk            (0x1UL << RCC_AHB4RSTR_ADC4RST_Pos)     /*!< 0x00000020 */
#define RCC_AHB4RSTR_ADC4RST                RCC_AHB4RSTR_ADC4RST_Msk

/********************  Bit definition for RCC_AHB5RSTR register  **************/
#define RCC_AHB5RSTR_RADIORST_Pos           (0U)
#define RCC_AHB5RSTR_RADIORST_Msk           (0x1UL << RCC_AHB5RSTR_RADIORST_Pos)    /*!< 0x00000001 */
#define RCC_AHB5RSTR_RADIORST               RCC_AHB5RSTR_RADIORST_Msk

/********************  Bit definition for RCC_APB1RSTR1 register  **************/
#define RCC_APB1RSTR1_TIM2RST_Pos           (0U)
#define RCC_APB1RSTR1_TIM2RST_Msk           (0x1UL << RCC_APB1RSTR1_TIM2RST_Pos)    /*!< 0x00000001 */
#define RCC_APB1RSTR1_TIM2RST               RCC_APB1RSTR1_TIM2RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos            (11U)
#define RCC_APB2RSTR_TIM1RST_Msk            (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)     /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos          (14U)
#define RCC_APB2RSTR_USART1RST_Msk          (0x1UL << RCC_APB2RSTR_USART1RST_Pos)   /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST              RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_TIM16RST_Pos           (17U)
#define RCC_APB2RSTR_TIM16RST_Msk           (0x1UL << RCC_APB2RSTR_TIM16RST_Pos)    /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM16RST               RCC_APB2RSTR_TIM16RST_Msk

/********************  Bit definition for RCC_APB7RSTR register  **************/
#define RCC_APB7RSTR_SYSCFGRST_Pos          (1U)
#define RCC_APB7RSTR_SYSCFGRST_Msk          (0x1UL << RCC_APB7RSTR_SYSCFGRST_Pos)   /*!< 0x00000002 */
#define RCC_APB7RSTR_SYSCFGRST              RCC_APB7RSTR_SYSCFGRST_Msk
#define RCC_APB7RSTR_SPI3RST_Pos            (5U)
#define RCC_APB7RSTR_SPI3RST_Msk            (0x1UL << RCC_APB7RSTR_SPI3RST_Pos)     /*!< 0x00000020 */
#define RCC_APB7RSTR_SPI3RST                RCC_APB7RSTR_SPI3RST_Msk
#define RCC_APB7RSTR_LPUART1RST_Pos         (6U)
#define RCC_APB7RSTR_LPUART1RST_Msk         (0x1UL << RCC_APB7RSTR_LPUART1RST_Pos)  /*!< 0x00000040 */
#define RCC_APB7RSTR_LPUART1RST             RCC_APB7RSTR_LPUART1RST_Msk
#define RCC_APB7RSTR_I2C3RST_Pos            (7U)
#define RCC_APB7RSTR_I2C3RST_Msk            (0x1UL << RCC_APB7RSTR_I2C3RST_Pos)     /*!< 0x00000080 */
#define RCC_APB7RSTR_I2C3RST                RCC_APB7RSTR_I2C3RST_Msk
#define RCC_APB7RSTR_LPTIM1RST_Pos          (11U)
#define RCC_APB7RSTR_LPTIM1RST_Msk          (0x1UL << RCC_APB7RSTR_LPTIM1RST_Pos)   /*!< 0x00000800 */
#define RCC_APB7RSTR_LPTIM1RST              RCC_APB7RSTR_LPTIM1RST_Msk

/********************  Bit definition for RCC_AHB1ENR register  **************/
#define RCC_AHB1ENR_GPDMA1EN_Pos            (0U)
#define RCC_AHB1ENR_GPDMA1EN_Msk            (0x1UL << RCC_AHB1ENR_GPDMA1EN_Pos)     /*!< 0x00000001 */
#define RCC_AHB1ENR_GPDMA1EN                RCC_AHB1ENR_GPDMA1EN_Msk
#define RCC_AHB1ENR_FLASHEN_Pos             (8U)
#define RCC_AHB1ENR_FLASHEN_Msk             (0x1UL << RCC_AHB1ENR_FLASHEN_Pos)      /*!< 0x00000100 */
#define RCC_AHB1ENR_FLASHEN                 RCC_AHB1ENR_FLASHEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos               (12U)
#define RCC_AHB1ENR_CRCEN_Msk               (0x1UL << RCC_AHB1ENR_CRCEN_Pos)        /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                   RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_TSCEN_Pos               (16U)
#define RCC_AHB1ENR_TSCEN_Msk               (0x1UL << RCC_AHB1ENR_TSCEN_Pos)        /*!< 0x00010000 */
#define RCC_AHB1ENR_TSCEN                   RCC_AHB1ENR_TSCEN_Msk
#define RCC_AHB1ENR_RAMCFGEN_Pos            (17U)
#define RCC_AHB1ENR_RAMCFGEN_Msk            (0x1UL << RCC_AHB1ENR_RAMCFGEN_Pos)     /*!< 0x00020000 */
#define RCC_AHB1ENR_RAMCFGEN                RCC_AHB1ENR_RAMCFGEN_Msk
#define RCC_AHB1ENR_SRAM1EN_Pos             (31U)
#define RCC_AHB1ENR_SRAM1EN_Msk             (0x1UL << RCC_AHB1ENR_SRAM1EN_Pos)      /*!< 0x80000000 */
#define RCC_AHB1ENR_SRAM1EN                 RCC_AHB1ENR_SRAM1EN_Msk

/********************  Bit definition for RCC_AHB2ENR register  **************/
#define RCC_AHB2ENR_GPIOAEN_Pos             (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos)      /*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                 RCC_AHB2ENR_GPIOAEN_Msk
#define RCC_AHB2ENR_GPIOBEN_Pos             (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOBEN_Pos)      /*!< 0x00000002 */
#define RCC_AHB2ENR_GPIOBEN                 RCC_AHB2ENR_GPIOBEN_Msk
#define RCC_AHB2ENR_GPIOCEN_Pos             (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOCEN_Pos)      /*!< 0x00000004 */
#define RCC_AHB2ENR_GPIOCEN                 RCC_AHB2ENR_GPIOCEN_Msk
#define RCC_AHB2ENR_GPIOHEN_Pos             (7U)
#define RCC_AHB2ENR_GPIOHEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOHEN_Pos)      /*!< 0x00000080 */
#define RCC_AHB2ENR_GPIOHEN                 RCC_AHB2ENR_GPIOHEN_Msk
#define RCC_AHB2ENR_AESEN_Pos               (16U)
#define RCC_AHB2ENR_AESEN_Msk               (0x1UL << RCC_AHB2ENR_AESEN_Pos)        /*!< 0x00010000 */
#define RCC_AHB2ENR_AESEN                   RCC_AHB2ENR_AESEN_Msk
#define RCC_AHB2ENR_HASHEN_Pos              (17U)
#define RCC_AHB2ENR_HASHEN_Msk              (0x1UL << RCC_AHB2ENR_HASHEN_Pos)       /*!< 0x00020000 */
#define RCC_AHB2ENR_HASHEN                  RCC_AHB2ENR_HASHEN_Msk
#define RCC_AHB2ENR_RNGEN_Pos               (18U)
#define RCC_AHB2ENR_RNGEN_Msk               (0x1UL << RCC_AHB2ENR_RNGEN_Pos)        /*!< 0x00040000 */
#define RCC_AHB2ENR_RNGEN                   RCC_AHB2ENR_RNGEN_Msk
#define RCC_AHB2ENR_HSEMEN_Pos              (20U)
#define RCC_AHB2ENR_HSEMEN_Msk              (0x1UL << RCC_AHB2ENR_HSEMEN_Pos)       /*!< 0x00100000 */
#define RCC_AHB2ENR_HSEMEN                  RCC_AHB2ENR_HSEMEN_Msk
#define RCC_AHB2ENR_PKAEN_Pos               (21U)
#define RCC_AHB2ENR_PKAEN_Msk               (0x1UL << RCC_AHB2ENR_PKAEN_Pos)        /*!< 0x00200000 */
#define RCC_AHB2ENR_PKAEN                   RCC_AHB2ENR_PKAEN_Msk
#define RCC_AHB2ENR_SRAM2EN_Pos             (30U)
#define RCC_AHB2ENR_SRAM2EN_Msk             (0x1UL << RCC_AHB2ENR_SRAM2EN_Pos)      /*!< 0x40000000 */
#define RCC_AHB2ENR_SRAM2EN                 RCC_AHB2ENR_SRAM2EN_Msk

/********************  Bit definition for RCC_AHB4ENR register  **************/
#define RCC_AHB4ENR_PWREN_Pos               (2U)
#define RCC_AHB4ENR_PWREN_Msk               (0x1UL << RCC_AHB4ENR_PWREN_Pos)        /*!< 0x00000004 */
#define RCC_AHB4ENR_PWREN                   RCC_AHB4ENR_PWREN_Msk
#define RCC_AHB4ENR_ADC4EN_Pos              (5U)
#define RCC_AHB4ENR_ADC4EN_Msk              (0x1UL << RCC_AHB4ENR_ADC4EN_Pos)       /*!< 0x00000020 */
#define RCC_AHB4ENR_ADC4EN                  RCC_AHB4ENR_ADC4EN_Msk

/********************  Bit definition for RCC_AHB5ENR register  **************/
#define RCC_AHB5ENR_RADIOEN_Pos             (0U)
#define RCC_AHB5ENR_RADIOEN_Msk             (0x1UL << RCC_AHB5ENR_RADIOEN_Pos)      /*!< 0x00000001 */
#define RCC_AHB5ENR_RADIOEN                 RCC_AHB5ENR_RADIOEN_Msk

/********************  Bit definition for RCC_APB1ENR1 register  **************/
#define RCC_APB1ENR1_TIM2EN_Pos             (0U)
#define RCC_APB1ENR1_TIM2EN_Msk             (0x1UL << RCC_APB1ENR1_TIM2EN_Pos)      /*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                 RCC_APB1ENR1_TIM2EN_Msk
#define RCC_APB1ENR1_WWDGEN_Pos             (11U)
#define RCC_APB1ENR1_WWDGEN_Msk             (0x1UL << RCC_APB1ENR1_WWDGEN_Pos)      /*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                 RCC_APB1ENR1_WWDGEN_Msk

/********************  Bit definition for RCC_APB2ENR register  **************/
#define RCC_APB2ENR_TIM1EN_Pos              (11U)
#define RCC_APB2ENR_TIM1EN_Msk              (0x1UL << RCC_APB2ENR_TIM1EN_Pos)       /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                  RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos            (14U)
#define RCC_APB2ENR_USART1EN_Msk            (0x1UL << RCC_APB2ENR_USART1EN_Pos)     /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_TIM16EN_Pos             (17U)
#define RCC_APB2ENR_TIM16EN_Msk             (0x1UL << RCC_APB2ENR_TIM16EN_Pos)      /*!< 0x00020000 */
#define RCC_APB2ENR_TIM16EN                 RCC_APB2ENR_TIM16EN_Msk

/********************  Bit definition for RCC_APB7ENR register  **************/
#define RCC_APB7ENR_SYSCFGEN_Pos            (1U)
#define RCC_APB7ENR_SYSCFGEN_Msk            (0x1UL << RCC_APB7ENR_SYSCFGEN_Pos)     /*!< 0x00000002 */
#define RCC_APB7ENR_SYSCFGEN                RCC_APB7ENR_SYSCFGEN_Msk
#define RCC_APB7ENR_SPI3EN_Pos              (5U)
#define RCC_APB7ENR_SPI3EN_Msk              (0x1UL << RCC_APB7ENR_SPI3EN_Pos)       /*!< 0x00000020 */
#define RCC_APB7ENR_SPI3EN                  RCC_APB7ENR_SPI3EN_Msk
#define RCC_APB7ENR_LPUART1EN_Pos           (6U)
#define RCC_APB7ENR_LPUART1EN_Msk           (0x1UL << RCC_APB7ENR_LPUART1EN_Pos)    /*!< 0x00000040 */
#define RCC_APB7ENR_LPUART1EN               RCC_APB7ENR_LPUART1EN_Msk
#define RCC_APB7ENR_I2C3EN_Pos              (7U)
#define RCC_APB7ENR_I2C3EN_Msk              (0x1UL << RCC_APB7ENR_I2C3EN_Pos)       /*!< 0x00000080 */
#define RCC_APB7ENR_I2C3EN                  RCC_APB7ENR_I2C3EN_Msk
#define RCC_APB7ENR_LPTIM1EN_Pos            (11U)
#define RCC_APB7ENR_LPTIM1EN_Msk            (0x1UL << RCC_APB7ENR_LPTIM1EN_Pos)     /*!< 0x00000800 */
#define RCC_APB7ENR_LPTIM1EN                RCC_APB7ENR_LPTIM1EN_Msk
#define RCC_APB7ENR_RTCAPBEN_Pos            (21U)
#define RCC_APB7ENR_RTCAPBEN_Msk            (0x1UL << RCC_APB7ENR_RTCAPBEN_Pos)     /*!< 0x00200000 */
#define RCC_APB7ENR_RTCAPBEN                RCC_APB7ENR_RTCAPBEN_Msk

/********************  Bit definition for RCC_AHB1SMENR register  **************/
#define RCC_AHB1SMENR_GPDMA1SMEN_Pos        (0U)
#define RCC_AHB1SMENR_GPDMA1SMEN_Msk        (0x1UL << RCC_AHB1SMENR_GPDMA1SMEN_Pos) /*!< 0x00000000*/
#define RCC_AHB1SMENR_GPDMA1SMEN            RCC_AHB1SMENR_GPDMA1SMEN_Msk
#define RCC_AHB1SMENR_FLASHSMEN_Pos         (8U)
#define RCC_AHB1SMENR_FLASHSMEN_Msk         (0x1UL << RCC_AHB1SMENR_FLASHSMEN_Pos)  /*!< 0x00000100 */
#define RCC_AHB1SMENR_FLASHSMEN             RCC_AHB1SMENR_FLASHSMEN_Msk
#define RCC_AHB1SMENR_CRCSMEN_Pos           (12U)
#define RCC_AHB1SMENR_CRCSMEN_Msk           (0x1UL << RCC_AHB1SMENR_CRCSMEN_Pos)    /*!< 0x00001000 */
#define RCC_AHB1SMENR_CRCSMEN               RCC_AHB1SMENR_CRCSMEN_Msk
#define RCC_AHB1SMENR_TSCSMEN_Pos           (16U)
#define RCC_AHB1SMENR_TSCSMEN_Msk           (0x1UL << RCC_AHB1SMENR_TSCSMEN_Pos)    /*!< 0x00010000 */
#define RCC_AHB1SMENR_TSCSMEN               RCC_AHB1SMENR_TSCSMEN_Msk
#define RCC_AHB1SMENR_RAMCFGSMEN_Pos        (17U)
#define RCC_AHB1SMENR_RAMCFGSMEN_Msk        (0x1UL << RCC_AHB1SMENR_RAMCFGSMEN_Pos) /*!< 0x00020000 */
#define RCC_AHB1SMENR_RAMCFGSMEN            RCC_AHB1SMENR_RAMCFGSMEN_Msk
#define RCC_AHB1SMENR_ICACHESMEN_Pos        (29U)
#define RCC_AHB1SMENR_ICACHESMEN_Msk        (0x1UL << RCC_AHB1SMENR_ICACHESMEN_Pos) /*!< 0x20000000 */
#define RCC_AHB1SMENR_ICACHESMEN            RCC_AHB1SMENR_ICACHESMEN_Msk
#define RCC_AHB1SMENR_SRAM1SMEN_Pos         (31U)
#define RCC_AHB1SMENR_SRAM1SMEN_Msk         (0x1UL << RCC_AHB1SMENR_SRAM1SMEN_Pos)  /*!< 0x80000000 */
#define RCC_AHB1SMENR_SRAM1SMEN             RCC_AHB1SMENR_SRAM1SMEN_Msk

/********************  Bit definition for RCC_AHB2SMENR register  **************/
#define RCC_AHB2SMENR_GPIOASMEN_Pos         (0U)
#define RCC_AHB2SMENR_GPIOASMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOASMEN_Pos)  /*!< 0x00000001 */
#define RCC_AHB2SMENR_GPIOASMEN             RCC_AHB2SMENR_GPIOASMEN_Msk
#define RCC_AHB2SMENR_GPIOBSMEN_Pos         (1U)
#define RCC_AHB2SMENR_GPIOBSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOBSMEN_Pos)  /*!< 0x00000002 */
#define RCC_AHB2SMENR_GPIOBSMEN             RCC_AHB2SMENR_GPIOBSMEN_Msk
#define RCC_AHB2SMENR_GPIOCSMEN_Pos         (2U)
#define RCC_AHB2SMENR_GPIOCSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOCSMEN_Pos)  /*!< 0x00000004 */
#define RCC_AHB2SMENR_GPIOCSMEN             RCC_AHB2SMENR_GPIOCSMEN_Msk
#define RCC_AHB2SMENR_GPIOHSMEN_Pos         (7U)
#define RCC_AHB2SMENR_GPIOHSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOHSMEN_Pos)  /*!< 0x00000080 */
#define RCC_AHB2SMENR_GPIOHSMEN             RCC_AHB2SMENR_GPIOHSMEN_Msk
#define RCC_AHB2SMENR_AESSMEN_Pos           (16U)
#define RCC_AHB2SMENR_AESSMEN_Msk           (0x1UL << RCC_AHB2SMENR_AESSMEN_Pos)    /*!< 0x00010000 */
#define RCC_AHB2SMENR_AESSMEN               RCC_AHB2SMENR_AESSMEN_Msk
#define RCC_AHB2SMENR_HASHSMEN_Pos          (17U)
#define RCC_AHB2SMENR_HASHSMEN_Msk          (0x1UL << RCC_AHB2SMENR_HASHSMEN_Pos)   /*!< 0x00020000 */
#define RCC_AHB2SMENR_HASHSMEN              RCC_AHB2SMENR_HASHSMEN_Msk
#define RCC_AHB2SMENR_RNGSMEN_Pos           (18U)
#define RCC_AHB2SMENR_RNGSMEN_Msk           (0x1UL << RCC_AHB2SMENR_RNGSMEN_Pos)    /*!< 0x00040000 */
#define RCC_AHB2SMENR_RNGSMEN               RCC_AHB2SMENR_RNGSMEN_Msk
#define RCC_AHB2SMENR_PKASMEN_Pos           (21U)
#define RCC_AHB2SMENR_PKASMEN_Msk           (0x1UL << RCC_AHB2SMENR_PKASMEN_Pos)    /*!< 0x00200000 */
#define RCC_AHB2SMENR_PKASMEN               RCC_AHB2SMENR_PKASMEN_Msk
#define RCC_AHB2SMENR_SRAM2SMEN_Pos         (30U)
#define RCC_AHB2SMENR_SRAM2SMEN_Msk         (0x1UL << RCC_AHB2SMENR_SRAM2SMEN_Pos)  /*!< 0x40000000 */
#define RCC_AHB2SMENR_SRAM2SMEN             RCC_AHB2SMENR_SRAM2SMEN_Msk

/********************  Bit definition for RCC_AHB4SMENR register  **************/
#define RCC_AHB4SMENR_PWRSMEN_Pos           (2U)
#define RCC_AHB4SMENR_PWRSMEN_Msk           (0x1UL << RCC_AHB4SMENR_PWRSMEN_Pos)    /*!< 0x00000004 */
#define RCC_AHB4SMENR_PWRSMEN               RCC_AHB4SMENR_PWRSMEN_Msk
#define RCC_AHB4SMENR_ADC4SMEN_Pos          (5U)
#define RCC_AHB4SMENR_ADC4SMEN_Msk          (0x1UL << RCC_AHB4SMENR_ADC4SMEN_Pos)   /*!< 0x00000040 */
#define RCC_AHB4SMENR_ADC4SMEN              RCC_AHB4SMENR_ADC4SMEN_Msk

/********************  Bit definition for RCC_AHB5SMENR register  **************/
#define RCC_AHB5SMENR_RADIOSMEN_Pos         (0U)
#define RCC_AHB5SMENR_RADIOSMEN_Msk         (0x1UL << RCC_AHB5SMENR_RADIOSMEN_Pos)  /*!< 0x00000001 */
#define RCC_AHB5SMENR_RADIOSMEN             RCC_AHB5SMENR_RADIOSMEN_Msk

/********************  Bit definition for RCC_APB1SMENR1 register  **************/
#define RCC_APB1SMENR1_TIM2SMEN_Pos         (0U)
#define RCC_APB1SMENR1_TIM2SMEN_Msk         (0x1UL << RCC_APB1SMENR1_TIM2SMEN_Pos)  /*!< 0x00000001 */
#define RCC_APB1SMENR1_TIM2SMEN             RCC_APB1SMENR1_TIM2SMEN_Msk
#define RCC_APB1SMENR1_WWDGSMEN_Pos         (11U)
#define RCC_APB1SMENR1_WWDGSMEN_Msk         (0x1UL << RCC_APB1SMENR1_WWDGSMEN_Pos)  /*!< 0x00000800 */
#define RCC_APB1SMENR1_WWDGSMEN             RCC_APB1SMENR1_WWDGSMEN_Msk

/********************  Bit definition for RCC_APB2SMENR register  **************/
#define RCC_APB2SMENR_TIM1SMEN_Pos          (11U)
#define RCC_APB2SMENR_TIM1SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM1SMEN_Pos)   /*!< 0x00000800 */
#define RCC_APB2SMENR_TIM1SMEN              RCC_APB2SMENR_TIM1SMEN_Msk
#define RCC_APB2SMENR_USART1SMEN_Pos        (14U)
#define RCC_APB2SMENR_USART1SMEN_Msk        (0x1UL << RCC_APB2SMENR_USART1SMEN_Pos) /*!< 0x00004000 */
#define RCC_APB2SMENR_USART1SMEN            RCC_APB2SMENR_USART1SMEN_Msk
#define RCC_APB2SMENR_TIM16SMEN_Pos         (17U)
#define RCC_APB2SMENR_TIM16SMEN_Msk         (0x1UL << RCC_APB2SMENR_TIM16SMEN_Pos)  /*!< 0x00020000 */
#define RCC_APB2SMENR_TIM16SMEN             RCC_APB2SMENR_TIM16SMEN_Msk

/********************  Bit definition for RCC_APB7SMENR register  **************/
#define RCC_APB7SMENR_SYSCFGSMEN_Pos        (1U)
#define RCC_APB7SMENR_SYSCFGSMEN_Msk        (0x1UL << RCC_APB7SMENR_SYSCFGSMEN_Pos) /*!< 0x00000002 */
#define RCC_APB7SMENR_SYSCFGSMEN            RCC_APB7SMENR_SYSCFGSMEN_Msk
#define RCC_APB7SMENR_SPI3SMEN_Pos          (5U)
#define RCC_APB7SMENR_SPI3SMEN_Msk          (0x1UL << RCC_APB7SMENR_SPI3SMEN_Pos)   /*!< 0x00000020 */
#define RCC_APB7SMENR_SPI3SMEN              RCC_APB7SMENR_SPI3SMEN_Msk
#define RCC_APB7SMENR_LPUART1SMEN_Pos       (6U)
#define RCC_APB7SMENR_LPUART1SMEN_Msk       (0x1UL << RCC_APB7SMENR_LPUART1SMEN_Pos)  /*!< 0x00000040 */
#define RCC_APB7SMENR_LPUART1SMEN           RCC_APB7SMENR_LPUART1SMEN_Msk
#define RCC_APB7SMENR_I2C3SMEN_Pos          (7U)
#define RCC_APB7SMENR_I2C3SMEN_Msk          (0x1UL << RCC_APB7SMENR_I2C3SMEN_Pos)   /*!< 0x00000080 */
#define RCC_APB7SMENR_I2C3SMEN              RCC_APB7SMENR_I2C3SMEN_Msk
#define RCC_APB7SMENR_LPTIM1SMEN_Pos        (11U)
#define RCC_APB7SMENR_LPTIM1SMEN_Msk        (0x1UL << RCC_APB7SMENR_LPTIM1SMEN_Pos) /*!< 0x00000800 */
#define RCC_APB7SMENR_LPTIM1SMEN            RCC_APB7SMENR_LPTIM1SMEN_Msk
#define RCC_APB7SMENR_RTCAPBSMEN_Pos        (21U)
#define RCC_APB7SMENR_RTCAPBSMEN_Msk        (0x1UL << RCC_APB7SMENR_RTCAPBSMEN_Pos) /*!< 0x00200000 */
#define RCC_APB7SMENR_RTCAPBSMEN            RCC_APB7SMENR_RTCAPBSMEN_Msk

/********************  Bit definition for RCC_CCIPR1 register  ******************/
#define RCC_CCIPR1_USART1SEL_Pos            (0U)
#define RCC_CCIPR1_USART1SEL_Msk            (0x3UL << RCC_CCIPR1_USART1SEL_Pos)     /*!< 0x00000003 */
#define RCC_CCIPR1_USART1SEL                RCC_CCIPR1_USART1SEL_Msk
#define RCC_CCIPR1_USART1SEL_0              (0x1UL << RCC_CCIPR1_USART1SEL_Pos)     /*!< 0x00000001 */
#define RCC_CCIPR1_USART1SEL_1              (0x2UL << RCC_CCIPR1_USART1SEL_Pos)     /*!< 0x00000002 */
#define RCC_CCIPR1_SYSTICKSEL_Pos           (22U)
#define RCC_CCIPR1_SYSTICKSEL_Msk           (0x3UL << RCC_CCIPR1_SYSTICKSEL_Pos)    /*!< 0x00C00000 */
#define RCC_CCIPR1_SYSTICKSEL               RCC_CCIPR1_SYSTICKSEL_Msk
#define RCC_CCIPR1_SYSTICKSEL_0             (0x1UL << RCC_CCIPR1_SYSTICKSEL_Pos)    /*!< 0x00400000 */
#define RCC_CCIPR1_SYSTICKSEL_1             (0x2UL << RCC_CCIPR1_SYSTICKSEL_Pos)    /*!< 0x00800000 */
#define RCC_CCIPR1_TIMICSEL_Pos             (31U)
#define RCC_CCIPR1_TIMICSEL_Msk             (0x1UL << RCC_CCIPR1_TIMICSEL_Pos)      /*!< 0x80000000 */
#define RCC_CCIPR1_TIMICSEL                 RCC_CCIPR1_TIMICSEL_Msk

/********************  Bit definition for RCC_CCIPR2 register  ******************/
#define RCC_CCIPR2_RNGSEL_Pos               (12U)
#define RCC_CCIPR2_RNGSEL_Msk               (0x3UL << RCC_CCIPR2_RNGSEL_Pos)        /*!< 0x00300000 */
#define RCC_CCIPR2_RNGSEL                   RCC_CCIPR2_RNGSEL_Msk
#define RCC_CCIPR2_RNGSEL_0                 (0x1UL << RCC_CCIPR2_RNGSEL_Pos)        /*!< 0x00100000 */
#define RCC_CCIPR2_RNGSEL_1                 (0x2UL << RCC_CCIPR2_RNGSEL_Pos)        /*!< 0x00200000 */

/********************  Bit definition for RCC_CCIPR3 register  ***************/
#define RCC_CCIPR3_LPUART1SEL_Pos           (0U)
#define RCC_CCIPR3_LPUART1SEL_Msk           (0x3UL << RCC_CCIPR3_LPUART1SEL_Pos)    /*!< 0x00000003 */
#define RCC_CCIPR3_LPUART1SEL               RCC_CCIPR3_LPUART1SEL_Msk
#define RCC_CCIPR3_LPUART1SEL_0             (0x1UL << RCC_CCIPR3_LPUART1SEL_Pos)    /*!< 0x00000001 */
#define RCC_CCIPR3_LPUART1SEL_1             (0x2UL << RCC_CCIPR3_LPUART1SEL_Pos)    /*!< 0x00000002 */
#define RCC_CCIPR3_SPI3SEL_Pos              (3U)
#define RCC_CCIPR3_SPI3SEL_Msk              (0x3UL << RCC_CCIPR3_SPI3SEL_Pos)       /*!< 0x00000018 */
#define RCC_CCIPR3_SPI3SEL                  RCC_CCIPR3_SPI3SEL_Msk
#define RCC_CCIPR3_SPI3SEL_0                (0x1UL << RCC_CCIPR3_SPI3SEL_Pos)       /*!< 0x00000008 */
#define RCC_CCIPR3_SPI3SEL_1                (0x2UL << RCC_CCIPR3_SPI3SEL_Pos)       /*!< 0x00000010 */
#define RCC_CCIPR3_I2C3SEL_Pos              (6U)
#define RCC_CCIPR3_I2C3SEL_Msk              (0x3UL << RCC_CCIPR3_I2C3SEL_Pos)       /*!< 0x000000C0 */
#define RCC_CCIPR3_I2C3SEL                  RCC_CCIPR3_I2C3SEL_Msk
#define RCC_CCIPR3_I2C3SEL_0                (0x1UL << RCC_CCIPR3_I2C3SEL_Pos)       /*!< 0x00000040 */
#define RCC_CCIPR3_I2C3SEL_1                (0x2UL << RCC_CCIPR3_I2C3SEL_Pos)       /*!< 0x00000080 */
#define RCC_CCIPR3_LPTIM1SEL_Pos            (10U)
#define RCC_CCIPR3_LPTIM1SEL_Msk            (0x3UL << RCC_CCIPR3_LPTIM1SEL_Pos)     /*!< 0x00000C00 */
#define RCC_CCIPR3_LPTIM1SEL                RCC_CCIPR3_LPTIM1SEL_Msk
#define RCC_CCIPR3_LPTIM1SEL_0              (0x1UL << RCC_CCIPR3_LPTIM1SEL_Pos)     /*!< 0x00000400 */
#define RCC_CCIPR3_LPTIM1SEL_1              (0x2UL << RCC_CCIPR3_LPTIM1SEL_Pos)     /*!< 0x00000800 */
#define RCC_CCIPR3_ADCSEL_Pos               (12U)
#define RCC_CCIPR3_ADCSEL_Msk               (0x7UL << RCC_CCIPR3_ADCSEL_Pos)        /*!< 0x00007000 */
#define RCC_CCIPR3_ADCSEL                   RCC_CCIPR3_ADCSEL_Msk
#define RCC_CCIPR3_ADCSEL_0                 (0x1UL << RCC_CCIPR3_ADCSEL_Pos)        /*!< 0x00001000 */
#define RCC_CCIPR3_ADCSEL_1                 (0x2UL << RCC_CCIPR3_ADCSEL_Pos)        /*!< 0x00002000 */
#define RCC_CCIPR3_ADCSEL_2                 (0x4UL << RCC_CCIPR3_ADCSEL_Pos)        /*!< 0x00004000 */

/********************  Bit definition for RCC_BDCR1 register  ******************/
#define RCC_BDCR1_LSEON_Pos                  (0U)
#define RCC_BDCR1_LSEON_Msk                  (0x1UL << RCC_BDCR1_LSEON_Pos)         /*!< 0x00000001 */
#define RCC_BDCR1_LSEON                      RCC_BDCR1_LSEON_Msk
#define RCC_BDCR1_LSERDY_Pos                 (1U)
#define RCC_BDCR1_LSERDY_Msk                 (0x1UL << RCC_BDCR1_LSERDY_Pos)        /*!< 0x00000002 */
#define RCC_BDCR1_LSERDY                     RCC_BDCR1_LSERDY_Msk
#define RCC_BDCR1_LSEBYP_Pos                 (2U)
#define RCC_BDCR1_LSEBYP_Msk                 (0x1UL << RCC_BDCR1_LSEBYP_Pos)        /*!< 0x00000004 */
#define RCC_BDCR1_LSEBYP                     RCC_BDCR1_LSEBYP_Msk
#define RCC_BDCR1_LSEDRV_Pos                 (3U)
#define RCC_BDCR1_LSEDRV_Msk                 (0x3UL << RCC_BDCR1_LSEDRV_Pos)        /*!< 0x00000018 */
#define RCC_BDCR1_LSEDRV                     RCC_BDCR1_LSEDRV_Msk
#define RCC_BDCR1_LSEDRV_0                   (0x1UL << RCC_BDCR1_LSEDRV_Pos)        /*!< 0x00000008 */
#define RCC_BDCR1_LSEDRV_1                   (0x2UL << RCC_BDCR1_LSEDRV_Pos)        /*!< 0x00000010 */
#define RCC_BDCR1_LSECSSON_Pos               (5U)
#define RCC_BDCR1_LSECSSON_Msk               (0x1UL << RCC_BDCR1_LSECSSON_Pos)      /*!< 0x00000020 */
#define RCC_BDCR1_LSECSSON                   RCC_BDCR1_LSECSSON_Msk
#define RCC_BDCR1_LSECSSD_Pos                (6U)
#define RCC_BDCR1_LSECSSD_Msk                (0x1UL << RCC_BDCR1_LSECSSD_Pos)       /*!< 0x00000040 */
#define RCC_BDCR1_LSECSSD                    RCC_BDCR1_LSECSSD_Msk
#define RCC_BDCR1_LSESYSEN_Pos               (7U)
#define RCC_BDCR1_LSESYSEN_Msk               (0x1UL << RCC_BDCR1_LSESYSEN_Pos)      /*!< 0x00000080 */
#define RCC_BDCR1_LSESYSEN                   RCC_BDCR1_LSESYSEN_Msk
#define RCC_BDCR1_RTCSEL_Pos                 (8U)
#define RCC_BDCR1_RTCSEL_Msk                 (0x3UL << RCC_BDCR1_RTCSEL_Pos)        /*!< 0x00000300 */
#define RCC_BDCR1_RTCSEL                     RCC_BDCR1_RTCSEL_Msk
#define RCC_BDCR1_RTCSEL_0                   (0x1UL << RCC_BDCR1_RTCSEL_Pos)        /*!< 0x00000100 */
#define RCC_BDCR1_RTCSEL_1                   (0x2UL << RCC_BDCR1_RTCSEL_Pos)        /*!< 0x00000200 */
#define RCC_BDCR1_LSESYSRDY_Pos              (11U)
#define RCC_BDCR1_LSESYSRDY_Msk              (0x1UL << RCC_BDCR1_LSESYSRDY_Pos)     /*!< 0x00000800 */
#define RCC_BDCR1_LSESYSRDY                  RCC_BDCR1_LSESYSRDY_Msk
#define RCC_BDCR1_LSEGFON_Pos                (12U)
#define RCC_BDCR1_LSEGFON_Msk                (0x1UL << RCC_BDCR1_LSEGFON_Pos)       /*!< 0x00001000 */
#define RCC_BDCR1_LSEGFON                    RCC_BDCR1_LSEGFON_Msk
#define RCC_BDCR1_LSETRIM_Pos                (13U)
#define RCC_BDCR1_LSETRIM_Msk                (0x3UL << RCC_BDCR1_LSETRIM_Pos)       /*!< 0x00006000 */
#define RCC_BDCR1_LSETRIM                    RCC_BDCR1_LSETRIM_Msk
#define RCC_BDCR1_LSETRIM_0                  (0x1UL << RCC_BDCR1_LSETRIM_Pos)       /*!< 0x00002000 */
#define RCC_BDCR1_LSETRIM_1                  (0x2UL << RCC_BDCR1_LSETRIM_Pos)       /*!< 0x00004000 */
#define RCC_BDCR1_BDRST_Pos                  (16U)
#define RCC_BDCR1_BDRST_Msk                  (0x1UL << RCC_BDCR1_BDRST_Pos)         /*!< 0x00010000 */
#define RCC_BDCR1_BDRST                      RCC_BDCR1_BDRST_Msk
#define RCC_BDCR1_RADIOSTSEL_Pos             (18U)
#define RCC_BDCR1_RADIOSTSEL_Msk             (0x3UL << RCC_BDCR1_RADIOSTSEL_Pos)    /*!< 0x000C0000 */
#define RCC_BDCR1_RADIOSTSEL                 RCC_BDCR1_RADIOSTSEL_Msk
#define RCC_BDCR1_RADIOSTSEL_0               (0x1UL << RCC_BDCR1_RADIOSTSEL_Pos)    /*!< 0x00040000 */
#define RCC_BDCR1_RADIOSTSEL_1               (0x2UL << RCC_BDCR1_RADIOSTSEL_Pos)    /*!< 0x00080000 */
#define RCC_BDCR1_LSCOEN_Pos                 (24U)
#define RCC_BDCR1_LSCOEN_Msk                 (0x1UL << RCC_BDCR1_LSCOEN_Pos)        /*!< 0x01000000 */
#define RCC_BDCR1_LSCOEN                     RCC_BDCR1_LSCOEN_Msk
#define RCC_BDCR1_LSCOSEL_Pos                (25U)
#define RCC_BDCR1_LSCOSEL_Msk                (0x1UL << RCC_BDCR1_LSCOSEL_Pos)       /*!< 0x02000000 */
#define RCC_BDCR1_LSCOSEL                    RCC_BDCR1_LSCOSEL_Msk
#define RCC_BDCR1_LSI1ON_Pos                 (26U)
#define RCC_BDCR1_LSI1ON_Msk                 (0x1UL << RCC_BDCR1_LSI1ON_Pos)        /*!< 0x04000000 */
#define RCC_BDCR1_LSI1ON                     RCC_BDCR1_LSI1ON_Msk
#define RCC_BDCR1_LSI1RDY_Pos                (27U)
#define RCC_BDCR1_LSI1RDY_Msk                (0x1UL << RCC_BDCR1_LSI1RDY_Pos)       /*!< 0x08000000 */
#define RCC_BDCR1_LSI1RDY                    RCC_BDCR1_LSI1RDY_Msk
#define RCC_BDCR1_LSI1PREDIV_Pos             (28U)
#define RCC_BDCR1_LSI1PREDIV_Msk             (0x1UL << RCC_BDCR1_LSI1PREDIV_Pos)    /*!< 0x10000000 */
#define RCC_BDCR1_LSI1PREDIV                 RCC_BDCR1_LSI1PREDIV_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_RMVF_Pos                    (23U)
#define RCC_CSR_RMVF_Msk                    (0x1UL << RCC_CSR_RMVF_Pos)             /*!< 0x00800000 */
#define RCC_CSR_RMVF                        RCC_CSR_RMVF_Msk
#define RCC_CSR_OBLRSTF_Pos                 (25U)
#define RCC_CSR_OBLRSTF_Msk                 (0x1UL << RCC_CSR_OBLRSTF_Pos)          /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                     RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                 (26U)
#define RCC_CSR_PINRSTF_Msk                 (0x1UL << RCC_CSR_PINRSTF_Pos)          /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                     RCC_CSR_PINRSTF_Msk
#define RCC_CSR_BORRSTF_Pos                 (27U)
#define RCC_CSR_BORRSTF_Msk                 (0x1UL << RCC_CSR_BORRSTF_Pos)          /*!< 0x08000000 */
#define RCC_CSR_BORRSTF                     RCC_CSR_BORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                 (28U)
#define RCC_CSR_SFTRSTF_Msk                 (0x1UL << RCC_CSR_SFTRSTF_Pos)          /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                     RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                (29U)
#define RCC_CSR_IWDGRSTF_Msk                (0x1UL << RCC_CSR_IWDGRSTF_Pos)         /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                    RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                (30U)
#define RCC_CSR_WWDGRSTF_Msk                (0x1UL << RCC_CSR_WWDGRSTF_Pos)         /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                    RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                (31U)
#define RCC_CSR_LPWRRSTF_Msk                (0x1UL << RCC_CSR_LPWRRSTF_Pos)         /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                    RCC_CSR_LPWRRSTF_Msk



/********************  Bit definition for RCC_CFGR4 register  *******************/
#define RCC_CFGR4_HPRE5_Pos                 (0U)
#define RCC_CFGR4_HPRE5_Msk                 (0x7UL << RCC_CFGR4_HPRE5_Pos)          /*!< 0x00000007 */
#define RCC_CFGR4_HPRE5                     RCC_CFGR4_HPRE5_Msk
#define RCC_CFGR4_HPRE5_0                   (0x1UL << RCC_CFGR4_HPRE5_Pos)          /*!< 0x00000001 */
#define RCC_CFGR4_HPRE5_1                   (0x2UL << RCC_CFGR4_HPRE5_Pos)          /*!< 0x00000002 */
#define RCC_CFGR4_HPRE5_2                   (0x4UL << RCC_CFGR4_HPRE5_Pos)          /*!< 0x00000004 */
#define RCC_CFGR4_HDIV5_Pos                 (4U)
#define RCC_CFGR4_HDIV5_Msk                 (0x1UL << RCC_CFGR4_HDIV5_Pos)          /*!< 0x00000080 */
#define RCC_CFGR4_HDIV5                     RCC_CFGR4_HDIV5_Msk

/********************  Bit definition for RCC_RADIOENR register  **************/
#define RCC_RADIOENR_BBCLKEN_Pos            (1U)
#define RCC_RADIOENR_BBCLKEN_Msk            (0x1UL << RCC_RADIOENR_BBCLKEN_Pos)      /*!< 0x00000002 */
#define RCC_RADIOENR_BBCLKEN                RCC_RADIOENR_BBCLKEN_Msk
#define RCC_RADIOENR_STRADIOCLKON_Pos       (16U)
#define RCC_RADIOENR_STRADIOCLKON_Msk       (0x1UL << RCC_RADIOENR_STRADIOCLKON_Pos) /*!< 0x00010000 */
#define RCC_RADIOENR_STRADIOCLKON           RCC_RADIOENR_STRADIOCLKON_Msk
#define RCC_RADIOENR_RADIOCLKRDY_Pos        (17U)
#define RCC_RADIOENR_RADIOCLKRDY_Msk        (0x1UL << RCC_RADIOENR_RADIOCLKRDY_Pos)  /*!< 0x00020000 */
#define RCC_RADIOENR_RADIOCLKRDY            RCC_RADIOENR_RADIOCLKRDY_Msk

/********************  Bit definition for RCC_ECSCR1 register  *******************/
#define RCC_ECSCR1_HSETRIM_Pos              (16U)
#define RCC_ECSCR1_HSETRIM_Msk              (0x3FUL << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x003F0000 */
#define RCC_ECSCR1_HSETRIM                  RCC_ECSCR1_HSETRIM_Msk
#define RCC_ECSCR1_HSETRIM_0                (0x1UL  << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00010000 */
#define RCC_ECSCR1_HSETRIM_1                (0x2UL  << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00020000 */
#define RCC_ECSCR1_HSETRIM_2                (0x4UL  << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00040000 */
#define RCC_ECSCR1_HSETRIM_3                (0x8UL  << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00080000 */
#define RCC_ECSCR1_HSETRIM_4                (0x10UL << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00100000 */
#define RCC_ECSCR1_HSETRIM_5                (0x20UL << RCC_ECSCR1_HSETRIM_Pos)       /*!< 0x00200000 */


/******************************************************************************/
/*                                                                            */
/*                                    RNG                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RNG_CR register  *******************/
#define RNG_CR_RNGEN_Pos                    (2U)
#define RNG_CR_RNGEN_Msk                    (0x1UL << RNG_CR_RNGEN_Pos)             /*!< 0x00000004 */
#define RNG_CR_RNGEN                        RNG_CR_RNGEN_Msk
#define RNG_CR_IE_Pos                       (3U)
#define RNG_CR_IE_Msk                       (0x1UL << RNG_CR_IE_Pos)                /*!< 0x00000008 */
#define RNG_CR_IE                           RNG_CR_IE_Msk
#define RNG_CR_CED_Pos                      (5U)
#define RNG_CR_CED_Msk                      (0x1UL << RNG_CR_CED_Pos)               /*!< 0x00000020 */
#define RNG_CR_CED                          RNG_CR_CED_Msk
#define RNG_CR_ARDIS_Pos                    (7U)
#define RNG_CR_ARDIS_Msk                    (0x1UL << RNG_CR_ARDIS_Pos)
#define RNG_CR_ARDIS                        RNG_CR_ARDIS_Msk
#define RNG_CR_RNG_CONFIG3_Pos              (8U)
#define RNG_CR_RNG_CONFIG3_Msk              (0xFUL << RNG_CR_RNG_CONFIG3_Pos)
#define RNG_CR_RNG_CONFIG3                  RNG_CR_RNG_CONFIG3_Msk
#define RNG_CR_NISTC_Pos                    (12U)
#define RNG_CR_NISTC_Msk                    (0x1UL << RNG_CR_NISTC_Pos)
#define RNG_CR_NISTC                        RNG_CR_NISTC_Msk
#define RNG_CR_RNG_CONFIG2_Pos              (13U)
#define RNG_CR_RNG_CONFIG2_Msk              (0x7UL << RNG_CR_RNG_CONFIG2_Pos)
#define RNG_CR_RNG_CONFIG2                  RNG_CR_RNG_CONFIG2_Msk
#define RNG_CR_CLKDIV_Pos                   (16U)
#define RNG_CR_CLKDIV_Msk                   (0xFUL << RNG_CR_CLKDIV_Pos)
#define RNG_CR_CLKDIV                       RNG_CR_CLKDIV_Msk
#define RNG_CR_CLKDIV_0                     (0x1UL << RNG_CR_CLKDIV_Pos)            /*!< 0x00010000 */
#define RNG_CR_CLKDIV_1                     (0x2UL << RNG_CR_CLKDIV_Pos)            /*!< 0x00020000 */
#define RNG_CR_CLKDIV_2                     (0x4UL << RNG_CR_CLKDIV_Pos)            /*!< 0x00040000 */
#define RNG_CR_CLKDIV_3                     (0x8UL << RNG_CR_CLKDIV_Pos)            /*!< 0x00080000 */
#define RNG_CR_RNG_CONFIG1_Pos              (20U)
#define RNG_CR_RNG_CONFIG1_Msk              (0x3FUL << RNG_CR_RNG_CONFIG1_Pos)
#define RNG_CR_RNG_CONFIG1                  RNG_CR_RNG_CONFIG1_Msk
#define RNG_CR_CONDRST_Pos                  (30U)
#define RNG_CR_CONDRST_Msk                  (0x1UL << RNG_CR_CONDRST_Pos)
#define RNG_CR_CONDRST                      RNG_CR_CONDRST_Msk
#define RNG_CR_CONFIGLOCK_Pos               (31U)
#define RNG_CR_CONFIGLOCK_Msk               (0x1UL << RNG_CR_CONFIGLOCK_Pos)
#define RNG_CR_CONFIGLOCK                   RNG_CR_CONFIGLOCK_Msk

/********************  Bits definition for RNG_SR register  *******************/
#define RNG_SR_DRDY_Pos                     (0U)
#define RNG_SR_DRDY_Msk                     (0x1UL << RNG_SR_DRDY_Pos)              /*!< 0x00000001 */
#define RNG_SR_DRDY                         RNG_SR_DRDY_Msk
#define RNG_SR_CECS_Pos                     (1U)
#define RNG_SR_CECS_Msk                     (0x1UL << RNG_SR_CECS_Pos)              /*!< 0x00000002 */
#define RNG_SR_CECS                         RNG_SR_CECS_Msk
#define RNG_SR_SECS_Pos                     (2U)
#define RNG_SR_SECS_Msk                     (0x1UL << RNG_SR_SECS_Pos)              /*!< 0x00000004 */
#define RNG_SR_SECS                         RNG_SR_SECS_Msk
#define RNG_SR_CEIS_Pos                     (5U)
#define RNG_SR_CEIS_Msk                     (0x1UL << RNG_SR_CEIS_Pos)              /*!< 0x00000020 */
#define RNG_SR_CEIS                         RNG_SR_CEIS_Msk
#define RNG_SR_SEIS_Pos                     (6U)
#define RNG_SR_SEIS_Msk                     (0x1UL << RNG_SR_SEIS_Pos)              /*!< 0x00000040 */
#define RNG_SR_SEIS                         RNG_SR_SEIS_Msk

/********************  Bits definition for RNG_DR register  *******************/
#define RNG_DR_RNDATA_Pos                  (0U)
#define RNG_DR_RNDATA_Msk                  (0xFFFFFFFFUL << RNG_DR_RNDATA_Pos)      /*!< 0xFFFFFFFF */
#define RNG_DR_RNDATA                      RNG_DR_RNDATA_Msk

/********************  Bits definition for RNG_HTCR register  *******************/
#define RNG_HTCR_HTCFG_Pos                 (0U)
#define RNG_HTCR_HTCFG_Msk                 (0xFFFFFFFFUL << RNG_HTCR_HTCFG_Pos)     /*!< 0xFFFFFFFF */
#define RNG_HTCR_HTCFG                     RNG_HTCR_HTCFG_Msk


/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_SU_Pos                       (0U)
#define RTC_TR_SU_Msk                       (0xFUL << RTC_TR_SU_Pos)                /*!< 0x0000000F */
#define RTC_TR_SU                           RTC_TR_SU_Msk
#define RTC_TR_SU_0                         (0x1UL << RTC_TR_SU_Pos)                /*!< 0x00000001 */
#define RTC_TR_SU_1                         (0x2UL << RTC_TR_SU_Pos)                /*!< 0x00000002 */
#define RTC_TR_SU_2                         (0x4UL << RTC_TR_SU_Pos)                /*!< 0x00000004 */
#define RTC_TR_SU_3                         (0x8UL << RTC_TR_SU_Pos)                /*!< 0x00000008 */
#define RTC_TR_ST_Pos                       (4U)
#define RTC_TR_ST_Msk                       (0x7UL << RTC_TR_ST_Pos)                /*!< 0x00000070 */
#define RTC_TR_ST                           RTC_TR_ST_Msk
#define RTC_TR_ST_0                         (0x1UL << RTC_TR_ST_Pos)                /*!< 0x00000010 */
#define RTC_TR_ST_1                         (0x2UL << RTC_TR_ST_Pos)                /*!< 0x00000020 */
#define RTC_TR_ST_2                         (0x4UL << RTC_TR_ST_Pos)                /*!< 0x00000040 */
#define RTC_TR_MNU_Pos                      (8U)
#define RTC_TR_MNU_Msk                      (0xFUL << RTC_TR_MNU_Pos)               /*!< 0x00000F00 */
#define RTC_TR_MNU                          RTC_TR_MNU_Msk
#define RTC_TR_MNU_0                        (0x1UL << RTC_TR_MNU_Pos)               /*!< 0x00000100 */
#define RTC_TR_MNU_1                        (0x2UL << RTC_TR_MNU_Pos)               /*!< 0x00000200 */
#define RTC_TR_MNU_2                        (0x4UL << RTC_TR_MNU_Pos)               /*!< 0x00000400 */
#define RTC_TR_MNU_3                        (0x8UL << RTC_TR_MNU_Pos)               /*!< 0x00000800 */
#define RTC_TR_MNT_Pos                      (12U)
#define RTC_TR_MNT_Msk                      (0x7UL << RTC_TR_MNT_Pos)               /*!< 0x00007000 */
#define RTC_TR_MNT                          RTC_TR_MNT_Msk
#define RTC_TR_MNT_0                        (0x1UL << RTC_TR_MNT_Pos)               /*!< 0x00001000 */
#define RTC_TR_MNT_1                        (0x2UL << RTC_TR_MNT_Pos)               /*!< 0x00002000 */
#define RTC_TR_MNT_2                        (0x4UL << RTC_TR_MNT_Pos)               /*!< 0x00004000 */
#define RTC_TR_HU_Pos                       (16U)
#define RTC_TR_HU_Msk                       (0xFUL << RTC_TR_HU_Pos)                /*!< 0x000F0000 */
#define RTC_TR_HU                           RTC_TR_HU_Msk
#define RTC_TR_HU_0                         (0x1UL << RTC_TR_HU_Pos)                /*!< 0x00010000 */
#define RTC_TR_HU_1                         (0x2UL << RTC_TR_HU_Pos)                /*!< 0x00020000 */
#define RTC_TR_HU_2                         (0x4UL << RTC_TR_HU_Pos)                /*!< 0x00040000 */
#define RTC_TR_HU_3                         (0x8UL << RTC_TR_HU_Pos)                /*!< 0x00080000 */
#define RTC_TR_HT_Pos                       (20U)
#define RTC_TR_HT_Msk                       (0x3UL << RTC_TR_HT_Pos)                /*!< 0x00300000 */
#define RTC_TR_HT                           RTC_TR_HT_Msk
#define RTC_TR_HT_0                         (0x1UL << RTC_TR_HT_Pos)                /*!< 0x00100000 */
#define RTC_TR_HT_1                         (0x2UL << RTC_TR_HT_Pos)                /*!< 0x00200000 */
#define RTC_TR_PM_Pos                       (22U)
#define RTC_TR_PM_Msk                       (0x1UL << RTC_TR_PM_Pos)                /*!< 0x00400000 */
#define RTC_TR_PM                           RTC_TR_PM_Msk

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_DU_Pos                       (0U)
#define RTC_DR_DU_Msk                       (0xFUL << RTC_DR_DU_Pos)                /*!< 0x0000000F */
#define RTC_DR_DU                           RTC_DR_DU_Msk
#define RTC_DR_DU_0                         (0x1UL << RTC_DR_DU_Pos)                /*!< 0x00000001 */
#define RTC_DR_DU_1                         (0x2UL << RTC_DR_DU_Pos)                /*!< 0x00000002 */
#define RTC_DR_DU_2                         (0x4UL << RTC_DR_DU_Pos)                /*!< 0x00000004 */
#define RTC_DR_DU_3                         (0x8UL << RTC_DR_DU_Pos)                /*!< 0x00000008 */
#define RTC_DR_DT_Pos                       (4U)
#define RTC_DR_DT_Msk                       (0x3UL << RTC_DR_DT_Pos)                /*!< 0x00000030 */
#define RTC_DR_DT                           RTC_DR_DT_Msk
#define RTC_DR_DT_0                         (0x1UL << RTC_DR_DT_Pos)                /*!< 0x00000010 */
#define RTC_DR_DT_1                         (0x2UL << RTC_DR_DT_Pos)                /*!< 0x00000020 */
#define RTC_DR_MU_Pos                       (8U)
#define RTC_DR_MU_Msk                       (0xFUL << RTC_DR_MU_Pos)                /*!< 0x00000F00 */
#define RTC_DR_MU                           RTC_DR_MU_Msk
#define RTC_DR_MU_0                         (0x1UL << RTC_DR_MU_Pos)                /*!< 0x00000100 */
#define RTC_DR_MU_1                         (0x2UL << RTC_DR_MU_Pos)                /*!< 0x00000200 */
#define RTC_DR_MU_2                         (0x4UL << RTC_DR_MU_Pos)                /*!< 0x00000400 */
#define RTC_DR_MU_3                         (0x8UL << RTC_DR_MU_Pos)                /*!< 0x00000800 */
#define RTC_DR_MT_Pos                       (12U)
#define RTC_DR_MT_Msk                       (0x1UL << RTC_DR_MT_Pos)                /*!< 0x00001000 */
#define RTC_DR_MT                           RTC_DR_MT_Msk
#define RTC_DR_WDU_Pos                      (13U)
#define RTC_DR_WDU_Msk                      (0x7UL << RTC_DR_WDU_Pos)               /*!< 0x0000E000 */
#define RTC_DR_WDU                          RTC_DR_WDU_Msk
#define RTC_DR_WDU_0                        (0x1UL << RTC_DR_WDU_Pos)               /*!< 0x00002000 */
#define RTC_DR_WDU_1                        (0x2UL << RTC_DR_WDU_Pos)               /*!< 0x00004000 */
#define RTC_DR_WDU_2                        (0x4UL << RTC_DR_WDU_Pos)               /*!< 0x00008000 */
#define RTC_DR_YU_Pos                       (16U)
#define RTC_DR_YU_Msk                       (0xFUL << RTC_DR_YU_Pos)                /*!< 0x000F0000 */
#define RTC_DR_YU                           RTC_DR_YU_Msk
#define RTC_DR_YU_0                         (0x1UL << RTC_DR_YU_Pos)                /*!< 0x00010000 */
#define RTC_DR_YU_1                         (0x2UL << RTC_DR_YU_Pos)                /*!< 0x00020000 */
#define RTC_DR_YU_2                         (0x4UL << RTC_DR_YU_Pos)                /*!< 0x00040000 */
#define RTC_DR_YU_3                         (0x8UL << RTC_DR_YU_Pos)                /*!< 0x00080000 */
#define RTC_DR_YT_Pos                       (20U)
#define RTC_DR_YT_Msk                       (0xFUL << RTC_DR_YT_Pos)                /*!< 0x00F00000 */
#define RTC_DR_YT                           RTC_DR_YT_Msk
#define RTC_DR_YT_0                         (0x1UL << RTC_DR_YT_Pos)                /*!< 0x00100000 */
#define RTC_DR_YT_1                         (0x2UL << RTC_DR_YT_Pos)                /*!< 0x00200000 */
#define RTC_DR_YT_2                         (0x4UL << RTC_DR_YT_Pos)                /*!< 0x00400000 */
#define RTC_DR_YT_3                         (0x8UL << RTC_DR_YT_Pos)                /*!< 0x00800000 */

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos                      (0U)
#define RTC_SSR_SS_Msk                      (0xFFFFFFFFUL << RTC_SSR_SS_Pos)        /*!< 0xFFFFFFFF */
#define RTC_SSR_SS                          RTC_SSR_SS_Msk

/********************  Bits definition for RTC_ICSR register  ******************/
#define RTC_ICSR_WUTWF_Pos                  (2U)
#define RTC_ICSR_WUTWF_Msk                  (0x1UL << RTC_ICSR_WUTWF_Pos)           /*!< 0x00000004 */
#define RTC_ICSR_WUTWF                      RTC_ICSR_WUTWF_Msk
#define RTC_ICSR_SHPF_Pos                   (3U)
#define RTC_ICSR_SHPF_Msk                   (0x1UL << RTC_ICSR_SHPF_Pos)            /*!< 0x00000008 */
#define RTC_ICSR_SHPF                       RTC_ICSR_SHPF_Msk
#define RTC_ICSR_INITS_Pos                  (4U)
#define RTC_ICSR_INITS_Msk                  (0x1UL << RTC_ICSR_INITS_Pos)           /*!< 0x00000010 */
#define RTC_ICSR_INITS                      RTC_ICSR_INITS_Msk
#define RTC_ICSR_RSF_Pos                    (5U)
#define RTC_ICSR_RSF_Msk                    (0x1UL << RTC_ICSR_RSF_Pos)             /*!< 0x00000020 */
#define RTC_ICSR_RSF                        RTC_ICSR_RSF_Msk
#define RTC_ICSR_INITF_Pos                  (6U)
#define RTC_ICSR_INITF_Msk                  (0x1UL << RTC_ICSR_INITF_Pos)           /*!< 0x00000040 */
#define RTC_ICSR_INITF                      RTC_ICSR_INITF_Msk
#define RTC_ICSR_INIT_Pos                   (7U)
#define RTC_ICSR_INIT_Msk                   (0x1UL << RTC_ICSR_INIT_Pos)            /*!< 0x00000080 */
#define RTC_ICSR_INIT                       RTC_ICSR_INIT_Msk
#define RTC_ICSR_BIN_Pos                    (8U)
#define RTC_ICSR_BIN_Msk                    (0x3UL << RTC_ICSR_BIN_Pos)             /*!< 0x00000300 */
#define RTC_ICSR_BIN                        RTC_ICSR_BIN_Msk
#define RTC_ICSR_BIN_0                      (0x1UL << RTC_ICSR_BIN_Pos)             /*!< 0x00000100 */
#define RTC_ICSR_BIN_1                      (0x2UL << RTC_ICSR_BIN_Pos)             /*!< 0x00000200 */
#define RTC_ICSR_BCDU_Pos                   (10U)
#define RTC_ICSR_BCDU_Msk                   (0x7UL << RTC_ICSR_BCDU_Pos)            /*!< 0x00001C00 */
#define RTC_ICSR_BCDU                       RTC_ICSR_BCDU_Msk
#define RTC_ICSR_BCDU_0                     (0x1UL << RTC_ICSR_BCDU_Pos)            /*!< 0x00000400 */
#define RTC_ICSR_BCDU_1                     (0x2UL << RTC_ICSR_BCDU_Pos)            /*!< 0x00000800 */
#define RTC_ICSR_BCDU_2                     (0x4UL << RTC_ICSR_BCDU_Pos)            /*!< 0x00001000 */
#define RTC_ICSR_RECALPF_Pos                (16U)
#define RTC_ICSR_RECALPF_Msk                (0x1UL << RTC_ICSR_RECALPF_Pos)         /*!< 0x00010000 */
#define RTC_ICSR_RECALPF                    RTC_ICSR_RECALPF_Msk

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_S_Pos               (0U)
#define RTC_PRER_PREDIV_S_Msk               (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)     /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S                   RTC_PRER_PREDIV_S_Msk
#define RTC_PRER_PREDIV_A_Pos               (16U)
#define RTC_PRER_PREDIV_A_Msk               (0x7FUL << RTC_PRER_PREDIV_A_Pos)       /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A                   RTC_PRER_PREDIV_A_Msk

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos                    (0U)
#define RTC_WUTR_WUT_Msk                    (0xFFFFUL << RTC_WUTR_WUT_Pos)          /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                        RTC_WUTR_WUT_Msk
#define RTC_WUTR_WUTOCLR_Pos                (16U)
#define RTC_WUTR_WUTOCLR_Msk                (0xFFFFUL << RTC_WUTR_WUTOCLR_Pos)      /*!< 0x0000FFFF */
#define RTC_WUTR_WUTOCLR                    RTC_WUTR_WUTOCLR_Msk

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_WUCKSEL_Pos                  (0U)
#define RTC_CR_WUCKSEL_Msk                  (0x7UL << RTC_CR_WUCKSEL_Pos)           /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                      RTC_CR_WUCKSEL_Msk
#define RTC_CR_WUCKSEL_0                    (0x1UL << RTC_CR_WUCKSEL_Pos)           /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1                    (0x2UL << RTC_CR_WUCKSEL_Pos)           /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2                    (0x4UL << RTC_CR_WUCKSEL_Pos)           /*!< 0x00000004 */
#define RTC_CR_BYPSHAD_Pos                  (5U)
#define RTC_CR_BYPSHAD_Msk                  (0x1UL << RTC_CR_BYPSHAD_Pos)           /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                      RTC_CR_BYPSHAD_Msk
#define RTC_CR_FMT_Pos                      (6U)
#define RTC_CR_FMT_Msk                      (0x1UL << RTC_CR_FMT_Pos)               /*!< 0x00000040 */
#define RTC_CR_FMT                          RTC_CR_FMT_Msk
#define RTC_CR_SSRUIE_Pos                   (7U)
#define RTC_CR_SSRUIE_Msk                   (0x1UL << RTC_CR_SSRUIE_Pos)            /*!< 0x00000080 */
#define RTC_CR_SSRUIE                       RTC_CR_SSRUIE_Msk
#define RTC_CR_ALRAE_Pos                    (8U)
#define RTC_CR_ALRAE_Msk                    (0x1UL << RTC_CR_ALRAE_Pos)             /*!< 0x00000100 */
#define RTC_CR_ALRAE                        RTC_CR_ALRAE_Msk
#define RTC_CR_ALRBE_Pos                    (9U)
#define RTC_CR_ALRBE_Msk                    (0x1UL << RTC_CR_ALRBE_Pos)             /*!< 0x00000200 */
#define RTC_CR_ALRBE                        RTC_CR_ALRBE_Msk
#define RTC_CR_WUTE_Pos                     (10U)
#define RTC_CR_WUTE_Msk                     (0x1UL << RTC_CR_WUTE_Pos)              /*!< 0x00000400 */
#define RTC_CR_WUTE                         RTC_CR_WUTE_Msk
#define RTC_CR_ALRAIE_Pos                   (12U)
#define RTC_CR_ALRAIE_Msk                   (0x1UL << RTC_CR_ALRAIE_Pos)            /*!< 0x00001000 */
#define RTC_CR_ALRAIE                       RTC_CR_ALRAIE_Msk
#define RTC_CR_ALRBIE_Pos                   (13U)
#define RTC_CR_ALRBIE_Msk                   (0x1UL << RTC_CR_ALRBIE_Pos)            /*!< 0x00002000 */
#define RTC_CR_ALRBIE                       RTC_CR_ALRBIE_Msk
#define RTC_CR_WUTIE_Pos                    (14U)
#define RTC_CR_WUTIE_Msk                    (0x1UL << RTC_CR_WUTIE_Pos)             /*!< 0x00004000 */
#define RTC_CR_WUTIE                        RTC_CR_WUTIE_Msk
#define RTC_CR_TSIE_Pos                     (15U)
#define RTC_CR_TSIE_Msk                     (0x1UL << RTC_CR_TSIE_Pos)              /*!< 0x00008000 */
#define RTC_CR_TSIE                         RTC_CR_TSIE_Msk
#define RTC_CR_ADD1H_Pos                    (16U)
#define RTC_CR_ADD1H_Msk                    (0x1UL << RTC_CR_ADD1H_Pos)             /*!< 0x00010000 */
#define RTC_CR_ADD1H                        RTC_CR_ADD1H_Msk
#define RTC_CR_SUB1H_Pos                    (17U)
#define RTC_CR_SUB1H_Msk                    (0x1UL << RTC_CR_SUB1H_Pos)             /*!< 0x00020000 */
#define RTC_CR_SUB1H                        RTC_CR_SUB1H_Msk
#define RTC_CR_BKP_Pos                      (18U)
#define RTC_CR_BKP_Msk                      (0x1UL << RTC_CR_BKP_Pos)               /*!< 0x00040000 */
#define RTC_CR_BKP                          RTC_CR_BKP_Msk
#define RTC_CR_TAMPTS_Pos                   (25U)
#define RTC_CR_TAMPTS_Msk                   (0x1UL << RTC_CR_TAMPTS_Pos)            /*!< 0x02000000 */
#define RTC_CR_TAMPTS                       RTC_CR_TAMPTS_Msk                       /*!<Activate timestamp on tamper detection event  */
#define RTC_CR_ALRAFCLR_Pos                 (27U)
#define RTC_CR_ALRAFCLR_Msk                 (0x1UL << RTC_CR_ALRAFCLR_Pos)          /*!< 0x8000000 */
#define RTC_CR_ALRAFCLR                     RTC_CR_ALRAFCLR_Msk                     /*!<Alarm A mask */
#define RTC_CR_ALRBFCLR_Pos                 (28U)
#define RTC_CR_ALRBFCLR_Msk                 (0x1UL << RTC_CR_ALRBFCLR_Pos)          /*!< 0x10000000 */
#define RTC_CR_ALRBFCLR                     RTC_CR_ALRBFCLR_Msk                      /*!<Alarm B mask */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos                     (0U)
#define RTC_WPR_KEY_Msk                     (0xFFUL << RTC_WPR_KEY_Pos)             /*!< 0x000000FF */
#define RTC_WPR_KEY                         RTC_WPR_KEY_Msk

/********************  Bits definition for RTC_CALR register  *****************/
#define RTC_CALR_CALM_Pos                   (0U)
#define RTC_CALR_CALM_Msk                   (0x1FFUL << RTC_CALR_CALM_Pos)          /*!< 0x000001FF */
#define RTC_CALR_CALM                       RTC_CALR_CALM_Msk
#define RTC_CALR_CALM_0                     (0x001UL << RTC_CALR_CALM_Pos)          /*!< 0x00000001 */
#define RTC_CALR_CALM_1                     (0x002UL << RTC_CALR_CALM_Pos)          /*!< 0x00000002 */
#define RTC_CALR_CALM_2                     (0x004UL << RTC_CALR_CALM_Pos)          /*!< 0x00000004 */
#define RTC_CALR_CALM_3                     (0x008UL << RTC_CALR_CALM_Pos)          /*!< 0x00000008 */
#define RTC_CALR_CALM_4                     (0x010UL << RTC_CALR_CALM_Pos)          /*!< 0x00000010 */
#define RTC_CALR_CALM_5                     (0x020UL << RTC_CALR_CALM_Pos)          /*!< 0x00000020 */
#define RTC_CALR_CALM_6                     (0x040UL << RTC_CALR_CALM_Pos)          /*!< 0x00000040 */
#define RTC_CALR_CALM_7                     (0x080UL << RTC_CALR_CALM_Pos)          /*!< 0x00000080 */
#define RTC_CALR_CALM_8                     (0x100UL << RTC_CALR_CALM_Pos)          /*!< 0x00000100 */
#define RTC_CALR_LPCAL_Pos                  (12U)
#define RTC_CALR_LPCAL_Msk                  (0x1UL << RTC_CALR_LPCAL_Pos)           /*!< 0x00001000 */
#define RTC_CALR_CALW16                     RTC_CALR_CALW16_Msk
#define RTC_CALR_CALW16_Pos                 (13U)
#define RTC_CALR_CALW16_Msk                 (0x1UL << RTC_CALR_CALW16_Pos)          /*!< 0x00002000 */
#define RTC_CALR_LPCAL                      RTC_CALR_LPCAL_Msk
#define RTC_CALR_CALW8_Pos                  (14U)
#define RTC_CALR_CALW8_Msk                  (0x1UL << RTC_CALR_CALW8_Pos)           /*!< 0x00004000 */
#define RTC_CALR_CALW8                      RTC_CALR_CALW8_Msk
#define RTC_CALR_CALP_Pos                   (15U)
#define RTC_CALR_CALP_Msk                   (0x1UL << RTC_CALR_CALP_Pos)            /*!< 0x00008000 */
#define RTC_CALR_CALP                       RTC_CALR_CALP_Msk

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos                (0U)
#define RTC_SHIFTR_SUBFS_Msk                (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)      /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS                    RTC_SHIFTR_SUBFS_Msk
#define RTC_SHIFTR_ADD1S_Pos                (31U)
#define RTC_SHIFTR_ADD1S_Msk                (0x1UL << RTC_SHIFTR_ADD1S_Pos)         /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S                    RTC_SHIFTR_ADD1S_Msk

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_SU_Pos                     (0U)
#define RTC_TSTR_SU_Msk                     (0xFUL << RTC_TSTR_SU_Pos)              /*!< 0x0000000F */
#define RTC_TSTR_SU                         RTC_TSTR_SU_Msk
#define RTC_TSTR_SU_0                       (0x1UL << RTC_TSTR_SU_Pos)              /*!< 0x00000001 */
#define RTC_TSTR_SU_1                       (0x2UL << RTC_TSTR_SU_Pos)              /*!< 0x00000002 */
#define RTC_TSTR_SU_2                       (0x4UL << RTC_TSTR_SU_Pos)              /*!< 0x00000004 */
#define RTC_TSTR_SU_3                       (0x8UL << RTC_TSTR_SU_Pos)              /*!< 0x00000008 */
#define RTC_TSTR_ST_Pos                     (4U)
#define RTC_TSTR_ST_Msk                     (0x7UL << RTC_TSTR_ST_Pos)              /*!< 0x00000070 */
#define RTC_TSTR_ST                         RTC_TSTR_ST_Msk
#define RTC_TSTR_ST_0                       (0x1UL << RTC_TSTR_ST_Pos)              /*!< 0x00000010 */
#define RTC_TSTR_ST_1                       (0x2UL << RTC_TSTR_ST_Pos)              /*!< 0x00000020 */
#define RTC_TSTR_ST_2                       (0x4UL << RTC_TSTR_ST_Pos)              /*!< 0x00000040 */
#define RTC_TSTR_MNU_Pos                    (8U)
#define RTC_TSTR_MNU_Msk                    (0xFUL << RTC_TSTR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_TSTR_MNU                        RTC_TSTR_MNU_Msk
#define RTC_TSTR_MNU_0                      (0x1UL << RTC_TSTR_MNU_Pos)             /*!< 0x00000100 */
#define RTC_TSTR_MNU_1                      (0x2UL << RTC_TSTR_MNU_Pos)             /*!< 0x00000200 */
#define RTC_TSTR_MNU_2                      (0x4UL << RTC_TSTR_MNU_Pos)             /*!< 0x00000400 */
#define RTC_TSTR_MNU_3                      (0x8UL << RTC_TSTR_MNU_Pos)             /*!< 0x00000800 */
#define RTC_TSTR_MNT_Pos                    (12U)
#define RTC_TSTR_MNT_Msk                    (0x7UL << RTC_TSTR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_TSTR_MNT                        RTC_TSTR_MNT_Msk
#define RTC_TSTR_MNT_0                      (0x1UL << RTC_TSTR_MNT_Pos)             /*!< 0x00001000 */
#define RTC_TSTR_MNT_1                      (0x2UL << RTC_TSTR_MNT_Pos)             /*!< 0x00002000 */
#define RTC_TSTR_MNT_2                      (0x4UL << RTC_TSTR_MNT_Pos)             /*!< 0x00004000 */
#define RTC_TSTR_HU_Pos                     (16U)
#define RTC_TSTR_HU_Msk                     (0xFUL << RTC_TSTR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_TSTR_HU                         RTC_TSTR_HU_Msk
#define RTC_TSTR_HU_0                       (0x1UL << RTC_TSTR_HU_Pos)              /*!< 0x00010000 */
#define RTC_TSTR_HU_1                       (0x2UL << RTC_TSTR_HU_Pos)              /*!< 0x00020000 */
#define RTC_TSTR_HU_2                       (0x4UL << RTC_TSTR_HU_Pos)              /*!< 0x00040000 */
#define RTC_TSTR_HU_3                       (0x8UL << RTC_TSTR_HU_Pos)              /*!< 0x00080000 */
#define RTC_TSTR_HT_Pos                     (20U)
#define RTC_TSTR_HT_Msk                     (0x3UL << RTC_TSTR_HT_Pos)              /*!< 0x00300000 */
#define RTC_TSTR_HT                         RTC_TSTR_HT_Msk
#define RTC_TSTR_HT_0                       (0x1UL << RTC_TSTR_HT_Pos)              /*!< 0x00100000 */
#define RTC_TSTR_HT_1                       (0x2UL << RTC_TSTR_HT_Pos)              /*!< 0x00200000 */
#define RTC_TSTR_PM_Pos                     (22U)
#define RTC_TSTR_PM_Msk                     (0x1UL << RTC_TSTR_PM_Pos)              /*!< 0x00400000 */
#define RTC_TSTR_PM                         RTC_TSTR_PM_Msk

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_DU_Pos                     (0U)
#define RTC_TSDR_DU_Msk                     (0xFUL << RTC_TSDR_DU_Pos)              /*!< 0x0000000F */
#define RTC_TSDR_DU                         RTC_TSDR_DU_Msk
#define RTC_TSDR_DU_0                       (0x1UL << RTC_TSDR_DU_Pos)              /*!< 0x00000001 */
#define RTC_TSDR_DU_1                       (0x2UL << RTC_TSDR_DU_Pos)              /*!< 0x00000002 */
#define RTC_TSDR_DU_2                       (0x4UL << RTC_TSDR_DU_Pos)              /*!< 0x00000004 */
#define RTC_TSDR_DU_3                       (0x8UL << RTC_TSDR_DU_Pos)              /*!< 0x00000008 */
#define RTC_TSDR_DT_Pos                     (4U)
#define RTC_TSDR_DT_Msk                     (0x3UL << RTC_TSDR_DT_Pos)              /*!< 0x00000030 */
#define RTC_TSDR_DT                         RTC_TSDR_DT_Msk
#define RTC_TSDR_DT_0                       (0x1UL << RTC_TSDR_DT_Pos)              /*!< 0x00000010 */
#define RTC_TSDR_DT_1                       (0x2UL << RTC_TSDR_DT_Pos)              /*!< 0x00000020 */
#define RTC_TSDR_MU_Pos                     (8U)
#define RTC_TSDR_MU_Msk                     (0xFUL << RTC_TSDR_MU_Pos)              /*!< 0x00000F00 */
#define RTC_TSDR_MU                         RTC_TSDR_MU_Msk
#define RTC_TSDR_MU_0                       (0x1UL << RTC_TSDR_MU_Pos)              /*!< 0x00000100 */
#define RTC_TSDR_MU_1                       (0x2UL << RTC_TSDR_MU_Pos)              /*!< 0x00000200 */
#define RTC_TSDR_MU_2                       (0x4UL << RTC_TSDR_MU_Pos)              /*!< 0x00000400 */
#define RTC_TSDR_MU_3                       (0x8UL << RTC_TSDR_MU_Pos)              /*!< 0x00000800 */
#define RTC_TSDR_MT_Pos                     (12U)
#define RTC_TSDR_MT_Msk                     (0x1UL << RTC_TSDR_MT_Pos)              /*!< 0x00001000 */
#define RTC_TSDR_MT                         RTC_TSDR_MT_Msk
#define RTC_TSDR_WDU_Pos                    (13U)
#define RTC_TSDR_WDU_Msk                    (0x7UL << RTC_TSDR_WDU_Pos)             /*!< 0x0000E000 */
#define RTC_TSDR_WDU                        RTC_TSDR_WDU_Msk
#define RTC_TSDR_WDU_0                      (0x1UL << RTC_TSDR_WDU_Pos)             /*!< 0x00002000 */
#define RTC_TSDR_WDU_1                      (0x2UL << RTC_TSDR_WDU_Pos)             /*!< 0x00004000 */
#define RTC_TSDR_WDU_2                      (0x4UL << RTC_TSDR_WDU_Pos)             /*!< 0x00008000 */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS_Pos                    (0U)
#define RTC_TSSSR_SS_Msk                    (0xFFFFFFFFUL << RTC_TSSSR_SS_Pos)      /*!< 0xFFFFFFFF */
#define RTC_TSSSR_SS                        RTC_TSSSR_SS_Msk                        /*!< rtc timestamp sub second > */

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_SU_Pos                   (0U)
#define RTC_ALRMAR_SU_Msk                   (0xFUL << RTC_ALRMAR_SU_Pos)            /*!< 0x0000000F */
#define RTC_ALRMAR_SU                       RTC_ALRMAR_SU_Msk
#define RTC_ALRMAR_SU_0                     (0x1UL << RTC_ALRMAR_SU_Pos)            /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1                     (0x2UL << RTC_ALRMAR_SU_Pos)            /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2                     (0x4UL << RTC_ALRMAR_SU_Pos)            /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3                     (0x8UL << RTC_ALRMAR_SU_Pos)            /*!< 0x00000008 */
#define RTC_ALRMAR_ST_Pos                   (4U)
#define RTC_ALRMAR_ST_Msk                   (0x7UL << RTC_ALRMAR_ST_Pos)            /*!< 0x00000070 */
#define RTC_ALRMAR_ST                       RTC_ALRMAR_ST_Msk
#define RTC_ALRMAR_ST_0                     (0x1UL << RTC_ALRMAR_ST_Pos)            /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1                     (0x2UL << RTC_ALRMAR_ST_Pos)            /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2                     (0x4UL << RTC_ALRMAR_ST_Pos)            /*!< 0x00000040 */
#define RTC_ALRMAR_MSK1_Pos                 (7U)
#define RTC_ALRMAR_MSK1_Msk                 (0x1UL << RTC_ALRMAR_MSK1_Pos)          /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1                     RTC_ALRMAR_MSK1_Msk
#define RTC_ALRMAR_MNU_Pos                  (8U)
#define RTC_ALRMAR_MNU_Msk                  (0xFUL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                      RTC_ALRMAR_MNU_Msk
#define RTC_ALRMAR_MNU_0                    (0x1UL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1                    (0x2UL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2                    (0x4UL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3                    (0x8UL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000800 */
#define RTC_ALRMAR_MNT_Pos                  (12U)
#define RTC_ALRMAR_MNT_Msk                  (0x7UL << RTC_ALRMAR_MNT_Pos)           /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                      RTC_ALRMAR_MNT_Msk
#define RTC_ALRMAR_MNT_0                    (0x1UL << RTC_ALRMAR_MNT_Pos)           /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1                    (0x2UL << RTC_ALRMAR_MNT_Pos)           /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2                    (0x4UL << RTC_ALRMAR_MNT_Pos)           /*!< 0x00004000 */
#define RTC_ALRMAR_MSK2_Pos                 (15U)
#define RTC_ALRMAR_MSK2_Msk                 (0x1UL << RTC_ALRMAR_MSK2_Pos)          /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2                     RTC_ALRMAR_MSK2_Msk
#define RTC_ALRMAR_HU_Pos                   (16U)
#define RTC_ALRMAR_HU_Msk                   (0xFUL << RTC_ALRMAR_HU_Pos)            /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                       RTC_ALRMAR_HU_Msk
#define RTC_ALRMAR_HU_0                     (0x1UL << RTC_ALRMAR_HU_Pos)            /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1                     (0x2UL << RTC_ALRMAR_HU_Pos)            /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2                     (0x4UL << RTC_ALRMAR_HU_Pos)            /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3                     (0x8UL << RTC_ALRMAR_HU_Pos)            /*!< 0x00080000 */
#define RTC_ALRMAR_HT_Pos                   (20U)
#define RTC_ALRMAR_HT_Msk                   (0x3UL << RTC_ALRMAR_HT_Pos)            /*!< 0x00300000 */
#define RTC_ALRMAR_HT                       RTC_ALRMAR_HT_Msk
#define RTC_ALRMAR_HT_0                     (0x1UL << RTC_ALRMAR_HT_Pos)            /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1                     (0x2UL << RTC_ALRMAR_HT_Pos)            /*!< 0x00200000 */
#define RTC_ALRMAR_PM_Pos                   (22U)
#define RTC_ALRMAR_PM_Msk                   (0x1UL << RTC_ALRMAR_PM_Pos)            /*!< 0x00400000 */
#define RTC_ALRMAR_PM                       RTC_ALRMAR_PM_Msk
#define RTC_ALRMAR_MSK3_Pos                 (23U)
#define RTC_ALRMAR_MSK3_Msk                 (0x1UL << RTC_ALRMAR_MSK3_Pos)          /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3                     RTC_ALRMAR_MSK3_Msk
#define RTC_ALRMAR_DU_Pos                   (24U)
#define RTC_ALRMAR_DU_Msk                   (0xFUL << RTC_ALRMAR_DU_Pos)            /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                       RTC_ALRMAR_DU_Msk
#define RTC_ALRMAR_DU_0                     (0x1UL << RTC_ALRMAR_DU_Pos)            /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1                     (0x2UL << RTC_ALRMAR_DU_Pos)            /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2                     (0x4UL << RTC_ALRMAR_DU_Pos)            /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3                     (0x8UL << RTC_ALRMAR_DU_Pos)            /*!< 0x08000000 */
#define RTC_ALRMAR_DT_Pos                   (28U)
#define RTC_ALRMAR_DT_Msk                   (0x3UL << RTC_ALRMAR_DT_Pos)            /*!< 0x30000000 */
#define RTC_ALRMAR_DT                       RTC_ALRMAR_DT_Msk
#define RTC_ALRMAR_DT_0                     (0x1UL << RTC_ALRMAR_DT_Pos)            /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1                     (0x2UL << RTC_ALRMAR_DT_Pos)            /*!< 0x20000000 */
#define RTC_ALRMAR_WDSEL_Pos                (30U)
#define RTC_ALRMAR_WDSEL_Msk                (0x1UL << RTC_ALRMAR_WDSEL_Pos)         /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL                    RTC_ALRMAR_WDSEL_Msk
#define RTC_ALRMAR_MSK4_Pos                 (31U)
#define RTC_ALRMAR_MSK4_Msk                 (0x1UL << RTC_ALRMAR_MSK4_Pos)          /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4                     RTC_ALRMAR_MSK4_Msk

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_SS_Pos                 (0U)
#define RTC_ALRMASSR_SS_Msk                 (0x7FFFUL << RTC_ALRMASSR_SS_Pos)       /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS                     RTC_ALRMASSR_SS_Msk
#define RTC_ALRMASSR_MASKSS_Pos             (24U)
#define RTC_ALRMASSR_MASKSS_Msk             (0x3FUL << RTC_ALRMASSR_MASKSS_Pos)     /*!< 0x3F000000 */
#define RTC_ALRMASSR_MASKSS                 RTC_ALRMASSR_MASKSS_Msk
#define RTC_ALRMASSR_MASKSS_0               (0x1UL << RTC_ALRMASSR_MASKSS_Pos)      /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1               (0x2UL << RTC_ALRMASSR_MASKSS_Pos)      /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2               (0x4UL << RTC_ALRMASSR_MASKSS_Pos)      /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3               (0x8UL << RTC_ALRMASSR_MASKSS_Pos)      /*!< 0x08000000 */
#define RTC_ALRMASSR_MASKSS_4               (0x10UL << RTC_ALRMASSR_MASKSS_Pos)     /*!< 0x10000000 */
#define RTC_ALRMASSR_MASKSS_5               (0x20UL << RTC_ALRMASSR_MASKSS_Pos)     /*!< 0x20000000 */
#define RTC_ALRMASSR_SSCLR_Pos              (31U)
#define RTC_ALRMASSR_SSCLR_Msk              (0x1UL << RTC_ALRMASSR_SSCLR_Pos)       /*!< 0x80000000 */
#define RTC_ALRMASSR_SSCLR                  RTC_ALRMASSR_SSCLR_Msk

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_SU_Pos                   (0U)
#define RTC_ALRMBR_SU_Msk                   (0xFUL << RTC_ALRMBR_SU_Pos)            /*!< 0x0000000F */
#define RTC_ALRMBR_SU                       RTC_ALRMBR_SU_Msk
#define RTC_ALRMBR_SU_0                     (0x1UL << RTC_ALRMBR_SU_Pos)            /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1                     (0x2UL << RTC_ALRMBR_SU_Pos)            /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2                     (0x4UL << RTC_ALRMBR_SU_Pos)            /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3                     (0x8UL << RTC_ALRMBR_SU_Pos)            /*!< 0x00000008 */
#define RTC_ALRMBR_ST_Pos                   (4U)
#define RTC_ALRMBR_ST_Msk                   (0x7UL << RTC_ALRMBR_ST_Pos)            /*!< 0x00000070 */
#define RTC_ALRMBR_ST                       RTC_ALRMBR_ST_Msk
#define RTC_ALRMBR_ST_0                     (0x1UL << RTC_ALRMBR_ST_Pos)            /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1                     (0x2UL << RTC_ALRMBR_ST_Pos)            /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2                     (0x4UL << RTC_ALRMBR_ST_Pos)            /*!< 0x00000040 */
#define RTC_ALRMBR_MSK1_Pos                 (7U)
#define RTC_ALRMBR_MSK1_Msk                 (0x1UL << RTC_ALRMBR_MSK1_Pos)          /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1                     RTC_ALRMBR_MSK1_Msk
#define RTC_ALRMBR_MNU_Pos                  (8U)
#define RTC_ALRMBR_MNU_Msk                  (0xFUL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                      RTC_ALRMBR_MNU_Msk
#define RTC_ALRMBR_MNU_0                    (0x1UL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1                    (0x2UL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2                    (0x4UL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3                    (0x8UL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000800 */
#define RTC_ALRMBR_MNT_Pos                  (12U)
#define RTC_ALRMBR_MNT_Msk                  (0x7UL << RTC_ALRMBR_MNT_Pos)           /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                      RTC_ALRMBR_MNT_Msk
#define RTC_ALRMBR_MNT_0                    (0x1UL << RTC_ALRMBR_MNT_Pos)           /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1                    (0x2UL << RTC_ALRMBR_MNT_Pos)           /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2                    (0x4UL << RTC_ALRMBR_MNT_Pos)           /*!< 0x00004000 */
#define RTC_ALRMBR_MSK2_Pos                 (15U)
#define RTC_ALRMBR_MSK2_Msk                 (0x1UL << RTC_ALRMBR_MSK2_Pos)          /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2                     RTC_ALRMBR_MSK2_Msk
#define RTC_ALRMBR_HU_Pos                   (16U)
#define RTC_ALRMBR_HU_Msk                   (0xFUL << RTC_ALRMBR_HU_Pos)            /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                       RTC_ALRMBR_HU_Msk
#define RTC_ALRMBR_HU_0                     (0x1UL << RTC_ALRMBR_HU_Pos)            /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1                     (0x2UL << RTC_ALRMBR_HU_Pos)            /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2                     (0x4UL << RTC_ALRMBR_HU_Pos)            /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3                     (0x8UL << RTC_ALRMBR_HU_Pos)            /*!< 0x00080000 */
#define RTC_ALRMBR_HT_Pos                   (20U)
#define RTC_ALRMBR_HT_Msk                   (0x3UL << RTC_ALRMBR_HT_Pos)            /*!< 0x00300000 */
#define RTC_ALRMBR_HT                       RTC_ALRMBR_HT_Msk
#define RTC_ALRMBR_HT_0                     (0x1UL << RTC_ALRMBR_HT_Pos)            /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1                     (0x2UL << RTC_ALRMBR_HT_Pos)            /*!< 0x00200000 */
#define RTC_ALRMBR_PM_Pos                   (22U)
#define RTC_ALRMBR_PM_Msk                   (0x1UL << RTC_ALRMBR_PM_Pos)            /*!< 0x00400000 */
#define RTC_ALRMBR_PM                       RTC_ALRMBR_PM_Msk
#define RTC_ALRMBR_MSK3_Pos                 (23U)
#define RTC_ALRMBR_MSK3_Msk                 (0x1UL << RTC_ALRMBR_MSK3_Pos)          /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3                     RTC_ALRMBR_MSK3_Msk
#define RTC_ALRMBR_DU_Pos                   (24U)
#define RTC_ALRMBR_DU_Msk                   (0xFUL << RTC_ALRMBR_DU_Pos)            /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                       RTC_ALRMBR_DU_Msk
#define RTC_ALRMBR_DU_0                     (0x1UL << RTC_ALRMBR_DU_Pos)            /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1                     (0x2UL << RTC_ALRMBR_DU_Pos)            /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2                     (0x4UL << RTC_ALRMBR_DU_Pos)            /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3                     (0x8UL << RTC_ALRMBR_DU_Pos)            /*!< 0x08000000 */
#define RTC_ALRMBR_DT_Pos                   (28U)
#define RTC_ALRMBR_DT_Msk                   (0x3UL << RTC_ALRMBR_DT_Pos)            /*!< 0x30000000 */
#define RTC_ALRMBR_DT                       RTC_ALRMBR_DT_Msk
#define RTC_ALRMBR_DT_0                     (0x1UL << RTC_ALRMBR_DT_Pos)            /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1                     (0x2UL << RTC_ALRMBR_DT_Pos)            /*!< 0x20000000 */
#define RTC_ALRMBR_WDSEL_Pos                (30U)
#define RTC_ALRMBR_WDSEL_Msk                (0x1UL << RTC_ALRMBR_WDSEL_Pos)         /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL                    RTC_ALRMBR_WDSEL_Msk
#define RTC_ALRMBR_MSK4_Pos                 (31U)
#define RTC_ALRMBR_MSK4_Msk                 (0x1UL << RTC_ALRMBR_MSK4_Pos)          /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4                     RTC_ALRMBR_MSK4_Msk

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_SS_Pos                 (0U)
#define RTC_ALRMBSSR_SS_Msk                 (0x7FFFUL << RTC_ALRMBSSR_SS_Pos)       /*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS                     RTC_ALRMBSSR_SS_Msk
#define RTC_ALRMBSSR_MASKSS_Pos             (24U)
#define RTC_ALRMBSSR_MASKSS_Msk             (0x3FUL << RTC_ALRMBSSR_MASKSS_Pos)     /*!< 0x3F000000 */
#define RTC_ALRMBSSR_MASKSS                 RTC_ALRMBSSR_MASKSS_Msk
#define RTC_ALRMBSSR_MASKSS_0               (0x1UL << RTC_ALRMBSSR_MASKSS_Pos)      /*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1               (0x2UL << RTC_ALRMBSSR_MASKSS_Pos)      /*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2               (0x4UL << RTC_ALRMBSSR_MASKSS_Pos)      /*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3               (0x8UL << RTC_ALRMBSSR_MASKSS_Pos)      /*!< 0x08000000 */
#define RTC_ALRMBSSR_MASKSS_4               (0x10UL << RTC_ALRMBSSR_MASKSS_Pos)     /*!< 0x10000000 */
#define RTC_ALRMBSSR_MASKSS_5               (0x20UL << RTC_ALRMBSSR_MASKSS_Pos)     /*!< 0x20000000 */
#define RTC_ALRMBSSR_SSCLR_Pos              (31U)
#define RTC_ALRMBSSR_SSCLR_Msk              (0x1UL << RTC_ALRMBSSR_SSCLR_Pos)       /*!< 0x80000000 */
#define RTC_ALRMBSSR_SSCLR                  RTC_ALRMBSSR_SSCLR_Msk

/********************  Bits definition for RTC_SR register  *******************/
#define RTC_SR_ALRAF_Pos                    (0U)
#define RTC_SR_ALRAF_Msk                    (0x1UL << RTC_SR_ALRAF_Pos)             /*!< 0x00000001 */
#define RTC_SR_ALRAF                        RTC_SR_ALRAF_Msk
#define RTC_SR_ALRBF_Pos                    (1U)
#define RTC_SR_ALRBF_Msk                    (0x1UL << RTC_SR_ALRBF_Pos)             /*!< 0x00000002 */
#define RTC_SR_ALRBF                        RTC_SR_ALRBF_Msk
#define RTC_SR_WUTF_Pos                     (2U)
#define RTC_SR_WUTF_Msk                     (0x1UL << RTC_SR_WUTF_Pos)              /*!< 0x00000004 */
#define RTC_SR_WUTF                         RTC_SR_WUTF_Msk
#define RTC_SR_TSF_Pos                      (3U)
#define RTC_SR_TSF_Msk                      (0x1UL << RTC_SR_TSF_Pos)               /*!< 0x00000008 */
#define RTC_SR_TSF                          RTC_SR_TSF_Msk
#define RTC_SR_TSOVF_Pos                    (4U)
#define RTC_SR_TSOVF_Msk                    (0x1UL << RTC_SR_TSOVF_Pos)             /*!< 0x00000010 */
#define RTC_SR_TSOVF                        RTC_SR_TSOVF_Msk
#define RTC_SR_SSRUF_Pos                    (6U)
#define RTC_SR_SSRUF_Msk                    (0x1UL << RTC_SR_SSRUF_Pos)             /*!< 0x00000040 */
#define RTC_SR_SSRUF                        RTC_SR_SSRUF_Msk

/********************  Bits definition for RTC_MISR register  *****************/
#define RTC_MISR_ALRAMF_Pos                 (0U)
#define RTC_MISR_ALRAMF_Msk                 (0x1UL << RTC_MISR_ALRAMF_Pos)          /*!< 0x00000001 */
#define RTC_MISR_ALRAMF                     RTC_MISR_ALRAMF_Msk
#define RTC_MISR_ALRBMF_Pos                 (1U)
#define RTC_MISR_ALRBMF_Msk                 (0x1UL << RTC_MISR_ALRBMF_Pos)          /*!< 0x00000002 */
#define RTC_MISR_ALRBMF                     RTC_MISR_ALRBMF_Msk
#define RTC_MISR_WUTMF_Pos                  (2U)
#define RTC_MISR_WUTMF_Msk                  (0x1UL << RTC_MISR_WUTMF_Pos)           /*!< 0x00000004 */
#define RTC_MISR_WUTMF                      RTC_MISR_WUTMF_Msk
#define RTC_MISR_TSMF_Pos                   (3U)
#define RTC_MISR_TSMF_Msk                   (0x1UL << RTC_MISR_TSMF_Pos)            /*!< 0x00000008 */
#define RTC_MISR_TSMF                       RTC_MISR_TSMF_Msk
#define RTC_MISR_TSOVMF_Pos                 (4U)
#define RTC_MISR_TSOVMF_Msk                 (0x1UL << RTC_MISR_TSOVMF_Pos)          /*!< 0x00000010 */
#define RTC_MISR_TSOVMF                     RTC_MISR_TSOVMF_Msk
#define RTC_MISR_SSRUMF_Pos                 (6U)
#define RTC_MISR_SSRUMF_Msk                 (0x1UL << RTC_MISR_SSRUMF_Pos)          /*!< 0x00000040 */
#define RTC_MISR_SSRUMF                     RTC_MISR_SSRUMF_Msk

/********************  Bits definition for RTC_SCR register  ******************/
#define RTC_SCR_CALRAF_Pos                  (0U)
#define RTC_SCR_CALRAF_Msk                  (0x1UL << RTC_SCR_CALRAF_Pos)           /*!< 0x00000001 */
#define RTC_SCR_CALRAF                      RTC_SCR_CALRAF_Msk
#define RTC_SCR_CALRBF_Pos                  (1U)
#define RTC_SCR_CALRBF_Msk                  (0x1UL << RTC_SCR_CALRBF_Pos)           /*!< 0x00000002 */
#define RTC_SCR_CALRBF                      RTC_SCR_CALRBF_Msk
#define RTC_SCR_CWUTF_Pos                   (2U)
#define RTC_SCR_CWUTF_Msk                   (0x1UL << RTC_SCR_CWUTF_Pos)            /*!< 0x00000004 */
#define RTC_SCR_CWUTF                       RTC_SCR_CWUTF_Msk
#define RTC_SCR_CTSF_Pos                    (3U)
#define RTC_SCR_CTSF_Msk                    (0x1UL << RTC_SCR_CTSF_Pos)             /*!< 0x00000008 */
#define RTC_SCR_CTSF                        RTC_SCR_CTSF_Msk
#define RTC_SCR_CTSOVF_Pos                  (4U)
#define RTC_SCR_CTSOVF_Msk                  (0x1UL << RTC_SCR_CTSOVF_Pos)           /*!< 0x00000010 */
#define RTC_SCR_CTSOVF                      RTC_SCR_CTSOVF_Msk
#define RTC_SCR_CSSRUF_Pos                  (6U)
#define RTC_SCR_CSSRUF_Msk                  (0x1UL << RTC_SCR_CSSRUF_Pos)           /*!< 0x00000040 */
#define RTC_SCR_CSSRUF                      RTC_SCR_CSSRUF_Msk

/********************  Bits definition for RTC_ALRABINR register  ******************/
#define RTC_ALRABINR_SS_Pos                 (0U)
#define RTC_ALRABINR_SS_Msk                 (0xFFFFFFFFUL << RTC_ALRABINR_SS_Pos)   /*!< 0xFFFFFFFF */
#define RTC_ALRABINR_SS                     RTC_ALRABINR_SS_Msk

/********************  Bits definition for RTC_ALRBBINR register  ******************/
#define RTC_ALRBBINR_SS_Pos                 (0U)
#define RTC_ALRBBINR_SS_Msk                 (0xFFFFFFFFUL << RTC_ALRBBINR_SS_Pos)   /*!< 0xFFFFFFFF */
#define RTC_ALRBBINR_SS                     RTC_ALRBBINR_SS_Msk


/******************************************************************************/
/*                                                                            */
/*                   Serial Peripheral Interface (SPI)                        */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_SPE_Pos                     (0U)
#define SPI_CR1_SPE_Msk                     (0x1UL << SPI_CR1_SPE_Pos)              /*!< 0x00000001 */
#define SPI_CR1_SPE                         SPI_CR1_SPE_Msk                         /*!<Serial Peripheral Enable */
#define SPI_CR1_MASRX_Pos                   (8U)
#define SPI_CR1_MASRX_Msk                   (0x1UL << SPI_CR1_MASRX_Pos)            /*!< 0x00000100 */
#define SPI_CR1_MASRX                       SPI_CR1_MASRX_Msk                       /*!<Master automatic SUSP in Receive mode */
#define SPI_CR1_CSTART_Pos                  (9U)
#define SPI_CR1_CSTART_Msk                  (0x1UL << SPI_CR1_CSTART_Pos)           /*!< 0x00000200 */
#define SPI_CR1_CSTART                      SPI_CR1_CSTART_Msk                      /*!<Master transfer start  */
#define SPI_CR1_CSUSP_Pos                   (10U)
#define SPI_CR1_CSUSP_Msk                   (0x1UL << SPI_CR1_CSUSP_Pos)            /*!< 0x00000400 */
#define SPI_CR1_CSUSP                       SPI_CR1_CSUSP_Msk                       /*!<Master SUSPend request */
#define SPI_CR1_HDDIR_Pos                   (11U)
#define SPI_CR1_HDDIR_Msk                   (0x1UL << SPI_CR1_HDDIR_Pos)            /*!< 0x00000800 */
#define SPI_CR1_HDDIR                       SPI_CR1_HDDIR_Msk                       /*!<Rx/Tx direction at Half-duplex mode */
#define SPI_CR1_SSI_Pos                     (12U)
#define SPI_CR1_SSI_Msk                     (0x1UL << SPI_CR1_SSI_Pos)              /*!< 0x00001000 */
#define SPI_CR1_SSI                         SPI_CR1_SSI_Msk                         /*!<Internal SS signal input level */
#define SPI_CR1_CRC33_17_Pos                (13U)
#define SPI_CR1_CRC33_17_Msk                (0x1UL << SPI_CR1_CRC33_17_Pos)         /*!< 0x00002000 */
#define SPI_CR1_CRC33_17                    SPI_CR1_CRC33_17_Msk                    /*!<32-bit CRC polynomial configuration */
#define SPI_CR1_RCRCINI_Pos                 (14U)
#define SPI_CR1_RCRCINI_Msk                 (0x1UL << SPI_CR1_RCRCINI_Pos)          /*!< 0x00004000 */
#define SPI_CR1_RCRCINI                     SPI_CR1_RCRCINI_Msk                     /*!<CRC init pattern control for receiver */
#define SPI_CR1_TCRCINI_Pos                 (15U)
#define SPI_CR1_TCRCINI_Msk                 (0x1UL << SPI_CR1_TCRCINI_Pos)          /*!< 0x00008000 */
#define SPI_CR1_TCRCINI                     SPI_CR1_TCRCINI_Msk                     /*!<CRC init pattern control for transmitter */
#define SPI_CR1_IOLOCK_Pos                  (16U)
#define SPI_CR1_IOLOCK_Msk                  (0x1UL << SPI_CR1_IOLOCK_Pos)           /*!< 0x00010000 */
#define SPI_CR1_IOLOCK                      SPI_CR1_IOLOCK_Msk                      /*!<Locking the AF configuration of associated IOs */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_TSIZE_Pos                   (0U)
#define SPI_CR2_TSIZE_Msk                   (0xFFFFUL << SPI_CR2_TSIZE_Pos)         /*!< 0x0000FFFF */
#define SPI_CR2_TSIZE                       SPI_CR2_TSIZE_Msk                       /*!<Number of data at current transfer */

/*******************  Bit definition for SPI_CFG1 register  ********************/
#define SPI_CFG1_DSIZE_Pos                  (0U)
#define SPI_CFG1_DSIZE_Msk                  (0x1FUL << SPI_CFG1_DSIZE_Pos)          /*!< 0x0000001F */
#define SPI_CFG1_DSIZE                      SPI_CFG1_DSIZE_Msk                      /*!<DSIZE[4:0]: Bits number in single SPI data frame */
#define SPI_CFG1_DSIZE_0                    (0x01UL << SPI_CFG1_DSIZE_Pos)          /*!< 0x00000001 */
#define SPI_CFG1_DSIZE_1                    (0x02UL << SPI_CFG1_DSIZE_Pos)          /*!< 0x00000002 */
#define SPI_CFG1_DSIZE_2                    (0x04UL << SPI_CFG1_DSIZE_Pos)          /*!< 0x00000004 */
#define SPI_CFG1_DSIZE_3                    (0x08UL << SPI_CFG1_DSIZE_Pos)          /*!< 0x00000008 */
#define SPI_CFG1_DSIZE_4                    (0x10UL << SPI_CFG1_DSIZE_Pos)          /*!< 0x00000010 */
#define SPI_CFG1_FTHLV_Pos                  (5U)
#define SPI_CFG1_FTHLV_Msk                  (0xFUL << SPI_CFG1_FTHLV_Pos)           /*!< 0x000001E0 */
#define SPI_CFG1_FTHLV                      SPI_CFG1_FTHLV_Msk                      /*!<FTHVL [3:0]: FIFO threshold level*/
#define SPI_CFG1_FTHLV_0                    (0x1UL << SPI_CFG1_FTHLV_Pos)           /*!< 0x00000020 */
#define SPI_CFG1_FTHLV_1                    (0x2UL << SPI_CFG1_FTHLV_Pos)           /*!< 0x00000040 */
#define SPI_CFG1_FTHLV_2                    (0x4UL << SPI_CFG1_FTHLV_Pos)           /*!< 0x00000080 */
#define SPI_CFG1_FTHLV_3                    (0x8UL << SPI_CFG1_FTHLV_Pos)           /*!< 0x00000100 */
#define SPI_CFG1_UDRCFG_Pos                 (9U)
#define SPI_CFG1_UDRCFG_Msk                 (0x1UL << SPI_CFG1_UDRCFG_Pos)          /*!< 0x00000600 */
#define SPI_CFG1_UDRCFG                     SPI_CFG1_UDRCFG_Msk                     /*!<Behavior of Slave transmitter at underrun */
#define SPI_CFG1_RXDMAEN_Pos                (14U)
#define SPI_CFG1_RXDMAEN_Msk                (0x1UL << SPI_CFG1_RXDMAEN_Pos)         /*!< 0x00004000 */
#define SPI_CFG1_RXDMAEN                    SPI_CFG1_RXDMAEN_Msk                    /*!<Rx DMA stream enable */
#define SPI_CFG1_TXDMAEN_Pos                (15U)
#define SPI_CFG1_TXDMAEN_Msk                (0x1UL << SPI_CFG1_TXDMAEN_Pos)         /*!< 0x00008000 */
#define SPI_CFG1_TXDMAEN                    SPI_CFG1_TXDMAEN_Msk                    /*!<Tx DMA stream enable */
#define SPI_CFG1_CRCSIZE_Pos                (16U)
#define SPI_CFG1_CRCSIZE_Msk                (0x1FUL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x001F0000 */
#define SPI_CFG1_CRCSIZE                    SPI_CFG1_CRCSIZE_Msk                    /*!<CRCSIZE [4:0]: Length of CRC frame */
#define SPI_CFG1_CRCSIZE_0                  (0x01UL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x00010000 */
#define SPI_CFG1_CRCSIZE_1                  (0x02UL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x00020000 */
#define SPI_CFG1_CRCSIZE_2                  (0x04UL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x00040000 */
#define SPI_CFG1_CRCSIZE_3                  (0x08UL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x00080000 */
#define SPI_CFG1_CRCSIZE_4                  (0x10UL << SPI_CFG1_CRCSIZE_Pos)        /*!< 0x00100000 */
#define SPI_CFG1_CRCEN_Pos                  (22U)
#define SPI_CFG1_CRCEN_Msk                  (0x1UL << SPI_CFG1_CRCEN_Pos)           /*!< 0x00400000 */
#define SPI_CFG1_CRCEN                      SPI_CFG1_CRCEN_Msk                      /*!<Hardware CRC computation enable */
#define SPI_CFG1_MBR_Pos                    (28U)
#define SPI_CFG1_MBR_Msk                    (0x7UL << SPI_CFG1_MBR_Pos)             /*!< 0x70000000 */
#define SPI_CFG1_MBR                        SPI_CFG1_MBR_Msk                        /*!<Master baud rate */
#define SPI_CFG1_MBR_0                      (0x1UL << SPI_CFG1_MBR_Pos)             /*!< 0x10000000 */
#define SPI_CFG1_MBR_1                      (0x2UL << SPI_CFG1_MBR_Pos)             /*!< 0x20000000 */
#define SPI_CFG1_MBR_2                      (0x4UL << SPI_CFG1_MBR_Pos)             /*!< 0x40000000 */
#define SPI_CFG1_BPASS_Pos                  (31U)
#define SPI_CFG1_BPASS_Msk                  (0x1UL << SPI_CFG1_BPASS_Pos)           /*!< 0x80000000 */
#define SPI_CFG1_BPASS                      SPI_CFG1_BPASS_Msk                      /*!<Bypass of the prescaler */

/*******************  Bit definition for SPI_CFG2 register  ********************/
#define SPI_CFG2_MSSI_Pos                   (0U)
#define SPI_CFG2_MSSI_Msk                   (0xFUL << SPI_CFG2_MSSI_Pos)            /*!< 0x0000000F */
#define SPI_CFG2_MSSI                       SPI_CFG2_MSSI_Msk                       /*!<Master SS Idleness */
#define SPI_CFG2_MSSI_0                     (0x1UL << SPI_CFG2_MSSI_Pos)            /*!< 0x00000001 */
#define SPI_CFG2_MSSI_1                     (0x2UL << SPI_CFG2_MSSI_Pos)            /*!< 0x00000002 */
#define SPI_CFG2_MSSI_2                     (0x4UL << SPI_CFG2_MSSI_Pos)            /*!< 0x00000004 */
#define SPI_CFG2_MSSI_3                     (0x8UL << SPI_CFG2_MSSI_Pos)            /*!< 0x00000008 */
#define SPI_CFG2_MIDI_Pos                   (4U)
#define SPI_CFG2_MIDI_Msk                   (0xFUL << SPI_CFG2_MIDI_Pos)            /*!< 0x000000F0 */
#define SPI_CFG2_MIDI                       SPI_CFG2_MIDI_Msk                       /*!<Master Inter-Data Idleness */
#define SPI_CFG2_MIDI_0                     (0x1UL << SPI_CFG2_MIDI_Pos)            /*!< 0x00000010 */
#define SPI_CFG2_MIDI_1                     (0x2UL << SPI_CFG2_MIDI_Pos)            /*!< 0x00000020 */
#define SPI_CFG2_MIDI_2                     (0x4UL << SPI_CFG2_MIDI_Pos)            /*!< 0x00000040 */
#define SPI_CFG2_MIDI_3                     (0x8UL << SPI_CFG2_MIDI_Pos)            /*!< 0x00000080 */
#define SPI_CFG2_RDIMM_Pos                  (13U)
#define SPI_CFG2_RDIMM_Msk                  (0x1UL << SPI_CFG2_RDIMM_Pos)           /*!< 0x00002000 */
#define SPI_CFG2_RDIMM                      SPI_CFG2_RDIMM_Msk                      /*!<RDY signal input master management */
#define SPI_CFG2_RDIOP_Pos                  (14U)
#define SPI_CFG2_RDIOP_Msk                  (0x1UL << SPI_CFG2_RDIOP_Pos)           /*!< 0x00004000 */
#define SPI_CFG2_RDIOP                      SPI_CFG2_RDIOP_Msk                      /*!<RDY signal input/output polarity */
#define SPI_CFG2_IOSWP_Pos                  (15U)
#define SPI_CFG2_IOSWP_Msk                  (0x1UL << SPI_CFG2_IOSWP_Pos)           /*!< 0x00008000 */
#define SPI_CFG2_IOSWP                      SPI_CFG2_IOSWP_Msk                      /*!<Swap functionality of MISO and MOSI pins */
#define SPI_CFG2_COMM_Pos                   (17U)
#define SPI_CFG2_COMM_Msk                   (0x3UL << SPI_CFG2_COMM_Pos)            /*!< 0x00060000 */
#define SPI_CFG2_COMM                       SPI_CFG2_COMM_Msk                       /*!<COMM [1:0]: SPI Communication Mode*/
#define SPI_CFG2_COMM_0                     (0x1UL << SPI_CFG2_COMM_Pos)            /*!< 0x00020000 */
#define SPI_CFG2_COMM_1                     (0x2UL << SPI_CFG2_COMM_Pos)            /*!< 0x00040000 */
#define SPI_CFG2_SP_Pos                     (19U)
#define SPI_CFG2_SP_Msk                     (0x7UL << SPI_CFG2_SP_Pos)              /*!< 0x00380000 */
#define SPI_CFG2_SP                         SPI_CFG2_SP_Msk                         /*!<SP[2:0]: Serial Protocol */
#define SPI_CFG2_SP_0                       (0x1UL << SPI_CFG2_SP_Pos)              /*!< 0x00080000 */
#define SPI_CFG2_SP_1                       (0x2UL << SPI_CFG2_SP_Pos)              /*!< 0x00100000 */
#define SPI_CFG2_SP_2                       (0x4UL << SPI_CFG2_SP_Pos)              /*!< 0x00200000 */
#define SPI_CFG2_MASTER_Pos                 (22U)
#define SPI_CFG2_MASTER_Msk                 (0x1UL << SPI_CFG2_MASTER_Pos)          /*!< 0x00400000 */
#define SPI_CFG2_MASTER                     SPI_CFG2_MASTER_Msk                     /*!<SPI Master */
#define SPI_CFG2_LSBFRST_Pos                (23U)
#define SPI_CFG2_LSBFRST_Msk                (0x1UL << SPI_CFG2_LSBFRST_Pos)         /*!< 0x00800000 */
#define SPI_CFG2_LSBFRST                    SPI_CFG2_LSBFRST_Msk                    /*!<Data frame format */
#define SPI_CFG2_CPHA_Pos                   (24U)
#define SPI_CFG2_CPHA_Msk                   (0x1UL << SPI_CFG2_CPHA_Pos)            /*!< 0x01000000 */
#define SPI_CFG2_CPHA                       SPI_CFG2_CPHA_Msk                       /*!<Clock Phase */
#define SPI_CFG2_CPOL_Pos                   (25U)
#define SPI_CFG2_CPOL_Msk                   (0x1UL << SPI_CFG2_CPOL_Pos)            /*!< 0x02000000 */
#define SPI_CFG2_CPOL                       SPI_CFG2_CPOL_Msk                       /*!<Clock Polarity */
#define SPI_CFG2_SSM_Pos                    (26U)
#define SPI_CFG2_SSM_Msk                    (0x1UL << SPI_CFG2_SSM_Pos)             /*!< 0x04000000 */
#define SPI_CFG2_SSM                        SPI_CFG2_SSM_Msk                        /*!<Software slave management */
#define SPI_CFG2_SSIOP_Pos                  (28U)
#define SPI_CFG2_SSIOP_Msk                  (0x1UL << SPI_CFG2_SSIOP_Pos)           /*!< 0x10000000 */
#define SPI_CFG2_SSIOP                      SPI_CFG2_SSIOP_Msk                      /*!<SS input/output polarity */
#define SPI_CFG2_SSOE_Pos                   (29U)
#define SPI_CFG2_SSOE_Msk                   (0x1UL << SPI_CFG2_SSOE_Pos)            /*!< 0x20000000 */
#define SPI_CFG2_SSOE                       SPI_CFG2_SSOE_Msk                       /*!<SS output enable */
#define SPI_CFG2_SSOM_Pos                   (30U)
#define SPI_CFG2_SSOM_Msk                   (0x1UL << SPI_CFG2_SSOM_Pos)            /*!< 0x40000000 */
#define SPI_CFG2_SSOM                       SPI_CFG2_SSOM_Msk                       /*!<SS output management in master mode */
#define SPI_CFG2_AFCNTR_Pos                 (31U)
#define SPI_CFG2_AFCNTR_Msk                 (0x1UL << SPI_CFG2_AFCNTR_Pos)          /*!< 0x80000000 */
#define SPI_CFG2_AFCNTR                     SPI_CFG2_AFCNTR_Msk                     /*!<Alternate function GPIOs control */

/*******************  Bit definition for SPI_IER register  ********************/
#define SPI_IER_RXPIE_Pos                   (0U)
#define SPI_IER_RXPIE_Msk                   (0x1UL << SPI_IER_RXPIE_Pos)            /*!< 0x00000001 */
#define SPI_IER_RXPIE                       SPI_IER_RXPIE_Msk                       /*!<RXP Interrupt Enable */
#define SPI_IER_TXPIE_Pos                   (1U)
#define SPI_IER_TXPIE_Msk                   (0x1UL << SPI_IER_TXPIE_Pos)            /*!< 0x00000002 */
#define SPI_IER_TXPIE                       SPI_IER_TXPIE_Msk                       /*!<TXP interrupt enable */
#define SPI_IER_DXPIE_Pos                   (2U)
#define SPI_IER_DXPIE_Msk                   (0x1UL << SPI_IER_DXPIE_Pos)            /*!< 0x00000004 */
#define SPI_IER_DXPIE                       SPI_IER_DXPIE_Msk                       /*!<DXP interrupt enable */
#define SPI_IER_EOTIE_Pos                   (3U)
#define SPI_IER_EOTIE_Msk                   (0x1UL << SPI_IER_EOTIE_Pos)            /*!< 0x00000008 */
#define SPI_IER_EOTIE                       SPI_IER_EOTIE_Msk                       /*!<EOT/SUSP/TXC interrupt enable */
#define SPI_IER_TXTFIE_Pos                  (4U)
#define SPI_IER_TXTFIE_Msk                  (0x1UL << SPI_IER_TXTFIE_Pos)           /*!< 0x00000010 */
#define SPI_IER_TXTFIE                      SPI_IER_TXTFIE_Msk                      /*!<TXTF interrupt enable */
#define SPI_IER_UDRIE_Pos                   (5U)
#define SPI_IER_UDRIE_Msk                   (0x1UL << SPI_IER_UDRIE_Pos)            /*!< 0x00000020 */
#define SPI_IER_UDRIE                       SPI_IER_UDRIE_Msk                       /*!<UDR interrupt enable */
#define SPI_IER_OVRIE_Pos                   (6U)
#define SPI_IER_OVRIE_Msk                   (0x1UL << SPI_IER_OVRIE_Pos)            /*!< 0x00000040 */
#define SPI_IER_OVRIE                       SPI_IER_OVRIE_Msk                       /*!<OVR interrupt enable */
#define SPI_IER_CRCEIE_Pos                  (7U)
#define SPI_IER_CRCEIE_Msk                  (0x1UL << SPI_IER_CRCEIE_Pos)           /*!< 0x00000080 */
#define SPI_IER_CRCEIE                      SPI_IER_CRCEIE_Msk                      /*!<CRCE interrupt enable */
#define SPI_IER_TIFREIE_Pos                 (8U)
#define SPI_IER_TIFREIE_Msk                 (0x1UL << SPI_IER_TIFREIE_Pos)          /*!< 0x00000100 */
#define SPI_IER_TIFREIE                     SPI_IER_TIFREIE_Msk                     /*!<TI Frame Error interrupt enable */
#define SPI_IER_MODFIE_Pos                  (9U)
#define SPI_IER_MODFIE_Msk                  (0x1UL << SPI_IER_MODFIE_Pos)           /*!< 0x00000200 */
#define SPI_IER_MODFIE                      SPI_IER_MODFIE_Msk                      /*!<MODF interrupt enable */

/*******************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXP_Pos                      (0U)
#define SPI_SR_RXP_Msk                      (0x1UL << SPI_SR_RXP_Pos)               /*!< 0x00000001 */
#define SPI_SR_RXP                          SPI_SR_RXP_Msk                          /*!<Rx-Packet available */
#define SPI_SR_TXP_Pos                      (1U)
#define SPI_SR_TXP_Msk                      (0x1UL << SPI_SR_TXP_Pos)               /*!< 0x00000002 */
#define SPI_SR_TXP                          SPI_SR_TXP_Msk                          /*!<Tx-Packet space available */
#define SPI_SR_DXP_Pos                      (2U)
#define SPI_SR_DXP_Msk                      (0x1UL << SPI_SR_DXP_Pos)               /*!< 0x00000004 */
#define SPI_SR_DXP                          SPI_SR_DXP_Msk                          /*!<Duplex Packet available */
#define SPI_SR_EOT_Pos                      (3U)
#define SPI_SR_EOT_Msk                      (0x1UL << SPI_SR_EOT_Pos)               /*!< 0x00000008 */
#define SPI_SR_EOT                          SPI_SR_EOT_Msk                          /*!<Duplex Packet available */
#define SPI_SR_TXTF_Pos                     (4U)
#define SPI_SR_TXTF_Msk                     (0x1UL << SPI_SR_TXTF_Pos)              /*!< 0x00000010 */
#define SPI_SR_TXTF                         SPI_SR_TXTF_Msk                         /*!<Transmission Transfer Filled */
#define SPI_SR_UDR_Pos                      (5U)
#define SPI_SR_UDR_Msk                      (0x1UL << SPI_SR_UDR_Pos)               /*!< 0x00000020 */
#define SPI_SR_UDR                          SPI_SR_UDR_Msk                          /*!<UDR at Slave transmission */
#define SPI_SR_OVR_Pos                      (6U)
#define SPI_SR_OVR_Msk                      (0x1UL << SPI_SR_OVR_Pos)               /*!< 0x00000040 */
#define SPI_SR_OVR                          SPI_SR_OVR_Msk                          /*!<Rx-Packet available */
#define SPI_SR_CRCE_Pos                     (7U)
#define SPI_SR_CRCE_Msk                     (0x1UL << SPI_SR_CRCE_Pos)              /*!< 0x00000080 */
#define SPI_SR_CRCE                         SPI_SR_CRCE_Msk                         /*!<CRC Error Detected */
#define SPI_SR_TIFRE_Pos                    (8U)
#define SPI_SR_TIFRE_Msk                    (0x1UL << SPI_SR_TIFRE_Pos)             /*!< 0x00000100 */
#define SPI_SR_TIFRE                        SPI_SR_TIFRE_Msk                        /*!<TI frame format error Detected */
#define SPI_SR_MODF_Pos                     (9U)
#define SPI_SR_MODF_Msk                     (0x1UL << SPI_SR_MODF_Pos)              /*!< 0x00000200 */
#define SPI_SR_MODF                         SPI_SR_MODF_Msk                         /*!<Mode Fault Detected */
#define SPI_SR_SUSP_Pos                     (11U)
#define SPI_SR_SUSP_Msk                     (0x1UL << SPI_SR_SUSP_Pos)              /*!< 0x00000800 */
#define SPI_SR_SUSP                         SPI_SR_SUSP_Msk                         /*!<SUSP is set by hardware */
#define SPI_SR_TXC_Pos                      (12U)
#define SPI_SR_TXC_Msk                      (0x1UL << SPI_SR_TXC_Pos)               /*!< 0x00001000 */
#define SPI_SR_TXC                          SPI_SR_TXC_Msk                          /*!<TxFIFO transmission complete */
#define SPI_SR_RXPLVL_Pos                   (13U)
#define SPI_SR_RXPLVL_Msk                   (0x3UL << SPI_SR_RXPLVL_Pos)            /*!< 0x00006000 */
#define SPI_SR_RXPLVL                       SPI_SR_RXPLVL_Msk                       /*!<RxFIFO Packing Level */
#define SPI_SR_RXPLVL_0                     (0x1UL << SPI_SR_RXPLVL_Pos)            /*!< 0x00002000 */
#define SPI_SR_RXPLVL_1                     (0x2UL << SPI_SR_RXPLVL_Pos)            /*!< 0x00004000 */
#define SPI_SR_RXWNE_Pos                    (15U)
#define SPI_SR_RXWNE_Msk                    (0x1UL << SPI_SR_RXWNE_Pos)             /*!< 0x00008000 */
#define SPI_SR_RXWNE                        SPI_SR_RXWNE_Msk                        /*!<Rx FIFO Word Not Empty */
#define SPI_SR_CTSIZE_Pos                   (16U)
#define SPI_SR_CTSIZE_Msk                   (0xFFFFUL << SPI_SR_CTSIZE_Pos)         /*!< 0xFFFF0000 */
#define SPI_SR_CTSIZE                       SPI_SR_CTSIZE_Msk                       /*!<Number of data frames remaining in TSIZE */

/*******************  Bit definition for SPI_IFCR register  ********************/
#define SPI_IFCR_EOTC_Pos                   (3U)
#define SPI_IFCR_EOTC_Msk                   (0x1UL << SPI_IFCR_EOTC_Pos)            /*!< 0x00000008 */
#define SPI_IFCR_EOTC                       SPI_IFCR_EOTC_Msk                       /*!<End Of Transfer flag clear */
#define SPI_IFCR_TXTFC_Pos                  (4U)
#define SPI_IFCR_TXTFC_Msk                  (0x1UL << SPI_IFCR_TXTFC_Pos)           /*!< 0x00000010 */
#define SPI_IFCR_TXTFC                      SPI_IFCR_TXTFC_Msk                      /*!<Transmission Transfer Filled flag clear */
#define SPI_IFCR_UDRC_Pos                   (5U)
#define SPI_IFCR_UDRC_Msk                   (0x1UL << SPI_IFCR_UDRC_Pos)            /*!< 0x00000020 */
#define SPI_IFCR_UDRC                       SPI_IFCR_UDRC_Msk                       /*!<Underrun flag clear */
#define SPI_IFCR_OVRC_Pos                   (6U)
#define SPI_IFCR_OVRC_Msk                   (0x1UL << SPI_IFCR_OVRC_Pos)            /*!< 0x00000040 */
#define SPI_IFCR_OVRC                       SPI_IFCR_OVRC_Msk                       /*!<Overrun flag clear */
#define SPI_IFCR_CRCEC_Pos                  (7U)
#define SPI_IFCR_CRCEC_Msk                  (0x1UL << SPI_IFCR_CRCEC_Pos)           /*!< 0x00000080 */
#define SPI_IFCR_CRCEC                      SPI_IFCR_CRCEC_Msk                      /*!<CRC Error flag clear */
#define SPI_IFCR_TIFREC_Pos                 (8U)
#define SPI_IFCR_TIFREC_Msk                 (0x1UL << SPI_IFCR_TIFREC_Pos)          /*!< 0x00000100 */
#define SPI_IFCR_TIFREC                     SPI_IFCR_TIFREC_Msk                     /*!<TI frame format error flag clear */
#define SPI_IFCR_MODFC_Pos                  (9U)
#define SPI_IFCR_MODFC_Msk                  (0x1UL << SPI_IFCR_MODFC_Pos)           /*!< 0x00000200 */
#define SPI_IFCR_MODFC                      SPI_IFCR_MODFC_Msk                      /*!<Mode Fault flag clear */
#define SPI_IFCR_SUSPC_Pos                  (11U)
#define SPI_IFCR_SUSPC_Msk                  (0x1UL << SPI_IFCR_SUSPC_Pos)           /*!< 0x00000800 */
#define SPI_IFCR_SUSPC                      SPI_IFCR_SUSPC_Msk                      /*!<SUSPend flag clear */

/*******************  Bit definition for SPI_AUTOCR register  ********************/
#define SPI_AUTOCR_TRIGSEL_Pos              (16U)
#define SPI_AUTOCR_TRIGSEL_Msk              (0xFUL << SPI_AUTOCR_TRIGSEL_Pos)       /*!< 0x000F0000 */
#define SPI_AUTOCR_TRIGSEL                  SPI_AUTOCR_TRIGSEL_Msk                  /*!<CTRIGSEL [3:0]: Trigger selection */
#define SPI_AUTOCR_TRIGSEL_0                (0x01UL << SPI_AUTOCR_TRIGSEL_Pos)      /*!< 0x00010000 */
#define SPI_AUTOCR_TRIGSEL_1                (0x02UL << SPI_AUTOCR_TRIGSEL_Pos)      /*!< 0x00020000 */
#define SPI_AUTOCR_TRIGSEL_2                (0x04UL << SPI_AUTOCR_TRIGSEL_Pos)      /*!< 0x00040000 */
#define SPI_AUTOCR_TRIGSEL_3                (0x08UL << SPI_AUTOCR_TRIGSEL_Pos)      /*!< 0x00080000 */
#define SPI_AUTOCR_TRIGPOL_Pos              (20U)
#define SPI_AUTOCR_TRIGPOL_Msk              (0x1UL << SPI_AUTOCR_TRIGPOL_Pos)       /*!< 0x00100000 */
#define SPI_AUTOCR_TRIGPOL                  SPI_AUTOCR_TRIGPOL_Msk                  /*!<Trigger polarity */
#define SPI_AUTOCR_TRIGEN_Pos               (21U)
#define SPI_AUTOCR_TRIGEN_Msk               (0x1UL << SPI_AUTOCR_TRIGEN_Pos)        /*!< 0x00200000 */
#define SPI_AUTOCR_TRIGEN                   SPI_AUTOCR_TRIGEN_Msk                   /*!<Trigger of CSTART control enable */

/*******************  Bit definition for SPI_TXDR register  ********************/
#define SPI_TXDR_TXDR_Pos                   (0U)
#define SPI_TXDR_TXDR_Msk                   (0xFFFFFFFFUL << SPI_TXDR_TXDR_Pos)     /*!< 0xFFFFFFFF */
#define SPI_TXDR_TXDR                       SPI_TXDR_TXDR_Msk                       /* Transmit Data Register */

/*******************  Bit definition for SPI_RXDR register  ********************/
#define SPI_RXDR_RXDR_Pos                   (0U)
#define SPI_RXDR_RXDR_Msk                   (0xFFFFFFFFUL << SPI_RXDR_RXDR_Pos)     /*!< 0xFFFFFFFF */
#define SPI_RXDR_RXDR                       SPI_RXDR_RXDR_Msk                       /* Receive Data Register */

/*******************  Bit definition for SPI_CRCPOLY register  ********************/
#define SPI_CRCPOLY_CRCPOLY_Pos             (0U)
#define SPI_CRCPOLY_CRCPOLY_Msk             (0xFFFFFFFFUL << SPI_CRCPOLY_CRCPOLY_Pos) /*!< 0xFFFFFFFF */
#define SPI_CRCPOLY_CRCPOLY                 SPI_CRCPOLY_CRCPOLY_Msk                 /* CRC Polynomial register */

/*******************  Bit definition for SPI_TXCRC register  ********************/
#define SPI_TXCRC_TXCRC_Pos                 (0U)
#define SPI_TXCRC_TXCRC_Msk                 (0xFFFFFFFFUL << SPI_TXCRC_TXCRC_Pos)   /*!< 0xFFFFFFFF */
#define SPI_TXCRC_TXCRC                     SPI_TXCRC_TXCRC_Msk                     /* CRCRegister for transmitter */

/*******************  Bit definition for SPI_RXCRC register  ********************/
#define SPI_RXCRC_RXCRC_Pos                 (0U)
#define SPI_RXCRC_RXCRC_Msk                 (0xFFFFFFFFUL << SPI_RXCRC_RXCRC_Pos)   /*!< 0xFFFFFFFF */
#define SPI_RXCRC_RXCRC                     SPI_RXCRC_RXCRC_Msk                     /* CRCRegister for receiver */

/*******************  Bit definition for SPI_UDRDR register  ********************/
#define SPI_UDRDR_UDRDR_Pos                 (0U)
#define SPI_UDRDR_UDRDR_Msk                 (0xFFFFFFFFUL << SPI_UDRDR_UDRDR_Pos)   /*!< 0xFFFFFFFF */
#define SPI_UDRDR_UDRDR                     SPI_UDRDR_UDRDR_Msk                     /* Data at slave underrun condition */


/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_BOOSTEN_Pos            (8U)
#define SYSCFG_CFGR1_BOOSTEN_Msk            (0x1UL << SYSCFG_CFGR1_BOOSTEN_Pos)     /*!< 0x00000100 */
#define SYSCFG_CFGR1_BOOSTEN                SYSCFG_CFGR1_BOOSTEN_Msk                /*!< I/O analog switch voltage booster enable */
#define SYSCFG_CFGR1_ANASWVDD_Pos           (9U)
#define SYSCFG_CFGR1_ANASWVDD_Msk           (0x1UL << SYSCFG_CFGR1_ANASWVDD_Pos)    /*!< 0x00000200 */
#define SYSCFG_CFGR1_ANASWVDD               SYSCFG_CFGR1_ANASWVDD_Msk               /*!< GPIO analog switch control voltage selection */
#define SYSCFG_CFGR1_PA6_FMP_Pos            (16U)
#define SYSCFG_CFGR1_PA6_FMP_Msk            (0x1UL << SYSCFG_CFGR1_PA6_FMP_Pos)     /*!< 0x00010000 */
#define SYSCFG_CFGR1_PA6_FMP                SYSCFG_CFGR1_PA6_FMP_Msk                /*!< I2C PA6 Fast mode plus */
#define SYSCFG_CFGR1_PA7_FMP_Pos            (17U)
#define SYSCFG_CFGR1_PA7_FMP_Msk            (0x1UL << SYSCFG_CFGR1_PA7_FMP_Pos)     /*!< 0x00020000 */
#define SYSCFG_CFGR1_PA7_FMP                SYSCFG_CFGR1_PA7_FMP_Msk                /*!< I2C PA7 Fast mode plus */
#define SYSCFG_CFGR1_PA15_FMP_Pos           (18U)
#define SYSCFG_CFGR1_PA15_FMP_Msk           (0x1UL << SYSCFG_CFGR1_PA15_FMP_Pos)    /*!< 0x00040000 */
#define SYSCFG_CFGR1_PA15_FMP               SYSCFG_CFGR1_PA15_FMP_Msk               /*!< I2C PA15 Fast mode plus */
#define SYSCFG_CFGR1_PB3_FMP_Pos            (19U)
#define SYSCFG_CFGR1_PB3_FMP_Msk            (0x1UL << SYSCFG_CFGR1_PB3_FMP_Pos)     /*!< 0x00080000 */
#define SYSCFG_CFGR1_PB3_FMP                SYSCFG_CFGR1_PB3_FMP_Msk                /*!< I2C PB3 Fast mode plus */

/******************  Bit definition for SYSCFG_FPUIMR register  ***************/
#define SYSCFG_FPUIMR_FPU_IE_Pos            (0U)
#define SYSCFG_FPUIMR_FPU_IE_Msk            (0x3FUL << SYSCFG_FPUIMR_FPU_IE_Pos)    /*!< 0x0000003F - */
#define SYSCFG_FPUIMR_FPU_IE                SYSCFG_FPUIMR_FPU_IE_Msk                /*!<  All FPU interrupts enable */
#define SYSCFG_FPUIMR_FPU_IE_0              (0x1UL << SYSCFG_FPUIMR_FPU_IE_Pos)     /*!< 0x00000001 - Invalid operation Interrupt enable */
#define SYSCFG_FPUIMR_FPU_IE_1              (0x2UL << SYSCFG_FPUIMR_FPU_IE_Pos)     /*!< 0x00000002 - Divide-by-zero Interrupt enable */
#define SYSCFG_FPUIMR_FPU_IE_2              (0x4UL << SYSCFG_FPUIMR_FPU_IE_Pos)     /*!< 0x00000004 - Underflow Interrupt enable */
#define SYSCFG_FPUIMR_FPU_IE_3              (0x8UL << SYSCFG_FPUIMR_FPU_IE_Pos)     /*!< 0x00000008 - Overflow Interrupt enable */
#define SYSCFG_FPUIMR_FPU_IE_4              (0x10UL << SYSCFG_FPUIMR_FPU_IE_Pos)    /*!< 0x00000010 - Input denormal Interrupt enable */
#define SYSCFG_FPUIMR_FPU_IE_5              (0x20UL << SYSCFG_FPUIMR_FPU_IE_Pos)    /*!< 0x00000020 - Inexact Interrupt enable (interrupt disabled at reset) */

/******************  Bit definition for SYSCFG_CNSLCKR register  **************/
#define SYSCFG_CNSLCKR_LOCKNSVTOR_Pos       (0U)
#define SYSCFG_CNSLCKR_LOCKNSVTOR_Msk       (0x1UL << SYSCFG_CNSLCKR_LOCKNSVTOR_Pos) /*!< 0x00000001 */
#define SYSCFG_CNSLCKR_LOCKNSVTOR           SYSCFG_CNSLCKR_LOCKNSVTOR_Msk           /*!< Disable VTOR_NS register writes by SW or debug agent */
#define SYSCFG_CNSLCKR_LOCKNSMPU_Pos        (1U)
#define SYSCFG_CNSLCKR_LOCKNSMPU_Msk        (0x1UL << SYSCFG_CNSLCKR_LOCKNSMPU_Pos) /*!< 0x00000002 */
#define SYSCFG_CNSLCKR_LOCKNSMPU            SYSCFG_CNSLCKR_LOCKNSMPU_Msk            /*!< Disable Non-Secure MPU registers writes by SW or debug agent */

/******************  Bit definition for SYSCFG_CFGR2 register  ****************/
#define SYSCFG_CFGR2_CLL_Pos                (0U)
#define SYSCFG_CFGR2_CLL_Msk                (0x1UL << SYSCFG_CFGR2_CLL_Pos)         /*!< 0x00000001 */
#define SYSCFG_CFGR2_CLL                    SYSCFG_CFGR2_CLL_Msk                    /*!< Core Lockup Lock */
#define SYSCFG_CFGR2_SPL_Pos                (1U)
#define SYSCFG_CFGR2_SPL_Msk                (0x1UL << SYSCFG_CFGR2_SPL_Pos)         /*!< 0x00000002 */
#define SYSCFG_CFGR2_SPL                    SYSCFG_CFGR2_SPL_Msk                    /*!< SRAM Parity Lock */
#define SYSCFG_CFGR2_PVDL_Pos               (2U)
#define SYSCFG_CFGR2_PVDL_Msk               (0x1UL << SYSCFG_CFGR2_PVDL_Pos)        /*!< 0x00000004 */
#define SYSCFG_CFGR2_PVDL                   SYSCFG_CFGR2_PVDL_Msk                   /*!<  PVD Lock */
#define SYSCFG_CFGR2_ECCL_Pos               (3U)
#define SYSCFG_CFGR2_ECCL_Msk               (0x1UL << SYSCFG_CFGR2_ECCL_Pos)        /*!< 0x00000008 */
#define SYSCFG_CFGR2_ECCL                   SYSCFG_CFGR2_ECCL_Msk                   /*!< ECC Lock*/

/******************  Bit definition for SYSCFG_MESR register  ****************/
#define SYSCFG_MESR_MCLR_Pos                (0U)
#define SYSCFG_MESR_MCLR_Msk                (0x1UL << SYSCFG_MESR_MCLR_Pos)         /*!< 0x00000001 */
#define SYSCFG_MESR_MCLR                    SYSCFG_MESR_MCLR_Msk                    /*!< Status of Erase after Reset */
#define SYSCFG_MESR_IPMEE_Pos               (16U)
#define SYSCFG_MESR_IPMEE_Msk               (0x1UL << SYSCFG_MESR_IPMEE_Pos)        /*!< 0x00010000 */
#define SYSCFG_MESR_IPMEE                   SYSCFG_MESR_IPMEE_Msk                   /*!< Status of End of Erase for ICache and PKA RAMs */

/******************  Bit definition for SYSCFG_CCCSR register  ****************/
#define SYSCFG_CCCSR_EN1_Pos                (0U)
#define SYSCFG_CCCSR_EN1_Msk                (0x1UL << SYSCFG_CCCSR_EN1_Pos)         /*!< 0x00000001 */
#define SYSCFG_CCCSR_EN1                    SYSCFG_CCCSR_EN1_Msk                    /*!< Enable compensation cell for VDD power rail */
#define SYSCFG_CCCSR_CS1_Pos                (1U)
#define SYSCFG_CCCSR_CS1_Msk                (0x1UL << SYSCFG_CCCSR_CS1_Pos)         /*!< 0x00000002 */
#define SYSCFG_CCCSR_CS1                    SYSCFG_CCCSR_CS1_Msk                    /*!< Code selection for VDD power rail */
#define SYSCFG_CCCSR_RDY1_Pos               (8U)
#define SYSCFG_CCCSR_RDY1_Msk               (0x1UL << SYSCFG_CCCSR_RDY1_Pos)        /*!< 0x00000100 */
#define SYSCFG_CCCSR_RDY1                   SYSCFG_CCCSR_RDY1_Msk                   /*!< VDD compensation cell ready flag */

/******************  Bit definition for SYSCFG_CCVR register  ****************/
#define SYSCFG_CCVR_NCV1_Pos                (0U)
#define SYSCFG_CCVR_NCV1_Msk                (0xFUL << SYSCFG_CCVR_NCV1_Pos)         /*!< 0x0000000F */
#define SYSCFG_CCVR_NCV1                    SYSCFG_CCVR_NCV1_Msk                    /*!< NMOS compensation value for VDD Power Rail */
#define SYSCFG_CCVR_PCV1_Pos                (4U)
#define SYSCFG_CCVR_PCV1_Msk                (0xFUL << SYSCFG_CCVR_PCV1_Pos)         /*!< 0x000000F0 */
#define SYSCFG_CCVR_PCV1                    SYSCFG_CCVR_PCV1_Msk                    /*!< PMOS compensation value for VDD Power Rail */

/******************  Bit definition for SYSCFG_CCCR register  ****************/
#define SYSCFG_CCCR_NCC1_Pos                (0U)
#define SYSCFG_CCCR_NCC1_Msk                (0xFUL << SYSCFG_CCCR_NCC1_Pos)         /*!< 0x0000000F */
#define SYSCFG_CCCR_NCC1                    SYSCFG_CCCR_NCC1_Msk                    /*!< NMOS compensation code for VDD Power Rail */
#define SYSCFG_CCCR_PCC1_Pos                (4U)
#define SYSCFG_CCCR_PCC1_Msk                (0xFUL << SYSCFG_CCCR_PCC1_Pos)         /*!< 0x000000F0 */
#define SYSCFG_CCCR_PCC1                    SYSCFG_CCCR_PCC1_Msk                    /*!< PMOS compensation code for VDD Power Rail */


/******************************************************************************/
/*                                                                            */
/*                     Tamper and backup register (TAMP)                      */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for TAMP_CR1 register  *****************/
#define TAMP_CR1_TAMP1E_Pos                 (0U)
#define TAMP_CR1_TAMP1E_Msk                 (0x1UL << TAMP_CR1_TAMP1E_Pos)          /*!< 0x00000001 */
#define TAMP_CR1_TAMP1E                     TAMP_CR1_TAMP1E_Msk
#define TAMP_CR1_TAMP2E_Pos                 (1U)
#define TAMP_CR1_TAMP2E_Msk                 (0x1UL << TAMP_CR1_TAMP2E_Pos)          /*!< 0x00000002 */
#define TAMP_CR1_TAMP2E                     TAMP_CR1_TAMP2E_Msk
#define TAMP_CR1_TAMP3E_Pos                 (2U)
#define TAMP_CR1_TAMP3E_Msk                 (0x1UL << TAMP_CR1_TAMP3E_Pos)          /*!< 0x00000004 */
#define TAMP_CR1_TAMP3E                     TAMP_CR1_TAMP3E_Msk
#define TAMP_CR1_ITAMP3E_Pos                (18U)
#define TAMP_CR1_ITAMP3E_Msk                (0x1UL << TAMP_CR1_ITAMP3E_Pos)         /*!< 0x00040000 */
#define TAMP_CR1_ITAMP3E                    TAMP_CR1_ITAMP3E_Msk
#define TAMP_CR1_ITAMP5E_Pos                (20U)
#define TAMP_CR1_ITAMP5E_Msk                (0x1UL << TAMP_CR1_ITAMP5E_Pos)         /*!< 0x00100000 */
#define TAMP_CR1_ITAMP5E                    TAMP_CR1_ITAMP5E_Msk
#define TAMP_CR1_ITAMP6E_Pos                (21U)
#define TAMP_CR1_ITAMP6E_Msk                (0x1UL << TAMP_CR1_ITAMP6E_Pos)         /*!< 0x00200000 */
#define TAMP_CR1_ITAMP6E                    TAMP_CR1_ITAMP6E_Msk
#define TAMP_CR1_ITAMP7E_Pos                (22U)
#define TAMP_CR1_ITAMP7E_Msk                (0x1UL << TAMP_CR1_ITAMP7E_Pos)         /*!< 0x00400000 */
#define TAMP_CR1_ITAMP7E                    TAMP_CR1_ITAMP7E_Msk
#define TAMP_CR1_ITAMP8E_Pos                (23U)
#define TAMP_CR1_ITAMP8E_Msk                (0x1UL << TAMP_CR1_ITAMP8E_Pos)         /*!< 0x00800000 */
#define TAMP_CR1_ITAMP8E                    TAMP_CR1_ITAMP8E_Msk
#define TAMP_CR1_ITAMP9E_Pos                (24U)
#define TAMP_CR1_ITAMP9E_Msk                (0x1UL << TAMP_CR1_ITAMP9E_Pos)         /*!< 0x01000000 */
#define TAMP_CR1_ITAMP9E                    TAMP_CR1_ITAMP9E_Msk
#define TAMP_CR1_ITAMP11E_Pos               (26U)
#define TAMP_CR1_ITAMP11E_Msk               (0x1UL << TAMP_CR1_ITAMP11E_Pos)        /*!< 0x04000000 */
#define TAMP_CR1_ITAMP11E                   TAMP_CR1_ITAMP11E_Msk
#define TAMP_CR1_ITAMP12E_Pos               (27U)
#define TAMP_CR1_ITAMP12E_Msk               (0x1UL << TAMP_CR1_ITAMP12E_Pos)        /*!< 0x08000000 */
#define TAMP_CR1_ITAMP12E                   TAMP_CR1_ITAMP12E_Msk
#define TAMP_CR1_ITAMP13E_Pos               (28U)
#define TAMP_CR1_ITAMP13E_Msk               (0x1UL << TAMP_CR1_ITAMP13E_Pos)        /*!< 0x10000000 */
#define TAMP_CR1_ITAMP13E                   TAMP_CR1_ITAMP13E_Msk

/********************  Bits definition for TAMP_CR2 register  *****************/
#define TAMP_CR2_TAMP1POM_Pos               (0U)
#define TAMP_CR2_TAMP1POM_Msk               (0x1UL << TAMP_CR2_TAMP1POM_Pos)    /*!< 0x00000001 */
#define TAMP_CR2_TAMP1POM                   TAMP_CR2_TAMP1POM_Msk
#define TAMP_CR2_TAMP2POM_Pos               (1U)
#define TAMP_CR2_TAMP2POM_Msk               (0x1UL << TAMP_CR2_TAMP2POM_Pos)    /*!< 0x00000002 */
#define TAMP_CR2_TAMP2POM                   TAMP_CR2_TAMP2POM_Msk
#define TAMP_CR2_TAMP3POM_Pos               (2U)
#define TAMP_CR2_TAMP3POM_Msk               (0x1UL << TAMP_CR2_TAMP3POM_Pos)    /*!< 0x00000004 */
#define TAMP_CR2_TAMP3POM                   TAMP_CR2_TAMP3POM_Msk
#define TAMP_CR2_TAMP1MSK_Pos               (16U)
#define TAMP_CR2_TAMP1MSK_Msk               (0x1UL << TAMP_CR2_TAMP1MSK_Pos)        /*!< 0x00010000 */
#define TAMP_CR2_TAMP1MSK                   TAMP_CR2_TAMP1MSK_Msk
#define TAMP_CR2_TAMP2MSK_Pos               (17U)
#define TAMP_CR2_TAMP2MSK_Msk               (0x1UL << TAMP_CR2_TAMP2MSK_Pos)        /*!< 0x00020000 */
#define TAMP_CR2_TAMP2MSK                   TAMP_CR2_TAMP2MSK_Msk
#define TAMP_CR2_TAMP3MSK_Pos               (18U)
#define TAMP_CR2_TAMP3MSK_Msk               (0x1UL << TAMP_CR2_TAMP3MSK_Pos)        /*!< 0x00040000 */
#define TAMP_CR2_TAMP3MSK                   TAMP_CR2_TAMP3MSK_Msk
#define TAMP_CR2_BKBLOCK_Pos                (22U)
#define TAMP_CR2_BKBLOCK_Msk                (0x1UL << TAMP_CR2_BKBLOCK_Pos)         /*!< 0x00400000 */
#define TAMP_CR2_BKBLOCK                    TAMP_CR2_BKBLOCK_Msk
#define TAMP_CR2_BKERASE_Pos                (23U)
#define TAMP_CR2_BKERASE_Msk                (0x1UL << TAMP_CR2_BKERASE_Pos)         /*!< 0x00800000 */
#define TAMP_CR2_BKERASE                    TAMP_CR2_BKERASE_Msk
#define TAMP_CR2_TAMP1TRG_Pos               (24U)
#define TAMP_CR2_TAMP1TRG_Msk               (0x1UL << TAMP_CR2_TAMP1TRG_Pos)        /*!< 0x01000000 */
#define TAMP_CR2_TAMP1TRG                   TAMP_CR2_TAMP1TRG_Msk
#define TAMP_CR2_TAMP2TRG_Pos               (25U)
#define TAMP_CR2_TAMP2TRG_Msk               (0x1UL << TAMP_CR2_TAMP2TRG_Pos)        /*!< 0x02000000 */
#define TAMP_CR2_TAMP2TRG                   TAMP_CR2_TAMP2TRG_Msk
#define TAMP_CR2_TAMP3TRG_Pos               (26U)
#define TAMP_CR2_TAMP3TRG_Msk               (0x1UL << TAMP_CR2_TAMP3TRG_Pos)        /*!< 0x02000000 */
#define TAMP_CR2_TAMP3TRG                   TAMP_CR2_TAMP3TRG_Msk

/********************  Bits definition for TAMP_CR3 register  *****************/
#define TAMP_CR3_ITAMP3POM_Pos              (2U)
#define TAMP_CR3_ITAMP3POM_Msk              (0x1UL << TAMP_CR3_ITAMP3POM_Pos)      /*!< 0x00000004 */
#define TAMP_CR3_ITAMP3POM                  TAMP_CR3_ITAMP3POM_Msk
#define TAMP_CR3_ITAMP5POM_Pos              (4U)
#define TAMP_CR3_ITAMP5POM_Msk              (0x1UL << TAMP_CR3_ITAMP5POM_Pos)      /*!< 0x00000010 */
#define TAMP_CR3_ITAMP5POM                  TAMP_CR3_ITAMP5POM_Msk
#define TAMP_CR3_ITAMP6POM_Pos              (5U)
#define TAMP_CR3_ITAMP6POM_Msk              (0x1UL << TAMP_CR3_ITAMP6POM_Pos)      /*!< 0x00000020 */
#define TAMP_CR3_ITAMP6POM                  TAMP_CR3_ITAMP6POM_Msk
#define TAMP_CR3_ITAMP7POM_Pos              (6U)
#define TAMP_CR3_ITAMP7POM_Msk              (0x1UL << TAMP_CR3_ITAMP7POM_Pos)      /*!< 0x00000040 */
#define TAMP_CR3_ITAMP7POM                  TAMP_CR3_ITAMP7POM_Msk
#define TAMP_CR3_ITAMP8POM_Pos              (7U)
#define TAMP_CR3_ITAMP8POM_Msk              (0x1UL << TAMP_CR3_ITAMP8POM_Pos)      /*!< 0x00000080 */
#define TAMP_CR3_ITAMP8POM                  TAMP_CR3_ITAMP8POM_Msk
#define TAMP_CR3_ITAMP9POM_Pos              (8U)
#define TAMP_CR3_ITAMP9POM_Msk              (0x1UL << TAMP_CR3_ITAMP9POM_Pos)      /*!< 0x00000100 */
#define TAMP_CR3_ITAMP9POM                  TAMP_CR3_ITAMP9POM_Msk
#define TAMP_CR3_ITAMP11POM_Pos             (10U)
#define TAMP_CR3_ITAMP11POM_Msk             (0x1UL << TAMP_CR3_ITAMP11POM_Pos)     /*!< 0x00000400 */
#define TAMP_CR3_ITAMP11POM                 TAMP_CR3_ITAMP11POM_Msk
#define TAMP_CR3_ITAMP12POM_Pos             (11U)
#define TAMP_CR3_ITAMP12POM_Msk             (0x1UL << TAMP_CR3_ITAMP12POM_Pos)     /*!< 0x00000800 */
#define TAMP_CR3_ITAMP12POM                 TAMP_CR3_ITAMP12POM_Msk
#define TAMP_CR3_ITAMP13POM_Pos             (12U)
#define TAMP_CR3_ITAMP13POM_Msk             (0x1UL << TAMP_CR3_ITAMP13POM_Pos)     /*!< 0x00001000 */
#define TAMP_CR3_ITAMP13POM                 TAMP_CR3_ITAMP13POM_Msk

/********************  Bits definition for TAMP_FLTCR register  ***************/
#define TAMP_FLTCR_TAMPFREQ_Pos             (0U)
#define TAMP_FLTCR_TAMPFREQ_Msk             (0x7UL << TAMP_FLTCR_TAMPFREQ_Pos)      /*!< 0x00000007 */
#define TAMP_FLTCR_TAMPFREQ                 TAMP_FLTCR_TAMPFREQ_Msk
#define TAMP_FLTCR_TAMPFREQ_0               (0x1UL << TAMP_FLTCR_TAMPFREQ_Pos)      /*!< 0x00000001 */
#define TAMP_FLTCR_TAMPFREQ_1               (0x2UL << TAMP_FLTCR_TAMPFREQ_Pos)      /*!< 0x00000002 */
#define TAMP_FLTCR_TAMPFREQ_2               (0x4UL << TAMP_FLTCR_TAMPFREQ_Pos)      /*!< 0x00000004 */
#define TAMP_FLTCR_TAMPFLT_Pos              (3U)
#define TAMP_FLTCR_TAMPFLT_Msk              (0x3UL << TAMP_FLTCR_TAMPFLT_Pos)       /*!< 0x00000018 */
#define TAMP_FLTCR_TAMPFLT                  TAMP_FLTCR_TAMPFLT_Msk
#define TAMP_FLTCR_TAMPFLT_0                (0x1UL << TAMP_FLTCR_TAMPFLT_Pos)       /*!< 0x00000008 */
#define TAMP_FLTCR_TAMPFLT_1                (0x2UL << TAMP_FLTCR_TAMPFLT_Pos)       /*!< 0x00000010 */
#define TAMP_FLTCR_TAMPPRCH_Pos             (5U)
#define TAMP_FLTCR_TAMPPRCH_Msk             (0x3UL << TAMP_FLTCR_TAMPPRCH_Pos)      /*!< 0x00000060 */
#define TAMP_FLTCR_TAMPPRCH                 TAMP_FLTCR_TAMPPRCH_Msk
#define TAMP_FLTCR_TAMPPRCH_0               (0x1UL << TAMP_FLTCR_TAMPPRCH_Pos)      /*!< 0x00000020 */
#define TAMP_FLTCR_TAMPPRCH_1               (0x2UL << TAMP_FLTCR_TAMPPRCH_Pos)      /*!< 0x00000040 */
#define TAMP_FLTCR_TAMPPUDIS_Pos            (7U)
#define TAMP_FLTCR_TAMPPUDIS_Msk            (0x1UL << TAMP_FLTCR_TAMPPUDIS_Pos)     /*!< 0x00000080 */
#define TAMP_FLTCR_TAMPPUDIS                TAMP_FLTCR_TAMPPUDIS_Msk

/********************  Bits definition for TAMP_ATCR1 register  ***************/
#define TAMP_ATCR1_TAMP1AM_Pos              (0U)
#define TAMP_ATCR1_TAMP1AM_Msk              (0x1UL << TAMP_ATCR1_TAMP1AM_Pos)       /*!< 0x00000001 */
#define TAMP_ATCR1_TAMP1AM                  TAMP_ATCR1_TAMP1AM_Msk
#define TAMP_ATCR1_TAMP2AM_Pos              (1U)
#define TAMP_ATCR1_TAMP2AM_Msk              (0x1UL << TAMP_ATCR1_TAMP2AM_Pos)       /*!< 0x00000002 */
#define TAMP_ATCR1_TAMP2AM                  TAMP_ATCR1_TAMP2AM_Msk
#define TAMP_ATCR1_TAMP3AM_Pos              (2U)
#define TAMP_ATCR1_TAMP3AM_Msk              (0x1UL << TAMP_ATCR1_TAMP3AM_Pos)       /*!< 0x00000004 */
#define TAMP_ATCR1_TAMP3AM                  TAMP_ATCR1_TAMP3AM_Msk
#define TAMP_ATCR1_ATOSEL1_Pos              (8U)
#define TAMP_ATCR1_ATOSEL1_Msk              (0x3UL << TAMP_ATCR1_ATOSEL1_Pos)       /*!< 0x00000300 */
#define TAMP_ATCR1_ATOSEL1                  TAMP_ATCR1_ATOSEL1_Msk
#define TAMP_ATCR1_ATOSEL1_0                (0x1UL << TAMP_ATCR1_ATOSEL1_Pos)       /*!< 0x00000100 */
#define TAMP_ATCR1_ATOSEL1_1                (0x2UL << TAMP_ATCR1_ATOSEL1_Pos)       /*!< 0x00000200 */
#define TAMP_ATCR1_ATOSEL2_Pos              (10U)
#define TAMP_ATCR1_ATOSEL2_Msk              (0x3UL << TAMP_ATCR1_ATOSEL2_Pos)       /*!< 0x00000C00 */
#define TAMP_ATCR1_ATOSEL2                  TAMP_ATCR1_ATOSEL2_Msk
#define TAMP_ATCR1_ATOSEL2_0                (0x1UL << TAMP_ATCR1_ATOSEL2_Pos)       /*!< 0x00000400 */
#define TAMP_ATCR1_ATOSEL2_1                (0x2UL << TAMP_ATCR1_ATOSEL2_Pos)       /*!< 0x00000800 */
#define TAMP_ATCR1_ATOSEL3_Pos              (12U)
#define TAMP_ATCR1_ATOSEL3_Msk              (0x3UL << TAMP_ATCR1_ATOSEL3_Pos)       /*!< 0x00003000 */
#define TAMP_ATCR1_ATOSEL3                  TAMP_ATCR1_ATOSEL3_Msk
#define TAMP_ATCR1_ATOSEL3_0                (0x1UL << TAMP_ATCR1_ATOSEL3_Pos)       /*!< 0x00001000 */
#define TAMP_ATCR1_ATOSEL3_1                (0x2UL << TAMP_ATCR1_ATOSEL3_Pos)       /*!< 0x00002000 */
#define TAMP_ATCR1_ATCKSEL_Pos              (16U)
#define TAMP_ATCR1_ATCKSEL_Msk              (0x7UL << TAMP_ATCR1_ATCKSEL_Pos)       /*!< 0x00070000 */
#define TAMP_ATCR1_ATCKSEL                  TAMP_ATCR1_ATCKSEL_Msk
#define TAMP_ATCR1_ATCKSEL_0                (0x1UL << TAMP_ATCR1_ATCKSEL_Pos)       /*!< 0x00010000 */
#define TAMP_ATCR1_ATCKSEL_1                (0x2UL << TAMP_ATCR1_ATCKSEL_Pos)       /*!< 0x00020000 */
#define TAMP_ATCR1_ATCKSEL_2                (0x4UL << TAMP_ATCR1_ATCKSEL_Pos)       /*!< 0x00040000 */
#define TAMP_ATCR1_ATPER_Pos                (24U)
#define TAMP_ATCR1_ATPER_Msk                (0x7UL << TAMP_ATCR1_ATPER_Pos)         /*!< 0x07000000 */
#define TAMP_ATCR1_ATPER                    TAMP_ATCR1_ATPER_Msk
#define TAMP_ATCR1_ATPER_0                  (0x1UL << TAMP_ATCR1_ATPER_Pos)         /*!< 0x01000000 */
#define TAMP_ATCR1_ATPER_1                  (0x2UL << TAMP_ATCR1_ATPER_Pos)         /*!< 0x02000000 */
#define TAMP_ATCR1_ATPER_2                  (0x4UL << TAMP_ATCR1_ATPER_Pos)         /*!< 0x04000000 */
#define TAMP_ATCR1_ATOSHARE_Pos             (30U)
#define TAMP_ATCR1_ATOSHARE_Msk             (0x1UL << TAMP_ATCR1_ATOSHARE_Pos)      /*!< 0x40000000 */
#define TAMP_ATCR1_ATOSHARE                 TAMP_ATCR1_ATOSHARE_Msk
#define TAMP_ATCR1_FLTEN_Pos                (31U)
#define TAMP_ATCR1_FLTEN_Msk                (0x1UL << TAMP_ATCR1_FLTEN_Pos)         /*!< 0x80000000 */
#define TAMP_ATCR1_FLTEN                    TAMP_ATCR1_FLTEN_Msk

/********************  Bits definition for TAMP_ATSEEDR register  ******************/
#define TAMP_ATSEEDR_SEED_Pos               (0U)
#define TAMP_ATSEEDR_SEED_Msk               (0xFFFFFFFFUL << TAMP_ATSEEDR_SEED_Pos) /*!< 0xFFFFFFFF */
#define TAMP_ATSEEDR_SEED                   TAMP_ATSEEDR_SEED_Msk

/********************  Bits definition for TAMP_ATOR register  ******************/
#define TAMP_ATOR_PRNG_Pos                  (0U)
#define TAMP_ATOR_PRNG_Msk                  (0xFF << TAMP_ATOR_PRNG_Pos)            /*!< 0x000000FF */
#define TAMP_ATOR_PRNG                      TAMP_ATOR_PRNG_Msk
#define TAMP_ATOR_PRNG_0                    (0x1UL << TAMP_ATOR_PRNG_Pos)           /*!< 0x00000001 */
#define TAMP_ATOR_PRNG_1                    (0x2UL << TAMP_ATOR_PRNG_Pos)           /*!< 0x00000002 */
#define TAMP_ATOR_PRNG_2                    (0x4UL << TAMP_ATOR_PRNG_Pos)           /*!< 0x00000004 */
#define TAMP_ATOR_PRNG_3                    (0x8UL << TAMP_ATOR_PRNG_Pos)           /*!< 0x00000008 */
#define TAMP_ATOR_PRNG_4                    (0x10UL << TAMP_ATOR_PRNG_Pos)          /*!< 0x00000010 */
#define TAMP_ATOR_PRNG_5                    (0x20UL << TAMP_ATOR_PRNG_Pos)          /*!< 0x00000020 */
#define TAMP_ATOR_PRNG_6                    (0x40UL << TAMP_ATOR_PRNG_Pos)          /*!< 0x00000040 */
#define TAMP_ATOR_PRNG_7                    (0x80UL << TAMP_ATOR_PRNG_Pos)          /*!< 0x00000080 */
#define TAMP_ATOR_SEEDF_Pos                 (14U)
#define TAMP_ATOR_SEEDF_Msk                 (1UL << TAMP_ATOR_SEEDF_Pos)            /*!< 0x00004000 */
#define TAMP_ATOR_SEEDF                     TAMP_ATOR_SEEDF_Msk
#define TAMP_ATOR_INITS_Pos                 (15U)
#define TAMP_ATOR_INITS_Msk                 (1UL << TAMP_ATOR_INITS_Pos)            /*!< 0x00008000 */
#define TAMP_ATOR_INITS                     TAMP_ATOR_INITS_Msk

/********************  Bits definition for TAMP_ATCR2 register  ***************/
#define TAMP_ATCR2_ATOSEL1_Pos              (8U)
#define TAMP_ATCR2_ATOSEL1_Msk              (0x7UL << TAMP_ATCR2_ATOSEL1_Pos)       /*!< 0x00000700 */
#define TAMP_ATCR2_ATOSEL1                  TAMP_ATCR2_ATOSEL1_Msk
#define TAMP_ATCR2_ATOSEL1_0                (0x1UL << TAMP_ATCR2_ATOSEL1_Pos)       /*!< 0x00000100 */
#define TAMP_ATCR2_ATOSEL1_1                (0x2UL << TAMP_ATCR2_ATOSEL1_Pos)       /*!< 0x00000200 */
#define TAMP_ATCR2_ATOSEL1_2                (0x4UL << TAMP_ATCR2_ATOSEL1_Pos)       /*!< 0x00000400 */
#define TAMP_ATCR2_ATOSEL2_Pos              (11U)
#define TAMP_ATCR2_ATOSEL2_Msk              (0x7UL << TAMP_ATCR2_ATOSEL2_Pos)       /*!< 0x00003800 */
#define TAMP_ATCR2_ATOSEL2                  TAMP_ATCR2_ATOSEL2_Msk
#define TAMP_ATCR2_ATOSEL2_0                (0x1UL << TAMP_ATCR2_ATOSEL2_Pos)       /*!< 0x00000800 */
#define TAMP_ATCR2_ATOSEL2_1                (0x2UL << TAMP_ATCR2_ATOSEL2_Pos)       /*!< 0x00001000 */
#define TAMP_ATCR2_ATOSEL2_2                (0x4UL << TAMP_ATCR2_ATOSEL2_Pos)       /*!< 0x00002000 */
#define TAMP_ATCR2_ATOSEL3_Pos              (14U)
#define TAMP_ATCR2_ATOSEL3_Msk              (0x7UL << TAMP_ATCR2_ATOSEL3_Pos)       /*!< 0x0001C000 */
#define TAMP_ATCR2_ATOSEL3                  TAMP_ATCR2_ATOSEL3_Msk
#define TAMP_ATCR2_ATOSEL3_0                (0x1UL << TAMP_ATCR2_ATOSEL3_Pos)       /*!< 0x00004000 */
#define TAMP_ATCR2_ATOSEL3_1                (0x2UL << TAMP_ATCR2_ATOSEL3_Pos)       /*!< 0x00008000 */
#define TAMP_ATCR2_ATOSEL3_2                (0x4UL << TAMP_ATCR2_ATOSEL3_Pos)       /*!< 0x00010000 */
#define TAMP_ATCR2_ATOSEL4_Pos              (17U)
#define TAMP_ATCR2_ATOSEL4_Msk              (0x7UL << TAMP_ATCR2_ATOSEL4_Pos)       /*!< 0x000E0000 */
#define TAMP_ATCR2_ATOSEL4                  TAMP_ATCR2_ATOSEL4_Msk
#define TAMP_ATCR2_ATOSEL4_0                (0x1UL << TAMP_ATCR2_ATOSEL4_Pos)       /*!< 0x00020000 */
#define TAMP_ATCR2_ATOSEL4_1                (0x2UL << TAMP_ATCR2_ATOSEL4_Pos)       /*!< 0x00040000 */
#define TAMP_ATCR2_ATOSEL4_2                (0x4UL << TAMP_ATCR2_ATOSEL4_Pos)       /*!< 0x00080000 */
#define TAMP_ATCR2_ATOSEL5_Pos              (20U)
#define TAMP_ATCR2_ATOSEL5_Msk              (0x7UL << TAMP_ATCR2_ATOSEL5_Pos)       /*!< 0x00700000 */
#define TAMP_ATCR2_ATOSEL5                  TAMP_ATCR2_ATOSEL5_Msk
#define TAMP_ATCR2_ATOSEL5_0                (0x1UL << TAMP_ATCR2_ATOSEL5_Pos)       /*!< 0x00100000 */
#define TAMP_ATCR2_ATOSEL5_1                (0x2UL << TAMP_ATCR2_ATOSEL5_Pos)       /*!< 0x00200000 */
#define TAMP_ATCR2_ATOSEL5_2                (0x4UL << TAMP_ATCR2_ATOSEL5_Pos)       /*!< 0x00400000 */
#define TAMP_ATCR2_ATOSEL6_Pos              (23U)
#define TAMP_ATCR2_ATOSEL6_Msk              (0x7UL << TAMP_ATCR2_ATOSEL6_Pos)       /*!< 0x03800000 */
#define TAMP_ATCR2_ATOSEL6                  TAMP_ATCR2_ATOSEL6_Msk
#define TAMP_ATCR2_ATOSEL6_0                (0x1UL << TAMP_ATCR2_ATOSEL6_Pos)       /*!< 0x00800000 */
#define TAMP_ATCR2_ATOSEL6_1                (0x2UL << TAMP_ATCR2_ATOSEL6_Pos)       /*!< 0x01000000 */
#define TAMP_ATCR2_ATOSEL6_2                (0x4UL << TAMP_ATCR2_ATOSEL6_Pos)       /*!< 0x02000000 */

/********************  Bits definition for TAMP_IER register  *****************/
#define TAMP_IER_TAMP1IE_Pos                (0U)
#define TAMP_IER_TAMP1IE_Msk                (0x1UL << TAMP_IER_TAMP1IE_Pos)         /*!< 0x00000001 */
#define TAMP_IER_TAMP1IE                    TAMP_IER_TAMP1IE_Msk
#define TAMP_IER_TAMP2IE_Pos                (1U)
#define TAMP_IER_TAMP2IE_Msk                (0x1UL << TAMP_IER_TAMP2IE_Pos)         /*!< 0x00000002 */
#define TAMP_IER_TAMP2IE                    TAMP_IER_TAMP2IE_Msk
#define TAMP_IER_TAMP3IE_Pos                (2U)
#define TAMP_IER_TAMP3IE_Msk                (0x1UL << TAMP_IER_TAMP3IE_Pos)         /*!< 0x00000004 */
#define TAMP_IER_TAMP3IE                    TAMP_IER_TAMP3IE_Msk
#define TAMP_IER_ITAMP3IE_Pos               (18U)
#define TAMP_IER_ITAMP3IE_Msk               (0x1UL << TAMP_IER_ITAMP3IE_Pos)        /*!< 0x00040000 */
#define TAMP_IER_ITAMP3IE                   TAMP_IER_ITAMP3IE_Msk
#define TAMP_IER_ITAMP5IE_Pos               (20U)
#define TAMP_IER_ITAMP5IE_Msk               (0x1UL << TAMP_IER_ITAMP5IE_Pos)        /*!< 0x00100000 */
#define TAMP_IER_ITAMP5IE                   TAMP_IER_ITAMP5IE_Msk
#define TAMP_IER_ITAMP6IE_Pos               (21U)
#define TAMP_IER_ITAMP6IE_Msk               (0x1UL << TAMP_IER_ITAMP6IE_Pos)        /*!< 0x00200000 */
#define TAMP_IER_ITAMP6IE                   TAMP_IER_ITAMP6IE_Msk
#define TAMP_IER_ITAMP7IE_Pos               (22U)
#define TAMP_IER_ITAMP7IE_Msk               (0x1UL << TAMP_IER_ITAMP7IE_Pos)        /*!< 0x00400000 */
#define TAMP_IER_ITAMP7IE                   TAMP_IER_ITAMP7IE_Msk
#define TAMP_IER_ITAMP8IE_Pos               (23U)
#define TAMP_IER_ITAMP8IE_Msk               (0x1UL << TAMP_IER_ITAMP8IE_Pos)        /*!< 0x00800000 */
#define TAMP_IER_ITAMP8IE                   TAMP_IER_ITAMP8IE_Msk
#define TAMP_IER_ITAMP9IE_Pos               (24U)
#define TAMP_IER_ITAMP9IE_Msk               (0x1UL << TAMP_IER_ITAMP9IE_Pos)        /*!< 0x01000000 */
#define TAMP_IER_ITAMP9IE                   TAMP_IER_ITAMP9IE_Msk
#define TAMP_IER_ITAMP11IE_Pos              (26U)
#define TAMP_IER_ITAMP11IE_Msk              (0x1UL << TAMP_IER_ITAMP11IE_Pos)       /*!< 0x04000000 */
#define TAMP_IER_ITAMP11IE                  TAMP_IER_ITAMP11IE_Msk
#define TAMP_IER_ITAMP12IE_Pos              (27U)
#define TAMP_IER_ITAMP12IE_Msk              (0x1UL << TAMP_IER_ITAMP12IE_Pos)       /*!< 0x08000000 */
#define TAMP_IER_ITAMP12IE                  TAMP_IER_ITAMP12IE_Msk
#define TAMP_IER_ITAMP13IE_Pos              (28U)
#define TAMP_IER_ITAMP13IE_Msk              (0x1UL << TAMP_IER_ITAMP13IE_Pos)       /*!< 0x10000000 */
#define TAMP_IER_ITAMP13IE                  TAMP_IER_ITAMP13IE_Msk

/********************  Bits definition for TAMP_SR register  *****************/
#define TAMP_SR_TAMP1F_Pos                  (0U)
#define TAMP_SR_TAMP1F_Msk                  (0x1UL << TAMP_SR_TAMP1F_Pos)           /*!< 0x00000001 */
#define TAMP_SR_TAMP1F                      TAMP_SR_TAMP1F_Msk
#define TAMP_SR_TAMP2F_Pos                  (1U)
#define TAMP_SR_TAMP2F_Msk                  (0x1UL << TAMP_SR_TAMP2F_Pos)           /*!< 0x00000002 */
#define TAMP_SR_TAMP2F                      TAMP_SR_TAMP2F_Msk
#define TAMP_SR_TAMP3F_Pos                  (2U)
#define TAMP_SR_TAMP3F_Msk                  (0x1UL << TAMP_SR_TAMP3F_Pos)           /*!< 0x00000004 */
#define TAMP_SR_TAMP3F                      TAMP_SR_TAMP3F_Msk
#define TAMP_SR_ITAMP3F_Pos                 (18U)
#define TAMP_SR_ITAMP3F_Msk                 (0x1UL << TAMP_SR_ITAMP3F_Pos)          /*!< 0x00040000 */
#define TAMP_SR_ITAMP3F                     TAMP_SR_ITAMP3F_Msk
#define TAMP_SR_ITAMP5F_Pos                 (20U)
#define TAMP_SR_ITAMP5F_Msk                 (0x1UL << TAMP_SR_ITAMP5F_Pos)          /*!< 0x00100000 */
#define TAMP_SR_ITAMP5F                     TAMP_SR_ITAMP5F_Msk
#define TAMP_SR_ITAMP6F_Pos                 (21U)
#define TAMP_SR_ITAMP6F_Msk                 (0x1UL << TAMP_SR_ITAMP6F_Pos)          /*!< 0x00200000 */
#define TAMP_SR_ITAMP6F                     TAMP_SR_ITAMP6F_Msk
#define TAMP_SR_ITAMP7F_Pos                 (22U)
#define TAMP_SR_ITAMP7F_Msk                 (0x1UL << TAMP_SR_ITAMP7F_Pos)          /*!< 0x00400000 */
#define TAMP_SR_ITAMP7F                     TAMP_SR_ITAMP7F_Msk
#define TAMP_SR_ITAMP8F_Pos                 (23U)
#define TAMP_SR_ITAMP8F_Msk                 (0x1UL << TAMP_SR_ITAMP8F_Pos)          /*!< 0x00800000 */
#define TAMP_SR_ITAMP8F                     TAMP_SR_ITAMP8F_Msk
#define TAMP_SR_ITAMP9F_Pos                 (24U)
#define TAMP_SR_ITAMP9F_Msk                 (0x1UL << TAMP_SR_ITAMP9F_Pos)          /*!< 0x01000000 */
#define TAMP_SR_ITAMP9F                     TAMP_SR_ITAMP9F_Msk
#define TAMP_SR_ITAMP11F_Pos                (26U)
#define TAMP_SR_ITAMP11F_Msk                (0x1UL << TAMP_SR_ITAMP11F_Pos)         /*!< 0x04000000 */
#define TAMP_SR_ITAMP11F                    TAMP_SR_ITAMP11F_Msk
#define TAMP_SR_ITAMP12F_Pos                (27U)
#define TAMP_SR_ITAMP12F_Msk                (0x1UL << TAMP_SR_ITAMP12F_Pos)         /*!< 0x08000000 */
#define TAMP_SR_ITAMP12F                    TAMP_SR_ITAMP12F_Msk
#define TAMP_SR_ITAMP13F_Pos                (28U)
#define TAMP_SR_ITAMP13F_Msk                (0x1UL << TAMP_SR_ITAMP13F_Pos)         /*!< 0x10000000 */
#define TAMP_SR_ITAMP13F                    TAMP_SR_ITAMP13F_Msk

/********************  Bits definition for TAMP_MISR register  ****************/
#define TAMP_MISR_TAMP1MF_Pos               (0U)
#define TAMP_MISR_TAMP1MF_Msk               (0x1UL << TAMP_MISR_TAMP1MF_Pos)        /*!< 0x00000001 */
#define TAMP_MISR_TAMP1MF                   TAMP_MISR_TAMP1MF_Msk
#define TAMP_MISR_TAMP2MF_Pos               (1U)
#define TAMP_MISR_TAMP2MF_Msk               (0x1UL << TAMP_MISR_TAMP2MF_Pos)        /*!< 0x00000002 */
#define TAMP_MISR_TAMP2MF                   TAMP_MISR_TAMP2MF_Msk
#define TAMP_MISR_TAMP3MF_Pos               (2U)
#define TAMP_MISR_TAMP3MF_Msk               (0x1UL << TAMP_MISR_TAMP3MF_Pos)        /*!< 0x00000004 */
#define TAMP_MISR_TAMP3MF                   TAMP_MISR_TAMP3MF_Msk
#define TAMP_MISR_ITAMP3MF_Pos              (18U)
#define TAMP_MISR_ITAMP3MF_Msk              (0x1UL << TAMP_MISR_ITAMP3MF_Pos)       /*!< 0x00040000 */
#define TAMP_MISR_ITAMP3MF                  TAMP_MISR_ITAMP3MF_Msk
#define TAMP_MISR_ITAMP5MF_Pos              (20U)
#define TAMP_MISR_ITAMP5MF_Msk              (0x1UL << TAMP_MISR_ITAMP5MF_Pos)       /*!< 0x00100000 */
#define TAMP_MISR_ITAMP5MF                  TAMP_MISR_ITAMP5MF_Msk
#define TAMP_MISR_ITAMP6MF_Pos              (21U)
#define TAMP_MISR_ITAMP6MF_Msk              (0x1UL << TAMP_MISR_ITAMP6MF_Pos)       /*!< 0x00200000 */
#define TAMP_MISR_ITAMP6MF                  TAMP_MISR_ITAMP6MF_Msk
#define TAMP_MISR_ITAMP7MF_Pos              (22U)
#define TAMP_MISR_ITAMP7MF_Msk              (0x1UL << TAMP_MISR_ITAMP7MF_Pos)       /*!< 0x00400000 */
#define TAMP_MISR_ITAMP7MF                  TAMP_MISR_ITAMP7MF_Msk
#define TAMP_MISR_ITAMP8MF_Pos              (23U)
#define TAMP_MISR_ITAMP8MF_Msk              (0x1UL << TAMP_MISR_ITAMP8MF_Pos)       /*!< 0x00800000 */
#define TAMP_MISR_ITAMP8MF                  TAMP_MISR_ITAMP8MF_Msk
#define TAMP_MISR_ITAMP9MF_Pos              (24U)
#define TAMP_MISR_ITAMP9MF_Msk              (0x1UL << TAMP_MISR_ITAMP9MF_Pos)       /*!< 0x01000000 */
#define TAMP_MISR_ITAMP9MF                  TAMP_MISR_ITAMP9MF_Msk
#define TAMP_MISR_ITAMP11MF_Pos             (26U)
#define TAMP_MISR_ITAMP11MF_Msk             (0x1UL << TAMP_MISR_ITAMP11MF_Pos)      /*!< 0x04000000 */
#define TAMP_MISR_ITAMP11MF                 TAMP_MISR_ITAMP11MF_Msk
#define TAMP_MISR_ITAMP12MF_Pos             (27U)
#define TAMP_MISR_ITAMP12MF_Msk             (0x1UL << TAMP_MISR_ITAMP12MF_Pos)      /*!< 0x08000000 */
#define TAMP_MISR_ITAMP12MF                 TAMP_MISR_ITAMP12MF_Msk
#define TAMP_MISR_ITAMP13MF_Pos             (28U)
#define TAMP_MISR_ITAMP13MF_Msk             (0x1UL << TAMP_MISR_ITAMP13MF_Pos)      /*!< 0x10000000 */
#define TAMP_MISR_ITAMP13MF                 TAMP_MISR_ITAMP13MF_Msk

/********************  Bits definition for TAMP_SMISR register  ************ *****/
#define TAMP_SMISR_TAMP1MF_Pos              (0U)
#define TAMP_SMISR_TAMP1MF_Msk              (0x1UL << TAMP_SMISR_TAMP1MF_Pos)       /*!< 0x00000001 */
#define TAMP_SMISR_TAMP1MF                  TAMP_SMISR_TAMP1MF_Msk
#define TAMP_SMISR_TAMP2MF_Pos              (1U)
#define TAMP_SMISR_TAMP2MF_Msk              (0x1UL << TAMP_SMISR_TAMP2MF_Pos)       /*!< 0x00000002 */
#define TAMP_SMISR_TAMP2MF                  TAMP_SMISR_TAMP2MF_Msk
#define TAMP_SMISR_TAMP3MF_Pos              (2U)
#define TAMP_SMISR_TAMP3MF_Msk              (0x1UL << TAMP_SMISR_TAMP3MF_Pos)       /*!< 0x00000004 */
#define TAMP_SMISR_TAMP3MF                  TAMP_SMISR_TAMP3MF_Msk
#define TAMP_SMISR_ITAMP3MF_Pos             (18U)
#define TAMP_SMISR_ITAMP3MF_Msk             (0x1UL << TAMP_SMISR_ITAMP3MF_Pos)      /*!< 0x00040000 */
#define TAMP_SMISR_ITAMP3MF                 TAMP_SMISR_ITAMP3MF_Msk
#define TAMP_SMISR_ITAMP5MF_Pos             (20U)
#define TAMP_SMISR_ITAMP5MF_Msk             (0x1UL << TAMP_SMISR_ITAMP5MF_Pos)      /*!< 0x00100000 */
#define TAMP_SMISR_ITAMP5MF                 TAMP_SMISR_ITAMP5MF_Msk
#define TAMP_SMISR_ITAMP6MF_Pos             (21U)
#define TAMP_SMISR_ITAMP6MF_Msk             (0x1UL << TAMP_SMISR_ITAMP6MF_Pos)      /*!< 0x00200000 */
#define TAMP_SMISR_ITAMP6MF                 TAMP_SMISR_ITAMP6MF_Msk
#define TAMP_SMISR_ITAMP7MF_Pos             (22U)
#define TAMP_SMISR_ITAMP7MF_Msk             (0x1UL << TAMP_SMISR_ITAMP7MF_Pos)      /*!< 0x00400000 */
#define TAMP_SMISR_ITAMP7MF                 TAMP_SMISR_ITAMP7MF_Msk
#define TAMP_SMISR_ITAMP8MF_Pos             (23U)
#define TAMP_SMISR_ITAMP8MF_Msk             (0x1UL << TAMP_SMISR_ITAMP8MF_Pos)      /*!< 0x00800000 */
#define TAMP_SMISR_ITAMP8MF                 TAMP_SMISR_ITAMP8MF_Msk
#define TAMP_SMISR_ITAMP9MF_Pos             (24U)
#define TAMP_SMISR_ITAMP9MF_Msk             (0x1UL << TAMP_SMISR_ITAMP9MF_Pos)      /*!< 0x01000000 */
#define TAMP_SMISR_ITAMP9MF                 TAMP_SMISR_ITAMP9MF_Msk
#define TAMP_SMISR_ITAMP11MF_Pos            (26U)
#define TAMP_SMISR_ITAMP11MF_Msk            (0x1UL << TAMP_SMISR_ITAMP11MF_Pos)     /*!< 0x04000000 */
#define TAMP_SMISR_ITAMP11MF                TAMP_SMISR_ITAMP11MF_Msk
#define TAMP_SMISR_ITAMP12MF_Pos            (27U)
#define TAMP_SMISR_ITAMP12MF_Msk            (0x1UL << TAMP_SMISR_ITAMP12MF_Pos)     /*!< 0x08000000 */
#define TAMP_SMISR_ITAMP12MF                TAMP_SMISR_ITAMP12MF_Msk
#define TAMP_SMISR_ITAMP13MF_Pos            (28U)
#define TAMP_SMISR_ITAMP13MF_Msk            (0x1UL << TAMP_SMISR_ITAMP13MF_Pos)     /*!< 0x10000000 */
#define TAMP_SMISR_ITAMP13MF                TAMP_SMISR_ITAMP13MF_Msk

/********************  Bits definition for TAMP_SCR register  *****************/
#define TAMP_SCR_CTAMP1F_Pos                (0U)
#define TAMP_SCR_CTAMP1F_Msk                (0x1UL << TAMP_SCR_CTAMP1F_Pos)         /*!< 0x00000001 */
#define TAMP_SCR_CTAMP1F                    TAMP_SCR_CTAMP1F_Msk
#define TAMP_SCR_CTAMP2F_Pos                (1U)
#define TAMP_SCR_CTAMP2F_Msk                (0x1UL << TAMP_SCR_CTAMP2F_Pos)         /*!< 0x00000002 */
#define TAMP_SCR_CTAMP2F                    TAMP_SCR_CTAMP2F_Msk
#define TAMP_SCR_CTAMP3F_Pos                (2U)
#define TAMP_SCR_CTAMP3F_Msk                (0x1UL << TAMP_SCR_CTAMP3F_Pos)         /*!< 0x00000004 */
#define TAMP_SCR_CTAMP3F                    TAMP_SCR_CTAMP3F_Msk
#define TAMP_SCR_CITAMP3F_Pos               (18U)
#define TAMP_SCR_CITAMP3F_Msk               (0x1UL << TAMP_SCR_CITAMP3F_Pos)        /*!< 0x00040000 */
#define TAMP_SCR_CITAMP3F                   TAMP_SCR_CITAMP3F_Msk
#define TAMP_SCR_CITAMP5F_Pos               (20U)
#define TAMP_SCR_CITAMP5F_Msk               (0x1UL << TAMP_SCR_CITAMP5F_Pos)        /*!< 0x00100000 */
#define TAMP_SCR_CITAMP5F                   TAMP_SCR_CITAMP5F_Msk
#define TAMP_SCR_CITAMP6F_Pos               (21U)
#define TAMP_SCR_CITAMP6F_Msk               (0x1UL << TAMP_SCR_CITAMP6F_Pos)        /*!< 0x00200000 */
#define TAMP_SCR_CITAMP6F                   TAMP_SCR_CITAMP6F_Msk
#define TAMP_SCR_CITAMP7F_Pos               (22U)
#define TAMP_SCR_CITAMP7F_Msk               (0x1UL << TAMP_SCR_CITAMP7F_Pos)        /*!< 0x00400000 */
#define TAMP_SCR_CITAMP7F                   TAMP_SCR_CITAMP7F_Msk
#define TAMP_SCR_CITAMP8F_Pos               (23U)
#define TAMP_SCR_CITAMP8F_Msk               (0x1UL << TAMP_SCR_CITAMP8F_Pos)        /*!< 0x00800000 */
#define TAMP_SCR_CITAMP8F                   TAMP_SCR_CITAMP8F_Msk
#define TAMP_SCR_CITAMP9F_Pos               (24U)
#define TAMP_SCR_CITAMP9F_Msk               (0x1UL << TAMP_SCR_CITAMP9F_Pos)        /*!< 0x01000000 */
#define TAMP_SCR_CITAMP9F                   TAMP_SCR_CITAMP9F_Msk
#define TAMP_SCR_CITAMP11F_Pos              (26U)
#define TAMP_SCR_CITAMP11F_Msk              (0x1UL << TAMP_SCR_CITAMP11F_Pos)       /*!< 0x04000000 */
#define TAMP_SCR_CITAMP11F                  TAMP_SCR_CITAMP11F_Msk
#define TAMP_SCR_CITAMP12F_Pos              (27U)
#define TAMP_SCR_CITAMP12F_Msk              (0x1UL << TAMP_SCR_CITAMP12F_Pos)       /*!< 0x08000000 */
#define TAMP_SCR_CITAMP12F                  TAMP_SCR_CITAMP12F_Msk
#define TAMP_SCR_CITAMP13F_Pos              (28U)
#define TAMP_SCR_CITAMP13F_Msk              (0x1UL << TAMP_SCR_CITAMP13F_Pos)       /*!< 0x10000000 */
#define TAMP_SCR_CITAMP13F                  TAMP_SCR_CITAMP13F_Msk

/********************  Bits definition for TAMP_COUNT1R register  ***************/
#define TAMP_COUNT1R_COUNT_Pos              (0U)
#define TAMP_COUNT1R_COUNT_Msk              (0xFFFFFFFFUL << TAMP_COUNT1R_COUNT_Pos)/*!< 0xFFFFFFFF */
#define TAMP_COUNT1R_COUNT                  TAMP_COUNT1R_COUNT_Msk

/********************  Bits definition for TAMP_BKP0R register  ***************/
#define TAMP_BKP0R_Pos                      (0U)
#define TAMP_BKP0R_Msk                      (0xFFFFFFFFUL << TAMP_BKP0R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP0R                          TAMP_BKP0R_Msk

/********************  Bits definition for TAMP_BKP1R register  ****************/
#define TAMP_BKP1R_Pos                      (0U)
#define TAMP_BKP1R_Msk                      (0xFFFFFFFFUL << TAMP_BKP1R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP1R                          TAMP_BKP1R_Msk

/********************  Bits definition for TAMP_BKP2R register  ****************/
#define TAMP_BKP2R_Pos                      (0U)
#define TAMP_BKP2R_Msk                      (0xFFFFFFFFUL << TAMP_BKP2R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP2R                          TAMP_BKP2R_Msk

/********************  Bits definition for TAMP_BKP3R register  ****************/
#define TAMP_BKP3R_Pos                      (0U)
#define TAMP_BKP3R_Msk                      (0xFFFFFFFFUL << TAMP_BKP3R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP3R                          TAMP_BKP3R_Msk

/********************  Bits definition for TAMP_BKP4R register  ****************/
#define TAMP_BKP4R_Pos                      (0U)
#define TAMP_BKP4R_Msk                      (0xFFFFFFFFUL << TAMP_BKP4R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP4R                          TAMP_BKP4R_Msk

/********************  Bits definition for TAMP_BKP5R register  ****************/
#define TAMP_BKP5R_Pos                      (0U)
#define TAMP_BKP5R_Msk                      (0xFFFFFFFFUL << TAMP_BKP5R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP5R                          TAMP_BKP5R_Msk

/********************  Bits definition for TAMP_BKP6R register  ****************/
#define TAMP_BKP6R_Pos                      (0U)
#define TAMP_BKP6R_Msk                      (0xFFFFFFFFUL << TAMP_BKP6R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP6R                          TAMP_BKP6R_Msk

/********************  Bits definition for TAMP_BKP7R register  ****************/
#define TAMP_BKP7R_Pos                      (0U)
#define TAMP_BKP7R_Msk                      (0xFFFFFFFFUL << TAMP_BKP7R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP7R                          TAMP_BKP7R_Msk

/********************  Bits definition for TAMP_BKP8R register  ****************/
#define TAMP_BKP8R_Pos                      (0U)
#define TAMP_BKP8R_Msk                      (0xFFFFFFFFUL << TAMP_BKP8R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP8R                          TAMP_BKP8R_Msk

/********************  Bits definition for TAMP_BKP9R register  ****************/
#define TAMP_BKP9R_Pos                      (0U)
#define TAMP_BKP9R_Msk                      (0xFFFFFFFFUL << TAMP_BKP9R_Pos)        /*!< 0xFFFFFFFF */
#define TAMP_BKP9R                          TAMP_BKP9R_Msk

/********************  Bits definition for TAMP_BKP10R register  ***************/
#define TAMP_BKP10R_Pos                     (0U)
#define TAMP_BKP10R_Msk                     (0xFFFFFFFFUL << TAMP_BKP10R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP10R                         TAMP_BKP10R_Msk

/********************  Bits definition for TAMP_BKP11R register  ***************/
#define TAMP_BKP11R_Pos                     (0U)
#define TAMP_BKP11R_Msk                     (0xFFFFFFFFUL << TAMP_BKP11R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP11R                         TAMP_BKP11R_Msk

/********************  Bits definition for TAMP_BKP12R register  ***************/
#define TAMP_BKP12R_Pos                     (0U)
#define TAMP_BKP12R_Msk                     (0xFFFFFFFFUL << TAMP_BKP12R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP12R                         TAMP_BKP12R_Msk

/********************  Bits definition for TAMP_BKP13R register  ***************/
#define TAMP_BKP13R_Pos                     (0U)
#define TAMP_BKP13R_Msk                     (0xFFFFFFFFUL << TAMP_BKP13R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP13R                         TAMP_BKP13R_Msk

/********************  Bits definition for TAMP_BKP14R register  ***************/
#define TAMP_BKP14R_Pos                     (0U)
#define TAMP_BKP14R_Msk                     (0xFFFFFFFFUL << TAMP_BKP14R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP14R                         TAMP_BKP14R_Msk

/********************  Bits definition for TAMP_BKP15R register  ***************/
#define TAMP_BKP15R_Pos                     (0U)
#define TAMP_BKP15R_Msk                     (0xFFFFFFFFUL << TAMP_BKP15R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP15R                         TAMP_BKP15R_Msk

/********************  Bits definition for TAMP_BKP16R register  ***************/
#define TAMP_BKP16R_Pos                     (0U)
#define TAMP_BKP16R_Msk                     (0xFFFFFFFFUL << TAMP_BKP16R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP16R                         TAMP_BKP16R_Msk

/********************  Bits definition for TAMP_BKP17R register  ***************/
#define TAMP_BKP17R_Pos                     (0U)
#define TAMP_BKP17R_Msk                     (0xFFFFFFFFUL << TAMP_BKP17R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP17R                         TAMP_BKP17R_Msk

/********************  Bits definition for TAMP_BKP18R register  ***************/
#define TAMP_BKP18R_Pos                     (0U)
#define TAMP_BKP18R_Msk                     (0xFFFFFFFFUL << TAMP_BKP18R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP18R                         TAMP_BKP18R_Msk

/********************  Bits definition for TAMP_BKP19R register  ***************/
#define TAMP_BKP19R_Pos                     (0U)
#define TAMP_BKP19R_Msk                     (0xFFFFFFFFUL << TAMP_BKP19R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP19R                         TAMP_BKP19R_Msk

/********************  Bits definition for TAMP_BKP20R register  ***************/
#define TAMP_BKP20R_Pos                     (0U)
#define TAMP_BKP20R_Msk                     (0xFFFFFFFFUL << TAMP_BKP20R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP20R                         TAMP_BKP20R_Msk

/********************  Bits definition for TAMP_BKP21R register  ***************/
#define TAMP_BKP21R_Pos                     (0U)
#define TAMP_BKP21R_Msk                     (0xFFFFFFFFUL << TAMP_BKP21R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP21R                         TAMP_BKP21R_Msk

/********************  Bits definition for TAMP_BKP22R register  ***************/
#define TAMP_BKP22R_Pos                     (0U)
#define TAMP_BKP22R_Msk                     (0xFFFFFFFFUL << TAMP_BKP22R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP22R                         TAMP_BKP22R_Msk

/********************  Bits definition for TAMP_BKP23R register  ***************/
#define TAMP_BKP23R_Pos                     (0U)
#define TAMP_BKP23R_Msk                     (0xFFFFFFFFUL << TAMP_BKP23R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP23R                         TAMP_BKP23R_Msk

/********************  Bits definition for TAMP_BKP24R register  ***************/
#define TAMP_BKP24R_Pos                     (0U)
#define TAMP_BKP24R_Msk                     (0xFFFFFFFFUL << TAMP_BKP24R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP24R                         TAMP_BKP24R_Msk

/********************  Bits definition for TAMP_BKP25R register  ***************/
#define TAMP_BKP25R_Pos                     (0U)
#define TAMP_BKP25R_Msk                     (0xFFFFFFFFUL << TAMP_BKP25R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP25R                         TAMP_BKP25R_Msk

/********************  Bits definition for TAMP_BKP26R register  ***************/
#define TAMP_BKP26R_Pos                     (0U)
#define TAMP_BKP26R_Msk                     (0xFFFFFFFFUL << TAMP_BKP26R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP26R                         TAMP_BKP26R_Msk

/********************  Bits definition for TAMP_BKP27R register  ***************/
#define TAMP_BKP27R_Pos                     (0U)
#define TAMP_BKP27R_Msk                     (0xFFFFFFFFUL << TAMP_BKP27R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP27R                         TAMP_BKP27R_Msk

/********************  Bits definition for TAMP_BKP28R register  ***************/
#define TAMP_BKP28R_Pos                     (0U)
#define TAMP_BKP28R_Msk                     (0xFFFFFFFFUL << TAMP_BKP28R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP28R                         TAMP_BKP28R_Msk

/********************  Bits definition for TAMP_BKP29R register  ***************/
#define TAMP_BKP29R_Pos                     (0U)
#define TAMP_BKP29R_Msk                     (0xFFFFFFFFUL << TAMP_BKP29R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP29R                         TAMP_BKP29R_Msk

/********************  Bits definition for TAMP_BKP30R register  ***************/
#define TAMP_BKP30R_Pos                     (0U)
#define TAMP_BKP30R_Msk                     (0xFFFFFFFFUL << TAMP_BKP30R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP30R                         TAMP_BKP30R_Msk

/********************  Bits definition for TAMP_BKP31R register  ***************/
#define TAMP_BKP31R_Pos                     (0U)
#define TAMP_BKP31R_Msk                     (0xFFFFFFFFUL << TAMP_BKP31R_Pos)       /*!< 0xFFFFFFFF */
#define TAMP_BKP31R                         TAMP_BKP31R_Msk


/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos                     (0U)
#define TIM_CR1_CEN_Msk                     (0x1UL << TIM_CR1_CEN_Pos)              /*!< 0x00000001 */
#define TIM_CR1_CEN                         TIM_CR1_CEN_Msk                         /*!<Counter enable */
#define TIM_CR1_UDIS_Pos                    (1U)
#define TIM_CR1_UDIS_Msk                    (0x1UL << TIM_CR1_UDIS_Pos)             /*!< 0x00000002 */
#define TIM_CR1_UDIS                        TIM_CR1_UDIS_Msk                        /*!<Update disable */
#define TIM_CR1_URS_Pos                     (2U)
#define TIM_CR1_URS_Msk                     (0x1UL << TIM_CR1_URS_Pos)              /*!< 0x00000004 */
#define TIM_CR1_URS                         TIM_CR1_URS_Msk                         /*!<Update request source */
#define TIM_CR1_OPM_Pos                     (3U)
#define TIM_CR1_OPM_Msk                     (0x1UL << TIM_CR1_OPM_Pos)              /*!< 0x00000008 */
#define TIM_CR1_OPM                         TIM_CR1_OPM_Msk                         /*!<One pulse mode */
#define TIM_CR1_DIR_Pos                     (4U)
#define TIM_CR1_DIR_Msk                     (0x1UL << TIM_CR1_DIR_Pos)              /*!< 0x00000010 */
#define TIM_CR1_DIR                         TIM_CR1_DIR_Msk                         /*!<Direction */
#define TIM_CR1_CMS_Pos                     (5U)
#define TIM_CR1_CMS_Msk                     (0x3UL << TIM_CR1_CMS_Pos)              /*!< 0x00000060 */
#define TIM_CR1_CMS                         TIM_CR1_CMS_Msk                         /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0                       (0x1UL << TIM_CR1_CMS_Pos)              /*!< 0x00000020 */
#define TIM_CR1_CMS_1                       (0x2UL << TIM_CR1_CMS_Pos)              /*!< 0x00000040 */
#define TIM_CR1_ARPE_Pos                    (7U)
#define TIM_CR1_ARPE_Msk                    (0x1UL << TIM_CR1_ARPE_Pos)             /*!< 0x00000080 */
#define TIM_CR1_ARPE                        TIM_CR1_ARPE_Msk                        /*!<Auto-reload preload enable */
#define TIM_CR1_CKD_Pos                     (8U)
#define TIM_CR1_CKD_Msk                     (0x3UL << TIM_CR1_CKD_Pos)              /*!< 0x00000300 */
#define TIM_CR1_CKD                         TIM_CR1_CKD_Msk                         /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0                       (0x1UL << TIM_CR1_CKD_Pos)              /*!< 0x00000100 */
#define TIM_CR1_CKD_1                       (0x2UL << TIM_CR1_CKD_Pos)              /*!< 0x00000200 */
#define TIM_CR1_UIFREMAP_Pos                (11U)
#define TIM_CR1_UIFREMAP_Msk                (0x1UL << TIM_CR1_UIFREMAP_Pos)         /*!< 0x00000800 */
#define TIM_CR1_UIFREMAP                    TIM_CR1_UIFREMAP_Msk                    /*!<Update interrupt flag remap */
#define TIM_CR1_DITHEN_Pos                  (12U)
#define TIM_CR1_DITHEN_Msk                  (0x1UL << TIM_CR1_DITHEN_Pos)           /*!< 0x00001000 */
#define TIM_CR1_DITHEN                      TIM_CR1_DITHEN_Msk                      /*!<Dithering enable */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define TIM_CR2_CCPC_Pos                    (0U)
#define TIM_CR2_CCPC_Msk                    (0x1UL << TIM_CR2_CCPC_Pos)             /*!< 0x00000001 */
#define TIM_CR2_CCPC                        TIM_CR2_CCPC_Msk                        /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos                    (2U)
#define TIM_CR2_CCUS_Msk                    (0x1UL << TIM_CR2_CCUS_Pos)             /*!< 0x00000004 */
#define TIM_CR2_CCUS                        TIM_CR2_CCUS_Msk                        /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos                    (3U)
#define TIM_CR2_CCDS_Msk                    (0x1UL << TIM_CR2_CCDS_Pos)             /*!< 0x00000008 */
#define TIM_CR2_CCDS                        TIM_CR2_CCDS_Msk                        /*!<Capture/Compare DMA Selection */
#define TIM_CR2_MMS_Pos                     (4U)
#define TIM_CR2_MMS_Msk                     (0x200007UL << TIM_CR2_MMS_Pos)         /*!< 0x02000070 */
#define TIM_CR2_MMS                         TIM_CR2_MMS_Msk                         /*!<MMS[3:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0                       (0x000001UL << TIM_CR2_MMS_Pos)         /*!< 0x00000010 */
#define TIM_CR2_MMS_1                       (0x000002UL << TIM_CR2_MMS_Pos)         /*!< 0x00000020 */
#define TIM_CR2_MMS_2                       (0x000004UL << TIM_CR2_MMS_Pos)         /*!< 0x00000040 */
#define TIM_CR2_MMS_3                       (0x200000UL << TIM_CR2_MMS_Pos)         /*!< 0x02000000 */
#define TIM_CR2_TI1S_Pos                    (7U)
#define TIM_CR2_TI1S_Msk                    (0x1UL << TIM_CR2_TI1S_Pos)             /*!< 0x00000080 */
#define TIM_CR2_TI1S                        TIM_CR2_TI1S_Msk                        /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos                    (8U)
#define TIM_CR2_OIS1_Msk                    (0x1UL << TIM_CR2_OIS1_Pos)             /*!< 0x00000100 */
#define TIM_CR2_OIS1                        TIM_CR2_OIS1_Msk                        /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos                   (9U)
#define TIM_CR2_OIS1N_Msk                   (0x1UL << TIM_CR2_OIS1N_Pos)            /*!< 0x00000200 */
#define TIM_CR2_OIS1N                       TIM_CR2_OIS1N_Msk                       /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos                    (10U)
#define TIM_CR2_OIS2_Msk                    (0x1UL << TIM_CR2_OIS2_Pos)             /*!< 0x00000400 */
#define TIM_CR2_OIS2                        TIM_CR2_OIS2_Msk                        /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos                   (11U)
#define TIM_CR2_OIS2N_Msk                   (0x1UL << TIM_CR2_OIS2N_Pos)            /*!< 0x00000800 */
#define TIM_CR2_OIS2N                       TIM_CR2_OIS2N_Msk                       /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos                    (12U)
#define TIM_CR2_OIS3_Msk                    (0x1UL << TIM_CR2_OIS3_Pos)             /*!< 0x00001000 */
#define TIM_CR2_OIS3                        TIM_CR2_OIS3_Msk                        /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos                   (13U)
#define TIM_CR2_OIS3N_Msk                   (0x1UL << TIM_CR2_OIS3N_Pos)            /*!< 0x00002000 */
#define TIM_CR2_OIS3N                       TIM_CR2_OIS3N_Msk                       /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos                    (14U)
#define TIM_CR2_OIS4_Msk                    (0x1UL << TIM_CR2_OIS4_Pos)             /*!< 0x00004000 */
#define TIM_CR2_OIS4                        TIM_CR2_OIS4_Msk                        /*!<Output Idle state 4 (OC4 output) */
#define TIM_CR2_OIS4N_Pos                   (15U)
#define TIM_CR2_OIS4N_Msk                   (0x1UL << TIM_CR2_OIS4N_Pos)            /*!< 0x00008000 */
#define TIM_CR2_OIS4N                       TIM_CR2_OIS4N_Msk                       /*!<Output Idle state 4 (OC4N output) */
#define TIM_CR2_OIS5_Pos                    (16U)
#define TIM_CR2_OIS5_Msk                    (0x1UL << TIM_CR2_OIS5_Pos)             /*!< 0x00010000 */
#define TIM_CR2_OIS5                        TIM_CR2_OIS5_Msk                        /*!<Output Idle state 5 (OC5 output) */
#define TIM_CR2_OIS6_Pos                    (18U)
#define TIM_CR2_OIS6_Msk                    (0x1UL << TIM_CR2_OIS6_Pos)             /*!< 0x00040000 */
#define TIM_CR2_OIS6                        TIM_CR2_OIS6_Msk                        /*!<Output Idle state 6 (OC6 output) */
#define TIM_CR2_MMS2_Pos                    (20U)
#define TIM_CR2_MMS2_Msk                    (0xFUL << TIM_CR2_MMS2_Pos)             /*!< 0x00F00000 */
#define TIM_CR2_MMS2                        TIM_CR2_MMS2_Msk                        /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS2_0                      (0x1UL << TIM_CR2_MMS2_Pos)             /*!< 0x00100000 */
#define TIM_CR2_MMS2_1                      (0x2UL << TIM_CR2_MMS2_Pos)             /*!< 0x00200000 */
#define TIM_CR2_MMS2_2                      (0x4UL << TIM_CR2_MMS2_Pos)             /*!< 0x00400000 */
#define TIM_CR2_MMS2_3                      (0x8UL << TIM_CR2_MMS2_Pos)             /*!< 0x00800000 */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define TIM_SMCR_SMS_Pos                    (0U)
#define TIM_SMCR_SMS_Msk                    (0x10007UL << TIM_SMCR_SMS_Pos)         /*!< 0x00010007 */
#define TIM_SMCR_SMS                        TIM_SMCR_SMS_Msk                        /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0                      (0x00001UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000001 */
#define TIM_SMCR_SMS_1                      (0x00002UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000002 */
#define TIM_SMCR_SMS_2                      (0x00004UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000004 */
#define TIM_SMCR_SMS_3                      (0x10000UL << TIM_SMCR_SMS_Pos)         /*!< 0x00010000 */
#define TIM_SMCR_OCCS_Pos                   (3U)
#define TIM_SMCR_OCCS_Msk                   (0x1UL << TIM_SMCR_OCCS_Pos)            /*!< 0x00000008 */
#define TIM_SMCR_OCCS                       TIM_SMCR_OCCS_Msk                       /*!< OCREF clear selection */
#define TIM_SMCR_TS_Pos                     (4U)
#define TIM_SMCR_TS_Msk                     (0x30007UL << TIM_SMCR_TS_Pos)          /*!< 0x00300070 */
#define TIM_SMCR_TS                         TIM_SMCR_TS_Msk                         /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0                       (0x00001UL << TIM_SMCR_TS_Pos)          /*!< 0x00000010 */
#define TIM_SMCR_TS_1                       (0x00002UL << TIM_SMCR_TS_Pos)          /*!< 0x00000020 */
#define TIM_SMCR_TS_2                       (0x00004UL << TIM_SMCR_TS_Pos)          /*!< 0x00000040 */
#define TIM_SMCR_TS_3                       (0x10000UL << TIM_SMCR_TS_Pos)          /*!< 0x00100000 */
#define TIM_SMCR_TS_4                       (0x20000UL << TIM_SMCR_TS_Pos)          /*!< 0x00200000 */
#define TIM_SMCR_MSM_Pos                    (7U)
#define TIM_SMCR_MSM_Msk                    (0x1UL << TIM_SMCR_MSM_Pos)             /*!< 0x00000080 */
#define TIM_SMCR_MSM                        TIM_SMCR_MSM_Msk                        /*!<Master/slave mode */
#define TIM_SMCR_ETF_Pos                    (8U)
#define TIM_SMCR_ETF_Msk                    (0xFUL << TIM_SMCR_ETF_Pos)             /*!< 0x00000F00 */
#define TIM_SMCR_ETF                        TIM_SMCR_ETF_Msk                        /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0                      (0x1UL << TIM_SMCR_ETF_Pos)             /*!< 0x00000100 */
#define TIM_SMCR_ETF_1                      (0x2UL << TIM_SMCR_ETF_Pos)             /*!< 0x00000200 */
#define TIM_SMCR_ETF_2                      (0x4UL << TIM_SMCR_ETF_Pos)             /*!< 0x00000400 */
#define TIM_SMCR_ETF_3                      (0x8UL << TIM_SMCR_ETF_Pos)             /*!< 0x00000800 */
#define TIM_SMCR_ETPS_Pos                   (12U)
#define TIM_SMCR_ETPS_Msk                   (0x3UL << TIM_SMCR_ETPS_Pos)            /*!< 0x00003000 */
#define TIM_SMCR_ETPS                       TIM_SMCR_ETPS_Msk                       /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0                     (0x1UL << TIM_SMCR_ETPS_Pos)            /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1                     (0x2UL << TIM_SMCR_ETPS_Pos)            /*!< 0x00002000 */
#define TIM_SMCR_ECE_Pos                    (14U)
#define TIM_SMCR_ECE_Msk                    (0x1UL << TIM_SMCR_ECE_Pos)             /*!< 0x00004000 */
#define TIM_SMCR_ECE                        TIM_SMCR_ECE_Msk                        /*!<External clock enable */
#define TIM_SMCR_ETP_Pos                    (15U)
#define TIM_SMCR_ETP_Msk                    (0x1UL << TIM_SMCR_ETP_Pos)             /*!< 0x00008000 */
#define TIM_SMCR_ETP                        TIM_SMCR_ETP_Msk                        /*!<External trigger polarity */
#define TIM_SMCR_SMSPE_Pos                  (24U)
#define TIM_SMCR_SMSPE_Msk                  (0x1UL << TIM_SMCR_SMSPE_Pos)           /*!< 0x02000000 */
#define TIM_SMCR_SMSPE                      TIM_SMCR_SMSPE_Msk                      /*!<SMS preload enable */
#define TIM_SMCR_SMSPS_Pos                  (25U)
#define TIM_SMCR_SMSPS_Msk                  (0x1UL << TIM_SMCR_SMSPS_Pos)           /*!< 0x04000000 */
#define TIM_SMCR_SMSPS                      TIM_SMCR_SMSPS_Msk                      /*!<SMS preload source */

/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE_Pos                    (0U)
#define TIM_DIER_UIE_Msk                    (0x1UL << TIM_DIER_UIE_Pos)             /*!< 0x00000001 */
#define TIM_DIER_UIE                        TIM_DIER_UIE_Msk                        /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos                  (1U)
#define TIM_DIER_CC1IE_Msk                  (0x1UL << TIM_DIER_CC1IE_Pos)           /*!< 0x00000002 */
#define TIM_DIER_CC1IE                      TIM_DIER_CC1IE_Msk                      /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos                  (2U)
#define TIM_DIER_CC2IE_Msk                  (0x1UL << TIM_DIER_CC2IE_Pos)           /*!< 0x00000004 */
#define TIM_DIER_CC2IE                      TIM_DIER_CC2IE_Msk                      /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos                  (3U)
#define TIM_DIER_CC3IE_Msk                  (0x1UL << TIM_DIER_CC3IE_Pos)           /*!< 0x00000008 */
#define TIM_DIER_CC3IE                      TIM_DIER_CC3IE_Msk                      /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos                  (4U)
#define TIM_DIER_CC4IE_Msk                  (0x1UL << TIM_DIER_CC4IE_Pos)           /*!< 0x00000010 */
#define TIM_DIER_CC4IE                      TIM_DIER_CC4IE_Msk                      /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos                  (5U)
#define TIM_DIER_COMIE_Msk                  (0x1UL << TIM_DIER_COMIE_Pos)           /*!< 0x00000020 */
#define TIM_DIER_COMIE                      TIM_DIER_COMIE_Msk                      /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos                    (6U)
#define TIM_DIER_TIE_Msk                    (0x1UL << TIM_DIER_TIE_Pos)             /*!< 0x00000040 */
#define TIM_DIER_TIE                        TIM_DIER_TIE_Msk                        /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos                    (7U)
#define TIM_DIER_BIE_Msk                    (0x1UL << TIM_DIER_BIE_Pos)             /*!< 0x00000080 */
#define TIM_DIER_BIE                        TIM_DIER_BIE_Msk                        /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos                    (8U)
#define TIM_DIER_UDE_Msk                    (0x1UL << TIM_DIER_UDE_Pos)             /*!< 0x00000100 */
#define TIM_DIER_UDE                        TIM_DIER_UDE_Msk                        /*!<Update DMA request enable */
#define TIM_DIER_CC1DE_Pos                  (9U)
#define TIM_DIER_CC1DE_Msk                  (0x1UL << TIM_DIER_CC1DE_Pos)           /*!< 0x00000200 */
#define TIM_DIER_CC1DE                      TIM_DIER_CC1DE_Msk                      /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos                  (10U)
#define TIM_DIER_CC2DE_Msk                  (0x1UL << TIM_DIER_CC2DE_Pos)           /*!< 0x00000400 */
#define TIM_DIER_CC2DE                      TIM_DIER_CC2DE_Msk                      /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos                  (11U)
#define TIM_DIER_CC3DE_Msk                  (0x1UL << TIM_DIER_CC3DE_Pos)           /*!< 0x00000800 */
#define TIM_DIER_CC3DE                      TIM_DIER_CC3DE_Msk                      /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos                  (12U)
#define TIM_DIER_CC4DE_Msk                  (0x1UL << TIM_DIER_CC4DE_Pos)           /*!< 0x00001000 */
#define TIM_DIER_CC4DE                      TIM_DIER_CC4DE_Msk                      /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos                  (13U)
#define TIM_DIER_COMDE_Msk                  (0x1UL << TIM_DIER_COMDE_Pos)           /*!< 0x00002000 */
#define TIM_DIER_COMDE                      TIM_DIER_COMDE_Msk                      /*!<COM DMA request enable */
#define TIM_DIER_TDE_Pos                    (14U)
#define TIM_DIER_TDE_Msk                    (0x1UL << TIM_DIER_TDE_Pos)             /*!< 0x00004000 */
#define TIM_DIER_TDE                        TIM_DIER_TDE_Msk                        /*!<Trigger DMA request enable */
#define TIM_DIER_IDXIE_Pos                  (20U)
#define TIM_DIER_IDXIE_Msk                  (0x1UL << TIM_DIER_IDXIE_Pos)           /*!< 0x00100000 */
#define TIM_DIER_IDXIE                      TIM_DIER_IDXIE_Msk                      /*!<Encoder index interrupt enable */
#define TIM_DIER_DIRIE_Pos                  (21U)
#define TIM_DIER_DIRIE_Msk                  (0x1UL << TIM_DIER_DIRIE_Pos)           /*!< 0x00200000 */
#define TIM_DIER_DIRIE                      TIM_DIER_DIRIE_Msk                      /*!<Encoder direction change interrupt enable */
#define TIM_DIER_IERRIE_Pos                 (22U)
#define TIM_DIER_IERRIE_Msk                 (0x1UL << TIM_DIER_IERRIE_Pos)          /*!< 0x00400000 */
#define TIM_DIER_IERRIE                     TIM_DIER_IERRIE_Msk                     /*!<Encoder index error enable */
#define TIM_DIER_TERRIE_Pos                 (23U)
#define TIM_DIER_TERRIE_Msk                 (0x1UL << TIM_DIER_TERRIE_Pos)          /*!< 0x00800000 */
#define TIM_DIER_TERRIE                     TIM_DIER_TERRIE_Msk                     /*!<Encoder transition error enable */

/********************  Bit definition for TIM_SR register  ********************/
#define TIM_SR_UIF_Pos                      (0U)
#define TIM_SR_UIF_Msk                      (0x1UL << TIM_SR_UIF_Pos)               /*!< 0x00000001 */
#define TIM_SR_UIF                          TIM_SR_UIF_Msk                          /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos                    (1U)
#define TIM_SR_CC1IF_Msk                    (0x1UL << TIM_SR_CC1IF_Pos)             /*!< 0x00000002 */
#define TIM_SR_CC1IF                        TIM_SR_CC1IF_Msk                        /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos                    (2U)
#define TIM_SR_CC2IF_Msk                    (0x1UL << TIM_SR_CC2IF_Pos)             /*!< 0x00000004 */
#define TIM_SR_CC2IF                        TIM_SR_CC2IF_Msk                        /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos                    (3U)
#define TIM_SR_CC3IF_Msk                    (0x1UL << TIM_SR_CC3IF_Pos)             /*!< 0x00000008 */
#define TIM_SR_CC3IF                        TIM_SR_CC3IF_Msk                        /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos                    (4U)
#define TIM_SR_CC4IF_Msk                    (0x1UL << TIM_SR_CC4IF_Pos)             /*!< 0x00000010 */
#define TIM_SR_CC4IF                        TIM_SR_CC4IF_Msk                        /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos                    (5U)
#define TIM_SR_COMIF_Msk                    (0x1UL << TIM_SR_COMIF_Pos)             /*!< 0x00000020 */
#define TIM_SR_COMIF                        TIM_SR_COMIF_Msk                        /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos                      (6U)
#define TIM_SR_TIF_Msk                      (0x1UL << TIM_SR_TIF_Pos)               /*!< 0x00000040 */
#define TIM_SR_TIF                          TIM_SR_TIF_Msk                          /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos                      (7U)
#define TIM_SR_BIF_Msk                      (0x1UL << TIM_SR_BIF_Pos)               /*!< 0x00000080 */
#define TIM_SR_BIF                          TIM_SR_BIF_Msk                          /*!<Break interrupt Flag */
#define TIM_SR_B2IF_Pos                     (8U)
#define TIM_SR_B2IF_Msk                     (0x1UL << TIM_SR_B2IF_Pos)              /*!< 0x00000100 */
#define TIM_SR_B2IF                         TIM_SR_B2IF_Msk                         /*!<Break 2 interrupt Flag */
#define TIM_SR_CC1OF_Pos                    (9U)
#define TIM_SR_CC1OF_Msk                    (0x1UL << TIM_SR_CC1OF_Pos)             /*!< 0x00000200 */
#define TIM_SR_CC1OF                        TIM_SR_CC1OF_Msk                        /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos                    (10U)
#define TIM_SR_CC2OF_Msk                    (0x1UL << TIM_SR_CC2OF_Pos)             /*!< 0x00000400 */
#define TIM_SR_CC2OF                        TIM_SR_CC2OF_Msk                        /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos                    (11U)
#define TIM_SR_CC3OF_Msk                    (0x1UL << TIM_SR_CC3OF_Pos)             /*!< 0x00000800 */
#define TIM_SR_CC3OF                        TIM_SR_CC3OF_Msk                        /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos                    (12U)
#define TIM_SR_CC4OF_Msk                    (0x1UL << TIM_SR_CC4OF_Pos)             /*!< 0x00001000 */
#define TIM_SR_CC4OF                        TIM_SR_CC4OF_Msk                        /*!<Capture/Compare 4 Overcapture Flag */
#define TIM_SR_SBIF_Pos                     (13U)
#define TIM_SR_SBIF_Msk                     (0x1UL << TIM_SR_SBIF_Pos)              /*!< 0x00002000 */
#define TIM_SR_SBIF                         TIM_SR_SBIF_Msk                         /*!<System Break interrupt Flag */
#define TIM_SR_CC5IF_Pos                    (16U)
#define TIM_SR_CC5IF_Msk                    (0x1UL << TIM_SR_CC5IF_Pos)             /*!< 0x00010000 */
#define TIM_SR_CC5IF                        TIM_SR_CC5IF_Msk                        /*!<Capture/Compare 5 interrupt Flag */
#define TIM_SR_CC6IF_Pos                    (17U)
#define TIM_SR_CC6IF_Msk                    (0x1UL << TIM_SR_CC6IF_Pos)             /*!< 0x00020000 */
#define TIM_SR_CC6IF                        TIM_SR_CC6IF_Msk                        /*!<Capture/Compare 6 interrupt Flag */
#define TIM_SR_IDXF_Pos                     (20U)
#define TIM_SR_IDXF_Msk                     (0x1UL << TIM_SR_IDXF_Pos)              /*!< 0x00100000 */
#define TIM_SR_IDXF                         TIM_SR_IDXF_Msk                         /*!<Encoder index interrupt flag */
#define TIM_SR_DIRF_Pos                     (21U)
#define TIM_SR_DIRF_Msk                     (0x1UL << TIM_SR_DIRF_Pos)              /*!< 0x00200000 */
#define TIM_SR_DIRF                         TIM_SR_DIRF_Msk                         /*!<Encoder direction change interrupt flag */
#define TIM_SR_IERRF_Pos                    (22U)
#define TIM_SR_IERRF_Msk                    (0x1UL << TIM_SR_IERRF_Pos)             /*!< 0x00400000 */
#define TIM_SR_IERRF                        TIM_SR_IERRF_Msk                        /*!<Encoder index error flag */
#define TIM_SR_TERRF_Pos                    (23U)
#define TIM_SR_TERRF_Msk                    (0x1UL << TIM_SR_TERRF_Pos)             /*!< 0x00800000 */
#define TIM_SR_TERRF                        TIM_SR_TERRF_Msk                        /*!<Encoder transition error flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG_Pos                      (0U)
#define TIM_EGR_UG_Msk                      (0x1UL << TIM_EGR_UG_Pos)               /*!< 0x00000001 */
#define TIM_EGR_UG                          TIM_EGR_UG_Msk                          /*!<Update Generation */
#define TIM_EGR_CC1G_Pos                    (1U)
#define TIM_EGR_CC1G_Msk                    (0x1UL << TIM_EGR_CC1G_Pos)             /*!< 0x00000002 */
#define TIM_EGR_CC1G                        TIM_EGR_CC1G_Msk                        /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                    (2U)
#define TIM_EGR_CC2G_Msk                    (0x1UL << TIM_EGR_CC2G_Pos)             /*!< 0x00000004 */
#define TIM_EGR_CC2G                        TIM_EGR_CC2G_Msk                        /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                    (3U)
#define TIM_EGR_CC3G_Msk                    (0x1UL << TIM_EGR_CC3G_Pos)             /*!< 0x00000008 */
#define TIM_EGR_CC3G                        TIM_EGR_CC3G_Msk                        /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                    (4U)
#define TIM_EGR_CC4G_Msk                    (0x1UL << TIM_EGR_CC4G_Pos)             /*!< 0x00000010 */
#define TIM_EGR_CC4G                        TIM_EGR_CC4G_Msk                        /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                    (5U)
#define TIM_EGR_COMG_Msk                    (0x1UL << TIM_EGR_COMG_Pos)             /*!< 0x00000020 */
#define TIM_EGR_COMG                        TIM_EGR_COMG_Msk                        /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                      (6U)
#define TIM_EGR_TG_Msk                      (0x1UL << TIM_EGR_TG_Pos)               /*!< 0x00000040 */
#define TIM_EGR_TG                          TIM_EGR_TG_Msk                          /*!<Trigger Generation */
#define TIM_EGR_BG_Pos                      (7U)
#define TIM_EGR_BG_Msk                      (0x1UL << TIM_EGR_BG_Pos)               /*!< 0x00000080 */
#define TIM_EGR_BG                          TIM_EGR_BG_Msk                          /*!<Break Generation */
#define TIM_EGR_B2G_Pos                     (8U)
#define TIM_EGR_B2G_Msk                     (0x1UL << TIM_EGR_B2G_Pos)              /*!< 0x00000100 */
#define TIM_EGR_B2G                         TIM_EGR_B2G_Msk                         /*!<Break 2 Generation */


/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S_Pos                  (0U)
#define TIM_CCMR1_CC1S_Msk                  (0x3UL << TIM_CCMR1_CC1S_Pos)           /*!< 0x00000003 */
#define TIM_CCMR1_CC1S                      TIM_CCMR1_CC1S_Msk                      /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0                    (0x1UL << TIM_CCMR1_CC1S_Pos)           /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1                    (0x2UL << TIM_CCMR1_CC1S_Pos)           /*!< 0x00000002 */
#define TIM_CCMR1_OC1FE_Pos                 (2U)
#define TIM_CCMR1_OC1FE_Msk                 (0x1UL << TIM_CCMR1_OC1FE_Pos)          /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE                     TIM_CCMR1_OC1FE_Msk                     /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos                 (3U)
#define TIM_CCMR1_OC1PE_Msk                 (0x1UL << TIM_CCMR1_OC1PE_Pos)          /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE                     TIM_CCMR1_OC1PE_Msk                     /*!<Output Compare 1 Preload enable */
#define TIM_CCMR1_OC1M_Pos                  (4U)
#define TIM_CCMR1_OC1M_Msk                  (0x1007UL << TIM_CCMR1_OC1M_Pos)        /*!< 0x00010070 */
#define TIM_CCMR1_OC1M                      TIM_CCMR1_OC1M_Msk                      /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0                    (0x0001UL << TIM_CCMR1_OC1M_Pos)        /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1                    (0x0002UL << TIM_CCMR1_OC1M_Pos)        /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2                    (0x0004UL << TIM_CCMR1_OC1M_Pos)        /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3                    (0x1000UL << TIM_CCMR1_OC1M_Pos)        /*!< 0x00010000 */
#define TIM_CCMR1_OC1CE_Pos                 (7U)
#define TIM_CCMR1_OC1CE_Msk                 (0x1UL << TIM_CCMR1_OC1CE_Pos)          /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE                     TIM_CCMR1_OC1CE_Msk                     /*!<Output Compare 1 Clear Enable */
#define TIM_CCMR1_CC2S_Pos                  (8U)
#define TIM_CCMR1_CC2S_Msk                  (0x3UL << TIM_CCMR1_CC2S_Pos)           /*!< 0x00000300 */
#define TIM_CCMR1_CC2S                      TIM_CCMR1_CC2S_Msk                      /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0                    (0x1UL << TIM_CCMR1_CC2S_Pos)           /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1                    (0x2UL << TIM_CCMR1_CC2S_Pos)           /*!< 0x00000200 */
#define TIM_CCMR1_OC2FE_Pos                 (10U)
#define TIM_CCMR1_OC2FE_Msk                 (0x1UL << TIM_CCMR1_OC2FE_Pos)          /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE                     TIM_CCMR1_OC2FE_Msk                     /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos                 (11U)
#define TIM_CCMR1_OC2PE_Msk                 (0x1UL << TIM_CCMR1_OC2PE_Pos)          /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE                     TIM_CCMR1_OC2PE_Msk                     /*!<Output Compare 2 Preload enable */
#define TIM_CCMR1_OC2M_Pos                  (12U)
#define TIM_CCMR1_OC2M_Msk                  (0x1007UL << TIM_CCMR1_OC2M_Pos)        /*!< 0x01007000 */
#define TIM_CCMR1_OC2M                      TIM_CCMR1_OC2M_Msk                      /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0                    (0x0001UL << TIM_CCMR1_OC2M_Pos)        /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1                    (0x0002UL << TIM_CCMR1_OC2M_Pos)        /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2                    (0x0004UL << TIM_CCMR1_OC2M_Pos)        /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3                    (0x1000UL << TIM_CCMR1_OC2M_Pos)        /*!< 0x01000000 */
#define TIM_CCMR1_OC2CE_Pos                 (15U)
#define TIM_CCMR1_OC2CE_Msk                 (0x1UL << TIM_CCMR1_OC2CE_Pos)          /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE                     TIM_CCMR1_OC2CE_Msk                     /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/
#define TIM_CCMR1_IC1PSC_Pos                (2U)
#define TIM_CCMR1_IC1PSC_Msk                (0x3UL << TIM_CCMR1_IC1PSC_Pos)         /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC                    TIM_CCMR1_IC1PSC_Msk                    /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0                  (0x1UL << TIM_CCMR1_IC1PSC_Pos)         /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1                  (0x2UL << TIM_CCMR1_IC1PSC_Pos)         /*!< 0x00000008 */
#define TIM_CCMR1_IC1F_Pos                  (4U)
#define TIM_CCMR1_IC1F_Msk                  (0xFUL << TIM_CCMR1_IC1F_Pos)           /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F                      TIM_CCMR1_IC1F_Msk                      /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0                    (0x1UL << TIM_CCMR1_IC1F_Pos)           /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1                    (0x2UL << TIM_CCMR1_IC1F_Pos)           /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2                    (0x4UL << TIM_CCMR1_IC1F_Pos)           /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3                    (0x8UL << TIM_CCMR1_IC1F_Pos)           /*!< 0x00000080 */
#define TIM_CCMR1_IC2PSC_Pos                (10U)
#define TIM_CCMR1_IC2PSC_Msk                (0x3UL << TIM_CCMR1_IC2PSC_Pos)         /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC                    TIM_CCMR1_IC2PSC_Msk                    /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0                  (0x1UL << TIM_CCMR1_IC2PSC_Pos)         /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1                  (0x2UL << TIM_CCMR1_IC2PSC_Pos)         /*!< 0x00000800 */
#define TIM_CCMR1_IC2F_Pos                  (12U)
#define TIM_CCMR1_IC2F_Msk                  (0xFUL << TIM_CCMR1_IC2F_Pos)           /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F                      TIM_CCMR1_IC2F_Msk                      /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0                    (0x1UL << TIM_CCMR1_IC2F_Pos)           /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1                    (0x2UL << TIM_CCMR1_IC2F_Pos)           /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2                    (0x4UL << TIM_CCMR1_IC2F_Pos)           /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3                    (0x8UL << TIM_CCMR1_IC2F_Pos)           /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define TIM_CCMR2_CC3S_Pos                  (0U)
#define TIM_CCMR2_CC3S_Msk                  (0x3UL << TIM_CCMR2_CC3S_Pos)           /*!< 0x00000003 */
#define TIM_CCMR2_CC3S                      TIM_CCMR2_CC3S_Msk                      /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0                    (0x1UL << TIM_CCMR2_CC3S_Pos)           /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1                    (0x2UL << TIM_CCMR2_CC3S_Pos)           /*!< 0x00000002 */
#define TIM_CCMR2_OC3FE_Pos                 (2U)
#define TIM_CCMR2_OC3FE_Msk                 (0x1UL << TIM_CCMR2_OC3FE_Pos)          /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE                     TIM_CCMR2_OC3FE_Msk                     /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos                 (3U)
#define TIM_CCMR2_OC3PE_Msk                 (0x1UL << TIM_CCMR2_OC3PE_Pos)          /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE                     TIM_CCMR2_OC3PE_Msk                     /*!<Output Compare 3 Preload enable */
#define TIM_CCMR2_OC3M_Pos                  (4U)
#define TIM_CCMR2_OC3M_Msk                  (0x1007UL << TIM_CCMR2_OC3M_Pos)        /*!< 0x00010070 */
#define TIM_CCMR2_OC3M                      TIM_CCMR2_OC3M_Msk                      /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0                    (0x0001UL << TIM_CCMR2_OC3M_Pos)        /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1                    (0x0002UL << TIM_CCMR2_OC3M_Pos)        /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2                    (0x0004UL << TIM_CCMR2_OC3M_Pos)        /*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3                    (0x1000UL << TIM_CCMR2_OC3M_Pos)        /*!< 0x00010000 */
#define TIM_CCMR2_OC3CE_Pos                 (7U)
#define TIM_CCMR2_OC3CE_Msk                 (0x1UL << TIM_CCMR2_OC3CE_Pos)          /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE                     TIM_CCMR2_OC3CE_Msk                     /*!<Output Compare 3 Clear Enable */
#define TIM_CCMR2_CC4S_Pos                  (8U)
#define TIM_CCMR2_CC4S_Msk                  (0x3UL << TIM_CCMR2_CC4S_Pos)           /*!< 0x00000300 */
#define TIM_CCMR2_CC4S                      TIM_CCMR2_CC4S_Msk                      /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0                    (0x1UL << TIM_CCMR2_CC4S_Pos)           /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1                    (0x2UL << TIM_CCMR2_CC4S_Pos)           /*!< 0x00000200 */
#define TIM_CCMR2_OC4FE_Pos                 (10U)
#define TIM_CCMR2_OC4FE_Msk                 (0x1UL << TIM_CCMR2_OC4FE_Pos)          /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE                     TIM_CCMR2_OC4FE_Msk                     /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos                 (11U)
#define TIM_CCMR2_OC4PE_Msk                 (0x1UL << TIM_CCMR2_OC4PE_Pos)          /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE                     TIM_CCMR2_OC4PE_Msk                     /*!<Output Compare 4 Preload enable */
#define TIM_CCMR2_OC4M_Pos                  (12U)
#define TIM_CCMR2_OC4M_Msk                  (0x1007UL << TIM_CCMR2_OC4M_Pos)        /*!< 0x01007000 */
#define TIM_CCMR2_OC4M                      TIM_CCMR2_OC4M_Msk                      /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0                    (0x0001UL << TIM_CCMR2_OC4M_Pos)        /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1                    (0x0002UL << TIM_CCMR2_OC4M_Pos)        /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2                    (0x0004UL << TIM_CCMR2_OC4M_Pos)        /*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3                    (0x1000UL << TIM_CCMR2_OC4M_Pos)        /*!< 0x01000000 */
#define TIM_CCMR2_OC4CE_Pos                 (15U)
#define TIM_CCMR2_OC4CE_Msk                 (0x1UL << TIM_CCMR2_OC4CE_Pos)          /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE                     TIM_CCMR2_OC4CE_Msk                     /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/
#define TIM_CCMR2_IC3PSC_Pos                (2U)
#define TIM_CCMR2_IC3PSC_Msk                (0x3UL << TIM_CCMR2_IC3PSC_Pos)         /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC                    TIM_CCMR2_IC3PSC_Msk                    /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0                  (0x1UL << TIM_CCMR2_IC3PSC_Pos)         /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1                  (0x2UL << TIM_CCMR2_IC3PSC_Pos)         /*!< 0x00000008 */
#define TIM_CCMR2_IC3F_Pos                  (4U)
#define TIM_CCMR2_IC3F_Msk                  (0xFUL << TIM_CCMR2_IC3F_Pos)           /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F                      TIM_CCMR2_IC3F_Msk                      /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                    (0x1UL << TIM_CCMR2_IC3F_Pos)           /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1                    (0x2UL << TIM_CCMR2_IC3F_Pos)           /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2                    (0x4UL << TIM_CCMR2_IC3F_Pos)           /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3                    (0x8UL << TIM_CCMR2_IC3F_Pos)           /*!< 0x00000080 */
#define TIM_CCMR2_IC4PSC_Pos                (10U)
#define TIM_CCMR2_IC4PSC_Msk                (0x3UL << TIM_CCMR2_IC4PSC_Pos)         /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC                    TIM_CCMR2_IC4PSC_Msk                    /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0                  (0x1UL << TIM_CCMR2_IC4PSC_Pos)         /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1                  (0x2UL << TIM_CCMR2_IC4PSC_Pos)         /*!< 0x00000800 */
#define TIM_CCMR2_IC4F_Pos                  (12U)
#define TIM_CCMR2_IC4F_Msk                  (0xFUL << TIM_CCMR2_IC4F_Pos)           /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F                      TIM_CCMR2_IC4F_Msk                      /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                    (0x1UL << TIM_CCMR2_IC4F_Pos)           /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1                    (0x2UL << TIM_CCMR2_IC4F_Pos)           /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2                    (0x4UL << TIM_CCMR2_IC4F_Pos)           /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3                    (0x8UL << TIM_CCMR2_IC4F_Pos)           /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR3 register  *******************/
#define TIM_CCMR3_OC5FE_Pos                 (2U)
#define TIM_CCMR3_OC5FE_Msk                 (0x1UL << TIM_CCMR3_OC5FE_Pos)          /*!< 0x00000004 */
#define TIM_CCMR3_OC5FE                     TIM_CCMR3_OC5FE_Msk                     /*!<Output Compare 5 Fast enable */
#define TIM_CCMR3_OC5PE_Pos                 (3U)
#define TIM_CCMR3_OC5PE_Msk                 (0x1UL << TIM_CCMR3_OC5PE_Pos)          /*!< 0x00000008 */
#define TIM_CCMR3_OC5PE                     TIM_CCMR3_OC5PE_Msk                     /*!<Output Compare 5 Preload enable */
#define TIM_CCMR3_OC5M_Pos                  (4U)
#define TIM_CCMR3_OC5M_Msk                  (0x1007UL << TIM_CCMR3_OC5M_Pos)        /*!< 0x00010070 */
#define TIM_CCMR3_OC5M                      TIM_CCMR3_OC5M_Msk                      /*!<OC5M[3:0] bits (Output Compare 5 Mode) */
#define TIM_CCMR3_OC5M_0                    (0x0001UL << TIM_CCMR3_OC5M_Pos)        /*!< 0x00000010 */
#define TIM_CCMR3_OC5M_1                    (0x0002UL << TIM_CCMR3_OC5M_Pos)        /*!< 0x00000020 */
#define TIM_CCMR3_OC5M_2                    (0x0004UL << TIM_CCMR3_OC5M_Pos)        /*!< 0x00000040 */
#define TIM_CCMR3_OC5M_3                    (0x1000UL << TIM_CCMR3_OC5M_Pos)        /*!< 0x00010000 */
#define TIM_CCMR3_OC5CE_Pos                 (7U)
#define TIM_CCMR3_OC5CE_Msk                 (0x1UL << TIM_CCMR3_OC5CE_Pos)          /*!< 0x00000080 */
#define TIM_CCMR3_OC5CE                     TIM_CCMR3_OC5CE_Msk                     /*!<Output Compare 5 Clear Enable */
#define TIM_CCMR3_OC6FE_Pos                 (10U)
#define TIM_CCMR3_OC6FE_Msk                 (0x1UL << TIM_CCMR3_OC6FE_Pos)          /*!< 0x00000400 */
#define TIM_CCMR3_OC6FE                     TIM_CCMR3_OC6FE_Msk                     /*!<Output Compare 6 Fast enable */
#define TIM_CCMR3_OC6PE_Pos                 (11U)
#define TIM_CCMR3_OC6PE_Msk                 (0x1UL << TIM_CCMR3_OC6PE_Pos)          /*!< 0x00000800 */
#define TIM_CCMR3_OC6PE                     TIM_CCMR3_OC6PE_Msk                     /*!<Output Compare 6 Preload enable */
#define TIM_CCMR3_OC6M_Pos                  (12U)
#define TIM_CCMR3_OC6M_Msk                  (0x1007UL << TIM_CCMR3_OC6M_Pos)        /*!< 0x01007000 */
#define TIM_CCMR3_OC6M                      TIM_CCMR3_OC6M_Msk                      /*!<OC6M[3:0] bits (Output Compare 6 Mode) */
#define TIM_CCMR3_OC6M_0                    (0x0001UL << TIM_CCMR3_OC6M_Pos)        /*!< 0x00001000 */
#define TIM_CCMR3_OC6M_1                    (0x0002UL << TIM_CCMR3_OC6M_Pos)        /*!< 0x00002000 */
#define TIM_CCMR3_OC6M_2                    (0x0004UL << TIM_CCMR3_OC6M_Pos)        /*!< 0x00004000 */
#define TIM_CCMR3_OC6M_3                    (0x1000UL << TIM_CCMR3_OC6M_Pos)        /*!< 0x01000000 */
#define TIM_CCMR3_OC6CE_Pos                 (15U)
#define TIM_CCMR3_OC6CE_Msk                 (0x1UL << TIM_CCMR3_OC6CE_Pos)          /*!< 0x00008000 */
#define TIM_CCMR3_OC6CE                     TIM_CCMR3_OC6CE_Msk                     /*!<Output Compare 6 Clear Enable */

/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E_Pos                   (0U)
#define TIM_CCER_CC1E_Msk                   (0x1UL << TIM_CCER_CC1E_Pos)            /*!< 0x00000001 */
#define TIM_CCER_CC1E                       TIM_CCER_CC1E_Msk                       /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos                   (1U)
#define TIM_CCER_CC1P_Msk                   (0x1UL << TIM_CCER_CC1P_Pos)            /*!< 0x00000002 */
#define TIM_CCER_CC1P                       TIM_CCER_CC1P_Msk                       /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos                  (2U)
#define TIM_CCER_CC1NE_Msk                  (0x1UL << TIM_CCER_CC1NE_Pos)           /*!< 0x00000004 */
#define TIM_CCER_CC1NE                      TIM_CCER_CC1NE_Msk                      /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos                  (3U)
#define TIM_CCER_CC1NP_Msk                  (0x1UL << TIM_CCER_CC1NP_Pos)           /*!< 0x00000008 */
#define TIM_CCER_CC1NP                      TIM_CCER_CC1NP_Msk                      /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos                   (4U)
#define TIM_CCER_CC2E_Msk                   (0x1UL << TIM_CCER_CC2E_Pos)            /*!< 0x00000010 */
#define TIM_CCER_CC2E                       TIM_CCER_CC2E_Msk                       /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos                   (5U)
#define TIM_CCER_CC2P_Msk                   (0x1UL << TIM_CCER_CC2P_Pos)            /*!< 0x00000020 */
#define TIM_CCER_CC2P                       TIM_CCER_CC2P_Msk                       /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos                  (6U)
#define TIM_CCER_CC2NE_Msk                  (0x1UL << TIM_CCER_CC2NE_Pos)           /*!< 0x00000040 */
#define TIM_CCER_CC2NE                      TIM_CCER_CC2NE_Msk                      /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos                  (7U)
#define TIM_CCER_CC2NP_Msk                  (0x1UL << TIM_CCER_CC2NP_Pos)           /*!< 0x00000080 */
#define TIM_CCER_CC2NP                      TIM_CCER_CC2NP_Msk                      /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos                   (8U)
#define TIM_CCER_CC3E_Msk                   (0x1UL << TIM_CCER_CC3E_Pos)            /*!< 0x00000100 */
#define TIM_CCER_CC3E                       TIM_CCER_CC3E_Msk                       /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos                   (9U)
#define TIM_CCER_CC3P_Msk                   (0x1UL << TIM_CCER_CC3P_Pos)            /*!< 0x00000200 */
#define TIM_CCER_CC3P                       TIM_CCER_CC3P_Msk                       /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos                  (10U)
#define TIM_CCER_CC3NE_Msk                  (0x1UL << TIM_CCER_CC3NE_Pos)           /*!< 0x00000400 */
#define TIM_CCER_CC3NE                      TIM_CCER_CC3NE_Msk                      /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos                  (11U)
#define TIM_CCER_CC3NP_Msk                  (0x1UL << TIM_CCER_CC3NP_Pos)           /*!< 0x00000800 */
#define TIM_CCER_CC3NP                      TIM_CCER_CC3NP_Msk                      /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos                   (12U)
#define TIM_CCER_CC4E_Msk                   (0x1UL << TIM_CCER_CC4E_Pos)            /*!< 0x00001000 */
#define TIM_CCER_CC4E                       TIM_CCER_CC4E_Msk                       /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos                   (13U)
#define TIM_CCER_CC4P_Msk                   (0x1UL << TIM_CCER_CC4P_Pos)            /*!< 0x00002000 */
#define TIM_CCER_CC4P                       TIM_CCER_CC4P_Msk                       /*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NE_Pos                  (14U)
#define TIM_CCER_CC4NE_Msk                  (0x1UL << TIM_CCER_CC4NE_Pos)           /*!< 0x00004000 */
#define TIM_CCER_CC4NE                      TIM_CCER_CC4NE_Msk                      /*!<Capture/Compare 4 Complementary output enable */
#define TIM_CCER_CC4NP_Pos                  (15U)
#define TIM_CCER_CC4NP_Msk                  (0x1UL << TIM_CCER_CC4NP_Pos)           /*!< 0x00008000 */
#define TIM_CCER_CC4NP                      TIM_CCER_CC4NP_Msk                      /*!<Capture/Compare 4 Complementary output Polarity */
#define TIM_CCER_CC5E_Pos                   (16U)
#define TIM_CCER_CC5E_Msk                   (0x1UL << TIM_CCER_CC5E_Pos)            /*!< 0x00010000 */
#define TIM_CCER_CC5E                       TIM_CCER_CC5E_Msk                       /*!<Capture/Compare 5 output enable */
#define TIM_CCER_CC5P_Pos                   (17U)
#define TIM_CCER_CC5P_Msk                   (0x1UL << TIM_CCER_CC5P_Pos)            /*!< 0x00020000 */
#define TIM_CCER_CC5P                       TIM_CCER_CC5P_Msk                       /*!<Capture/Compare 5 output Polarity */
#define TIM_CCER_CC6E_Pos                   (20U)
#define TIM_CCER_CC6E_Msk                   (0x1UL << TIM_CCER_CC6E_Pos)            /*!< 0x00100000 */
#define TIM_CCER_CC6E                       TIM_CCER_CC6E_Msk                       /*!<Capture/Compare 6 output enable */
#define TIM_CCER_CC6P_Pos                   (21U)
#define TIM_CCER_CC6P_Msk                   (0x1UL << TIM_CCER_CC6P_Pos)            /*!< 0x00200000 */
#define TIM_CCER_CC6P                       TIM_CCER_CC6P_Msk                       /*!<Capture/Compare 6 output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define TIM_CNT_CNT_Pos                     (0U)
#define TIM_CNT_CNT_Msk                     (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)       /*!< 0xFFFFFFFF */
#define TIM_CNT_CNT                         TIM_CNT_CNT_Msk                         /*!<Counter Value */
#define TIM_CNT_UIFCPY_Pos                  (31U)
#define TIM_CNT_UIFCPY_Msk                  (0x1UL << TIM_CNT_UIFCPY_Pos)           /*!< 0x80000000 */
#define TIM_CNT_UIFCPY                      TIM_CNT_UIFCPY_Msk                      /*!<Update interrupt flag copy (if UIFREMAP=1) */

/*******************  Bit definition for TIM_PSC register  ********************/
#define TIM_PSC_PSC_Pos                     (0U)
#define TIM_PSC_PSC_Msk                     (0xFFFFUL << TIM_PSC_PSC_Pos)           /*!< 0x0000FFFF */
#define TIM_PSC_PSC                         TIM_PSC_PSC_Msk                         /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  ********************/
#define TIM_ARR_ARR_Pos                     (0U)
#define TIM_ARR_ARR_Msk                     (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)       /*!< 0xFFFFFFFF */
#define TIM_ARR_ARR                         TIM_ARR_ARR_Msk                         /*!<Actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define TIM_RCR_REP_Pos                     (0U)
#define TIM_RCR_REP_Msk                     (0xFFFFUL << TIM_RCR_REP_Pos)           /*!< 0x0000FFFF */
#define TIM_RCR_REP                         TIM_RCR_REP_Msk                         /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define TIM_CCR1_CCR1_Pos                   (0U)
#define TIM_CCR1_CCR1_Msk                   (0xFFFFFUL << TIM_CCR1_CCR1_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR1_CCR1                       TIM_CCR1_CCR1_Msk                       /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define TIM_CCR2_CCR2_Pos                   (0U)
#define TIM_CCR2_CCR2_Msk                   (0xFFFFFUL << TIM_CCR2_CCR2_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR2_CCR2                       TIM_CCR2_CCR2_Msk                       /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define TIM_CCR3_CCR3_Pos                   (0U)
#define TIM_CCR3_CCR3_Msk                   (0xFFFFFUL << TIM_CCR3_CCR3_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR3_CCR3                       TIM_CCR3_CCR3_Msk                       /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define TIM_CCR4_CCR4_Pos                   (0U)
#define TIM_CCR4_CCR4_Msk                   (0xFFFFFUL << TIM_CCR4_CCR4_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR4_CCR4                       TIM_CCR4_CCR4_Msk                       /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_CCR5 register  *******************/
#define TIM_CCR5_CCR5_Pos                   (0U)
#define TIM_CCR5_CCR5_Msk                   (0xFFFFFUL << TIM_CCR5_CCR5_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR5_CCR5                       TIM_CCR5_CCR5_Msk                       /*!<Capture/Compare 5 Value */
#define TIM_CCR5_GC5C1_Pos                  (29U)
#define TIM_CCR5_GC5C1_Msk                  (0x1UL << TIM_CCR5_GC5C1_Pos)           /*!< 0x20000000 */
#define TIM_CCR5_GC5C1                      TIM_CCR5_GC5C1_Msk                      /*!<Group Channel 5 and Channel 1 */
#define TIM_CCR5_GC5C2_Pos                  (30U)
#define TIM_CCR5_GC5C2_Msk                  (0x1UL << TIM_CCR5_GC5C2_Pos)           /*!< 0x40000000 */
#define TIM_CCR5_GC5C2                      TIM_CCR5_GC5C2_Msk                      /*!<Group Channel 5 and Channel 2 */
#define TIM_CCR5_GC5C3_Pos                  (31U)
#define TIM_CCR5_GC5C3_Msk                  (0x1UL << TIM_CCR5_GC5C3_Pos)           /*!< 0x80000000 */
#define TIM_CCR5_GC5C3                      TIM_CCR5_GC5C3_Msk                      /*!<Group Channel 5 and Channel 3 */

/*******************  Bit definition for TIM_CCR6 register  *******************/
#define TIM_CCR6_CCR6_Pos                   (0U)
#define TIM_CCR6_CCR6_Msk                   (0xFFFFFUL << TIM_CCR6_CCR6_Pos)        /*!< 0x000FFFFF */
#define TIM_CCR6_CCR6                       TIM_CCR6_CCR6_Msk                       /*!<Capture/Compare 6 Value */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define TIM_BDTR_DTG_Pos                    (0U)
#define TIM_BDTR_DTG_Msk                    (0xFFUL << TIM_BDTR_DTG_Pos)            /*!< 0x000000FF */
#define TIM_BDTR_DTG                        TIM_BDTR_DTG_Msk                        /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0                      (0x01UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000001 */
#define TIM_BDTR_DTG_1                      (0x02UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000002 */
#define TIM_BDTR_DTG_2                      (0x04UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000004 */
#define TIM_BDTR_DTG_3                      (0x08UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000008 */
#define TIM_BDTR_DTG_4                      (0x10UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000010 */
#define TIM_BDTR_DTG_5                      (0x20UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000020 */
#define TIM_BDTR_DTG_6                      (0x40UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000040 */
#define TIM_BDTR_DTG_7                      (0x80UL << TIM_BDTR_DTG_Pos)            /*!< 0x00000080 */
#define TIM_BDTR_LOCK_Pos                   (8U)
#define TIM_BDTR_LOCK_Msk                   (0x3UL << TIM_BDTR_LOCK_Pos)            /*!< 0x00000300 */
#define TIM_BDTR_LOCK                       TIM_BDTR_LOCK_Msk                       /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0                     (0x1UL << TIM_BDTR_LOCK_Pos)            /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1                     (0x2UL << TIM_BDTR_LOCK_Pos)            /*!< 0x00000200 */
#define TIM_BDTR_OSSI_Pos                   (10U)
#define TIM_BDTR_OSSI_Msk                   (0x1UL << TIM_BDTR_OSSI_Pos)            /*!< 0x00000400 */
#define TIM_BDTR_OSSI                       TIM_BDTR_OSSI_Msk                       /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos                   (11U)
#define TIM_BDTR_OSSR_Msk                   (0x1UL << TIM_BDTR_OSSR_Pos)            /*!< 0x00000800 */
#define TIM_BDTR_OSSR                       TIM_BDTR_OSSR_Msk                       /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos                    (12U)
#define TIM_BDTR_BKE_Msk                    (0x1UL << TIM_BDTR_BKE_Pos)             /*!< 0x00001000 */
#define TIM_BDTR_BKE                        TIM_BDTR_BKE_Msk                        /*!<Break enable for Break 1 */
#define TIM_BDTR_BKP_Pos                    (13U)
#define TIM_BDTR_BKP_Msk                    (0x1UL << TIM_BDTR_BKP_Pos)             /*!< 0x00002000 */
#define TIM_BDTR_BKP                        TIM_BDTR_BKP_Msk                        /*!<Break Polarity for Break 1 */
#define TIM_BDTR_AOE_Pos                    (14U)
#define TIM_BDTR_AOE_Msk                    (0x1UL << TIM_BDTR_AOE_Pos)             /*!< 0x00004000 */
#define TIM_BDTR_AOE                        TIM_BDTR_AOE_Msk                        /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos                    (15U)
#define TIM_BDTR_MOE_Msk                    (0x1UL << TIM_BDTR_MOE_Pos)             /*!< 0x00008000 */
#define TIM_BDTR_MOE                        TIM_BDTR_MOE_Msk                        /*!<Main Output enable */
#define TIM_BDTR_BKF_Pos                    (16U)
#define TIM_BDTR_BKF_Msk                    (0xFUL << TIM_BDTR_BKF_Pos)             /*!< 0x000F0000 */
#define TIM_BDTR_BKF                        TIM_BDTR_BKF_Msk                        /*!<Break Filter for Break 1 */
#define TIM_BDTR_BK2F_Pos                   (20U)
#define TIM_BDTR_BK2F_Msk                   (0xFUL << TIM_BDTR_BK2F_Pos)            /*!< 0x00F00000 */
#define TIM_BDTR_BK2F                       TIM_BDTR_BK2F_Msk                       /*!<Break Filter for Break 2 */
#define TIM_BDTR_BK2E_Pos                   (24U)
#define TIM_BDTR_BK2E_Msk                   (0x1UL << TIM_BDTR_BK2E_Pos)            /*!< 0x01000000 */
#define TIM_BDTR_BK2E                       TIM_BDTR_BK2E_Msk                       /*!<Break enable for Break 2 */
#define TIM_BDTR_BK2P_Pos                   (25U)
#define TIM_BDTR_BK2P_Msk                   (0x1UL << TIM_BDTR_BK2P_Pos)            /*!< 0x02000000 */
#define TIM_BDTR_BK2P                       TIM_BDTR_BK2P_Msk                       /*!<Break Polarity for Break 2 */
#define TIM_BDTR_BKDSRM_Pos                 (26U)
#define TIM_BDTR_BKDSRM_Msk                 (0x1UL << TIM_BDTR_BKDSRM_Pos)          /*!< 0x04000000 */
#define TIM_BDTR_BKDSRM                     TIM_BDTR_BKDSRM_Msk                     /*!<Break disarming/re-arming */
#define TIM_BDTR_BK2DSRM_Pos                (27U)
#define TIM_BDTR_BK2DSRM_Msk                (0x1UL << TIM_BDTR_BK2DSRM_Pos)         /*!< 0x08000000 */
#define TIM_BDTR_BK2DSRM                    TIM_BDTR_BK2DSRM_Msk                    /*!<Break2 disarming/re-arming */
#define TIM_BDTR_BKBID_Pos                  (28U)
#define TIM_BDTR_BKBID_Msk                  (0x1UL << TIM_BDTR_BKBID_Pos)           /*!< 0x10000000 */
#define TIM_BDTR_BKBID                      TIM_BDTR_BKBID_Msk                      /*!<Break BIDirectional */
#define TIM_BDTR_BK2BID_Pos                 (29U)
#define TIM_BDTR_BK2BID_Msk                 (0x1UL << TIM_BDTR_BK2BID_Pos)          /*!< 0x20000000 */
#define TIM_BDTR_BK2BID                     TIM_BDTR_BK2BID_Msk                     /*!<Break2 BIDirectional */

/*******************  Bit definition for TIM_DCR register  ********************/
#define TIM_DCR_DBA_Pos                     (0U)
#define TIM_DCR_DBA_Msk                     (0x1FUL << TIM_DCR_DBA_Pos)             /*!< 0x0000001F */
#define TIM_DCR_DBA                         TIM_DCR_DBA_Msk                         /*!<DBA[4:0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0                       (0x01UL << TIM_DCR_DBA_Pos)             /*!< 0x00000001 */
#define TIM_DCR_DBA_1                       (0x02UL << TIM_DCR_DBA_Pos)             /*!< 0x00000002 */
#define TIM_DCR_DBA_2                       (0x04UL << TIM_DCR_DBA_Pos)             /*!< 0x00000004 */
#define TIM_DCR_DBA_3                       (0x08UL << TIM_DCR_DBA_Pos)             /*!< 0x00000008 */
#define TIM_DCR_DBA_4                       (0x10UL << TIM_DCR_DBA_Pos)             /*!< 0x00000010 */
#define TIM_DCR_DBL_Pos                     (8U)
#define TIM_DCR_DBL_Msk                     (0x1FUL << TIM_DCR_DBL_Pos)             /*!< 0x00001F00 */
#define TIM_DCR_DBL                         TIM_DCR_DBL_Msk                         /*!<DBL[4:0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0                       (0x01UL << TIM_DCR_DBL_Pos)             /*!< 0x00000100 */
#define TIM_DCR_DBL_1                       (0x02UL << TIM_DCR_DBL_Pos)             /*!< 0x00000200 */
#define TIM_DCR_DBL_2                       (0x04UL << TIM_DCR_DBL_Pos)             /*!< 0x00000400 */
#define TIM_DCR_DBL_3                       (0x08UL << TIM_DCR_DBL_Pos)             /*!< 0x00000800 */
#define TIM_DCR_DBL_4                       (0x10UL << TIM_DCR_DBL_Pos)             /*!< 0x00001000 */
#define TIM_DCR_DBSS_Pos                    (16U)
#define TIM_DCR_DBSS_Msk                    (0xFUL << TIM_DCR_DBSS_Pos)             /*!< 0x00000F00 */
#define TIM_DCR_DBSS                        TIM_DCR_DBSS_Msk                        /*!<DBSS[19:16] bits (DMA Burst Source Selection) */
#define TIM_DCR_DBSS_0                      (0x01UL << TIM_DCR_DBSS_Pos)            /*!< 0x00000100 */
#define TIM_DCR_DBSS_1                      (0x02UL << TIM_DCR_DBSS_Pos)            /*!< 0x00000200 */
#define TIM_DCR_DBSS_2                      (0x04UL << TIM_DCR_DBSS_Pos)            /*!< 0x00000400 */
#define TIM_DCR_DBSS_3                      (0x08UL << TIM_DCR_DBSS_Pos)            /*!< 0x00000800 */

/*******************  Bit definition for TIM_AF1 register  *******************/
#define TIM_AF1_BKINE_Pos                  (0U)
#define TIM_AF1_BKINE_Msk                  (0x1UL << TIM_AF1_BKINE_Pos)             /*!< 0x00000001 */
#define TIM_AF1_BKINE                      TIM_AF1_BKINE_Msk                        /*!<BRK BKIN input enable */
#define TIM_AF1_BKCMP1E_Pos                (1U)
#define TIM_AF1_BKCMP1E_Msk                (0x1UL << TIM_AF1_BKCMP1E_Pos)           /*!< 0x00000002 */
#define TIM_AF1_BKCMP1E                    TIM_AF1_BKCMP1E_Msk                      /*!<BRK COMP1 enable */
#define TIM_AF1_BKCMP2E_Pos                (2U)
#define TIM_AF1_BKCMP2E_Msk                (0x1UL << TIM_AF1_BKCMP2E_Pos)           /*!< 0x00000004 */
#define TIM_AF1_BKCMP2E                    TIM_AF1_BKCMP2E_Msk                      /*!<BRK COMP2 enable */
#define TIM_AF1_BKCMP3E_Pos                (3U)
#define TIM_AF1_BKCMP3E_Msk                (0x1UL << TIM_AF1_BKCMP3E_Pos)           /*!< 0x00000008 */
#define TIM_AF1_BKCMP3E                    TIM_AF1_BKCMP3E_Msk                      /*!<BRK COMP3 enable */
#define TIM_AF1_BKCMP4E_Pos                (4U)
#define TIM_AF1_BKCMP4E_Msk                (0x1UL << TIM_AF1_BKCMP4E_Pos)           /*!< 0x00000010 */
#define TIM_AF1_BKCMP4E                    TIM_AF1_BKCMP4E_Msk                      /*!<BRK COMP4 enable */
#define TIM_AF1_BKCMP5E_Pos                (5U)
#define TIM_AF1_BKCMP5E_Msk                (0x1UL << TIM_AF1_BKCMP5E_Pos)           /*!< 0x00000020 */
#define TIM_AF1_BKCMP5E                    TIM_AF1_BKCMP5E_Msk                      /*!<BRK COMP5 enable */
#define TIM_AF1_BKCMP6E_Pos                (6U)
#define TIM_AF1_BKCMP6E_Msk                (0x1UL << TIM_AF1_BKCMP6E_Pos)           /*!< 0x00000040 */
#define TIM_AF1_BKCMP6E                    TIM_AF1_BKCMP6E_Msk                      /*!<BRK COMP6 enable */
#define TIM_AF1_BKCMP7E_Pos                (7U)
#define TIM_AF1_BKCMP7E_Msk                (0x1UL << TIM_AF1_BKCMP7E_Pos)           /*!< 0x00000080 */
#define TIM_AF1_BKCMP7E                    TIM_AF1_BKCMP7E_Msk                      /*!<BRK COMP7 enable */
#define TIM_AF1_BKCMP8E_Pos                (8U)
#define TIM_AF1_BKCMP8E_Msk                (0x1UL << TIM_AF1_BKCMP8E_Pos)           /*!< 0x00000100 */
#define TIM_AF1_BKCMP8E                    TIM_AF1_BKCMP8E_Msk                      /*!<BRK COMP8 enable */
#define TIM_AF1_BKINP_Pos                  (9U)
#define TIM_AF1_BKINP_Msk                  (0x1UL << TIM_AF1_BKINP_Pos)             /*!< 0x00000200 */
#define TIM_AF1_BKINP                      TIM_AF1_BKINP_Msk                        /*!<BRK BKIN input polarity */
#define TIM_AF1_BKCMP1P_Pos                (10U)
#define TIM_AF1_BKCMP1P_Msk                (0x1UL << TIM_AF1_BKCMP1P_Pos)           /*!< 0x00000400 */
#define TIM_AF1_BKCMP1P                    TIM_AF1_BKCMP1P_Msk                      /*!<BRK COMP1 input polarity */
#define TIM_AF1_BKCMP2P_Pos                (11U)
#define TIM_AF1_BKCMP2P_Msk                (0x1UL << TIM_AF1_BKCMP2P_Pos)           /*!< 0x00000800 */
#define TIM_AF1_BKCMP2P                    TIM_AF1_BKCMP2P_Msk                      /*!<BRK COMP2 input polarity */
#define TIM_AF1_BKCMP3P_Pos                (12U)
#define TIM_AF1_BKCMP3P_Msk                (0x1UL << TIM_AF1_BKCMP3P_Pos)           /*!< 0x00001000 */
#define TIM_AF1_BKCMP3P                    TIM_AF1_BKCMP3P_Msk                      /*!<BRK COMP3 input polarity */
#define TIM_AF1_BKCMP4P_Pos                (13U)
#define TIM_AF1_BKCMP4P_Msk                (0x1UL << TIM_AF1_BKCMP4P_Pos)           /*!< 0x00002000 */
#define TIM_AF1_BKCMP4P                    TIM_AF1_BKCMP4P_Msk                      /*!<BRK COMP4 input polarity */
#define TIM_AF1_ETRSEL_Pos                 (14U)
#define TIM_AF1_ETRSEL_Msk                 (0xFUL << TIM_AF1_ETRSEL_Pos)            /*!< 0x0003C000 */
#define TIM_AF1_ETRSEL                     TIM_AF1_ETRSEL_Msk                       /*!<ETRSEL[3:0] bits (TIM1 ETR source selection) */
#define TIM_AF1_ETRSEL_0                   (0x1UL << TIM_AF1_ETRSEL_Pos)            /*!< 0x00004000 */
#define TIM_AF1_ETRSEL_1                   (0x2UL << TIM_AF1_ETRSEL_Pos)            /*!< 0x00008000 */
#define TIM_AF1_ETRSEL_2                   (0x4UL << TIM_AF1_ETRSEL_Pos)            /*!< 0x00010000 */
#define TIM_AF1_ETRSEL_3                   (0x8UL << TIM_AF1_ETRSEL_Pos)            /*!< 0x00020000 */

/*******************  Bit definition for TIM_AF2 register  *********************/
#define TIM_AF2_BK2INE_Pos                 (0U)
#define TIM_AF2_BK2INE_Msk                 (0x1UL << TIM_AF2_BK2INE_Pos)            /*!< 0x00000001 */
#define TIM_AF2_BK2INE                     TIM_AF2_BK2INE_Msk                       /*!<BRK2 BKIN input enable */
#define TIM_AF2_BK2CMP1E_Pos               (1U)
#define TIM_AF2_BK2CMP1E_Msk               (0x1UL << TIM_AF2_BK2CMP1E_Pos)          /*!< 0x00000002 */
#define TIM_AF2_BK2CMP1E                   TIM_AF2_BK2CMP1E_Msk                     /*!<BRK2 COMP1 enable */
#define TIM_AF2_BK2CMP2E_Pos               (2U)
#define TIM_AF2_BK2CMP2E_Msk               (0x1UL << TIM_AF2_BK2CMP2E_Pos)          /*!< 0x00000004 */
#define TIM_AF2_BK2CMP2E                   TIM_AF2_BK2CMP2E_Msk                     /*!<BRK2 COMP2 enable */
#define TIM_AF2_BKCMP3E_Pos                (3U)
#define TIM_AF2_BKCMP3E_Msk                (0x1UL << TIM_AF2_BKCMP3E_Pos)           /*!< 0x00000008 */
#define TIM_AF2_BKCMP3E                    TIM_AF2_BKCMP3E_Msk                      /*!<BRK2 COMP3 enable */
#define TIM_AF2_BKCMP4E_Pos                (4U)
#define TIM_AF2_BKCMP4E_Msk                (0x1UL << TIM_AF2_BKCMP4E_Pos)           /*!< 0x00000010 */
#define TIM_AF2_BKCMP4E                    TIM_AF2_BKCMP4E_Msk                      /*!<BRK2 COMP4 enable */
#define TIM_AF2_BKCMP5E_Pos                (5U)
#define TIM_AF2_BKCMP5E_Msk                (0x1UL << TIM_AF2_BKCMP5E_Pos)           /*!< 0x00000020 */
#define TIM_AF2_BKCMP5E                    TIM_AF2_BKCMP5E_Msk                      /*!<BRK2 COMP5 enable */
#define TIM_AF2_BKCMP6E_Pos                (6U)
#define TIM_AF2_BKCMP6E_Msk                (0x1UL << TIM_AF2_BKCMP6E_Pos)           /*!< 0x00000040 */
#define TIM_AF2_BKCMP6E                    TIM_AF2_BKCMP6E_Msk                      /*!<BRK2 COMP6 enable */
#define TIM_AF2_BKCMP7E_Pos                (7U)
#define TIM_AF2_BKCMP7E_Msk                (0x1UL << TIM_AF2_BKCMP7E_Pos)           /*!< 0x00000080 */
#define TIM_AF2_BKCMP7E                    TIM_AF2_BKCMP7E_Msk                      /*!<BRK2 COMP7 enable */
#define TIM_AF2_BKCMP8E_Pos                (8U)
#define TIM_AF2_BKCMP8E_Msk                (0x1UL << TIM_AF2_BKCMP8E_Pos)           /*!< 0x00000100 */
#define TIM_AF2_BKCMP8E                    TIM_AF2_BKCMP8E_Msk                      /*!<BRK2 COMP8 enable */
#define TIM_AF2_BK2INP_Pos                 (9U)
#define TIM_AF2_BK2INP_Msk                 (0x1UL << TIM_AF2_BK2INP_Pos)            /*!< 0x00000200 */
#define TIM_AF2_BK2INP                     TIM_AF2_BK2INP_Msk                       /*!<BRK2 BKIN input polarity */
#define TIM_AF2_BK2CMP1P_Pos               (10U)
#define TIM_AF2_BK2CMP1P_Msk               (0x1UL << TIM_AF2_BK2CMP1P_Pos)          /*!< 0x00000400 */
#define TIM_AF2_BK2CMP1P                   TIM_AF2_BK2CMP1P_Msk                     /*!<BRK2 COMP1 input polarity */
#define TIM_AF2_BK2CMP2P_Pos               (11U)
#define TIM_AF2_BK2CMP2P_Msk               (0x1UL << TIM_AF2_BK2CMP2P_Pos)          /*!< 0x00000800 */
#define TIM_AF2_BK2CMP2P                   TIM_AF2_BK2CMP2P_Msk                     /*!<BRK2 COMP2 input polarity */
#define TIM_AF2_BK2CMP3P_Pos               (11U)
#define TIM_AF2_BK2CMP3P_Msk               (0x1UL << TIM_AF2_BK2CMP3P_Pos)          /*!< 0x00000800 */
#define TIM_AF2_BK2CMP3P                   TIM_AF2_BK2CMP3P_Msk                     /*!<BRK2 COMP3 input polarity */
#define TIM_AF2_BK2CMP4P_Pos               (11U)
#define TIM_AF2_BK2CMP4P_Msk               (0x1UL << TIM_AF2_BK2CMP4P_Pos)          /*!< 0x00000800 */
#define TIM_AF2_BK2CMP4P                   TIM_AF2_BK2CMP4P_Msk                     /*!<BRK2 COMP4 input polarity */
#define TIM_AF2_OCRSEL_Pos                 (16U)
#define TIM_AF2_OCRSEL_Msk                 (0x7UL << TIM_AF2_OCRSEL_Pos)            /*!< 0x00070000 */
#define TIM_AF2_OCRSEL                     TIM_AF2_OCRSEL_Msk                       /*!<OCREF_CLR source selection */
#define TIM_AF2_OCRSEL_0                   (0x1UL << TIM_AF2_OCRSEL_Pos)            /*!< 0x00010000 */
#define TIM_AF2_OCRSEL_1                   (0x2UL << TIM_AF2_OCRSEL_Pos)            /*!< 0x00020000 */
#define TIM_AF2_OCRSEL_2                   (0x4UL << TIM_AF2_OCRSEL_Pos)            /*!< 0x00040000 */

/*******************  Bit definition for TIM_OR register  *********************/
#define TIM_OR_HSE32EN_Pos                 (1U)
#define TIM_OR_HSE32EN_Msk                 (0x1UL << TIM_OR_HSE32EN_Pos)            /*!< 0x00000002 */
#define TIM_OR_HSE32EN                     TIM_OR_HSE32EN_Msk                       /*!< HSE/32 clock enable */

/*******************  Bit definition for TIM_TISEL register  *********************/
#define TIM_TISEL_TI1SEL_Pos                (0U)
#define TIM_TISEL_TI1SEL_Msk                (0xFUL << TIM_TISEL_TI1SEL_Pos)         /*!< 0x0000000F */
#define TIM_TISEL_TI1SEL                    TIM_TISEL_TI1SEL_Msk                    /*!<TI1SEL[3:0] bits (TIM1 TI1 SEL)*/
#define TIM_TISEL_TI1SEL_0                  (0x1UL << TIM_TISEL_TI1SEL_Pos)         /*!< 0x00000001 */
#define TIM_TISEL_TI1SEL_1                  (0x2UL << TIM_TISEL_TI1SEL_Pos)         /*!< 0x00000002 */
#define TIM_TISEL_TI1SEL_2                  (0x4UL << TIM_TISEL_TI1SEL_Pos)         /*!< 0x00000004 */
#define TIM_TISEL_TI1SEL_3                  (0x8UL << TIM_TISEL_TI1SEL_Pos)         /*!< 0x00000008 */
#define TIM_TISEL_TI2SEL_Pos                (8U)
#define TIM_TISEL_TI2SEL_Msk                (0xFUL << TIM_TISEL_TI2SEL_Pos)         /*!< 0x00000F00 */
#define TIM_TISEL_TI2SEL                    TIM_TISEL_TI2SEL_Msk                    /*!<TI2SEL[3:0] bits (TIM1 TI2 SEL)*/
#define TIM_TISEL_TI2SEL_0                  (0x1UL << TIM_TISEL_TI2SEL_Pos)         /*!< 0x00000100 */
#define TIM_TISEL_TI2SEL_1                  (0x2UL << TIM_TISEL_TI2SEL_Pos)         /*!< 0x00000200 */
#define TIM_TISEL_TI2SEL_2                  (0x4UL << TIM_TISEL_TI2SEL_Pos)         /*!< 0x00000400 */
#define TIM_TISEL_TI2SEL_3                  (0x8UL << TIM_TISEL_TI2SEL_Pos)         /*!< 0x00000800 */
#define TIM_TISEL_TI3SEL_Pos                (16U)
#define TIM_TISEL_TI3SEL_Msk                (0xFUL << TIM_TISEL_TI3SEL_Pos)         /*!< 0x000F0000 */
#define TIM_TISEL_TI3SEL                    TIM_TISEL_TI3SEL_Msk                    /*!<TI3SEL[3:0] bits (TIM1 TI3 SEL)*/
#define TIM_TISEL_TI3SEL_0                  (0x1UL << TIM_TISEL_TI3SEL_Pos)         /*!< 0x00010000 */
#define TIM_TISEL_TI3SEL_1                  (0x2UL << TIM_TISEL_TI3SEL_Pos)         /*!< 0x00020000 */
#define TIM_TISEL_TI3SEL_2                  (0x4UL << TIM_TISEL_TI3SEL_Pos)         /*!< 0x00040000 */
#define TIM_TISEL_TI3SEL_3                  (0x8UL << TIM_TISEL_TI3SEL_Pos)         /*!< 0x00080000 */
#define TIM_TISEL_TI4SEL_Pos                (24U)
#define TIM_TISEL_TI4SEL_Msk                (0xFUL << TIM_TISEL_TI4SEL_Pos)         /*!< 0x0F000000 */
#define TIM_TISEL_TI4SEL                    TIM_TISEL_TI4SEL_Msk                    /*!<TI4SEL[3:0] bits (TIM1 TI4 SEL)*/
#define TIM_TISEL_TI4SEL_0                  (0x1UL << TIM_TISEL_TI4SEL_Pos)         /*!< 0x01000000 */
#define TIM_TISEL_TI4SEL_1                  (0x2UL << TIM_TISEL_TI4SEL_Pos)         /*!< 0x02000000 */
#define TIM_TISEL_TI4SEL_2                  (0x4UL << TIM_TISEL_TI4SEL_Pos)         /*!< 0x04000000 */
#define TIM_TISEL_TI4SEL_3                  (0x8UL << TIM_TISEL_TI4SEL_Pos)         /*!< 0x08000000 */

/*******************  Bit definition for TIM_DTR2 register  *********************/
#define TIM_DTR2_DTGF_Pos                   (0U)
#define TIM_DTR2_DTGF_Msk                   (0xFFUL << TIM_DTR2_DTGF_Pos)           /*!< 0x0000000F */
#define TIM_DTR2_DTGF                       TIM_DTR2_DTGF_Msk                       /*!<DTGF[7:0] bits (Deadtime falling edge generator setup)*/
#define TIM_DTR2_DTGF_0                     (0x01UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000001 */
#define TIM_DTR2_DTGF_1                     (0x02UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000002 */
#define TIM_DTR2_DTGF_2                     (0x04UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000004 */
#define TIM_DTR2_DTGF_3                     (0x08UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000008 */
#define TIM_DTR2_DTGF_4                     (0x10UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000010 */
#define TIM_DTR2_DTGF_5                     (0x20UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000020 */
#define TIM_DTR2_DTGF_6                     (0x40UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000040 */
#define TIM_DTR2_DTGF_7                     (0x80UL << TIM_DTR2_DTGF_Pos)           /*!< 0x00000080 */
#define TIM_DTR2_DTAE_Pos                   (16U)
#define TIM_DTR2_DTAE_Msk                   (0x1UL << TIM_DTR2_DTAE_Pos)            /*!< 0x00004000 */
#define TIM_DTR2_DTAE                       TIM_DTR2_DTAE_Msk                       /*!<Deadtime asymmetric enable */
#define TIM_DTR2_DTPE_Pos                   (17U)
#define TIM_DTR2_DTPE_Msk                   (0x1UL << TIM_DTR2_DTPE_Pos)            /*!< 0x00008000 */
#define TIM_DTR2_DTPE                       TIM_DTR2_DTPE_Msk                       /*!<Deadtime prelaod enable */

/*******************  Bit definition for TIM_ECR register  *********************/
#define TIM_ECR_IE_Pos                      (0U)
#define TIM_ECR_IE_Msk                      (0x1UL << TIM_ECR_IE_Pos)               /*!< 0x00000001 */
#define TIM_ECR_IE                          TIM_ECR_IE_Msk                          /*!<Index enable */
#define TIM_ECR_IDIR_Pos                    (1U)
#define TIM_ECR_IDIR_Msk                    (0x3UL << TIM_ECR_IDIR_Pos)             /*!< 0x00000006 */
#define TIM_ECR_IDIR                        TIM_ECR_IDIR_Msk                        /*!<IDIR[1:0] bits (Index direction)*/
#define TIM_ECR_IDIR_0                      (0x01UL << TIM_ECR_IDIR_Pos)            /*!< 0x00000001 */
#define TIM_ECR_IDIR_1                      (0x02UL << TIM_ECR_IDIR_Pos)            /*!< 0x00000002 */
#define TIM_ECR_IBLK_Pos                    (3U)
#define TIM_ECR_IBLK_Msk                    (0x3UL << TIM_ECR_IBLK_Pos)             /*!< 0x00000018 */
#define TIM_ECR_IBLK                        TIM_ECR_IBLK_Msk                        /*!<IBLK[1:0] bits (Index blanking)*/
#define TIM_ECR_IBLK_0                      (0x01UL << TIM_ECR_IBLK_Pos)            /*!< 0x00000008 */
#define TIM_ECR_IBLK_1                      (0x02UL << TIM_ECR_IBLK_Pos)            /*!< 0x00000010 */
#define TIM_ECR_FIDX_Pos                    (5U)
#define TIM_ECR_FIDX_Msk                    (0x1UL << TIM_ECR_FIDX_Pos)             /*!< 0x00000020 */
#define TIM_ECR_FIDX                        TIM_ECR_FIDX_Msk                        /*!<First index enable */
#define TIM_ECR_IPOS_Pos                    (6U)
#define TIM_ECR_IPOS_Msk                    (0x3UL << TIM_ECR_IPOS_Pos)             /*!< 0x0000000C0 */
#define TIM_ECR_IPOS                        TIM_ECR_IPOS_Msk                        /*!<IPOS[1:0] bits (Index positioning)*/
#define TIM_ECR_IPOS_0                      (0x01UL << TIM_ECR_IPOS_Pos)            /*!< 0x00000001 */
#define TIM_ECR_IPOS_1                      (0x02UL << TIM_ECR_IPOS_Pos)            /*!< 0x00000002 */
#define TIM_ECR_PW_Pos                      (16U)
#define TIM_ECR_PW_Msk                      (0xFFUL << TIM_ECR_PW_Pos)              /*!< 0x00FF0000 */
#define TIM_ECR_PW                          TIM_ECR_PW_Msk                          /*!<PW[7:0] bits (Pulse width)*/
#define TIM_ECR_PW_0                        (0x01UL << TIM_ECR_PW_Pos)              /*!< 0x00010000 */
#define TIM_ECR_PW_1                        (0x02UL << TIM_ECR_PW_Pos)              /*!< 0x00020000 */
#define TIM_ECR_PW_2                        (0x04UL << TIM_ECR_PW_Pos)              /*!< 0x00040000 */
#define TIM_ECR_PW_3                        (0x08UL << TIM_ECR_PW_Pos)              /*!< 0x00080000 */
#define TIM_ECR_PW_4                        (0x10UL << TIM_ECR_PW_Pos)              /*!< 0x00100000 */
#define TIM_ECR_PW_5                        (0x20UL << TIM_ECR_PW_Pos)              /*!< 0x00200000 */
#define TIM_ECR_PW_6                        (0x40UL << TIM_ECR_PW_Pos)              /*!< 0x00400000 */
#define TIM_ECR_PW_7                        (0x80UL << TIM_ECR_PW_Pos)              /*!< 0x00800000 */
#define TIM_ECR_PWPRSC_Pos                  (24U)
#define TIM_ECR_PWPRSC_Msk                  (0x7UL << TIM_ECR_PWPRSC_Pos)           /*!< 0x07000000 */
#define TIM_ECR_PWPRSC                      TIM_ECR_PWPRSC_Msk                      /*!<PWPRSC[2:0] bits (Pulse width prescaler)*/
#define TIM_ECR_PWPRSC_0                    (0x01UL << TIM_ECR_PWPRSC_Pos)          /*!< 0x01000000 */
#define TIM_ECR_PWPRSC_1                    (0x02UL << TIM_ECR_PWPRSC_Pos)          /*!< 0x02000000 */
#define TIM_ECR_PWPRSC_2                    (0x04UL << TIM_ECR_PWPRSC_Pos)          /*!< 0x04000000 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define TIM_DMAR_DMAB_Pos                   (0U)
#define TIM_DMAR_DMAB_Msk                   (0xFFFFFFFFUL << TIM_DMAR_DMAB_Pos)     /*!< 0xFFFFFFFF */
#define TIM_DMAR_DMAB                       TIM_DMAR_DMAB_Msk                       /*!<DMA register for burst accesses */


/******************************************************************************/
/*                                                                            */
/*                          Touch Sensing Controller (TSC)                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TSC_CR register  *********************/
#define TSC_CR_TSCE_Pos          (0U)
#define TSC_CR_TSCE_Msk          (0x1UL << TSC_CR_TSCE_Pos)                    /*!< 0x00000001 */
#define TSC_CR_TSCE              TSC_CR_TSCE_Msk                               /*!<Touch sensing controller enable */
#define TSC_CR_START_Pos         (1U)
#define TSC_CR_START_Msk         (0x1UL << TSC_CR_START_Pos)                   /*!< 0x00000002 */
#define TSC_CR_START             TSC_CR_START_Msk                              /*!<Start acquisition */
#define TSC_CR_AM_Pos            (2U)
#define TSC_CR_AM_Msk            (0x1UL << TSC_CR_AM_Pos)                      /*!< 0x00000004 */
#define TSC_CR_AM                TSC_CR_AM_Msk                                 /*!<Acquisition mode */
#define TSC_CR_SYNCPOL_Pos       (3U)
#define TSC_CR_SYNCPOL_Msk       (0x1UL << TSC_CR_SYNCPOL_Pos)                 /*!< 0x00000008 */
#define TSC_CR_SYNCPOL           TSC_CR_SYNCPOL_Msk                            /*!<Synchronization pin polarity */
#define TSC_CR_IODEF_Pos         (4U)
#define TSC_CR_IODEF_Msk         (0x1UL << TSC_CR_IODEF_Pos)                   /*!< 0x00000010 */
#define TSC_CR_IODEF             TSC_CR_IODEF_Msk                              /*!<IO default mode */

#define TSC_CR_MCV_Pos           (5U)
#define TSC_CR_MCV_Msk           (0x7UL << TSC_CR_MCV_Pos)                     /*!< 0x000000E0 */
#define TSC_CR_MCV               TSC_CR_MCV_Msk                                /*!<MCV[2:0] bits (Max Count Value) */
#define TSC_CR_MCV_0             (0x1UL << TSC_CR_MCV_Pos)                     /*!< 0x00000020 */
#define TSC_CR_MCV_1             (0x2UL << TSC_CR_MCV_Pos)                     /*!< 0x00000040 */
#define TSC_CR_MCV_2             (0x4UL << TSC_CR_MCV_Pos)                     /*!< 0x00000080 */

#define TSC_CR_PGPSC_Pos         (12U)
#define TSC_CR_PGPSC_Msk         (0x7UL << TSC_CR_PGPSC_Pos)                   /*!< 0x00007000 */
#define TSC_CR_PGPSC             TSC_CR_PGPSC_Msk                              /*!<PGPSC[2:0] bits (Pulse Generator Prescaler) */
#define TSC_CR_PGPSC_0           (0x1UL << TSC_CR_PGPSC_Pos)                   /*!< 0x00001000 */
#define TSC_CR_PGPSC_1           (0x2UL << TSC_CR_PGPSC_Pos)                   /*!< 0x00002000 */
#define TSC_CR_PGPSC_2           (0x4UL << TSC_CR_PGPSC_Pos)                   /*!< 0x00004000 */

#define TSC_CR_SSPSC_Pos         (15U)
#define TSC_CR_SSPSC_Msk         (0x1UL << TSC_CR_SSPSC_Pos)                   /*!< 0x00008000 */
#define TSC_CR_SSPSC             TSC_CR_SSPSC_Msk                              /*!<Spread Spectrum Prescaler */
#define TSC_CR_SSE_Pos           (16U)
#define TSC_CR_SSE_Msk           (0x1UL << TSC_CR_SSE_Pos)                     /*!< 0x00010000 */
#define TSC_CR_SSE               TSC_CR_SSE_Msk                                /*!<Spread Spectrum Enable */

#define TSC_CR_SSD_Pos           (17U)
#define TSC_CR_SSD_Msk           (0x7FUL << TSC_CR_SSD_Pos)                    /*!< 0x00FE0000 */
#define TSC_CR_SSD               TSC_CR_SSD_Msk                                /*!<SSD[6:0] bits (Spread Spectrum Deviation) */
#define TSC_CR_SSD_0             (0x01UL << TSC_CR_SSD_Pos)                    /*!< 0x00020000 */
#define TSC_CR_SSD_1             (0x02UL << TSC_CR_SSD_Pos)                    /*!< 0x00040000 */
#define TSC_CR_SSD_2             (0x04UL << TSC_CR_SSD_Pos)                    /*!< 0x00080000 */
#define TSC_CR_SSD_3             (0x08UL << TSC_CR_SSD_Pos)                    /*!< 0x00100000 */
#define TSC_CR_SSD_4             (0x10UL << TSC_CR_SSD_Pos)                    /*!< 0x00200000 */
#define TSC_CR_SSD_5             (0x20UL << TSC_CR_SSD_Pos)                    /*!< 0x00400000 */
#define TSC_CR_SSD_6             (0x40UL << TSC_CR_SSD_Pos)                    /*!< 0x00800000 */

#define TSC_CR_CTPL_Pos          (24U)
#define TSC_CR_CTPL_Msk          (0xFUL << TSC_CR_CTPL_Pos)                    /*!< 0x0F000000 */
#define TSC_CR_CTPL              TSC_CR_CTPL_Msk                               /*!<CTPL[3:0] bits (Charge Transfer pulse low) */
#define TSC_CR_CTPL_0            (0x1UL << TSC_CR_CTPL_Pos)                    /*!< 0x01000000 */
#define TSC_CR_CTPL_1            (0x2UL << TSC_CR_CTPL_Pos)                    /*!< 0x02000000 */
#define TSC_CR_CTPL_2            (0x4UL << TSC_CR_CTPL_Pos)                    /*!< 0x04000000 */
#define TSC_CR_CTPL_3            (0x8UL << TSC_CR_CTPL_Pos)                    /*!< 0x08000000 */

#define TSC_CR_CTPH_Pos          (28U)
#define TSC_CR_CTPH_Msk          (0xFUL << TSC_CR_CTPH_Pos)                    /*!< 0xF0000000 */
#define TSC_CR_CTPH              TSC_CR_CTPH_Msk                               /*!<CTPH[3:0] bits (Charge Transfer pulse high) */
#define TSC_CR_CTPH_0            (0x1UL << TSC_CR_CTPH_Pos)                    /*!< 0x10000000 */
#define TSC_CR_CTPH_1            (0x2UL << TSC_CR_CTPH_Pos)                    /*!< 0x20000000 */
#define TSC_CR_CTPH_2            (0x4UL << TSC_CR_CTPH_Pos)                    /*!< 0x40000000 */
#define TSC_CR_CTPH_3            (0x8UL << TSC_CR_CTPH_Pos)                    /*!< 0x80000000 */

/*******************  Bit definition for TSC_IER register  ********************/
#define TSC_IER_EOAIE_Pos        (0U)
#define TSC_IER_EOAIE_Msk        (0x1UL << TSC_IER_EOAIE_Pos)                  /*!< 0x00000001 */
#define TSC_IER_EOAIE            TSC_IER_EOAIE_Msk                             /*!<End of acquisition interrupt enable */
#define TSC_IER_MCEIE_Pos        (1U)
#define TSC_IER_MCEIE_Msk        (0x1UL << TSC_IER_MCEIE_Pos)                  /*!< 0x00000002 */
#define TSC_IER_MCEIE            TSC_IER_MCEIE_Msk                             /*!<Max count error interrupt enable */

/*******************  Bit definition for TSC_ICR register  ********************/
#define TSC_ICR_EOAIC_Pos        (0U)
#define TSC_ICR_EOAIC_Msk        (0x1UL << TSC_ICR_EOAIC_Pos)                  /*!< 0x00000001 */
#define TSC_ICR_EOAIC            TSC_ICR_EOAIC_Msk                             /*!<End of acquisition interrupt clear */
#define TSC_ICR_MCEIC_Pos        (1U)
#define TSC_ICR_MCEIC_Msk        (0x1UL << TSC_ICR_MCEIC_Pos)                  /*!< 0x00000002 */
#define TSC_ICR_MCEIC            TSC_ICR_MCEIC_Msk                             /*!<Max count error interrupt clear */

/*******************  Bit definition for TSC_ISR register  ********************/
#define TSC_ISR_EOAF_Pos         (0U)
#define TSC_ISR_EOAF_Msk         (0x1UL << TSC_ISR_EOAF_Pos)                   /*!< 0x00000001 */
#define TSC_ISR_EOAF             TSC_ISR_EOAF_Msk                              /*!<End of acquisition flag */
#define TSC_ISR_MCEF_Pos         (1U)
#define TSC_ISR_MCEF_Msk         (0x1UL << TSC_ISR_MCEF_Pos)                   /*!< 0x00000002 */
#define TSC_ISR_MCEF             TSC_ISR_MCEF_Msk                              /*!<Max count error flag */

/*******************  Bit definition for TSC_IOHCR register  ******************/
#define TSC_IOHCR_G1_IO1_Pos     (0U)
#define TSC_IOHCR_G1_IO1_Msk     (0x1UL << TSC_IOHCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOHCR_G1_IO1         TSC_IOHCR_G1_IO1_Msk                          /*!<GROUP1_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO2_Pos     (1U)
#define TSC_IOHCR_G1_IO2_Msk     (0x1UL << TSC_IOHCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOHCR_G1_IO2         TSC_IOHCR_G1_IO2_Msk                          /*!<GROUP1_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO3_Pos     (2U)
#define TSC_IOHCR_G1_IO3_Msk     (0x1UL << TSC_IOHCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOHCR_G1_IO3         TSC_IOHCR_G1_IO3_Msk                          /*!<GROUP1_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO4_Pos     (3U)
#define TSC_IOHCR_G1_IO4_Msk     (0x1UL << TSC_IOHCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOHCR_G1_IO4         TSC_IOHCR_G1_IO4_Msk                          /*!<GROUP1_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO1_Pos     (4U)
#define TSC_IOHCR_G2_IO1_Msk     (0x1UL << TSC_IOHCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOHCR_G2_IO1         TSC_IOHCR_G2_IO1_Msk                          /*!<GROUP2_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO2_Pos     (5U)
#define TSC_IOHCR_G2_IO2_Msk     (0x1UL << TSC_IOHCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOHCR_G2_IO2         TSC_IOHCR_G2_IO2_Msk                          /*!<GROUP2_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO3_Pos     (6U)
#define TSC_IOHCR_G2_IO3_Msk     (0x1UL << TSC_IOHCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOHCR_G2_IO3         TSC_IOHCR_G2_IO3_Msk                          /*!<GROUP2_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO4_Pos     (7U)
#define TSC_IOHCR_G2_IO4_Msk     (0x1UL << TSC_IOHCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOHCR_G2_IO4         TSC_IOHCR_G2_IO4_Msk                          /*!<GROUP2_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO1_Pos     (8U)
#define TSC_IOHCR_G3_IO1_Msk     (0x1UL << TSC_IOHCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOHCR_G3_IO1         TSC_IOHCR_G3_IO1_Msk                          /*!<GROUP3_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO2_Pos     (9U)
#define TSC_IOHCR_G3_IO2_Msk     (0x1UL << TSC_IOHCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOHCR_G3_IO2         TSC_IOHCR_G3_IO2_Msk                          /*!<GROUP3_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO3_Pos     (10U)
#define TSC_IOHCR_G3_IO3_Msk     (0x1UL << TSC_IOHCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOHCR_G3_IO3         TSC_IOHCR_G3_IO3_Msk                          /*!<GROUP3_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO4_Pos     (11U)
#define TSC_IOHCR_G3_IO4_Msk     (0x1UL << TSC_IOHCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOHCR_G3_IO4         TSC_IOHCR_G3_IO4_Msk                          /*!<GROUP3_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO1_Pos     (12U)
#define TSC_IOHCR_G4_IO1_Msk     (0x1UL << TSC_IOHCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOHCR_G4_IO1         TSC_IOHCR_G4_IO1_Msk                          /*!<GROUP4_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO2_Pos     (13U)
#define TSC_IOHCR_G4_IO2_Msk     (0x1UL << TSC_IOHCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOHCR_G4_IO2         TSC_IOHCR_G4_IO2_Msk                          /*!<GROUP4_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO3_Pos     (14U)
#define TSC_IOHCR_G4_IO3_Msk     (0x1UL << TSC_IOHCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOHCR_G4_IO3         TSC_IOHCR_G4_IO3_Msk                          /*!<GROUP4_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO4_Pos     (15U)
#define TSC_IOHCR_G4_IO4_Msk     (0x1UL << TSC_IOHCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOHCR_G4_IO4         TSC_IOHCR_G4_IO4_Msk                          /*!<GROUP4_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO1_Pos     (16U)
#define TSC_IOHCR_G5_IO1_Msk     (0x1UL << TSC_IOHCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOHCR_G5_IO1         TSC_IOHCR_G5_IO1_Msk                          /*!<GROUP5_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO2_Pos     (17U)
#define TSC_IOHCR_G5_IO2_Msk     (0x1UL << TSC_IOHCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOHCR_G5_IO2         TSC_IOHCR_G5_IO2_Msk                          /*!<GROUP5_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO3_Pos     (18U)
#define TSC_IOHCR_G5_IO3_Msk     (0x1UL << TSC_IOHCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOHCR_G5_IO3         TSC_IOHCR_G5_IO3_Msk                          /*!<GROUP5_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO4_Pos     (19U)
#define TSC_IOHCR_G5_IO4_Msk     (0x1UL << TSC_IOHCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOHCR_G5_IO4         TSC_IOHCR_G5_IO4_Msk                          /*!<GROUP5_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO1_Pos     (20U)
#define TSC_IOHCR_G6_IO1_Msk     (0x1UL << TSC_IOHCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOHCR_G6_IO1         TSC_IOHCR_G6_IO1_Msk                          /*!<GROUP6_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO2_Pos     (21U)
#define TSC_IOHCR_G6_IO2_Msk     (0x1UL << TSC_IOHCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOHCR_G6_IO2         TSC_IOHCR_G6_IO2_Msk                          /*!<GROUP6_IO2 schmitt trigger hysteresis mode */

/*******************  Bit definition for TSC_IOASCR register  *****************/
#define TSC_IOASCR_G1_IO1_Pos    (0U)
#define TSC_IOASCR_G1_IO1_Msk    (0x1UL << TSC_IOASCR_G1_IO1_Pos)              /*!< 0x00000001 */
#define TSC_IOASCR_G1_IO1        TSC_IOASCR_G1_IO1_Msk                         /*!<GROUP1_IO1 analog switch enable */
#define TSC_IOASCR_G1_IO2_Pos    (1U)
#define TSC_IOASCR_G1_IO2_Msk    (0x1UL << TSC_IOASCR_G1_IO2_Pos)              /*!< 0x00000002 */
#define TSC_IOASCR_G1_IO2        TSC_IOASCR_G1_IO2_Msk                         /*!<GROUP1_IO2 analog switch enable */
#define TSC_IOASCR_G1_IO3_Pos    (2U)
#define TSC_IOASCR_G1_IO3_Msk    (0x1UL << TSC_IOASCR_G1_IO3_Pos)              /*!< 0x00000004 */
#define TSC_IOASCR_G1_IO3        TSC_IOASCR_G1_IO3_Msk                         /*!<GROUP1_IO3 analog switch enable */
#define TSC_IOASCR_G1_IO4_Pos    (3U)
#define TSC_IOASCR_G1_IO4_Msk    (0x1UL << TSC_IOASCR_G1_IO4_Pos)              /*!< 0x00000008 */
#define TSC_IOASCR_G1_IO4        TSC_IOASCR_G1_IO4_Msk                         /*!<GROUP1_IO4 analog switch enable */
#define TSC_IOASCR_G2_IO1_Pos    (4U)
#define TSC_IOASCR_G2_IO1_Msk    (0x1UL << TSC_IOASCR_G2_IO1_Pos)              /*!< 0x00000010 */
#define TSC_IOASCR_G2_IO1        TSC_IOASCR_G2_IO1_Msk                         /*!<GROUP2_IO1 analog switch enable */
#define TSC_IOASCR_G2_IO2_Pos    (5U)
#define TSC_IOASCR_G2_IO2_Msk    (0x1UL << TSC_IOASCR_G2_IO2_Pos)              /*!< 0x00000020 */
#define TSC_IOASCR_G2_IO2        TSC_IOASCR_G2_IO2_Msk                         /*!<GROUP2_IO2 analog switch enable */
#define TSC_IOASCR_G2_IO3_Pos    (6U)
#define TSC_IOASCR_G2_IO3_Msk    (0x1UL << TSC_IOASCR_G2_IO3_Pos)              /*!< 0x00000040 */
#define TSC_IOASCR_G2_IO3        TSC_IOASCR_G2_IO3_Msk                         /*!<GROUP2_IO3 analog switch enable */
#define TSC_IOASCR_G2_IO4_Pos    (7U)
#define TSC_IOASCR_G2_IO4_Msk    (0x1UL << TSC_IOASCR_G2_IO4_Pos)              /*!< 0x00000080 */
#define TSC_IOASCR_G2_IO4        TSC_IOASCR_G2_IO4_Msk                         /*!<GROUP2_IO4 analog switch enable */
#define TSC_IOASCR_G3_IO1_Pos    (8U)
#define TSC_IOASCR_G3_IO1_Msk    (0x1UL << TSC_IOASCR_G3_IO1_Pos)              /*!< 0x00000100 */
#define TSC_IOASCR_G3_IO1        TSC_IOASCR_G3_IO1_Msk                         /*!<GROUP3_IO1 analog switch enable */
#define TSC_IOASCR_G3_IO2_Pos    (9U)
#define TSC_IOASCR_G3_IO2_Msk    (0x1UL << TSC_IOASCR_G3_IO2_Pos)              /*!< 0x00000200 */
#define TSC_IOASCR_G3_IO2        TSC_IOASCR_G3_IO2_Msk                         /*!<GROUP3_IO2 analog switch enable */
#define TSC_IOASCR_G3_IO3_Pos    (10U)
#define TSC_IOASCR_G3_IO3_Msk    (0x1UL << TSC_IOASCR_G3_IO3_Pos)              /*!< 0x00000400 */
#define TSC_IOASCR_G3_IO3        TSC_IOASCR_G3_IO3_Msk                         /*!<GROUP3_IO3 analog switch enable */
#define TSC_IOASCR_G3_IO4_Pos    (11U)
#define TSC_IOASCR_G3_IO4_Msk    (0x1UL << TSC_IOASCR_G3_IO4_Pos)              /*!< 0x00000800 */
#define TSC_IOASCR_G3_IO4        TSC_IOASCR_G3_IO4_Msk                         /*!<GROUP3_IO4 analog switch enable */
#define TSC_IOASCR_G4_IO1_Pos    (12U)
#define TSC_IOASCR_G4_IO1_Msk    (0x1UL << TSC_IOASCR_G4_IO1_Pos)              /*!< 0x00001000 */
#define TSC_IOASCR_G4_IO1        TSC_IOASCR_G4_IO1_Msk                         /*!<GROUP4_IO1 analog switch enable */
#define TSC_IOASCR_G4_IO2_Pos    (13U)
#define TSC_IOASCR_G4_IO2_Msk    (0x1UL << TSC_IOASCR_G4_IO2_Pos)              /*!< 0x00002000 */
#define TSC_IOASCR_G4_IO2        TSC_IOASCR_G4_IO2_Msk                         /*!<GROUP4_IO2 analog switch enable */
#define TSC_IOASCR_G4_IO3_Pos    (14U)
#define TSC_IOASCR_G4_IO3_Msk    (0x1UL << TSC_IOASCR_G4_IO3_Pos)              /*!< 0x00004000 */
#define TSC_IOASCR_G4_IO3        TSC_IOASCR_G4_IO3_Msk                         /*!<GROUP4_IO3 analog switch enable */
#define TSC_IOASCR_G4_IO4_Pos    (15U)
#define TSC_IOASCR_G4_IO4_Msk    (0x1UL << TSC_IOASCR_G4_IO4_Pos)              /*!< 0x00008000 */
#define TSC_IOASCR_G4_IO4        TSC_IOASCR_G4_IO4_Msk                         /*!<GROUP4_IO4 analog switch enable */
#define TSC_IOASCR_G5_IO1_Pos    (16U)
#define TSC_IOASCR_G5_IO1_Msk    (0x1UL << TSC_IOASCR_G5_IO1_Pos)              /*!< 0x00010000 */
#define TSC_IOASCR_G5_IO1        TSC_IOASCR_G5_IO1_Msk                         /*!<GROUP5_IO1 analog switch enable */
#define TSC_IOASCR_G5_IO2_Pos    (17U)
#define TSC_IOASCR_G5_IO2_Msk    (0x1UL << TSC_IOASCR_G5_IO2_Pos)              /*!< 0x00020000 */
#define TSC_IOASCR_G5_IO2        TSC_IOASCR_G5_IO2_Msk                         /*!<GROUP5_IO2 analog switch enable */
#define TSC_IOASCR_G5_IO3_Pos    (18U)
#define TSC_IOASCR_G5_IO3_Msk    (0x1UL << TSC_IOASCR_G5_IO3_Pos)              /*!< 0x00040000 */
#define TSC_IOASCR_G5_IO3        TSC_IOASCR_G5_IO3_Msk                         /*!<GROUP5_IO3 analog switch enable */
#define TSC_IOASCR_G5_IO4_Pos    (19U)
#define TSC_IOASCR_G5_IO4_Msk    (0x1UL << TSC_IOASCR_G5_IO4_Pos)              /*!< 0x00080000 */
#define TSC_IOASCR_G5_IO4        TSC_IOASCR_G5_IO4_Msk                         /*!<GROUP5_IO4 analog switch enable */
#define TSC_IOASCR_G6_IO1_Pos    (20U)
#define TSC_IOASCR_G6_IO1_Msk    (0x1UL << TSC_IOASCR_G6_IO1_Pos)              /*!< 0x00100000 */
#define TSC_IOASCR_G6_IO1        TSC_IOASCR_G6_IO1_Msk                         /*!<GROUP6_IO1 analog switch enable */
#define TSC_IOASCR_G6_IO2_Pos    (21U)
#define TSC_IOASCR_G6_IO2_Msk    (0x1UL << TSC_IOASCR_G6_IO2_Pos)              /*!< 0x00200000 */
#define TSC_IOASCR_G6_IO2        TSC_IOASCR_G6_IO2_Msk                         /*!<GROUP6_IO2 analog switch enable */

/*******************  Bit definition for TSC_IOSCR register  ******************/
#define TSC_IOSCR_G1_IO1_Pos     (0U)
#define TSC_IOSCR_G1_IO1_Msk     (0x1UL << TSC_IOSCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOSCR_G1_IO1         TSC_IOSCR_G1_IO1_Msk                          /*!<GROUP1_IO1 sampling mode */
#define TSC_IOSCR_G1_IO2_Pos     (1U)
#define TSC_IOSCR_G1_IO2_Msk     (0x1UL << TSC_IOSCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOSCR_G1_IO2         TSC_IOSCR_G1_IO2_Msk                          /*!<GROUP1_IO2 sampling mode */
#define TSC_IOSCR_G1_IO3_Pos     (2U)
#define TSC_IOSCR_G1_IO3_Msk     (0x1UL << TSC_IOSCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOSCR_G1_IO3         TSC_IOSCR_G1_IO3_Msk                          /*!<GROUP1_IO3 sampling mode */
#define TSC_IOSCR_G1_IO4_Pos     (3U)
#define TSC_IOSCR_G1_IO4_Msk     (0x1UL << TSC_IOSCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOSCR_G1_IO4         TSC_IOSCR_G1_IO4_Msk                          /*!<GROUP1_IO4 sampling mode */
#define TSC_IOSCR_G2_IO1_Pos     (4U)
#define TSC_IOSCR_G2_IO1_Msk     (0x1UL << TSC_IOSCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOSCR_G2_IO1         TSC_IOSCR_G2_IO1_Msk                          /*!<GROUP2_IO1 sampling mode */
#define TSC_IOSCR_G2_IO2_Pos     (5U)
#define TSC_IOSCR_G2_IO2_Msk     (0x1UL << TSC_IOSCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOSCR_G2_IO2         TSC_IOSCR_G2_IO2_Msk                          /*!<GROUP2_IO2 sampling mode */
#define TSC_IOSCR_G2_IO3_Pos     (6U)
#define TSC_IOSCR_G2_IO3_Msk     (0x1UL << TSC_IOSCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOSCR_G2_IO3         TSC_IOSCR_G2_IO3_Msk                          /*!<GROUP2_IO3 sampling mode */
#define TSC_IOSCR_G2_IO4_Pos     (7U)
#define TSC_IOSCR_G2_IO4_Msk     (0x1UL << TSC_IOSCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOSCR_G2_IO4         TSC_IOSCR_G2_IO4_Msk                          /*!<GROUP2_IO4 sampling mode */
#define TSC_IOSCR_G3_IO1_Pos     (8U)
#define TSC_IOSCR_G3_IO1_Msk     (0x1UL << TSC_IOSCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOSCR_G3_IO1         TSC_IOSCR_G3_IO1_Msk                          /*!<GROUP3_IO1 sampling mode */
#define TSC_IOSCR_G3_IO2_Pos     (9U)
#define TSC_IOSCR_G3_IO2_Msk     (0x1UL << TSC_IOSCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOSCR_G3_IO2         TSC_IOSCR_G3_IO2_Msk                          /*!<GROUP3_IO2 sampling mode */
#define TSC_IOSCR_G3_IO3_Pos     (10U)
#define TSC_IOSCR_G3_IO3_Msk     (0x1UL << TSC_IOSCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOSCR_G3_IO3         TSC_IOSCR_G3_IO3_Msk                          /*!<GROUP3_IO3 sampling mode */
#define TSC_IOSCR_G3_IO4_Pos     (11U)
#define TSC_IOSCR_G3_IO4_Msk     (0x1UL << TSC_IOSCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOSCR_G3_IO4         TSC_IOSCR_G3_IO4_Msk                          /*!<GROUP3_IO4 sampling mode */
#define TSC_IOSCR_G4_IO1_Pos     (12U)
#define TSC_IOSCR_G4_IO1_Msk     (0x1UL << TSC_IOSCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOSCR_G4_IO1         TSC_IOSCR_G4_IO1_Msk                          /*!<GROUP4_IO1 sampling mode */
#define TSC_IOSCR_G4_IO2_Pos     (13U)
#define TSC_IOSCR_G4_IO2_Msk     (0x1UL << TSC_IOSCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOSCR_G4_IO2         TSC_IOSCR_G4_IO2_Msk                          /*!<GROUP4_IO2 sampling mode */
#define TSC_IOSCR_G4_IO3_Pos     (14U)
#define TSC_IOSCR_G4_IO3_Msk     (0x1UL << TSC_IOSCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOSCR_G4_IO3         TSC_IOSCR_G4_IO3_Msk                          /*!<GROUP4_IO3 sampling mode */
#define TSC_IOSCR_G4_IO4_Pos     (15U)
#define TSC_IOSCR_G4_IO4_Msk     (0x1UL << TSC_IOSCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOSCR_G4_IO4         TSC_IOSCR_G4_IO4_Msk                          /*!<GROUP4_IO4 sampling mode */
#define TSC_IOSCR_G5_IO1_Pos     (16U)
#define TSC_IOSCR_G5_IO1_Msk     (0x1UL << TSC_IOSCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOSCR_G5_IO1         TSC_IOSCR_G5_IO1_Msk                          /*!<GROUP5_IO1 sampling mode */
#define TSC_IOSCR_G5_IO2_Pos     (17U)
#define TSC_IOSCR_G5_IO2_Msk     (0x1UL << TSC_IOSCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOSCR_G5_IO2         TSC_IOSCR_G5_IO2_Msk                          /*!<GROUP5_IO2 sampling mode */
#define TSC_IOSCR_G5_IO3_Pos     (18U)
#define TSC_IOSCR_G5_IO3_Msk     (0x1UL << TSC_IOSCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOSCR_G5_IO3         TSC_IOSCR_G5_IO3_Msk                          /*!<GROUP5_IO3 sampling mode */
#define TSC_IOSCR_G5_IO4_Pos     (19U)
#define TSC_IOSCR_G5_IO4_Msk     (0x1UL << TSC_IOSCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOSCR_G5_IO4         TSC_IOSCR_G5_IO4_Msk                          /*!<GROUP5_IO4 sampling mode */
#define TSC_IOSCR_G6_IO1_Pos     (20U)
#define TSC_IOSCR_G6_IO1_Msk     (0x1UL << TSC_IOSCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOSCR_G6_IO1         TSC_IOSCR_G6_IO1_Msk                          /*!<GROUP6_IO1 sampling mode */
#define TSC_IOSCR_G6_IO2_Pos     (21U)
#define TSC_IOSCR_G6_IO2_Msk     (0x1UL << TSC_IOSCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOSCR_G6_IO2         TSC_IOSCR_G6_IO2_Msk                          /*!<GROUP6_IO2 sampling mode */

/*******************  Bit definition for TSC_IOCCR register  ******************/
#define TSC_IOCCR_G1_IO1_Pos     (0U)
#define TSC_IOCCR_G1_IO1_Msk     (0x1UL << TSC_IOCCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOCCR_G1_IO1         TSC_IOCCR_G1_IO1_Msk                          /*!<GROUP1_IO1 channel mode */
#define TSC_IOCCR_G1_IO2_Pos     (1U)
#define TSC_IOCCR_G1_IO2_Msk     (0x1UL << TSC_IOCCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOCCR_G1_IO2         TSC_IOCCR_G1_IO2_Msk                          /*!<GROUP1_IO2 channel mode */
#define TSC_IOCCR_G1_IO3_Pos     (2U)
#define TSC_IOCCR_G1_IO3_Msk     (0x1UL << TSC_IOCCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOCCR_G1_IO3         TSC_IOCCR_G1_IO3_Msk                          /*!<GROUP1_IO3 channel mode */
#define TSC_IOCCR_G1_IO4_Pos     (3U)
#define TSC_IOCCR_G1_IO4_Msk     (0x1UL << TSC_IOCCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOCCR_G1_IO4         TSC_IOCCR_G1_IO4_Msk                          /*!<GROUP1_IO4 channel mode */
#define TSC_IOCCR_G2_IO1_Pos     (4U)
#define TSC_IOCCR_G2_IO1_Msk     (0x1UL << TSC_IOCCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOCCR_G2_IO1         TSC_IOCCR_G2_IO1_Msk                          /*!<GROUP2_IO1 channel mode */
#define TSC_IOCCR_G2_IO2_Pos     (5U)
#define TSC_IOCCR_G2_IO2_Msk     (0x1UL << TSC_IOCCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOCCR_G2_IO2         TSC_IOCCR_G2_IO2_Msk                          /*!<GROUP2_IO2 channel mode */
#define TSC_IOCCR_G2_IO3_Pos     (6U)
#define TSC_IOCCR_G2_IO3_Msk     (0x1UL << TSC_IOCCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOCCR_G2_IO3         TSC_IOCCR_G2_IO3_Msk                          /*!<GROUP2_IO3 channel mode */
#define TSC_IOCCR_G2_IO4_Pos     (7U)
#define TSC_IOCCR_G2_IO4_Msk     (0x1UL << TSC_IOCCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOCCR_G2_IO4         TSC_IOCCR_G2_IO4_Msk                          /*!<GROUP2_IO4 channel mode */
#define TSC_IOCCR_G3_IO1_Pos     (8U)
#define TSC_IOCCR_G3_IO1_Msk     (0x1UL << TSC_IOCCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOCCR_G3_IO1         TSC_IOCCR_G3_IO1_Msk                          /*!<GROUP3_IO1 channel mode */
#define TSC_IOCCR_G3_IO2_Pos     (9U)
#define TSC_IOCCR_G3_IO2_Msk     (0x1UL << TSC_IOCCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOCCR_G3_IO2         TSC_IOCCR_G3_IO2_Msk                          /*!<GROUP3_IO2 channel mode */
#define TSC_IOCCR_G3_IO3_Pos     (10U)
#define TSC_IOCCR_G3_IO3_Msk     (0x1UL << TSC_IOCCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOCCR_G3_IO3         TSC_IOCCR_G3_IO3_Msk                          /*!<GROUP3_IO3 channel mode */
#define TSC_IOCCR_G3_IO4_Pos     (11U)
#define TSC_IOCCR_G3_IO4_Msk     (0x1UL << TSC_IOCCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOCCR_G3_IO4         TSC_IOCCR_G3_IO4_Msk                          /*!<GROUP3_IO4 channel mode */
#define TSC_IOCCR_G4_IO1_Pos     (12U)
#define TSC_IOCCR_G4_IO1_Msk     (0x1UL << TSC_IOCCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOCCR_G4_IO1         TSC_IOCCR_G4_IO1_Msk                          /*!<GROUP4_IO1 channel mode */
#define TSC_IOCCR_G4_IO2_Pos     (13U)
#define TSC_IOCCR_G4_IO2_Msk     (0x1UL << TSC_IOCCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOCCR_G4_IO2         TSC_IOCCR_G4_IO2_Msk                          /*!<GROUP4_IO2 channel mode */
#define TSC_IOCCR_G4_IO3_Pos     (14U)
#define TSC_IOCCR_G4_IO3_Msk     (0x1UL << TSC_IOCCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOCCR_G4_IO3         TSC_IOCCR_G4_IO3_Msk                          /*!<GROUP4_IO3 channel mode */
#define TSC_IOCCR_G4_IO4_Pos     (15U)
#define TSC_IOCCR_G4_IO4_Msk     (0x1UL << TSC_IOCCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOCCR_G4_IO4         TSC_IOCCR_G4_IO4_Msk                          /*!<GROUP4_IO4 channel mode */
#define TSC_IOCCR_G5_IO1_Pos     (16U)
#define TSC_IOCCR_G5_IO1_Msk     (0x1UL << TSC_IOCCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOCCR_G5_IO1         TSC_IOCCR_G5_IO1_Msk                          /*!<GROUP5_IO1 channel mode */
#define TSC_IOCCR_G5_IO2_Pos     (17U)
#define TSC_IOCCR_G5_IO2_Msk     (0x1UL << TSC_IOCCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOCCR_G5_IO2         TSC_IOCCR_G5_IO2_Msk                          /*!<GROUP5_IO2 channel mode */
#define TSC_IOCCR_G5_IO3_Pos     (18U)
#define TSC_IOCCR_G5_IO3_Msk     (0x1UL << TSC_IOCCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOCCR_G5_IO3         TSC_IOCCR_G5_IO3_Msk                          /*!<GROUP5_IO3 channel mode */
#define TSC_IOCCR_G5_IO4_Pos     (19U)
#define TSC_IOCCR_G5_IO4_Msk     (0x1UL << TSC_IOCCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOCCR_G5_IO4         TSC_IOCCR_G5_IO4_Msk                          /*!<GROUP5_IO4 channel mode */
#define TSC_IOCCR_G6_IO1_Pos     (20U)
#define TSC_IOCCR_G6_IO1_Msk     (0x1UL << TSC_IOCCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOCCR_G6_IO1         TSC_IOCCR_G6_IO1_Msk                          /*!<GROUP6_IO1 channel mode */
#define TSC_IOCCR_G6_IO2_Pos     (21U)
#define TSC_IOCCR_G6_IO2_Msk     (0x1UL << TSC_IOCCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOCCR_G6_IO2         TSC_IOCCR_G6_IO2_Msk                          /*!<GROUP6_IO2 channel mode */

/*******************  Bit definition for TSC_IOGCSR register  *****************/
#define TSC_IOGCSR_G1E_Pos       (0U)
#define TSC_IOGCSR_G1E_Msk       (0x1UL << TSC_IOGCSR_G1E_Pos)                 /*!< 0x00000001 */
#define TSC_IOGCSR_G1E           TSC_IOGCSR_G1E_Msk                            /*!<Analog IO GROUP1 enable */
#define TSC_IOGCSR_G2E_Pos       (1U)
#define TSC_IOGCSR_G2E_Msk       (0x1UL << TSC_IOGCSR_G2E_Pos)                 /*!< 0x00000002 */
#define TSC_IOGCSR_G2E           TSC_IOGCSR_G2E_Msk                            /*!<Analog IO GROUP2 enable */
#define TSC_IOGCSR_G3E_Pos       (2U)
#define TSC_IOGCSR_G3E_Msk       (0x1UL << TSC_IOGCSR_G3E_Pos)                 /*!< 0x00000004 */
#define TSC_IOGCSR_G3E           TSC_IOGCSR_G3E_Msk                            /*!<Analog IO GROUP3 enable */
#define TSC_IOGCSR_G4E_Pos       (3U)
#define TSC_IOGCSR_G4E_Msk       (0x1UL << TSC_IOGCSR_G4E_Pos)                 /*!< 0x00000008 */
#define TSC_IOGCSR_G4E           TSC_IOGCSR_G4E_Msk                            /*!<Analog IO GROUP4 enable */
#define TSC_IOGCSR_G5E_Pos       (4U)
#define TSC_IOGCSR_G5E_Msk       (0x1UL << TSC_IOGCSR_G5E_Pos)                 /*!< 0x00000010 */
#define TSC_IOGCSR_G5E           TSC_IOGCSR_G5E_Msk                            /*!<Analog IO GROUP5 enable */
#define TSC_IOGCSR_G6E_Pos       (5U)
#define TSC_IOGCSR_G6E_Msk       (0x1UL << TSC_IOGCSR_G6E_Pos)                 /*!< 0x00000020 */
#define TSC_IOGCSR_G6E           TSC_IOGCSR_G6E_Msk                            /*!<Analog IO GROUP6 enable */
#define TSC_IOGCSR_G1S_Pos       (16U)
#define TSC_IOGCSR_G1S_Msk       (0x1UL << TSC_IOGCSR_G1S_Pos)                 /*!< 0x00010000 */
#define TSC_IOGCSR_G1S           TSC_IOGCSR_G1S_Msk                            /*!<Analog IO GROUP1 status */
#define TSC_IOGCSR_G2S_Pos       (17U)
#define TSC_IOGCSR_G2S_Msk       (0x1UL << TSC_IOGCSR_G2S_Pos)                 /*!< 0x00020000 */
#define TSC_IOGCSR_G2S           TSC_IOGCSR_G2S_Msk                            /*!<Analog IO GROUP2 status */
#define TSC_IOGCSR_G3S_Pos       (18U)
#define TSC_IOGCSR_G3S_Msk       (0x1UL << TSC_IOGCSR_G3S_Pos)                 /*!< 0x00040000 */
#define TSC_IOGCSR_G3S           TSC_IOGCSR_G3S_Msk                            /*!<Analog IO GROUP3 status */
#define TSC_IOGCSR_G4S_Pos       (19U)
#define TSC_IOGCSR_G4S_Msk       (0x1UL << TSC_IOGCSR_G4S_Pos)                 /*!< 0x00080000 */
#define TSC_IOGCSR_G4S           TSC_IOGCSR_G4S_Msk                            /*!<Analog IO GROUP4 status */
#define TSC_IOGCSR_G5S_Pos       (20U)
#define TSC_IOGCSR_G5S_Msk       (0x1UL << TSC_IOGCSR_G5S_Pos)                 /*!< 0x00100000 */
#define TSC_IOGCSR_G5S           TSC_IOGCSR_G5S_Msk                            /*!<Analog IO GROUP5 status */
#define TSC_IOGCSR_G6S_Pos       (21U)
#define TSC_IOGCSR_G6S_Msk       (0x1UL << TSC_IOGCSR_G6S_Pos)                 /*!< 0x00200000 */
#define TSC_IOGCSR_G6S           TSC_IOGCSR_G6S_Msk                            /*!<Analog IO GROUP6 status */

/*******************  Bit definition for TSC_IOGXCR register  *****************/
#define TSC_IOGXCR_CNT_Pos       (0U)
#define TSC_IOGXCR_CNT_Msk       (0x3FFFUL << TSC_IOGXCR_CNT_Pos)              /*!< 0x00003FFF */
#define TSC_IOGXCR_CNT           TSC_IOGXCR_CNT_Msk                            /*!<CNT[13:0] bits (Counter value) */


/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_UE_Pos                    (0U)
#define USART_CR1_UE_Msk                    (0x1UL << USART_CR1_UE_Pos)             /*!< 0x00000001 */
#define USART_CR1_UE                        USART_CR1_UE_Msk                        /*!< USART Enable */
#define USART_CR1_UESM_Pos                  (1U)
#define USART_CR1_UESM_Msk                  (0x1UL << USART_CR1_UESM_Pos)           /*!< 0x00000002 */
#define USART_CR1_UESM                      USART_CR1_UESM_Msk                      /*!< USART Enable in STOP Mode */
#define USART_CR1_RE_Pos                    (2U)
#define USART_CR1_RE_Msk                    (0x1UL << USART_CR1_RE_Pos)             /*!< 0x00000004 */
#define USART_CR1_RE                        USART_CR1_RE_Msk                        /*!< Receiver Enable */
#define USART_CR1_TE_Pos                    (3U)
#define USART_CR1_TE_Msk                    (0x1UL << USART_CR1_TE_Pos)             /*!< 0x00000008 */
#define USART_CR1_TE                        USART_CR1_TE_Msk                        /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos                (4U)
#define USART_CR1_IDLEIE_Msk                (0x1UL << USART_CR1_IDLEIE_Pos)         /*!< 0x00000010 */
#define USART_CR1_IDLEIE                    USART_CR1_IDLEIE_Msk                    /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos                (5U)
#define USART_CR1_RXNEIE_Msk                (0x1UL << USART_CR1_RXNEIE_Pos)         /*!< 0x00000020 */
#define USART_CR1_RXNEIE                    USART_CR1_RXNEIE_Msk                    /*!< RXNE Interrupt Enable */
#define USART_CR1_RXNEIE_RXFNEIE_Pos        USART_CR1_RXNEIE_Pos
#define USART_CR1_RXNEIE_RXFNEIE_Msk        USART_CR1_RXNEIE_Msk                    /*!< 0x00000020 */
#define USART_CR1_RXNEIE_RXFNEIE            USART_CR1_RXNEIE_Msk                    /*!< RXNE and RX FIFO Not Empty Interrupt Enable */
#define USART_CR1_TCIE_Pos                  (6U)
#define USART_CR1_TCIE_Msk                  (0x1UL << USART_CR1_TCIE_Pos)           /*!< 0x00000040 */
#define USART_CR1_TCIE                      USART_CR1_TCIE_Msk                      /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos                 (7U)
#define USART_CR1_TXEIE_Msk                 (0x1UL << USART_CR1_TXEIE_Pos)          /*!< 0x00000080 */
#define USART_CR1_TXEIE                     USART_CR1_TXEIE_Msk                     /*!< TXE Interrupt Enable */
#define USART_CR1_TXEIE_TXFNFIE_Pos         (7U)
#define USART_CR1_TXEIE_TXFNFIE_Msk         (0x1UL << USART_CR1_TXEIE_Pos)          /*!< 0x00000080 */
#define USART_CR1_TXEIE_TXFNFIE             USART_CR1_TXEIE                         /*!< TXE and TX FIFO Not Full Interrupt Enable */
#define USART_CR1_PEIE_Pos                  (8U)
#define USART_CR1_PEIE_Msk                  (0x1UL << USART_CR1_PEIE_Pos)           /*!< 0x00000100 */
#define USART_CR1_PEIE                      USART_CR1_PEIE_Msk                      /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos                    (9U)
#define USART_CR1_PS_Msk                    (0x1UL << USART_CR1_PS_Pos)             /*!< 0x00000200 */
#define USART_CR1_PS                        USART_CR1_PS_Msk                        /*!< Parity Selection */
#define USART_CR1_PCE_Pos                   (10U)
#define USART_CR1_PCE_Msk                   (0x1UL << USART_CR1_PCE_Pos)            /*!< 0x00000400 */
#define USART_CR1_PCE                       USART_CR1_PCE_Msk                       /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos                  (11U)
#define USART_CR1_WAKE_Msk                  (0x1UL << USART_CR1_WAKE_Pos)           /*!< 0x00000800 */
#define USART_CR1_WAKE                      USART_CR1_WAKE_Msk                      /*!< Receiver Wakeup method */
#define USART_CR1_M_Pos                     (12U)
#define USART_CR1_M_Msk                     (0x10001UL << USART_CR1_M_Pos)          /*!< 0x10001000 */
#define USART_CR1_M                         USART_CR1_M_Msk                         /*!< Word length */
#define USART_CR1_M0_Pos                    (12U)
#define USART_CR1_M0_Msk                    (0x1UL << USART_CR1_M0_Pos)             /*!< 0x00001000 */
#define USART_CR1_M0                        USART_CR1_M0_Msk                        /*!< Word length - Bit 0 */
#define USART_CR1_MME_Pos                   (13U)
#define USART_CR1_MME_Msk                   (0x1UL << USART_CR1_MME_Pos)            /*!< 0x00002000 */
#define USART_CR1_MME                       USART_CR1_MME_Msk                       /*!< Mute Mode Enable */
#define USART_CR1_CMIE_Pos                  (14U)
#define USART_CR1_CMIE_Msk                  (0x1UL << USART_CR1_CMIE_Pos)           /*!< 0x00004000 */
#define USART_CR1_CMIE                      USART_CR1_CMIE_Msk                      /*!< Character match interrupt enable */
#define USART_CR1_OVER8_Pos                 (15U)
#define USART_CR1_OVER8_Msk                 (0x1UL << USART_CR1_OVER8_Pos)          /*!< 0x00008000 */
#define USART_CR1_OVER8                     USART_CR1_OVER8_Msk                     /*!< Oversampling by 8-bit or 16-bit mode */
#define USART_CR1_DEDT_Pos                  (16U)
#define USART_CR1_DEDT_Msk                  (0x1FUL << USART_CR1_DEDT_Pos)          /*!< 0x001F0000 */
#define USART_CR1_DEDT                      USART_CR1_DEDT_Msk                      /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CR1_DEDT_0                    (0x01UL << USART_CR1_DEDT_Pos)          /*!< 0x00010000 */
#define USART_CR1_DEDT_1                    (0x02UL << USART_CR1_DEDT_Pos)          /*!< 0x00020000 */
#define USART_CR1_DEDT_2                    (0x04UL << USART_CR1_DEDT_Pos)          /*!< 0x00040000 */
#define USART_CR1_DEDT_3                    (0x08UL << USART_CR1_DEDT_Pos)          /*!< 0x00080000 */
#define USART_CR1_DEDT_4                    (0x10UL << USART_CR1_DEDT_Pos)          /*!< 0x00100000 */
#define USART_CR1_DEAT_Pos                  (21U)
#define USART_CR1_DEAT_Msk                  (0x1FUL << USART_CR1_DEAT_Pos)          /*!< 0x03E00000 */
#define USART_CR1_DEAT                      USART_CR1_DEAT_Msk                      /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define USART_CR1_DEAT_0                    (0x01UL << USART_CR1_DEAT_Pos)          /*!< 0x00200000 */
#define USART_CR1_DEAT_1                    (0x02UL << USART_CR1_DEAT_Pos)          /*!< 0x00400000 */
#define USART_CR1_DEAT_2                    (0x04UL << USART_CR1_DEAT_Pos)          /*!< 0x00800000 */
#define USART_CR1_DEAT_3                    (0x08UL << USART_CR1_DEAT_Pos)          /*!< 0x01000000 */
#define USART_CR1_DEAT_4                    (0x10UL << USART_CR1_DEAT_Pos)          /*!< 0x02000000 */
#define USART_CR1_RTOIE_Pos                 (26U)
#define USART_CR1_RTOIE_Msk                 (0x1UL << USART_CR1_RTOIE_Pos)          /*!< 0x04000000 */
#define USART_CR1_RTOIE                     USART_CR1_RTOIE_Msk                     /*!< Receive Time Out interrupt enable */
#define USART_CR1_EOBIE_Pos                 (27U)
#define USART_CR1_EOBIE_Msk                 (0x1UL << USART_CR1_EOBIE_Pos)          /*!< 0x08000000 */
#define USART_CR1_EOBIE                     USART_CR1_EOBIE_Msk                     /*!< End of Block interrupt enable */
#define USART_CR1_M1_Pos                    (28U)
#define USART_CR1_M1_Msk                    (0x1UL << USART_CR1_M1_Pos)             /*!< 0x10000000 */
#define USART_CR1_M1                        USART_CR1_M1_Msk                        /*!< Word length - Bit 1 */
#define USART_CR1_FIFOEN_Pos                (29U)
#define USART_CR1_FIFOEN_Msk                (0x1UL << USART_CR1_FIFOEN_Pos)         /*!< 0x20000000 */
#define USART_CR1_FIFOEN                    USART_CR1_FIFOEN_Msk                    /*!< FIFO mode enable */
#define USART_CR1_TXFEIE_Pos                (30U)
#define USART_CR1_TXFEIE_Msk                (0x1UL << USART_CR1_TXFEIE_Pos)         /*!< 0x40000000 */
#define USART_CR1_TXFEIE                    USART_CR1_TXFEIE_Msk                    /*!< TXFIFO empty interrupt enable */
#define USART_CR1_RXFFIE_Pos                (31U)
#define USART_CR1_RXFFIE_Msk                (0x1UL << USART_CR1_RXFFIE_Pos)         /*!< 0x80000000 */
#define USART_CR1_RXFFIE                    USART_CR1_RXFFIE_Msk                    /*!< RXFIFO Full interrupt enable */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_SLVEN_Pos                 (0U)
#define USART_CR2_SLVEN_Msk                 (0x1UL << USART_CR2_SLVEN_Pos)          /*!< 0x00000001 */
#define USART_CR2_SLVEN                     USART_CR2_SLVEN_Msk                     /*!< Synchronous Slave mode enable */
#define USART_CR2_DIS_NSS_Pos               (3U)
#define USART_CR2_DIS_NSS_Msk               (0x1UL << USART_CR2_DIS_NSS_Pos)        /*!< 0x00000008 */
#define USART_CR2_DIS_NSS                   USART_CR2_DIS_NSS_Msk                   /*!< Slave Select (NSS) pin management */
#define USART_CR2_ADDM7_Pos                 (4U)
#define USART_CR2_ADDM7_Msk                 (0x1UL << USART_CR2_ADDM7_Pos)          /*!< 0x00000010 */
#define USART_CR2_ADDM7                     USART_CR2_ADDM7_Msk                     /*!< 7-bit or 4-bit Address Detection */
#define USART_CR2_LBDL_Pos                  (5U)
#define USART_CR2_LBDL_Msk                  (0x1UL << USART_CR2_LBDL_Pos)           /*!< 0x00000020 */
#define USART_CR2_LBDL                      USART_CR2_LBDL_Msk                      /*!< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos                 (6U)
#define USART_CR2_LBDIE_Msk                 (0x1UL << USART_CR2_LBDIE_Pos)          /*!< 0x00000040 */
#define USART_CR2_LBDIE                     USART_CR2_LBDIE_Msk                     /*!< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos                  (8U)
#define USART_CR2_LBCL_Msk                  (0x1UL << USART_CR2_LBCL_Pos)           /*!< 0x00000100 */
#define USART_CR2_LBCL                      USART_CR2_LBCL_Msk                      /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos                  (9U)
#define USART_CR2_CPHA_Msk                  (0x1UL << USART_CR2_CPHA_Pos)           /*!< 0x00000200 */
#define USART_CR2_CPHA                      USART_CR2_CPHA_Msk                      /*!< Clock Phase */
#define USART_CR2_CPOL_Pos                  (10U)
#define USART_CR2_CPOL_Msk                  (0x1UL << USART_CR2_CPOL_Pos)           /*!< 0x00000400 */
#define USART_CR2_CPOL                      USART_CR2_CPOL_Msk                      /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos                 (11U)
#define USART_CR2_CLKEN_Msk                 (0x1UL << USART_CR2_CLKEN_Pos)          /*!< 0x00000800 */
#define USART_CR2_CLKEN                     USART_CR2_CLKEN_Msk                     /*!< Clock Enable */
#define USART_CR2_STOP_Pos                  (12U)
#define USART_CR2_STOP_Msk                  (0x3UL << USART_CR2_STOP_Pos)           /*!< 0x00003000 */
#define USART_CR2_STOP                      USART_CR2_STOP_Msk                      /*!< STOP[1:0] bits (STOP bits) */
#define USART_CR2_STOP_0                    (0x1UL << USART_CR2_STOP_Pos)           /*!< 0x00001000 */
#define USART_CR2_STOP_1                    (0x2UL << USART_CR2_STOP_Pos)           /*!< 0x00002000 */
#define USART_CR2_LINEN_Pos                 (14U)
#define USART_CR2_LINEN_Msk                 (0x1UL << USART_CR2_LINEN_Pos)          /*!< 0x00004000 */
#define USART_CR2_LINEN                     USART_CR2_LINEN_Msk                     /*!< LIN mode enable */
#define USART_CR2_SWAP_Pos                  (15U)
#define USART_CR2_SWAP_Msk                  (0x1UL << USART_CR2_SWAP_Pos)           /*!< 0x00008000 */
#define USART_CR2_SWAP                      USART_CR2_SWAP_Msk                      /*!< SWAP TX/RX pins */
#define USART_CR2_RXINV_Pos                 (16U)
#define USART_CR2_RXINV_Msk                 (0x1UL << USART_CR2_RXINV_Pos)          /*!< 0x00010000 */
#define USART_CR2_RXINV                     USART_CR2_RXINV_Msk                     /*!< RX pin active level inversion */
#define USART_CR2_TXINV_Pos                 (17U)
#define USART_CR2_TXINV_Msk                 (0x1UL << USART_CR2_TXINV_Pos)          /*!< 0x00020000 */
#define USART_CR2_TXINV                     USART_CR2_TXINV_Msk                     /*!< TX pin active level inversion */
#define USART_CR2_DATAINV_Pos               (18U)
#define USART_CR2_DATAINV_Msk               (0x1UL << USART_CR2_DATAINV_Pos)        /*!< 0x00040000 */
#define USART_CR2_DATAINV                   USART_CR2_DATAINV_Msk                   /*!< Binary data inversion */
#define USART_CR2_MSBFIRST_Pos              (19U)
#define USART_CR2_MSBFIRST_Msk              (0x1UL << USART_CR2_MSBFIRST_Pos)       /*!< 0x00080000 */
#define USART_CR2_MSBFIRST                  USART_CR2_MSBFIRST_Msk                  /*!< Most Significant Bit First */
#define USART_CR2_ABREN_Pos                 (20U)
#define USART_CR2_ABREN_Msk                 (0x1UL << USART_CR2_ABREN_Pos)          /*!< 0x00100000 */
#define USART_CR2_ABREN                     USART_CR2_ABREN_Msk                     /*!< Auto Baud-Rate Enable*/
#define USART_CR2_ABRMODE_Pos               (21U)
#define USART_CR2_ABRMODE_Msk               (0x3UL << USART_CR2_ABRMODE_Pos)        /*!< 0x00600000 */
#define USART_CR2_ABRMODE                   USART_CR2_ABRMODE_Msk                   /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define USART_CR2_ABRMODE_0                 (0x1UL << USART_CR2_ABRMODE_Pos)        /*!< 0x00200000 */
#define USART_CR2_ABRMODE_1                 (0x2UL << USART_CR2_ABRMODE_Pos)        /*!< 0x00400000 */
#define USART_CR2_RTOEN_Pos                 (23U)
#define USART_CR2_RTOEN_Msk                 (0x1UL << USART_CR2_RTOEN_Pos)          /*!< 0x00800000 */
#define USART_CR2_RTOEN                     USART_CR2_RTOEN_Msk                     /*!< Receiver Time-Out enable */
#define USART_CR2_ADD_Pos                   (24U)
#define USART_CR2_ADD_Msk                   (0xFFUL << USART_CR2_ADD_Pos)           /*!< 0xFF000000 */
#define USART_CR2_ADD                       USART_CR2_ADD_Msk                       /*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos                   (0U)
#define USART_CR3_EIE_Msk                   (0x1UL << USART_CR3_EIE_Pos)            /*!< 0x00000001 */
#define USART_CR3_EIE                       USART_CR3_EIE_Msk                       /*!< Error Interrupt Enable */
#define USART_CR3_IREN_Pos                  (1U)
#define USART_CR3_IREN_Msk                  (0x1UL << USART_CR3_IREN_Pos)           /*!< 0x00000002 */
#define USART_CR3_IREN                      USART_CR3_IREN_Msk                      /*!< IrDA mode Enable */
#define USART_CR3_IRLP_Pos                  (2U)
#define USART_CR3_IRLP_Msk                  (0x1UL << USART_CR3_IRLP_Pos)           /*!< 0x00000004 */
#define USART_CR3_IRLP                      USART_CR3_IRLP_Msk                      /*!< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos                 (3U)
#define USART_CR3_HDSEL_Msk                 (0x1UL << USART_CR3_HDSEL_Pos)          /*!< 0x00000008 */
#define USART_CR3_HDSEL                     USART_CR3_HDSEL_Msk                     /*!< Half-Duplex Selection */
#define USART_CR3_NACK_Pos                  (4U)
#define USART_CR3_NACK_Msk                  (0x1UL << USART_CR3_NACK_Pos)           /*!< 0x00000010 */
#define USART_CR3_NACK                      USART_CR3_NACK_Msk                      /*!< SmartCard NACK enable */
#define USART_CR3_SCEN_Pos                  (5U)
#define USART_CR3_SCEN_Msk                  (0x1UL << USART_CR3_SCEN_Pos)           /*!< 0x00000020 */
#define USART_CR3_SCEN                      USART_CR3_SCEN_Msk                      /*!< SmartCard mode enable */
#define USART_CR3_DMAR_Pos                  (6U)
#define USART_CR3_DMAR_Msk                  (0x1UL << USART_CR3_DMAR_Pos)           /*!< 0x00000040 */
#define USART_CR3_DMAR                      USART_CR3_DMAR_Msk                      /*!< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos                  (7U)
#define USART_CR3_DMAT_Msk                  (0x1UL << USART_CR3_DMAT_Pos)           /*!< 0x00000080 */
#define USART_CR3_DMAT                      USART_CR3_DMAT_Msk                      /*!< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos                  (8U)
#define USART_CR3_RTSE_Msk                  (0x1UL << USART_CR3_RTSE_Pos)           /*!< 0x00000100 */
#define USART_CR3_RTSE                      USART_CR3_RTSE_Msk                      /*!< RTS Enable */
#define USART_CR3_CTSE_Pos                  (9U)
#define USART_CR3_CTSE_Msk                  (0x1UL << USART_CR3_CTSE_Pos)           /*!< 0x00000200 */
#define USART_CR3_CTSE                      USART_CR3_CTSE_Msk                      /*!< CTS Enable */
#define USART_CR3_CTSIE_Pos                 (10U)
#define USART_CR3_CTSIE_Msk                 (0x1UL << USART_CR3_CTSIE_Pos)          /*!< 0x00000400 */
#define USART_CR3_CTSIE                     USART_CR3_CTSIE_Msk                     /*!< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos                (11U)
#define USART_CR3_ONEBIT_Msk                (0x1UL << USART_CR3_ONEBIT_Pos)         /*!< 0x00000800 */
#define USART_CR3_ONEBIT                    USART_CR3_ONEBIT_Msk                    /*!< One sample bit method enable */
#define USART_CR3_OVRDIS_Pos                (12U)
#define USART_CR3_OVRDIS_Msk                (0x1UL << USART_CR3_OVRDIS_Pos)         /*!< 0x00001000 */
#define USART_CR3_OVRDIS                    USART_CR3_OVRDIS_Msk                    /*!< Overrun Disable */
#define USART_CR3_DDRE_Pos                  (13U)
#define USART_CR3_DDRE_Msk                  (0x1UL << USART_CR3_DDRE_Pos)           /*!< 0x00002000 */
#define USART_CR3_DDRE                      USART_CR3_DDRE_Msk                      /*!< DMA Disable on Reception Error */
#define USART_CR3_DEM_Pos                   (14U)
#define USART_CR3_DEM_Msk                   (0x1UL << USART_CR3_DEM_Pos)            /*!< 0x00004000 */
#define USART_CR3_DEM                       USART_CR3_DEM_Msk                       /*!< Driver Enable Mode */
#define USART_CR3_DEP_Pos                   (15U)
#define USART_CR3_DEP_Msk                   (0x1UL << USART_CR3_DEP_Pos)            /*!< 0x00008000 */
#define USART_CR3_DEP                       USART_CR3_DEP_Msk                       /*!< Driver Enable Polarity Selection */
#define USART_CR3_SCARCNT_Pos               (17U)
#define USART_CR3_SCARCNT_Msk               (0x7UL << USART_CR3_SCARCNT_Pos)        /*!< 0x000E0000 */
#define USART_CR3_SCARCNT                   USART_CR3_SCARCNT_Msk                   /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define USART_CR3_SCARCNT_0                 (0x1UL << USART_CR3_SCARCNT_Pos)        /*!< 0x00020000 */
#define USART_CR3_SCARCNT_1                 (0x2UL << USART_CR3_SCARCNT_Pos)        /*!< 0x00040000 */
#define USART_CR3_SCARCNT_2                 (0x4UL << USART_CR3_SCARCNT_Pos)        /*!< 0x00080000 */
#define USART_CR3_TXFTIE_Pos                (23U)
#define USART_CR3_TXFTIE_Msk                (0x1UL << USART_CR3_TXFTIE_Pos)         /*!< 0x00800000 */
#define USART_CR3_TXFTIE                    USART_CR3_TXFTIE_Msk                    /*!< TXFIFO threshold interrupt enable */
#define USART_CR3_TCBGTIE_Pos               (24U)
#define USART_CR3_TCBGTIE_Msk               (0x1UL << USART_CR3_TCBGTIE_Pos)        /*!< 0x01000000 */
#define USART_CR3_TCBGTIE                   USART_CR3_TCBGTIE_Msk                   /*!< Transmission Complete Before Guard Time Interrupt Enable */
#define USART_CR3_RXFTCFG_Pos               (25U)
#define USART_CR3_RXFTCFG_Msk               (0x7UL << USART_CR3_RXFTCFG_Pos)        /*!< 0x0E000000 */
#define USART_CR3_RXFTCFG                   USART_CR3_RXFTCFG_Msk                   /*!< RXFIFO FIFO threshold configuration */
#define USART_CR3_RXFTCFG_0                 (0x1UL << USART_CR3_RXFTCFG_Pos)        /*!< 0x02000000 */
#define USART_CR3_RXFTCFG_1                 (0x2UL << USART_CR3_RXFTCFG_Pos)        /*!< 0x04000000 */
#define USART_CR3_RXFTCFG_2                 (0x4UL << USART_CR3_RXFTCFG_Pos)        /*!< 0x08000000 */
#define USART_CR3_RXFTIE_Pos                (28U)
#define USART_CR3_RXFTIE_Msk                (0x1UL << USART_CR3_RXFTIE_Pos)         /*!< 0x10000000 */
#define USART_CR3_RXFTIE                    USART_CR3_RXFTIE_Msk                    /*!< RXFIFO threshold interrupt enable */
#define USART_CR3_TXFTCFG_Pos               (29U)
#define USART_CR3_TXFTCFG_Msk               (0x7UL << USART_CR3_TXFTCFG_Pos)        /*!< 0xE0000000 */
#define USART_CR3_TXFTCFG                   USART_CR3_TXFTCFG_Msk                   /*!< TXFIFO threshold configuration */
#define USART_CR3_TXFTCFG_0                 (0x1UL << USART_CR3_TXFTCFG_Pos)        /*!< 0x20000000 */
#define USART_CR3_TXFTCFG_1                 (0x2UL << USART_CR3_TXFTCFG_Pos)        /*!< 0x40000000 */
#define USART_CR3_TXFTCFG_2                 (0x4UL << USART_CR3_TXFTCFG_Pos)        /*!< 0x80000000 */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_LPUART_Pos                (0U)
#define USART_BRR_LPUART_Msk                (0xFFFFFUL << USART_BRR_LPUART_Pos)     /*!< 0x000FFFFF */
#define USART_BRR_LPUART                    USART_BRR_LPUART_Msk                    /*!< LPUART Baud rate register [19:0] */
#define USART_BRR_BRR                       ((uint16_t)0xFFFF)                      /*!< USART  Baud rate register [15:0] */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos                  (0U)
#define USART_GTPR_PSC_Msk                  (0xFFUL << USART_GTPR_PSC_Pos)          /*!< 0x000000FF */
#define USART_GTPR_PSC                      USART_GTPR_PSC_Msk                      /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_Pos                   (8U)
#define USART_GTPR_GT_Msk                   (0xFFUL << USART_GTPR_GT_Pos)           /*!< 0x0000FF00 */
#define USART_GTPR_GT                       USART_GTPR_GT_Msk                       /*!< GT[7:0] bits (Guard time value) */

/*******************  Bit definition for USART_RTOR register  *****************/
#define USART_RTOR_RTO_Pos                  (0U)
#define USART_RTOR_RTO_Msk                  (0xFFFFFFUL << USART_RTOR_RTO_Pos)      /*!< 0x00FFFFFF */
#define USART_RTOR_RTO                      USART_RTOR_RTO_Msk                      /*!< Receiver Time Out Value */
#define USART_RTOR_BLEN_Pos                 (24U)
#define USART_RTOR_BLEN_Msk                 (0xFFUL << USART_RTOR_BLEN_Pos)         /*!< 0xFF000000 */
#define USART_RTOR_BLEN                     USART_RTOR_BLEN_Msk                     /*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define USART_RQR_ABRRQ                     ((uint16_t)0x0001)                      /*!< Auto-Baud Rate Request */
#define USART_RQR_SBKRQ                     ((uint16_t)0x0002)                      /*!< Send Break Request */
#define USART_RQR_MMRQ                      ((uint16_t)0x0004)                      /*!< Mute Mode Request */
#define USART_RQR_RXFRQ                     ((uint16_t)0x0008)                      /*!< Receive Data flush Request */
#define USART_RQR_TXFRQ                     ((uint16_t)0x0010)                      /*!< Transmit data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define USART_ISR_PE_Pos                    (0U)
#define USART_ISR_PE_Msk                    (0x1UL << USART_ISR_PE_Pos)             /*!< 0x00000001 */
#define USART_ISR_PE                        USART_ISR_PE_Msk                        /*!< Parity Error */
#define USART_ISR_FE_Pos                    (1U)
#define USART_ISR_FE_Msk                    (0x1UL << USART_ISR_FE_Pos)             /*!< 0x00000002 */
#define USART_ISR_FE                        USART_ISR_FE_Msk                        /*!< Framing Error */
#define USART_ISR_NE_Pos                    (2U)
#define USART_ISR_NE_Msk                    (0x1UL << USART_ISR_NE_Pos)             /*!< 0x00000004 */
#define USART_ISR_NE                        USART_ISR_NE_Msk                        /*!< Noise detected Flag */
#define USART_ISR_ORE_Pos                   (3U)
#define USART_ISR_ORE_Msk                   (0x1UL << USART_ISR_ORE_Pos)            /*!< 0x00000008 */
#define USART_ISR_ORE                       USART_ISR_ORE_Msk                       /*!< OverRun Error */
#define USART_ISR_IDLE_Pos                  (4U)
#define USART_ISR_IDLE_Msk                  (0x1UL << USART_ISR_IDLE_Pos)           /*!< 0x00000010 */
#define USART_ISR_IDLE                      USART_ISR_IDLE_Msk                      /*!< IDLE line detected */
#define USART_ISR_RXNE_Pos                  (5U)
#define USART_ISR_RXNE_Msk                  (0x1UL << USART_ISR_RXNE_Pos)           /*!< 0x00000020 */
#define USART_ISR_RXNE                      USART_ISR_RXNE_Msk                      /*!< Read Data Register Not Empty */
#define USART_ISR_RXNE_RXFNE_Pos            USART_ISR_RXNE_Pos
#define USART_ISR_RXNE_RXFNE_Msk            USART_ISR_RXNE_Msk                      /*!< 0x00000020 */
#define USART_ISR_RXNE_RXFNE                USART_ISR_RXNE_Msk                      /*!< Read Data Register or RX FIFO Not Empty */
#define USART_ISR_TC_Pos                    (6U)
#define USART_ISR_TC_Msk                    (0x1UL << USART_ISR_TC_Pos)             /*!< 0x00000040 */
#define USART_ISR_TC                        USART_ISR_TC_Msk                        /*!< Transmission Complete */
#define USART_ISR_TXE_Pos                   (7U)
#define USART_ISR_TXE_Msk                   (0x1UL << USART_ISR_TXE_Pos)            /*!< 0x00000080 */
#define USART_ISR_TXE                       USART_ISR_TXE_Msk                       /*!< Transmit Data Register Empty */
#define USART_ISR_TXE_TXFNF_Pos             USART_ISR_TXE_Pos
#define USART_ISR_TXE_TXFNF_Msk             USART_ISR_TXE_Msk                       /*!< 0x00000080 */
#define USART_ISR_TXE_TXFNF                 USART_ISR_TXE_Msk                       /*!< Transmit Data Register Empty or TX FIFO Not Full Flag */
#define USART_ISR_LBDF_Pos                  (8U)
#define USART_ISR_LBDF_Msk                  (0x1UL << USART_ISR_LBDF_Pos)           /*!< 0x00000100 */
#define USART_ISR_LBDF                      USART_ISR_LBDF_Msk                      /*!< LIN Break Detection Flag */
#define USART_ISR_CTSIF_Pos                 (9U)
#define USART_ISR_CTSIF_Msk                 (0x1UL << USART_ISR_CTSIF_Pos)          /*!< 0x00000200 */
#define USART_ISR_CTSIF                     USART_ISR_CTSIF_Msk                     /*!< CTS interrupt flag */
#define USART_ISR_CTS_Pos                   (10U)
#define USART_ISR_CTS_Msk                   (0x1UL << USART_ISR_CTS_Pos)            /*!< 0x00000400 */
#define USART_ISR_CTS                       USART_ISR_CTS_Msk                       /*!< CTS flag */
#define USART_ISR_RTOF_Pos                  (11U)
#define USART_ISR_RTOF_Msk                  (0x1UL << USART_ISR_RTOF_Pos)           /*!< 0x00000800 */
#define USART_ISR_RTOF                      USART_ISR_RTOF_Msk                      /*!< Receiver Time Out */
#define USART_ISR_EOBF_Pos                  (12U)
#define USART_ISR_EOBF_Msk                  (0x1UL << USART_ISR_EOBF_Pos)           /*!< 0x00001000 */
#define USART_ISR_EOBF                      USART_ISR_EOBF_Msk                      /*!< End Of Block Flag */
#define USART_ISR_UDR_Pos                   (13U)
#define USART_ISR_UDR_Msk                   (0x1UL << USART_ISR_UDR_Pos)            /*!< 0x00002000 */
#define USART_ISR_UDR                       USART_ISR_UDR_Msk                       /*!< SPI slave underrun error flag */
#define USART_ISR_ABRE_Pos                  (14U)
#define USART_ISR_ABRE_Msk                  (0x1UL << USART_ISR_ABRE_Pos)           /*!< 0x00004000 */
#define USART_ISR_ABRE                      USART_ISR_ABRE_Msk                      /*!< Auto-Baud Rate Error */
#define USART_ISR_ABRF_Pos                  (15U)
#define USART_ISR_ABRF_Msk                  (0x1UL << USART_ISR_ABRF_Pos)           /*!< 0x00008000 */
#define USART_ISR_ABRF                      USART_ISR_ABRF_Msk                      /*!< Auto-Baud Rate Flag */
#define USART_ISR_BUSY_Pos                  (16U)
#define USART_ISR_BUSY_Msk                  (0x1UL << USART_ISR_BUSY_Pos)           /*!< 0x00010000 */
#define USART_ISR_BUSY                      USART_ISR_BUSY_Msk                      /*!< Busy Flag */
#define USART_ISR_CMF_Pos                   (17U)
#define USART_ISR_CMF_Msk                   (0x1UL << USART_ISR_CMF_Pos)            /*!< 0x00020000 */
#define USART_ISR_CMF                       USART_ISR_CMF_Msk                       /*!< Character Match Flag */
#define USART_ISR_SBKF_Pos                  (18U)
#define USART_ISR_SBKF_Msk                  (0x1UL << USART_ISR_SBKF_Pos)           /*!< 0x00040000 */
#define USART_ISR_SBKF                      USART_ISR_SBKF_Msk                      /*!< Send Break Flag */
#define USART_ISR_RWU_Pos                   (19U)
#define USART_ISR_RWU_Msk                   (0x1UL << USART_ISR_RWU_Pos)            /*!< 0x00080000 */
#define USART_ISR_RWU                       USART_ISR_RWU_Msk                       /*!< Receive Wake Up from mute mode Flag */
#define USART_ISR_TEACK_Pos                 (21U)
#define USART_ISR_TEACK_Msk                 (0x1UL << USART_ISR_TEACK_Pos)          /*!< 0x00200000 */
#define USART_ISR_TEACK                     USART_ISR_TEACK_Msk                     /*!< Transmit Enable Acknowledge Flag */
#define USART_ISR_REACK_Pos                 (22U)
#define USART_ISR_REACK_Msk                 (0x1UL << USART_ISR_REACK_Pos)          /*!< 0x00400000 */
#define USART_ISR_REACK                     USART_ISR_REACK_Msk                     /*!< Receive Enable Acknowledge Flag */
#define USART_ISR_TXFE_Pos                  (23U)
#define USART_ISR_TXFE_Msk                  (0x1UL << USART_ISR_TXFE_Pos)           /*!< 0x00800000 */
#define USART_ISR_TXFE                      USART_ISR_TXFE_Msk                      /*!< TXFIFO Empty */
#define USART_ISR_RXFF_Pos                  (24U)
#define USART_ISR_RXFF_Msk                  (0x1UL << USART_ISR_RXFF_Pos)           /*!< 0x01000000 */
#define USART_ISR_RXFF                      USART_ISR_RXFF_Msk                      /*!< RXFIFO Full */
#define USART_ISR_TCBGT_Pos                 (25U)
#define USART_ISR_TCBGT_Msk                 (0x1UL << USART_ISR_TCBGT_Pos)          /*!< 0x02000000 */
#define USART_ISR_TCBGT                     USART_ISR_TCBGT_Msk                     /*!< Transmission Complete Before Guard Time completion */
#define USART_ISR_RXFT_Pos                  (26U)
#define USART_ISR_RXFT_Msk                  (0x1UL << USART_ISR_RXFT_Pos)           /*!< 0x04000000 */
#define USART_ISR_RXFT                      USART_ISR_RXFT_Msk                      /*!< RXFIFO threshold flag */
#define USART_ISR_TXFT_Pos                  (27U)
#define USART_ISR_TXFT_Msk                  (0x1UL << USART_ISR_TXFT_Pos)           /*!< 0x08000000 */
#define USART_ISR_TXFT                      USART_ISR_TXFT_Msk                      /*!< TXFIFO threshold flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define USART_ICR_PECF_Pos                  (0U)
#define USART_ICR_PECF_Msk                  (0x1UL << USART_ICR_PECF_Pos)           /*!< 0x00000001 */
#define USART_ICR_PECF                      USART_ICR_PECF_Msk                      /*!< Parity Error Clear Flag */
#define USART_ICR_FECF_Pos                  (1U)
#define USART_ICR_FECF_Msk                  (0x1UL << USART_ICR_FECF_Pos)           /*!< 0x00000002 */
#define USART_ICR_FECF                      USART_ICR_FECF_Msk                      /*!< Framing Error Clear Flag */
#define USART_ICR_NECF_Pos                  (2U)
#define USART_ICR_NECF_Msk                  (0x1UL << USART_ICR_NECF_Pos)           /*!< 0x00000004 */
#define USART_ICR_NECF                      USART_ICR_NECF_Msk                      /*!< Noise detected Clear Flag */
#define USART_ICR_ORECF_Pos                 (3U)
#define USART_ICR_ORECF_Msk                 (0x1UL << USART_ICR_ORECF_Pos)          /*!< 0x00000008 */
#define USART_ICR_ORECF                     USART_ICR_ORECF_Msk                     /*!< OverRun Error Clear Flag */
#define USART_ICR_IDLECF_Pos                (4U)
#define USART_ICR_IDLECF_Msk                (0x1UL << USART_ICR_IDLECF_Pos)         /*!< 0x00000010 */
#define USART_ICR_IDLECF                    USART_ICR_IDLECF_Msk                    /*!< IDLE line detected Clear Flag */
#define USART_ICR_TXFECF_Pos                (5U)
#define USART_ICR_TXFECF_Msk                (0x1UL << USART_ICR_TXFECF_Pos)         /*!< 0x00000020 */
#define USART_ICR_TXFECF                    USART_ICR_TXFECF_Msk                    /*!< TXFIFO empty Clear flag */
#define USART_ICR_TCCF_Pos                  (6U)
#define USART_ICR_TCCF_Msk                  (0x1UL << USART_ICR_TCCF_Pos)           /*!< 0x00000040 */
#define USART_ICR_TCCF                      USART_ICR_TCCF_Msk                      /*!< Transmission Complete Clear Flag */
#define USART_ICR_TCBGTCF_Pos               (7U)
#define USART_ICR_TCBGTCF_Msk               (0x1UL << USART_ICR_TCBGTCF_Pos)        /*!< 0x00000080 */
#define USART_ICR_TCBGTCF                   USART_ICR_TCBGTCF_Msk                   /*!< Transmission Complete Before Guard Time Clear Flag */
#define USART_ICR_LBDCF_Pos                 (8U)
#define USART_ICR_LBDCF_Msk                 (0x1UL << USART_ICR_LBDCF_Pos)          /*!< 0x00000100 */
#define USART_ICR_LBDCF                     USART_ICR_LBDCF_Msk                     /*!< LIN Break Detection Clear Flag */
#define USART_ICR_CTSCF_Pos                 (9U)
#define USART_ICR_CTSCF_Msk                 (0x1UL << USART_ICR_CTSCF_Pos)          /*!< 0x00000200 */
#define USART_ICR_CTSCF                     USART_ICR_CTSCF_Msk                     /*!< CTS Interrupt Clear Flag */
#define USART_ICR_RTOCF_Pos                 (11U)
#define USART_ICR_RTOCF_Msk                 (0x1UL << USART_ICR_RTOCF_Pos)          /*!< 0x00000800 */
#define USART_ICR_RTOCF                     USART_ICR_RTOCF_Msk                     /*!< Receiver Time Out Clear Flag */
#define USART_ICR_EOBCF_Pos                 (12U)
#define USART_ICR_EOBCF_Msk                 (0x1UL << USART_ICR_EOBCF_Pos)          /*!< 0x00001000 */
#define USART_ICR_EOBCF                     USART_ICR_EOBCF_Msk                     /*!< End Of Block Clear Flag */
#define USART_ICR_UDRCF_Pos                 (13U)
#define USART_ICR_UDRCF_Msk                 (0x1UL << USART_ICR_UDRCF_Pos)          /*!< 0x00002000 */
#define USART_ICR_UDRCF                     USART_ICR_UDRCF_Msk                     /*!< SPI Slave Underrun Clear Flag */
#define USART_ICR_CMCF_Pos                  (17U)
#define USART_ICR_CMCF_Msk                  (0x1UL << USART_ICR_CMCF_Pos)           /*!< 0x00020000 */
#define USART_ICR_CMCF                      USART_ICR_CMCF_Msk                      /*!< Character Match Clear Flag */

/*******************  Bit definition for USART_RDR register  ******************/
#define USART_RDR_RDR                       ((uint16_t)0x01FF)                      /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define USART_TDR_TDR                       ((uint16_t)0x01FF)                      /*!< TDR[8:0] bits (Transmit Data value) */

/*******************  Bit definition for USART_PRESC register  ****************/
#define USART_PRESC_PRESCALER_Pos           (0U)
#define USART_PRESC_PRESCALER_Msk           (0xFUL << USART_PRESC_PRESCALER_Pos)    /*!< 0x0000000F */
#define USART_PRESC_PRESCALER               USART_PRESC_PRESCALER_Msk               /*!< PRESCALER[3:0] bits (Clock prescaler) */
#define USART_PRESC_PRESCALER_0             (0x1UL << USART_PRESC_PRESCALER_Pos)    /*!< 0x00000001 */
#define USART_PRESC_PRESCALER_1             (0x2UL << USART_PRESC_PRESCALER_Pos)    /*!< 0x00000002 */
#define USART_PRESC_PRESCALER_2             (0x4UL << USART_PRESC_PRESCALER_Pos)    /*!< 0x00000004 */
#define USART_PRESC_PRESCALER_3             (0x8UL << USART_PRESC_PRESCALER_Pos)    /*!< 0x00000008 */

/*******************  Bit definition for USART_AUTOCR register  ******************/
#define USART_AUTOCR_TDN_Pos                (0U)
#define USART_AUTOCR_TDN_Msk                (0xFFFFUL << USART_AUTOCR_TDN_Pos)      /*!< 0x0000FFFF */
#define USART_AUTOCR_TDN                    USART_AUTOCR_TDN_Msk                    /*!< TDN[15:0] bits (Transmission Data Number) */
#define USART_AUTOCR_TRIGPOL_Pos            (16U)
#define USART_AUTOCR_TRIGPOL_Msk            (0x1UL << USART_AUTOCR_TRIGPOL_Pos)     /*!< 0x00010000 */
#define USART_AUTOCR_TRIGPOL                USART_AUTOCR_TRIGPOL_Msk                /*!< Trigger Polarity Bit (Rising/Falling edge) */
#define USART_AUTOCR_TRIGEN_Pos             (17U)
#define USART_AUTOCR_TRIGEN_Msk             (0x1UL << USART_AUTOCR_TRIGEN_Pos)      /*!< 0x00020000 */
#define USART_AUTOCR_TRIGEN                 USART_AUTOCR_TRIGEN_Msk                 /*!< Trigger Enable Bit */
#define USART_AUTOCR_IDLEDIS_Pos            (18U)
#define USART_AUTOCR_IDLEDIS_Msk            (0x1UL << USART_AUTOCR_IDLEDIS_Pos)     /*!< 0x00040000 */
#define USART_AUTOCR_IDLEDIS                USART_AUTOCR_IDLEDIS_Msk                /*!< Idle Frame Transmission Disable Bit*/
#define USART_AUTOCR_TRIGSEL_Pos            (19U)
#define USART_AUTOCR_TRIGSEL_Msk            (0xFUL << USART_AUTOCR_TRIGSEL_Pos)     /*!< 0x00780000 */
#define USART_AUTOCR_TRIGSEL                USART_AUTOCR_TRIGSEL_Msk                /*!< Trigger Selection Bits */
#define USART_AUTOCR_TRIGSEL_0              (0x0001UL << USART_AUTOCR_TRIGSEL_Pos)  /*!< 0x00000001 */
#define USART_AUTOCR_TRIGSEL_1              (0x0002UL << USART_AUTOCR_TRIGSEL_Pos)  /*!< 0x00000002 */
#define USART_AUTOCR_TRIGSEL_2              (0x0004UL << USART_AUTOCR_TRIGSEL_Pos)  /*!< 0x00000004 */
#define USART_AUTOCR_TRIGSEL_3              (0x0008UL << USART_AUTOCR_TRIGSEL_Pos)  /*!< 0x00000008 */


/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos                       (0U)
#define WWDG_CR_T_Msk                       (0x7FUL << WWDG_CR_T_Pos)               /*!< 0x0000007F */
#define WWDG_CR_T                           WWDG_CR_T_Msk                           /*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0                         (0x01UL << WWDG_CR_T_Pos)               /*!< 0x00000001 */
#define WWDG_CR_T_1                         (0x02UL << WWDG_CR_T_Pos)               /*!< 0x00000002 */
#define WWDG_CR_T_2                         (0x04UL << WWDG_CR_T_Pos)               /*!< 0x00000004 */
#define WWDG_CR_T_3                         (0x08UL << WWDG_CR_T_Pos)               /*!< 0x00000008 */
#define WWDG_CR_T_4                         (0x10UL << WWDG_CR_T_Pos)               /*!< 0x00000010 */
#define WWDG_CR_T_5                         (0x20UL << WWDG_CR_T_Pos)               /*!< 0x00000020 */
#define WWDG_CR_T_6                         (0x40UL << WWDG_CR_T_Pos)               /*!< 0x00000040 */
#define WWDG_CR_WDGA_Pos                    (7U)
#define WWDG_CR_WDGA_Msk                    (0x1UL << WWDG_CR_WDGA_Pos)             /*!< 0x00000080 */
#define WWDG_CR_WDGA                        WWDG_CR_WDGA_Msk                        /*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos                      (0U)
#define WWDG_CFR_W_Msk                      (0x7FUL << WWDG_CFR_W_Pos)              /*!< 0x0000007F */
#define WWDG_CFR_W                          WWDG_CFR_W_Msk                          /*!<W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0                        (0x01UL << WWDG_CFR_W_Pos)              /*!< 0x00000001 */
#define WWDG_CFR_W_1                        (0x02UL << WWDG_CFR_W_Pos)              /*!< 0x00000002 */
#define WWDG_CFR_W_2                        (0x04UL << WWDG_CFR_W_Pos)              /*!< 0x00000004 */
#define WWDG_CFR_W_3                        (0x08UL << WWDG_CFR_W_Pos)              /*!< 0x00000008 */
#define WWDG_CFR_W_4                        (0x10UL << WWDG_CFR_W_Pos)              /*!< 0x00000010 */
#define WWDG_CFR_W_5                        (0x20UL << WWDG_CFR_W_Pos)              /*!< 0x00000020 */
#define WWDG_CFR_W_6                        (0x40UL << WWDG_CFR_W_Pos)              /*!< 0x00000040 */
#define WWDG_CFR_EWI_Pos                    (9U)
#define WWDG_CFR_EWI_Msk                    (0x1UL << WWDG_CFR_EWI_Pos)             /*!< 0x00000200 */
#define WWDG_CFR_EWI                        WWDG_CFR_EWI_Msk                        /*!<Early Wakeup Interrupt */
#define WWDG_CFR_WDGTB_Pos                  (11U)
#define WWDG_CFR_WDGTB_Msk                  (0x7UL << WWDG_CFR_WDGTB_Pos)           /*!< 0x00003800 */
#define WWDG_CFR_WDGTB                      WWDG_CFR_WDGTB_Msk                      /*!<WDGTB[2:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0                    (0x1UL << WWDG_CFR_WDGTB_Pos)           /*!< 0x00000800 */
#define WWDG_CFR_WDGTB_1                    (0x2UL << WWDG_CFR_WDGTB_Pos)           /*!< 0x00001000 */
#define WWDG_CFR_WDGTB_2                    (0x4UL << WWDG_CFR_WDGTB_Pos)           /*!< 0x00002000 */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos                    (0U)
#define WWDG_SR_EWIF_Msk                    (0x1UL << WWDG_SR_EWIF_Pos)             /*!< 0x00000001 */
#define WWDG_SR_EWIF                        WWDG_SR_EWIF_Msk                        /*!<Early Wakeup Interrupt Flag */

/** @} */

/** @} */

/** @addtogroup STM32WBAxx_Peripheral_Exported_macros
  * @{
  */


/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC4_NS)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC4_COMMON_NS)

/******************************* AES Instances ********************************/
#define IS_AES_ALL_INSTANCE(INSTANCE) ((INSTANCE) == AES_NS)

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC_NS)

/******************************** DMA Instances *******************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPDMA1_Channel0_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel1_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel2_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel3_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel4_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel5_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel6_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel7_NS))

#define IS_GPDMA_INSTANCE(INSTANCE)   (((INSTANCE) == GPDMA1_Channel0_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel1_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel2_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel3_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel4_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel5_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel6_NS) || \
                                       ((INSTANCE) == GPDMA1_Channel7_NS))

/****************************** RAMCFG Instances ********************************/
#define IS_RAMCFG_ALL_INSTANCE(INSTANCE) (((INSTANCE) == RAMCFG_SRAM1_NS) || \
                                          ((INSTANCE) == RAMCFG_SRAM2_NS) || \
                                          ((INSTANCE) == RAMCFG_SRAM6_NS))

/***************************** RAMCFG PED Instances *****************************/
#define IS_RAMCFG_PED_INSTANCE(INSTANCE) ((INSTANCE) == RAMCFG_SRAM2_NS)

/***************************** RAMCFG IT Instances ******************************/
#define IS_RAMCFG_IT_INSTANCE(INSTANCE) ((INSTANCE) == RAMCFG_SRAM2_NS)

/************************ RAMCFG Write Protection Instances *********************/
#define IS_RAMCFG_WP_INSTANCE(INSTANCE) ((INSTANCE) == RAMCFG_SRAM2_NS)

/************************ RAMCFG Erase Instances ********************************/
#define IS_RAMCFG_ER_INSTANCE(INSTANCE) (((INSTANCE) == RAMCFG_SRAM1_NS) || \
                                         ((INSTANCE) == RAMCFG_SRAM2_NS))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA_NS) || \
                                        ((INSTANCE) == GPIOB_NS) || \
                                        ((INSTANCE) == GPIOC_NS) || \
                                        ((INSTANCE) == GPIOH_NS))

/******************************* GPIO AF Instances ****************************/
/* On WBA, all GPIO Bank support AF */
#define IS_GPIO_AF_INSTANCE(INSTANCE)   IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
/* On WBA, all GPIO Bank support the Lock mechanism */
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** HSEM Lock Instances *****************************/
#define IS_HSEM_ALL_INSTANCE(INSTANCE) ((INSTANCE) == HSEM_NS)

#define HSEM_CPU1_LOCKID   (HSEM_CR_LOCKID_CURRENT >> HSEM_CR_LOCKID_Pos)/* Semaphore Lock ID */

#define HSEM_SEMID_MIN     (0U)       /* HSEM ID Min*/
#define HSEM_SEMID_MAX     (15U)      /* HSEM ID Max */

#define HSEM_PROCESSID_MIN (0U)       /* HSEM Process ID Min */
#define HSEM_PROCESSID_MAX (255U)     /* HSEM Process ID Max */

#define HSEM_CLEAR_KEY_MIN (0U)       /* HSEM clear Key Min value */
#define HSEM_CLEAR_KEY_MAX (0xFFFFU)  /* HSEM clear Key Max value */

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C3_NS)

/******************* I2C Instances : Group belongingness *********************/
#define IS_I2C_GRP1_INSTANCE(INSTANCE) (0)

#define IS_I2C_GRP2_INSTANCE(INSTANCE) ((INSTANCE) == I2C3_NS)

/****************** I2C Instances : wakeup capability from stop modes *********/
#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)

/******************************* AES Instances ********************************/
#define IS_PKA_ALL_INSTANCE(INSTANCE) ((INSTANCE) == PKA_NS)

/******************************* RNG Instances ********************************/
#define IS_RNG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RNG_NS)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == RTC_NS)

/****************************** SMBUS Instances *******************************/
#define IS_SMBUS_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C3_NS)

/******************* SMBUS Instances : Group belongingness *********************/
#define IS_SMBUS_GRP1_INSTANCE(INSTANCE) (0)

#define IS_SMBUS_GRP2_INSTANCE(INSTANCE) ((INSTANCE) == I2C3_NS)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPI3_NS)

#define IS_SPI_LIMITED_INSTANCE(INSTANCE) ((INSTANCE) == SPI3_NS)

#define IS_SPI_FULL_INSTANCE(INSTANCE) (0)

/******************* SPI Instances : Group belongingness *********************/
#define IS_SPI_GRP1_INSTANCE(INSTANCE) (0)

#define IS_SPI_GRP2_INSTANCE(INSTANCE) ((INSTANCE) == SPI3_NS)

/******************************** LPTIM Instances *******************************/
#define IS_LPTIM_INSTANCE(INSTANCE)     ((INSTANCE) == LPTIM1_NS)

/****************** LPTIM Instances : DMA supported instances *****************/
#define IS_LPTIM_DMA_INSTANCE(INSTANCE)  ((INSTANCE) == LPTIM1_NS)

/************* LPTIM Instances : at least 1 capture/compare channel ***********/
#define IS_LPTIM_CC1_INSTANCE(INSTANCE) ((INSTANCE) == LPTIM1_NS)

/************* LPTIM Instances : at least 2 capture/compare channel ***********/
#define IS_LPTIM_CC2_INSTANCE(INSTANCE) ((INSTANCE) == LPTIM1_NS)

/****************** LPTIM Instances : supporting encoder interface **************/
#define IS_LPTIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  ((INSTANCE) == LPTIM1_NS)

/****************** LPTIM Instances : supporting Input Capture **************/
#define IS_LPTIM_INPUT_CAPTURE_INSTANCE(INSTANCE)  ((INSTANCE) == LPTIM1_NS)

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)       (((INSTANCE) == TIM1_NS)   || \
                                         ((INSTANCE) == TIM2_NS)   || \
                                         ((INSTANCE) == TIM16_NS))

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) ((INSTANCE) == TIM2_NS)

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS)   || \
                                            ((INSTANCE) == TIM16_NS))

/************** TIM Instances : supporting Break source selection *************/
#define IS_TIM_BREAKSOURCE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1_NS)  || \
                                               ((INSTANCE) == TIM16_NS))

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1_NS)

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                         ((INSTANCE) == TIM2_NS) || \
                                         ((INSTANCE) == TIM16_NS))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS)  || \
                                         ((INSTANCE) == TIM2_NS))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS)  || \
                                         ((INSTANCE) == TIM2_NS))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS)  || \
                                         ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1_NS)

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1_NS)

/************ TIM Instances : DMA requests generation (TIMx_DIER.COMDE) *******/
#define IS_TIM_CCDMA_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS)  || \
                                            ((INSTANCE) == TIM16_NS))

/****************** TIM Instances : DMA requests generation (TIMx_DIER.UDE) ***/
#define IS_TIM_DMA_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1_NS) || \
                                            ((INSTANCE) == TIM2_NS) || \
                                            ((INSTANCE) == TIM16_NS))

/************ TIM Instances : DMA requests generation (TIMx_DIER.CCxDE) *******/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                            ((INSTANCE) == TIM2_NS) || \
                                            ((INSTANCE) == TIM16_NS))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE) (((INSTANCE) == TIM1_NS) || \
                                            ((INSTANCE) == TIM2_NS) || \
                                            ((INSTANCE) == TIM16_NS))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1_NS)  &&              \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4) ||          \
      ((CHANNEL) == TIM_CHANNEL_5) ||          \
      ((CHANNEL) == TIM_CHANNEL_6)))           \
     ||                                        \
     (((INSTANCE) == TIM2_NS)  &&              \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
     ||                                        \
     (((INSTANCE) == TIM16_NS) &&              \
     (((CHANNEL) == TIM_CHANNEL_1))))

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1_NS)  &&               \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3) ||           \
      ((CHANNEL) == TIM_CHANNEL_4)))            \
    ||                                          \
    (((INSTANCE) == TIM16_NS)  &&               \
     ((CHANNEL) == TIM_CHANNEL_1)))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                                    ((INSTANCE) == TIM2_NS) || \
                                                    ((INSTANCE) == TIM16_NS))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM1_NS) || \
                                                        ((INSTANCE) == TIM2_NS))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1_NS) || \
                                                        ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1_NS) || \
                                                        ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS) || \
                                                       ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting combined 3-phase PWM mode ******/
#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1_NS)

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE) (((INSTANCE) == TIM1_NS) || \
                                                     ((INSTANCE) == TIM16_NS))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                                         ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1_NS) || \
                                                      ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1_NS) || \
                                                          ((INSTANCE) == TIM2_NS))

/**************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS) || \
                                          ((INSTANCE) == TIM2_NS))

/************* TIM Instances : supporting ETR source selection ***************/
#define IS_TIM_ETRSEL_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS) || \
                                             ((INSTANCE) == TIM2_NS))

/****** TIM Instances : Master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                           ((INSTANCE) == TIM2_NS))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1_NS) || \
                                           ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1_NS)  || \
                                                 ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1_NS)  || \
                                            ((INSTANCE) == TIM2_NS))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1_NS)  || \
                                                       ((INSTANCE) == TIM16_NS))

/****************** TIM Instances : supporting ADC triggering through TRGO2 ***/
#define IS_TIM_TRGO2_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1_NS)

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1_NS) || \
                                            ((INSTANCE) == TIM2_NS))

/******************* TIM Instances : Timer input selection ********************/
#define IS_TIM_TISEL_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1_NS)  || \
                                          ((INSTANCE) == TIM2_NS)  || \
                                          ((INSTANCE) == TIM16_NS))

/******************* TIM Instances : supporting HSE32 as input  ********************/
#define IS_TIM_HSE32_INSTANCE(INSTANCE)  ((INSTANCE) == TIM16_NS)

/****************** TIM Instances : Advanced timer instances *******************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)       ((INSTANCE) == TIM1_NS)

/****************** TIM Instances : supporting synchronization ****************/
#define IS_TIM_SYNCHRO_INSTANCE(__INSTANCE__)  (((INSTANCE) == TIM1_NS) || \
                                                ((INSTANCE) == TIM2_NS))

/****************************** TSC Instances *********************************/
#define IS_TSC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == TSC_NS)

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/*********************** UART Instances : FIFO mode ***************************/
#define IS_UART_FIFO_INSTANCE(INSTANCE) (((INSTANCE) == USART1_NS) || \
                                         ((INSTANCE) == LPUART1_NS))

/*********************** UART Instances : SPI Slave mode **********************/
#define IS_UART_SPI_SLAVE_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/****************** UART Instances : Auto Baud Rate detection ****************/
#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/****************** UART Instances : Driver Enable *****************/
#define IS_UART_DRIVER_ENABLE_INSTANCE(INSTANCE)    (((INSTANCE) == USART1_NS) || \
                                                     ((INSTANCE) == LPUART1_NS))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == USART1_NS) || \
                                                 ((INSTANCE) == LPUART1_NS))

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1_NS) || \
                                           ((INSTANCE) == LPUART1_NS))

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE)  ((INSTANCE) == USART1_NS)

/******************** UART Instances : Wake-up from Stop mode **********************/
#define IS_UART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)   (((INSTANCE) == USART1_NS) || \
                                                      ((INSTANCE) == LPUART1_NS))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/********************* USART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) ((INSTANCE) == USART1_NS)

/*********************** UART Instances : AUTONOMOUS mode ***************************/
#define IS_UART_AUTONOMOUS_INSTANCE(INSTANCE)  (((INSTANCE) == USART1_NS) || \
                                                ((INSTANCE) == LPUART1_NS))

/******************** LPUART Instance *****************************************/
#define IS_LPUART_INSTANCE(INSTANCE)    ((INSTANCE) == LPUART1_NS)

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG_NS)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG_NS)


/** @} */ /* End of group STM32WBAxx_Peripheral_Exported_macros */

/** @} */ /* End of group STM32WBA50xx */

/** @} */ /* End of group ST */

#ifdef __cplusplus
}
#endif

#endif  /* STM32WBA50xx_H */

