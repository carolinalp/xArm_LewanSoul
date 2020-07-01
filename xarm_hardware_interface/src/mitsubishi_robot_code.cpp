#include <controller_manager/controller_manager.h>
#include <xarm_hardware_interface/mitsubishi_code.h>
int main(int argc, char** argv)
{
    ros::init(argc, argv, "mitsubishi_arm_hardware_interface");
    ros::NodeHandle node;

    hardware_interface::JointStateInterface  jnt_state_interface_;
    hardware_interface::PositionJointInterface jnt_pos_interface_;

    MitsubishiArmInterface robot(node);
    robot.init(jnt_state_interface_, jnt_pos_interface_);
    controller_manager::ControllerManager cm(&robot, node);
    
    printf("##############    after sleep ###############\n");

    ros::AsyncSpinner spinner(4);
    spinner.start();
    printf("##############    after Star ###############\n");
    usleep(5*1000000);
    ros::Time previous=ros::Time::now();

    ros::Rate rate(1);
    

    while (ros::ok())
    {
        printf("##############    inside while   ###############\n");
        ros::Duration period;
        robot.readHW();
        ros::Time now=ros::Time::now();
        period=now-previous;
        //std::cout << "period:"<<period<<std::endl;
        cm.update(now, period);
        robot.writeHW();
        rate.sleep();
    }

    spinner.stop();

    return 0;
}

