#include <xarm_hardware_interface/xarm_hardware_interface.h>
int main(int argc, char** argv)
/*{
    ros::init(argc, argv, "xarm_hardware_interface");

    ros::NodeHandle nh;
 
    ros::AsyncSpinner spinner(1);
    spinner.start();
    xarm_hardware_interface::xarmHardwareInterface rhi(nh);

    ros::spin();
    return 0;
}*/

{
    xarm::xarm xarmrobot;
    std::vector<std::string> joint_names = {"xarm_2_joint", "xarm_3_joint", "xarm_5_joint", "xarm_6_joint", "xarm_4_joint"};
    
    std::vector<double> joint_positions;
    
    xarmrobot.setJointPosition(joint_names[0], 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(joint_names[1], 0.0,1000); 
    usleep(2*1000000);
    xarmrobot.setJointPosition(joint_names[2], 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(joint_names[3], 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(joint_names[4], 0.0, 1000);
    usleep(2*1000000);
    
   
    joint_positions = xarmrobot.readJointsPosition(joint_names);
}

