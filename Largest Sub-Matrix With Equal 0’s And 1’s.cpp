// C++ implementation to find largest area rectangular
// submatrix with equal number of 1's and 0's
#include <bits/stdc++.h>
using namespace std;

bool subArrWithSumZero(int arr[], int &start, int &end, int n)
{
    int sum[n];
    memset(sum, 0, sizeof(sum));
    unordered_map<int, int> um;
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum[i] == 0)
        {
            start = 0;
            end = i;
            maxLen = (i + 1);
        }

        else if (um.find(sum[i]) == um.end())
            um[sum[i]] = i;
        else
        {
            if (maxLen < (i - um[sum[i]]))
            {
                maxLen = (i - um[sum[i]]);
                start = um[sum[i]] + 1;
                end = i;
            }
        }
    }

    if (maxLen == 0)
        return false;
    return true;
}

int maxAreaRectWithSumZero(vector<vector<int>> mat, int row, int col)
{
    int temp[row], startRow, endRow;
    int maxArea = 0;
    for (int left = 0; left < col; left++)
    {
        memset(temp, 0, sizeof(temp));
        for (int right = left; right < col; right++)
        {
            for (int i = 0; i < row; i++)
                temp[i] += mat[i][right] ? 1 : -1;

            if (subArrWithSumZero(temp, startRow, endRow, row))
            {
                int area = (right - left + 1) * (endRow - startRow + 1);
                if (maxArea < area)
                    maxArea = area;
            }
        }
    }
    return maxArea;
}

// Driver program to test above
// int main()
// {
//     int mat[MAX_ROW][MAX_COL] = {{0, 0, 1, 1},
//                                  {0, 1, 1, 0},
//                                  {1, 1, 1, 0},
//                                  {1, 0, 0, 1}};
//     int row = 4, col = 4;
//     maxAreaRectWithSumZero(mat, row, col);
//     return 0;
// }
