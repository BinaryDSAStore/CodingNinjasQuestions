#include <bits/stdc++.h>
using namespace std;

// recursive
// int stockProfitrec(vector<int> &prices, int n, int idx, bool buy)
// {
//     if (idx >= n)
//         return 0;

//     if (buy)
//         return max(-prices[idx] + stockProfitrec(prices, n, idx + 1, !buy), stockProfitrec(prices, n, idx + 1, buy));

//     return max(prices[idx] + stockProfitrec(prices, n, idx + 2, !buy), stockProfitrec(prices, n, idx + 1, buy));
// }

// int stockProfit(vector<int> &prices)
// {
//     return stockProfitrec(prices, prices.size(), 0, true);
// }

// memoization
// int stockProfitmemo(vector<int> &prices, int n, int idx, bool buy, vector<vector<int>> &dp)
// {
//     if (idx >= n)
//         return 0;

//     if (dp[idx][buy] != -1)
//         return dp[idx][buy];

//     if (buy)
//         return dp[idx][buy] = max(-prices[idx] + stockProfitmemo(prices, n, idx + 1, !buy, dp), stockProfitmemo(prices, n, idx + 1, buy, dp));

//     return dp[idx][buy] = max(prices[idx] + stockProfitmemo(prices, n, idx + 2, !buy, dp), stockProfitmemo(prices, n, idx + 1, buy, dp));
// }

// int stockProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return stockProfitmemo(prices, n, 0, true, dp);
// }

// tabulation
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2));

    for (int i{n - 1}; i >= 0; i--)
    {
        dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
    }

    return dp[0][1];
}

// tabulation space optimized
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2));
    vector<int> prev1(2);
    vector<int> prev2(2);
    vector<int> curr(2);

    for (int i{n - 1}; i >= 0; i--)
    {
        curr[1] = max(-prices[i] + prev1[0], prev1[1]);
        curr[0] = max(prices[i] + prev2[1], prev1[0]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1[1];
}