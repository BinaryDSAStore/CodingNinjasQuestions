#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int k{0};
    for (auto i : arr)
        k += i;

    vector<bool> prev(k + 1, false);
    prev[0] = true;
    for (int i{1}; i <= k; i++)
        prev[i] = arr[0] == i;

    for (int i{1}; i < n; i++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int j{1}; j < k + 1; j++)
        {
            bool take = false;
            if (j - arr[i] >= 0)
                take = prev[j - arr[i]];

            curr[j] = take || prev[j];
        }
        prev = curr;
    }

    int ans = INT_MAX;

    for (int i{0}; i <= k; i++)
    {
        if (prev[i])
        {
            int diff = abs(2 * i - k);
            ans = (diff, ans);
        }
    }

    return k ? ans : 0;
}