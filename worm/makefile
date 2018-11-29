screen.x:  screen.o getChar.o board.o worm.o
	g++ -ggdb -o screen.x screen.o worm.o getChar.o board.o -lcurses -ltermcap

screen.o: screen.cpp
	g++ -c -ggdb screen.cpp -o screen.o

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o

worm.o: worm.cpp worm.h
	gcc -c -ggdb worm.cpp -o worm.o

board.o: board.cpp board.h
	gcc -c -ggdb board.cpp -o board.o
clean:
	/bin/rm -f screen.x screen.o getChar.o *~
