#include "mybits/stdc++.h"

using namespace std;

typedef pair<int, pair<int, int>> ppi;
const int maxN = 10001;

struct Node
{
    int key, val, freq;
    Node *next, *prev;
    Node(int _key, int _val, int count)
    {
        key = _key;
        val = _val;
        freq = count;
        next = nullptr;
        prev = nullptr;
    }
};

struct List
{
    Node *head, *tail;
    int length;
    List()
    {
        head = new Node(-1, -1, 0);
        tail = new Node(-1, -1, 0);
        head->next = tail;
        tail->prev = head;
        length = 0;
    }

    void insertAtHead(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        length++;
    }

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        length--;
        delete node;
    }
};

class LFUCache
{
    unordered_map<int, Node *> nodeMap;
    unordered_map<int, List> freqListMap;
    int maxCacheSize, minFreq, size;

public:
    LFUCache(int capacity)
    {
        maxCacheSize = capacity;
        size = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node *targetNode)
    {
        freqListMap[targetNode->freq].removeNode(targetNode);
        if (targetNode->freq == minFreq && freqListMap[targetNode->freq].length == 0)
        {
            minFreq++;
        }
        targetNode->freq++;
        freqListMap[targetNode->freq].insertAtHead(targetNode);
    }

    int get(int key)
    {
        if (nodeMap.find(key) == nodeMap.end())
            return -1;
        Node *targetNode = nodeMap[key];
        // write logic to ensure correct node order w.r.t freq
        updateFreqListMap(targetNode);
        return targetNode->val;
    }

    void put(int key, int value)
    {
        if (maxCacheSize == 0)
            return; // Handle edge case
        if (nodeMap.find(key) == nodeMap.end())
        {
            // delete LFU node if cache size if full
            if (size == maxCacheSize)
            {
                List &l = freqListMap[minFreq];
                Node *nodeToEvict = l.tail->prev;
                nodeMap.erase(nodeToEvict->key);
                l.removeNode(l.tail->prev);
                size--;
            }
            Node *temp = new Node(key, value, 1);
            minFreq = 1;
            nodeMap[key] = temp;
            freqListMap[1].insertAtHead(temp);
            size++;
        }
        else
        {
            Node *targetNode = nodeMap[key];
            targetNode->val = value;
            updateFreqListMap(targetNode);
        }
    }
};

struct MinStack
{
    stack<int> st;
    int minSoFar;

    void push(int x)
    {
        if (isEmpty())
        {
            st.push(x);
            minSoFar = x;
        }

        else if (x < minSoFar)
        {
            int modifiedVal = 2 * x - minSoFar;
            st.push(modifiedVal);
            minSoFar = x;
        }

        else
            st.push(x);
    }

    void pop()
    {
        if (isEmpty())
            return;
        int topElement = st.top();
        st.pop();
        if (topElement < minSoFar)
        {
            int prevMin = 2 * minSoFar - topElement;
            minSoFar = prevMin;
        }
    }

    int top()
    {
        return max(st.top(), minSoFar);
    }

    bool isEmpty()
    {
        return st.empty();
    }
};

struct KStacks
{
    int *arr, n, k;
    int *next, *top, free_top;
    KStacks(int size, int k)
    {
        n = size;
        arr = new int[size];
        this->k = k;
        next = new int[size];
        top = new int[k];
        fill(top, top + k, -1);
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
        free_top = 0;
    }

    void push(int sn, int x)
    {
        // push element x to stack sn
        int i = free_top;
        free_top = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn)
    {
        // pop & return top element of stack sn
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free_top;
        free_top = i;
        return arr[i];
    }

    bool isEmpty()
    {
    }
};

