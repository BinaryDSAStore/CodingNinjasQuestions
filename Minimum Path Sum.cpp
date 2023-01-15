#include <bits/stdc++.h>
using namespace std;

// recursive
int minSumPath(int n, int m, vector<vector<int>> &grid)
{
    if (n == 0 && m == 0)
        return grid[n][m];
    if (n == 0)
        return minSumPath(n, m - 1, grid) + grid[n][m];
    if (m == 0)
        return minSumPath(n - 1, m, grid) + grid[n][m];
    int op1 = minSumPath(n - 1, m, grid);
    int op2 = minSumPath(n, m - 1, grid);
    return min(op1, op2) + grid[n][m];
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return minSumPath(n - 1, m - 1, grid);
}

// memoization
int minSumPathmem(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return dp[n][m] = grid[n][m];
    if (n == 0)
        return dp[n][m] = minSumPathmem(n, m - 1, grid, dp) + grid[n][m];
    if (m == 0)
        return dp[n][m] = minSumPathmem(n - 1, m, grid, dp) + grid[n][m];
    if (dp[n][m] != -1)
        return dp[n][m];
    int op1 = minSumPathmem(n - 1, m, grid, dp);
    int op2 = minSumPathmem(n, m - 1, grid, dp);
    return dp[n][m] = min(op1, op2) + grid[n][m];
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSumPathmem(n - 1, m - 1, grid, dp);
}

// tabulation
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            int op1 = dp[i - 1][j];
            int op2 = dp[i][j - 1];
            dp[i][j] = min(op1, op2) + grid[i][j];
        }
    return dp[n - 1][m - 1];
}

// tabulation space optimized
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m, 0);
    dp[0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[i] = dp[i - 1] + grid[0][i];
    for (int i = 1; i < n; i++)
    {
        dp[0] += grid[i][0];
        for (int j = 1; j < m; j++)
        {
            int op1 = dp[j];
            int op2 = dp[j - 1];
            dp[j] = min(op1, op2) + grid[i][j];
        }
    }
    return dp[m - 1];
}   

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << minSumPath(grid) << endl;
}