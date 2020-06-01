
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
			hid_device *handle;
			std::vector<double> readJointsPosition();
			void  setJointPosition(int joint_id, int position); 
	};
}

#endif