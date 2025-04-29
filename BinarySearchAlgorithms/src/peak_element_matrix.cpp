#include <iostream>
#include <vector>

using namespace std;

/**
 *
 * Given a 2D Array, find peak (greater than element at top down left & right)
 * All outside elements are -1.
 * TC -> O(nlogm)
 */

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxIndex = 0, maxi = mat[maxIndex][mid];
        for (int i = 0; i < n; i++)
        {
            if (maxi < mat[i][mid])
            {
                maxIndex = i;
                maxi = mat[i][mid];
            }
        }
        int left = mid > 0 ? mat[maxIndex][mid - 1] : -1;
        int right = mid < m - 1 ? mat[maxIndex][mid + 1] : -1;
        if (maxi > left && maxi > right)
            return {maxIndex, mid};
        else if (left > maxi)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    // driver code
    return 0;
}