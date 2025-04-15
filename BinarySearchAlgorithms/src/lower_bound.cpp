#include "include/lower_bound.h"
#include <iostream>

/*
 Lower Bound -> Index of the first element that is equal
 to or greater than target
*/
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
