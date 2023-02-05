#include <bits/stdc++.h>
using namespace std;

vector<string> digit = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
vector<string> tens = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string numToWords(int n, string s)
{
    string str = "";
    if (n > 19)
        str += tens[n / 10] + digit[n % 10];
    else
        str += digit[n];
    if (n)
        str += s;

    return str;
}

string handleAll(int n)
{
    string out;
    out += numToWords((n / 10000000), "crore ");
    out += numToWords(((n / 100000) % 100), "lakh ");
    out += numToWords(((n / 1000) % 100), "thousand ");
    out += numToWords(((n / 100) % 10), "hundred ");

    if (n > 100 && n % 100)
        out += "and ";
    out += numToWords((n % 100), "");
    if (out == "")
        out = "zero";

    return out;
}