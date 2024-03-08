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

    float inverseCosine(float a, float b, float c)
    {
      std::cout<<(pow(c, 2) - pow(a, 2) - pow(b, 2))/(2.0f*a*b)<<std::endl;
      return acos((pow(c, 2) - pow(a, 2) - pow(b, 2))/(2.0f*a*b));
    }

    //serv1, serv2, serv3, dist2cen, dist2serv1, pixX, pixY
    // std::vector<std::vector<float>> ammo = 
    // {
    //   {0, 0, 0, 0, 0, 0},
    //   {0, 0, 0, 0, 0, 0},
    //   {0, 0, 0, 0, 0, 0},
    //   {0, 0, 0, 0, 0, 0},
    //   {0, 0, 0, 0, 0, 0}
    // };
    
    std::vector<float> decide(const arm_interfaces::msg::PosisiBidak::SharedPtr points)
    {
      // std::vector<float> toMove = {ammo[0][0], ammo[0][1], ammo[0][2], 0, 0, 0};
      std::vector<float> toMove = {-1, -1, -1, -1, -1, -1};

      const float midX = 320.0f;
      const float midY = 240.0f;

      const float diagonalRealLen = 0.064f;
      const float centerDist = 61.0f;
      const float diagonalPixLen = 800.0f;
      const float focLen = 0.0395f;

      const float factorPIX2REAL = (diagonalRealLen*centerDist)/(diagonalPixLen*focLen);
      
      const float pixServY = midY + (25.8f / factorPIX2REAL); //to be assigned (in pixelll)
      const float height_arm2pawn = 6.7f;
      const float backArmLen = 15.3f;
      const float frontArmLen = 15.3f;

      toMove[0] = 90 - atan2((midX - points->fromx), (pixServY - points->fromy)) * (180/3.141592);
      toMove[3] = 90 - atan2((midX - points->tox), (pixServY - points->toy)) * (180/3.141592);

      float dist_fr2serv = (findDistPix(points->fromx, midX, points->fromy, pixServY) * factorPIX2REAL) - 14.5f;
      float dist_to2serv = (findDistPix(points->tox, midX, points->toy, pixServY) * factorPIX2REAL) - 14.5f;

      std::cout<<"dist_fr2serv: "<<dist_fr2serv<<std::endl;
      std::cout<<"dist_to2serv: "<<dist_to2serv<<std::endl<<std::endl;

      float angle_basefr = atan2(height_arm2pawn, dist_fr2serv) * (180/3.141592);
      float angle_baseto = atan2(height_arm2pawn, dist_to2serv) * (180/3.141592);

      std::cout<<"angle_basefr: "<<angle_basefr<<std::endl;
      std::cout<<"angle_baseto: "<<angle_baseto<<std::endl<<std::endl;

      dist_fr2serv = sqrt(pow(height_arm2pawn, 2) + pow(dist_fr2serv, 2));
      dist_to2serv = sqrt(pow(height_arm2pawn, 2) + pow(dist_to2serv, 2));

      std::cout<<"dist_fr2serv: "<<dist_fr2serv<<std::endl;
      std::cout<<"dist_to2serv: "<<dist_to2serv<<std::endl<<std::endl;

      float angle_totalfr = inverseCosine(backArmLen, frontArmLen, dist_fr2serv) * (180/3.141592);
      float angle_totalto = inverseCosine(backArmLen, frontArmLen, dist_to2serv) * (180/3.141592);

      std::cout<<"angle_totalfr: "<<angle_totalfr<<std::endl;
      std::cout<<"angle_totalto: "<<angle_totalto<<std::endl<<std::endl;
      
      toMove[1] = angle_totalfr/2 + angle_basefr;
      toMove[2] = angle_totalfr/2 - angle_basefr;
      
      toMove[4] = angle_totalto/2 + angle_baseto;
      toMove[5] = angle_totalto/2 - angle_baseto;

      return toMove;
    }

    void timer_callback(std::vector<float> ServoMoves)
    
      auto message = arm_interfaces::msg::ServoParameters();

      // message.take1 = 0;
      // message.take2 = 0;
      // message.take3 = 0;
      // message.drop1 = 0;
      // message.drop2 = 0;
      // message.drop3 = 0;
      message.take1 = ServoMoves[0];
      message.take2 = ServoMoves[1];
      message.take3 = ServoMoves[2];
      message.drop1 = ServoMoves[3];
      message.drop2 = ServoMoves[4];
      message.drop3 = ServoMoves[5];

      std::cout<<"take1: "<<ServoMoves[0]<<std::endl;
      std::cout<<"take2: "<<ServoMoves[1]<<std::endl;
      std::cout<<"take3: "<<ServoMoves[2]<<std::endl;
      std::cout<<"drop1: "<<ServoMoves[3]<<std::endl;
      std::cout<<"drop2: "<<ServoMoves[4]<<std::endl;
      std::cout<<"drop3: "<<ServoMoves[5]<<std::endl;
      // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      std::cout<<"Publishing... " << count_++ << std::endl;
      publisher_->publish(message);
    }
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