#include <iostream>
#include "ListMyJosephus.h"

int main(void){

    ListMyJosephus newList = ListMyJosephus(1400,24);

    newList.startGame();

    newList.PrintEliminationSequence();

    newList.PrintTimingStats();

    cin.get();

    return 0;
}