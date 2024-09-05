#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// abc = {" ", a, b, c, ab, bc, ac, abc};   2^n

// abc
/*
                abc
            a         " "
        ab    a      b    " "
    abc   ab ac a   bc c  c  " "
*/

void power(string s, int i, string current)
{
    if (i >= s.size())
    {
        cout << current << ", ";
        return;
    }
    power(s, i + 1, current + s[i]);
    power(s, i + 1, current);
}
int main()
{
    power("abc", 0, "");
    return 0;
}