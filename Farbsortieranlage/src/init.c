/****************************************************
	Initialization of Ports, LCD, Timer and ...
****************************************************/
#include "global.h"CAN_Transmit
//#include "ILI9341.h"

void PortsInit(void)
// Recommendation: Switch DILs to pull down when used as input
/*
    Unusable Port Bits:
    A15 A14 A13 A12    A11      A8  A7            A2 A1
    B15 B14 B13 B12    B11 B10            B4   B3
    C15 C14     C12    C11 C10         C5 C4         C1
*/
{

}

void TimerInit(void)
{

}

void IntInit()
{

}

// TODO Init Nvic Correct
void UART_Init(void)
{
    USART_InitTypeDef usart1_init_struct;
    GPIO_InitTypeDef gpioa_init_struct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 |
                           RCC_APB2Periph_AFIO |
                           RCC_APB2Periph_GPIOA,
                           ENABLE);

    // PIN9 alternative function
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_9;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpioa_init_struct);
    // PIN10 alternative function
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_10;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpioa_init_struct);

    USART_Cmd(USART1, ENABLE);

    USART_StructInit(&usart1_init_struct);

    USART_Init(USART1, &usart1_init_struct);

    // Enable interrupt
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_InitTypeDef USART1_IRQ_init;

    USART1_IRQ_init.NVIC_IRQChannel = USART1_IRQn;
    USART1_IRQ_init.NVIC_IRQChannelPreemptionPriority = 1;
    USART1_IRQ_init.NVIC_IRQChannelSubPriority = 0;
    USART1_IRQ_init.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&USART1_IRQ_init);
    //NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_PriorityGroup_4,0,0));
    //NVIC_EnableIRQ(USART1_IRQn);
    //NVIC_PriorityGroup_1;
}

void ProjectInit(void)
{
    // UART_Init();
    CAN_Init4Models();

    CanTxMsg msg;

    msg.Data[0] = 0x01;
    msg.Data[1] = 0x00;
    msg.DLC = 2;
    msg.StdId = 0;
    msg.ExtId = 0;
    msg.IDE = CAN_Id_Standard;
    msg.RTR = 0;


    uint8_t mailBox = CAN_Transmit(CAN1, &msg);
    uint8_t status = CAN_TransmitStatus(CAN1, mailBox);
}


