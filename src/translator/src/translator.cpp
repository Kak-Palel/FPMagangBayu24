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

    float findDistPix(float x1, float x2, float y1, float y2)
    {
      return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    float ruleOfCosine(float a, float b, float alpha)
    {
      return sqrt(pow(a, 2) + pow(b, 2) + 2.0f*a*b*cos(alpha));
    }

    float reverseCosine(float a, float b, float c)
    {
      return cosh((pow(c, 2) - pow(a, 2) - pow(b, 2))/(2.0f*a*b));
    }

    //serv1, serv2, serv3, dist2cen, dist2serv1, pixX, pixY
    std::vector<std::vector<float>> ammo = 
    {
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    };
    
    std::vector<float> decide(const arm_interfaces::msg::PosisiBidak::SharedPtr points)
    {
      std::vector<float> toMove = {ammo[0][0], ammo[0][1], ammo[0][2], 0, 0, 0};

      const float midX = 320.0f;
      const float midY = 240.0f;

      const float dist_serv2cen = 0; //to be assigned

      const float pixServY = 0; //to be assigned

      const float diagonalRealLen = 0.064f;
      const float centerDist = 50.0f;
      const float diagonalPixLen = 800.0f;
      const float focLen = 0.0395f;

      const float factorPIX2REAL = (diagonalRealLen*centerDist)/(diagonalPixLen*focLen);
      // const float factorPIX2REAL = (0.064*50)/(2203*0.0395);

      // float realDistTO = findDistPix(points->tox, midX, points->toy, midY) * factorPIX2REAL;
      // float realDistFR = findDistPix(points->tox, midX, points->toy, midY) * factorPIX2REAL;

      float dist_to2cen = findDistPix(points->tox, midX, points->toy, midY);
      float dist_amm2cen = findDistPix(ammo[0][5], midX, ammo[0][6], midY);
      float dist_amm2to = findDistPix(points->tox, ammo[0][5], points->toy, ammo[0][6]);

      float centerAlpha = reverseCosine(dist_to2cen, dist_amm2cen, dist_amm2to);

      float c = ruleOfCosine(dist_to2cen*factorPIX2REAL, ammo[0][3], centerAlpha);

      float alpha2serv = reverseCosine(dist_serv2cen, dist_to2cen, findDistPix(points->tox, midX, points->toy, pixServY));
      float a = ruleOfCosine(dist_to2cen * factorPIX2REAL, dist_serv2cen, alpha2serv);
      
      toMove[3] = reverseCosine(a, ammo[0][4], c);

      return toMove;
    }

    void timer_callback(std::vector<float> ServoMoves)
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