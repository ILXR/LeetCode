#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.size() == 0)
        {
            return vector<vector<int>>{newInterval};
        }
        int i = 0, len;
        vector<vector<int>> result;
        for (auto &item : intervals)
        {
            if (item[0] >= newInterval[0])
            {
                break;
            }
            else
            {
                result.push_back(item);
                i++;
            }
        }
        auto insert = [&](vector<int> &item)
        {
            if (len < 0 || item[0] > result[len][1])
            {
                result.push_back(item);
                len++;
            }
            else
            {
                result[len][1] = max(result[len][1], item[1]);
            }
        };
        len = i - 1;
        insert(newInterval);
        for (; i < intervals.size(); i++)
        {
            insert(intervals[i]);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
