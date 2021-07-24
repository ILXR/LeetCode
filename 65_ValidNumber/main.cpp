#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> folatState{{2, 1, 3, 5}, {2, 5, 3, 5}, {2, 5, 3, 5}, {4, 5, 5, 5}, {4, 5, 5, 5}};
    vector<vector<int>> intState{{2, 1, 3, 3}, {2, 3, 3, 3}, {2, 3, 3, 3}};
    int getAction(char &c)
    {
        if (c >= '0' && c <= '9')
            return 0;
        else if (c == '+' || c == '-')
            return 1;
        else if (c == '.')
            return 2;
        else
            return 3;
    }
    bool isFloat(string &s)
    {
        int state = 0;
        bool hasPoint = false, hasNum = false;
        for (auto &c : s)
        {
            int action = getAction(c);
            state = folatState[state][action];
            if (state == 5)
                return false;
            if (state == 3)
                hasPoint = true;
            if (state == 2 || state == 4)
                hasNum = true;
        }
        return hasPoint && hasNum;
    }
    bool isInt(string &s)
    {
        int state = 0;
        bool hasNum = false;
        for (auto &c : s)
        {
            int action = getAction(c);
            state = intState[state][action];
            if (state == 3)
                return false;
            if (state == 2)
                hasNum = true;
        }
        return hasNum;
    }
    bool isNumber(string s)
    {
        int count = 0, size = s.size(), divid = -1;
        bool hasPoint = false;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            if (c == 'e' || c == 'E')
            {
                count++;
                divid = i;
            }
            if (c == '.')
                hasPoint = true;
        }
        switch (count)
        {
        case 0:
            return hasPoint ? isFloat(s) : isInt(s);
        case 1:
        {
            string str1 = s.substr(0, divid), str2 = s.substr(divid + 1, size - divid - 1);
            return isInt(str2) && (hasPoint ? isFloat(str1) : isInt(str1));
            break;
        }
        default:
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    string strs[] = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

    for (auto str : strs)
    {
        auto res = solu.isNumber(str);
        cout << res << endl;
    }

    return 0;
}
