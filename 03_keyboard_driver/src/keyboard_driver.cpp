#include <ncurses.h>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>

class KeyboardDriver
{
public:
  KeyboardDriver();
  void keyLoop();

private:


  ros::NodeHandle nh_;
  double linear_, angular_, l_scale_, a_scale_;
  ros::Publisher twist_pub_;

};
//
KeyboardDriver::KeyboardDriver():
  linear_(0),
  angular_(0),
  l_scale_(0.25),
  a_scale_(1)
{
  nh_.param("scale_angular", a_scale_, a_scale_);
  nh_.param("scale_linear", l_scale_, l_scale_);

  twist_pub_ = nh_.advertise<geometry_msgs::Twist>("rover_velocity_controller/cmd_vel", 1);
}

void quit(int sig)
{
  (void)sig;
  endwin();
  ros::shutdown();
  exit(0);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "keyboard_driver");
  KeyboardDriver keyboard_driver;

  signal(SIGINT,quit);

  keyboard_driver.keyLoop();

  return(0);
}


void KeyboardDriver::keyLoop()
{
  //we will be sending commands of type "twist"
  geometry_msgs::Twist base_cmd;

  char cmd;
  initscr(); //get terminal environment variables
  printw("Type a command and then press enter. "
    "Use 'w','a','s', and 'd' to navigate and 'q' to exit.\n");
  cbreak();  //line buffering disabled; pass on everything
  timeout(500);  //getch blocks for 1 second

  while(nh_.ok()){

    cmd = getch();

    if(cmd !='w' && cmd !='a' && cmd !='s' && cmd !='d' && cmd !='q' && cmd != 'e' && cmd != -1)
    {
      std::cout << "unknown command...\n\r";
      continue;
    }

    base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0.0;
    //move forward
    if(cmd =='w'){
      linear_ = 1.0;
      angular_ = 0.0;
    }
    //move backwards
    else if(cmd =='s'){
      linear_ = -1.0;
      angular_ = 0.0;
    }
    //turn left (yaw) and drive forward at the same time
    else if(cmd =='a'){
      linear_ = 0.0;
      angular_ = 1;
    }
    //turn right (yaw) and drive forward at the same time
    else if(cmd =='d'){
      linear_ = 0.0;
      angular_ = -1;
    }
    else if(cmd == -1 || cmd == 'q'){
      linear_ = 0.0;
      angular_ = 0.0;
    }
    // //quit
    // else if(cmd =='q'){
    //   base_cmd.angular.z = 0.0;
    //   base_cmd.linear.x = 0.0;
    // }
    base_cmd.angular.z = angular_ * a_scale_;
    base_cmd.linear.x = linear_ * l_scale_;
    //publish the assembled command
    twist_pub_.publish(base_cmd);

    std::cout << "\n\r";
  }
  nocbreak(); //return terminal to "cooked" mode
  return;
}
