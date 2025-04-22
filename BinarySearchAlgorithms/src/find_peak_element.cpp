#include <iostream>
#include <vector>

using namespace std;

/**
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 5
 */

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int low = 1, high = n - 2;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] > nums[mid - 1])
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << findPeakElement(nums) << "\n";
    return 0;
}