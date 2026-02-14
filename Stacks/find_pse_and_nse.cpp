/**
 * Problem: Previous Smaller Element & Next Smaller Element
 * For each element in the array, find the nearest smaller element to its left
 * (PSE) and nearest smaller element to its right (NSE) using monotonic stack.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printPSEandNSE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> cachePSE(n, -1), cacheNSE(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            int poppedIndex = st.top();
            st.pop();
            cacheNSE[poppedIndex] = nums[i];
            cachePSE[poppedIndex] = !st.empty() ? nums[st.top()] : -1;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int poppedIndex = st.top();
        st.pop();
        cacheNSE[poppedIndex] = -1;
        cachePSE[poppedIndex] = !st.empty() ? nums[st.top()] : -1;
    }

    for (int x : cacheNSE)
        cout << x << " ";
    cout << endl;
    for (int x : cachePSE)
        cout << x << " ";
}

int main()
{
    vector<int> nums = {4, 5, 2, 10, 8};
    printPSEandNSE(nums);
    // Expected Output:
    // NGE: 5 10 10 -1 -1
    // PGE: -1 -1 5 -1 10
    return 0;
}
