/*
**              Staudinger Simulation Model
**
**					and CANOpen
**
**********************************************************************/

#include "global.h"


// file global variables for Simulation Model
uint8_t Model_ReceiveData[] = {0x00};
uint8_t Model_TransmitData[] = {0x00, 0x00, 0x00};

bool resetFlag = false;
bool waited;
uint8_t actor = 0;
uint8_t sensor;

/*********************************************

    Checking the sensor bits

*********************************************/


/*********************************************

    Set / Reset the Actor bits

*********************************************/





/*********************************************

    Text Messages

*********************************************/
void SIM_Model_Manual()
{
    TFT_ReframeAddrSet(0, TFT_HEIGHT(), 0, TFT_WIDTH());
    TFT_MemoryWrite(red, (numOfRows * 20));
    TFT_MemoryWriteContinue(white, (numOfRows * 280));
    TFT_MemoryWriteContinue(yellow, (numOfRows * 20));
    TFT_ReframeAddrSet(0, TFT_HEIGHT(), 0, TFT_WIDTH());
    TFT_TextPuts("Successful Initialization & NMT-Transmission\n", &Font_7x10, yellow, red);
}

/*********************************************

    Initialization of Simulation Model

*********************************************/

/*********************************************
    Send Message if new TxData available
*********************************************/
void SIM_Model_TransmitNewData()
{

}

/*********************************************

    Service the Interrupts of the Simulation Model

*********************************************/

/*
DATA:
    msg.Data | 0x08     Enable Lampe

*/
bool open = false;
int color = 2;
void ColorSortRecieveData(CanRxMsg *msg){
    sensor = msg->Data[0];
    TurnLampOn();

    if(sensor & 0x01){
        color = 1;
    }
    if(sensor & 0x02){
        color = 2;
    }
    if(sensor & 0x03){
        color = 3;
    }


    if((sensor == 0x40) && color == 1){
        OpenSort();
    }else if((sensor == 0x50) && color == 2){
        OpenSort();
    }else if((sensor == 0x60) && color == 3){
        OpenSort();
    }

    color = 0;


}

void OpenSort(){
        uint8_t data = actor | (0x80);
        data = data & (~0x70);
        data = data | (0x60);
        data = data & (~0x50);
        Send_Data(0x200 + 0x12, data, 0);
        resetFlag = true;
        waited = false;
        actor = data;
}

void CloseSort(){
        uint8_t data = actor & (~0x80);
        data = data | (0x70);
        data = data & (~0x60);
        data = data | (0x50);
        Send_Data(0x200 + 0x12, data, 0);
        resetFlag = true;
        waited = false;
        actor = data;
}

void TurnLampOn(){
    uint8_t data = actor | 0x08;
    Send_Data(0x200 + 0x12, data, 0);
    actor = data;
}

void TurnLampOff(){
    uint8_t data = actor & (~0x08);
    Send_Data(0x200 + 0x12, data, 0);
    actor = data;
}

unsigned int tick = 0;

void ColorSortTick(){

    if(tick%100==0){
        if(resetFlag && waited){
            uint8_t data = actor & 0x0f;
            Send_Data(0x200 + 0x12, data, 0);
        }
        waited = true;
    }
    tick++;



}


void SIM_Init()
{
    CloseSort();
    TurnLampOn();
}
