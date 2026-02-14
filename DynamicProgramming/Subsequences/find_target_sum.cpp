/**
 * Problem: Subset Sum Problem
 * Given an array of integers and a target sum, determine if there exists a
 * subset whose elements sum to the target. Boolean DP approach.
 * Time Complexity: O(n * target)
 * Space Complexity: O(n * target)
 */
#include <iostream>

using namespace std;

int main()
{
    vector<int> a = {2, 3, 1, 1};
    int n = a.size();
    int target = 3;

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    dp[0][0] = true;
    dp[0][a[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= target; k++)
        {
            bool notTake = dp[i - 1][k];
            bool take = false;
            if (k - a[i] >= 0)
            {
                take = dp[i - 1][k - a[i]];
            }
            dp[i][k] = take || notTake;
        }
    }

    cout << dp[n - 1][target] << endl;
}