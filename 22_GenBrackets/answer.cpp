#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>

using namespace std;

class Solution
{
private:
    void dfs(vector<string> &result, string &temRes, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(temRes);
            return;
        }
        if (left < 0 || right < 0 || left > right)
            return;
        // 添加左括号
        temRes.push_back('(');
        dfs(result, temRes, left - 1, right);
        temRes.pop_back();
        // 添加右括号
        temRes.push_back(')');
        dfs(result, temRes, left, right - 1);
        temRes.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string temRes;
        if (!n)
            return result;
        dfs(result, temRes, n, n);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.generateParenthesis(4);
    cout << "size: " << result.size() << endl;
    for (auto &str : result)
    {
        cout << str << endl;
    }
}