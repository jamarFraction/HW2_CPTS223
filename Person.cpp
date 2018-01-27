#include "Person.h"

Person::Person(int passedPosition){

    //set the person's position to either the passed position or the default 0
    this->position = passedPosition;

}

Person::~Person(){};


void Person::print(){

    //print out the position of the current person
    std::cout << this->position << std::endl;


}