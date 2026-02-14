#include <iostream>

using namespace std;

/**
 * Binary Exponentiation is an algorithm through which we can find
 * exponentiation of a number in log(n) time complexity.
 */

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