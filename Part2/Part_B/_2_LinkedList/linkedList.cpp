#include<iostream>
#include<stdlib.h>
using namespace std;

// Implementation of Linked List

typedef class Node{
public: 
    int data;
    class Node* next;
}Node; 

typedef class LinkedList{
public: 

    // all the attributes and methods are defined here
    Node* head, *tail;

    // initialize the linked list 
    void initializeLL(int element){
        this->head = (Node*)malloc(sizeof(Node));
        this->head->data = element;
        this->head->next = NULL;

        this->tail = head;
        
    }

    // insert the linked list
    void insertNodeAtHead(int element){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = this->head;

        this->head = newNode;
        cout<<"SUCCESS INSERT"<<endl;
    }

    // insert the linked list
    void insertNodeAfterNode(int target, int element){
        Node* curr = head;
        int flag = 0;
        while(curr->next!=NULL){
            if(curr->data == target){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = element;
                newNode->next = curr->next;
                curr->next = newNode;
                flag = 1;
                break;
            }
            curr = curr->next;
        }

        if(flag){
            cout<<"SUCCESS INSERT"<<endl;
        }
        else{
            cout<<"FAILED INSERT"<<endl;

        }
    }

    // insert the linked list
    void insertNodeAtEnd(int element){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = NULL;

        this->tail->next = newNode;
        this->tail = newNode;

        cout<<"SUCCESS INSERT"<<endl;
    }

    // delete node from LL
    void deleteAtHead(){
        Node* curr = this->head;
        this->head = this->head->next;
        free(curr);
        return ;
    }

    // delete from linked list
    int deleteNode(int element){
        int flag = 0;
        Node* curr = this->head;
        while(curr != NULL){
            if(curr->data == element && curr->next!=NULL){
                curr->data = curr->next->data;
                curr->next = curr->next->next;
                return 1;
            }
            else if(curr->data == element && curr->next==NULL){
                this->deleteAtEnd();
                return 1;
            }
            curr = curr->next;
        }

        if(this->tail->data == element && this->head->data == element){
            this->head = NULL;
            this->tail = NULL;
            flag = 1;
        }
        else if(this->tail->data == element){
            this->tail = NULL;
            flag = 1;
        }

        if(flag){
            cout<<"SUCCESS DELETE"<<endl;
        }
        return -1;
    }

     // delete node from LL
    void deleteAtEnd(){
        Node* curr = this->head;
        if(this->head == this->tail){
            this->head = this->head->next;
            free(curr);
            return ;
        }

        while(curr->next!=this->tail){
            curr = curr->next;
        }

        curr->next = this->tail->next;
        this->tail = curr;
    }

    void searchLL(int element){
        int flag = 0;
        Node* curr = this->head;
        while(curr!=NULL){
            if(curr->data == element){
                flag = 1;
                break;
            }
            curr=curr->next;
        }
        if(flag){
            cout<<"FOUND: "<<element<<endl;
            return;
        }
        cout<<"NOT FOUND"<<endl;
    }

    void traverseLL(){
        Node* curr = this->head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
}LinkedList;

int main(){

    // Create an instance of linked list
    LinkedList l;
    l.initializeLL(1);
    l.insertNodeAtEnd(2);
    l.insertNodeAtEnd(4);
    l.insertNodeAtEnd(5);
    l.traverseLL();
    l.insertNodeAfterNode(2,3);
    l.traverseLL();
    l.insertNodeAtHead(0);
    l.traverseLL();

    l.deleteAtHead();
    l.traverseLL();
    l.deleteAtEnd();
    l.traverseLL();
    l.deleteNode(4);
    l.traverseLL();

    l.searchLL(6);
    return 0;
}