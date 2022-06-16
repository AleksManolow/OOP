#ifndef __TASKMANAGER_H
#define __TASKMANAGER_H

#include<iostream>
#include<fstream>
#include<vector>
#include"Hero.h"
#include"Mag.h"
#include"Person.h"
#include"Warrior.h"
#include"Treasure.h"
#include"Armor.h"
#include"Weapon.h"
#include"Spell.h"
#include"Monster.h"
#include"GenerateMap.h"
#include"CommandReader.h"
#include"String.h"
#include"CoordinatesHero.h"

class TaskManager
{
private:
    std::fstream file;
    String nameFile;
    Hero* hero;
    CoordinatesHero coordinates;
    int level;
    GenerateMap map;

    //flags whether there is an open and close file
    bool isReadFromOpenFile;
    bool isCloseFile;

    //indicates whether the game is saved in a file
    bool isSavedInFile;

    //HELP FUNCTIONS

    //streaming read and write features
    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out) const;

    //on-screen printing features
    

    //movement on the playing field
    bool thisMovementIsNotPossible(int x, int y);

    //playGame
    void playGame(int x, int y);
public:
    TaskManager();
    ~TaskManager();
    //command functions
    void openFile();
    void up();
    void down();
    void left();
    void right();
    void saveAsFile();
    void saveFile();
    void closeFile();
    void help();
    void exit();



    void printHeroAndMap();
};

#endif
