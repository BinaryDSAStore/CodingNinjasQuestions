#include <bits/stdc++.h>
using namespace std;

bool duplicateParanthesis(string &str)
{
    stack<char> val;
    for (char ch : str)
    {
        if (ch == ')')
        {
            char top = val.top();
            val.pop();
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = val.top();
                val.pop();
            }
            if (elementsInside < 1)
            {
                return true;
            }
        }
        else
            val.push(ch);
    }

    return false;
}