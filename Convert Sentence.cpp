#include <bits/stdc++.h>
using namespace std;

string covertSentence(string s)
{
    string ref[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"};
        
    int n = s.length();

    string ans = "";

    for (char i : s)
        ans += i == ' ' ? "0" : ref[i - 'a'];

    return ans;
}
