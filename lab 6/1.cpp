#include <iostream>

using namespace std;

class StackObj
{
  public:
    int elem;
    int min_until;
    StackObj *prvs;

    StackObj(int elem);
};

class MinStack
{
  public:
    StackObj *top;

    MinStack();
    void push(int val);
    void pop();
    int getTop();
    int getMin();
};

StackObj::StackObj(int val)
{
    elem = val;
    min_until = 0;
    prvs = nullptr;
}

MinStack::MinStack()
{
    top = nullptr;
}

void MinStack::push(int val)
{
    StackObj *stackObject = new StackObj(val);
    int prvsMin = (top != nullptr) ? top->min_until : val;
    stackObject->min_until = val <= prvsMin ? val : prvsMin;
    stackObject->prvs = top;
    top = stackObject;
}

void MinStack::pop()
{
    StackObj *old_top = top;
    if (top != nullptr)
    {
        top = top->prvs;
        delete old_top;
    }
    else
    {
        cout << "Stack empty\n";
    }
}

int MinStack::getTop()
{
    if (top != nullptr)
    {
        return top->elem;
    }
    else
    {
        cout << "Stack empty\n";
        return -99999;
    }
}

int MinStack::getMin()
{
    if (top != nullptr)
    {
        return top->min_until;
    }
    else
    {
        cout << "Stack empty";
        return -99999;
    }
}

int main()
{
    int n, operations, elem, op;
    cin >> n;
    auto minstack = new MinStack;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        minstack->push(elem);
    }
    cin >> operations;
    for (int i = 0; i < operations; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> elem;
            minstack->push(elem);
            break;

        case 2:
            minstack->pop();
            break;

        case 3:
            cout << minstack->getTop() << endl;
            break;

        case 4:
            cout << minstack->getMin() << endl;
            break;

        default:
            break;
        }
    }
    return 0;
}
