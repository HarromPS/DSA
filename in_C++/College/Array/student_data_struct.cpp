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
}student;

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

    student s;
    s.Division[3] = {'m'};
    s.name = "Harish";
    s.Class = "S.Y.";
    s.roll_no=10;
    s.Branch = "IT";
    s.phy = 12.23;
    s.chem = 78.4;
    s.maths = 56.23;

    cout << "The name of the student is: " << s.name << endl
         << "The Class of the student is: " << s.Class << endl
         << "The Roll No. of the student is: " << s.roll_no << endl
         << "The Branch of the student is: " << s.Branch << endl
         << "The Marks in Physics: " << s.phy << endl
         << "The Marks in Chemistry: " << s.chem << endl
         << "The Marks in Maths: " << s.maths << endl;

    int result = Avg_Per_Totl(s.phy, s.chem, s.maths);
    cout << "The Percentage of the student is: " << result<<"\t";
    if (result > 85)
    {
        cout << "A Grade" << endl;
    }
    else if (result > 65 && result < 85)
    {
        cout << "B Grade" << endl;
    }
    else
    {
        cout << "C Grade" << endl;
    }

    return 0;
}