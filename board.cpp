#include"board.hpp"
#include<cstdlib>
#include<iostream>
#include<curses.h>
#include<fstream>
#include<ostream>
#include <iomanip>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Board consructor////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
Board::Board(int row, int column)
{
  grow = row;
  gcol = column;
  //initialize count to 0
  count = 0;

  //size of screen/board 
  int maxSize = (row-2) * (column -2);

   //create my freepool
  freePool = new Cell[maxSize];

  //create my tD array
  screen = new int *[row];
    for(int i=0; i< row; i++)
    {
      screen[i]= new int [column];
    }


   for(int i=1; i< row - 1; i++)    //This loops on the rows.
    {
      for(int j=1; j<column - 1; j++) //This loops on the columns
	{
	  screen[i][j] = count;
	  freePool[count].x = i;
	  freePool[count].y = j;
	  count++;
	}
    }

  //putting -1 at my my walls
for(int i =0; i < row; i++)
  {
    screen[i][0] = -1;
    screen[i][column -1] = -1;
  }
for(int i=0; i< column; i++)
  {
    screen[0][i] = -1;
    screen[row - 1][i] = -1;
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Board class Destructor////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Board::~Board()
{
  delete [] freePool;
  for(int i=0; i< grow; i++)
    {
      delete [] screen[i];
    }
  delete [] screen;
   
  
}

bool Board::addFreePool(int x,int y)
{
  if(screen[x][y] != -1)
    {
    return false;
    }
  freePool[count].x = x;
  freePool[count].y = y;
  screen[x][y] = count;
  count ++;
  return true;
}

bool Board::deleteFreePool(int x, int y)
{
  if(screen[x][y] == -1)
    {
    return false;
    }
  count--;
  int spotGoingTo = screen[x][y];
  freePool[spotGoingTo].x = freePool[count].x;
  freePool[spotGoingTo].y = freePool[count].y;
  screen[freePool[spotGoingTo].x][freePool[spotGoingTo].y] = spotGoingTo;
  screen[x][y] = -1;
  return true;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////Create the game walls//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Board::createWalls(int row, int column)
{
  move(0,0);
  addstr("W  O  R  M       G  A  M  E");
  for(int i =1; i < row + 1; i++)
    {
      move(i, 0);  // move the curser to the second row, first column.
      addch('+');  // put a character at (1, 0)
      move(i,column);
      addch('+');
    }
  for(int j=0; j<column + 1; j++)
    {
      move(1,j);
      addch('+');
      move(row, j);
      addch('+');
    }
 
}

///////////////////////////////////////////////////////////
///////////////////munchie rnadom generator/////////////////////////
//////////////////////////////////////////////////////////
int Board::randomMunchieGenerator()
{
  srand (time(NULL));
  int tempmunchie = rand() % 9 +1;
  return tempmunchie;

}

Cell Board::randomMunchieGen()
{
  srand(time(NULL));
  int randomspace = rand() % count;
  return freePool[randomspace];
}


void Board::print_Screen()
{
  std::fstream fs;
  fs.open("output.txt", std::fstream::out);
  fs << "ROWS: " << grow;
  fs << "COLUMNS: " << gcol << std::endl;
  for(int i=0; i < grow; i++){
    for(int j =0; j< gcol; j++){
	fs << std::setw(4) << screen[i][j] << std::flush;
    }
    fs <<std::endl;
  }
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////Increase worm if munchie has been devoured//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//{
//if head Cord == an integer
//dont delete the tail until the snake has moved a total times of the integer ate.
//make sure freePool is udated.



//}                                             
