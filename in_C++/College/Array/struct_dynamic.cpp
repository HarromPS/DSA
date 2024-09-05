#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

// Creating a Student structure to store the students attributes
// & functions

typedef struct student
{
    // All members are default public
    int roll_no;
    char Division[3];
    string name, Class, Branch;
    // Marking of the student
    float phy, chem, maths;
} student;

float Avg_Per_Totl(float phy, float chem, float maths)
{
    float total;
    total = phy + chem + maths;
    float avg = total / 3;
    float percentage = (total * 100) / 300;

    return (percentage);
}
int main()
{
    int n;
    cout << "Enter how many students are there in the class: ";
    cin >> n;
    // Array of Objects
    student s[n];
    cout << "Fill the details of each student" << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<endl<<i+1<<" student"<<endl;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Division: ";
        cin >> s[i].Division[3];
        cout << "Class: ";
        cin >> s[i].Class;
        cout << "Roll No: ";
        cin >> s[i].roll_no;
        cout << "Branch: ";
        cin >> s[i].Branch;
        cout << "Physics Marks: ";
        cin >> s[i].phy;
        cout << "Chemistry Marks: ";
        cin >> s[i].chem;
        cout << "Maths Marks: ";
        cin >> s[i].maths;
        cout<<endl;

        cout << "The name of the student is: " << s[i].name << endl
             << "The Class of the student is: " << s[i].Class << endl
             << "The Roll No. of the student is: " << s[i].roll_no << endl
             << "The Branch of the student is: " << s[i].Branch << endl
             << "The Marks in Physics: " << s[i].phy << endl
             << "The Marks in Chemistry: " << s[i].chem << endl
             << "The Marks in Maths: " << s[i].maths << endl;

        int result = Avg_Per_Totl(s[i].phy, s[i].chem, s[i].maths);
        cout << "The Percentage of the student is: " << result << "\t";
        if (result > 85)
        {
            cout << "'A Grade'" << endl;
        }
        else if (result > 65 && result < 85)
        {
            cout << "'B Grade'" << endl;
        }
        else
        {
            cout << "'C Grade'" << endl<<endl;
        }
    }

    return 0;
}