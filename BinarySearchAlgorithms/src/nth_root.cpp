/**
 * Problem: Find Nth Root of an Integer
 * Given two integers num and n, find the nth root of num. If it doesn't exist
 * as an integer, return -1. Uses binary search + binary exponentiation.
 *
 * Example: nthRoot(81, 4) → 3 (since 3^4 = 81)
 * Time Complexity: O(log(num) * log(n))
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

int binaryExponentiation(int a, int x)
{
    int res = 1;
    while (x > 0)
    {
        if (x & 1)
        {
            res = res * a;
        }
        a = a * a;
        x = x >> 1;
    }
    return res;
}

int nthRoot(int num, int n)
{
    if (num <= 1)
        return num;

    int low = 2, high = num;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1); // precedence left to right

        int nthSq = binaryExponentiation(mid, n);
        if (nthSq == num)
            return mid;
        else if (nthSq < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 81, m = 4;
    cout << nthRoot(81, 4); // o/p: 3
    return 0;
}