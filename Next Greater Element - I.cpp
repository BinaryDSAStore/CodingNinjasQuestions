#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    stack<int> s;
    for (int i = 0; i < m; i++)
    {
        while (!s.empty() && s.top() < B[i])
        {
            mp[s.top()] = B[i];
            s.pop();
        }
        s.push(B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.find(A[i]) != mp.end())
            ans.push_back(mp[A[i]]);
        else
            ans.push_back(-1);
    }
    return ans;
}