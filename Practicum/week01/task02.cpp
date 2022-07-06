#include<iostream>
const int N = 1000;
bool isEven(int n)
{
    if (n % 2 == 0)
        return true;

    return false;
}
int* filter(int arr[], int size, bool(*pred)(int), int& sizeNew)
{
    for (int i = 0; i < size; i++)
    {
        if (pred(arr[i]))
        {
            sizeNew++;
        }
    }
    int* newArr = new int[sizeNew];

    
    for (int i = 0, counter = 0; i < size; i++)
    {
        if (pred(arr[i]))
        {
            newArr[counter] = arr[i];
            counter++;
        }
    }
    return newArr;
}
int main()
{
    int size = 0;
    int arr[N];
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    int newArrSize = 0;
    int* newArr = filter(arr, size, isEven, newArrSize);
    for (int i = 0; i < newArrSize; i++)
    {
        std::cout << newArr[i] << std::endl;
    }
    
    delete newArr;
    return 0;
}