#pragma once

#define STEPMOTOR_ID 0x15


// Init Function
int StepMotor_Init();

// On Recieve Data
void StepMotor_RecieveData(CanRxMsg *msg);

// On Tick
void StepMotor_Tick(unsigned int tick);
