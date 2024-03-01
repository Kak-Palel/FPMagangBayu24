#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "arm_interfaces/msg/servo_parameters.hpp"
#include "arm_interfaces/msg/posisi_bidak.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class TranslatorTicTacToe : public rclcpp::Node
{
  public:
    TranslatorTicTacToe()
    : Node("bot_translator"), count_(0)
    {
      publisher_ = this->create_publisher<arm_interfaces::msg::ServoParameters>("topic_tes", 10);
      timer_ = this->create_wall_timer(
      3000ms, std::bind(&TranslatorTicTacToe::timer_callback, this));

      subscription_ = this->create_subscription<arm_interfaces::msg::PosisiBidak>(
      "to_move", 10, std::bind(&TranslatorTicTacToe::topic_callback, this, _1));
    }

  private:
    void topic_callback(const arm_interfaces::msg::PosisiBidak::SharedPtr msg)
    {
      RCLCPP_INFO(this->get_logger(), "Nerima");
    }
    rclcpp::Subscription<arm_interfaces::msg::PosisiBidak>::SharedPtr subscription_;

    std::vector<int> decide(const arm_interfaces::msg::PosisiBidak::SharedPtr msg)
    {
      /**
       * 
       * ANJENGGGGGG
       * 
       * HUAAAAA
       * 
       * 
       * 
      */
      std::vector<int> JANCOK = {0, 0, 0, 0};
      return JANCOK;
    }

    void timer_callback()
    {
      auto message = arm_interfaces::msg::ServoParameters();
      message.take1 = 1;
      message.take4 = 1;
      message.drop1 = 1;
      message.drop4 = 1;
      // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      std::cout<<"Publishing... " << count_++ << std::endl;
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<arm_interfaces::msg::ServoParameters>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TranslatorTicTacToe>());
  rclcpp::shutdown();
  return 0;
}