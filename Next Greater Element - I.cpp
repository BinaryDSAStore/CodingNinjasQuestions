#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B)
{
    map<int, int> mp;

    for (int i = 0; i < n; ++i)
        mp[A[i]] = i;

    stack<int> st;
    st.push(-1);

    for (int i = m - 1; i >= 0; i--)
    {

        if (mp.find(B[i]) == mp.end())
        {
            st.push(B[i]);
            continue;
        }

        if (st.top() >= B[i])
        {
            int index = mp[B[i]];
            A[index] = st.top();
            st.push(B[i]);
        }
        else
        {
            while (st.top() != -1 and st.top() <= B[i])
                st.pop();

            int index = mp[B[i]];
            A[index] = st.top();
            st.push(B[i]);
        }
    }

    return A;
}