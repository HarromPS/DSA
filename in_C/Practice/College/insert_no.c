#include<stdio.h>

// DS Practical :
// WAP to insert a number at a particular position in a array  

int replace(int* arr,int n)
{
        int position,x;
        printf("Enter the position to replace a number: ");
        scanf("%d",&position);
        
        if(position>n)
        {
                printf("Invalid Input \n\nEND!");
        }
        else{
                if(position==0)
          {
                printf("The new array is: \n");
                for(int i=0;i<n;i++)
                {
                        printf("Element at %d: %d\n",i+1,arr[i]);
                }
          }
        else
          {
                printf("Enter the element: ");
                scanf("%d",&x);
        
                printf("\nEnter '0' to end the loop\n");
                arr[position-1]=x;
        
               return replace(arr,n);
          }
        }
}

int main()
{
        int n;
        printf("Enter the size of your array\n");
        scanf("%d",&n);
        int arr[10];
        printf("Enter the elements in the array\n");
        for(int i=0;i<n;i++)
        {
                printf("Enter %d element: ",i+1);
                scanf("%d",&arr[i]);
        }
        printf("\nThe elements you entered:\n");
        for(int i=0;i<n;i++)
        {
                printf("Element at %d: %d\n",i+1,arr[i]);
        }
        replace(arr,n);
        return 0;
}
