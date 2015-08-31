//  File Name: Resistor.cpp
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#include <string>
#include <iostream>
#include <iomanip>
#include "Resistor.h"
#include "Node.h"
using namespace std;

//accessor to get the next resistor
Resistor *Resistor ::getNext() const
{
    return next;
}
//mutator to set the next resistor in the list
void Resistor::setNext(Resistor *newRes)
{
    next = newRes;
}
Resistor::Resistor(string newname,double newresistance,int endpoints_[2])
{
    name = newname;
    resistance = newresistance;
    for(int i = 0; i<2 ; i++)
    {
        endpointNodeIDs[i] = endpoints_[i];

    }
    next = NULL;

}

//Accessor to get the name of the resistor
string Resistor::getName() const
{
    return name;
}
int Resistor::getendpointNodeID1() const
{
    return endpointNodeIDs[0];
}
int Resistor::getendpointNodeID2() const
{
    return endpointNodeIDs[1];
}
//Accessor to ger the resistance of the resistor
double Resistor::getResistance() const
{
    return resistance;
}

//Mutator to write a new value to the resistance
void Resistor::setResistance(double newResistance)
{
    resistance = newResistance;

}
void Resistor::drawdotfirst(float xcen, float ycen)
{
    window.gl_setcolor (DARKGREEN);   
    window.gl_fillarc(xcen,ycen,2,0,360);
}

void Resistor::drawdotsecond(float xcen, float ycen)
{
     window.gl_setcolor (DARKGREEN);   
     window.gl_fillarc (520.,300.,2,0,360);
}
void Resistor::drawhorrizontalline(float x1, float y1, float x2, float y2)
{
   window.gl_setlinestyle (SOLID);
   window.gl_setcolor (MAGENTA);
   window.gl_setlinewidth (1);
   window.gl_drawline(x1,y1,x1+1,y1);
   window.gl_drawline(x1+1,y1,x1+2,y1+1);
   window.gl_drawline(x1+2,y1+1,x1+3,y1-1);
   window.gl_drawline(x1+3,y1-1,x1+4,y1+1);
   window.gl_drawline(x1+4,y1+1,x1+5,y1-1);
   window.gl_drawline(x1+5,y1-1,x1+6,y1+1);
   window.gl_drawline(x1+6,y1+1,x1+7,y1-1);
   window.gl_drawline(x1+7,y1-1,x1+7,y2);
   window.gl_drawline(x1+7,y1-1,x2,y2);
}
void Resistor::drawnamewithresistance(float x1, float y1, float x)
{
    string line,ohm, resname;
    resname = name;
    double res = resistance;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    char openbracket, closebracket,whitespace;
    whitespace = ' ';
    openbracket = ' (';
    closebracket = ') ';
    ohm = "Ohm";
    stringstream linestream(line);
    line>>resname>>openbracket>>res>>whitespace>>ohm>>closebracket;
    window.gl_setcolor (BLACK);
    window.gl_setfontsize (2);
    window.gl_drawtext (x1,y1,line,x);
}

//Destructor
Resistor::~Resistor(){}
