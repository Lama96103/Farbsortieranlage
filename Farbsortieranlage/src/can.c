/*
**              Basic Driver for CAN Communication
**					with Staudinger Models,
**					based on CANOpen
**
**********************************************************************/

#include "global.h"


/*******************************************************************
*																   *
*		 Initialization of Simulation Model						   *
*																   *
********************************************************************/
void CAN_Init4Models()
{
    /*******************************************

        Port and Clock Initialization

    *******************************************/

    // Init CanRx mapped to GPIOD_0

    // Init CanTx mapped to GPIOD_1

    RCC_APB1PeriphClockCmd(RCC_APB1ENR_CAN1EN, enable);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, enable);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, enable);


    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOD, &gpio);

    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Pin = GPIO_Pin_1;
    GPIO_Init(GPIOD, &gpio);

    // TODO
    // Maybe GPIO_Remap1_CAN1
    // GPIO_PinRemapConfig(GPIO_Remap_PD01, enable);
    //GPIO_PinRemapConfig(GPIO_Remap1_CAN1, enable);
     GPIO_PinRemapConfig(GPIO_Remap2_CAN1, enable);

    /*******************************************

        Initialization of CAN1

    *******************************************/
    CAN_InitTypeDef CAN1_InitStructure;

    CAN_DeInit(CAN1);
    CAN_StructInit(&CAN1_InitStructure);

    /**************************************
        Init of
        MCR (Master Control Register)
        MSR (Master Status Register)
        BTR (Bit Timing Register)
    **************************************/
    CAN1_InitStructure.CAN_Prescaler = 2;
    CAN1_InitStructure.CAN_BS1 = CAN_BS1_12tq;
    CAN1_InitStructure.CAN_BS2 = CAN_BS2_5tq;
    CAN1_InitStructure.CAN_SJW = CAN_SJW_1tq;

    if (CAN_Init(CAN1, &CAN1_InitStructure))
    {

        /**************************************
            Init of Filter 0
            FMR (Master Control Register)
            FAR1 (Master Status Register)
            FSR1 (Bit Timing Register)
            set to Identifier Mask Mode
            -> filtering according to ID and Mask
        **************************************/
        CAN_FilterInitTypeDef filter;
        filter.CAN_FilterIdHigh = 0x0;
        filter.CAN_FilterIdLow = 0x20012;
        filter.CAN_FilterMaskIdHigh = 0x0;
        filter.CAN_FilterMaskIdLow = 0x20012;

        filter.CAN_FilterFIFOAssignment = 0;
        filter.CAN_FilterNumber = 0;
        filter.CAN_FilterMode = CAN_FilterMode_IdMask;
        filter.CAN_FilterScale = CAN_FilterScale_16bit;

        filter.CAN_FilterActivation = enable;

        CAN_FilterInit(&filter);

    }
    else
    {
        TFT_TextPuts("Error with CAN-Init \n", &Font_11x18, 0xffffff, 0x000000);
        while(true);
    }
    /***********************************************************

        Initialization of NVIC to enable Receive Interrupt

    ***********************************************************/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    // Timer Interrupts
    NVIC_InitTypeDef exti;
    exti.NVIC_IRQChannel = CAN1_RX0_IRQn;
    exti.NVIC_IRQChannelCmd = ENABLE;
    exti.NVIC_IRQChannelSubPriority = 0;
    exti.NVIC_IRQChannelPreemptionPriority = 15;
    NVIC_Init(&exti);

    // CAN_ITCONNVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);


    CAN_ITConfig(CAN1, CAN_IT_FMP0, enable);

}
/*******************************************************************
*																   *
*		 Transmit CAN-Messages and CAN-Connect NMT  			   *
*																   *
********************************************************************/


/*******************************************************************
*																   *
*		 Interrupt Handler for CAN-Receive						   *
*																   *
********************************************************************/
// CAN cleared auto pending, PM 126,
void CAN1_RX0_IRQHandler(void)
{
    CanTxMsg msg;
    CAN_Receive(CAN1, CAN_FIFO0, &msg);

}
