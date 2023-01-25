#include <bits/stdc++.h>
using namespace std;

// recursive
// long countWaysToMakeChangerec(int *denominations, int idx, int value)
// {
//     if (!value)
//         return 1;

//     if (idx == -1 || value < 0)
//         return 0;

//     long take = countWaysToMakeChangerec(denominations, idx, value - denominations[idx]);
//     long nottake = countWaysToMakeChangerec(denominations, idx - 1, value);

//     return take + nottake;
// }

// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//    return countWaysToMakeChangerec(denominations, n - 1, value);
// }

// memoization
// long countWaysToMakeChangememo(int *denominations, int idx, int value, vector<vector<long>> &dp)
// {
//     if (!value)
//         return 1;

//     if (idx == -1 || value < 0)
//         return 0;

//     if (dp[idx][value] != -1)
//         return dp[idx][value];

//     long take = countWaysToMakeChangememo(denominations, idx, value - denominations[idx], dp);
//     long nottake = countWaysToMakeChangememo(denominations, idx - 1, value, dp);

//     return dp[idx][value] = take + nottake;
// }

// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     vector<vector<long>> dp(n, vector<long>(value + 1, -1));
//     countWaysToMakeChangememo(denominations, n - 1, value, dp);
// }

// tabulation
// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     vector<vector<long>> dp(n + 1, vector<long>(value + 1, 0));
//     for (int i{0}; i < n; i++)
//         dp[i][0] = 1;
//     for (int i{1}; i <= n; i++)
//     {
//         for (int j{1}; j <= value; j++)
//         {
//             long take = 0;
//             if (j >= denominations[i - 1])
//                 take = dp[i][j - denominations[i - 1]];
//             long nottake = dp[i - 1][j];
//             dp[i][j] = nottake + take;
//         }
//     }
//     return dp[n][value];
// }

// tabulation space optimized
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0);
    prev[0] = 1;
    for (int i{1}; i <= n; i++)
    {
        vector<long> curr(value + 1, 0);
        curr[0] = 1;

        for (int j{value}; j >= 0; j--)
        {
            long take = 0;
            if (j >= denominations[i - 1])
                take = curr[j - denominations[i - 1]];
            long nottake = prev[j];
            curr[j] = nottake + take;
        }
        prev = curr;
    }
    return prev[value];
}