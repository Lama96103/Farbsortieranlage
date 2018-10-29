/*
**              Staudinger Simulation Model
**					Process Line
**					and CANOpen
**
**********************************************************************/

#ifndef COLORSORT_H__
#define COLORSORT_H__


#define CAN_NMTID               0x00
#define SIM_Model_ActorDO     	0x201
#define SIM_Model_SensorDI    	0x181

#define TFTReframeOn            1
#define TFTReframeOff           0

#define Model_DLC               1

//-------- CAN-Defines --------------

// Data Output from Process Line


//********************************
// Declaration of Global Variables
bool flagOnholdTransmit;
bool flagRequestTransmitNMT;
bool flagRequestTransmitPL;

// Declaration of Global Functions
// Data Input Functions from Process Line

// Data Output Functions from Process Line

// further SIM functions
extern void SIM_Init();

extern void SIM_Model_TransmitNewData();


void ColorSortRecieveData(CanRxMsg *msg);

#endif // !COLORSORT_H__
