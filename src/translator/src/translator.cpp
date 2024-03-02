#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
#include <vector>

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

      subscription_ = this->create_subscription<arm_interfaces::msg::PosisiBidak>(
      "to_move", 10, std::bind(&TranslatorTicTacToe::topic_callback, this, _1));
    }

  private:
    void topic_callback(const arm_interfaces::msg::PosisiBidak::SharedPtr msg)
    {
      RCLCPP_INFO(this->get_logger(), "Nerima");
      timer_callback(decide(msg));
    }
    rclcpp::Subscription<arm_interfaces::msg::PosisiBidak>::SharedPtr subscription_;

    float findDist(float x1, float x2, float y1, float y2)
    {
      return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    std::vector<int> decide(const arm_interfaces::msg::PosisiBidak::SharedPtr points)
    {
      const float midX = 320;
      const float midY = 240;

      const float factorPIX2REAL = (0.064*30)/(2203*0.0395);

      float realDistTO = findDist(points->tox, midX, points->toy, midY) * factorPIX2REAL;
      float realDistFR = findDist(points->tox, midX, points->toy, midY) * factorPIX2REAL;



      std::vector<int> JANCOK = {0, 0, 0, 0};
      return JANCOK;
    }

    void timer_callback(std::vector<int> ServoMoves)
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