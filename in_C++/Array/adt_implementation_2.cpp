#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// IN C++ language "classes" are used for ADT implementation
// Implementation of ADT of Array Data type.
// Creating my custom datatype to classify data structures

// class of My Array
class myArray
{
    // Set Of Values with NO RESERVED MEMORY

    int total_size, used_size;
    int *ptr; // using this pointer ptr to create a array of integers
public:
    void Show(class myArray *);
    void createArray(class myArray *, int, int);
    void SetValue(class myArray *);
};

// Creating a Function to create my Array which returns nothing
void myArray::createArray(class myArray *a, int Tsize, int Usize)
{
    // (*a).total_size=Tsize;     // Assigning the total size of array
    // (*a).used_size=Usize;     // Assigning the used size of array

    // // Creating array of integers
    // (*a).ptr=(int*)malloc(sizeof(int)*Tsize);

    // SHORTCUT (arrow operator)
    a->total_size = Tsize; // Assigning the total size of array
    a->used_size = Usize;  // Assigning the used size of array

    // Creating array of integers
    a->ptr = (int *)malloc(sizeof(int) * Tsize);
}

// Set values function
void myArray::SetValue(class myArray *a)
{
    int n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < a->used_size; ++i)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> (a->ptr)[i];

        // or
        // cin>>n;
        // (a->ptr)[i]=n;
    }
}
// Show function
void myArray::Show(class myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "The values at the used block " << i + 1 << " is " << (a->ptr)[i] << endl;
    }
}
int main()
{

    class myArray marks;
    cout << "Array is created\n"
         << endl;
    marks.createArray(&marks, 6, 2);
    cout << "Set value function is running\n";
    marks.SetValue(&marks);
    cout << endl
         << "Show function is running\n";
    marks.Show(&marks);

    return 0;
}