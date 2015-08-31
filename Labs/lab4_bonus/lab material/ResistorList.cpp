//  File Name: ResistorList.cpp
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#include "ResistorList.h"
//constructor
Resistorlist::Resistorlist()
{
    head = NULL;//initialises head to NULL
}
//tail insert of a new resistor
bool Resistorlist:: tailInsert(Resistor *newRes)
{
    if(head == NULL)
        head = newRes;
    else
    {
        Resistor *tempRes = head;
        while(tempRes -> getNext()!= NULL)
            tempRes = tempRes -> getNext();
            tempRes -> setNext(newRes);
    }
    return true;
}
//deletes a resistor
bool Resistorlist::deleteResistor(string resistor)
{
    Resistor* current = head;
    Resistor* previous = NULL;
    while(current!= NULL && current -> getName()!= resistor)
    {
        previous = current;
        current = current -> getNext();
    }
    if(current == NULL)
        return false;
    if(previous == NULL)
        head = current -> getNext();
    else
        previous -> setNext(current -> getNext());
    delete current;
    return true;
}
//deletes all resistor in a resistor list, even deleting all the nodes
bool Resistorlist::deleteAllResistor()
{
    Resistor* current = head;
    while(current != NULL)
    {
        Resistor *previous = NULL;
        previous = current;
        current = current -> getNext();
        delete previous;
    }
    head = NULL;
    return true;
}
// prints a particular resistor
bool Resistorlist::printResistor(string resistor)
{
    Resistor* current = head;
    while(current!= NULL)
    {
        if(current -> getName() == resistor)
        {
            cout << setfill (' ') << setw (20); //Sets the output stream's field witdth
            cout << left << current -> getName(); // the output is alligned to left
            cout<<' ';
            cout << setfill (' ') << setw (8);
            cout << right << current -> getResistance(); // the output is alligned to right
            cout<<' ';
            cout<<"Ohms ";
            cout<<current -> getendpointNodeID1()<<" -> "<< current -> getendpointNodeID2()<<endl;
            return true;
        }
        current = current -> getNext();
    }
    return false;
}
// returns the head of a resistor list
Resistor *Resistorlist::getHead() const
{
    return head;
}
//returns the resistor if found in the resistor list
Resistor* Resistorlist::getResistor(string resistor) const
{
    Resistor* temp = head;
    while(temp != NULL)
    {
        if(temp -> getName() == resistor)
            return temp;
        temp = temp -> getNext();
    }
    return NULL;
}
int Resistorlist::countnumberofresistors()
{
    Resistor* current = head;
    while(current != NULL)
    {
        numberofresistors++;
        current = current -> next;
    }
    return numberofresistors;
}

// destructor
Resistorlist::~Resistorlist()
{
    Resistor* current = head;
    while(current != NULL)
    {
        Resistor *previous = NULL;
        previous = current;
        current = current -> getNext();
        delete previous;
    }
    head = NULL;
}