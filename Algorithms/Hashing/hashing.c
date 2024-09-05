#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define t_size 10
typedef struct
{
    int *arr;
    char * name;
}student;

student* createStudent(){
    student *s=(student*)malloc(sizeof(student)*1);
    s->arr=(int*)calloc(sizeof(int),t_size);
}
void details(student* s)
{
    printf("Enter a name: ");
    char * name;
    scanf("%s",&name);
}
int main(){
    char * name;
    scanf("%s",&name);
    printf("%s",(name[2]));
    return 0;
}