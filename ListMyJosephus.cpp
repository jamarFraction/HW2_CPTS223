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
    for (int i = 0; i < this->N; i++)
    {

        //The newly created person's starting position will be i
        Person currentPerson = Person(i);

        //add the person to the circle
        addToCircle(currentPerson);

        //increment the list size by 1
        this->size += 1;
    }
}

void ListMyJosephus::addToCircle(Person &passedPerson)
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