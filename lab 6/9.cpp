#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<string> path;
    string curr = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if (c != '/' && c != '.')
        {
            curr += c;
        }
        else
        {
            if (s.at(i) == '.' && (i < s.length() - 1 && s.at(i + 1) == '.'))
            {
                path.pop();
            }
            if (curr != "")
            {
                path.push(curr);
                curr = "";
            }
        }
    }
    if (curr != "")
    {
        path.push(curr);
    }
    string simplified = "";
    if (path.empty())
    {
        cout << "/\n";
    }
    else
    {
        while (!path.empty())
        {
            simplified = "/" + path.top() + simplified;
            path.pop();
        }
        cout << simplified << "\n";
    }
    return 0;
}