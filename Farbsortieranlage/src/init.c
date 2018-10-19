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

void ProjectInit(void)
{
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


