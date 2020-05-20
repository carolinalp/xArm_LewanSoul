#include "ros/ros.h"
#include <stdexcept>
#include <xarm_hardware_interface/xarm.h>

namespace xarm
{
	xarm::xarm()
	{
		/*for (int i = 0; i < 8; i++)
		{
			armRight.joints[i].setMotorId(i + 1);
			armLeft.joints[i].setMotorId(i + 16);
		}


		//armLeft
		armLeft.joints[0].name = "JointLeftShoulderPan";
		armLeft.joints[0].setMotorId(16);
		armLeft.joints[1].name = "JointLeftShoulderTilt";
		armLeft.joints[1].setMotorId(17);
		armLeft.joints[2].name = "JointLeftUpperArmRoll";
		armLeft.joints[2].setMotorId(18);
		armLeft.joints[3].name = "JointLeftElbowFlex";
		armLeft.joints[3].setMotorId(19);
		armLeft.joints[4].name = "JointLeftForearmRoll";
		armLeft.joints[4].setMotorId(20);
		armLeft.joints[5].name = "JointLeftWristFlex";
		armLeft.joints[5].setMotorId(21);
		armLeft.joints[6].name = "JointLeftWristRoll";
		armLeft.joints[6].setMotorId(22);
		armLeft.joints[7].name = "JointLeftGripper";
		armLeft.joints[7].setMotorId(23);

		armLeft.joints[6].setActuatorType(ACTUATOR_TYPE_SERVO);
		armLeft.joints[7].setActuatorType(ACTUATOR_TYPE_SERVO);

		armLeft.joints[6].setServoLimits(0, 180);
		armLeft.joints[7].setServoLimits(20, 120);*/
	}

	xarm::~xarm()
	{

	}
	double xarm::readJointPosition(std::string jointName)
	{
		double position=0.0;
		return position;
	}
	
	void  xarm::setJointPosition(std::string jointName, double position)
	{

	} 


	
}
