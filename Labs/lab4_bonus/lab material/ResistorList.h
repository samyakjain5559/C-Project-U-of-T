//  File Name: ResistorList.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#ifndef __Lab_4__ResistorList__
#define __Lab_4__ResistorList__

#include "Resistor.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int numberofresistors = 0;
class Resistorlist
{
private:
    Resistor* head;//head of a resistor
public:
    Resistorlist();//resistor list
    bool tailInsert(Resistor *newRes);//inserts a resistor in the tail
    bool deleteResistor (string resistor);//deletes a particular resistor
    bool deleteAllResistor();//deletes all the resistor in the list
    bool printResistor(string resistor);//prints a particular resistor
    Resistor *getHead() const;//returns the head of the resistor list
    Resistor *getResistor(string resistor) const;//gets the resistor in the resistor array
    int countnumberofresistors();
    ~Resistorlist();//destructor
};
#endif /* defined(__Lab_4__ResistorList__) */
