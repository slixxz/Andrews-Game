#ifndef HANGMAN_DEF
#define HANGMAN_DEF

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include "game.hpp"

using namespace std;

class Hangman: public Game{
  
  
public:
  Hangman();
  bool RunHangman();
  string HangManToUpper(string s);
  string HangManmakeblanks (int num);
  string HangManGetSecretWord ();
  void HangManDisplaygame (int misses);
  
private:                                                                                                                                                                  
                                                                                                                                                                          
};                                                                                                                                                                        
#endif
