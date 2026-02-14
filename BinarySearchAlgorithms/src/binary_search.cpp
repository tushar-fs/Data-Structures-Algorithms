/**
 * Problem: Binary Search (Iterative)
 * Given a sorted array and a target value, find the index of the target
 * using iterative binary search.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include "include/binary_search.h"
#include <iostream> // for debugging purpose

void binarySearchIterative(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int locationIndex = -1;
    while (low <= high)
    {
        int mid = low + (high - low) >> 1;
        if (nums[mid] == target)
        {
            locationIndex = mid;
            return;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (locationIndex == -1)
        cout << "Element not found! \n";
    else
        cout << "Element found at Index: " << locationIndex << endl;
}