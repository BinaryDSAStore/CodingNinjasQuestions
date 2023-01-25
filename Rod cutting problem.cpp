#include <bits/stdc++.h>
using namespace std;

// recursive
// int cutRodrec(vector<int> &price, int n, int idx)
// {
//     if (n < 0)
//         return -1e8;

//     if (idx == 0)
//         return n * price[0];

//     int take = price[idx] + cutRodrec(price, n - idx - 1, idx);
//     int nottake = cutRodrec(price, n, idx - 1);

//     return max(take, nottake);
// }

// int cutRod(vector<int> &price, int n)
// {
//     return cutRodrec(price, n, n - 1);
// }

// memoization
// int cutRodmemo(vector<int> &price, int n, int idx, vector<vector<int>> &dp)
// {
//     if (n < 0)
//         return -1e8;

//     if (idx == 0)
//         return n * price[0];

//     if (dp[idx][n] != -1)
//         return dp[idx][n];

//     int take = price[idx] + cutRodmemo(price, n - idx - 1, idx, dp);
//     int nottake = cutRodmemo(price, n, idx - 1, dp);

//     return dp[idx][n] = max(take, nottake);
// }

// int cutRod(vector<int> &price, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return cutRodmemo(price, n, n - 1, dp);
// }

// tabulation
// int cutRod(vector<int> &price, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, 0));

//     for (int i{0}; i <= n; i++)
//         dp[0][i] = i * price[0];

//     for (int i{1}; i < n; i++)
//     {
//         for (int j{1}; j <= n; j++)
//         {

//             int take = j - i - 1 >= 0 ? price[i] + dp[i][j - i - 1] : INT_MIN;
//             int nottake = dp[i - 1][j];

//             dp[i][j] = max(take, nottake);
//         }
//     }

//     // Dp Table
//     for (auto i : dp)
//     {
//         for (auto j : i)
//             cout << j << " ";
//         cout << endl;
//     }

//     return dp[n - 1][n];
// }

// tabulation space optimized
int cutRod(vector<int> &price, int n)
{
    // vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    vector<int> dp(n + 1, 0);

    for (int i{0}; i <= n; i++)
        dp[i] = i * price[0];

    for (int i{1}; i < n; i++)
    {
        for (int j{1}; j <= n; j++)
        {

            int take = j - i - 1 >= 0 ? price[i] + dp[j - i - 1] : INT_MIN;
            int nottake = dp[j];

            dp[j] = max(take, nottake);
        }
    }

    return dp[n];
}

int main()
{
    int n{0};
    cin >> n;
    vector<int> num(n);

    for (int i{0}; i < n; i++)
        cin >> num[i];

    cout << cutRod(num, n);
}