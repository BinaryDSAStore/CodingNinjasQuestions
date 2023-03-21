#include <bits/stdc++.h>
using namespace std;

int isCyclicRotation(string &p, string &q)
{
    if (p.length() != q.length())
        return 0;

    string temp = p + p;
    return temp.find(q) != string::npos;
}
