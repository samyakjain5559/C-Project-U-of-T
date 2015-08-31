// File Name: Rparser.cpp
// Created by Vaibhav Vijay on 2013-10-06
// Copyright (c) 2013 Vaibhav Vijay. all rights reserved.
// Last updated on: November 10, 2013

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Rparser.h"

using namespace std;

easygl window("Resistor Display", WHITE);


// Constructor: to define the default values
Parser::Parser()
{
    resnodes[0] = 0;
    resnodes[1] = 0;
    unsetVoltage = 0;
    g_NodeListPtr = &nodeStart;
}
//parser to start the project
void Rparser()
{
    Parser obj;
    string line;
    cout<<"> ";
    getline(cin,line);
    while(!cin.eof())
    {
        obj.input(line);
        cout<<"> ";
        getline(cin,line);
        
    }
}
bool Parser::input(string line)
{
    stringstream linestream(line);
    linestream>>command;
    if(command == "insertR")
    {
        insertR(line);
        return true;
    }
    //calls function modifyR when the command is modifyR
    else if(command == "modifyR")
    {
        modifyR(line);
        return true;
    }
    //calls function printR when the command is printR
    else if(command == "printR")
    {
        printR(line);
        return true;
    }
    //calls function printNode when the command is printNode
    else if(command == "printNode")
    {
        printNode(line);
        return true;
    }
    //calls function deleteR when the command is deleteR
    else if(command == "deleteR")
    {
        deleteR(line);
        return true;
    }
    //calls the function setV when the command is setV
    else if(command == "setV")
    {
        setV(line);
        return true;
    }
    //calls the function unsetV when the command is unsetV
    else if(command == "unsetV")
    {
        unsetV(line);
        return true;
    }
    //calls the function solve when the commmand is solve
    else if(command == "solve")
    {
        solve(line);
        return true;
    }
    else if(command == "draw")
    {
        parse_draw(nodeStart);
        return true;
    }
    return true;
}


//inserts the line in the starting
bool Parser::insertR(string line)
{
    stringstream linestream(line);
    linestream>>command>>name>>resistance>>node1>>node2;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    resnodes[0] = node1;
    resnodes[1] = node2;
    Resistor *resnode1 = new Resistor(name,resistance,resnodes);
    Resistor *resnode2 = new Resistor(name,resistance,resnodes);
    Node *temp = nodeStart.gethead();
    if(temp == NULL)
    {
        Node *node_1 = new Node(node1);
        Node *node_2 = new Node(node2);
        nodeStart.headInsert(node_1);
        node_1 -> addResistor(resnode1);
        nodeStart.sortedInsert(node_2);
        node_2 -> addResistor(resnode2);
        cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
        return true;
    }
    
    else
    {
        
        Node *place1;
        Node *place2;
        place1 = nodeStart.getNode(node1);
        place2 = nodeStart.getNode(node2);
        if(place1 != NULL && place2 != NULL)
        {
            place1 -> addResistor(resnode1);
            place2 -> addResistor(resnode2);
            cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
            return true;
        }
        
        else if(place1 != NULL && place2 == NULL)
        {
            place1 -> addResistor(resnode1);
            Node *node_2 = new Node(node2);
            nodeStart.sortedInsert(node_2);
            node_2 -> addResistor(resnode2);
            cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
        }
        else if(place2 != NULL && place1 == NULL)
        {
            place2 -> addResistor(resnode2);
            Node *node_1 = new Node(node1);
            nodeStart.sortedInsert(node_1);
            node_1 -> addResistor(resnode1);
            cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
        }
        else
        {
            Node *node_1 = new Node(node1);
            Node *node_2 = new Node(node2);
            nodeStart.sortedInsert(node_1);
            node_1 -> addResistor(resnode1);
            nodeStart.sortedInsert(node_2);
            node_2 -> addResistor(resnode2);
            cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
        }
    }
    
    return true;
}

//modifies a resistance in a node
//changes the resistance twice
bool Parser::modifyR(string line)
{
    stringstream linestream(line);
    linestream>>command>>name>>resistance;
    bool isFound = false;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    Node *temp = nodeStart.gethead();
    double oldRes;
    while(temp != NULL)
    {
        
        Resistor *rtempo = temp->list() -> getHead();
        
        while(rtempo != NULL)
        {
            if(name == rtempo-> getName())
            {
                oldRes = rtempo -> getResistance();
                rtempo -> setResistance(resistance);
                isFound = true;
            }
            rtempo = rtempo->getNext();
            
        }
        temp = temp->getNext();
    }
    
    if(isFound)
    {
        cout<<"Modified: resistor "<<name<<" from "<<oldRes<<" Ohms to "<<resistance<<" Ohms"<<endl;
        return true;
    }
    else
    {
        cout<<"Error: resistor " <<name<<" not found"<<endl;
    }
    return isFound;
}

