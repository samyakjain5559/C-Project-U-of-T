//  File Name: Rparser.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#ifndef RPARSER_H
#define RPARSER_H


#include <iostream>
#include <string>
#include "Resistor.h"
#include "Node.h"
#include "ResistorList.h"
#include "NodeList.h"
#include "easygl.h"
using namespace std;
Nodelist *g_NodeListPtr;
class Parser
{
private:
    // Variables:
    // command - stores the command part of the input line
    // name - stores the name of the resistor
    // resistance - stores the value of the resistance
    string  command, name;
    double resistance, voltage;
    int node1, node2;
    int resnodes[2];
    Nodelist nodeStart;//object of the Nodelist
    int nodeid;
    double unsetVoltage;//is zero

public:
    Parser();
    bool input(string word); //Checks the command string
    bool insertR(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool modifyR(string line); //Checks the string where command is insertR
                            //Returns TRUE with printed statement if valid
    bool printR(string line);//Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool printNode(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool deleteR(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool setV(string line); //Checks the string where the command is setV
                            //Returns TRUE with printed statement if valid
    bool unsetV(string line);//Checks the string where the command is unsetV
                            //Returns TRUE with printed statement if valid
    bool solve(string line);//Checks the string where the command is solve
                            //Returns TRUE with printed statement if valid
    void parse_draw(Nodelist& nodelist);
};
//Checks the input and builds the network
void Rparser();
#endif /* defined(__Rparser__Rparser__) */
