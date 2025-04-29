#include <iostream>
#include <vector>

using namespace std;

/**
 * LEETCODE #540
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * Return the single element that appears only once.
 *
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 */

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid & 1)
        {
            // check search space side of single element
            if (nums[mid] == nums[mid - 1])
                low = mid + 1;
            else if (nums[mid] == nums[mid + 1])
                high = mid - 1;
            else
                return nums[mid];
        }
        else
        {
            // check search space side of single element
            if (nums[mid] == nums[mid + 1])
                low = mid + 1;
            else if (nums[mid] == nums[mid - 1])
                high = mid - 1;
            else
                return nums[mid];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << "\n";
    return 0;
}