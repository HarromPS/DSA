#include <iostream>
#include <cstdio>
using namespace std;
// Stack using array
// Push operation
int push(int arr[], int *n, int *top, int *element)
{
    if (*top > *n)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "Element Pushed: " << *element << endl;
        *top += 1;
        int x = *n + *top;
        arr[x] = *element;
        cout << *top << endl
             << x << endl;
    }
}
// Pop operation
int pop(int arr[], int *n, int *top)
{
    if (*top == 0)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Element Popped: " << arr[*n + (*top)] << endl;
        *top -= 1;
        int x = *n + *top;
        arr[x] = 0;
    }
}
// Displaying the stack
void show(int arr[], int *n, int *top)
{
    int x = *n + *top;
    cout<<x<<endl;
    cout<<*top<<endl;

    // cout<<arr[x+1]<<endl;

    cout << "Stack: (";
    for (int i = 0; i < (x); i++)
    {
        if (i <= (x - 2))
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << ")" << endl;
}
int main()
{
    int n, element, top = 0;
    cout << "Type the size of your array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    cout << "Elements in the stack are: (";
    for (int i = 0; i < n; i++)
    {
        if (i <= (n - 2))
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << ")" << endl;
    cout << "Enter\n1) Push\n2) Pop\n3)Status\n4) Exit\n";
    int x = 1;
    cin >> x;
    while (x != 4)
    {
        switch (x)
        {
        case 1:
            cout << "Push Operation" << endl;
            cout << "Enter a number to push in the array: ";
            cin >> element;
            push(arr, &n, &top, &element);
            break;
        case 2:
            cout << "Pop Operation" << endl;
            pop(arr, &n, &top);
            break;
        case 3:
            cout << "Show Operation" << endl;
            show(arr, &n, &top);
            break;
        case 4:
            cout << "Exit Operation" << endl;
            break;
        default:
            cout << "PROGRAM END" << endl;
            break;
        }
        printf("Enter\n1) Push\n2) Pop\n3)Status\n4) Exit\n");
        cin >> x;
    }
    return 0;
}