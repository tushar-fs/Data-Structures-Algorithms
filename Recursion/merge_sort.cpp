#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l1, int r1, int l2, int r2)
{
    // [l1,...., r1]
    // [l2,...., r2]
    vector<int> temp;
    int i = l1, j = l1, k = l2;
    while (j <= r1 && k <= r2)
    {
        if (arr[j] <= arr[k])
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[k]);
            k++;
        }
    }

    while (j <= r1)
    {
        temp.push_back(arr[j++]);
    }

    while (k <= r2)
    {
        temp.push_back(arr[k++]);
    }

    for (int i = l1; i <= r2; i++)
    {
        arr[i] = temp[i - l1];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, mid + 1, end);
}

int main()
{
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
