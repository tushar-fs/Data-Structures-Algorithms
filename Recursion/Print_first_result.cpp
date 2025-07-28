#include <iostream>
#include <vector>

using namespace std;

bool printSubsetWithSumK(int ind, vector<int> &ds, vector<int> &arr, int k, int sum)
{
    if (ind == arr.size())
    {
        if (sum == k)
        {
            for (int x : ds)
                cout << x << " ";
            return true;
        }
        return false;
    }

    if (sum + arr[ind] < k)
    {
        ds.push_back(arr[ind]);
        if (printSubsetWithSumK(ind + 1, ds, arr, k, sum + arr[ind]))
        {
            return true;
        }
        ds.pop_back();
    }
    if (printSubsetWithSumK(ind + 1, ds, arr, k, sum))
        return true;
    return false;
}

int main()
{
    return 0;
}