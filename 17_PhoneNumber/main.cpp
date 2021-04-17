#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <sstream>

using namespace std;
class Solution
{
private:
    vector<int> counts;
    stringstream temString;
    vector<string> result;
    string digits;

    inline char number2char(int number, int index)
    {
        if (number < 7)
            return 'a' + (number - 2) * 3 + index;
        switch (number)
        {
        case 7:
        {
            return 'p' + index;
            break;
        }
        case 8:
        {
            return 't' + index;
            break;
        }
        case 9:
        {
            return 'w' + index;
            break;
        }
        default:
            return 'a';
            break;
        }
    }

    void getString(int len)
    {
        temString.str("");
        for (size_t i = 0; i < len; i++)
        {
            temString << number2char(digits[i] - '0', counts[i]);
        }
        result.push_back(temString.str());
    }
    void traverse(int index, int &len)
    {
        if (index == len)
        {
            getString(len);
            return;
        }
        for (size_t i = 0; i < getLength(digits[index] - '0'); i++)
        {
            counts[index] = i;
            traverse(index + 1, len);
        }
    }
    inline int getLength(int number)
    {
        return (number == 9 || number == 7) ? 4 : 3;
    }

public:
    Solution() : counts(0), result(0) {}
    vector<string> letterCombinations(string digits)
    {
        int len = digits.size();
        if (len == 0)
            return result;
        counts.resize(len);
        temString.str("");
        this->digits = digits;
        traverse(0, len);
        return this->result;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.letterCombinations("7");
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}