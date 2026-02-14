#include <iostream>

using namespace std;

int main()
{
    vector<int> a{2, 4, 6};
    vector<int> wt{5, 11, 13};
    int weight = 10;
    int n = a.size();
    vector<int> prev(weight + 1, 0);

    for (int i = 1; i <= weight; i++)
    {
        if (i % wt[0] == 0)
        {
            prev[i] = (i / wt[0]) * a[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(weight + 1, 0);
        for (int j = 1; j <= weight; j++)
        {
            int pick = INT_MIN;
            if (j - wt[i] >= 0)
            {
                pick = a[i] + cur[j - wt[i]];
            }
            int notPick = prev[j];
            cur[j] = max(pick, notPick);
        }
        prev = cur;
    }

    cout << prev[weight] << endl;

    return 0;
}