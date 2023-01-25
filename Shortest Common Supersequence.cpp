#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string a, string b)
{
    int len1 = a.length(), len2 = b.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i{1}; i <= len1; i++)
        for (int j{1}; j <= len2; j++)
            dp[i][j] = a[i - 1] == b[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);

    int len = dp[len1][len2] - 1;
    string ans = "";

    while (len1 > 0 && len2 > 0)
    {
        if (a[len1 - 1] == b[len2 - 1])
        {
            ans += a[len1 - 1];
            len1--, len2--, len--;
        }
        else if (dp[len1 - 1][len2] > dp[len1][len2 - 1])
        {
            ans += a[len1 - 1];
            len1--;
        }
        else
        {
            ans += b[len2 - 1];
            len2--;
        }
    }

    while (len1 > 0)
    {
        ans += a[len1 - 1];
        len1--;
    }
    while (len2 > 0)
    {
        ans += b[len2 - 1];
        len2--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a{""}, b{""};
    cin >> a;
    cin >> b;

    cout << shortestSupersequence(a, b);
    return 0;
}
