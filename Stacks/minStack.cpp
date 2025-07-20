#include <stack>

using namespace std;

class MinStack
{
private:
    int curMin;
    stack<int> minStack;

public:
    MinStack()
    {
        this->curMin = INT_MAX;
    }

    void push(int x)
    {
        if (minStack.empty())
        {
            this->curMin = x;
            minStack.push(x);
        }
        else
        {
            if (x < curMin)
            {
                int modifiedVal = 2 * x - curMin;
                minStack.push(modifiedVal);
                this->curMin = x;
            }
            else
            {
                minStack.push(x);
            }
        }
    }

    int top()
    {
        if (minStack.empty())
            return -1;

        int top = minStack.top();
        if (top < curMin)
        {
            return curMin;
        }
        else
        {
            return top;
        }
    }

    void pop()
    {
        int top = minStack.top();
        minStack.pop();
        if (top < curMin)
        {
            int prevMin = 2 * curMin - top;
            this->curMin = prevMin;
        }
    }

    bool isEmpty()
    {
        return minStack.empty();
    }

    int getMin()
    {
        return this->curMin;
    }
};