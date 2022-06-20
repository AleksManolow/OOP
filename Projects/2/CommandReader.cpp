#include"CommandReader.h"

CommandReader::CommandReader()
{
	commandsSet.push_back("open");
	commandsSet.push_back("up");
    commandsSet.push_back("down");
	commandsSet.push_back("left");
    commandsSet.push_back("right");
	commandsSet.push_back("save");
	commandsSet.push_back("save as");
	commandsSet.push_back("close");
    commandsSet.push_back("help");
	commandsSet.push_back("exit");
}
void CommandReader::start()
{
    TaskManager manager;
    do
    {
        bool isCommand = false;
        std::cout << "Enter command: ";
        std::cin >> command;

        size_t i = 0;
		for (i ; i < commandsSet.size(); i++)
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
        else if (!manager.getIsReadFromOpenFile() && command != "open")
        {
            std::cout << "First open a file with command open!" << std::endl;
            continue;
        }
		else 
        {
			switch (i)
			{
			case 0: manager.openFile(); break;
			case 1: manager.up(); break;
			case 2: manager.down(); break;
			case 3: manager.left(); break;
			case 4: manager.right(); break;
			case 5: manager.saveFile(); break;
            case 6: manager.saveAsFile(); break;
            case 7: manager.closeFile(); break;
			case 8: manager.help(); break;
			default:
				break;
			}

            if (command == "up" || command == "left" || command == "down" || command == "right" || command == "open")
            {
                manager.printHeroAndMap();
            }
            
		}

        if (command == "exit" && !manager.getIsSavedInFile())
        {
            String choice;
            std::cout << "Are you sure you want to close the game without saving it!" << std::endl;
            std::cout << "Enter \"Yes\" or \"No\": ";
            std::cin >> choice;
            if (choice == "Yes")
            {
                std::cout << "The game is not saved!" << std::endl;
            }
            else if (choice == "No")
            {
                std::cout << "Enter the \"save\" or \"save as\" command to save the game!" << std::endl; 
                command = "";
            }
            else
            {
                std::cout << "Invalid choice!" << std::endl;
                command = "";
            }
            
        }
        if (command == "exit" && !manager.getIsCloseFile())
        {
            std::cout << "Has an open file. Please close it first with the command close!" << std::endl;
            command = "";
        }
        
        
    } while (!(command == "exit"));
    std::cout << "Exiting the program..." << std::endl;
    
}