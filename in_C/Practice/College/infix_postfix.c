#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Converting a Infix Expression to Postfix Expression

int main()
{
    char expression[20];
    printf("Enter the expression: ");

    // User input of the expression
    scanf("%[^\n]", expression);
    printf("Your expression is: %s\n", expression);

    // Array for the stack
    char Stack[10];
    int top = 0;
    // Scanning the expression
    char *ptr;
    ptr = expression;
    while (*ptr != '\0')
    {
        if ((*ptr == '+') || (*ptr == '-') || (*ptr == '*') || (*ptr == '/'))
        {
            Stack[top] = *ptr;
            top++;
        }
        else
        {
            if (*ptr <= '\0')
            {
                printf("+++");
            }
            else
            {
                printf("%c ", *ptr);
            }
        }
        ptr++;
    }
    printf("\nThe operators in the stack are\n");
    printf("Length of Stack is %d\n",sizeof(Stack)/sizeof(int));
    for (int i = 0; i <sizeof(Stack)/sizeof(int)/* strlen(Stack)*/; i++)
    {
       printf("%c ", Stack[i]);
    }
    return 0;
}