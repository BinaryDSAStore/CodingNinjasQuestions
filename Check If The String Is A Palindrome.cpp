#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    string str = "";

    for (int i{0}; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            str += s[i];

        if (s[i] >= '0' && s[i] <= '9')
            str += s[i];

        if (s[i] >= 'A' && s[i] <= 'Z')
            str += s[i] + 32;
    }

    int n = str.length();

    for (int i{0}; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
            return false;
    }
    return true;
}