#include <bits/stdc++.h>
using namespace std;

int stringBreakerrec(string s, unordered_map<string, int> &dict, int prev, int idx)
{
    int n = s.length();
    if (idx >= n)
        return 0;

    cout << idx << " " << prev;
    int res = 1e8;
    for (int i{idx}; i < n; i++)
    {
        string st = s.substr(prev, idx - prev);
        if (dict[st])
        {
            int temp = stringBreakerrec(s, dict, idx, idx + 1);
            res = min(temp, res);
        }
    }

    return res;
}

int stringBreaker(string s, int n, vector<string> dictionary)
{
    unordered_map<string, int> dict;

    for (auto i : dictionary)
        dict[i] = 1;

    int ans = stringBreakerrec(s, dict, 0, 1);
    return ans >= 1e8 ? -1 : ans;
}