#include <iostream>
using namespace std;

// just like card

void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i - 1;
        int first = arr[i];
        while (j > -1 && arr[j] > first)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = first;
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(int);
    insertionSort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}