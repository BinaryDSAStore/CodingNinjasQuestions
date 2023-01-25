#include <bits/stdc++.h>
using namespace std;

// recursive
// int unboundedKnapsackrec(int idx, int w, vector<int> &profit, vector<int> &weight)
// {
//     if (w < 0)
//         return -1e8;

//     if (idx == 0)
//         return w / weight[0] * profit[0];

//     int take = profit[idx] + unboundedKnapsackrec(idx, w - weight[idx], profit, weight);
//     int nottake = unboundedKnapsackrec(idx - 1, w, profit, weight);

//     return max(take, nottake);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     return unboundedKnapsackrec(n - 1, w, profit, weight);
// }

// memoization
// int unboundedKnapsackmemo(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
// {
//     if (w < 0)
//         return -1e8;

//     if (idx == 0)
//         return w / weight[0] * profit[0];

//     if (dp[idx][w] != w)
//         return dp[idx][w];

//     int take = profit[idx] + unboundedKnapsackmemo(idx, w - weight[idx], profit, weight, dp);
//     int nottake = unboundedKnapsackmemo(idx - 1, w, profit, weight, dp);

//     return dp[idx][w] = max(take, nottake);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>> dp(n, vector<int>(w + 1, -1));
//     return unboundedKnapsackmemo(n - 1, w, profit, weight, dp);
// }

// tabulation
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>> dp(n, vector<int>(w + 1, 0));

//     for (int i{0}; i <= w; i++)
//         dp[0][i] = i / weight[0] * profit[0];

//     for (int i{1}; i < n; i++)
//     {
//         for (int j{1}; j <= w; j++)
//         {
//             int take = 0;
//             if (j >= weight[i])
//                 take = profit[i] + dp[i][j - weight[i]];

//             dp[i][j] = max(take, dp[i - 1][j]);
//         }
//     }

//     return dp[n - 1][w];
// }

// tabulation space optimized
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);

    for (int i{0}; i <= w; i++)
        prev[i] = i / weight[0] * profit[0];

    for (int i{1}; i < n; i++)
    {
        for (int j{1}; j <= w; j++)
        {
            int take = 0;
            if (j >= weight[i])
                take = profit[i] + prev[j - weight[i]];

            prev[j] = max(take, prev[j]);
        }
    }

    return prev[w];
}
