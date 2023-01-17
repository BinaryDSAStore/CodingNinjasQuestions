#include <bits/stdc++.h>
using namespace std;

// recursive
// int findWaysrec(vector<int> &num, int tar, int i)
// {
//     if (tar < 0)
//         return 0;
//     if (i < 0)
//         return tar == 0;

//     return findWaysrec(num, tar - num[i], i - 1) + findWaysrec(num, tar, i - 1);
// }

// int findWays(vector<int> &num, int tar)
// {
//     return findWaysrec(num, tar, num.size() - 1);
// }

// memoization
int findWaysmemo(vector<int> &num, int tar, int i, vector<vector<int>> &dp)
{
    if (tar < 0)
        return 0;
    if (i < 0)
        return tar == 0;

    if (dp[i][tar] != -1)
        return dp[i][tar];

    return dp[i][tar] = findWaysmemo(num, tar - num[i], i - 1, dp) + findWaysmemo(num, tar, i - 1, dp);
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return findWaysmemo(num, tar, num.size() - 1, dp);
}

// tabulation - not working
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//     for (int i{0}; i <= tar; i++)
//         dp[0][i] = num[0] == i;
//     for (int i{0}; i < n; i++)
//         dp[i][0] = 1;
//     for (int i{1}; i < n; i++)
//     {
//         for (int j{1}; j <= tar; j++)
//         {
//             dp[i][j] = dp[i - 1][j];
//             if (j - num[i] >= 0)
//                 dp[i][j] += dp[i - 1][j - num[i]];
//         }
//     }
//     for (int i{0}; i < n; i++)
//     {
//         for (int j{0}; j <= tar; j++)
//             cout << dp[i][j] << " ";
//         cout << endl;
//     }

//     return dp[n - 1][tar];
// }

int main()
{

    int n{0}, tar{0};
    cin >> n >> tar;
    vector<int> nums(n);
    for (int i{0}; i < n; i++)
        cin >> nums[i];

    cout << findWays(nums, tar);
}