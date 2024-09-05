#include<iostream>
#include<cstdio>
using namespace std;

int main(){

    int a;
    int *ptr;   // *ptr is a variable which stores the address of other 
                // variables and values both using (*) == dereferencing operator
    a=10;
    ptr = &a;     // ptr stores address of a

    // simply value of "a"
    printf("The value of 'a' is: %d\n",a);

    // ptr ==> address and *(ptr) ==> value
    // " &(variable_name) " ==> address of variable
    printf("The value of '*ptr' is: %d\n",*(ptr));

    // *(&a) <==> *(ptr)
    printf("The value of '*(&a)' is: %d\n",*(&a));

    // Addresses of variables 
    // Address of " a "
    printf("The address at '&a' is: %d\n",&a);

    // Address of " ptr " <==> " &a "
    printf("The address at 'ptr' is: %d\n",ptr);

    // Address of "ptr" is
    printf("The address of '&ptr' is: %d\n",&ptr);

    printf("\nNow the value of ptr is changed\n");
    *(&a)=20;       // a==20
    // *(&a) <==> a <==> *(ptr)
    printf("The value of 'a' is: %d\n",a);
    printf("The value of '*ptr' is: %d\n",*(ptr));
    printf("The value of '*(&a)' is: %d\n",*(&a));
    printf("The value of '&a' is: %d\n",&a);
  
    return 0; 
}