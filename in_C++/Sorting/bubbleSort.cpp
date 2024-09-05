#include <iostream>
#include <cstdio>
using namespace std;

// Bubble sort in an array :
int main()
{
    int array[6] = {23,87, 34, 2, 3, 22};
    cout << "The array is: ";
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i-1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swapping without third variable;
                array[j] = array[j] + array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1];
            }
        }
    }
    cout << "The array sorted in increasing order: ";
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < (6 - 1 - i); j++)
        {
            if (array[j] < array[j + 1])
            {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] -= array[j + 1];
            }
        }
    }
    cout << "The array sorted in decreasing order: ";
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}