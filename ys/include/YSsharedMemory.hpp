#ifndef SINGLELEGMPC_SHAREDMEMORY_HPP
#define SINGLELEGMPC_SHAREDMEMORY_HPP

#include "Eigen/Dense"

typedef class _TIME_
{
public:
    _TIME_(double VISUAL_dT)
        : mVisualdT(VISUAL_dT)
        , mCurrentTime(0)
    {
    }

    double getVisualdT() const;
    void updateCurrentTime(long long &a);
    double getCurrentTime();


private:
    const double mVisualdT;
    double mCurrentTime;
} TIME, * pTIME;

typedef class _JOINT_
{
public:
    _JOINT_(int NumofJoint)
        : mCurrentJointPosition(NumofJoint)
        , mCurrentJointVelocity(NumofJoint)
        , mCurrentJointTorque(NumofJoint)
    {
        mCurrentJointPosition.setZero();
        mCurrentJointVelocity.setZero();
        mCurrentJointTorque.setZero();
    }

    void getcurrentJointPos(Eigen::VectorXd& CurrnetJointPos);
    void getcurrentJointVel(Eigen::VectorXd& CurrnetJointVel);
    void getcurrentJointTorque(Eigen::VectorXd& CurrnetJointTorque);
    void setcurrentJointPos(const Eigen::VectorXd& CurrnetJointPos);
    void setcurrentJointVel(const Eigen::VectorXd& CurrnetJointVel);
    void setcurrentJointTorque(const Eigen::VectorXd& CurrnetJointTorque);
private:
    Eigen::VectorXd mCurrentJointPosition;
    Eigen::VectorXd mCurrentJointVelocity;
    Eigen::VectorXd mCurrentJointTorque;
} JOINT, * pJOINT;


typedef class _SHM_
{
public:
    _SHM_(double VISUAL_dT, int NumofJoint)
        : timeVariable(VISUAL_dT)
        , jointVariable(NumofJoint)
    {
    }
    TIME timeVariable;
    JOINT jointVariable;
} SHM, * pSHMYS;


#endif //SINGLELEGMPC_SHAREDMEMORY_HPP
