#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

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
      std::string strBoard = msg->data.c_str();
      std::cout<<strBoard<<std::endl;
      std::vector<int> vecBoard = this->string2vec(strBoard);
      for(int j = 0; j < 9; j++)
      {
        std::cout<<vecBoard[j]<<" ";
        if((j+1) % 3 == 0){std::cout<<std::endl;}
      }
      std::cout<<std::endl;
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

    std::vector<int> string2vec(std::string strBoard) const
    {
      std::vector<int> vecBoard;
      for(int i = 0; i < 9; i++)
      {
        vecBoard.push_back(std::stoi(strBoard.substr(i, 1), nullptr, 10));
      }
      return vecBoard;
    }
    
    std::vector<std::vector<int>> winCombination =
    {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
      {1, 4, 7},
      {2, 5, 8},
      {3, 6, 9},
      {1, 5, 9},
      {3, 5, 7},
    };


    bool checkWin(std::vector<int> boardState, int player)
    {
      //loop through all the win combo, if any i for all j in boardState[winCombination[i][j]] == player, return true
      return false;
    }

    int moveScore(std::vector<int> boardState, int Player)
    {
      //check win/lose and return 1 or -1

      //else loop thru all moves that we can make, and then do a recursive search with alternating Player (2 if statement)

      //return score
      return 0;
    }

    int determine(std::vector<int> boardState)
    {
      return 0;
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerTicTacToe>());
  rclcpp::shutdown();
  return 0;
}