#include <stdio.h>
#include<stdlib.h>

// ADT(Abstract Data Type) OR Custom Data Type
// And Operations

struct adt
{
    int num1;
    int num2;

} adt;

// int max()
// {
// }
int min()
{
}

int insert()
{
}
int delete ()
{
}
int main()
{

    int* arr;
    arr=(int*)malloc(5*sizeof(int));

    for(int i=0;i<sizeof(arr);i++)
    {
        arr[i]=i+1;
    }
    printf("Addresses & the values at that address\n");
    for(int i=0;i<sizeof(arr);i++)
    {
        printf("%d-> %d\n",&arr[i],arr[i]);
    }

    free(arr);
    return 0;
}
