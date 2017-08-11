#Name: Nick Schneider, Brian Dobransky
#Username: cssc1093, cssc1094
#Class: CS570, Summer 2017
#Assignment: assignment #1, bots
#Due: 6-5-2017
#Instructor: Prof. Leonard
#Files: Makefile
bots: bots.o main.o
	g++ -pthread -std=c++11 bots.o main.o -o bots

main.o: main.cpp bots.h
	g++ -c main.cpp

bots.o: bots.cpp bots.h
	g++ -pthread -std=c++11 -c bots.cpp

clean:
	rm -f *.o bots quote.txt
tar:
	tar -czvf bots.tar.gz main.cpp bots.h bots.cpp Makefile README.txt
