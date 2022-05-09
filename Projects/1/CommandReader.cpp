#include"CommandReader.h"

CommandReader::CommandReader()
{
	commandsSet.pushBack("sort");
	commandsSet.pushBack("find");
    commandsSet.pushBack("add");
	commandsSet.pushBack("remove");
    commandsSet.pushBack("output");
    commandsSet.pushBack("help");
	commandsSet.pushBack("exit");
}

void CommandReader::print()
{
	for (size_t i = 0; i < commandsSet.getSize(); i++)
	{
		std::cout << commandsSet[i] << " ";
	}
}

void CommandReader::start()
{
    TaskAdministrator manager;
    do
    {
        bool isCommand = false;
        std::cout << "Enter command: ";
        std::cin >> command;

        size_t i = 0;
		for (i ; i < commandsSet.getSize(); i++)
		{
			if (command == commandsSet[i])
			{
				isCommand = true;
				break;
			}
		}

        if (!isCommand)
		{
			std::cout << "Invalid command! Type help for more info." << std::endl;
		}
		else 
        {
			switch (i)
			{
			case 0: manager.sortB(); break;
			case 1: manager.findB(); break;
			case 2: manager.addB(); break;
			case 3: manager.removeB(); break;
			case 4: manager.outputB(); break;
			case 5: manager.helpB(); break;
			default:
				break;
			}
		}
    } while (!(command == "exit"));
    std::cout << "Exiting the program..." << std::endl;
    
}