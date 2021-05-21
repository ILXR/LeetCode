#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // 栈方法
        /*
        int max_len = 0;
        stack<int> left;
        left.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left.push(i);
            }
            else
            {
                left.pop();
                if (left.empty())
                {
                    left.push(i);
                }
                else
                {
                    max_len = max(max_len, i - left.top());
                }
            }
        }
        */

        // 动态规划
        int max_len = 0;
        return max_len;
    }
};

int main()
{
    Solution solu;
    string str = ")()())";
    int result = solu.longestValidParentheses(str);
    cout << "result:" << endl;
    cout << result << endl;
    cout << "end" << endl;
}