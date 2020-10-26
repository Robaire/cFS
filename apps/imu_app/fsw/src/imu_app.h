#ifndef _imu_app_h_
#define _imu_app_h_

// Required headers
#include "cfe.h"
#include "cfe_error.h"
#include "cfe_evs.h"
#include "cfe_sb.h"
#include "cfe_es.h"

// App specific headers
#include "imu_app_msgids.h"
#include "imu_app_msg.h"

// Set the Command Pipe Depth
// What is the Command Pipe and why is it 32?
#define IMU_PIPE_DEPTH 32

// Buffer to hold telemetry data
// Does this need to be done for any data that will be passed around on the message buffer?
typedef union
{
    CFE_SB_Msg_t MsgHdr;
    IMU_HkTlm_t HkTlm;
} IMU_HkBuffer_t;

// Global App Data
typedef struct
{
    
    // Housekeeping telemetry packet
    IMU_HkBuffer_t HkBuf;

    // Run Status
    uint32 RunStatus;

    // Operational Data
    CFE_SB_PipeId_t CommandPipe;
    CFE_SB_MsgPtr_t MsgPtr;

    // Initialization data
    char PipeName[16];
    uint16 PipeDepth;
} IMU_AppData_t;

// Local Function Prototypes
void IMU_AppMain(void);
int32 IMU_AppInit(void);
void IMU_ProcessCommandPacket(CFE_SB_MsgPtr_t Msg);
void IMU_ProcessGroundCommand(CFE_SB_MsgPtr_t Msg);

#endif