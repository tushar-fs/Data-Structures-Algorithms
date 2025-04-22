#include <iostream>
#include <vector>

using namespace std;

/*
 TC -> (logN)
 Sorted array with distinct values
*/
int searchInSortedRotatedArray(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        // check left sorted
        if (nums[mid] > nums[n - 1])
        {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

/**
 * TC -> O(N) worst case
 *  O(log N) average case
 * Rotated Sorted Array with duplicates
 */
bool searchInSortedAndRotatedArray(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        if (nums[mid] == nums[high])
            high--; // to avoid duplicates, since this creates problem thus exclude it
        else if (nums[mid] > nums[high])
        {
            // checking in left sorted array
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // checking in right sorted array
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    return 0;
}