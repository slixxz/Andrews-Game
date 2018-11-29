game.x: game.o hangman.o gameMain.o getChar.o board.o worm.o
	g++ -std=c++11 -ggdb -o game.x gameMain.o game.o hangman.o worm.o getChar.o board.o -lcurses -ltermcap

gameMain.o: gameMain.cpp 
	g++ -std=c++11 -g -c gameMain.cpp -o gameMain.o 

game.o: game.cpp
	g++ -ggdb -std=c++11 -c game.cpp -o game.o

hangman.o: hangman.cpp 
	g++ -ggdb -std=c++11 -c hangman.cpp -o hangman.o 

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o

worm.o: worm.cpp worm.hpp
	 gcc -c -ggdb worm.cpp -o worm.o 

board.o: board.cpp board.hpp
	gcc -c -ggdb board.cpp -o board.o
clean:
	rm *.o *.x *~ *#	
	/bin/rm -f screen.x screen.o getChar.o *~

