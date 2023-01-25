executavel:  Midia.o Cd.o Dvd.o main.o
	g++  Midia.o Cd.o Dvd.o main.o -o executavel

Midia.o: Midia.cpp
	g++ -c -Wall -Wextra Midia.cpp

Cd.o: Cd.cpp
	g++ -c -Wall -Wextra Cd.cpp

Dvd.o: Dvd.cpp
	g++ -c -Wall -Wextra Dvd.cpp

main.o: main.cpp
	g++ -c -Wall -Wextra main.cpp
