#pragma once

#define SERVOMOTOR_ID 0x14


// Init Function
int ServoMotor_Init();

// On Recieve Data
void ServoMotor_RecieveData(CanRxMsg *msg);

// On Tick
void ServoMotor_Tick(unsigned int tick);
