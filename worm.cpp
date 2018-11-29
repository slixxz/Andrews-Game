#include"worm.hpp"
#include"board.hpp"
#include"getChar.hpp"
#include<curses.h>

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<ostream>
#include<iomanip>
#include<list>
#include<stdlib.h>


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

//10-25 and 10-80
bool Worm::RunWorm(int bRow, int bColumn)
{
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////Create game, Call the functions to run the game, create variables//////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  startup();

  //coonstructors
  Board board = Board(bRow, bColumn);
  Worm worm = Worm(bRow, bColumn);

  //create walls
  board.createWalls ( bRow , bColumn );
  refresh();

  //variable declarations
  bool failed = true;
  bool moving = true;
  int headx = bRow/2;
  int heady = bColumn/2;
  int px = 0;
  int py = 0;

  move(headx + 1, heady);
  addch('@');
  worm.insertq(headx, heady);

  //randomMunchie = board.randomMunchieGenerator();
  // randomCords = board.randomMunchieGen();
  //the munchuie gen
  int randomMunchie = board.randomMunchieGenerator();
  Cell randomCords = board.randomMunchieGen();
  char munchie = '0' + randomMunchie;
  mvaddch(randomCords.x + 1, randomCords.y, munchie);
  refresh();

 for(int i = 0; i < 8; i++)
    {
      mvaddch(headx+1, heady+i-4, 'o');
      worm.insertq(headx, heady+i-4);
      failed = board.deleteFreePool(headx,heady+i-4);
    }
  heady = (bColumn/2) + 3;
  mvaddch(headx+1, heady, '@');
  refresh();

  //store tail Cords into emptail
  Cell temptail;
  int previousTailx = temptail.x;
  int previousTaily = temptail.y;

  refresh();

  /////////////////////////////////////////////////////////////////////////////
  //////////////////////Add head to the game/////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  /////////////////////implementation of the movement keys/////////////////////
  /////////////////////////////////////////////////////////////////////////////

  while(moving)
    {
      char mv = get_char();
      px = headx;
      py = heady;
      bool F = false;
      switch(mv)
	{
	case 'w':
	  headx = headx - 1;
	  F=true;
	  break;

	case 'd':
	  heady  = heady + 1;

	  F=true;
	  break;

	case 's':
	  headx = headx +1;
	  F=true;
	  break;

	case 'a':
	  heady = heady -1;
	  F=true;
	  break;

	case 'q':
	  moving =false;
	  terminate();
	  return 1;

	default:
	  break;
	}
      if(F == true)
	{
	  mvaddch(headx +1, heady, '@');
	  mvaddch(px +1, py, 'o');

	  temptail = worm.moveSnake(headx, heady);
	  failed = board.deleteFreePool(headx, heady);
	  if(failed == false)
	    {
	      moving = false;
	      mvaddstr(10,10, "YOU LOSE!!!!!");
	    }

	  //if(!worm.isGrowing())
	  if (temptail.x != -1 & temptail.y != -1)
	    {
	      mvaddch(temptail.x + 1, temptail.y, ' ');
	      board.addFreePool(temptail.x, temptail.y);
	    }

	  if(heady == randomCords.y && headx == randomCords.x)
	    {
	      worm.storeGrowth(randomMunchie);
	      randomMunchie = board.randomMunchieGenerator();
	      randomCords = board.randomMunchieGen();
	      munchie = '0' + randomMunchie;
	      //worm.insertq(randomCords.x, randomCords.y);
	      mvaddch(randomCords.x + 1, randomCords.y, munchie);
	    }
	  //      mvaddch(previousTailx +1, previousTaily, '%');

	  refresh();


	  board.print_Screen();
	  //update freeSpace;

	}
      refresh();
    }

  while (get_char() != ' ');
  //end the curses to screen
  terminate();
  
}





void Worm::startup( void )
{
     initscr();     /* activate curses                                            */
     curs_set(0);   /* prevent the cursor to be displayed                         */
     clear();       /* clear the screen that curses provides                      */
     noecho();      /* prevent the input chars to be echoed to the screen         */
     cbreak();      /* change the stty so that characters are delivered to the                                                                                                             
                       program as they are typed--no need to hit the return key!  */
}

void Worm::terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}

