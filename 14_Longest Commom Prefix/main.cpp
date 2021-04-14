#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }

    int shortest_len = INT_MAX;
    for (size_t i = 0; i < strs.size(); i++)
    {
        if (strs[i].size() < shortest_len)
        {
            shortest_len = strs[i].size();
        }
    }

    for (int i = 0; i < shortest_len; i++)
    {
        char c = strs[0][i];
        for (size_t j = 1; j < strs.size(); j++)
        {
            if (strs[j].size() == i || strs[j][i] != c)
            {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0].substr(0, shortest_len);
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs1 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs) << endl;
}