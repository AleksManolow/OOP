#ifndef __BAG_H
#define __BAG_H
#include<iostream>

template<typename T>
class Bag
{
protected:
    static const std::size_t DEFAULET_INCREASE_CAPACITY = 2;
    static const std::size_t DEFAULET_CAPACITY = 2;

    std::size_t capacity;
    std::size_t size;
    T* elements;

    void deleteElements();
    void copy(T* );
    void resize();
public:
    Bag();
    Bag(const Bag& );
    Bag& operator=(const Bag& );
    ~Bag();

    void Add(T );
    T Get();
    void print();

    Bag operator+(const Bag& );
    bool operator==(const Bag& ) const;
};
template<typename T>
void Bag<T>::deleteElements()
{
    delete[] elements;
}
template<typename T>
void Bag<T>::copy(T* _elements)
{
    elements = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        elements[i] = _elements[i];
    }
}
template<typename T>
void Bag<T>::resize()
{
    T* newElemets = new T[capacity * DEFAULET_INCREASE_CAPACITY];
    for (size_t i = 0; i < size; i++)
    {
        newElemets[i] = elements[i];
    }
    deleteElements();
    elements = newElemets;
}
template<typename T>
Bag<T>::Bag()
{
    capacity = DEFAULET_CAPACITY;
    size = 0;
    elements = new T[capacity];
}
template<typename T>
Bag<T>::Bag(const Bag& other)
{
    capacity = other.capacity;
    size = other.size;
    copy(other.elements);
}
template<typename T>
Bag<T>& Bag<T>::operator=(const Bag& other)
{
    if (this != &other)
    {
        deleteElements();

        capacity = other.capacity;
        size = other.size;
        copy(other.elements);
    }
    return *this;
}
template<typename T>
Bag<T>::~Bag()
{
    deleteElements();
}
template<typename T>
void Bag<T>::Add(T element)
{
    if (size == capacity)
    {
        void resize();
    }
    elements[size++] = element;
}
template<typename T>
T Bag<T>::Get()
{
    T result = elements[0];
    for (int i = 0; i < size - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    size--;
    return result;
}
template<typename T>
void Bag<T>::print()
{
    std::cout << "Size: " << size << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << elements[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
Bag<T> Bag<T>::operator+(const Bag& other)
{
    Bag result(*this);
    for (size_t i = 0; i < other.size; i++)
    {
        result.Add(other.elements[i]);
    }
    return result;
}
template<typename T>
bool Bag<T>::operator==(const Bag& other) const
{
    if (size != other.size)
    {
        return false;
    }
            
    for (int i = 0; i < size; i++)
    {
        if (elements[i] != other.elements[i])
        {
            return false;
        }
        
    }
    return true;
}
#endif