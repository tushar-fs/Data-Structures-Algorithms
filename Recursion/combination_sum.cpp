#include <iostream>

using namespace std;

void printAllCombinations(int ind, vector<int> &arr, int target, vector<int> &container, vector<vector<int>> &combinations)
{
    if (target == 0)
    {
        combinations.push_back(container);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            container.push_back(arr[i]);
            printAllCombinations(i, arr, target - arr[i], container, combinations);
            container.pop_back();
        }
    }
}

void printAllCombinationsV2(int ind, vector<int> &arr, int target, vector<int> &container)
{

    if (ind == arr.size())
    {
        if (target == 0)
        {
            for (int x : container)
                cout << x << " ";
        }
        cout << "\n";
        return;
    }

    if (target - arr[ind] >= 0)
    {
        container.push_back(arr[ind]);
        printAllCombinationsV2(ind, arr, target - arr[ind], container);
        container.pop_back();
    }

    printAllCombinationsV2(ind + 1, arr, target, container);
}