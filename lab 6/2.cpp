#include <iostream>
#include <stack>

using namespace std;

class Student
{
  public:
    int index;
    int val;
};

int main()
{
    stack<Student> students;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int soln[n];
    for (int i = 0; i < n; i++)
    {
        soln[i] = -1;
    }
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            auto elem = new Student;
            elem->index = i;
            elem->val = arr[i];
            if (students.empty())
            {
                students.push(*elem);
            }
            else
            {
                while (!students.empty() && elem->val > students.top().val)
                {
                    if (j == 0)
                    {
                        soln[students.top().index] = elem->index - students.top().index;
                    }
                    else
                    {
                        if (soln[students.top().index] == -1)
                        {
                            soln[students.top().index] = elem->index - students.top().index + n;
                        }
                    }
                    students.pop();
                }
                students.push(*elem);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << soln[i] << " ";
    }
    cout << "\n";
    return 0;
}