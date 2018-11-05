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
bool sort_isOpen = false;
bool light_isOn = false;
uint8_t actor = 0;
uint8_t sensor;

unsigned int tick = 0;
unsigned int sortOpenTick = 0;

enum Color { none, orangeBall, blueBall, greenBall} color;

void OpenSort();
void CloseSort();

/*********************************************

    Checking the sensor bits

*********************************************/
void GetColor(uint8_t sens){

    if(sens & 0x01){
        color = orangeBall;
    }else if(sens & 0x02){
        color = blueBall;
    }else if(sens & 0x03){
        color = greenBall;
    }
}

void CheckSensor(uint8_t sens){

    if((sensor == 0x40) && color == orangeBall){
        OpenSort();
    }else if((sensor == & 0x50) && color == blueBall){
        OpenSort();
    }else if((sensor == 0x60) && color == greenBall){
        OpenSort();
    }
}


/*********************************************

    Set / Reset the Actor bits

*********************************************/
void OpenSort(){
        uint8_t data = actor | (0x80);
        data = data & (~0x70);
        data = data | (0x60);
        data = data & (~0x50);
        Send_Data(COLOR_ID, data, 0);
        resetFlag = true;
        waited = false;
        actor = data;
        sort_isOpen = true;
        sortOpenTick = 0;
}

void CloseSort(){
        uint8_t data = actor & (~0x80);
        data = data | (0x70);
        data = data & (~0x60);
        data = data | (0x50);
        Send_Data(COLOR_ID, data, 0);
        resetFlag = true;
        waited = false;
        actor = data;

        sort_isOpen = false;
}

void TurnLampOn(){
    uint8_t data = actor | 0x08;
    Send_Data(COLOR_ID, data, 0);
    actor = data;
    light_isOn = true;
}

void TurnLampOff(){
    uint8_t data = actor & (~0x08);
    Send_Data(COLOR_ID, data, 0);
    actor = data;
    light_isOn = false;
}





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



void ColorSortRecieveData(CanRxMsg *msg){
    sensor = msg->Data[0];

    GetColor(sensor);
    CheckSensor(sensor);
}



void ColorSortTick(){

    if(tick%100==0){
        if(resetFlag && waited){
            uint8_t data = actor & 0x0f;
            Send_Data(COLOR_ID, data, 0);
        }
        waited = true;

        if(sort_isOpen){
            sortOpenTick++;
            if(sortOpenTick > 10){
                CloseSort();
            }
        }
    }
    tick++;
}

/*********************************************

    Initialization of Simulation Model

*********************************************/
void SIM_Init()
{
    CloseSort();
    TurnLampOn();
    color = none;
}
