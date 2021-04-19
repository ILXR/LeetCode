#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        auto char2int = [](char c) -> int {
            switch (c)
            {
            case '(':
                return 1;
            case ')':
                return -1;
            case '{':
                return 2;
            case '}':
                return -2;
            case '[':
                return 3;
            case ']':
                return -3;
            default:
                return 0;
            }
        };
        stack<int> c_stack;
        for (size_t i = 0; i < s.size(); i++)
        {
            int cint = char2int(s[i]);
            int top = c_stack.empty() ? -4 : c_stack.top();
            if (top + cint == 0)
            {
                c_stack.pop();
            }
            else
            {
                if (cint < 0)
                    return false;
                else
                    c_stack.push(cint);
            }
        }
        return c_stack.empty();
    }
};

int main()
{
    Solution solution;
    bool result = solution.isValid("(]");
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}