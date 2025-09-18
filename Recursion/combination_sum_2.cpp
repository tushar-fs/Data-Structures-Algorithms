#include <iostream>

using namespace std;

void printAllUniqueCombinations(int ind, vector<int> &arr, int target, vector<int> &container)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            for (int x : container)
                cout << x << " ";
            cout << "\n";
        }
        return;
    }

    if (target - arr[ind] >= 0)
    {
        container.push_back(arr[ind]);
        printAllUniqueCombinations(ind + 1, arr, target - arr[ind], container);
        container.pop_back();
    }
    while (ind + 1 < arr.size() && arr[ind] == arr[ind + 1])
        ind++;
    printAllUniqueCombinations(ind + 1, arr, target, container);
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<int> container;

    sort(arr.begin(), arr.end());
    printAllUniqueCombinations(0, arr, target, container);
}