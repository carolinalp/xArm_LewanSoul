
#ifndef XARM__H
#define XARM__H
#include <hidapi/hidapi.h>
#include <sstream>

namespace xarm
{
	class xarm
	{
		public:
			xarm();
			~xarm();
			
			std::vector<double> readJointsPosition();
			void  setJointPosition(int joint_id, double position_rad, int time); 
			double convertUnitToRad(int joint_id, int unit);
			int convertRadToUnit(int joint_id, double rad);

		private:
			hid_device *handle;
			struct hid_device_info *devs, *cur_dev; 
			void printDeviceInformation();
			int matrix_unit_rad[6][2];
	};
}

#endif