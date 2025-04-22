#include <iostream>
#include <vector>

using namespace std;

double sqrtOfNumber(int n, int precision)
{
    if (n <= 1)
        return n;
    int low = 1, high = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (mid <= n / mid) // to avoid overflow
            low = mid + 1;
        else
            high = mid;
    }

    double sqrt = high - 1; // floor if not perfect square
    double increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (sqrt * sqrt < n)
        {
            sqrt += increment;
        }
        if (sqrt * sqrt > n)
            sqrt -= increment;
        increment /= 10;
    }
    return sqrt;
}

int main()
{
    return 0;
}