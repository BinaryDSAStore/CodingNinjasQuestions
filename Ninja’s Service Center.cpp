#include<bits/stdc++.h>
using namespace std;

double positionForCentre(vector<vector<double> > location, int N)
{
    double x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        x += location[i][0];
        y += location[i][1];
    }
    return sqrt(x * x + y * y);
}