#include <bits/stdc++.h>
using namespace std;

string convertString(string s)
{
    int n = s.length();

    if (n > 0)
        s[0] = toupper(s[0]);

    for (int i = 0; i < n; i++)
        if (s[i] == ' ')
            s[i + 1] = toupper(s[i + 1]);

    return s;
}