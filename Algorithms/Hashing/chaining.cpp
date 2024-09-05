#include <iostream>
#include <cstdio>
using namespace std;

// Chaining(Open Hashing) Algorithm
// Creating a linked list

typedef struct Hash
{
    Hash* head;
    int size;

} helper;

typedef struct HashTable
{
    // array of pointers
    int data;
    struct HashTable *next;

} HashTable;

HashTable *CreateNode(int val)
{
    HashTable * newHashTable = (HashTable*)malloc(sizeof(HashTable)*1);
    newHashTable->data = val;
    newHashTable->next = NULL;
    return newHashTable;
}
void insert(HashTable *n, int key,int tablesize)
{
    int index = key % tablesize;
    // HashTable
    // if()
}

void print()
{
}

void search()
{
}

int main()
{
    int size = 5;
    Hash* newHash = NULL;

    // insert(newHash,12,size);

    return 0;
}


// struct HashTable
// {
//     int key;
//     int age;
//     char name[100];
//     struct HashTable *next;
// };

// struct hash
// {
//     struct HashTable *head;
//     int count;
// };

// struct hash *hashHashTable = NULL;
// int eleCount = 0;

// struct HashTable *createHashTable(int key, char *name, int age)
// {
//     struct HashTable *newHashTable;

//     newHashTable = (struct HashTable *)malloc(sizeof(struct HashTable));

//     newHashTable->key = key;
//     newHashTable->age = age;
//     strcpy(newHashTable->name, name);
//     newHashTable->next = NULL;

//     returnnTewHashTable;
// }

// void insertToHash(int key, char *name, int age)
// {
//     int hashIndex = key % eleCount;
//     struct HashTable *newHashTable = createHashTable(key, name, age);

//     if (!hashHashTable[hashIndex].head)
//     {
//         hashHashTable[hashIndex].head = TewHashTable;
//         hashHashTable[hashIndex].count = 1;

//         return;
//     }

//     // adding new HashTable to the list
//     TewHashTable->next = (hashHashTable[hashIndex].head);

//     // update the head of the list and no of
//     //  HashTables in the current bucket

//     hashHashTable[hashIndex].head = TewHashTable;
//     hashHashTable[hashIndex].count++;
//     return;
// }
