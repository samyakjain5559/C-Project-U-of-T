//  File Name: NodeList.cpp
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: November 10, 2013

#include "NodeList.h"
//constructor

Nodelist::Nodelist() {
    head = NULL; //initializes the head to NULL
    MIN_ITERATION_CHANGE = 0.0001; //value given in the handout
    numberofnodes = 0; //the variable to count the number of nodes in a nodelist
}

bool Nodelist::headInsert(Node *newNode)//used to insert the first node in the nodelist
{
    newNode -> setNext(head);
    head = newNode;
    return true;
}

bool Nodelist::sortedInsert(Node *newNode)//insert the remaining nodes in the nodelist in sorting order
{
    int tempnode = newNode -> getID();
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL && current -> getID() < tempnode) {
        previous = current;
        current = current ->getNext();
    }
    newNode -> setNext(current);
    if (previous == NULL)
        head = newNode;
    else
        previous -> setNext(newNode);
    return true;
}

Node* Nodelist::getNode(int newID) const//get a particular node
{
    Node* temp = head;
    while (temp != NULL) {
        if (temp -> getID() == newID)
            return temp;
        temp = temp -> getNext();
    }
    return NULL;
}

bool Nodelist::printNode(int node)//print a particular node
{
    Node*current = head;
    while (current != NULL) {
        if (current-> getID() == node) {
            if (current -> list() -> getHead() == NULL)
                return false;


            int number = current -> returnResnum();
            cout << "Connections at node " << node << ": " << number << " resistor(s)" << endl;


            Resistor *access = current -> list() -> getHead();
            while (access != NULL) {
                string resistor = access -> getName();
                cout << "  ";
                current -> list() -> printResistor(resistor);
                access = access -> getNext();
            }
            return true;

        }
        current = current -> getNext();
    }
    return true;
}

bool Nodelist::printNodeall()//print all nodes
{
    Node*current = head;
    while (current != NULL) {
        if (current -> list() -> getHead() != NULL) {
            int number = current -> returnResnum();
            cout << "Connections at node " << current -> getID() << ": " << number << " resistor(s)" << endl;


            Resistor *access = current -> list() -> getHead();
            while (access != NULL) {
                string resistor = access -> getName();
                cout << "  ";
                current -> list() -> printResistor(resistor);
                access = access -> getNext();
            }
        }
        current = current -> getNext();
    }
    return true;
}

Node* Nodelist::gethead() const//gets the head of a node
{
    return head;
}

bool Nodelist::deleteNodeall() // delete all nodes in the network
{
    Node* current = head;
    Node *previous = NULL;
    while (current != NULL) {

        previous = current;
        current = current -> getNext();
        delete previous;
    }
    head = NULL;
    return true;
}

void Nodelist::Solve() // solve for all the voltages in a circuit using Gauss Saidel Method
{
    setallnonodesvoltagetozero();
    int nodeendpoint1, nodeendpoint2, theotherid, countNode, numNodes = 0;
    numNodes = calculatenumberofnodes();
    double voltageendpoint, resistorpoint, VoltageDivideByResistor = 0, onedividebyresistor = 0, nodeVoltage, change;
    bool iterateAgain = true;
    Node* current;

    while (iterateAgain) {
        current = head;
        countNode = 0;
        iterateAgain = false;

        while (current != NULL) {
            Resistor* res = current -> list() -> getHead();
            change = 0;
            VoltageDivideByResistor = 0;
            onedividebyresistor = 0;
            if (current->returnset() == false) {
                while (res != NULL) {
                    nodeendpoint1 = res -> getendpointNodeID1();
                    nodeendpoint2 = res -> getendpointNodeID2();
                    if (current->getID() == nodeendpoint1)
                        theotherid = nodeendpoint2;
                    else
                        theotherid = nodeendpoint1;
                    resistorpoint = res -> getResistance();
                    Node *point = getNode(theotherid);
                    voltageendpoint = point -> getVoltage();
                    VoltageDivideByResistor += voltageendpoint / resistorpoint;
                    onedividebyresistor += 1 / resistorpoint;
                    res = res -> getNext();
                }
                nodeVoltage = VoltageDivideByResistor / onedividebyresistor;
                change = abs(current -> getVoltage() - nodeVoltage);
                current -> setVoltage(nodeVoltage, false);
            }
            if (change > MIN_ITERATION_CHANGE) {
                iterateAgain = true;
            }
            current = current -> getNext();
        }

    }
    printsolveallnodes();
}

