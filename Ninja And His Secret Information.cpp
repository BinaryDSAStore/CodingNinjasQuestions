#include <bits/stdc++.h>
using namespace std;

string encode(string secretInformation)
{
    int n = secretInformation.length();
    string encodedInformation = "";
    for (int i = 0; i <= n; i += 2)
    {
        if (i + 1 < n)
            encodedInformation += secretInformation[i + 1];
        encodedInformation += secretInformation[i];
    }
    return encodedInformation;
}

string decode(string encodedInformation)
{
    int n = encodedInformation.length();
    string decodedInformation = "";
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
            decodedInformation += encodedInformation[i + 1];
        decodedInformation += encodedInformation[i];
    }
    return decodedInformation;
}

int main()
{
    string secretInformation;
    getline(cin, secretInformation);
    string encodedInformation = encode(secretInformation);
    cout << encodedInformation << endl;
    string decodedInformation = decode(encodedInformation);
    cout << decodedInformation << endl;
    return 0;
}