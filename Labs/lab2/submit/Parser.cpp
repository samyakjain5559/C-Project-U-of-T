// Parser.cpp
// Created by Vaibhav Vijay on 2013-10-06
// Copyright (c) 2013 Vaibhav Vijay. all rights reserved.
// Last updated on: October 10, 2013

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

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
    string  command, name;
    char line[300];
    int letters;
    double resistance;
    int node1, node2;
    int MAX_NODE_NUMBER;
    int count;
    int INSERT_WORD_PER_LINE;
    int MODIFY_WORD_PER_LINE;
    int PRINT_WORD_PER_LINE;
    int DELETE_WORD_PER_LINE;
    int NODE_WORD_PER_LINE;
    int numberOfWords;
public:
    Parser();
    bool input(string word);
    bool insertR(string line);
    int countWords(string line);
    bool modifyR(string line);
    bool printR(string line);
    bool printNode(string line);
    bool deleteR(string line);
};

// Constructor: to define the default values
Parser::Parser()
{
    letters = 0;
    MAX_NODE_NUMBER = 5000;
    INSERT_WORD_PER_LINE =5;
    MODIFY_WORD_PER_LINE = 3;
    PRINT_WORD_PER_LINE = 2;
    DELETE_WORD_PER_LINE =2;
    NODE_WORD_PER_LINE =2;
    numberOfWords = 0;
}

bool Parser::input(string word)
{
    // Counts the number of letters in a string
    for(int i =0; word[i]!='\0'; i++)
        letters++;

    // Copies the string into a new string called 'line'
    size_t length = word.copy(line,letters,0);
    line[length]='\0';

    stringstream linestream(line);
    linestream>>command;

    // Checks for the command entered and calls a function accordingly
    if(command == "insertR")
    {
        insertR(line);
        return true;
    }
    else if(command == "modifyR")
    {
        modifyR(line);
        return true;
    }

    else if(command == "printR")
    {
        printR(line);
        return true;
    }

    else if(command == "printNode")
    {
        printNode(line);
        return true;
    }

    else if(command == "deleteR")
    {
        deleteR(line);
        return true;
    }
    else
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }
}

bool Parser::insertR(string line)
{
    //checks for the arguments, when command is insertR

    numberOfWords = countWords(line);
    // Counts number of words in a string
    if(numberOfWords == 0)
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }

    stringstream linestream(line);
    linestream>>command;

    linestream>>name;

    // Checks if the resistor name is "all"
    // Returns out of the function if the condition is satisfied
    if(name == "all")
    {
        cout<<"Error: resistor name cannot be the keyword \"all\"" <<endl;
        return false;
    }

    // Checks if enough arguments are not specified
    else if(linestream.eof())
    {
        cout<<"Error: too few arguments"<<endl;
        return false;
    }

    linestream>>resistance;

    // Checks if the resistance entered is negative
    if(resistance< 0)
    {
        cout<<"Error: negative resistance"<<endl;
        return false;
    }

    // Checks if a real number is not entered for the resistance
    else if(linestream.fail())
    {
        cout<<"Error: invalid argument"<<endl;
        return false;
    }
    else if(linestream.peek()!= ' ' && linestream.peek()!= '\t') // Checks if an integer is not entered for the node number
    {
        if(linestream.eof()) // Checks if more than enough arguments have been entered for the current commmand
        {
            cout<<"Error: too few arguments"<<endl;
            return false;
        }
        else
        {
            cout<<"Error: invalid argument"<<endl;
            return false;
        }
    }


    linestream>>node1;

    if (linestream.eof())
    {
        cout<<"Error: too few arguments"<<endl;
        return false;
    }
    // Checks if an integer is not entered for the node number
    else if(linestream.fail())
    {
        cout<<"Error: invalid argument"<<endl;
        return false;

    }
    else if(linestream.peek()!= ' ' && linestream.peek()!= '\t')
    {
        cout<<"Error: invalid argument"<<endl;
        return false;
    }
    // Checks if the node number is within the range required
    else if(node1 > MAX_NODE_NUMBER)
    {
        cout<<"Error: node "<<node1<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
        return false;
    }
    else if(node1 <0)
    {
        cout<<"Error: node "<<node1<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
        return false;
    }


    linestream>>node2;


    if(linestream.fail() && linestream.eof())
    {
        cout<<"Error: invalid argument"<<endl;
        return false;
    }

    else if(!linestream.eof())
    {
        if(linestream.peek() != ' ' && linestream.peek() != '\t')
        {
            cout<<"Error: invalid argument"<<endl;
            return false;
        }
        else
        {
            // Checks if the two nodes have the same value
            if(node1 == node2)
            {
                cout<<"Error: both terminals of resistor connect to node "<<node1<<endl;
                return false;
            }
            else
            {
                string temp;
                // Checks to make sure there are not more than enough arguments
                if(linestream>>temp)
                {
                    cout<<"Error: too many arguments"<<endl;
                    return false;
                }
            }
        }
    }
