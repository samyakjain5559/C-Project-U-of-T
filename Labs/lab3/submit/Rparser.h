//  File Name: Rparser.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: October 2013

#ifndef RPARSER_H
#define RPARSER_H
#include <iostream>
#include <string>
#include "Resistor.h"
#include "Node.h"
using namespace std;

class Parser
{
private:
    // Variables:
    // command - stores the command part of the input line
    // name - stores the name of the resistor
    // resistance - stores the value of the resistance
    // node1 - stores the value of the first node
    // node2 - stores the value of the second node
    // count - counts the number of words in a line
    string  command, name;
    char line[300];
    int letters;
    double resistance;
    int node1, node2;
    int count;
    int INSERT_WORD_PER_LINE;
    int MODIFY_WORD_PER_LINE;
    int PRINT_WORD_PER_LINE;
    int DELETE_WORD_PER_LINE;
    int NODE_WORD_PER_LINE;
    int numberOfWords;
    int maxNodeNumber; // specifies the appropriate size for the resistor
    int maxResistors; // specifies the appropriate size for the node arrays
    int resistorIndex;
    int newMaxNode;


public:
    Parser();
    bool input(string word); //Checks the command string
    bool insertR(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    int countWords(string line); // counts the number of words in a string
    bool modifyR(string line); //Checks the string where command is insertR
                            //Returns TRUE with printed statement if valid
    bool printR(string line);//Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool printNode(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool deleteR(string line); //Checks the string where command is insertR
                                //Returns TRUE with printed statement if valid
    bool maxVal(string line); //Checks the string where command is insertR
                            //Returns TRUE with printed statement if valid

};
//Checks the input and builds the network
void Rparser();
#endif /* defined(__Rparser__Rparser__) */
