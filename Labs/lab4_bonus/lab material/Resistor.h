//  File Name: Resistor.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
class Resistor
{
private:
    Resistor *next;
   double resistance; // resistance (in Ohms)
   string name; // C++ string holding the label
   int endpointNodeIDs[2]; // IDs of nodes it attaches to

public:
    Resistor *getNext () const;
    void setNext (Resistor *newRes);
    Resistor (string name,double resistance,int endpoints_[2]);
   ~Resistor();

   string getName() const; // returns the name
   double getResistance() const; // returns the resistance

   void setResistance (double resistance_);//mutator to change the resistance
    int getendpointNodeID1() const;//accessor to return the node 1 in the resistor
    int getendpointNodeID2() const;//accessor to return the node 2 in the resistor
    void drawdotfirst();
    void drawnamewithresistance();
    void drawdotsecond();
    void drawhorrizontalline();
};



#endif	/* RESISTOR_H */

