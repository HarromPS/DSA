#include<stdio.h>

// DS Practical :
// WAP on stack operation using array & function 

// global declaration 
int array[4],top=-1;    // count of the topmost element in the array

int push(int a)
{
    if(top>4)
    {
        printf("Stack is full\n");
        return 0;
    }
    else
    {
        top+=1;
        array[top]=a;
        printf("Number pushed: %d\n",a);
        return 1;
    }
}
int pop()
{
    if(top<0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Number poped: %d\n",array[top]);
        array[top]=0;
        top-=1;
        printf("Top= %d\n",top+1);
        
    }
}
int status(int no_of_elements)
{
    printf("The elements in the array are: ");
    for(int i=0;i<(no_of_elements);i++)
    {
        printf("%d ",array[i]);
    }
}

int main()
{
    int element;
    int no_of_elements=0;
    no_of_elements=sizeof(array)/sizeof(int);
    printf("Total no of element in the array: %d \n",(no_of_elements));
    
    int n=0;    
    while(n!=4){
    
    printf("Enter\n1) Push\n2) Pop\n3)Status\n4) Exit\n");
    
    printf("\n");
    scanf("%d",&n);
    
    switch(n)
    {
        case 1:
        printf("Push operation \n");
        printf("Enter a number to push in the array\n");
        scanf("%d",&element);
        push(element);
        break; 
        
        case 2:
        printf("Pop operation \n");
        pop();
        break;
        
        case 3:
        printf("Status of the stack\n");
        status(no_of_elements);
        break;
        
        case 4:
        printf("Exit!\n");
        break;
        
        default:
        printf("PROGRAM END!\n");
    }
} 
   return 0;
}
