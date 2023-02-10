#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &arr)
{
    int N = arr.size();
    int maxi = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int cnt = 1, j;
        for (j = i; j < N; j++)
        {
            if (arr[j + 1] == arr[j] + 1)
                cnt++;
            else
                break;
        }
        maxi = max(maxi, cnt);
        i = j;
    }
    return maxi;
}
