#include <iostream>

using namespace std;

int findAllWays(int n, vector<int> &a, int target, vector<vector<int>> &dp, int offSet)
{
    if (n == 0)
    {
        if (target - a[n] == 0 || target + a[n] == 0)
            return 1;
        return 0;
    }

    if (dp[n][offSet + target] != -1)
        return dp[n][offSet + target];

    int ways = 0;
    ways += findAllWays(n - 1, a, target + a[n], dp, offSet);
    ways += findAllWays(n - 1, a, target - a[n], dp, offSet);
    return dp[n][offSet + target] = ways;
}

int main()
{
    vector<int> a = {1, 2, 3, 1};
    int n = a.size();
    int target = 3;
    int totalSum = 0;
    for (int x : a)
        totalSum += x;
    vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
    cout << findAllWays(n - 1, a, target, dp, totalSum);
    return 0;
}