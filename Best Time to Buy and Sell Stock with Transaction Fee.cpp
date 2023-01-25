#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int> &prices)
{
    int prev0{0}, prev1{0}, curr0{0}, curr1{0};
    for (int i{n - 1}; i >= 0; i--)
    {
        curr1 = max(-prices[i] + prev0, prev1);
        curr0 = max(prices[i] + prev1 - fee, prev0);
        prev0 = curr0;
        prev1 = curr1;
    }
    return prev1;
}
