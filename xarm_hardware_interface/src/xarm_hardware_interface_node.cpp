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
    joint_positions = xarmrobot.readJointsPosition();
    xarmrobot.setJointPosition(2, 400); 

}

