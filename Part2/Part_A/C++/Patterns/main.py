import os

print(os.path.exists("./"))

def makeFiles():
    for i in range(0,22):
        if(not os.path.exists("./C++/Patterns/")):
            with open(os.path.join("./",f"_{i+1}_pattern.cpp"),'w') as file:
                text='''#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

void printPattern(int n){
    
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
}
     
                '''
                file.write(text)

makeFiles()

def removeFiles():
    for i in range(0,22):
        if(not os.path.exists("./C++/Patterns/")):
            os.remove(f"./_{i+1}_pattern.cpp")

# removeFiles()
        