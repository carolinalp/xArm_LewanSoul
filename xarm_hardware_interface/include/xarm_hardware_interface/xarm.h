
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
			void  setJointPosition(int joint_id, int position, int time); 

		private:
			hid_device *handle;
			struct hid_device_info *devs, *cur_dev; 
			void printDeviceInformation();
	};
}

#endif