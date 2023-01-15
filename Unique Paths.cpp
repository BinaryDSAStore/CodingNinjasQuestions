#include <bits/stdc++.h>
using namespace std;

// recursive solution
// int uniquePaths(int m, int n)
// {
//     if (m == 1 || n == 1)
//         return 1;
//     return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
// }

// memoization solution
// int uniquePathsmemo(int m, int n, vector<vector<int>> &dp)
// {
//     if (m == 1 || n == 1)
//         return 1;
//     if (dp[m][n] != -1)
//         return dp[m][n];
//     return dp[m][n] = uniquePathsmemo(m - 1, n, dp) + uniquePathsmemo(m, n - 1, dp);
// }

// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     return uniquePathsmemo(m, n, dp);
// }

// tabulation solution
// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     for (int i = 1; i <= m; i++)
//         dp[i][1] = 1;
//     for (int i = 1; i <= n; i++)
//         dp[1][i] = 1;
//     for (int i = 2; i <= m; i++)
//         for (int j = 2; j <= n; j++)
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//     return dp[m][n];
// }

// tabulation solution space optimized
// int uniquePaths(int m, int n)
// {
//     vector<int> dp(n + 1, 1);
//     for (int i = 2; i <= m; i++)
//         for (int j = 2; j <= n; j++)
//             dp[j] += dp[j - 1];
//     return dp[n];
// }

//Formula solution
int uniquePaths(int m, int n)
{
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}