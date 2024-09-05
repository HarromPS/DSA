#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
// Hash Table -> Array + Hash Function
typedef struct {
    char name[MAX_NAME];
    int age;
}person;

unsigned int hashFunction(char * name)
{
    int length=strnlen(name,MAX_NAME);
    unsigned int hash_value=0;
    for(int i=0;i<length;i++){
        // ascii values of the characters
        hash_value+=name[i];
        hash_value=(hash_value * name[i])%TABLE_SIZE;
    }
    return hash_value;
}
int main(){
    char * string ="an me";
    printf("%s\n",string);

    // returns the length of the string with n parameter
    // n-> no at which we want to find length of the string
    // null char not included
    printf("%d\n",strnlen(string,5));

    printf("hariom => hash value: %d\n",hashFunction("har iom"));
    printf("abhij => hash value: %d\n",hashFunction("abhi"));
    printf("john => hash value: %d\n",hashFunction("john"));
    printf("limboh => hash value: %d\n",hashFunction("limbo"));
    printf("kibo => hash value: %d\n",hashFunction("kibo"));
    return 0;
}