#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

class DLL
{
public:
    int key, value;
    DLL *next, *prev;
    DLL() : key(-1), value(-1), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    DLL *head;
    DLL *tail;
    std::map<int, DLL*> lruMap;
    int capacity = 0;

    void insertAtHead(DLL* node){
        node->prev = head;
        node->next = head->next;
        head->next = node;
        head->next->prev = node;
    }

    void deleteNode(DLL* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    // implementing lru cache using doubly linked list and hashmap data structure

    LRUCache(int cap)
    {
        // code here
        this->capacity = cap;
        head = (DLL*)malloc(sizeof(DLL));
        tail = (DLL*)malloc(sizeof(DLL));

        head->key = -1;
        head->value = -1;

        tail->key = -1;
        tail->value = -1;

        head->prev = NULL;
        head->next = tail;

        tail->next = NULL;
        tail->prev = head;
    }

    

    int get(int key)
    {
        // code here
        auto it = lruMap.find(key); // curr node
        if (it == lruMap.end())
        {
            return -1;
        }

        deleteNode(it->second);
        insertAtHead(it->second);
        return lruMap.find(key)->second->value;
    }

    void put(int key, int value)
    {
        // if already exists, update and bring to start
        auto it = lruMap.find(key); // curr node
        if (it != lruMap.end())     // exist
        {
            // update the value and position of the recently used node;
            // it->second->value=value;
            lruMap[key]->value=value;
            deleteNode(it->second);
            insertAtHead(it->second);
            return;
        }

        // create a new node and update 
        DLL* newNode = (DLL*)malloc(sizeof(DLL));
        newNode->prev=NULL;
        newNode->next=NULL;
        newNode->value=value;
        newNode->key=key;

        lruMap.emplace(key,newNode);
        insertAtHead(newNode);

        // if reached the capacity, remove last node 
        if(lruMap.size() > this->capacity){
            DLL* temp=tail->prev;
            deleteNode(temp);

            lruMap.erase(temp->key);
            free(temp);
        }
    }

    ~LRUCache(){
        DLL* curr = head->next;
        while(curr != tail){
            DLL* temp = curr;
            curr = curr->next;
            free(temp);
        }
        free(head);
        free(tail);
        lruMap.clear(); 
    }
};

void solve()
{

    int capacity;
    std::cin >> capacity;
    LRUCache *cache = new LRUCache(capacity);
    int queries;
    std::cin >> queries;
    while (queries--)
    {
        std::string q;
        std::cin >> q;
        if (q == "PUT")
        {
            int key;
            std::cin >> key;
            int value;
            std::cin >> value;
            cache->put(key, value);
        }
        else
        {
            int key;
            std::cin>>key;
            std::cout<<cache->get(key)<<"\n";
        }
    }
    std::cout << "~" << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    // ll test;
    // std::cin >> test;
    // while (test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}

