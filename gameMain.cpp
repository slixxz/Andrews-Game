//dave smith

#include"game.hpp"
using namespace std;

/*
This game is for my friends, the goal is to cross the country/teritory/map 
to do this you need to answer questions, play games, and complete quests.
you can play as Connor as Andrew as your main character/hero. Better know them well
because one slip up and you are dead, and so are they!
*/
int main()
{
  string A = "Andrew";
  string C = "Connor";
  int answer = 0;
  //call constructor of class game and make new instance of game
  Game *g1 = new Game();
  
  
  cout << "Choose your hero!" <<endl;
  cout << "Enter 2 for Andrew! I know you only have one choice :'( " << endl;
  //  system("pause");
  cin >> answer;
  
  if(answer == 1)
    {
      cout<<"CONNOR" << endl;
      cout << "Not who I would have chosen but thats ok...." <<endl <<endl;
      //call connor game function
    }
  
  else if(answer == 2)
    {
      cout <<"ANDREW"<< endl;
      cout << "Not who I would have chosen but thats ok...." <<endl << endl;
      //creat a new instance of game !
      //  g->andrew();     
      g1->andrew();
    }
  else
    {
      cout << "not a valid champion try again."<< endl;
      cout << "2 for Andrew!" << endl;
      while(answer != 2)
	{
	  cin >> answer;
	}
      cout <<"ANDREW"<< endl;
      cout << "Not who I would have chosen but thats ok...." <<endl << endl;
      //creat a new instance of game !
      //      g->andrew();
     g1->andrew();
    }



  
  cout << "congradulations you beat this amazing game....you will live to see anther day" << endl;
  
  
  return 0;
}

  
