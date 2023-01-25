#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int findWaysmemo(vector<int> &num, int tar, int i, vector<vector<int>> &dp)
{
    if (tar < 0)
        return 0;
    if (i < 0)
        return tar == 0;

    if (dp[i][tar] != -1)
        return dp[i][tar];

    return dp[i][tar] = (findWaysmemo(num, tar - num[i], i - 1, dp) + findWaysmemo(num, tar, i - 1, dp)) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int tsum{0};
    tsum = accumulate(arr.begin(), arr.end(), 0);
    int tar = (tsum - d);
    if (tar % 2 || tar < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return findWaysmemo(arr, tar / 2, n - 1, dp);
}