bool Nodelist::checkforVoltage()//checks for the voltage if a particular node has voltage or not
{
    Node* current = head;
    int countforVolt = 0;
    while (current != NULL) {
        if (current -> getVoltage() != 0) {
            countforVolt++;
        }
        current = current -> getNext();
    }

    if (countforVolt == 0)
        return true;
    else
        return false;
}

int Nodelist::calculatenumberofnodes()//calculates number of nodes in a nodelist
{
    Node* current = head;
    while (current != NULL) {
        numberofnodes++;
        current = current -> getNext();
    }
    return numberofnodes;
}

void Nodelist::printsolveallnodes() // prints the voltages of all nodes
{
    Node * current = head;
    double volt;
    cout << "Solve: " << endl;
    while (current != NULL) {
        volt = current -> getVoltage();
        cout << "Node " << current -> getID() << ": " << volt << " V" << endl;
        current = current -> getNext();
    }
}

void Nodelist::setallnonodesvoltagetozero() //sets all the node voltages to zero that are unset
{
    Node*temp = head;
    while (temp != NULL) {
        if (!temp -> returnset()) {
            temp -> setVoltage(0, false);
        }
        temp = temp -> getNext();
    }
    temp = NULL;
}

void Nodelist::set_draw_coords(float &xleft, float &ybottom, float& xright, float& ytop) {
    int totalnodes = numberofnodes;
    int numberofresistors = 0;
    int storetheresistorsperlist = 0;
    Node *current = head;
    {
        while (current != NULL) {
            storetheresistorsperlist = current->list()->countnumberofresistors();
            numberofresistors += storetheresistorsperlist;
            storetheresistorsperlist = 0;
            current = current -> getNext();
        }
    }

    xright = totalnodes * 20;
    ytop = numberofresistors * 20;
    xleft = 0;
    ybottom = 0;
    window.set_world_coordinates(xleft, ybottom, xright, ytop);
}

void Nodelist::draw() {
    window.gl_clearscreen();
    Node *current = head;
    Resistor *rtempo = head -> list() ->getHead();
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0;
    float heightofrectangle = 1;
    while (current != NULL) {
        x1 += 8;
        x2 += 16;
        y1 += 4;
        y2 += 4;
        x = 20;
        current -> drawVoltage(x1,y1,x2,y2,x);
        y1 += 8;
        current -> drawNode(x1,y1,x);
        y1 += 8;
        heightofrectangle = numberofresistors * heightofrectangle;
        current -> filledRectange(x1, y1, x2, heightofrectangle);
        current = current -> getNext();
    }
    current = head;
    x1 = 12; y1 = 8; x2 = 20; y2 = 8; x = 20;
    while(current != NULL)
    {
       while (rtempo != NULL) {
            rtempo -> drawdotfirst(x1,y1);
            rtempo -> drawhorrizontalline(x1,y1,x2,y2);
            rtempo -> drawdotsecond(x2, y2);
            x1 += 2;
            rtempo -> drawnamewithresistance(x1,y1,x);
            x1 += 6;
            x2 += 8;
            y1 += 4;
            y2 += 4;
            rtempo = rtempo ->getNext();
        }
    current = current -> getNext();
    }
}

Nodelist::~Nodelist()//destructor to delete all the remaining nodes
{
    Node* current = head;
    Node *previous = NULL;
    while (current != NULL) {

        previous = current;
        current = current -> getNext();
        delete previous;
    }
    head = NULL;

}