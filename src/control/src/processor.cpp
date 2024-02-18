#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class ControllerTicTacToe : public rclcpp::Node
{
  public:
    ControllerTicTacToe()
    : Node("bot_control"), count_(0)
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "ttt_state", 10, std::bind(&ControllerTicTacToe::topic_callback, this, _1));
    
      publisher_ = this->create_publisher<std_msgs::msg::String>("ttt_moves", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&ControllerTicTacToe::timer_callback, this));
      std::cout<<"constructor executed\n";
    }

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "A: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "SUSHI LUTUUU " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerTicTacToe>());
  rclcpp::shutdown();
  return 0;
}