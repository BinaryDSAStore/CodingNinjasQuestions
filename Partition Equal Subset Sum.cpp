#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int> prev(k + 1, 0);
    prev[0] = 1;
    for (int i{1}; i <= k; i++)
        prev[i] = arr[0] == i;

    for (int i{1}; i < n; i++)
    {
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
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

bool canPartition(vector<int> &arr, int n)
{
    int sum{0};
    for (int i{0}; i < n; i++)
        sum += arr[i];

    if (sum % 2)
        return false;

    return subsetSumToK(n, sum / 2, arr);
}