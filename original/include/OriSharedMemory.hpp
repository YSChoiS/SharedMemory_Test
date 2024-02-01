//
// Created by camel on 22. 9. 13.
//

#ifndef RAISIM_SHAREDMEMORY_H
#define RAISIM_SHAREDMEMORY_H

#include "Eigen/Dense"

#define CMD_dT              0.002
#define HIGH_CONTROL_dT     0.02
#define LOW_CONTROL_dT      0.002
#define VISUAL_dT           0.01
#define IMU_dT              0.005
#define ESTIMATOR_dT        0.002
#define MAX_COMMAND_DATA    10
#define MAX_CUSTOM_DATA     20
#define PI                  3.141592
#define R2D                 57.2957802
#define D2R                 0.0174533
#define MPC_HORIZON         5


typedef struct _UI_COMMAND_
{
    int userCommand;
    int gaitCommand;
    char userParamChar[MAX_COMMAND_DATA];
    int userParamInt[MAX_COMMAND_DATA];
    double userParamDouble[MAX_COMMAND_DATA];
} UI_COMMAND, * pUI_COMMAND;

typedef struct _SHMORI_
{

    double localTime;

    Eigen::Vector3d estimatedGroundSlope;

} SHMORI, * pSHMORI;

typedef struct _CUSTOM_DATA_
{
    double customVariableDouble[MAX_CUSTOM_DATA];
    int customVariableInt[MAX_CUSTOM_DATA];
} CUSTOM_DATA, * pCUSTOM_DATA;



#endif //RAISIM_SHAREDMEMORY_H
