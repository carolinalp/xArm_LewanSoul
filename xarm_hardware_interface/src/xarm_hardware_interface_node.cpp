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
    
    double position ;
    std::string jointName="xarm_5_joint";
    position = xarmrobot.readJointPosition(jointName);

    printf("%f\n", position);
    

}

