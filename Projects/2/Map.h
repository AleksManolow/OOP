#ifndef __MAP_H
#define __MAP_H
#include<iostream>

class Map
{
private:
    int rows;
    int columns;
    char** matrix;

    char** allocateMemory(int r, int c, char** rhs);
    void deleteMemory();
public:
    Map();
    Map(int _rows, int _columns, char** _map);
    Map(const Map& );
    Map& operator=(const Map& );
    ~Map();

	char** getMatrix() const;
	char getAt(size_t, size_t) const;

    void setMatrix(char** );
	void setAt(size_t , size_t , char );

    void print() const;

    friend std::istream& operator>>(std::istream& is, Map& );
    friend std::ostream& operator<<(std::ostream& os, const Map& );
};



#endif