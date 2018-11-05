#pragma once

#define UNLOADING_ID 0x13


// Init Function
int Unloading_Init();

// On Recieve Data
void Unloading_RecieveData(CanRxMsg *msg);

// On Tick
void Unloading_Tick(unsigned int tick);
