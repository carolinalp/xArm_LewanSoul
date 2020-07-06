#include <xarm_hardware_interface/xarm_hardware_interface.h>
#include <ros/callback_queue.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "xarm_hardware_interface");
    ros::CallbackQueue ros_queue;

    ros::NodeHandle nh;
    nh.setCallbackQueue(&ros_queue);
    xarm_hardware_interface::xarmHardwareInterface rhi(nh);
    usleep(5*1000000);
    

    ros::MultiThreadedSpinner spinner(0);
    spinner.spin(&ros_queue);
    return 0;
}/     xarm::xarm xarmrobot;
//     std::vector<std::string> joint_names = {"xarm_2_joint", "xarm_3_joint", "xarm_5_joint", "xarm_6_joint", "xarm_4_joint"};
    
//     std::vector<double> joint_positions;
    
//     xarmrobot.setJointPosition(joint_names[0], 0.0, 1000);
//     usleep(2*1000000);
//     xarmrobot.setJointPosition(joint_names[1], 0.0,1000); 
//     usleep(2*1000000);
//     xarmrobot.setJointPosition(joint_names[2], 0.0, 1000);
//     usleep(2*1000000);
//     xarmrobot.setJointPosition(joint_names[3], 0.0, 1000);
//     usleep(2*1000000);
//     xarmrobot.setJointPosition(joint_names[4], 0.0, 1000);
//     usleep(2*1000000);
    
   
//     joint_positions = xarmrobot.readJointsPosition(joint_names);
// }