#include<iostream>
int operation(int n)
{
    return n + 1;
}
void map(int arr[], int (*f )(int))
{
    for (int i = 0; i < 3; i++)
    {
        arr[i] = f(arr[i]);
    }
}
int main()
{
    int arr[3] = {1, 2, 3};
    map(arr, operation);
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}