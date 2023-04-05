#include <bits/stdc++.h>
using namespace std;

// Algorithm :

// Make a constant PI = 3.1415927
// If n=1, we just check if r<=R holds true.
// If it holds true, we return true. else, we return false.
// Store the value of r / ( R- r ) in a double variable “angle”.
// Initialize “sineValue” as Math.asin ( angle ).
// Multiply the “sineValue” by n
// Check if “sinValue” <= PI
// If the above equation holds true, return true. else return false.

bool countPlatesOnTable(int n, int R, int r)
{
    if (n == 1)
        return (r <= R);

    double angle = (double)r / (R - r);
    double sineValue = asin(angle);
    sineValue *= n;
    if (sineValue <= 3.1415927)
        return true;
    else
        return false;
}