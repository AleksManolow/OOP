#ifndef __IMPROVEDBAG_H
#define __IMPROVEDBAG_H
#include"Bag.h"
#include<cstring>
template<typename T>
class ImprovedBag:public Bag<T>
{
private:
    char* nameManufacturer;
public:
    ImprovedBag();
    ImprovedBag(char* );
    ImprovedBag(const ImprovedBag& other);
    ImprovedBag& operator=(const ImprovedBag& other);
    ~ImprovedBag();

    char* allocateMemory(char* );
    void deleteMemory(char* );

    void Insert(T , int );
};
template<typename T>
char* ImprovedBag<T>::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
template<typename T>
void ImprovedBag<T>::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
template<typename T>
ImprovedBag<T>::ImprovedBag():Bag<T>()
{
    nameManufacturer = NULL;
}
template<typename T>
ImprovedBag<T>::ImprovedBag(char* _nameManufacturer):Bag<T>()
{
    nameManufacturer = allocateMemory(_nameManufacturer);
}
template<typename T>
ImprovedBag<T>::ImprovedBag(const ImprovedBag& other):Bag<T>(other)
{
    nameManufacturer = allocateMemory(other.nameManufacturer);
}
template<typename T>
ImprovedBag<T>& ImprovedBag<T>::operator=(const ImprovedBag& other)
{
    if (this != &other)
    {
        Bag<T>::operator=(other);
        deleteMemory(nameManufacturer);

        nameManufacturer = allocateMemory(other.nameManufacturer);
    }
    return *this;
}
template<typename T>
ImprovedBag<T>::~ImprovedBag()
{
    deleteMemory(nameManufacturer);
}
template<typename T>
void ImprovedBag<T>::Insert(T element, int index)
{
    if (index >= Bag<T>::size)
    {
        Bag<T>::Add(element);
    }
    else
    {
        if (Bag<T>::size == Bag<T>::capacity)
        {
            void resize();
        }
        ;
        for (size_t i = Bag<T>::size; i > index; i--)
        {
            Bag<T>::elements[i] = Bag<T>::elements[i - 1];
        }
        Bag<T>::elements[index] = element;
        Bag<T>::size++;
    }
}
#endif