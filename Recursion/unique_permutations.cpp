#include <iostream>
#include <unordered_set>

using namespace std;

void uniquePermutations(vector<int> &nums, vector<int> &container, unordered_set<int> &vis, vector<vector<int>> &res)
{
    if (container.size() == nums.size())
    {
        res.push_back(container);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if ((i > 0 && nums[i] == nums[i - 1] && vis.find(i - 1) == vis.end()) || vis.find(i) != vis.end())
            continue;
        vis.insert(i);
        container.push_back(nums[i]);
        uniquePermutations(nums, container, vis, res);
        container.pop_back();
        vis.erase(i);
    }
}

int main()
{
    vector<int> nums = {1, 2, 1};
    sort(nums.begin(), nums.end());
    vector<int> container;
    vector<vector<int>> res;
    unordered_set<int> vis;
    uniquePermutations(nums, container, vis, res);
    for (auto v : res)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}