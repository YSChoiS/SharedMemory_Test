//
// Created by ys on 24. 1. 29.
//
#include "YSsharedMemory.hpp"

void _JOINT_::getcurrentJointPos(Eigen::VectorXd& CurrnetJointPos)
{
    CurrnetJointPos = mCurrentJointPosition;
}

void _JOINT_::getcurrentJointVel(Eigen::VectorXd& CurrnetJointVel)
{
    CurrnetJointVel = mCurrentJointVelocity;
}

void _JOINT_::getcurrentJointTorque(Eigen::VectorXd& CurrnetJointTorque)
{
    CurrnetJointTorque =  mCurrentJointTorque;
}

void _JOINT_::setcurrentJointPos(const Eigen::VectorXd& CurrnetJointPos)
{
    mCurrentJointPosition = CurrnetJointPos;
}

void _JOINT_::setcurrentJointVel(const Eigen::VectorXd& CurrnetJointVel)
{
    mCurrentJointVelocity = CurrnetJointVel;
}

void _JOINT_::setcurrentJointTorque(const Eigen::VectorXd& CurrnetJointTorque)
{
    mCurrentJointTorque = CurrnetJointTorque;
}

double _TIME_::getVisualdT() const
{
    return mVisualdT;
}

void _TIME_::updateCurrentTime(long long &a)
{
    mCurrentTime += a;
}

double _TIME_::getCurrentTime()
{
    return mCurrentTime;
}