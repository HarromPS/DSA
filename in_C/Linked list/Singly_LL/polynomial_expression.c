#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating a struct node for Polynomial Expression
struct Node
{
    int coefficient, power; // variables for coefficient & power of expression
    struct Node *next_link; // linking pointer for the next coeff. & power
};

// Function which will create polynomial expression
void Create_poly(struct Node **poly)
{
    // local variables
    int coeff, pow, x = 1;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    *poly = temp;
    do
    {
        printf("Enter the coefficient and power of a segment of the expression\n");
        scanf("%d %d", &coeff, &pow);
        temp->coefficient = coeff;
        temp->power = pow;
        temp->next_link = NULL;
        printf("Enter any key to continue or Enter 0 to finish: ");
        scanf("%d", &x);
        if (x)
        {
            temp->next_link = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next_link;
            temp->next_link = NULL;
        }
    } while (x != 0);
}

// Creating a function to Display the expressions
void Display(struct Node *poly)
{
    printf("The expression is\n==>");
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->power);
        poly = poly->next_link;
        if (poly != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
int main()
{
    // Creating objects for polynomial expression
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    Create_poly(&first);
    Display(first);

    Create_poly(&second);
    Display(second);

    return 0;
}