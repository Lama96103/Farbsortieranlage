#pragma once

#define LOADING_ID 0x11


// Init Function
int Loading_Init();

// On Recieve Data
void Loading_RecieveData(CanRxMsg *msg);

// On Tick
void Loading_Tick(unsigned int tick);
