#include <bits/stdc++.h>
using namespace std;

bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
        if (S1[j] != '*')
            return false;
    return true;
}

// recursive
// bool wildcardMatchingrec(string &pattern, string &text, int idxp, int idxt)
// {
//     if (idxp == -1 && idxt == -1)
//         return true;

//     if (idxp < 0 && idxt >= 0)
//         return false;
//     if (idxt < 0 && idxp >= 0)
//         return isAllStars(pattern, idxp);

//     if (pattern[idxp] == text[idxt] || pattern[idxp] == '?')
//         return wildcardMatchingrec(pattern, text, idxp - 1, idxt - 1);

//     if (pattern[idxp] == '*')
//         return wildcardMatchingrec(pattern, text, idxp - 1, idxt) || wildcardMatchingrec(pattern, text, idxp, idxt - 1);

//     return false;
// }

// bool wildcardMatching(string pattern, string text)
// {
//     return wildcardMatchingrec(pattern, text, pattern.length() - 1, text.length() - 1);
// }

// memoization
// bool wildcardMatchingmemo(string &pattern, string &text, int idxp, int idxt, vector<vector<int>> &dp)
// {
//     if (idxp == -1 && idxt == -1)
//         return true;

//     if (idxp < 0 && idxt >= 0)
//         return false;
//     if (idxt < 0 && idxp >= 0)
//         return isAllStars(pattern, idxp);

//     if (dp[idxp][idxt] != -1)
//         return dp[idxp][idxt];

//     if (pattern[idxp] == text[idxt] || pattern[idxp] == '?')
//         return dp[idxp][idxt] = wildcardMatchingmemo(pattern, text, idxp - 1, idxt - 1, dp);

//     if (pattern[idxp] == '*')
//         return dp[idxp][idxt] = wildcardMatchingmemo(pattern, text, idxp - 1, idxt, dp) || wildcardMatchingmemo(pattern, text, idxp, idxt - 1, dp);

//     return dp[idxp][idxt] = false;
// }

// bool wildcardMatching(string pattern, string text)
// {
//     int lenp = pattern.length(), lent = text.length();
//     vector<vector<int>> dp(lenp, vector<int>(lent, -1));
//     return wildcardMatchingmemo(pattern, text, lenp - 1, lent - 1, dp);
// }

// tabulation
// bool wildcardMatching(string pattern, string text)
// {
//     int lenp = pattern.length(), lent = text.length();
//     vector<vector<bool>> dp(lenp + 1, vector<bool>(lent + 1));

//     dp[0][0] = true;

//     for (int i = 1; i <= lenp; i++)
//         dp[i][0] = isAllStars(pattern, i-1);

//     for (int i{1}; i <= lenp; i++)
//         for (int j{1}; j <= lent; j++)
//         {
//             if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
//                 dp[i][j] = dp[i - 1][j - 1];
//             else if (pattern[i - 1] == '*')
//                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//             else
//                 dp[i][j] = false;
//         }

//     return dp[lenp][lent];
// }

// tabulation space optimized
bool wildcardMatching(string pattern, string text)
{
    int lenp = pattern.length(), lent = text.length();
    vector<bool> prev(lent + 1);

    prev[0] = true;

    for (int i{1}; i <= lenp; i++)
    {
        vector<bool> curr(lent + 1);
        curr[0] = isAllStars(pattern, i - 1);

        for (int j{1}; j <= lent; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (pattern[i - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }

    return prev[lent];
}