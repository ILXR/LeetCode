#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        string start = "0000";
    }
    bool cantGo(vector<string> &deadends, string &target)
    {
        if (deadends.size() < 8)
        {
            return false;
        }
        bool res = true;
        for (int i = 0; i < 4; i++)
        {
            string tem = target;
            tem[i] += 1;
            tem[i] %= 10;
            auto has = find(deadends.begin(), deadends.end(), tem);
            if (has == deadends.end())
            {
                return false;
            }
            tem[i] += 8;
            tem[i] %= 10;
            auto has = find(deadends.begin(), deadends.end(), tem);
            if (has == deadends.end())
            {
                return false;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
