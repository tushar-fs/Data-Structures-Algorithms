/**
 * Problem: Frog Jump with K Steps
 * A frog wants to climb from step 0 to step n-1. From any step, it can jump
 * up to K steps. The cost of a jump is the absolute difference in heights.
 * Find the minimum energy to reach the last step.
 * Time Complexity: O(n * k)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

int findMinimumEnergy(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(k, INT_MAX);
    vector<int> parent(n, -1);
    dp[n - 1] = 0;
    parent[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        int ind = -1;
        for (int j = 0; j <= k; j++)
        {
            if (i + j < n)
            {
                if (dp[i] > dp[i + j] + abs(heights[i] - heights[i + j]))
                {
                    dp[i] = dp[i + j] + abs(heights[i] - heights[i + j]);
                    ind = i + j;
                }
            }
        }
        parent[i] = ind;
    }
    // print minimal path
    int ind = 0;
    while (ind != -1)
    {
        cout << ind << " ";
        ind = parent[ind];
    }
    return dp[0];
}