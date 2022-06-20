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

    std::fstream listOfProperties(fileNameMap.returnChar(), std::ios::in | std::ios::out);
    map.loadFromStream(listOfProperties);
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
bool TaskManager::battleWithMonsterIsVictory(int numberOfMonster)
{
    Monster monsterInBattle = map.getAtMonster(numberOfMonster);
    double heroHealth = hero->getHealth();

    while(monsterInBattle.getHealth() > 0 && hero->getHealth() > 0)
    {
        String choise;
        std::cout << "Choose whether to hit the monster with a \"Power attack\" or by \"Casting a spell\"!" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choise;
        if (choise == "Power attack")
        {

            double demageWeapon = (hero->getWeapon().getPercent() / 100) * hero->getForse();
            double demageBeforeArmor = hero->getForse() + demageWeapon;
            double demegeAfterArmor = demageBeforeArmor - ((monsterInBattle.getArrmor().getPercent() / 100) * demageBeforeArmor); 
            monsterInBattle.setHealth(monsterInBattle.getHealth() - demegeAfterArmor);
        }
        else if (choise == "Casting a spell")
        {
            double demageSpell = (hero->getSpell().getPercent() / 100) * hero->getForse();
            double demageBeforeArmor = hero->getForse() + demageSpell;
            double demegeAfterArmor = demageBeforeArmor - ((monsterInBattle.getArrmor().getPercent() / 100) * demageBeforeArmor); 
            monsterInBattle.setHealth(monsterInBattle.getHealth() - demegeAfterArmor);
        }
        else
        {
            std::cout << "Envalid choice" << std::endl;
        }
        if (monsterInBattle.getHealth() < 0)
        {
            break;
        }
        
        double demageMonsterAfterArmor = monsterInBattle.getForse() - ((hero->getArrmor().getPercent() / 100) * monsterInBattle.getForse());
        hero->setHealth(hero->getHealth() - demageMonsterAfterArmor);

        std::cout << "INDICATORS OF THE HEROES IN BATTLE" << std::endl;
        hero->print();
        monsterInBattle.print();
    }

    if (hero->getHealth() > 0)
    {
        hero->setHealth(hero->getHealth() + ((heroHealth - hero->getHealth()) / 2));
        return true;
    }
    else
    {
        return false;
    }
}
void TaskManager::playGame(int x, int y)
{
    if (thisMovementIsNotPossible(x, y))
    {
        std::cout << "This movement is not valid!" << std::endl;
    }
    else
    {
        static int countM = 0;
        static int countT = 0;

        if (map.getAt(x, y) == '.')
        {
            map.setAt(coordinates.getX(), coordinates.getY(), '.');
            map.setAt(x, y, 'H');
            coordinates.setX(x);
            coordinates.setY(y);
        }
        if (map.getAt(x, y) == 'M')
        {
            
            if (battleWithMonsterIsVictory(countM))
            {
                std::cout << "You successfully defeated this monster!" << std::endl;
                countM++;
                map.setAt(coordinates.getX(), coordinates.getY(), '.');
                map.setAt(x, y, 'H');
                coordinates.setX(x);
                coordinates.setY(y);
            }
            else
            {
                std::cout << "You lost the battle with the monster!" << std::endl;
            }
        }
        
        if (map.getAt(x, y) == 'T')
        {

            std::cout << "You came across a treasure. Will he keep it?" << std::endl;
            map.getAtTreasure(countT)->print();
            String choice;
            std::cout << "Enter \"Yes\" ot \"No\": ";
            std::cin >> choice;
            if (choice == "Yes")
            {
                if (typeid(*map.getAtTreasure(countT)) == typeid(Armor))
                {
                    hero->setArrmor(map.getAtTreasure(countT));
                    std::cout << "The treasure was taken successfully!" << std::endl;
                }
                else if (typeid(*map.getAtTreasure(countT)) == typeid(Weapon))
                {
                    hero->setWeapon(map.getAtTreasure(countT));
                    std::cout << "The treasure was taken successfully!" << std::endl;
                }
                else if (typeid(*map.getAtTreasure(countT)) == typeid(Spell))
                {
                    hero->setSpell(map.getAtTreasure(countT));
                    std::cout << "The treasure was taken successfully!" << std::endl;
                } 
                else  
                {
                    std::cout << "Unsuccessful retrieval of the treasure!" << std::endl;
                }
                countT++;
                map.setAt(coordinates.getX(), coordinates.getY(), '.');
                map.setAt(x, y, 'H');
                coordinates.setX(x);
                coordinates.setY(y);
            }
            else if(choice == "No")
            {
                std::cout << "You did not take the treasure!" << std::endl;
                countT++;
                map.setAt(coordinates.getX(), coordinates.getY(), '.');
                map.setAt(x, y, 'H');
                coordinates.setX(x);
                coordinates.setY(y);
            }
            else
            {
                std::cout << "Invalid choice!" << std::endl;
            }
        }


        if (x == (map.getRows() - 1) && y == (map.getColumns() - 1))
        {
            std::cout << "Congratulations you successfully passed to the next level!" << std::endl;
            std::cout << "You get 30 points! Choose how to distribute them." << std::endl;

            double pointDistribution = 0;
            std::cout << "Enter by how many points to increase the force: ";
            std::cin >> pointDistribution;
            hero->setForse(hero->getForse() + pointDistribution);
            std::cout << "Enter by how many points to increase the mana: ";
            std::cin >> pointDistribution;
            hero->setMana(hero->getMana() + pointDistribution);
            std::cout << "Enter by how many points to increase the health: ";
            std::cin >> pointDistribution;
            hero->setHealth(hero->getHealth() + pointDistribution);
            
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

            std::fstream listOfProperties(fileNameMap.returnChar(), std::ios::in | std::ios::out);
            map.loadFromStream(listOfProperties);

            listOfProperties.close();
            
            map.increasePerformanceOfMonster(level);
            map.setAt(coordinates.getX(), coordinates.getY(), 'H');

            countM = 0;
            countT = 0;
        }
        
    }
}
TaskManager::TaskManager()
{
    hero = NULL;
    std::fstream listOfProperties("Level1.txt", std::ios::in | std::ios::out);
    level = 1;
    map.loadFromStream(listOfProperties);

    isReadFromOpenFile = false;
    isCloseFile = true;


    isSavedInFile = true;
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
        }
        map.setAt(coordinates.getX(), coordinates.getY(), 'H');
        isCloseFile = true;
        isSavedInFile = false;
    }
    else
    {
        std::cout << "Failed to open the file!" << std::endl;
    }
}
void TaskManager::up()
{
    playGame(coordinates.getX() - 1, coordinates.getY());
}
void TaskManager::down()
{
    playGame(coordinates.getX() + 1, coordinates.getY());
}
void TaskManager::left()
{
    playGame(coordinates.getX(), coordinates.getY() - 1);
}
void TaskManager::right()
{
    playGame(coordinates.getX(), coordinates.getY() + 1);
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
    std::cout << "The following commands are supported :" << std::endl;
    std::cout << "open      opens a found file or creates a file" << std::endl;
    std::cout << "up        \"up\" to navigate the map" << std::endl;
    std::cout << "down		\"down\" to navigate the map" << std::endl;
    std::cout << "left	    \"left\" to navigate the map" << std::endl;
    std::cout << "right	    \"right\" to navigate the map" << std::endl;
    std::cout << "help		 prints this information" << std::endl;
    std::cout << "save       saves to file" << std::endl;
    std::cout << "save as    saves to a new file" << std::endl;
    std::cout << "close      closes the file if it is not closed" << std::endl;
    std::cout << "exit		 exiting the program" << std::endl;  
}
