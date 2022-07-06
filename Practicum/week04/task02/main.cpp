#include<iostream>
#include<fstream>
#include <time.h>
#include "Developer.h"
int main()
{
    srand(time(NULL));

    Developer dev;

    try
    {
        dev.initialize();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        return 1;
    }

    std::ofstream outFile("developers.dev", std::ios::app);
    dev.writeToStream(outFile);

    outFile.close();

    dev.deleteDynamic();

    Developer dev1;
    std::ifstream inFile("developers.dev");
    try
    {
        dev1.loadFromStream(inFile);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        return 1;
    }
    dev1.print();

    inFile.close();

    dev1.deleteDynamic();


    return 0;
}