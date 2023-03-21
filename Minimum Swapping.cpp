#include <bits/stdc++.h>
using namespace std;

int minimumSwap(vector<int> &arr, int n)
{
    int left = 0, right = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = right; i < n; i++)
    {
        if (arr[i] == 1)
        {
            int count = 0;
            for (int j = i - 1; j >= 0; j--)
                if (arr[j] == 0)
                    ans1++;
        }
    }

    left = right = n - 1;

    for (int i = right; i >= 0; i--)
    {
        if (arr[i] == 1)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
                if (arr[j] == 0)
                    ans2++;
        }
    }

    return min(ans1, ans2);
}

// Optimized Solution
