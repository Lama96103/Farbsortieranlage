/*
**              Staudinger Simulation Model
**					Process Line
**					and CANOpen
**
**********************************************************************/
/*
#ifndef COLORSORT_H__
#define COLORSORT_H__
*/

#pragma once

//-------- CAN-Defines --------------
#define COLORSORT_ID                0x212

// Init Function
int ColorSort_Init();

// On Recieve Data
void ColorSort_RecieveData(CanRxMsg *msg);

// On Tick
void ColorSort_Tick(unsigned int tick);

//#endif // !COLORSORT_H__
