#include "ros/ros.h"
#include <stdexcept>
#include <xarm_hardware_interface/xarm.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 255
#include <string>
using std::string;

namespace xarm
{
	xarm::xarm()
	{		
		// Initialize the hidapi library
		if (hid_init())
			return;
		int found=0;
		devs = hid_enumerate(0x0, 0x0);
		cur_dev = devs;	
		while (cur_dev) {
					
			std::wstring ws(cur_dev->product_string);
			string product(ws.begin(), ws.end());
		
			if (product=="LOBOT")
			{
				ROS_INFO("LOBOT found \n");
				found=1;
				break;
			}
			cur_dev = cur_dev->next;
		}
		if (found==0)
		{
			ROS_ERROR("LOBOT not found, make sure it is power on \n");
			throw std::exception();
		}

		handle = hid_open_path(cur_dev->path);
		
		if (!handle) {
			ROS_ERROR("unable to open device\n");
 			throw std::exception();
		}
		ROS_INFO("Device opened \n");
		hid_free_enumeration(devs);
		
	}

	xarm::~xarm()
	{
		hid_close(handle);

		/* Free static HIDAPI objects. */
		hid_exit();
		
	}

	void xarm::printDeviceInformation()
	{
		devs = hid_enumerate(0x0, 0x0);
		cur_dev = devs;	
		while (cur_dev) {
			printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls", cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
			printf("\n");
			printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
			printf("  Product:      %ls\n", cur_dev->product_string);
			printf("  Release:      %hx\n", cur_dev->release_number);
			printf("  Interface:    %d\n",  cur_dev->interface_number);
			printf("\n");
		
			cur_dev = cur_dev->next;
		}
	}

	std::vector<double> xarm::readJointsPosition()
	{
		int res;
		std::vector<double> joint_positions;
		unsigned char buf[65];

		joint_positions.resize(6);
		buf[0] = 0x55;
		buf[1] = 0x55;
		buf[2] = 9;
		buf[3] = 21;
		buf[4] = 6;
		buf[5] = 1;
		buf[6] = 2;
		buf[7] = 3;
		buf[8] = 4;
		buf[9] = 5;
		buf[10] = 6;
		res = hid_write(handle, buf, 17);
		
		if (res < 0) {
			printf("Unable to write()\n");
			printf("Error: %ls\n", hid_error(handle));
		}
		
		res = 0;
		while (res == 0) {
			res = hid_read(handle, buf, sizeof(buf));
			if (res == 0)
				printf("waiting...\n");
			if (res < 0)
				printf("Unable to read()\n");
			
			usleep(500*1000);
			
		}

		int id, p_lsb, p_msb, pos;
		for (int i=0; i< 6; i++){
			id = buf[5+3*i];
			p_lsb= buf[5+3*i+1];
			p_msb= buf[5+3*i+2];
			joint_positions[i] = (p_msb << 8) + p_lsb;
			printf("servo %d in joint_position %f \n", id, joint_positions[i]);
		}

		return joint_positions;
	}
	
	void  xarm::setJointPosition(int joint_id, int position, int time=1000)
	{
		/*
        CMD_SERVO_MOVE
        0x55 0x55 len 0x03 [time_lsb time_msb, id, pos_lsb pos_msb]
        Servo position is in range [0, 1000]
        */
	    
		unsigned char buf[65];
		unsigned char t_lsb,t_msb, p_lsb, p_msb;
		int res;
		
        t_lsb= time & 0xFF;
		t_msb = time >> 8;
		p_lsb = position & 0xFF;
		p_msb = position >> 8;

		buf[0] = 0x55;
		buf[1] = 0x55;
		buf[2] = 8;
		buf[3] = 0x03;
		buf[4] = 1;
		buf[5] = t_lsb;
		buf[6] = t_msb;
		buf[7] = joint_id+1;
		buf[8] = p_lsb;
		buf[9] = p_msb;
		
		res = hid_write(handle, buf, 17);
		
		if (res < 0) {
			printf("Unable to write()\n");
			printf("Error: %ls\n", hid_error(handle));
		}

	} 
	
}
