#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// recursive
// int editDistancerec(string &str1, string &str2, int i, int j)
// {
//     if (i < 0)
//         return j + 1;
//     if (j < 0)
//         return i + 1;
//     if (str1[i] == str2[j])
//         return editDistancerec(str1, str2, i - 1, j - 1);
//     return 1 + min(editDistancerec(str1, str2, i, j - 1), min(editDistancerec(str1, str2, i - 1, j), editDistancerec(str1, str2, i - 1, j - 1)));
// }

// int editDistance(string str1, string str2)
// {
//     return editDistancerec(str1, str2, str1.length() - 1, str2.length() - 1);
// }

// memoization
// int editDistancememo(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
// {
//     if (i < 0)
//         return j + 1;
//     if (j < 0)
//         return i + 1;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (str1[i] == str2[j])
//         return dp[i][j] = editDistancememo(str1, str2, i - 1, j - 1, dp);
//     return dp[i][j] = 1 + min(editDistancememo(str1, str2, i, j - 1, dp), min(editDistancememo(str1, str2, i - 1, j, dp), editDistancememo(str1, str2, i - 1, j - 1, dp)));
// }

// int editDistance(string str1, string str2)
// {
//     int len1 = str1.length(), len2 = str2.length();
//     vector<vector<int>> dp(len1, vector<int>(len2, -1));
//     return editDistancememo(str1, str2, str1.length() - 1, str2.length() - 1, dp);
// }

// tabulation
// int editDistance(string str1, string str2)
// {
//     int len1 = str1.length(), len2 = str2.length();
//     vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

//     for (int i{0}; i <= len2; i++)
//         dp[0][i] = i;
//     for (int i{0}; i <= len1; i++)
//         dp[i][0] = i;

//     for (int i{1}; i <= len1; i++)
//         for (int j{1}; j <= len2; j++)
//         {
//             if (str1[i - 1] == str2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
//         }

//     return dp[len1][len2];
// }

// tabulation space optimized
int editDistance(string str1, string str2)
{
    int len1 = str1.length(), len2 = str2.length();
    vector<int> prev(len2 + 1);

    for (int i{0}; i <= len2; i++)
        prev[i] = i;

    for (int i{1}; i <= len1; i++)
    {
        vector<int> curr(len2 + 1);
        curr[0] = i;
        for (int j{1}; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
        }
        prev = curr;
    }

    return prev[len2];
}