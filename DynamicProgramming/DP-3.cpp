#include <iostream>
#include <vector>

using namespace std;

// Frog with K jumps

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