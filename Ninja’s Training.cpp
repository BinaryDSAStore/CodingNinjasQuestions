#include <bits/stdc++.h>
using namespace std;

// recursive solution
// int ninjaTrainingrec(int n, int last, vector<vector<int>> &points)
// {
//     if (n == 0)
//         return max(points[n][0], max(points[n][1], points[n][2]));
//     int ans = 0;
//     if (last == 0)
//         ans = max(ninjaTrainingrec(n - 1, 1, points) + points[n][1], ninjaTrainingrec(n - 1, 2, points) + points[n][2]);
//     if (last == 1)
//         ans = max(ninjaTrainingrec(n - 1, 0, points) + points[n][0], ninjaTrainingrec(n - 1, 2, points) + points[n][2]);
//     if (last == 2)
//         ans = max(ninjaTrainingrec(n - 1, 0, points) + points[n][0], ninjaTrainingrec(n - 1, 1, points) + points[n][1]);
//     return ans;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     int ans = 0;
//     for (int i = 0; i < 3; i++)
//         ans = max(ans, ninjaTrainingrec(n - 2, i, points) + points[n-1][i]);
    
//     return ans;
// }

// memoization solution
// int ninjaTrainingmemo(int n, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
// {
//     if (n == 0)
//         return max(points[n][0], max(points[n][1], points[n][2]));
//     if (dp[n][last] != -1)
//         return dp[n][last];
//     int ans = 0;
//     if (last == 0)
//         ans = max(ninjaTrainingmemo(n - 1, 1, points, dp) + points[n][1], ninjaTrainingmemo(n - 1, 2, points, dp) + points[n][2]);
//     if (last == 1)
//         ans = max(ninjaTrainingmemo(n - 1, 0, points, dp) + points[n][0], ninjaTrainingmemo(n - 1, 2, points, dp) + points[n][2]);
//     if (last == 2)
//         ans = max(ninjaTrainingmemo(n - 1, 0, points, dp) + points[n][0], ninjaTrainingmemo(n - 1, 1, points, dp) + points[n][1]);
//     return dp[n][last] = ans;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(3, -1));
//     int ans = 0;
//     for (int i = 0; i < 3; i++)
//         ans = max(ans, ninjaTrainingmemo(n - 2, i, points, dp) + points[n-1][i]);
    
//     return ans;
// }

// tabulation solution
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(3, -1));
//     for (int i = 0; i < 3; i++)
//         dp[0][i] = points[0][i];
//     for (int i = 1; i < n; i++)
//     {
//         dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + points[i][0];
//         dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + points[i][1];
//         dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + points[i][2];
//     }
//     int ans = 0;
//     for (int i = 0; i < 3; i++)
//         ans = max(ans, dp[n - 1][i]);
//     return ans;
// }

// tabulation solution space optimized

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(3, -1);
    for (int i = 0; i < 3; i++)
        dp[i] = points[0][i];
    for (int i = 1; i < n; i++)
    {
        int a = dp[0];
        int b = dp[1];
        int c = dp[2];
        dp[0] = max(b, c) + points[i][0];
        dp[1] = max(a, c) + points[i][1];
        dp[2] = max(a, b) + points[i][2];
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[i]);
    return ans;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << ninjaTraining(n, points) << endl;
    return 0;
}