/**
 * Problem: Ninja Training / Paint Houses — Tabulation (LC #256 variant)
 * Given N days and 3 tasks with different points, maximize the total points
 * such that you don't perform the same task on two consecutive days.
 * Bottom-up tabulation approach.
 * Time Complexity: O(n * 3)
 * Space Complexity: O(n * 3)
 */
#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(3, INT_MAX));

    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = points[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        // perform task 0
        dp[i][0] = min(dp[i][0], points[i][0] + min(dp[i - 1][1], dp[i - 1][2]));

        // perform task 1
        dp[i][1] = min(dp[i][1], points[i][1] + min(dp[i - 1][0], dp[i - 1][2]));

        // perform task 2
        dp[i][2] = min(dp[i][2], points[i][2] + min(dp[i - 1][0], dp[i - 1][1]));
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

    return 0;
}