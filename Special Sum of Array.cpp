#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int specialSum(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i{0}; i < n; i++)
        sum += arr[i];

    // sum of digits of sum
    int ans = sum;
    while (ans >= 10)
    {
        ans = sumOfDigits(sum);
        sum = ans;
    }
   
    return ans;
}