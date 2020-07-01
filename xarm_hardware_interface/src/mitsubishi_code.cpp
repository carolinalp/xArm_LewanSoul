 
#include <xarm_hardware_interface/mitsubishi_code.h>
#include <sstream>
MitsubishiArmInterface::MitsubishiArmInterface(ros::NodeHandle& nh): nh_(nh)
{
    //joint_state_pub=n_priv.advertise<sensor_msgs::JointState>( "joint_states", 1);

    pos.resize(joint_number);
    vel.resize(joint_number);
    eff.resize(joint_number);
    cmd.resize(joint_number);
    cmd_previous.resize(joint_number);



    std::cout << "Init done!" << '\n';

//    init();
    return;
}

MitsubishiArmInterface::~MitsubishiArmInterface()
{
 
}



bool MitsubishiArmInterface::init(hardware_interface::JointStateInterface  & jnt_state_interface_,
                                  hardware_interface::PositionJointInterface & jnt_pos_interface_)
{
    // Get joint names
    nh_.getParam("/xarm/hardware_interface/joints", joint_names_);

    // connect and register the joint state interface
    hardware_interface::JointStateHandle state_handle_j2("xarm_2_joint", &pos[0], &vel[0], &eff[0]);
    jnt_state_interface_.registerHandle(state_handle_j2);

    hardware_interface::JointStateHandle state_handle_j3("xarm_3_joint", &pos[1], &vel[1], &eff[1]);
    jnt_state_interface_.registerHandle(state_handle_j3);

    hardware_interface::JointStateHandle state_handle_j4("xarm_4_joint", &pos[2], &vel[2], &eff[2]);
    jnt_state_interface_.registerHandle(state_handle_j4);

    hardware_interface::JointStateHandle state_handle_j5("xarm_5_joint", &pos[3], &vel[3], &eff[3]);
    jnt_state_interface_.registerHandle(state_handle_j5);

    hardware_interface::JointStateHandle state_handle_j6("xarm_6_joint", &pos[4], &vel[4], &eff[4]);
    jnt_state_interface_.registerHandle(state_handle_j6);

    registerInterface(&jnt_state_interface_);

    // connect and register the joint position interface
   
    hardware_interface::JointHandle pos_handle_j2(jnt_state_interface_.getHandle("xarm_2_joint"), &cmd[0]);
    jnt_pos_interface_.registerHandle(pos_handle_j2);

    hardware_interface::JointHandle pos_handle_j3(jnt_state_interface_.getHandle("xarm_3_joint"), &cmd[1]);
    jnt_pos_interface_.registerHandle(pos_handle_j3);

    hardware_interface::JointHandle pos_handle_j4(jnt_state_interface_.getHandle("xarm_4_joint"), &cmd[2]);
    jnt_pos_interface_.registerHandle(pos_handle_j4);

    hardware_interface::JointHandle pos_handle_j5(jnt_state_interface_.getHandle("xarm_5_joint"), &cmd[3]);
    jnt_pos_interface_.registerHandle(pos_handle_j5);

    hardware_interface::JointHandle pos_handle_j6(jnt_state_interface_.getHandle("xarm_6_joint"), &cmd[4]);
    jnt_pos_interface_.registerHandle(pos_handle_j6);

    registerInterface(&jnt_pos_interface_);
    

}




void MitsubishiArmInterface::readHW()
{
    std::vector<double> position_t;
    position_t = xarm.readJointsPosition(joint_names_);
    for (int i = 0; i < 5; i++) {
        //printf ("joint position %d : %f\n", i, position_t[i]);
        pos[i]=position_t[i];
        }
    
    /*pos[1]=1.0;
    pos[2]=1.0;
    pos[3]=1.0;
    pos[4]=1.0;


    eff[0]=0.0;
    eff[1]=0.0;
    eff[2]=0.0;
    eff[3]=0.0;
    eff[4]=0.0;
    
    vel[0]=0.0;
    vel[1]=0.0;
    vel[2]=0.0;
    vel[3]=0.0;
    vel[4]=0.0;*/
    

}


void MitsubishiArmInterface::writeHW()
{
    // positionJointSoftLimitsInterface.enforceLimits(elapsed_time);
    for (int i = 0; i < 5; i++) {  //change 6 for num_joints
        xarm.setJointPosition(joint_names_[i], cmd[i], 1000);
        //printf ("joint position command %f\n", cmd[i]);
    }

/*    if(isEqual(cmd_previous[0],cmd[0],0.00001)&&
       isEqual(cmd_previous[1],cmd[1],0.00001)&&
       isEqual(cmd_previous[2],cmd[2],0.00001)&&
       isEqual(cmd_previous[3],cmd[3],0.00001)&&
       isEqual(cmd_previous[4],cmd[4],0.00001)&&
       isEqual(cmd_previous[5],cmd[5],0.00001))
    {

        cmd_previous=cmd;
        return;
    }
    static int new_command_count=0;
    new_command_count++;
    std::cout << "new command:"<< new_command_count << std::endl;
    //boost::mutex::scoped_lock lock(io_mutex);
    // WRITE MOVE to robot
    unsigned char cmd_msg[] = "2\r\n";
    int n_written = 0;

    do
    {
        n_written += write( USB, &cmd_msg[n_written], 1 );
    }
    while (cmd_msg[n_written-1] != '\n');

    // READ RESPONSE (M)
    char buf [256];
    memset (&buf, '\0', sizeof buf);
    int n = 0;
    std::string response;

    do
    {
        n += read( USB, &buf, 1);
        response.append( buf );
    }
    while( buf[0] != '\n');

    if (response.find("M\r\n") == std::string::npos)
    {
        std::cout << "didn-t find M!" << '\n';
        exit(-1);
    }

    response.clear();
    // END READ

    std::stringstream write_msg;
    //std::cout << cmd[1] << std::endl;
    write_msg << double(cmd[0]) << "," <<cmd[1] << "," << cmd[2] << "," << cmd[3] << "," << cmd[4] << "," << cmd[5] << "\r\n";

    std::string write_str=write_msg.str();
    //std::cout << "writing command:" << write_str<< std::endl;

    // Write command
    write( USB, write_str.c_str(), write_str.size());
    cmd_previous=cmd;
    // READ RESPONSE (E)
    memset (&buf, '\0', sizeof buf);
    n = 0;
    //std::cout << "getting respoinse"<< std::endl;

    do
    {
        n += read( USB, &buf, 1);
        response.append( buf );
    }
    while( buf[0] != '\n');

    if (response.find("E\r\n") == std::string::npos)
    {
        std::cout << "didn-t find E!" << '\n';
        exit(-1);
    }


    // END READ*/
}