#ifndef __COMPUTER_H
#define __COMPUTER_H

class Computer
{
private:
    char* brand;
    char* processor;
    char* video;
    char* hardDrive;
    double price;
    unsigned quantity;  

    char* allocateMemory(char*);
    void deleteMemory(char*);

public:
    Computer();
    Computer(char* , char* , char* , char* , double , unsigned );
    Computer(const Computer&);
    ~Computer();
    Computer &operator=(Computer const &otherComputer);
    void print() const;
    void create();
};

#endif