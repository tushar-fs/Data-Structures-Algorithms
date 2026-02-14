#include <iostream>

using namespace std;

int minCost(int ind, int lastExecuted, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (ind < 0)
        return 0;

    if (dp[ind][lastExecuted] != -1)
    {
        return dp[ind][lastExecuted];
    }

    int mini = INT_MAX;
    for (int task = 0; task < 3; task++)
    {
        if (task != lastExecuted)
        {
            mini = min(mini, points[ind][task] + minCost(ind - 1, task, points, dp));
        }
    }

    return dp[ind][lastExecuted] = mini;
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int result = minCost(n - 1, 3, points, dp);
    cout << "The maximum merit points are: " << result << endl; // Output: 210

    return 0;
}