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
    
    std::vector<double> joint_positions;
    xarmrobot.setJointPosition(1, -1.57, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(2, 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(3, 0.0,1000); 
    usleep(2*1000000);
    xarmrobot.setJointPosition(4, 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(5, 0.0, 1000);
    usleep(2*1000000);
    xarmrobot.setJointPosition(6, 0.0, 1000);
    usleep(2*1000000);
    joint_positions = xarmrobot.readJointsPosition();
}

