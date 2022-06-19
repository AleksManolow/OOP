#ifndef __GENERATEMAP_h
#define __GENERATEMAP_h
#include<iostream>
#include<vector>
#include"Treasure.h"
#include"Armor.h"
#include"Weapon.h"
#include"Spell.h"
#include"Monster.h"

class GenerateMap
{
private:
    int rows;
    int columns;
    char** matrix;
    std::vector<Monster > monsters;
    std::vector<Treasure* > treasures;

    char** allocateMemory(int r, int c, char** rhs);
    void deleteMemory();
public:
    GenerateMap();
    GenerateMap(int _rows, int _columns, char** _GenerateMap);
    GenerateMap(const GenerateMap& );
    GenerateMap& operator=(const GenerateMap& );
    ~GenerateMap();

    int getRows(){   return rows;    }
    int getColumns(){   return columns;    }
	char** getMatrix() const;
	char getAt(size_t, size_t) const;
    Monster getAtMonster(size_t ) const;
    Treasure* getAtTreasure(size_t ) const;

    void setMatrix(char** );
	void setAt(size_t , size_t , char );

    void print() const;

    void increasePerformanceOfMonster(int level);

    //friend std::istream& operator>>(std::istream& is, GenerateMap& );
    //friend std::ostream& operator<<(std::ostream& os, const GenerateMap& );

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out) const;
};



#endif