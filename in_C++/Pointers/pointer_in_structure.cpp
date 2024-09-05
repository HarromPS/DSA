#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

struct student
{
    int phy, chem, maths;
    char name[10];
    int age;
};

int function(struct student *A, int n)
{
    // *(A) <==> *(address)
    printf("Displaying values '*A' with A++ \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d element is: %d\n", i + 1, *(A));
        A++;
    }
}
int main()
{
    // Dynamic memory allocation ==> can be changed
    int n;
    printf("Enter the size of your array: ");
    scanf("%d", &n);

    // Allocating memory for "n" size
    struct student *A;
    A = (struct student *)malloc(n * sizeof(struct student));
    int *ptr;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for student %d\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", &A[i].name);
        printf("Enter the age: ");
        scanf("%d", &A[i].age);
        printf("Enter the marks in Phy, Chem, Maths \n");
        scanf("%d %d %d", &A[i].phy, &A[i].chem, &A[i].maths);
    }

    // Passing Pointer to function
    // Function call

    // No need to mention '&A' because 'A' itself is the address of the
    // first element
    function(A, n);

    return 0;
}