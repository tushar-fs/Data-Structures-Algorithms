#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double medianOfMatrix(vector<vector<int>> &a)
{
    // find median in row-wise sorted matrix
    int n = a.size();
    int m = a[0].size();
    int total = n * m;

    int medianPos = (total + 1) / 2;

    int low = INT_MAX, high = INT_MIN, firstMed;
    for (int i = 0; i < m; i++)
    {
        low = min(low, a[i][0]);
        high = max(high, a[i][m - 1]);
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 1;
        // find count of elements <= mid
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
        }

        if (count < medianPos)
            low = mid + 1;
        else
        {
            firstMed = mid;
            high = mid - 1;
        }
    }

    if (total & 1)
        return low;
    else
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += upper_bound(a[i].begin(), a[i].end(), firstMed) - a[i].begin();
        }
        if (count >= medianPos + 1)
            return (firstMed + firstMed) / 2.0;
        int secondMedian = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(a[i].begin(), a[i].end(), firstMed);
            if (it != a[i].end())
            {
                secondMedian = min(secondMedian, *it);
            }
        }
        return (firstMed + secondMedian) / 2.0;
    }
}

int main()
{
    // driver code;
    return 0;
}