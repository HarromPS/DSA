#include <stdio.h>

int main()
{
    int count = 0;

    // Here n=3 and there are 2 loops
    // so time complexity or loop run for n*n times ==> log n^n(base n)
    // for 3 nested loops it will run for n*n*n times
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int z = 0; z < 3; z++)
            {
                count++;
            }
        }
    }
    printf("The loop will run for %d times\n", count);
    return 0;
}
