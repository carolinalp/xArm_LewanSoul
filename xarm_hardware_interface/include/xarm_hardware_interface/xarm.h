
#ifndef XARM__H
#define XARM__H

#include <sstream>

namespace xarm
{
	class xarm
	{
		public:
			xarm();
			~xarm();

			double readJointPosition(std::string jointName);
			void  setJointPosition(std::string jointName, double position); 
	};
}

#endif