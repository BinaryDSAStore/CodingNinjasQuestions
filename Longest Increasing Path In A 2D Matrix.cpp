#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int top;
    if (i - 1 < 0 || matrix[i - 1][j] <= matrix[i][j])
        top = 1;
    else
        top = 1 + dfs(matrix, i - 1, j, dp);

    int bot;
    if (i + 1 >= matrix.size() || matrix[i + 1][j] <= matrix[i][j])
        bot = 1;
    else
        bot = 1 + dfs(matrix, i + 1, j, dp);
    int left;
    if (j - 1 < 0 || matrix[i][j - 1] <= matrix[i][j])
        left = 1;
    else
        left = 1 + dfs(matrix, i, j - 1, dp);

    int right;
    if (j + 1 >= matrix[0].size() || matrix[i][j + 1] <= matrix[i][j])
        right = 1;
    else
        right = 1 + dfs(matrix, i, j + 1, dp);

    dp[i][j] = max(max(left, right), max(top, bot));
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ret = 0;
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ret = max(ret, dfs(mat, i, j, dp));

    return ret;
}