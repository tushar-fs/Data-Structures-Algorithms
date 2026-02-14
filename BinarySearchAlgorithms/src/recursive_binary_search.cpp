/**
 * Problem: Binary Search (Recursive)
 * Given a sorted array and a target value, find the index of the target
 * using recursive binary search.
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) — recursion stack
 */
#include "include/recursive_binary_search.h"
#include <iostream> // for debugging purpose

int binarySearchRecursive(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) >> 1;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearchRecursive(nums, mid + 1, high, target);
    else
        return binarySearchRecursive(nums, low, mid - 1, target);
}