/**
 * Problem: Lower Bound
 * Find the index of the first element in a sorted array that is
 * greater than or equal to the target value.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include "include/lower_bound.h"
#include <iostream>
int lowerBound(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) >> 1;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    if (low < n && nums[low] >= target)
        return low;
    return -1;
}
