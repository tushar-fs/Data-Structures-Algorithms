#include <iostream>

using namespace std;

// find minimum coins

int findMinimumCoins(int ind, vector<int> &coins, int target)
{
    if (target < 0)
        return 1e9;
    if (target == 0)
        return 0;
    if (ind == 0)
    {
        if (target == coins[ind])
            return 1;
        return 1e9;
    }

    int minCoins = 1e9;
    minCoins = 1 + min(minCoins, findMinimumCoins(ind, coins, target - coins[ind]));
    minCoins = min(minCoins, findMinimumCoins(ind - 1, coins, target));
    return minCoins;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int n = nums.size();
    int target = 7;

    vector<int> prev(target + 1, 1e9);

    prev[0] = 0;

    for (int i = 1; i <= target; i++)
    {
        if (i % nums[0] == 0)
            prev[i] = i / nums[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(target + 1, 1e9);
        cur[0] = 0;
        for (int k = 1; k <= target; k++)
        {
            int take = 1e9, notTake = 1e9;
            if (k - nums[i] >= 0)
                take = min(take, 1 + cur[k - nums[i]]);
            notTake = min(notTake, prev[k]);
            cur[k] = min(take, notTake);
        }
        prev = cur;
    }

    cout << prev[target] << endl;

    return 0;
}