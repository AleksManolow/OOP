#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include"TaskManager.h"

class CommandReader
{
private:
    std::vector<String> commandsSet;
	String command;
public:
    CommandReader();
    void start();
};

#endif