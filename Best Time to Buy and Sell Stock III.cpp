#include <bits/stdc++.h>
using namespace std;

// recursive
// int maxProfitrec(vector<int> &prices, int n, int idx, bool buy, int cap)
// {
//     if (idx == n || !cap)
//         return 0;

//     if (buy)
//         return max(-prices[idx] + maxProfitrec(prices, n, idx + 1, !buy, cap), maxProfitrec(prices, n, idx + 1, buy, cap));

//     return max(prices[idx] + maxProfitrec(prices, n, idx + 1, !buy, cap - 1), maxProfitrec(prices, n, idx + 1, buy, cap));
// }

// int maxProfit(vector<int> &prices, int n)
// {
//     return maxProfitrec(prices, n, 0, true, 2);
// }

// memoization
// int maxProfitmemo(vector<int> &prices, int n, int idx, bool buy, int cap, vector<vector<vector<int>>> &dp)
// {
//     if (idx == n || cap <= 0)
//         return 0;

//     if (dp[idx][buy][cap] != -1)
//         return dp[idx][buy][cap];

//     if (buy)
//         return dp[idx][buy][cap] = max(-prices[idx] + maxProfitmemo(prices, n, idx + 1, !buy, cap, dp), maxProfitmemo(prices, n, idx + 1, buy, cap, dp));

//     return dp[idx][buy][cap] = max(prices[idx] + maxProfitmemo(prices, n, idx + 1, !buy, cap - 1, dp), maxProfitmemo(prices, n, idx + 1, buy, cap, dp));
// }

// int maxProfit(vector<int> &prices, int n)
// {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return maxProfitmemo(prices, n, 0, true, 2, dp);
// }

// tabulation
// int maxProfit(vector<int> &prices, int n)
// {
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));

//     for (int i{n - 1}; i >= 0; i--)
//     {
//         // buy
//         dp[i][1][1] = max(-prices[i] + dp[i + 1][0][1], dp[i + 1][1][1]);
//         dp[i][1][2] = max(-prices[i] + dp[i + 1][0][2], dp[i + 1][1][2]);

//         // sell
//         dp[i][0][1] = max(prices[i] + dp[i + 1][1][0], dp[i + 1][0][1]);
//         dp[i][0][2] = max(prices[i] + dp[i + 1][1][1], dp[i + 1][0][2]);
//     }

//     return dp[0][1][2];
// }

// tabulation space optimized
int maxProfit(vector<int> &prices, int n)
{
    vector<vector<int>> prev(2, vector<int>(3));
    vector<vector<int>> curr(2, vector<int>(3));
    for (int i{n - 1}; i >= 0; i--)
    {

        // buy
        curr[1][1] = max(-prices[i] + prev[0][1], prev[1][1]);
        curr[1][2] = max(-prices[i] + prev[0][2], prev[1][2]);

        // sell
        curr[0][1] = max(prices[i] + prev[1][0], prev[0][1]);
        curr[0][2] = max(prices[i] + prev[1][1], prev[0][2]);

        prev = curr;
    }

    return prev[1][2];
}