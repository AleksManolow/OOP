#ifndef __NEWSPAPER_H
#define __NEWSPAPER_H
#include"PrintedEdition.h"
class Newspaper:public PrintedEdition
{
private:
    int edNum;
public:
    Newspaper();
    Newspaper(char* _name, int _volume, int _edNum);
    Newspaper(const Newspaper& );
    Newspaper& operator=(const Newspaper& );
    ~Newspaper();

    friend std::ostream& operator<<(std::ostream& os, const Newspaper& printedEdition);
};

#endif