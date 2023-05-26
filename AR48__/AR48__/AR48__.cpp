#include <iostream>

int main()
{
    void kfc(int arr[], int ind, int len);

    int arr[5] = { 5,7,1,2,3 };

    kfc(arr, 0, 5);

    return 0;
}

void kfc(int arr[], int ind, int len)
{
    if (ind == len)
        return;

    std::cout << arr[ind];
    kfc(arr, ind + 1, len);
    std::cout << arr[ind];
}