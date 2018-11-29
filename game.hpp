#ifndef GAME_DEF
#define GAME_DEF
#include<string>
#include<iostream>
#include<fstream>
#include"stdlib.h"
#include<vector>

using namespace std;

class Game{
  
public:
  /*functions*/
  Game();
  ~Game();
  void andrew();

private:
  bool gameOutcomeCheck();
  void game_Map();
  void update_level();
  bool hangman();
  bool andrewQuiz();
  
protected:
  bool gameOver, playing, levelResult;
  int choice;  
  int levelCounter;
  vector <int> gameMap;
  vector <string> andrewQuizVec;
  
};


#endif
