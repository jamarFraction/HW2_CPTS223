#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus()
{

    int newN = 0, newM = 0;

    //List size initializer
    this->size = 0;

    //Prompt user for N and M values
    cout << "Please enter an N value (number of player in the game): ";
    cin >> newN;

    cout << "Please enter an M value (number of times to pass the potato): ";
    cin >> newM;

    system("clear");

    //Pass to the public list initializer method
    init(newN, newM);
}

ListMyJosephus::ListMyJosephus(int passedN, int passedM)
{

    //List size initializer
    this->size = 0;

    //Pass to the public list initializer method
    init(passedN, passedM);
}

ListMyJosephus::~ListMyJosephus() {}

void ListMyJosephus::init(int passedN, int passedM)
{

    this->N = passedN;
    this->M = passedM;

    //create a person and and them to the circle
    for (int i = 0; i < N; i++)
    {

        //The newly created person's starting position will be i
        Person current = Person(i);

        //add the person to the circle
        addToCircle(current);

        //increment the list size by 1
        this->size += 1;
    }
}

void ListMyJosephus::addToCircle(Person passedPerson)
{

    //Push the person to the back of the list, which coincides with the position
    this->circ.push_back(passedPerson);
}

void ListMyJosephus::clear()
{

    while (!this->isEmpty())
    {

        //pop the 0 element and decrement the size
        this->circ.pop_front();

        this->size -= 1;
    }
}

bool ListMyJosephus::isEmpty()
{

    return this->circ.size() == 0;
}

int ListMyJosephus::currentSize()
{

    return this->size;
}

void ListMyJosephus::printAll()
{

    //iterate through the list and print the position contents
    list<Person>::iterator location = circ.begin();

    cout << "{" << flush;

    for (; location != circ.end(); ++location)
    {

        cout << location->getPosition() << flush;
    }

    cout << "}" << flush;

    cin.get();

    system("clear");
}

void ListMyJosephus::startGame()
{

    clock_t startTime, endTime;

    startTime = clock();

    //set the iterator to the biginning the list
    iterator = circ.begin();

    //continue while theres still at least 1 person in the circle
    while (this->size > 1)
    {

        eliminateNext();

        //temp varibale created to test if this element is at the end of
        //the list
        list<Person>::iterator temp = iterator;
        temp++;

        if (temp == circ.end())
        {

            iterator = circ.begin();
            circ.pop_back();
        }
        else
        {

            iterator = circ.erase(iterator);
        }

        //decrement the size of the circle
        size -= 1;

        //printAll();
    }

    //capture the time for the for the end of the game
    endTime = clock();

    //calculate duration of the game
    this->gameDuration = (endTime - startTime);
    gameDuration = gameDuration / CLOCKS_PER_MS;

    //calculate average time between eliminations
    averageEliminationTime = gameDuration / (N-1);
}

Person ListMyJosephus::eliminateNext()
{

    for (int i = 0; i < M; i++)
    {

        if (iterator == circ.end())
        {

            iterator = circ.begin();
        }
        ++iterator;
    }

    //check again
    if (iterator == circ.end())
    {

        iterator = circ.begin();
    }

    //add the the iterator position to the eliminated list
    int toRemove = (*iterator).getPosition();
    this->eliminationSequence.push_back(toRemove);

    //get outta here
    return *iterator;
}

void ListMyJosephus::PrintEliminationSequence(){

    //prints order of elimination in the form:
    //{ x x2 x3 ... xN-1 }, winner: y 
    if(!this->isEmpty()){

        cout << "Elimination Sequence: { " << flush;

        std::list<int>::iterator it = eliminationSequence.begin();

        for(;it != eliminationSequence.end(); ++it){

            cout << *it << " " << flush;

        }
        
        cout << "}, winner: " << circ.begin()->getPosition() << endl;
    }


}

void ListMyJosephus::PrintTimingStats(){

    cout << "Total game time: " << this->gameDuration << "ms" << endl;

    cout << "Average elimination time: " << this->averageEliminationTime << "ms" << endl;

    // //testing
    // passedRT = this->gameDuration;
    // passedAT = this->averageEliminationTime;
    // //testing
}
