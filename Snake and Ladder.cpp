#include <bits/stdc++.h>
using namespace std;

int minDiceThrowToLastCell(int **board, int n)
{
    vector<int> value(n * n);
    int index = 0;
    bool alr = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (alr)
            for (int j = 0; j < n; j++)
                value[index++] = board[i][j];
        else
            for (int j = n - 1; j >= 0; j--)
                value[index++] = board[i][j];
        alr = !alr;
    }
    vector<int> step(n * n, -1);
    queue<int> q;
    q.push(0);
    step[0] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == n * n - 1)
            return step[curr];

        for (int i = 1; i <= 6; i++)
        {
            int next = curr + i;
            if (next >= n * n)
                continue;
            if (value[next] != -1)
                next = value[next] - 1;
            if (step[next] == -1)
            {
                step[next] = step[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}