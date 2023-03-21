#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int N, int K)
{
    if (K == 0)
    {
        if (N == 1)
            return "0";
        else
            return "-1";
    }

    if (K > 9 * N)
        return "-1";

    string answer = "";
    K--;
    for (int i = N - 1; i >= 1; i--)
    {
        if (K >= 9)
        {
            answer += '9';
            K -= 9;
        }
        else
        {
            answer += to_string(K);
            K = 0;
        }
    }
    answer += to_string(K + 1);
    reverse(answer.begin(), answer.end());
    return answer;
}