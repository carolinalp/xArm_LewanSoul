#include "ros/ros.h"
#include <stdexcept>
#include <xarm_hardware_interface/xarm.h>
#include <stdio.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>
#define MAX_STR 255
#include <string>
using std::string;

namespace xarm
{
	xarm::xarm()
	{
		/*
		new full-speed USB device number 52 using xhci_hcd
		[  520.458387] usb 1-1: New USB device found, idVendor=0483, idProduct=5750
		[  520.458392] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
		[  520.458395] usb 1-1: Product: LOBOT
		[  520.458398] usb 1-1: Manufacturer: MyUSB_HID
		[  520.458401] usb 1-1: SerialNumber: 497806693832

		
		for (int i = 0; i < 8; i++)
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
	
		unsigned char buf[65];
		wchar_t wstr[MAX_STR];
		hid_device *handle;
		int i;
		int res;
		
		struct hid_device_info *devs, *cur_dev;
		
		// Initialize the hidapi library
		if (hid_init())
			return;

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
		
			std::wstring ws(cur_dev->product_string);
			string product(ws.begin(), ws.end());
		
			if (product=="LOBOT")
			{
				printf("LOBOT found \n");
				break;
			}
			cur_dev = cur_dev->next;
		}

		handle = hid_open_path(cur_dev->path);
		if (!handle) {
			printf("unable to open device\n");
 			return;
		}
		printf("device opened \n");
		hid_free_enumeration(devs);
		
		
		// Read the Manufacturer String
		res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
		printf("Manufacturer String: %ls\n", wstr);
		
		/*// Read the Product String
		res = hid_get_product_string(handle, wstr, MAX_STR);
		wprintf(L"Product String: %s\n", wstr);

		// Read the Serial Number String
		res = hid_get_serial_number_string(handle, wstr, MAX_STR);
		wprintf(L"Serial Number String: (%d) %s\n", wstr[0], wstr);

		// Read Indexed String 1
		res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
		wprintf(L"Indexed String 1: %s\n", wstr);*/
		
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
