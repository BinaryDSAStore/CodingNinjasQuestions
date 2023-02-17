#include <bits/stdc++.h>
using namespace std;

void generateValidStrings(string str, int idx, string curr, int open, int close, int minRemoval, unordered_set<string> &result)
{
    if (idx == str.size())
    {
        if (minRemoval == 0)
            result.insert(curr);
        return;
    }
    if (str[idx] == '(')
    {
        generateValidStrings(str, idx + 1, curr + "(", open + 1, close, minRemoval, result);
        generateValidStrings(str, idx + 1, curr, open, close, minRemoval + 1, result);
    }
    else if (str[idx] == ')')
    {
        if (open > close)
            generateValidStrings(str, idx + 1, curr + ")", open, close + 1, minRemoval, result);
        generateValidStrings(str, idx + 1, curr, open, close, minRemoval + 1, result);
    }
    else
        generateValidStrings(str, idx + 1, curr + string(1, str[idx]), open, close, minRemoval, result);
}

vector<string> minRemovaltoMakeStringValid(string &str)
{
    unordered_set<string> result;
    generateValidStrings(str, 0, "", 0, 0, 0, result);

    return vector<string>(result.begin(), result.end());
}