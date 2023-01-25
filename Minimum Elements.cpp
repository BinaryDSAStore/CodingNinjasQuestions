#include <bits/stdc++.h>
using namespace std;

// recursive
// int minimumElementsrec(vector<int> &num, int x, int idx)
// {
//     if (x == 0)
//         return 0;
//     if (idx == num.size())
//         return 1e8;
//     int take = 1e8, nottake = 1e8;
//     if (x >= num[idx])
//         take = 1 + minimumElementsrec(num, x - num[idx], idx);
//     nottake = minimumElementsrec(num, x, idx + 1);
//     return min(take, nottake);
// }

// int minimumElements(vector<int> &num, int x)
// {
//     int ans = minimumElementsrec(num, x, 0);
//     return ans >= 1e8 ? -1 : ans;

// }

// memoization
// int minimumElementsmemo(vector<int> &num, int x, int idx, vector<vector<int>> &dp)
// {
//     if (x == 0)
//         return 0;
//     if (idx == num.size())
//         return 1e8;

//     if (dp[idx][x] != -1)
//         return dp[idx][x];

//     int take = 1e8, nottake = 1e8;
//     if (x >= num[idx])
//         take = 1 + minimumElementsmemo(num, x - num[idx], idx, dp);
//     nottake = minimumElementsmemo(num, x, idx + 1, dp);
//     return dp[idx][x] = min(take, nottake);
// }

// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(x+1, -1));
//     int ans = minimumElementsmemo(num, x, 0, dp);
//     return ans >= 1e8 ? -1 : ans;
// }

// tabulation
// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(x + 1, 0));

//     for (int i{0}; i < x + 1; i++)
//         dp[n - 1][i] = i % num[n - 1] ? 1e8 : i / num[n - 1];

//     for (int idx{n - 2}; idx >= 0; idx--)
//     {
//         for (int j{1}; j <= x; j++)
//         {
//             int take = 1e8, nottake = 1e8;
//             if (j >= num[idx])
//                 take = 1 + dp[idx][j - num[idx]];
//             nottake = dp[idx + 1][j];

//             dp[idx][j] = min(take, nottake);
//         }
//     }

//     // Dp Table
//     //  for (auto i : dp)
//     //  {
//     //      for (auto j : i)
//     //          cout << j << " ";
//     //      cout << endl;
//     //  }

//     return dp[0][x] >= 1e8 ? -1 : dp[0][x];
// }

// tabulation space optimized
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, 0);

    for (int i{0}; i < x + 1; i++)
        prev[i] = i % num[n - 1] ? 1e8 : i / num[n - 1];

    for (int idx{n - 2}; idx >= 0; idx--)
    {
        vector<int> curr(x + 1, 0);
        for (int j{1}; j <= x; j++)
        {
            int take = 1e8, nottake = 1e8;
            if (j >= num[idx])
                take = 1 + curr[j - num[idx]];
            nottake = prev[j];

            curr[j] = min(take, nottake);
        }
        prev = curr;
    }

    return prev[x] >= 1e8 ? -1 : prev[x];
}

int main()
{
    int n{0}, x{0};
    cin >> n >> x;
    vector<int> num(n);

    for (int i{0}; i < n; i++)
        cin >> num[i];

    cout << minimumElements(num, x);
}