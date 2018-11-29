#include"worm.h"
#include<curses.h>
#include<cstdlib>
#include<iostream>
#include "getChar.hpp"
#include<fstream>
#include<ostream>
#include <iomanip>

Worm::Worm(int row, int column)
{
  maxSize = (row - 2)*(column - 2);
  head = 0;
  tail = 0;
  count = 0;
  worm = new Cell[maxSize];
  addSize = 0;
}

bool Worm::isEmpty()
{
  return count == 0;
}

bool Worm::insertq(int row, int column)
{
  bool result = false;
  if(count < maxSize)
    {
      worm[tail].x = row;
      worm[tail].y =column;
      tail = (tail + 1) % maxSize;
      count ++;
      result =true;
    }
  return result;
}

bool Worm::deleteq()
{
  bool result = false;
  if(!isEmpty())
    {
      head = (head +1) % maxSize;
      count --;
      result = true;
    }
  return result;
}


int Worm::sizeofSpace(){
  return (tail - head);
}


bool Worm::isFull(){
  if(head==(tail+1)%maxSize){
    //YOU WIN~~~~~~~~~
    return true;
  }else{
    return false;
  }
}

//move the head to row column, returns the tail/removes tail
// usage: in main: take input, move snake, update freepool (remove head from fp, add tail(return value of this fn) to fp)
Cell Worm::moveSnake(int row, int column)
{
  grow.x = -1;
  grow.y = -1;
  worm[head].x = row;
  worm[head].y = column;
  head++;
  
  if(head >= maxSize)
    {
      head = 0;
    }
  if(addSize == 0)
    {
      if(tail >= maxSize)
	{
	  tail = 0;
	}
	return worm[tail++];
    }
  
  else
    addSize--;
  return grow;
  
}

Cell Worm::storeGrowth(int randomMunchieSize)
{
  addSize += randomMunchieSize; 	
}

bool Worm::isGrowing()
{
	return addSize > 0;
}

bool Worm::outOfBounds(int row, int column, int head)
{



}

void Worm::print_Screen()
{
  /*  std::fstream fs;
  fs.open("output.txt", std::fstream::out);
  fs << "ROWS: " << row;
  fs << "COLUMNS: " << col << std::endl;
  for(int i=0; i < row; i++){
    fs << std::setw(4) << worm[i]  << std::flush;
  }
    fs <<std::endl;
  }
  */
}

