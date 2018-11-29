#include"hangman.hpp" //sub class of game class
#include"worm.hpp"//sub class of game
#include"board.hpp"
#include"stdlib.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

Game::Game()
{
  gameOver = false;
  playing = true;
  choice = 0;
  levelResult = true;
  levelCounter = 0; //update after each level

  for(int i = 0; i < 10; i++)//makes a game with 10 levels 
    {
      gameMap.push_back(i); 
    }
  andrewQuizVec.push_back("shadow");//answer 1
  andrewQuizVec.push_back("uranus");//answer 2
  andrewQuizVec.push_back("pun");//answer 3
  andrewQuizVec.push_back("expert");//answer4
  andrewQuizVec.push_back("reading");//answer 5
  andrewQuizVec.push_back("ass");//answer 6
  andrewQuizVec.push_back("kim");//answer 7
  andrewQuizVec.push_back("superak");//answer 8
}

Game::~Game()
{
  gameMap.clear();
  andrewQuizVec.clear();
}

void Game::andrew()
{

  while(playing==true)
    {
      
      
      cout << "welcome to my quest, help me defeat evil and swoop up as manny women as possible muhaha" << endl;
  
      //Load map
       game_Map();
       cout<< "Here are the levels we must beat to get beer and booty" << endl;
       cout << endl;
       cout << "looks like the first task is to answer some questions about me....I woldnt want you to know nothing about your amazing champing...me(flings hair) "<<endl;
      cout << "because as we all know I am the hero... and this is all about me :D " << endl;

   
      //set a variable for the function to store its result in.
      ////////////////////Level 1//////////////////////////////
            
      levelResult = andrewQuiz();
      //check the outcome of game
      if(gameOutcomeCheck() == false)
      {
         // end program
          exit (0);
      }
      
      string answer1;
      cout << " are you ready to begin the quest? yes or no?" << endl;
      cin >> answer1;
      update_level();
      
      ///////////////////Level 2//////////////////////////////
       Hangman *h = new Hangman();
       levelResult = h->RunHangman();
       if(gameOutcomeCheck() == false)
	 {
	   cout << "you have faild, NOOOOO!" << endl;
	   exit (0);
	 }
           
      cout << " well done lets move on to a new game " << endl;
       update_level();
       
       Worm *w = new Worm(25,75);      
       w->RunWorm(25,75);
       cout << "It's ok, We cant all be winners " << endl;
       cout << "Wow thats amazing ....." << endl << endl;
      
}
  
  
  return;
}

void Game::game_Map()
{

  //I choose an array for my gameMap
  for(int i = 0; i < gameMap.size();/*should be are global*/ i++)
    {
      if(i == levelCounter)
	{
	  //where we are on the map;
	  cout <<"      :)"<< endl;
	}
      else
	{
	  cout << "level : "<< gameMap[i] << endl;
	}
    }
}
void Game::update_level()
{
  levelCounter++;
  game_Map();
}

bool Game::andrewQuiz()
{
  string answer = "";
  cout<< "OK lets see how well you know me...." <<endl;
  cout<< "ready to begin? Here we go"<< endl<<endl;
  cout << "enter your guesses in lower case" << endl;
  cout << "What is my cats name? "<< endl;
  cin >> answer;

  while(true)
    {
      if(answer != andrewQuizVec[0])//shadow
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "correct! you know me so well fap fap fap" << endl<<endl;
	}
      cout << "What is my favorite planet? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[1])//uranus
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "Haha yes yes yes" << endl<<endl;
	}
      cout << "The last answer was a grea example of a what? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[2])//pun
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "Correct... Don't spell part backwards. It's a trap." << endl << endl;
	}
      cout << "Am i a expert, clueless, or lost at movie and shows? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[3])//expert
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "Correct... I am !" << endl << endl;
	}
      
      cout << "What do I hate the most...beans, reading, ass, talking? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[4])//reading
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "" << endl << endl;
	}

      cout << "What do I like the most from that list?...beans, reading, ass, excercise? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[5])//ass
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout << "I love some booty ;) " << endl << endl;
	}

      cout << "Whos is my favorite Kardashian? "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[6])//kim
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "Kim asked me to touch uranus once. " << endl << endl;
	}

      cout << "Last question, There is a hidden word using the letters in all of the previous answers, What is the word? Hint:it is in order..... "<< endl;
      cin >> answer;
      if(answer != andrewQuizVec[7])//superak
	{
	  cout << "Not correct: Nooo we have failed! " <<endl;
	  levelResult = false;
	  return false;
	}
      else
	{
	  cout<< "In fact I dont want to play this game since there is so much reading YAWN !" << endl << endl;
	  cout << "Well done we have copleted the first level! " << endl << endl << endl;
	  cout << endl << endl;
	  return true;
	}
      
      
    }
  
  
  return true;
}

bool Game::gameOutcomeCheck()
{
  if(levelResult == false)
    {
      gameOver = true;
      playing = false;
      cout << "GAME OVER we have failed!" << endl;
      return false;//end program
    }
  else
    return true;
  
}
