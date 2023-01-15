#include <bits/stdc++.h>
using namespace std;

// recursive
// bool subsetSumToKrec(int n, int k, vector<int> &arr)
// {
//     if (k < 0)
//         return false;
//     if (k == 0)
//         return true;
//     if (n == 0)
//         return arr[n] == k;

//     return subsetSumToKrec(n - 1, k, arr) || subsetSumToKrec(n - 1, k - arr[n], arr);
// }

// bool subsetSumToK(int n, int k, vector<int> &arr)
// {
//     return subsetSumToKrec(n - 1, k, arr);
// }

// memoization
// bool subsetSumToKMemo(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (k < 0)
//         return false;
//     if (k == 0)
//         return true;
//     if (n == 0)
//         return arr[n] == k;

//     if (dp[n][k] != -1)
//         return dp[n][k];

//     return dp[n][k] = subsetSumToKMemo(n - 1, k, arr, dp) || subsetSumToKMemo(n - 1, k - arr[n], arr, dp);
// }

// bool subsetSumToK(int n, int k, vector<int> &arr)
// {
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return subsetSumToKMemo(n - 1, k, arr, dp);
// }

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i{0}; i <= k; i++)
        dp[0][i] = arr[0] == i;

    for (int i{0}; i < n; i++)
        dp[i][0] = 1;

    for (int i{1}; i < n; i++)
        for (int j{1}; j < k + 1; j++)
        {
            bool take = false;
            if (j - arr[i] >= 0)
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take || dp[i - 1][j];
        }
    return dp[n - 1][k];
}

// tabulation space optimized
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int> prev(k + 1, 0);
    prev[0] = 1;
    for (int i{1}; i <= k; i++)
        prev[i] = arr[0] == i;

    for (int i{1}; i < n; i++)
    {
        vector<int> curr(k + 1, 0);
        for (int j{1}; j < k + 1; j++)
        {
            bool take = false;
            if (j - arr[i] >= 0)
                take = prev[j - arr[i]];

            curr[j] = take || prev[j];
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    int n{0}, k{0};
    cin >> n >> k;
    vector<int> arr(n);
    for (int i{0}; i < n; i++)
        cin >> arr[i];

    cout << subsetSumToK(n, k, arr);
}