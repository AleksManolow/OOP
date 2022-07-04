#include<iostream>
#include"Bag.h"
#include"ImprovedBag.h"
int main()
{
    Bag<int> a;
    a.Add(5);
    a.Add(6);
    a.Add(7);
    Bag<int> b;
    b.Add(5);
    b.Add(4);
    b.Add(7);
    Bag<int> result = a + b;
    result.print();

    ImprovedBag<int> abv("Vankata");
    abv.Add(0);
    abv.Add(1);
    abv.Add(2);
    abv.Add(3);
    abv.Add(4);
    abv.Add(5);
    abv.Insert(78, 1);
    abv.print();

    return 0;
}