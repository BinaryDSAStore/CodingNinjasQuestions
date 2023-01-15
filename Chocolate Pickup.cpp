#include <bits/stdc++.h>
using namespace std;

// recursive
// int maximumChocolatesrec(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
// {
//     if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
//         return -1e8;

//     if (i == r - 1)
//         return j1 == j2 ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);

//     int ans = INT_MIN;

//     for (int k{-1}; k < 2; k++)
//     {
//         for (int j{-1}; j < 2; j++)
//         {
//             int temp{0};
//             temp = j1 == j2 ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
//             temp += maximumChocolatesrec(i + 1, j1 + k, j2 + j, r, c, grid);
//             ans = max(temp, ans);
//         }
//     }

//     return ans;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     return maximumChocolatesrec(0, 0, c-1, r, c, grid);
// }

// memoization
// int maximumChocolatesmemo(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
// {
//     if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
//         return -1e8;

//     if (i == r - 1)
//         return j1 == j2 ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);

//     if (dp[i][j1][j2] != -1)
//         return dp[i][j1][j2];

//     int ans = INT_MIN;

//     for (int k{-1}; k < 2; k++)
//     {
//         for (int j{-1}; j < 2; j++)
//         {
//             int temp{0};
//             temp = j1 == j2 ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
//             temp += maximumChocolatesmemo(i + 1, j1 + k, j2 + j, r, c, grid, dp);
//             ans = max(temp, ans);
//         }
//     }

//     return dp[i][j1][j2] = ans;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
//     return maximumChocolatesmemo(0, 0, c - 1, r, c, grid, dp);
// }

// tabulation
// int maximumChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

//     for (int m{0}; m < c; m++)
//         for (int n{0}; n < c; n++)
//             dp[r - 1][m][n] = m == n ? grid[r - 1][m] : (grid[r - 1][m] + grid[r - 1][n]);

//     for (int l{r - 2}; l >= 0; l--)
//         for (int m{0}; m < c; m++)
//             for (int n{0}; n < c; n++)
//             {
//                 int ans{0};
//                 for (int k{-1}; k < 2; k++)
//                 {
//                     for (int j{-1}; j < 2; j++)
//                     {
//                         int temp{0};
//                         temp = m == n ? grid[l][m] : (grid[l][m] + grid[l][n]);
//                         if ((m + k) < c && (m + k) >= 0 && (n + j) < c && (n + j) >= 0)
//                             temp += dp[l + 1][m + k][n + j];
//                         else
//                             temp += -1e8;
//                         ans = max(temp, ans);
//                     }
//                 }
//                 dp[l][m][n] = ans;
//             }

//     return dp[0][0][c - 1];
// }

// tabulation space optimized

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  vector<vector<int>> prev(c, vector<int>(c, 0));

  for (int m{0}; m < c; m++)
    for (int n{0}; n < c; n++)
      prev[m][n] = m == n ? grid[r - 1][m] : (grid[r - 1][m] + grid[r - 1][n]);

  for (int l{r - 2}; l >= 0; l--)
  {
    vector<vector<int>> curr(c, vector<int>(c, 0));
    for (int m{0}; m < c; m++)
    {
      for (int n{0}; n < c; n++)
      {
        int ans{0};
        for (int k{-1}; k < 2; k++)
        {
          for (int j{-1}; j < 2; j++)
          {
            int temp{0};
            temp = m == n ? grid[l][m] : (grid[l][m] + grid[l][n]);
            if ((m + k) >= c || (m + k) < 0 || (n + j) >= c || (n + j) < 0)
              temp += -1e9;
            else
              temp += prev[m + k][n + j];
            ans = max(temp, ans);
          }
        }
        curr[m][n] = ans;
      }
    }
    prev = curr;
  }

  return prev[0][c - 1];
}