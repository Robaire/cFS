#ifndef _imu_app_msg_h_
#define _imu_app_msg_h_

// App Command Codes
// What do these mean?
#define IMU_APP_NOOP_CC 0
#define IMU_APP_PROCESS_CC 1

// No arguments command struct (AKA it is just a header)
typedef struct 
{
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} IMU_NoArgsCmd_t;

// "NoArgs" Commands
typedef IMU_NoArgsCmd_t IMU_Noop_t;
typedef IMU_NoArgsCmd_t IMU_Process_t;

// IMU App Housekeeping Stucture
// Is this the data that gets sent to house keeping?
// Is one of these needed for all outgoing data?
typedef struct
{
    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 spare[2];
} IMU_HkTlm_Payload_t;

typedef struct
{
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    IMU_HkTlm_Payload_t Payload;
} OS_PACK IMU_HkTlm_t;

#endif
