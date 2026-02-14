/**
 * Problem: Binary Exponentiation (Fast Power)
 * Compute a^x efficiently using the binary representation of the exponent.
 * Squares the base and halves the exponent at each step.
 * Time Complexity: O(log x)
 * Space Complexity: O(1)
 */
#include <iostream>

using namespace std;

void binaryExponentiation(int a, int x)
{
    int res = 1;
    while (x)
    {
        if (x & 1)
            res = res * a;
        a = a * a;
        x = x >> 1;
    }
    cout << res << endl;
}