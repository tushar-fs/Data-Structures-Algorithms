#include <iostream>

using namespace std;

// nums contains numbers from [1, n]
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