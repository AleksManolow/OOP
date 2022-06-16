#include"TaskManager.h"
void TaskManager::loadFromStream(std::istream& in)
{
    String tempHero;
    in >> tempHero;
    if (tempHero == "Mag")
    {
        hero = new Mag();
        hero->loadFromStream(in);
    }
    else if (tempHero == "Person")
    {
        hero = new Person();
        hero->loadFromStream(in);
    }
    else if (tempHero == "Warrior")
    {
        hero = new Warrior();
        hero->loadFromStream(in);
    }
    coordinates.loadFromStream(in);
    in >> level;
    String fileNameMap;
    switch (level)
    {
    case 1:
        fileNameMap = "Level1.txt";
        break;
    case 2:
        fileNameMap = "Level2.txt";
        break;
    case 3:
        fileNameMap = "Level3.txt";
        break;
    case 4:
        fileNameMap = "Level4.txt";
        break;
    }
    GenerateMap tempMap;
    std::fstream listOfProperties(fileNameMap.returnChar(), std::ios::in | std::ios::out);
    listOfProperties >> tempMap;
    map = tempMap;
}
void TaskManager::writeToStream(std::ostream& out) const
{
    hero->writeToStream(out);
    coordinates.writeToStream(out);
    out << level << '\n';
}
void TaskManager::printHeroAndMap()
{
    hero->print();
    map.print();
}
bool TaskManager::thisMovementIsNotPossible(int x, int y)
{
    if (map.getAt(x, y) == '#' || x < 0 || y < 0 || x >= map.getRows() || y >= map.getColumns())
    {
        return true;
    }
    return false;
}
void TaskManager::playGame(int x, int y)
{
    if (thisMovementIsNotPossible(x, y))
    {
        std::cout << "This movement is not valid!" << std::endl;
    }
    else
    {
        ////




        if (x == map.getRows() && y == map.getColumns())
        {
            std::cout << "Congratulations you successfully passed to the next level!" << std::endl;
            std::cout << "You get 30 points! Choose how to distribute them." << std::endl;

            double pointDistribution = 0;
            std::cout << "Enter by how many points to increase the force: ";
            std::cin >> pointDistribution;
            std::cout << "Enter by how many points to increase the mana: ";
            std::cin >> pointDistribution;
            std::cout << "Enter by how many points to increase the health: ";
            std::cin >> pointDistribution;

            coordinates.setX(0);
            coordinates.setY(0);

            level++;

            String fileNameMap;
            switch (level)
            {
            case 1:
                fileNameMap = "Level1.txt";
                break;
            case 2:
                fileNameMap = "Level2.txt";
                break;
            case 3:
                fileNameMap = "Level3.txt";
                break;
            case 4:
                fileNameMap = "Level4.txt";
                break;
            }
            GenerateMap tempMap;
            std::fstream listOfProperties(fileNameMap.returnChar(), std::ios::in | std::ios::out);
            listOfProperties >> tempMap;
            map = tempMap;
            listOfProperties.close();
            //!!!!!!!!!!!!!trqbwa da uwelicha na chudowishtata stoinostite!!!!!!!!!!!
        }
        
    }
}
TaskManager::TaskManager()
{
    hero = NULL;
    std::fstream listOfProperties("Level1.txt", std::ios::in | std::ios::out);
    level = 1;
    listOfProperties >> map;

    isReadFromOpenFile = false;
    isCloseFile = true;


    isSavedInFile = false;
}
TaskManager::~TaskManager()
{
    delete hero;
}
void TaskManager::openFile()
{
    std::cout << "Enter file name: ";
    std::cin >> nameFile;
    file.open(nameFile.returnChar(), std::ios::in | std::ios::out | std::ios::app);
    if (file.is_open())
    {   
        isReadFromOpenFile = true;
        isCloseFile = false;
        std::cout << "Successfully opened " << nameFile << std::endl;
        if (!(file.peek() == std::ifstream::traits_type::eof()))
        {
            loadFromStream(file);
            std::cout << "You run the game successfully!" << std::endl;
        }
        else
        {
            String kindOfHero;
            std::cout << "Choose your hero \"Warrior\", \"Mag\" or \"Person\": ";
            std::cin >> kindOfHero;
            bool isHero = false;
            if (kindOfHero == "Mag")
            {
                isHero = true;
                hero = new Mag();
            }
            else if (kindOfHero == "Person")
            {
                isHero = true;
                hero = new Person();
            }
            else if (kindOfHero == "Warrior")
            {
                isHero = true;
                hero = new Warrior();
            }
            else
            {
                std::cout << "Invalid hero name!" << std::endl;
            }

            if (isHero)
            {
                std::cout << "You run the game successfully!" << std::endl;
            }
            file.close();
            isCloseFile = true;
        }
    }
    else
    {
        std::cout << "Failed to open the file!" << std::endl;
    }
}
void TaskManager::up()
{
    playGame(coordinates.getX(), coordinates.getY() - 1);
}
void TaskManager::down()
{
    playGame(coordinates.getX(), coordinates.getY() + 1);
}
void TaskManager::left()
{
    playGame(coordinates.getX() - 1, coordinates.getY());
}
void TaskManager::right()
{
    playGame(coordinates.getX() + 1, coordinates.getY());
}
void TaskManager::saveAsFile()
{
    std::cout << "Enter file name: ";
    String newFileName;
    std::cin >> newFileName;
    std::fstream fileNew;
    fileNew.open(newFileName.returnChar(), std::ios::in | std::ios::out | std::ios::trunc);

    if (fileNew.is_open())
    {
        writeToStream(fileNew);
        std::cout << "Successfully saved another " << newFileName << std::endl;
        isSavedInFile = true;
        fileNew.close();
    }
    else 
    {
        std::cout << "Failed to open the file!" << std::endl;
        std::cout << "Try again." << std::endl;
    }
}
void TaskManager::saveFile()
{
    std::fstream fileNewForSave;
    fileNewForSave.open(nameFile.returnChar(), std::ios::in | std::ios::out | std::ios::trunc);

    if (fileNewForSave.is_open())
    {
        writeToStream(fileNewForSave);
        std::cout << "Successfully saved " << nameFile << std::endl;
        isSavedInFile = true;
        fileNewForSave.close();
    }
    else 
    {
        std::cout << "Failed to open the file!" << std::endl;
        std::cout << "Try again." << std::endl;
    }
}
void TaskManager::closeFile()
{
    if (file.is_open())
    {
        file.close();
        std::cout <<  "Successfully closed " << nameFile <<  std::endl;
        isCloseFile = true;
    }
}
void TaskManager::help()
{

}
