//
// Created by camel on 22. 9. 13.
//

#ifndef RAISIM_SHAREDMEMORY_H
#define RAISIM_SHAREDMEMORY_H

#include "Eigen/Dense"


#define MAX_COMMAND_DATA    10
#define MAX_CUSTOM_DATA     20


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
