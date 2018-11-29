#include<iostream>
#include"connect4.hpp"
#include<cctype>

using namespace std;

Connect::Connect()
{
  player1 = "";
  player2 = "";
  game_Piece = ' ';
  choice = 0;
  taken = false;
  playing = true;
  P1 =true;
  
  for(int i =0; i < 7; i++)
    for(int j =0; j < 7; j++)
      {
	board[i][j] = ' ';
      }
}


bool Connect::connect_Game()
{
  cout << "Welcome to connect 4! Please enter player ones name: " << endl;
  cin >> player1;
  cout << "Welcome: " << player1 << endl << "Now enter player twos name: " << endl;
  cin >> player2;
  cout << "Wlecome: " << player2 << endl << " Lets Begin! " << endl;

  print_Board();

  cout << player1 << " is X's and " << player2 << " is O's " << endl;
  cout << player1 << "to choose a column enter a column number 1 - 7. Lets begin " << endl;
  
  
  while(playing == true)
    {
      //check if board is full, if so set playing to false
      if(P1 == true)
	{
	  game_Piece = 'X';
	}
      else
	{
	  game_Piece = 'O';
	}
      
      user_Choice();
      update_Board();
      if(is_Board_Full() == true)
	{
	  cout << "game Over, No one won! " << endl;
	  print_Board();
	  playing = false;
	}
    }
}




bool Connect::is_Column_Taken(/*pass in cords*/)
{
  if(board[0][choice - 1] == 'X' || board[0][choice - 1] == 'O')
    {
      return true;    
    }
  else
    return false;
  
}


bool Connect::winner_Check()
{
  int xcounter = 1;
  int ocounter = 1;
  //across
  for(int i = 0; i < 7; i++)
    for(int j = 0; j < 7; j++)
      { 
	if(xcounter == 4) 
	  {
	    if(P1 == true)
	      cout << player1 << " Won!" << endl;
	    else
	      cout << player2 << " Won!" << endl;
	    playing = false;
	    return true; 
	  } 
	if(ocounter == 4) 
	  { 
	    if(P1 == true)
	      cout << player1 << " Won!" << endl;
	    else
	      cout << player2 << " Won!" << endl;
	    playing = false;
	    return true; 
	  } 
	if(board[i][j] == 'X')
	  {
	    xcounter++; 
	    ocounter = 0;

	  }
	else if(board[i][j] == 'O')
	  {
	    xcounter = 0;
	    ocounter++;
	  }
	else
	  {
	    xcounter = 0;
	    ocounter = 0;
	  }
      }
  //up
  xcounter = 1; 
  ocounter = 1; 
   for(int j = 0; j < 7; j++)
     for(int i = 0; i < 7; i++)
       {
	 if(xcounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(ocounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(board[i][j] == 'X')
	   {
	     xcounter++;
	     ocounter = 0;
	   }
	 else if(board[i][j] == 'O')
	   {
	     xcounter = 0;
	     ocounter++;
	   }
	 else
	   {
	     xcounter = 0;
	     ocounter = 0;
	   }
       } 

   int xcounter = 1;
   int ocounter = 1;
   //across
   for(int i = 0; i < 7; i++)
     for(int j = 0; j < 7; j++)
       {
	 if(xcounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(ocounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(board[i][j] == 'X')
	   {
	     xcounter++;
	     ocounter = 0;

	   }
	 else if(board[i][j] == 'O')
	   {
	     xcounter = 0;
	     ocounter++;
	   }
	 else
	   {
	     xcounter = 0;
	     ocounter = 0;
	   }
       }

   xcounter = 1;
   ocounter = 1;
   //positive slope
   for(int i = 0; i < 7; i++)
     for(int j = 0; j < 7; j++)
       {
	 if(xcounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(ocounter == 4)
	   {
	     if(P1 == true)
	       cout << player1 << " Won!" << endl;
	     else
	       cout << player2 << " Won!" << endl;
	     playing = false;
	     return true;
	   }
	 if(board[i][j] == 'X' && board[i+1][j+1] == 'X')
	   {
	     xcounter++;
	     ocounter = 0;

	   }
	 else if(board[i][j] == 'O')
	   {
	     xcounter = 0;
	     ocounter++;
	   }
	 else
	   {
	     xcounter = 0;
	     ocounter = 0;
	   }
       }

   
   return false;
   
}



void Connect::update_Board()
{
  //check winner
  if(winner_Check() == true)
    {
      cout << "Thanks for playing!" << endl;
    }
  
  //first check if spot is ok by calling is_Spot_taken
  while(is_Column_Taken() == true)
    {
      cout << "column is full choose another option " <<endl;
      user_Choice();
    }
  find_And_Drop();
  //check winner
  if(winner_Check() == true)
    {
      cout << "Thanks for playing!" << endl;
    }
  print_Board();
  
  if(P1 == true)
    P1 = false;
  else
    P1 =true;

}


void Connect::print_Board()
{
  for(int i =0; i < 7; i++)
    {
      cout << "|";
      for(int j =0; j < 7; j++)
	{
	  cout <<' ' << board[i][j];
	}
      cout << " |" << endl;
    }
  cout << " ";
  for(int i = 1; i < 8; i++)
    {
      cout <<" " << i;
    }
  cout << " " << endl << endl;
}

void Connect::user_Choice()
{
  cin >> choice;
  while(7 < choice || choice < 1 || isalpha(choice))
    {
      cout << "Not a valid option, try again! " << endl;
      cin >> choice;
    }
}

//function to drop the X or Y
void Connect::find_And_Drop()
{
  for(int i = 7; i >= 0; i--)
    {
      if(board[i][choice - 1] == ' ')
	{
	  board[i][choice - 1] = game_Piece;
	  break;
	}
    }
}

bool Connect::is_Board_Full()
{
  for(int i =0; i < 7; i ++)
    {
      if(board[0][i] == ' ')
	return false;
    }
  return true;
}

