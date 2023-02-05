#include <bits/stdc++.h>
using namespace std;

vector<int> numsSameConsecDiff(int N, int K)
{
    vector<int> dp[N + 1];
    for (int i = 1; i <= 9; i++)
    {
        dp[1].push_back(i);
    }
    for (int i = 1; i < N; i++)
    {
        set<int> visited;
        for (int j = 0; j < dp[i].size(); j++)
        {
            int x = dp[i][j];
            int lastNum = x % 10;
            int digit = lastNum + K;
            if (digit >= 0 && digit <= 9 && !visited.count(x * 10 + digit))
            {
                dp[i + 1].push_back(x * 10 + digit);
                visited.insert(x * 10 + digit);
            }
            digit = lastNum - K;
            if (digit >= 0 && digit <= 9 && !visited.count(x * 10 + digit))
            {
                dp[i + 1].push_back(x * 10 + digit);
                visited.insert(x * 10 + digit);
            }
        }
    }
    if (N == 1)
    {
        dp[N].push_back(0);
    }
    return dp[N];
}