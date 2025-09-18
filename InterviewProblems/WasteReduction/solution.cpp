#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

int chooseContainers(vector<int> &requirements, int numContainerSets, vector<vector<int>> &containers)
{
    vector<vector<int>> sets(numContainerSets);
    for (auto &container : containers)
    {
        sets[container[0]].push_back(container[1]);
    }

    sort(requirements.begin(), requirements.end());

    int totalRequirementSize = 0;
    for (int x : requirements)
    {
        totalRequirementSize += x;
    }

    int totalWastage = LLONG_MAX, minWasteSetIndex = -1;
    for (int i = 0; i < numContainerSets; i++)
    {
        if (sets[i].empty() || sets[i].back() < requirements.back())
        {
            continue;
        }

        int prevReqIndex = -1;
        int containerSizeReq = 0;
        for (int container : sets[i])
        {
            int curReqIndex = (upper_bound(requirements.begin(), requirements.end(), container) - requirements.begin()) - 1;
            if (curReqIndex > prevReqIndex)
            {
                containerSizeReq += (curReqIndex - prevReqIndex) * 1ll * container;
                prevReqIndex = curReqIndex;
            }
        }

        int curWastage = containerSizeReq - totalRequirementSize;

        if (curWastage < totalWastage)
        {
            totalWastage = curWastage;
            minWasteSetIndex = i;
        }
    }
    return minWasteSetIndex;
}

signed main()
{
    vector<int> requirements = {10, 15};
    int numContainerSets = 3;
    vector<vector<int>> containers = {
        {0, 11}, {0, 20}, {1, 11}, {1, 17}, {2, 12}, {2, 16}};

    // Call the function with the sample data
    int result = chooseContainers(requirements, numContainerSets, containers);

    // Print the output
    // Expected output for this case is 1
    cout << "The best container set index is: " << result << endl;
    return 0;
}