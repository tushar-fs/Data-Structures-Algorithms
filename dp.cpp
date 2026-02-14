#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(10001, -1);
int solve(int ind, vector<int> &nums)
{
    if (ind >= nums.size())
    {
        return 0;
    }

    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + solve(ind + nums[ind], nums);
    int notPick = solve(ind + 1, nums);

    return dp[ind] = max(pick, notPick);
}

int main()
{
    vector<int> nums = {2, 3, 4, 99, 1};
    cout << solve(0, nums) << endl;
    return 0;
}