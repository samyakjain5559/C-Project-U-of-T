//  File Name: Node.cpp
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Node.h"
#include "Resistor.h"

using namespace std;
//constructor
Node::Node(int NodeID)
{
    ID = NodeID; // the node number
    numRes = 0; // the number of resistors in a node
    next = NULL; // points the next pointer to NULL
    nextreslist = new Resistorlist; // makes a new resistor list whenever a new node is made
    SetV = false; // sets the value false if the voltage for a particular node doesnt exist
}

int Node::getID() const
{
    return ID; // accessor for the node ID
}

void Node::addResistor (Resistor *resistor)
{

    nextreslist -> tailInsert(resistor); // mutator to add a resistor in the resistor list
    numRes++; // increases the resistors in a node
}

Node* Node::getNext() const
{
    return next; // returns the pointer for the next node
}

void Node::setNext(Node *newID)
{
    next = newID; // mutator to add a new node
}

int Node::returnResnum() const
{
    return numRes; // accessor to return the number of resistors in a node
}

Resistorlist *Node:: list() const
{
    return nextreslist; // accessor to return the pointer of head of resistor list
}

void Node:: setResnumagain()
{
    numRes--; // mutator to delete a resistor of a node when called a delete command
}
double Node::getVoltage() const
{
    return voltage; // accessor to return the voltage of a particular node
}
void Node:: setVoltage(double setNewV, bool set)
{
    SetV = set; // true if there is a voltafe set by the user otherwise false
    voltage = setNewV; // mutator to set the voltage of a particular node
}
bool Node::returnset() const
{
    return SetV; // accessor to return the voltage of a node
}
void Node::drawNode(float x1, float y1, float x)
{
    window.gl_setfontsize(2);
    window.gl_setcolor(BLACK);
    string line,name;
    int nodeID;
    name = "Node ";
    nodeID = ID;
    stringstream linestream(line);
    linestream>>name>>nodeID;
    window.gl_drawtext(x1,y1,line,x);
}


void Node::drawVoltage(float x1, float y1, float x2, float y2, float x)
{
    float x1 = 4, y1 = 2, x2 = 8, y2 = 2 ,x = 14;
    window.gl_setfontsize(2);
    window.gl_setcolor(CYAN);
    string line;
     stringstream linestream(line);
     cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
     double volt = 0;
     char V;
     V = 'V';
     volt = voltage;
    linestream>>volt>>V;
    window.gl_drawtext(x1,y1,volt,x);
}

void Node::filledRectange(float x1, float y1, float x2, float y2)
{
    float x1 =3, x2 = 5, y1 = 8, y2 = numberofresistors*5;
    window.gl_setcolor (LIGHTGREY);
   window.gl_fillrect (x1,y1,x2,y2);
}


Node::~Node()//destructor to delete the resistor list of a particulat node
{
    delete nextreslist;
    nextreslist = NULL;
}