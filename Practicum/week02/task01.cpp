#include<iostream>
#include<cstring>
const int N = 1024;
enum SaberType
{
    SINGLEBLADED = 1,
    DOUBLE_BLADED,
    CROSSGUARD
};
struct LightSaber
{
    char* color;
    SaberType type;
};
struct Jedi
{
    char* name;
    unsigned int age;
    int power;
    LightSaber lightSaber;
    double healthPoints;

};
void initializeSaber(Jedi& jedi)
{
    char input[N];
    std::cout << "Input color: ";
    std::cin >> input;
    jedi.lightSaber.color = new char [strlen(input) + 1];
    strcpy(jedi.lightSaber.color, input);

    std::cout << "Enter type: \n";
    std::cout << "1 - SINGLEBLADED\n";
    std::cout << "2 - DOUBLE_BLADED\n";
    std::cout << "3 - CROSSGUARD\n";
    int choise;
    std::cin >> choise;

    switch (choise)
    {
    case 1:
        jedi.lightSaber.type = SaberType::SINGLEBLADED;
        break;
    case 2:
        jedi.lightSaber.type = SaberType::DOUBLE_BLADED;
        break;
    case 3:
        jedi.lightSaber.type = SaberType::CROSSGUARD;
        break;
    default:
        throw "No supported blade type!";
    }
}
void initializeJedi(Jedi& jedi)
{
    char input[N];
    std::cout << "Input name: ";
    std::cin >> input;
    jedi.name = new char [strlen(input) + 1];
    strcpy(jedi.name, input);

    std::cout <<"Enter age: ";
    std::cin >> jedi.age;

    std::cout << "Enter power: ";
    std::cin >> jedi.power;

    initializeSaber(jedi);

    std::cout << "Enter health points: ";
    std::cin >> jedi.healthPoints;
}
void printSaber(LightSaber& saber)
{
    std::cout << "Saber color: " << saber.color<< std::endl;
    const char* types[] = {"SINGLEBLADED",
                            "DOUBLE_BLADED",
                            "CROSSGUARD"};
    std::cout << "Saber type: " << types[saber.type - 1] << std::endl;
}
void printJedi(Jedi& jedi)
{
    std::cout << "Name: " << jedi.name<< std::endl;
    std::cout << "Age: " << jedi.age<< std::endl;
    std::cout << "Power: " << jedi.power << std::endl;
    printSaber(jedi.lightSaber);
    std::cout << "HP: " << jedi.healthPoints<< std::endl;
}
void killJedi(Jedi& jedi)
{
    delete[] jedi.name;
    delete[] jedi.lightSaber.color;

}
void battle(Jedi& jedi1, Jedi& jedi2)
{
    std::cout << "Epic battle (" << jedi1.name << " vs " << jedi2.name << ")" <<std::endl;
    double jedi1Dmg = (jedi1.power * jedi1.lightSaber.type * strlen(jedi1.lightSaber.color)) / jedi1.age;
    double jedi2Dmg = (jedi2.power * jedi2.lightSaber.type * strlen(jedi2.lightSaber.color)) / jedi2.age;
    while (jedi1.healthPoints > 0 && jedi2.healthPoints > 0)
    {
        jedi1.healthPoints = jedi1.healthPoints - jedi2Dmg > 0 ? jedi1.healthPoints - jedi2Dmg : 0;
        jedi2.healthPoints = jedi2.healthPoints - jedi1Dmg > 0 ? jedi2.healthPoints - jedi1Dmg : 0;
    }
    if (jedi1.healthPoints > 0 || jedi2.healthPoints > 0)
    {
        std::cout << "---------Winner---------" << std::endl;
        if (jedi1.healthPoints > 0)
        {
            printJedi(jedi1);
        }
        else
        {
            printJedi(jedi2);
        }


        std::cout << "------------------------" << std::endl;
    }
    else
    {
        std::cout << "No winner! "<< std::endl;
    }
    
    
}
int main()
{
    Jedi jedi1, jedi2;
    initializeJedi(jedi1);
    printJedi(jedi1);

    initializeJedi(jedi2);
    printJedi(jedi2);

    battle(jedi1, jedi2);

    killJedi(jedi1);
    killJedi(jedi2);
    return 0;
}