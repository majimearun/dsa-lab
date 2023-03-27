#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    stack<char> brackets;
    for (char c : s)
    {
        if (c == '(')
        {
            brackets.push('(');
        }
        else
        {
            if (brackets.empty() || brackets.top() == ')')
            {
                count++;
            }
            else
            {
                brackets.pop();
            }
        }
    }
    while (!brackets.empty())
    {
        count++;
        brackets.pop();
    }
    cout << count;
}