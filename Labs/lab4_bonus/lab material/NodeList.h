//  File Name: NodeList.h
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#ifndef __Lab_4__NodeList__
#define __Lab_4__NodeList__
#include "Node.h"
#include "ResistorList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
class Nodelist{
private:
    Node *head;//points to the head of a node
    double MIN_ITERATION_CHANGE;//change provided in the handout
    int numberofnodes;//number of nodes in a nodelist
public:
    Nodelist();//constructor
    bool headInsert(Node *newnode);//inserts a node from the head
    bool sortedInsert(Node *newnode);//sorts the nodes when inserted in a sorted manner
    bool printNode(int node);//prints a particular node
    bool printNodeall();//prints all nodes in a nodelist
    Node *gethead () const;//returns the head of node
    Node *getNode(int newID) const; //returns a particular ID number
    bool deleteNodeall();//deletes all the Nodes
    void Solve();//solves the voltages in a node using Gauss Saidel Method
    void printsolveallnodes();//prints the voltages of all nodes
    int calculatenumberofnodes();//calculates the number of nodes in a nodelist
    bool checkforVoltage();//checks if the voltage is there in a node or not
    void set_draw_coords(float& xleft, float& ybottom,float& xright,float& ytop);
    void draw();
    void setallnonodesvoltagetozero();//sets all the unset nodes to zero
    ~Nodelist();//destructor
};

#endif /* defined(__Lab_4__NodeList__) */
