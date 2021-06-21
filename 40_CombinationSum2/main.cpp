#include <iostream>
#include <string>
#include <string.h>
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
private:
    vector<vector<int>> result;
    vector<int> tem;
    int size;

    void dfs(int start, vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            result.emplace_back(tem);
            return;
        }
        if (start == size)
        {
            return;
        }
        int pre_num = -1;
        for (int i = start; i < size; i++)
        {
            int num = candidates[i];
            if (num == pre_num)
            {
                continue;
            }
            pre_num = num;
            if (num > target)
            {
                break;
            }
            else
            {
                tem.emplace_back(num);
                dfs(i + 1, candidates, target - num);
                tem.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        result.clear();
        tem.clear();
        size = candidates.size();
        dfs(0, candidates, target);
        return result;
    }
};

int main()
{
    Solution solu;
    vector<int> candidates{2,5,2,1,2};
    int target = 5;
    auto result = solu.combinationSum2(candidates, target);
    cout << 222;
}