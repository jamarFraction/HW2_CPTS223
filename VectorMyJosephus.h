#ifndef __VECTORMyJosephus_H__
#define __VECTORMyJosephus_H__

#include <iostream>
#include <vector>
#include <time.h>
#include "Person.h"

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

using namespace std;

class VectorMyJosephus {

public:
	
	//empty playing circle constructor
	VectorMyJosephus();

	VectorMyJosephus(int passedN,int passedM);

	//Destructor
	~VectorMyJosephus();

	//This init function does the same thing as the argument constructor above.
	//This function is provided for convenience purposes:
	//To support the user code specifying either VectorMyJosephus(N,M) <or> VectorMyJosephus() first and then init(N,M). 
	//Both should achieve the same effect of initializing the game with N people and set M as the interval of elimination.
	void init(int N,int M);

	//makes the circle empty 
	void clear();

	//prints the number of people still playing the game (i.e., not yet eliminated) 
	int currentSize();

	//returns true if circle is empty
	bool isEmpty();

	//eliminates the next person as per the game's rule
	Person eliminateNext();

	//prints the current content of circle in sequence starting from the person with the least position number
	void printAll();

	//adds the passed person to the circle
	void addToCircle(Person passedPerson);

	//starts the elimination process
	void startGame();

	//prints the sequence of elimination
	void PrintEliminationSequence();

	//prints the timing stats of the game
	void PrintTimingStats();

private:

	//the circle itself
	vector<Person> circ; 

	//list containing the order in which players are eliminated
	vector<int> eliminationSequence;

	//dynamic size of circle; initially size=N and then it will keep decreasing with each elimination
	int size;
	
	//the number of people at the start of the game.
	int N;

	//the interval of elimination; i.e., number of positions to skip before next elimination
	int M;

	//game duration
	double gameDuration;

	//average elimination time of each player
	double averageEliminationTime;
	
	//controls position in the circle
	vector<Person>::iterator iterator;
};

#endif
