#include <bits/stdc++.h>
using namespace std;

// recursive
// int knapsackrec(vector<int> &weight, vector<int> &value, int n, int maxWeight, int idx)
// {
//     if (idx == n || !maxWeight)
//         return 0;
//     int take{0}, nottake{0};
//     if (maxWeight >= weight[idx])
//         take = value[idx] + knapsackrec(weight, value, n, maxWeight - weight[idx], idx + 1);
//     nottake = knapsackrec(weight, value, n, maxWeight, idx + 1);
//     return max(take, nottake);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     return knapsackrec(weight, value, n, maxWeight, 0);
// }

// memoization
// int knapsackmemo(vector<int> &weight, vector<int> &value, int n, int maxWeight, int idx, vector<vector<int>> &dp)
// {
//     if (idx == n || !maxWeight)
//         return 0;
//     if (dp[idx][maxWeight] != -1)
//         return dp[idx][maxWeight];
//     int take{0},
//         nottake{0};
//     if (maxWeight >= weight[idx])
//         take = value[idx] + knapsackmemo(weight, value, n, maxWeight - weight[idx], idx + 1, dp);
//     nottake = knapsackmemo(weight, value, n, maxWeight, idx + 1, dp);
//     return dp[idx][maxWeight] = max(take, nottake);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
//     return knapsackmemo(weight, value, n, maxWeight, 0,dp);
// }

// tabulation
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
//     for (int idx{n - 1}; idx >= 0; idx--)
//     {
//         for (int j{1}; j < maxWeight + 1; j++)
//         {
//             int take{0}, nottake{0};
//             if (j >= weight[idx])
//                 take = value[idx] + dp[idx + 1][j - weight[idx]];
//             nottake = dp[idx + 1][j];
//             dp[idx][j] = max(take, nottake);
//         }
//     }
//     return dp[0][maxWeight];
// }

// tabulation space optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int idx{n - 1}; idx >= 0; idx--)
    {
        // vector<int> curr(maxWeight + 1, 0);
        for (int j{maxWeight}; j >= 0; j--)
        {
            int take{0}, nottake{0};

            if (j >= weight[idx])
                take = value[idx] + prev[j - weight[idx]];

            nottake = prev[j];

            prev[j] = max(take, nottake);
        }
        // prev = curr;
    }

    return prev[maxWeight];
}

int main()
{
    int n{0}, maxWeight{0};
    cin >> n;
    vector<int> weight(n), value(n);

    for (int i{0}; i < n; i++)
        cin >> weight[i];

    for (int i{0}; i < n; i++)
        cin >> value[i];

    cin >> maxWeight;

    cout << knapsack(weight, value, n, maxWeight);
}