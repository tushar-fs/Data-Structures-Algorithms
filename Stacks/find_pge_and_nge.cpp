#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printPGEandNGE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> cachePGE(n, -1), cacheNGE(n, -1);
    // Part 1: Monotonic stack (strictly decreasing) + Boundry detection
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            // for all the elements that will be popped, nums[i]
            // will be it's next greater element
            int poppedIndex = st.top();
            st.pop();
            int pge = !st.empty() ? nums[st.top()] : -1;
            int nge = nums[i];
            cachePGE[poppedIndex] = pge;
            cacheNGE[poppedIndex] = nge;
        }
        st.push(i);
    }

    /*
    Part 2: Process elements remaining on the stack
    These elements form a decreasing sequence and have no NGE to their right.
    */
    while (!st.empty())
    {
        int poppedIndex = st.top();
        int curVal = nums[poppedIndex];
        st.pop();
        cachePGE[poppedIndex] = !st.empty() ? nums[st.top()] : -1;
        cacheNGE[poppedIndex] = -1;
    }

    for (int x : cacheNGE)
        cout << x << " ";
    cout << endl;
    for (int x : cachePGE)
        cout << x << " ";
}

void printPGEIndexes(vector<int> &nums)
{
    int n = nums.size();

    stack<int> st;
    vector<int> pgeIndexes(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        pgeIndexes[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }

    for (int x : pgeIndexes)
    {
        cout << x << " ";
    }
}

void printNGEIndexes(vector<int> &nums)
{
    int n = nums.size();

    stack<int> st;
    vector<int> ngeIndexes(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] <= nums[st.top()])
        {
            st.pop();
        }
        ngeIndexes[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }

    for (int x : ngeIndexes)
        cout << x << " ";
}

int main()
{
    vector<int> nums = {4, 10, 5, 8, 20, 15, 3};
    printPGEIndexes(nums);
    // Expected Output:
    // NGE: 5 10 10 -1 -1
    // PGE: -1 -1 5 -1 10
    return 0;
}
