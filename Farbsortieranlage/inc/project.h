/****************************************************
	Project Specific Definitions and Declarations
****************************************************/
#ifndef PROJECT_H
#define PROJECT_H

#include "ILI9341_CmdDriver.h"

//********************************
// Declaration of Bits, Type sbit

//********************************
// Declaration of Constants
#define true               1
#define false              0
#define start              1
#define stop               0
#define high               1
#define low                0
#define on                 1
#define off                0
#define enable             1
#define disable            0
#define active             1
#define inactive           0
#define forwards           0x01
#define numOfRows           240


typedef enum cmd
{
    rdMADCTLToggleRGB,
    rdDisplaySeveralData,
    wrDisplayInversion,
    rdChangeDispDataDir,
    wrColourRowsAndText2TFT,
    wrText2TFT,
    wrString1ToTFT,
    wrString2ToTFT,
    noCmd,
} cmd;


//********************************
// Declaration of Global Variables

//************************************
// Method Declaration
extern void ProjectInit( void);

// Präprozessor C
#endif
