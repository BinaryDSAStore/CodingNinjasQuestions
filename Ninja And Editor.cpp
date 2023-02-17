#include <bits/stdc++.h>
using namespace std;

string editSentence(string &str)
{
    string ans = "";
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (i != 0)
                ans += " ";
            ans += str[i] + 32;
        }
        else
            ans += str[i];
    }
    return ans;
}

int main()
{
    string str = "CodingNinjasIsACodingPlatform";

    cout << editSentence(str);
}