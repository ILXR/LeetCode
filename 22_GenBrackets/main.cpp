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
    bool isSymmetric(deque<char> &strDeque)
    {
        deque<char>::iterator left = strDeque.begin(), right = strDeque.end() - 1;
        while (left + 1 != right)
        {
            char l = *left, r = *right;
            if (l + 1 != r && r + 1 != l)
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
    void genBrakets(vector<string> &result, deque<char> &strDeque, stringstream &strStream, int n)
    {
        if (n == 0)
        {
            strStream.str("");
            for (deque<char>::iterator i = strDeque.begin(); i < strDeque.end(); i++)
            {
                strStream << *i;
            }
            result.push_back(strStream.str());
            return;
        }
        else
        {
            bool willRight = true;
            // 直接扩住
            strDeque.push_back(')');
            strDeque.push_front('(');
            genBrakets(result, strDeque, strStream, n - 1);
            strDeque.pop_back();
            strDeque.pop_front();
            // 左加括号
            strDeque.push_front(')');
            strDeque.push_front('(');
            willRight = !isSymmetric(strDeque);
            genBrakets(result, strDeque, strStream, n - 1);
            strDeque.pop_front();
            strDeque.pop_front();
            // 右加括号
            if (willRight)
            {
                strDeque.push_back('(');
                strDeque.push_back(')');
                genBrakets(result, strDeque, strStream, n - 1);
                strDeque.pop_back();
                strDeque.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (!n)
            return result;

        stringstream strStream;
        deque<char> strDeque;
        // init
        strDeque.push_front(')');
        strDeque.push_front('(');
        n--;
        // for
        genBrakets(result, strDeque, strStream, n);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.generateParenthesis(3);
    for (auto &str : result)
    {
        cout << str << endl;
    }
}