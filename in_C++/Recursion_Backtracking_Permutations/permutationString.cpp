#include <iostream>
#include <cstdio>
using namespace std;

string swap(string s, int a, int b)
{
    char c = s[a];
    s[a] = s[b];
    s[b] = c;
    return s;
}

// find all the possible permutations of a string
// abc => {abc, acb, bac, bca, cab, cba}

/*
                    abc
     a(bc)               b(ac)            c(ab)
a(bc)    a(cb)      b(ac)     b(ca)   c(ab)  c(ba)

*/

// fix a & solve (): subproblem
void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << ", ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        s = swap(s, l, i); // swap
        permute(s, l + 1, r);
        s = swap(s, l, i); // restore swap : backtracking
    }
}
int main()
{
    permute("abc", 0, 2);
    return 0;
}