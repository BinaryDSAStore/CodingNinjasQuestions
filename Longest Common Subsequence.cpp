#include <bits/stdc++.h>
using namespace std;

// recursive
// int getLengthOfLCSrec(string &str1, string &str2, int i1, int i2)
// {
//     if (i2 < 0 || i1 < 0)
//         return 0;

//     if (str1[i1] == str2[i2])
//         return 1 + getLengthOfLCSrec(str1, str2, i1 - 1, i2 - 1);

//     return max(getLengthOfLCSrec(str1, str2, i1, i2 - 1), getLengthOfLCSrec(str1, str2, i1 - 1, i2));
// }

// int getLengthOfLCS(string &str1, string &str2)
// {
//     return getLengthOfLCSrec(str1, str2, str1.length() - 1, str2.length() - 1);
// }

// memoization
// int getLengthOfLCSmemo(string &str1, string &str2, int i1, int i2, vector<vector<int>> &dp)
// {
//     if (i2 < 0 || i1 < 0)
//         return 0;

//     if (dp[i1][i2] != -1)
//         return dp[i1][i2];

//     if (str1[i1] == str2[i2])
//         return dp[i1][i2] = 1 + getLengthOfLCSmemo(str1, str2, i1 - 1, i2 - 1, dp);

//     return dp[i1][i2] = max(getLengthOfLCSmemo(str1, str2, i1, i2 - 1, dp), getLengthOfLCSmemo(str1, str2, i1 - 1, i2, dp));
// }

// int getLengthOfLCS(string &str1, string &str2)
// {
//     vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
//     return getLengthOfLCSmemo(str1, str2, str1.length() - 1, str2.length() - 1, dp);
// }

// tabulation
// int getLengthOfLCS(string &str1, string &str2)
// {
//     int len1 = str1.length(), len2 = str2.length();

//     vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

//     for (int i{1}; i <= len1; i++)
//         for (int j{1}; j <= len2; j++)
//             dp[i][j] = (str1[i - 1] == str2[j - 1]) ? (1 + dp[i - 1][j - 1]) : max(dp[i - 1][j], dp[i][j - 1]);

//     return dp[len1][len2];
// }

// tabulation space optimized
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