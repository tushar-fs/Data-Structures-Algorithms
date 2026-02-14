#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> knapsack = {{3, 30}, {2, 40}, {5, 60}};
    int bagWeight = 6;
    int n = knapsack.size();

    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));

    for (int wt = knapsack[0][0]; wt <= bagWeight; wt++)
        dp[0][wt] = knapsack[0][1];
    for (int i = 1; i < n; i++)
    {
        for (int wt = 1; wt <= bagWeight; wt++)
        {
            int notTake = dp[i - 1][wt];
            int take = 0;
            if (wt - knapsack[i][0] >= 0)
                take = knapsack[i][1] + dp[i - 1][wt - knapsack[i][0]];
            dp[i][wt] = max(notTake, take);
        }
    }

    cout << dp[n - 1][bagWeight] << endl;

    return 0;
}