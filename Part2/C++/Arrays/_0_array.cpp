#include<iostream>
#include<stdlib.h>
using namespace std;

// Implementation of array data structure 

typedef struct Arrays {
    // by default every attribute is public in struct datatype 
    int *arr;
    int totalSize;
    int usedSize;
} Arrays;

// initialize the array with a size
Arrays initializeArray(int size){
    Arrays s;
    s.arr = (int*)calloc(sizeof(int),size);
    s.totalSize = size;
    s.usedSize = 0;
    return s;
}

// Operations on array

// O(N)
// 1. Traversal
void traverseArray(Arrays arr){
    cout<<"\n' ";
    for(int i=0;i<arr.usedSize;i++){
        cout<<arr.arr[i]<<" ";
    }
    cout<<"'\n\n";
}

// O(1)
// 2. Insertion
void insertArray(Arrays* arr, int element){
    if(arr->usedSize >= arr->totalSize){
        cout<<"ARRAY IS FULL"<<endl;
        return;
    }
    else{
        arr->arr[arr->usedSize++] = element;
        cout<<"SUCCESS-INSERTED"<<endl;
        return;
    }
    cout<<"FAILED-INSERTED"<<endl;
}

// O(N)
// 3. Deletion (deletes first instance an element)
int deleteElement(Arrays *arr,int target){
    int index = -1,flag=0;
    for(int i=0;i<=arr->usedSize;i++){
        if(arr->arr[i] == target){
            index = i;
            break;
        }
    }

    int res = arr->arr[index];
    if(index != -1 && index<arr->usedSize){
        for(int i=index;i<arr->usedSize;i++){
            arr->arr[i] = arr->arr[i+1];
            index = i;    
        }
        arr->arr[index+1] = 0;
        flag = 1;
    }
    else{
        arr->arr[index] = 0;
        flag = 1;
    }

    if(flag){
        cout<<"SUCCESS DELETED"<<endl;
        return res;
    }
    cout<<"FAILED DELETED"<<endl;
    return -1;
}

// O(N)
// 4. Searching a particular element
int searchElement(Arrays arr, int element){
    int flag = -1;
    for(int i=0;i<arr.usedSize;i++){
        if(arr.arr[i] == element){
            flag = i;
            break;
        }
    }
    if(flag){
        cout<<"FOUND AT INDEX: "<<flag<<endl;
        return flag;
    }
    cout<<"NOT FOUND: "<<endl;
    return flag;
}

int main(){
    // Create an instance of Arrays
    Arrays a;
    a = initializeArray(10);
    insertArray(&a, 1);
    insertArray(&a, 2);
    traverseArray(a);
    insertArray(&a, 3);
    insertArray(&a, 4);
    traverseArray(a);

    deleteElement(&a, 3);
    traverseArray(a);

    searchElement(a,2);
    return 0;
}