#include <bits/stdc++.h>
using namespace std;

int *immediateSmaller(int *arr, int n)
{
    int *ans = new int[n];
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
            ans[i] = arr[i + 1];
        else
            ans[i] = -1;
    }
    ans[n - 1] = -1;
    return ans;
}