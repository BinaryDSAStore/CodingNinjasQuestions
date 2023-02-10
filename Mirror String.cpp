#include <bits/stdc++.h>
using namespace std;

bool isReflectionEqual(string &s)
{
    vector<bool> ref = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
    int n = s.length();

    for (int i{0}; i < n; i++)
        if (!ref[s[i] - 'A'])
            return false;

    for (int i{0}; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;

    return true;
}

int main()
{
    string a = "erwetwt";
    cout << isReflectionEqual(a);
}