class Solution
{
private:
    int binarySearch(vector<int> &nums, int key, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == key)
                return mid;
            else if (nums[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

public:
    void sortColor(vector<int> nums)
    {
        //[1, 0, 1, 2, 0]
        // [0, low-1] -> 0's
        // [low, mid] -> 1's
        // [mid, high] -> 2's
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
                mid++;
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int x = heights[st.top()];
                st.pop();
                int nseX = i;
                int pseX = !st.empty() ? st.top() : -1;
                ans = max(ans, (i - pseX - 1) * x);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int x = heights[st.top()];
            st.pop();
            int nseX = n;
            int pseX = !st.empty() ? st.top() : -1;
            ans = max(ans, x * (nseX - pseX - 1));
        }
        return ans;
    }

    int findCelebrity(vector<vector<int>> &a)
    {
        // brute force O(n*n)
        int n = a.size();
        // for (int i = 0; i < n; i++)
        // {
        //     int j = 0;
        //     for (; j < n; j++)
        //     {
        //         if ((i == j) || (a[i][j] == 0 && a[j][i] == 1))
        //             continue;
        //         else
        //             break;
        //     }
        //     if (j == n)
        //         return i;
        // }
        // return -1;

        // Efficient O(n)

        int top = 0, down = n - 1;
        while (top < down)
        {
            if (a[top][down])
                top++;
            else if (a[down][top])
                down--;
            else
                top++, down--;
        }

        bool isCelebrity = true;
        for (int i = 0; i < n; i++)
        {
            if (i != top && a[top][i] == 1 || a[i][top] == 0)
            {
                isCelebrity = false;
            }
        }
        return isCelebrity ? top : -1;
    }

    double medianOfMatrix(vector<vector<int>> &a)
    {
        // find median in row-wise sorted matrix
        int n = a.size();
        int m = a[0].size();
        int total = n * m;

        int medianPos = (total + 1) / 2;

        int low = INT_MAX, high = INT_MIN, firstMed;
        for (int i = 0; i < m; i++)
        {
            low = min(low, a[i][0]);
            high = max(high, a[i][m - 1]);
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 1;
            // find count of elements <= mid
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                count += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
            }

            if (count < medianPos)
                low = mid + 1;
            else
            {
                firstMed = mid;
                high = mid - 1;
            }
        }

        if (total & 1)
            return low;
        else
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                count += upper_bound(a[i].begin(), a[i].end(), firstMed) - a[i].begin();
            }
            if (count >= medianPos + 1)
                return (firstMed + firstMed) / 2.0;
            int secondMedian = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                auto it = upper_bound(a[i].begin(), a[i].end(), firstMed);
                if (it != a[i].end())
                {
                    secondMedian = min(secondMedian, *it);
                }
            }
            return (firstMed + secondMedian) / 2.0;
        }
    }

    bool isValidParenthesis(string s)
    {
        // can be done using range based method as well
        stack<int> openBracketContainer;
        stack<int> asterickContainer;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                openBracketContainer.push(i);
            else if (s[i] == '*')
                asterickContainer.push(i);
            else
            {
                if (!openBracketContainer.empty())
                    openBracketContainer.pop();
                else if (!asterickContainer.empty())
                    asterickContainer.pop();
                else
                    return false;
            }
        }
        while (!openBracketContainer.empty() && !asterickContainer.empty())
        {
            if (openBracketContainer.top() > asterickContainer.top())
                return false;
            openBracketContainer.pop();
            asterickContainer.pop();
        }

        return openBracketContainer.empty();
    }

    void binaryExponentiation(int a, int n)
    {
        // a^n -> in o(log(n)) TC
        long long res = 1;
        while (n)
        {
            if (n & 1)
            {
                res *= a;
            }
            a = a * a;
            n = n >> 1;
        }
    }
    void exponentialSearch(vector<int> &nums, int key)
    {
        /*
        2 step process:
            a - Find the ranges in which the key is present
            b - do binary search in that range

        to find ranges we will check in subarray of size 1 then
        keep doubling it's size.
        */
        if (nums[0] == key)
            return;
        int i = 1;
        while (i < nums.size() && nums[i] <= key)
            i = i * 2;
        int index = binarySearch(nums, key, i / 2, i - 1);
        cout << index << endl;
    }

    vector<int> maximumSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }

    void mergeKSortedArrays(vector<vector<int>> &lists)
    {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            pq.push({lists[i][0], {0, i}});
        }

        vector<int> ans;
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.first);
            int row = cur.second.second;
            int col = cur.second.first;
            if (col + 1 < lists[row].size())
            {
                pq.push({lists[row][col + 1], {col + 1, row}});
            }
        }

        for (int x : ans)
            cout << x << " ";
    }

    string minWindowSubstring(string s, string t)
    {
        int left = 0;
        unordered_map<char, int> windowMap, targetMap;
        for (char x : t)
            targetMap[x]++;
        int matches = 0, startIdx = 0, minLen = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            windowMap[s[i]]++;
            if (targetMap.count(s[i]))
            {
                if (windowMap[s[i]] == targetMap[s[i]])
                {
                    matches++;
                }
            }
            while (matches == targetMap.size())
            {
                if (minLen > i - left + 1)
                {
                    minLen = i - left + 1;
                    startIdx = left;
                }
                windowMap[s[left]]--;
                if (targetMap.count(s[left]))
                {
                    if (windowMap[s[left]] < targetMap[s[left]])
                    {
                        matches--;
                    }
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
    void longestSubstringWithAtmost2Distinct(string s)
    {
        int left = 0, maxLen = 1;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            while (mp.size() > 2)
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        cout << maxLen << endl;
    }

    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        vector<char> freq(256, 0);
        int left = 0, maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            while (freq[s[i]] > 0)
            {
                freq[s[left]]--;
                left++;
            }
            freq[s[i]]++;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }

    int maxProductSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int preProd = 1;
        int sufProd = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            preProd *= nums[i];
            sufProd *= nums[n - i - 1];
            ans = max(ans, max(preProd, sufProd));
            if (preProd == 0)
                preProd = 1;
            if (sufProd == 0)
                sufProd = 1;
        }
        return ans;
        // TC -> O(N), SC -> O(1)
    }

    void maxAppearElementInRange(vector<int> &l, vector<int> &r)
    {
        int freq[maxN];
        fill(freq, freq + maxN, 0);
        for (int i = 0; i < l.size(); i++)
        {
            freq[l[i]]++;
            freq[r[i] + 1]--;
        }
        for (int i = 1; i < maxN; i++)
            freq[i] += freq[i - 1];
        int maxAppearingElement = 0;
        for (int i = 1; i < maxN; i++)
        {
            if (freq[i] > freq[maxAppearingElement])
                maxAppearingElement = i;
        }

        cout << maxAppearingElement << endl;
    }

    void minFlips(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        vector<pair<int, int>> vp0, vp1;
        while (i < n)
        {
            while (j < n && nums[i] == nums[j])
            {
                j++;
            }
            if (nums[i] == 0)
                vp0.push_back({i, j - 1});
            else
                vp1.push_back({i, j - 1});
            i = j;
        }
        if (vp0.size() <= vp1.size())
        {
            for (auto x : vp0)
                cout << x.first << " " << x.second << endl;
        }
        else
        {
            for (auto x : vp1)
                cout << x.first << " " << x.second << endl;
        }
    }

    void frequencyInSortedArray(vector<int> &nums)
    {
        int n = nums.size();
        int freq = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                freq++;
            else
            {
                cout << nums[i - 1] << " " << freq << endl; // print current element with freq
                freq = 1;
            }
        }
        cout << nums.back() << " " << freq << endl;
        /*
            TC -> O(Size of Array)
            SC -> O(1)
        */
    }

    void maxSumSubarrayOfSizeK(vector<int> &nums, int k)
    {
        int left = 0, right = k, windowSum = 0, maxSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += nums[i];
        while (right < nums.size())
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= nums[left++];
            windowSum += nums[right++];
        }
        maxSum = max(maxSum, windowSum);

        cout << maxSum << "\n";
    }

    void leadersInArray(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans;
        int maxSoFar = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= maxSoFar)
                ans.push_back(a[i]);
            maxSoFar = max(maxSoFar, a[i]);
        }
        for (int x : ans)
            cout << x << " ";
    }

    void merge3SortedArrays(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        stack<int> res;
        int alen = a.size(), blen = b.size(), clen = c.size();
        int i = alen - 1, j = blen - 1, k = clen - 1;
        while (i >= 0 || j >= 0 || k >= 0)
        {
            // get largest element
            int elementA = i >= 0 ? a[i] : INT_MIN;
            int elementB = j >= 0 ? b[j] : INT_MIN;
            int elementC = k >= 0 ? c[k] : INT_MIN;
            int maxElement = max(elementA, max(elementB, elementC));
            if (i >= 0 && a[i] == maxElement)
                i--;
            else if (j >= 0 && b[j] == maxElement)
                j--;
            else
                k--;
            if (res.empty() || res.top() != maxElement)
                res.push(maxElement);
        }

        while (!res.empty())
        {
            cout << res.top() << " ";
            res.pop();
        }
    }
};

vector<int> firstAndLastOccurrence(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    if (n == 0)
        return {-1, -1};
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low >= n || nums[low] != target)
        return {-1, -1};

    int firstOcc = low;

    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    int lastOcc = low - 1;
    return {firstOcc, lastOcc};
}

int main()
{
    // vector<int> a(n), b(n);
    // for (int &x : a)
    //     cin >> x;
    // vector<int> arr = {2, 3, 4, 10, 40};
    // vector<vector<int>> lists = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    // Solution sol;
    // cout << "HI" << endl;
    // sol.exponentialSearch(arr, 10);

    cout << "Hello";
    return 0;
}