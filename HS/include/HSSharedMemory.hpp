//
// Created by hs on 23. 7. 25.
//

#ifndef TOEBOT_SHAREDMEMORY_HPP
#define TOEBOT_SHAREDMEMORY_HPP

#include <Eigen/Dense>


typedef struct _SH_COMMAND_
{
    unsigned char UserCommand;
}SH_COMMAND;

typedef struct _SH_DATA_
{
    // For basic
    double localTime;
    // Base states on Global frame

    Eigen::Matrix<double,4,1> GlobalBaseQuaternion;
    Eigen::Matrix<double,3,1> GlobalBaseEulerAngle;
    Eigen::Matrix<double,3,1> GlobalBaseAngularVelocity;


}SH_DATA;

#endif //TOEBOT_SHAREDMEMORY_HPP
