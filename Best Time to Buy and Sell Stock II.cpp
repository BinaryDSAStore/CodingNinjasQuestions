#include <bits/stdc++.h>
using namespace std;

// recursive
// long getMaximumProfitrec(long *values, int n, int idx, bool buy)
// {
//     if (idx == n)
//         return 0;

//     if (buy)
//         return max(-values[idx] + getMaximumProfitrec(values, n, idx + 1, !buy), getMaximumProfitrec(values, n, idx + 1, buy));

//     return max(values[idx] + getMaximumProfitrec(values, n, idx + 1, !buy), getMaximumProfitrec(values, n, idx + 1, buy));
// }

// long getMaximumProfit(long *values, int n)
// {
//     return getMaximumProfitrec(values, n, 0, true);
// }

// memoization
// long getMaximumProfitmemo(long *values, int n, int idx, bool buy, vector<vector<long>> &dp)
// {
//     if (idx == n)
//         return 0;
//     if (dp[idx][buy] != -1)
//         return dp[idx][buy];
//     if (buy)
//         return dp[idx][buy] = max(-values[idx] + getMaximumProfitmemo(values, n, idx + 1, !buy, dp), getMaximumProfitmemo(values, n, idx + 1, buy, dp));
//     return dp[idx][buy] = max(values[idx] + getMaximumProfitmemo(values, n, idx + 1, !buy, dp), getMaximumProfitmemo(values, n, idx + 1, buy, dp));
// }

// long getMaximumProfit(long *values, int n)
// {
//     vector<vector<long>> dp(n, vector<long>(2, -1));
//     return getMaximumProfitmemo(values, n, 0, true, dp);
// }

// tabulation
// long getMaximumProfit(long *values, int n)
// {
//     vector<vector<long>> dp(n + 1, vector<long>(2, 0));

//     dp[n][0] = dp[n][1] = 0;

//     for (int i{n - 1}; i >= 0; i--)
//     {
//         dp[i][1] = max(-values[i] + dp[i + 1][0], dp[i + 1][1]);
//         dp[i][0] = max(values[i] + dp[i + 1][1], dp[i + 1][0]);
//     }

//     return dp[0][1];
// }

// tabulation space optimized
long getMaximumProfit(long *values, int n)
{
    long prev0{0}, prev1{0}, curr0{0}, curr1{0};
    for (int i{n - 1}; i >= 0; i--)
    {
        curr1 = max(-values[i] + prev0, prev1);
        curr0 = max(values[i] + prev1, prev0);
        prev0 = curr0;
        prev1 = curr1;
    }
    return prev1;
}