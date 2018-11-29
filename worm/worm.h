#ifndef WORM_H
#define WORM_H
#include"cell.h"
#include"board.h"

class Worm

{
 public:
 
  Worm(int row,int column);
  bool insertq(int row, int column);
  bool deleteq();
  int sizeofSpace();
  bool isEmpty();
  bool isFull();

  Cell storeGrowth(int randomMunchieSize);
  Cell moveSnake(int row, int column);
  bool outOfBounds(int x, int y, int head);
  int size();
  bool isGrowing();
  void print_Screen();
  
 private:
  Cell *worm;
  Cell grow;
  int head, tail, maxSize0, maxSize,  count, addSize;
 
};

#endif
