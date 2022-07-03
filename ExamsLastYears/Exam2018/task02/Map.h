#ifndef __MAP_H
#define __MAP_H
#include<iostream>

template <typename K, typename V>
class Map
{
private:
    static const std::size_t DEFAULT_CAPACITY_RESIZE = 2;
    static const std::size_t DEFAULT_CAPACITY = 2;

    std::size_t size;
    std::size_t capacity;
    K* keys;
    V* values;

    void delocateMemory();
    void copy(K* _keys,V* _values);
    void resize();
public:
    Map();
    Map(std::size_t _capacity);
    Map(const Map& );
    Map& operator=(const Map& );
    ~Map();

    void push_back(K _key,V _value);
    void removeAt(size_t index);

    bool operator==(const Map& ) const;
    bool operator!=(const Map& ) const;
    Map operator+(const Map& other);

    template<typename A, typename B>
    friend std::ostream& operator<<(std::ostream& out, const Map<A, B>& other);
};
template <typename K, typename V>
void Map<K,V>::delocateMemory()
{
    delete[] keys;
    delete[] values;
}
template <typename K, typename V>
void Map<K,V>::copy(K* _keys,V* _values)
{
    keys = new K[capacity];
    for (size_t i = 0; i < size; i++)
    {
        keys[i] = _keys[i];
    }
    
    values = new V[capacity];
    for (size_t i = 0; i < size; i++)
    {
        values[i] = _values[i];
    }
}
template <typename K, typename V>
void Map<K,V>::resize()
{
    K* newKeys = new K[capacity * DEFAULT_CAPACITY_RESIZE];
    V* newValues = new V[capacity * DEFAULT_CAPACITY_RESIZE];
    
    for (size_t i = 0; i < size; i++)
    {
        newKeys[i] = keys[i];
        newValues[i] = values[i];
    }
    delocateMemory();
    keys = newKeys;
    values = newValues;
    capacity = capacity * DEFAULT_CAPACITY_RESIZE;
}
template <typename K, typename V>
Map<K,V>::Map():capacity(DEFAULT_CAPACITY)
{
    size = 0;
    keys = new K[DEFAULT_CAPACITY];
    values = new V[DEFAULT_CAPACITY];
}
template <typename K, typename V>
Map<K,V>::Map(std::size_t _capacity):capacity(_capacity)
{
    size = 0;
    keys = new K[_capacity];
    values = new V[_capacity];
}
template <typename K, typename V>
Map<K,V>::Map(const Map& other)
{
    size = other.size;
    capacity = other.capacity;
    copy(other.keys, other.values);
}
template <typename K, typename V>
Map<K,V>& Map<K,V>::operator=(const Map& other)
{
    if (this != &other)
    {
        delocateMemory();

        size = other.size;
        capacity = other.capacity;
        copy(other.keys, other.values);     
    }
    return *this;
}
template <typename K, typename V>
Map<K,V>::~Map()
{
    delocateMemory();
}
template <typename K, typename V>
void Map<K,V>::push_back(K _key,V _value)
{
    if (size == capacity)
    {
        resize();
    }
    keys[size] = _key;
    values[size] =_value;
    size++;
}
template <typename K, typename V>
void Map<K,V>::removeAt(size_t index)
{
    if (index >= size)
    {
        throw "Index out of bounds!\n";
    }
    
    for (size_t i = index; i < size - 1; i++)
    {
        keys[i] = keys[i + 1];
        values[i] = values[i + 1];
    }
    size--;
    
}
template <typename K, typename V>
bool Map<K,V>::operator==(const Map& other) const
{
    if (size != other.size)
    {
        return false;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (keys[i] != other.keys[i] || values[i] != other.values[i])
        {
            return false;
        }
    }
    return true;
    
}
template <typename K, typename V>
bool Map<K,V>::operator!=(const Map& other) const
{
    for (int i = 0; i < size; i++)
    {
        if (keys[i] != other.keys[i] || values[i] != other.values[i])
        {
            return true;
        }
    }
    return false;
}
template <typename K, typename V>
Map<K,V> Map<K,V>::operator+(const Map& other)
{
    Map<K,V> result(*this);
    for (size_t i = 0; i < other.size; i++)
    {
        result.push_back(other.keys[i], other.values[i]);
    }
    return result;
}
template<typename A, typename B>
std::ostream& operator<<(std::ostream& out, const Map<A, B>& other)
{
    out << "Size: "<< other.size << '\n';
    for (size_t i = 0; i < other.size; i++)
    {
        out << other.keys[i] << " -> " << other.values[i] << '\n';
    } 
}
#endif