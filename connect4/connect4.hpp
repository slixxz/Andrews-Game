#include<iostream>

using namespace std;

class Connect{
public:
  Connect();
  bool connect_Game();
  
private:
  bool is_Column_Taken();
  bool winner_Check();
  bool is_Board_Full();
  void find_And_Drop();
  void update_Board();
  void print_Board();
  void user_Choice();
  string player1;
  string player2;
  char game_Piece;
  int choice;
  bool taken, playing, P1;

  char board[7][7];
};
