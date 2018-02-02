#include <iostream>
#include "VectorMyJosephus.h"

int main(void){

    VectorMyJosephus newList = VectorMyJosephus(1400,24);

    newList.startGame();

    newList.PrintEliminationSequence();

    newList.PrintTimingStats();

    cin.get();

    return 0;
}