// Checks if the node is out of range
    else if(node2 > MAX_NODE_NUMBER)
    {
        cout<<"Error: node "<<node2<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
        return false;
    }
    else if(node2 <0)
    {
        cout<<"Error: node "<<node2<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
        return false;
    }
    else if(node1 == node2)
    {
        cout<<"Error: both terminals of resistor connect to node "<<node1<<endl;
        return false;
    }

    // Following three lines set the output of double to show two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
    return true;
}

bool Parser::modifyR(string line)
{
    //checks for the arguments, when command is modifyR
    numberOfWords = countWords(line);
    if(numberOfWords == 0)
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }

    stringstream linestream(line);
    linestream>>command;

    linestream>>name;
    if(name == "all")
    {

        cout<<"Error: resistor name cannot be the keyword \"all\"" <<endl;
        return false;
    }

    else if(linestream.eof())
    {
        cout<<"Error: too few arguments"<<endl;

        return false;
    }
    linestream>>resistance;


    if(resistance< 0)
    {
        cout<<"Error: negative resistance"<<endl;
        return false;
    }

    else if(linestream.fail())
    {

        cout<<"Error: invalid argument"<<endl;
        return false;
    }
    else if(!linestream.eof())
    {
        if(linestream.peek() != ' ' && linestream.peek() != '\t')
        {
            cout<<"Error: invalid argument"<<endl;
            return false;
        }
        else
        {
            string temp;
            if(linestream>>temp)
            {
                cout<<"Error: too many arguments"<<endl;
                return false;
            }
        }

    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Modified: resistor "<<name<<" to "<<resistance<<" Ohms"<<endl;
    return true;
}

bool Parser::printR(string line)
{
    //checks for the arguments, when command is printR
    numberOfWords = countWords(line);
    if(numberOfWords == 0)
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }
    else if(numberOfWords > PRINT_WORD_PER_LINE)
    {
        cout<<"Error: too many arguments"<<endl;
        return false;
    }
    else if(numberOfWords < PRINT_WORD_PER_LINE)
    {
        cout<<"Error: too few arguments"<<endl;
        return false;

    }
    stringstream linestream(line);
    linestream>>command;
    linestream>>name;

    if(linestream. fail())
    {
        return false;
    }

    else if(name=="all")
    {
        cout<<"Print: all resistors"<<endl;
        return true;
    }
    else
    {
        cout<<"Print: resistor "<<name<<endl;
        return true;
    }
}

bool Parser::deleteR(string line)
{
    //checks for the arguments, when command is deleteR
    numberOfWords = countWords(line);
    if(numberOfWords == 0)
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }

    else if(numberOfWords > PRINT_WORD_PER_LINE)
    {
        cout<<"Error: too many arguments"<<endl;
        return false;
    }
    else if(numberOfWords < PRINT_WORD_PER_LINE)
    {

        cout<<"Error: too few arguments"<<endl;
        return false;

    }
    stringstream linestream(line);
    linestream>>command;
    linestream>>name;

    if(linestream. fail())
    {
        return false;
    }

    else if(name=="all")
    {
        cout<<"Deleted: all resistors"<<endl;
        return true;
    }
    else
    {
        cout<<"Deleted: resistor "<<name<<endl;
        return true;
    }
}

bool Parser::printNode(string line)
{
    // Prints either "all" nodes or a specific one
    numberOfWords = countWords(line);
    if(numberOfWords == 0)
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }
    stringstream linestream(line);
    linestream>>command;
    linestream>>name;

    if(name== "all")
    {
        string waste;
        if(linestream>>waste)
        {
            cout<<"Error: too many arguments"<<endl;
            return false;
        }
        else
        {
            cout<<"Print: all nodes"<<endl;
            return true;
        }
    }
    else if(linestream.fail() && linestream.eof())
    {
        cout<<"Error: too few arguments"<<endl;
        return false;
    }
    else
    {
        // New stringstream to check if an integer has been entered
        stringstream checkForNumb(name);
        checkForNumb>>node1;
        if(checkForNumb.fail())
        {
            cout<<"Error: invalid argument"<<endl;
            return false;
        }
        else if(!checkForNumb.eof())
        {
            cout<<"Error: invalid argument"<<endl;
            return false;
        }
        else if(node1 > MAX_NODE_NUMBER )
        {
            cout<<"Error: node "<<node1<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
            return false;
        }
        else if(node1 < 0)
        {
            cout<<"Error: node "<<node1<<" is out of permitted range "<<"0-"<<MAX_NODE_NUMBER<<endl;
            return false;
        }
        else
        {
            string temp;
            if(linestream>>temp)
            {
                cout<<"Error: too many arguments"<<endl;
                return false;
            }
            else
            {
                cout<<"Print: node "<<node1<<endl;
                return true;

            }
        }
    }
}

int Parser::countWords(string line)
{
    // Count the number of words in a string
    string word;
    count =0;
    stringstream linestream(line);
    while(linestream>>word)
        count++;

    return count;
}

// Contains call to the object 'input' of class Parser
int main()
{
    Parser obj;
    // Stores entire input line
    string line;
    cout<<"> ";
    // Get a line from the input stream
    getline(cin,line);
    // Runs until an End of File (EOF) command is entered
    while(!cin.eof())
    {
        obj.input(line);
        cout<<"> ";
        getline(cin,line);

    }
    return 0;
}
