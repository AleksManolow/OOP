#include<iostream>
#include"House.h"
House theMostSpaciousHouse(House* houses, int size)
{
    House houseMaxAverageFloorHeight = houses[0];
    for (size_t i = 1; i < size; i++)
    {
        if (houses[i].averageFloorHeight() > houseMaxAverageFloorHeight.averageFloorHeight())
        {
            houseMaxAverageFloorHeight = houses[i];
        }
    }
    return houseMaxAverageFloorHeight;
}
int main()
{
    int size = 0;
    std::cout << "Enter number of houses:" << std::endl;
    std::cin >> size;

    House* houses = new House[size];
    for (size_t i = 0; i < size; i++)
    {
        houses[i].loadFromStream(std::cin);
    }

    theMostSpaciousHouse(houses, size).writeToStream(std::cout);

    delete[] houses;

    return 0;
}

