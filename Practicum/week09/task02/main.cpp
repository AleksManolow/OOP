#include <iostream>
#include "Doctor.h"
int main()
{   
    Patient one("Aleks", "20.01.2012g", 5);
    Patient two("Gosho", "15.02.2001g", 9);
    
    //one.print();
    //two.print();
    Patient* arr = new Patient[2];
    arr[0] = one;
    arr[1] = two;
    Doctor a("Pesho",2 , arr, 7845);

    a.operator<<(std::cout);
    delete[] arr; 
    

    return 0;
}