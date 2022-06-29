#include<iostream>
#include"Clothes.h"
#include"Dress.h"
#include"Suit.h"
#include"Pants.h"
#include"Suitcase.h"
int main()
{
    Clothes* a = new Dress("Red", "M", 200, 1.5);
    Clothes* b = new Suit("Black", "XXL", 150);
    Clothes* c = new Pants("Red", "XS", 780, 1.5);

    std::list<Clothes*> listOfClothes;
    listOfClothes.push_back(a);
    listOfClothes.push_back(b);
    listOfClothes.push_back(c);

    Suitcase abc("Grean","Aleks","Sheinowo", 13246578, listOfClothes);

    delete a;
    delete b;
    delete c;

    return 0;
}