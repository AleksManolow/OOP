#ifndef __TASKMANAGER_H
#define __TASKMANAGER_H

#include<iostream>
#include<string>
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
    String nameFile;
    Hero* hero;
    CoordinatesHero coordinates;
    int level;
    GenerateMap GenerateMap;

public:
    TaskManager();
    void openFile();
    // void up();
    // void down();
    // void left();
    // void right();
    void start()
    void saveAsFile();
    void saveFile();
    void closeFile();
    void help();
};

#endif
