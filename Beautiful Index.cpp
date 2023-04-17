#include <bits/stdc++.h>
using namespace std;

int beautifulIndex(int N, vector<int> A)
{
    vector<int> left(N, 0);
    vector<int> right(N, 0);

    left[0] = A[0];

    for (int i = 1; i < N; ++i)
        left[i] = left[i - 1] + A[i];

    right[N - 1] = A[N - 1];

    for (int i = N - 2; i >= 0; --i)
        right[i] = right[i + 1] + A[i];

    for (int i = 0; i < N; ++i)
        if (left[i] == right[i])
            return i;
    
    return -1;
}