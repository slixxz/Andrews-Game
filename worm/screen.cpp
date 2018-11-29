#include<curses.h>
#include "getChar.hpp"
#include"board.h"
#include"worm.h"
#include<cstdlib>
#include <stdlib.h>
#include<iostream>
#include<list>


void startup( void );
void terminate( void );



int main(int argc, char **argv)
{
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////making sure user inputs 3 arguments////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(argc != 3)
    {
      std::cout<<"not enough arguments, give two values for rows and collumns" <<std::endl;
      return 1;
    }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////making sure the user inputes the correct arguments for the game 10-25 and 10-80.////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int bColumn = atoi(argv[2]);
  int bRow = atoi(argv[1]);
  if(bRow <10 || bRow > 25)
     {
      std::cout<<"out of bounds please enter a row between 10 25" << std::cout;
      return 1;
    }
   
   if(bColumn < 10 || bColumn > 80)
    {
      std::cout<<"out of bounds, please enter a collumn between 10 and 80" <<std::endl;
      return 1;
    }
  
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
  bool failed = true;
  bool moving = true;
  while(moving)
    {
      char mv = get_char();
      px = headx;
      py = heady;
      
      switch(mv)
	{
	case 'w':
	  headx = headx - 1;
	  break;
	  
	case 'd':
	  heady  = heady + 1;
	  break;
	  
	case 's':
	  headx = headx +1;
	  break;
	  
	case 'a':
	  heady = heady -1;
	  break;
	  
	case 'q':
	  moving =false;
	  terminate();
	  return 1;
	  break;
	}
      
      mvaddch(headx +1, heady, '@');
      mvaddch(px +1, py, 'o');

      temptail = worm.moveSnake(headx, heady);
      failed = board.deleteFreePool(headx, heady);
      if(failed == false)
	{
	  moving = false;
	  mvaddstr(10,10, "you lose"); 
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



  //set head taken in freepool make tail free in freepool


  //if head = a -1 game over. we delared are -1 by seting screen [][] = to -1. 
  /*
  if (head.bRow < 10 || head.bRow > 25)
    move(10, 20);
  addstr("you lose :(");
  if(head.bColumn < 10 || head.bColumn > 80)*/
  move(10, 20);
  addstr("you lose :( press space");
  
      
    //  refresh();
    //koosheshs 
  /* for(int i = 1; i < 15; i++)
    {
      mvaddch( i, i, get_char() );
      refresh();
    }
  */
  while (get_char() != ' ');
  //end the curses to screen
  terminate();
}





void startup( void )
{
     initscr();	    /* activate curses                                            */
     curs_set(0);   /* prevent the cursor to be displayed                         */
     clear();	    /* clear the screen that curses provides                      */           
     noecho();	    /* prevent the input chars to be echoed to the screen         */      
     cbreak();	    /* change the stty so that characters are delivered to the
		       program as they are typed--no need to hit the return key!  */
}

void terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}
