#include <bits/stdc++.h>
using namespace std;

// recursive
int minimumPathSumrec(vector<vector<int>> &triangle, int n, int i)
{
    if (n == triangle.size() - 1)
        return triangle[n][i];

    int down = minimumPathSumrec(triangle, n + 1, i);
    int downRight = minimumPathSumrec(triangle, n + 1, i + 1);

    cout << down << " " << downRight << endl;

    return triangle[n][i] + min(down, downRight);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return minimumPathSumrec(triangle, 0, 0);
}

// memoization
int minimumPathSummemo(vector<vector<int>> &triangle, int n, int i, vector<vector<int>> &dp)
{
    if (n == triangle.size() - 1)
        return triangle[n][i];

    if (dp[n][i] != -1)
        return dp[n][i];

    int down = minimumPathSummemo(triangle, n + 1, i, dp);
    int downRight = minimumPathSummemo(triangle, n + 1, i + 1, dp);

    return dp[n][i] = triangle[n][i] + min(down, downRight);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minimumPathSummemo(triangle, 0, 0, dp);
}

// tabulation
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        dp[n - 1][i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);

    return dp[0][0];
}

// tabulation space optimized
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n, -1);

    for (int i = 0; i < n; i++)
        dp[i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);

    return dp[0];
}

// iterative
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);

    return triangle[0][0];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    cout << minimumPathSum(triangle, n) << endl;
    return 0;
}