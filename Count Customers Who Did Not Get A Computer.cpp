#include <bits/stdc++.h>
using namespace std;

int countCustomers(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ref(n + 1);
    int avco = k, ans{0};

    for (auto i : arr)
    {
        if (ref[i] == 0)
        {
            if (avco < 1)
                ref[i]--;
            else
                ref[i]++, avco--;
        }
        else if (ref[i] == 1)
        {
            ref[i] = -1;
            avco++;
        }
        else
            ans++;
    }
    return ans;
}