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
    int finalMove = -1;
    
    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
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
      finalMove = determine(vecBoard);
      std::cout<<"move: "<<finalMove<<std::endl;
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void timer_callback()
    {
      if(finalMove != -1)
      {
        auto message = std_msgs::msg::String();
        message.data = std::to_string(finalMove);
        publisher_->publish(message);
        finalMove = -1;
      }
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
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8},
      {0, 4, 8},
      {2, 4, 6}
    };

    bool checkWin(std::vector<int> boardState, int player)
    {
      //loop through all the win combo, if any i for all j in boardState[winCombination[i][j]] == player, return true
      for (uint64_t i = 0; i < winCombination.size(); i++)
      {
        if
        (
          boardState[winCombination[i][0]] == player &&
          boardState[winCombination[i][1]] == player &&
          boardState[winCombination[i][2]] == player
        )
        {return true;}
      }
      return false;
    }

    std::vector<int> availableMoves(std::vector<int> boardState)
    {
      std::vector<int> moves;
      for(int i = 0; i < 9; i++)
      {
        if(boardState[i] == 0) {moves.push_back(i);}
      }
      return moves;
    }

    int moveScore(std::vector<int> boardState, int playing)
    {
      if(checkWin(boardState, 1)) {return 1;}
      else if(checkWin(boardState, 2)) {return -1;}
      else
      {
        for(uint64_t i = 0; i < boardState.size(); i++)
        {
          if(boardState[i] == 0) {break;}
          if(i == 7) {return 0;}
        }
      }

      //else loop thru all moves that we can make, and then do a recursive search with alternating Player
      int score = 0;
      std::vector<int> emptyGrids = availableMoves(boardState);
      for(uint64_t i = 0; i < emptyGrids.size(); i++)
      {
        boardState[emptyGrids[i]] = playing;
        score += moveScore(boardState, (playing == 1 ? 2 : 1));
        boardState[emptyGrids[i]] = 0;
      }
      return score;
      // return 0;
    }

    int determine(std::vector<int> boardState)
    {
      int maxScore = 0;
      int maxMove = -1;
      std::vector<int> moves = availableMoves(boardState);
      for(uint64_t i = 0; i < moves.size(); i++)
      {
        boardState[moves[i]] = 2;
        int tempScore = moveScore(boardState, 1);
        std::cout<<"finalScore: "<<tempScore<<std::endl;
        if(tempScore > maxScore)
        {
          maxScore = tempScore;
          maxMove = moves[i];
        }
        boardState[moves[i]] = 0;
      }
      return maxMove;
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerTicTacToe>());
  rclcpp::shutdown();
  return 0;
}