#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include"TaskAdministrator.h"

class CommandReader
{
private:
    Vector<String> commandsSet;
	String command;
public:
    CommandReader();

    void print();
    void start();
};

#endif