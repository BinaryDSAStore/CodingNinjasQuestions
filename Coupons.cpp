#include <bits/stdc++.h>
using namespace std;

int pickCoupons(int n, vector<int> &coupons)
{
    unordered_map<int, vector<int>> freq;

    for (int i = 0; i < n; i++)
        freq[coupons[i]].push_back(i);

    int ans = INT_MAX;

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second.size() == 1)
            continue;

        int minDiff = INT_MAX;
        for (int i = 0; i < it->second.size() - 1; i++)
            minDiff = min(minDiff, it->second[i + 1] - it->second[i]);

        ans = min(ans, minDiff);
    }

    if (ans == INT_MAX)
        return -1;

    return ans + 1;
}
