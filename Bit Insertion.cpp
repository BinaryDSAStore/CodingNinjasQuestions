#include <bits/stdc++.h>
using namespace std;

vector<int> intintobinary(int n)
{
    vector<int> ans;
    while (n)
    {
        ans.push_back(n % 2);
        n /= 2;
    }
    while (ans.size() < 32)
        ans.push_back(0);

    // reverse(ans.begin(), ans.end());
    return ans;
}

int binarytoint(vector<int> &bin)
{
    int ans = 0;
    for (int i = 0; i < bin.size(); i++)
        ans += bin[i] * pow(2, bin.size() - i - 1);

    return ans;
}

int bitInsertion(int x, int y, int a, int b)
{
    vector<int> xbin = intintobinary(x);
    vector<int> ybin = intintobinary(y);


    cout << "xbin: ";
    for (int i = 0; i < xbin.size(); i++)
        cout << xbin[i] << " ";
    cout << endl;
    cout << "ybin: ";
    for (int i = 0; i < ybin.size(); i++)
        cout << ybin[i] << " ";
    cout << endl;

    int j = 0;
    for (int i = a; i <= b; i++)
    {
        cout << "i: " << xbin[i] << " j: " << j << endl;
        xbin[i] = ybin[j++];
    }

    cout << "xbin: ";
    for (int i = 0; i < xbin.size(); i++)
        cout << xbin[i] << " ";
    cout << endl;

    reverse(xbin.begin(), xbin.end());

    return binarytoint(xbin);
}

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << bitInsertion(x, y, a, b) << endl;
    return 0;
}