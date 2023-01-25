#include <bits/stdc++.h>
using namespace std;

// recursive
// int maximumProfitrec(vector<int> &prices, int n, int idx, bool buy, int cap)
// {
//     if (idx == n || !cap)
//         return 0;

//     if (buy)
//         return max(-prices[idx] + maximumProfitrec(prices, n, idx + 1, !buy, cap), maximumProfitrec(prices, n, idx + 1, buy, cap));

//     return max(prices[idx] + maximumProfitrec(prices, n, idx + 1, !buy, cap - 1), maximumProfitrec(prices, n, idx + 1, buy, cap));
// }

// int maximumProfit(vector<int> &prices, int n, int k)
// {
//     return maximumProfitrec(prices, n, 0, true, k);
// }

// memoization
// int maximumProfitmemo(vector<int> &prices, int n, int idx, bool buy, int cap, vector<vector<vector<int>>> &dp)
// {
//     if (idx == n || cap <= 0)
//         return 0;

//     if (dp[idx][buy][cap] != -1)
//         return dp[idx][buy][cap];

//     if (buy)
//         return dp[idx][buy][cap] = max(-prices[idx] + maximumProfitmemo(prices, n, idx + 1, !buy, cap, dp), maximumProfitmemo(prices, n, idx + 1, buy, cap, dp));

//     return dp[idx][buy][cap] = max(prices[idx] + maximumProfitmemo(prices, n, idx + 1, !buy, cap - 1, dp), maximumProfitmemo(prices, n, idx + 1, buy, cap, dp));
// }

// int maximumProfit(vector<int> &prices, int n, int k)
// {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
//     return maximumProfitmemo(prices, n, 0, true, k, dp);
// }

// tabulation
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1)));

    for (int i{n - 1}; i >= 0; i--)
    {
        // buy
        for (int j{1}; j <= k; j++)
            dp[i][1][j] = max(-prices[i] + dp[i + 1][0][j], dp[i + 1][1][j]);

        // sell
        for (int j{1}; j <= k; j++)
            dp[i][0][j] = max(prices[i] + dp[i + 1][1][j - 1], dp[i + 1][0][j]);
    }

    return dp[0][1][k];
}

// tabulation space optimized
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> prev(2, vector<int>(k + 1));
    vector<vector<int>> curr(2, vector<int>(k + 1));

    for (int i{n - 1}; i >= 0; i--)
    {
        // buy
        for (int j{1}; j <= k; j++)
            curr[1][j] = max(-prices[i] + curr[0][j], curr[1][j]);

        // sell
        for (int j{1}; j <= k; j++)
            curr[0][j] = max(prices[i] + curr[1][j - 1], curr[0][j]);

        prev = curr;
    }

    return prev[1][k];
}