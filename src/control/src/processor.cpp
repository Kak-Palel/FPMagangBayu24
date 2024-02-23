#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

/**
 * Class untuk menerima keadaan grid, menentukan gerakan terbaik, dan mengirimkannya.
 * Menggunakan algoritma alphabeta yang merupakan ekstensi yang lebih efisien dari
 * algoritma minimax, suatu algoritma yang sering digunakan dalam game game yang jelas,
 * bekerja dengan cara mengiterasi semua gerakan yang dapat diambil dan secara rekursif
 * melihat semua probabilitas keadaan grid yang dapat terjadi untuk menentukan gerakan
 * mana yang terebaik
 * Sumber: "https://cwoebker.com/posts/tic-tac-toe"
*/
class ControllerTicTacToe : public rclcpp::Node
{
  public:
    //yang publik constructornya doang aowkaowokaokwo
    ControllerTicTacToe()
    : Node("bot_control"), count_(0)
    {
      //inisiasi subscription untuk menerima kondisi grid dari node vision
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "ttt_state", 10, std::bind(&ControllerTicTacToe::topic_callback, this, _1));

      //inisiasi publisher untuk mengirim perintah gerakan yang telah ditentukan
      publisher_ = this->create_publisher<std_msgs::msg::String>("ttt_moves", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&ControllerTicTacToe::timer_callback, this));
      std::cout<<"constructor executed\n";
    }

  private:
    //default value dari gerakan yang akan dikirim, jika nilainya berubah, maka perhitungan sudah selesai dan siap dikirim
    int finalMove = -1;
    
    /**
     * method listener yang menerima kondisi grid, memanggil fungsi yangn mengubahnya ke bentuk 
     * vector dan fungsi yang bertugas untuk menentukan gerakan, dan lalu menyimpannya pada finalMove untuk kemudian dikirim
     * */
    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
      //terima posisi grid
      RCLCPP_INFO(this->get_logger(), "A: '%s'", msg->data.c_str());
      std::string strBoard = msg->data.c_str();
      std::cout<<strBoard<<std::endl;
      
      //ubah dalam bentuk vector
      std::vector<int> vecBoard = this->string2vec(strBoard);

      //print untuk keperluan debugging
      for(int j = 0; j < 9; j++)
      {
        std::cout<<vecBoard[j]<<" ";
        if((j+1) % 3 == 0){std::cout<<std::endl;}
      }
      std::cout<<std::endl;

      //panggil fungsi determine dan simpan ke finalMove
      finalMove = determine(vecBoard);
      std::cout<<"move: "<<finalMove<<std::endl;
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    //method yang mempublish finalMove dalam bentuk string apabila nilainya berubah dari default valuenya (-1)
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

    //method untuk mengubah string posisi grid ke vector
    std::vector<int> string2vec(std::string strBoard) const
    {
      std::vector<int> vecBoard;
      for(int i = 0; i < 9; i++)
      {
        vecBoard.push_back(std::stoi(strBoard.substr(i, 1), nullptr, 10));
      }
      return vecBoard;
    }
    
    //kombinasi kombinasi kolom grid yang menandakan kemenangan bila di populasi bersamaan
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

    //method untuk mengecek suatu player telah menang atau belum
    bool checkWin(std::vector<int> boardState, int player)
    {
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

    //method untuk menentukan kolom grid mana saja yang dapat menjadi gerakan bot
    std::vector<int> availableMoves(std::vector<int> boardState)
    {
      std::vector<int> moves;
      for(int i = 0; i < 9; i++)
      {
        if(boardState[i] == 0) {moves.push_back(i);}
      }
      return moves;
    }

    //method implementasi algoritma alpha-beta
    int alphaBeta(std::vector<int> boardState, int playing, int alpha, int beta)
    {
      if(checkWin(boardState, 2)) {return 1;}
      else if(checkWin(boardState, 1)) {return -1;}
      else
      {
        for(uint64_t i = 0; i < boardState.size(); i++)
        {
          if(boardState[i] == 0) {break;}
          if(i == 7) {return 0;}
        }
      }

      int score = 0;
      std::vector<int> emptyGrids = availableMoves(boardState);
      for(uint64_t i = 0; i < emptyGrids.size(); i++)
      {
        boardState[emptyGrids[i]] = playing;
        score = alphaBeta(boardState, (playing == 1 ? 2 : 1), alpha, beta);
        boardState[emptyGrids[i]] = 0;
        if(playing == 2)
        {
          if(score > alpha) {alpha = score;}
          if(alpha >= beta) {return beta;}
        }
        else
        {
          if(score < beta) {beta = score;}
          if(beta <= alpha) {return alpha;}
        }
      }
      if(playing == 2) {return alpha;} return beta;
    }

    //method yang menentukan gerakan terbaik dengan menerapkan algoritma alpha-beta pada semua gerakan yang mungkin
    int determine(std::vector<int> boardState)
    {
      int maxScore = -2;
      int maxMove = -1;
      std::vector<int> moves = availableMoves(boardState);
      if (moves.size() == 9) {return 4;}
      for(uint64_t i = 0; i < moves.size(); i++)
      {
        boardState[moves[i]] = 2;
        int tempScore = alphaBeta(boardState, 1, -2, 2);
        std::cout<<"finalScore: "<<tempScore<<std::endl;
        if(tempScore > maxScore)
        {
          maxScore = tempScore;
          maxMove = moves[i];
          if(maxScore == 1) {return maxMove;}
        }
        boardState[moves[i]] = 0;
      }
      return maxMove;
    }
};

//entry
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerTicTacToe>());
  rclcpp::shutdown();
  return 0;
}