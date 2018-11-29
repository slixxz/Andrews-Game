#ifndef WORM_H
#define WORM_H
#include"cell.hpp"
#include"board.hpp"
#include"game.hpp"

class Game;
class Worm{
public:
  Worm(int row,int column);
  bool RunWorm(int, int);
  bool insertq(int row, int column);
  bool deleteq();
  int sizeofSpace();
  bool isEmpty();
  bool isFull();
  void startup( void );  
  Cell storeGrowth(int randomMunchieSize);
  Cell moveSnake(int row, int column);
  bool outOfBounds(int x, int y, int head);
  int size();
  bool isGrowing();
  void print_Screen();
  void terminate( void );  
  
 private:
  Cell *worm;
  Cell grow;
  int head, tail, maxSize0, maxSize,  count, addSize;
 
};

#endif
