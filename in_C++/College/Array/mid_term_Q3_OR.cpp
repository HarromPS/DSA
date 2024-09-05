#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
    Define a stack of students info consists of roll_no,name & 3 subject marks, when we push element, calculate Sum & average & save it. Print sum and average
    of second last student.
*/
int top = 0;
int count = 0;

struct Student_Info
{
    int roll_no;
    float Phy, Chem, Maths;
    string name;
};

int Push(Student_Info S1[], float phy, float chem, float maths)
{
    if (top > (sizeof(*S1) / sizeof(struct Student_Info)))
    {
        cout << "Stack is full\n";
    }
    else
    {

        ++top;
        S1[top].Phy = phy;
        S1[top].Chem = chem;
        S1[top].Maths = maths;
        count = top;
        // cout << count << endl;
    }
}

int Pop(Student_Info S1[])
{
    if (top < 0)
    {
        cout << "Stack is Empty\nNo details";
    }
    else
    {
        if ((top-1)==(count-1))
        {
            float Sum = (S1[top].Phy + S1[top].Chem + S1[top].Maths);
            float Avg = Sum / 3;
            cout<<"The Name of the student is: "<<S1[top-1].name<<endl;
            cout<<"The Roll No of the student is: "<<S1[top-1].roll_no<<endl;
            cout << "The total marks of the Student is: " << Sum << endl;
            cout << "The Average of the student is: " << Avg << endl;
        }
        else{
            --top;
            return Pop(S1);
        }
    }
}
int main()
{
    Student_Info Student[3];
    float phy, chem, maths;
    int x, i = 0;
    cout << "Choose\n1) Add Student\n2) Show details of the last second student "
         << "\n3) Exit" << endl;
    cin >> x;
    while (x != 3)
    {

        switch (x)
        {
        case 1:
            cout << "Enter details of the students " << endl
                 << endl;
            cout << "Enter details of " << i + 1 << " Student " << endl;
            cout << "Name: ";
            cin >> Student[i].name;
            cout << "Roll No: ";
            cin >> Student[i].roll_no;
            cout << "Physics marks: ";
            cin >> phy;
            cout << "Chemisty marks: ";
            cin >> chem;
            cout << "Maths marks: ";
            cin >> maths;
            Push(Student, phy, chem, maths);
            ++i;
            break;
        case 2:
            cout << "The details of the last second student are==> " << endl;
            Pop(Student);
            break;
        case 3:
            cout << "EXIT !" << endl;
            break;
        default:
            cout << "Invalid Number" << endl;
            break;
        }
        cout << "Choose\n1) Add Student\n2) Show details of the last second student"
             << "\n3) Exit" << endl;
        cin >> x;
    }
    return 0;
}