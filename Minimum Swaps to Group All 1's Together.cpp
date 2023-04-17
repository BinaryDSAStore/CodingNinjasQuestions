#include <bits/stdc++.h>
using namespace std;

int groupAllOneTogether(vector<int> &nums, int n)
{
    int count_1 = 0;

    for (int i = 0; i < n; i++)
        if (nums[i])
            count_1++;

    if (count_1 == 0)
        return 0;

    vector<int> double_arr = nums;
    for (int i = 0; i < n; i++)
        double_arr.push_back(nums[i]);

    int maxi = 0;
    int count = 0;
    for (int i = 0; i < double_arr.size(); i++)
    {
        if (i < count_1)
        {
            if (double_arr[i])
                count++;
        }
        else
        {
            maxi = max(maxi, count);

            if (double_arr[i - count_1])
                count--;

            if (double_arr[i])
                count++;
        }
    }

    maxi = max(maxi, count);
    return count_1 - maxi;
}
