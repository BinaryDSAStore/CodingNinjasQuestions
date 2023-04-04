#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// recursive
int maximizeScorerec(vector<int> &arr, int st, int en, int k)
{
    if (k == 0)
        return 0;

    int ans = INT_MIN;
    int takest = arr[st] + maximizeScorerec(arr, st + 1, en, k - 1);
    int takeen = arr[en] + maximizeScorerec(arr, st, en - 1, k - 1);

    return max(takest, takeen);
}

int maximizeScore(vector<int> &arr, int n, int k)
{
    return maximizeScorerec(arr, 0, n - 1, k);
}

// Memoization

int maximizeScorememo(vector<int> &arr, int st, int en, int k, vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 0;

    if (dp[st][en][k] != -1)
        return dp[st][en][k];

    int ans = 0;
    int takest = arr[st] + maximizeScorememo(arr, st + 1, en, k - 1, dp);
    int takeen = arr[en] + maximizeScorememo(arr, st, en - 1, k - 1, dp);

    return dp[st][en][k] = max(takest, takeen);
}

int maximizeScore(vector<int> &arr, int n, int k)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    return maximizeScorememo(arr, 0, n - 1, k, dp);
}

