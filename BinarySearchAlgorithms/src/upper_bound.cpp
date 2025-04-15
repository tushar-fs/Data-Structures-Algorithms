#include "include/upper_bound.h"
#include <iostream>

/*
 Upper bound -> Index of the first element greater than target
*/
int upperBound(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) >> 1;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low < n && nums[low] > target)
        return low;
    return -1;
}