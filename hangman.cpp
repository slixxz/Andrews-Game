// File : Proj2
// Project : CS 115 Project 2 - Hangman
// Author : David Smith
// Date : Fall 2010
// Description : Hangman 
#include"hangman.hpp"

using namespace std;
const int MAX_MISSES = 9;  // constant to hold maximum number of misses

Hangman::Hangman()
{
    
}

bool Hangman::RunHangman()
{
  string blanks;  
  int misses;
  
  cout << " Welcome to my Hangman. " << endl;
  cout << "To play Hangman you must guess letters for an unkown word." <<endl
       << "The goal of the game is to figure out what the secret word is." << endl
       << "Guess letters to the word, If you guess wrong your closer to becoming a dead man, watch out!!!! " << endl;
  cout << " Are you ready? enter yes or no " << endl; 

  string YorN; 
  cin >> YorN;
  
  while (HangManToUpper(YorN)== "YES")
    {
      misses = 0;
      string bad;
      char guess;
      string word = HangManGetSecretWord();
      int good = word.size();

      blanks = HangManmakeblanks (word.size());        
      cout<< endl;
      /*missing code*/
      bool found;
      while (good > 0 && misses < MAX_MISSES)
	{ 
	  found=false;
	  HangManDisplaygame (misses);
	  for (int i=0; i<blanks.size();i++){
	    cout<<blanks[i]<<' ';
	  }  
	  cout<<endl;
	  cout<< "These guesses are wrong: " << bad <<endl;
	  cout<< "Enter a letter ";
	  cout<< endl; 
	  cin>> guess;
	  guess=toupper (guess);
	
	  for(int i=0;i<word.size();i++ ) 
	    {
	      if (word[i] == toupper(guess))
		{
		  good--;
		  blanks[i]=guess; /*replace blank with secrete word letter*/
		  found=true;

		}
	    }
	     

	  if (found==false){
	    misses++;
	    bad+=guess;
	  }
	}
    
      if (misses == MAX_MISSES){
    	cout<<" Sorry you died. The word was:  " << word << endl;
	return false;
      }
      else{ 
	cout<<"You are the winner! "<<endl;
	return true;
      }      
      HangManDisplaygame (misses);       
    
/*check to see if misses equals MAX_MISSES and if so the then sorry they lost else say the won
then ask if they want to play again
      */ 
      cout<< "the secrete word was: " << word << endl;
      cout<< "Do you want to play again? "<<endl;
      cout<< "Enter yes or no. "<<endl;
      
      cin>>  YorN;
    }
  return true;
}


string Hangman::HangManToUpper(string s){
  string r=s;
  for (int i=0; i<s.size(); i++) 
    r[i]= toupper(s[i]);
  return r;  
}

string Hangman::HangManmakeblanks (int num)
{ string b;
  for (int i=0; i<num;i++)
    {      
      b+='_';
    } 
  return b;
}



string Hangman::HangManGetSecretWord ()
// This function will get a word from the secret word file
{
  // Declare and open the file of secret words
  ifstream file ("hangman.txt");
  // Declare a varaible to hold the number of words
  int numwords = 1;
  // Declare a varaible to hold a random number
  int whichword=0;
  // Declare a variable to hold the selected word
  string word = "RANDOM";
  // Initialize the random number generator
  srand (time (NULL));
  // Read in the number of words
  file >> numwords;
  // Calculate a random number >= 0 amd < the number of words
  whichword = rand() % numwords;
  // Loop to read the file
  do
    {
      // Read a word from the file
      file >> word;
      // Decrement the counter
      whichword--;
      // Stop reading when the counter hits 0
    } while (whichword > 0);
  // Close the file
  file.close();
  // Return the selected word
  return word;
}

void Hangman::HangManDisplaygame (int misses)
// This function will print the hangman gallows
{
  // Declare and initialize the display
  string display [] = {"       |------|       ",
		       "       |      |       ",
		       "       O      |       ",
		       "      /|\\     |       ",
		       "       |      |       ",
		       "      / \\     |       ",
		       "     /   \\    |       ",
		       "              |       ",
		       "            -----     ",
		       "            |   |     ",
		       "          ---------   ",
		       "          |       |   "};

  // Block out the parts of the display that are not needed
  if (misses < 1)
    display [2][7] = ' ';
  if (misses < 2)
    display [3][7] = ' ';
  if (misses < 3)
    display [3][6] = ' ';
  if (misses < 4)
    display [3][8] = ' ';
  if (misses < 5)
    display [4][7] = ' ';
  if (misses < 6)
    display [5][6] = ' ';
  if (misses < 7)
    display [5][8] = ' ';
  if (misses < 8)
    display [6][5] = ' ';
  if (misses < 9)
    display [6][9] = ' ';
  // Print the lines of the display
  for (int i = 0; i < 12; i++)
    cout << display[i] << endl;
}
