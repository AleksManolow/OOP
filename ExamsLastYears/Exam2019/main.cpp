#include<iostream>
#include"SurfAndTurf.h"
int main()
{
    char** ingredientsNames = new char*[3];
    char* a = "tomatoes" ;
    char* b = "cucumber";
    char* c = "basil";
    ingredientsNames[0] = new char[strlen(a) + 1];
    strcpy(ingredientsNames[0], a);
    ingredientsNames[1] = new char[strlen(b) + 1];
    strcpy(ingredientsNames[1], b);
    ingredientsNames[2] = new char[strlen(c) + 1];
    strcpy(ingredientsNames[2], c);

    SurfAndTurf surfTruft(3,ingredientsNames,90,"chicken", "fish");
    surfTruft.print();

    for (size_t i = 0; i < 3; i++)
    {
        delete[] ingredientsNames[i];
    }
    delete[] ingredientsNames;
    
    return 0;
}