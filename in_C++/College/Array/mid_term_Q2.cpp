#include <iostream>
#include <cstdio>
using namespace std;

// WAP to print using recursion the sum of all numbers divisible by
// 2, 3, 2 & 3 both & return count in main program
// Find the time complexity of the program.
// ANS ==> Time Complexity : O(n)

int i = 1;
int Print_Out(int *count, int *sum, int *limit)
{

    if (i == *limit)
    {
        if ((i % 3) == 0)
        {
            *count += 1;
            *sum += i;
            cout << "The Sum of the numbers divisible by '3' int your list is: " << *sum << endl;
            return (*count);
        }
        else
        {
            cout << "Sum is: " << *sum << endl;
            return (*count);
        }
    }
    else
    {
        if ((i % 3) == 0)
        {
            *count += 1;
            *sum += i;
        }
        i++;

        return Print_Out(count, sum, limit);
    }
}
int main()
{
    int sum = 0, count = 0, limit;
    cout << "Type how many numbers are there in your list: ";
    cin >> limit;
    cout << "The count of odd numbers divisible by 2 is: 0" << endl;
    cout << "The Sum is: 0" << endl;

    cout << "The count of odd numbers divisible by 2 & 3 both is: 0 " << endl;
    cout << "The Sum is: 0" << endl;

    int result = Print_Out(&count, &sum, &limit);
    cout << "The count of numbers divisible by '3' is: " << result << endl;
    return 0;
}
