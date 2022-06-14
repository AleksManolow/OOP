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
#include"Map.h"
#include"CommandReader.h"
#include"String.h"

class TaskManager
{
private:
    String nameFile;
    Hero* hero;
    int level;
    Map map;

public:
    TaskManager();
    ~TaskManager();
};

#endif
