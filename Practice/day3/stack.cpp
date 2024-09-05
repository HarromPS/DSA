#include <iostream>
#include <cstdio>
using namespace std;

class CustomStack
{
public:
    void push(int x)
    {
        if (this->top + 1 >= this->size)
        {
            return;
        }
        this->top += 1;
        this->arr[this->top] = x;
        return;
    }

    int size;
    int *arr;
    int top;
    CustomStack(int maxSize)
    {
        this->size = maxSize;
        arr = (int *)calloc(sizeof(int), maxSize);
        this->top = -1;
    }

    int pop()
    {
        if (this->top == -1)
        {
            return -1;
        }
        int res = this->arr[this->top];
        this->top -= 1;
        return res;
    }

    void increment(int k, int val)
    {
        int len = (k >= this->size ? this->size - 1 : k);
        for (int i = 0; i <= len; i++)
        {
            this->arr[i] += val;
        }
    }

    void showStack()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CustomStack stk(3); // = new CustomStack(3);
    // stk.push(12);
    // stk.increment(1, 12);
    // cout << stk.pop();

    stk.push(1);               // stack becomes [1]
    stk.push(2);               // stack becomes [1, 2]
    cout << stk.pop() << endl; // return 2 --> Return top of the stack 2, stack becomes [1]
    stk.push(2);               // stack becomes [1, 2]
    stk.push(3);               // stack becomes [1, 2, 3]
    stk.push(4);               // stack still [1, 2, 3], Do not add another elements as size is 4
    stk.increment(30, 100);    // stack becomes [101, 102, 103]
    stk.showStack();
    stk.increment(2, 100); // stack becomes [201, 202, 103]
    stk.showStack();
    cout << stk.pop() << endl; // return 103 --> Return top of the stack 103, stack becomes [201, 202]
    cout << stk.pop() << endl; // return 202 --> Return top of the stack 202, stack becomes [201]
    cout << stk.pop() << endl; // return 201 --> Return top of the stack 201, stack becomes []
    cout << stk.pop() << endl;
    return 0;
}