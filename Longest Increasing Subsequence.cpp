#include <bits/stdc++.h>
using namespace std;

// recursive
int longestIncreasingSubsequencerec(int arr[], int n, int *max_ref)
{
    if (n == 1)
        return 1;
    int res, max_ending_here = 1;

    for (int i = 1; i < n; i++)
    {
        res = longestIncreasingSubsequencerec(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    return max_ending_here;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return longestIncreasingSubsequencerec(arr, n, 0);
}
