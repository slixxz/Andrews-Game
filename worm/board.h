#ifndef BOARD_H
#define BOARD_H
#include"cell.h"

class Board
{
  
 public:
  Board(int row, int column);
  ~Board();
  bool addFreePool(int x, int y);
  bool deleteFreePool(int x, int y);
  void createWalls(int row, int column);
  int randomMunchieGenerator();
  Cell randomMunchieGen();
  void print_Screen();  
 private:
  int **screen;
  Cell *freePool;
  int grow, gcol, count;
};

#endif
