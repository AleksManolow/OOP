#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#define DEFAULT_CAPACITY 8

class String
{
private:
    char* mData;
    size_t mCapacity;

    char* dynCopy(const char* other, size_t capacity) const;
    void resize(size_t capacity);
public:
    String();
    String(const char* other);
    String(const String& other);
    String& operator=(const String& other);
    ~String();
    
    size_t size() const;
    size_t capacity() const;
    String& append(const String&); // concatenates the current string with the string other
    String& append(const char*); // same as the above method
    void pushBack(char c); // adds a character to the end of the string
    void erase();
	bool isEmpty() const;
    
    void swap(String& other);
    String* substring(size_t start, size_t end) const; //returns a newly created object with the contents of the substring of the current string, starting from the start position and ending at the end position
	
    String& operator+(const String&)const; // returns a new string that represents the concatenation of the current string
    String& operator+=(const String&); // returns an alias to the current string, having previously concatenated with the string
    char operator[](size_t) const; // returns a copy of the symbol at the index position
    char& operator[](size_t); // returns an alias to the index character
    bool operator!=(const String&) const; // lexicographically checks whether the two strings are different
    bool operator==(const String&) const; // lexicographically checks whether the two strings are the same

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
};

#endif