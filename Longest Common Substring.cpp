#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2)
{
    int len1 = str1.length(), len2 = str2.length(), ans{0};

    vector<int> prev(len2 + 1, 0);

    for (int i{1}; i <= len1; i++)
    {
        vector<int> curr(len2 + 1, 0);
        for (int j{1}; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                int val = 1 + prev[j - 1];
                curr[j] = val;
                ans = max(ans, val);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}