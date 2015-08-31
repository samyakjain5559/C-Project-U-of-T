//  File Name: Node.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#ifndef NODE_H
#define NODE_H

#include "ResistorList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Node
{
private:

    int ID;//the ID of a node
    int numRes;//number of resistors in a node
    Resistorlist *nextreslist;//the resistor list of a node
    Node *next;//the next node
    double voltage;// the voltage of a particular node
    bool SetV;//true if voltage is set else false

public:
    Node();//constructor
    Resistorlist *list() const;//accessor to return the resistor list
    void Resnum();//accessor to get the number of resistors in a node
    Node* getNext()const;//gets the next node
    Node(int NodeID);//finds the specified node
    int getID() const;//gets the ID of the node
    void setNext(Node *newID);//sets the next node
    int returnResnum() const;//returns the number of resistors in a node
    void addResistor (Resistor *resistor);//adds a particular resistor in the resistor list
    void setResnumagain();//decreases the number of resistor if deleted of a node
    double getVoltage() const;//gets the voltage of a node
    void setVoltage(double newV, bool set);//sets the voltage of a particular node
    bool returnset() const;//returns the set if voltage exists and if true
    void drawNode();
    void drawVoltage();
    void filledRectange();
    ~Node();
};

#endif	/* NODE_H */

