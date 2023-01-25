#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// recursive
// int subsequenceCountingrec(string &t, string &s, int idxt, int idxs)
// {

//     if (idxs < 0)
//         return 1;
//     if (idxt < 0)
//         return 0;

//     if (t[idxt] == s[idxs])
//         return (subsequenceCountingrec(t, s, idxt - 1, idxs - 1) + subsequenceCountingrec(t, s, idxt - 1, idxs)) % mod;
//     return subsequenceCountingrec(t, s, idxt - 1, idxs) % mod;
// }

// int subsequenceCounting(string &t, string &s, int lt, int ls)
// {
//     return subsequenceCountingrec(t, s, lt - 1, ls - 1);
// }

// memoization
// int subsequenceCountingmemo(string &t, string &s, int idxt, int idxs, vector<vector<int>> &dp)
// {
//     if (idxs < 0)
//         return 1;
//     if (idxt < 0)
//         return 0;

//     if (dp[idxt][idxs] != -1)
//         return dp[idxt][idxs];

//     if (t[idxt] == s[idxs])
//         return (subsequenceCountingmemo(t, s, idxt - 1, idxs - 1, dp) + subsequenceCountingmemo(t, s, idxt - 1, idxs, dp)) % mod;
//     return subsequenceCountingmemo(t, s, idxt - 1, idxs, dp) % mod;
// }

// int subsequenceCounting(string &t, string &s, int lt, int ls)
// {
//     vector<vector<int>> dp(lt, vector<int>(ls, -1));
//     return subsequenceCountingmemo(t, s, lt - 1, ls - 1, dp);
// }

// tabulation
// int subsequenceCounting(string &t, string &s, int lt, int ls)
// {
//     vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));
//     for (int i{0}; i <= lt; i++)
//         dp[i][0] = 1;
//     for (int i{1}; i <= lt; i++)
//         for (int j{1}; j <= ls; j++)
//         {
//             if (t[i - 1] == s[j - 1])
//                 dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
//             else
//                 dp[i][j] = (dp[i - 1][j]) % mod;
//         }
//     return dp[lt][ls];
// }

// tabulation space optimized
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<int> dp(ls + 1);
    dp[0] = 1;
    for (int i{1}; i <= lt; i++)
        for (int j{ls}; j >= 1; j--)
            if (t[i - 1] == s[j - 1])
                dp[j] = (dp[j - 1] + dp[j]) % mod;

    return dp[ls];
}

int main()
{
    string a{""}, b{""};
    cin >> a;
    cin >> b;

    cout << subsequenceCounting(a, b, a.length(), b.length());
    return 0;
}
