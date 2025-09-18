/**
 * The Supply & Demand Pattern: Focuses on the core logic of tracking available resources vs. needs.
 *
 * Problems on similar pattern
 * LeetCode 659. Split Array into Consecutive Subsequences
 * LeetCode 870. Advantage Shuffle
 * LeetCode 954. Array of Doubled Pairs
 * LeetCode 1296. Divide Array in Sets of K Consecutive Numbers
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> freq, subsMap;
        for (int i : nums)
            freq[i]++;

        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if (freq[cur] == 0)
                continue;
            if (subsMap.find(cur - 1) != subsMap.end() && subsMap[cur - 1] > 0)
            {
                subsMap[cur - 1]--;
                subsMap[cur]++;
            }
            else if (freq[cur + 1] > 0 && freq[cur + 2] > 0)
            {
                subsMap[cur + 2]++;
                freq[cur + 1]--;
                freq[cur + 2]--;
            }
            else
            {
                return false;
            }
            freq[cur]--;
        }
        return true;
    }
};