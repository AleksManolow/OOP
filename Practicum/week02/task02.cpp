#include<iostream>
#include<cstring>
const int N = 1024;
enum Tastes
{
    SOUR, 
    SWEET, 
    BITTER, 
    SPICY
};
struct Vegetable
{
    char* name;
    Tastes taste;
    double weight;

    void create()
    {
        char input[N];
        std::cout << "Enter vegetable name: ";
        std::cin >> input;

        name = new char [strlen(input) + 1];
        strcpy(name, input);

        std::cout << "Enter vegetable taste: \n";
        std::cout << "0 - SOUR\n";
        std::cout << "1 - SWEET\n";
        std::cout << "2 - BITTER\n";
        std::cout << "3 - PICY\n";
        int choise;
        std::cin >> choise;
        switch (choise)
        {
        case 0:
            taste = Tastes::SOUR;
            break;
        case 1:
            taste = Tastes::SWEET;
            break;
        case 2:
            taste = Tastes::BITTER;
            break;
        case 3:
            taste = Tastes::SPICY;
            break;
        default:
            throw "No type!";
        }
        std::cout << "Enter vegetable weight: ";
        std::cin >> weight;
    }
};
struct Dressing
{
    char* name;
    Tastes taste;
    double quantity;
    char** alergens;

    void create(int& numberOfAlergens)
    {
        char input[N];
        std::cout << "Enter dressing name : ";
        std::cin >> input;

        name = new char [strlen(input) + 1];
        strcpy(name, input);

        std::cout << "Enter dressing taste: \n";
        std::cout << "0 - SOUR\n";
        std::cout << "1 - SWEET\n";
        std::cout << "2 - BITTER\n";
        std::cout << "3 - SPICY\n";
        int choise;
        std::cin >> choise;
        switch (choise)
        {
        case 0:
            taste = Tastes::SOUR;
            break;
        case 1:
            taste = Tastes::SWEET;
            break;
        case 2:
            taste = Tastes::BITTER;
            break;
        case 3:
            taste = Tastes::SPICY;
            break;
        default:
            throw "No type!";
        }
        std::cout << "Enter dressing quantity: ";
        std::cin >> quantity;

        std::cout << "Enter size alergens: ";
        std::cin >> numberOfAlergens;
        alergens = new char* [numberOfAlergens];
        for (int i = 0; i < numberOfAlergens; i++)
        {
            char input[N];
            std::cout << "Enter aregen: ";
            std::cin >> input;

            alergens[i] = new char [strlen(input) + 1];
            strcpy(alergens[i], input);
        }
    }
};
struct Salad
{
    int numberOfVegetable;
    Vegetable* vegetables;
    int numberOfDressings;
    Dressing* dressings;

    void create(int arrNumberOfAl[N])
    {
        std::cout << "Enter number of vegetables: ";
        std:: cin >> numberOfVegetable;

        vegetables = new Vegetable[numberOfVegetable];
        for (int i = 0; i < numberOfVegetable; i++)
        {
            vegetables[i].create();
        }

        std::cout << "Enter number of dressings: ";
        std:: cin >> numberOfDressings;

        dressings = new Dressing[numberOfDressings];
        for (int i = 0; i < numberOfDressings; i++)
        {
            dressings[i].create(arrNumberOfAl[i]);

        }
    }
    double getWeight()
    {
        double sumWeight = 0;
        for (int i = 0; i < numberOfVegetable; i++)
        {
            sumWeight = sumWeight + vegetables[i].weight;
        }
        double sumQuantity = 0;
        for (int i = 0; i < numberOfDressings; i++)
        {
            sumQuantity = sumQuantity + dressings[i].quantity;
        }
        return sumQuantity + sumWeight;
    }
    Tastes getTaste()
    {
        int arr[N] {0, 0, 0, 0};
        for (int i = 0; i < numberOfVegetable; i++)
        {
            arr[vegetables[i].taste]++;
        }
        for (int i = 0; i < numberOfDressings; i++)
        {
            arr[dressings[i].taste]++;
        }

        int maxNumberInIndex = 0;
        for (int i = 1; i < 4; i++)
        {
            if (arr[i] > arr[maxNumberInIndex])
            {
                maxNumberInIndex = i;
            }
        }

        Tastes mostCommonTaste;
        switch (maxNumberInIndex)
        {
        case 0:
            mostCommonTaste = Tastes::SOUR;
            break;
        case 1:
            mostCommonTaste = Tastes::SWEET;
            break;
        case 2:
            mostCommonTaste = Tastes::BITTER;
            break;
        case 3:
            mostCommonTaste = Tastes::SPICY;
            break;
        default:
            throw "No type!";
        }

        return mostCommonTaste;
    }
    void printAlergens(int arrNumberOfAl[])
    {
        std::cout << "Alergens: ";
        for (int i = 0; i < numberOfDressings; i++)
        {
            for (int j = 0; j < arrNumberOfAl[i]; j++)
            {
                std::cout << dressings[i].alergens[j] << " ";
            }
        }
        std::cout << std::endl;
    }
};
void deleteMemory(Salad& shopska, int arrNumberOfAl[N])
{
    for (int i = 0; i < shopska.numberOfVegetable; i++)
    {
        delete[] shopska.vegetables[i].name;
    }
    delete[] shopska.vegetables;

    for (int i = 0; i < shopska.numberOfDressings; i++)
    {
        delete[] shopska.dressings[i].name;
        for (int j = 0; j < arrNumberOfAl[i]; j++)
        {
            delete[] shopska.dressings[i].alergens[j];
        }
        delete[] shopska.dressings[i].alergens;
        
    }
    delete[] shopska.dressings;
    
}
int main()
{
    int arrNumberOfAl[N];
    Salad shopska;
    shopska.create(arrNumberOfAl);

    std::cout << "------------ Shopska ----------------" << std::endl;
    std::cout << "Contents: ";
    for (int i = 0; i < shopska.numberOfVegetable; i++)
    {
        std::cout << shopska.vegetables[i].name << ", "; 
    }
    for (int i = 0; i < shopska.numberOfDressings; i++)
    {
        if (i + 1 == shopska.numberOfDressings)
        {
            std::cout << shopska.dressings[i].name << "." << std::endl; 
        }
        else
        {
            std::cout << shopska.dressings[i].name << ", "; 
        }
    }
    std::cout << "Quantity: " << shopska.getWeight()<< std::endl;
    
    std::cout << "Description: ";
    switch (shopska.getTaste())
    {
    case 0:
        std::cout << "SOUR" << std::endl;
        break;
    case 1:
        std::cout << "SWEET" << std::endl;
        break;
    case 2:
        std::cout << "BITTER" << std::endl;
        break;
    case 3:
        std::cout << "SPICY" << std::endl;
        break;
    default:
        throw "No type!";
    }

    shopska.printAlergens(arrNumberOfAl);
    std::cout << "------------ Bon appetit! -----------"<< std::endl;

    deleteMemory(shopska, arrNumberOfAl);
    return 0;
}