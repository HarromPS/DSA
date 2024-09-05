#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* DFS(Depth first Search)
=> Data Structre used is Stack
*/

// implementing stack data structure
typedef struct Stack
{
    int top,size;
    int *arr;
}Stack;

int isFull(Stack* s){
    if(s->top==s->size-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(Stack* s){
    if(s->top==-1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(Stack* s,int val){
    if(isFull(s)){
        printf("Stack is Full\n");
    }
    else {
        s->top++;
        s->arr[s->top]=val;
    }
}

int pop(Stack* s)
{
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    return s->top--;
}
 int main()
{
    Stack s;//(Stack*)malloc(sizeof(Stack)*1);
    s.top=-1;
    s.size=10;
    s.arr=(int*)calloc(sizeof(int),s.size);

    // DFS Implementation
    int adj_matrix[7][7]=
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("Enter initial node: ");
    int i;
    scanf("%d",&i);
    printf("%d ",i);
    int visited[7]={0,0,0,0,0,0,0};

    // using the inbuilt stack of the compiler
    // for(int i=1;i<10;i++){
    //     for(int j=1;j<10;j++){
    //         if(j==1 || j==i || j==9){
    //             printf("*");
    //         }
    //         else {
    //             printf(" ");
    //         }

    //     }
    //     printf("\n");
    // }
    return 0;
}