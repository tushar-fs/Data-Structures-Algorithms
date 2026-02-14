/**
 * Problem: Maximum Appearing Element in Ranges
 * Given N ranges [left[i], right[i]], find the element that appears in the
 * maximum number of ranges. Uses prefix sum / difference array technique.
 * Time Complexity: O(n + maxRange)
 * Space Complexity: O(maxRange)
 */
#include "mybits/stdc++.h"

using namespace std;

int getMaximumAppearingElement(vector<int> &left, vector<int> &right)
{
    vector<int> freq(10001, 0);
    int n = left.size();
    for (int i = 0; i < n; i++)
    {
        freq[left[i]]++;
        freq[right[i] + 1]--;
    }
}

int main()
{
    vector<int> left = {1, 2, 5, 15};
    vector<int> right = {5, 8, 7, 18};

    return 0;
}