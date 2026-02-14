/**
 * Problem: Cycle Sort
 * Sort an array containing numbers from [1, n] by placing each element at
 * its correct index (nums[i] = i+1) using constant swaps.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <iostream>

using namespace std;
void cycleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n;)
    {
        if (nums[i] != i + 1)
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
            i++;
    }
}