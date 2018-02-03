#include <iostream>
#include "ListMyJosephus.h"
//#include <math.h>
//#include <fstream>

using std::ofstream;

int main(void){



    ListMyJosephus newList = ListMyJosephus(1400,24);

    newList.startGame();

    newList.PrintEliminationSequence();

    newList.PrintTimingStats();

    cin.get();
    
        // //testing variables
        // ofstream outfile("data.csv");
        // double runTime = 0.0, averageElimination = 0.0;
        // int M = (int)pow(2, 1), i = 1;


        // while(M <= 1024){

        //     ListMyJosephus newList = ListMyJosephus(1024,M);

        //     newList.startGame();


        //     //testing
        //     newList.PrintTimingStats(runTime, averageElimination);
        //     outfile << M << "," << runTime << "," << averageElimination << "\n";
        //     i++;
        //     M = (int)pow(2, i);
        //     //testing
        // }

    

    return 0;
}