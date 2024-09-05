#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Solution
{
    int key, value;
    struct Solution *next;
} Solution;

int main()
{
    Solution *array[3];
    for (int i = 0; i < 3; i++)
    {
        // Allocate memory for each Solution struct
        array[i] = new Solution;

        // initialize the node
        array[i]->key = (i + 1) * 12;
        array[i]->value = (i + 1) * 24;

        // each list of solution ends with a null pointer
        array[i]->next = nullptr;

        if (i == 2)
        {
            Solution *temp = nullptr;
            array[i]->next = temp;
            for (int j = 0; j < 3; j++)
            {
                // temp = new Solution;
                // temp->key = (j + 2) * 12;
                // temp->key = (j + 2) * 24;
                // temp->next = nullptr;
                // temp = temp->next;
                temp = new Solution;
                temp->key = (j + 2) * 12;
                temp->value = (j + 2) * 24;
                temp->next = nullptr;
                array[i]->next = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << array[i]->key << " " << array[i]->value << endl;
        if (array[i]->next != nullptr)
        {
            cout << "Shout" << endl;
            Solution *temp = array[i]->next;
            while (temp->next != nullptr)
            {
                cout << temp->key << " " << temp->value << endl;
                temp = temp->next;
            }
        }
    }

    // Clean up memory by deleting dynamically allocated structs
    for (int i = 0; i < 3; i++)
    {
        Solution *current = array[i];
        while (current != nullptr)
        {
            Solution *temp = current;
            current = current->next;
            delete temp;
        }
    }
    return 0;
}