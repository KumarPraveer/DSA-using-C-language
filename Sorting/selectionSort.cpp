#include <iostream>
using namespace std;
//This is selection Sort
void selectionSort(int arr[], int length)
{
    int i, j, k;
    for (int i = 0; i < length - 1; i++)
    {
        for (j = k = i; j < length; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(int);
    selectionSort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}