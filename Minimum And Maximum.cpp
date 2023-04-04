#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(int a, int b)
{
    int max = (a + b + abs(a - b)) / 2;
    int min = (a + b - abs(a - b)) / 2;

    return {min, max};
}