//prints a particular resistor
bool Parser::printR(string line)
{
    stringstream linestream(line);
    bool isFound = false;
    linestream>>command>>name;
    Node *temp = nodeStart.gethead();
    while(temp != NULL)
    {
        if(temp -> list() == NULL)
        {
            cout<<"Error: resistor " << name <<" not found"<<endl;
            return false;
        }
        else if(temp -> list() -> getResistor(name))
        {
            cout<<"Print: "<<endl;
            isFound = true;
            temp -> list() -> printResistor(name);
            return true;
        }
        temp = temp -> getNext();
    }
    if(!isFound)
    {
        cout<<"Error: resistor " << name <<" not found"<<endl;
        return false;
    }
    return true;
}

//prints a particular node and all nodes according to the commands
bool Parser::printNode(string line)
{
    stringstream linestream(line);
    bool isFirst = false;
    
    int printN = 0;
    linestream>>command;
    linestream>>name;
    if(name == "all")
    {
        Node *tempall = nodeStart.gethead();
        if(tempall == NULL)
        {
            cout<<"Print: "<<endl;
            isFirst = true;
        }
        else
        {
            cout<<"Print: "<<endl;
            nodeStart.printNodeall();
            return true;
        }
    }
    else
    {
        stringstream checkForNumb(name);
        checkForNumb>>printN;
        cout<<"Print: "<<endl;
        nodeStart.printNode(printN);
    }
    Node* temp = nodeStart.getNode(printN);
    if(temp == NULL && !isFirst)
    {
        cout<<"Print: "<<endl;
    }
    
    return true;
}

//deletes all resistors or a specific resistor according to the command
bool Parser::deleteR(string line)
{
    stringstream linestream(line);
    bool isFound = false;
    linestream>>command>>name;
    Node *temp = nodeStart.gethead();
    if(name == "all")
    {
        while(temp!= NULL)
        {
            temp -> list() -> deleteAllResistor();
            temp -> setResnumagain();
            temp = temp -> getNext();
        }
        nodeStart.deleteNodeall();
        cout<<"Deleted: all resistors"<<endl;
        return true;
    }
    else
    {
        while(temp != NULL)
        {
            if((temp -> list() -> deleteResistor(name)))
            {
                temp -> setResnumagain();
                isFound = true;
            }
            
            temp = temp -> getNext();
        }
        if(isFound)
        {
            cout<<"Deleted: resistor "<<name<<endl;
        }
        else
        {
            cout<<"Error: resistor "<<name<<" not found"<<endl;
        }
    }
    return true;
}
//sets the voltage of a particular node
bool Parser::setV(string line)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    stringstream linestream(line);
    linestream>>command>>nodeid>>voltage;
    Node *temp = nodeStart.getNode(nodeid);
    if(temp != NULL)
    {
        temp -> setVoltage(voltage, true);
    }
    else
    {
        Node *nodeID = new Node(nodeid);
        nodeStart.sortedInsert(nodeID);
        nodeID -> setVoltage(voltage, true);
    }
    cout<<"Set: node "<<nodeid<<" to "<<voltage<<" Volts"<<endl;
    return true;
}
//unsets the voltage of a particular node
bool Parser::unsetV(string line)
{
    stringstream linestream(line);
    linestream>>command>>nodeid;
    Node *temp = nodeStart.getNode(nodeid);
    if(temp != NULL)
    {
        temp -> setVoltage(unsetVoltage, false);
    }
    else
    {
        Node *nodeID = new Node(nodeid);
        nodeStart.sortedInsert(nodeID);
        nodeID -> setVoltage(unsetVoltage, false);
    }
    cout<<"Unset: the solver will determine the voltage of node "<<nodeid<<endl;
    return true;
}
//solves for the voltage in the entire circuit using Gauss Saidel equation
bool Parser::solve(string line)
{
    stringstream linestream(line);
    linestream>>command;
    if(nodeStart.checkforVoltage())
    {
        cout<<"Error: no nodes have their voltage set"<<endl;
        return false;
    }
    else
    nodeStart.Solve();
    return true;
}

void Parser::parse_draw(Nodelist& nodeList)
{
    float xleft, ybottom, xright, ytop;
    nodeList.set_draw_coords(xleft, ybottom, xright, ytop);
    window.set_world_coordinates(xleft, ybottom, xright, ytop);
    g_NodeListPtr = &nodeList;
    nodeList.draw();
    cout<<"Draw: control passed to graphics window."<<endl;
    window.gl_event_loop();
    cout<<"Draw: complete; responding to commands again"<<endl;
}

void easygl::drawscreen()
{
    window.gl_clearscreen();
    g_NodeListPtr -> draw;
}