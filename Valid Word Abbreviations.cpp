#include <bits/stdc++.h>
using namespace std;

bool validAbbreviation(string &word, string &abbr)
{
    int count = 0;
    int i = 0, j = 0;
    for (; i < abbr.length() && j < word.length(); i++)
    {
        if (abbr[i] >= '0' && abbr[i] <= '9')
        {
            if (count == 0 && abbr[i] == '0')
                return false;
            count = count * 10 + (abbr[i] - '0');
        }
        else
        {
            if (count != 0)
            {
                j = j + count;
                count = 0;
            }
            if (j >= word.length() || abbr[i] != word[j])
                return false;

            j++;
        }
    }

    return i == abbr.length() && j + count == word.length();
}