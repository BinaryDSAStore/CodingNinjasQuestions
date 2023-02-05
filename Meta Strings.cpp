// C++ program to check if two strings are meta strings
#include <bits/stdc++.h>
using namespace std;

bool checkMeta(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 != len2)
        return false;

    if (str1 == str2)
        return false;

    int prev = -1, curr = -1;

    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
        {
            count++;
            if (count > 2)
                return false;
            prev = curr;
            curr = i;
        }
    }
    return (count == 2 && str1[prev] == str2[curr] && str1[curr] == str2[prev]);
}

// Driver code
int main()
{
    string str1 = "converse";
    string str2 = "converse";

    checkMeta(str1, str2) ? cout << "Yes" : cout << "No";
    return 0;
}
