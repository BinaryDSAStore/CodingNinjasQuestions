#include <bits/stdc++.h>
using namespace std;

int getLengthOfLCS(string &str1, string &str2)
{
    int len1 = str1.length(), len2 = str2.length();

    vector<int> prev(len2 + 1, 0);

    for (int i{1}; i <= len1; i++)
    {
        vector<int> curr(len2 + 1, 0);
        for (int j{1}; j <= len2; j++)
            curr[j] = (str1[i - 1] == str2[j - 1]) ? (1 + prev[j - 1]) : max(prev[j], curr[j - 1]);
        prev = curr;
    }
    return prev[len2];
}

int canYouMake(string &str, string &ptr)
{
    int k = getLengthOfLCS(str, ptr);
    return str.length() + ptr.length() - (2 * k);
}