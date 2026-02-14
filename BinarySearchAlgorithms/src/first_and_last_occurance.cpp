/**
 * Problem: Find First and Last Position of Element in Sorted Array (LC #34)
 * Given an array of integers sorted in non-decreasing order, find the starting
 * and ending position of a given target value.
 * Time Complexity: O(2 * log n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> firstAndLastOccurrence(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    if (n == 0)
        return {-1, -1};
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low >= n || nums[low] != target)
        return {-1, -1};

    int firstOcc = low;

    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    int lastOcc = low - 1;
    return {firstOcc, lastOcc};
}

int main()
{
    return 0;
}