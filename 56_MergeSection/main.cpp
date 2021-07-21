#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int len = 0;
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > result[len][1])
            {
                result.push_back(intervals[i]);
                len++;
            }
            else
            {
                result[len][1] = max(result[len][1], intervals[i][1]);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
