#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<int> row(n, 1), col(m, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }

    vector<vector<int>> ans(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row[i] == 0 || col[j] == 0)
                ans[i][j] = 0;

    return ans;
}
