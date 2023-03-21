#include <bits/stdc++.h>
using namespace std;

bool oneSegment(string str)
{
    int n = str.length();
    int i = 0;
    while (i < n && str[i] == '1')
        i++;
    while (i < n && str[i] == '0')
        i++;
    return i == n;
}