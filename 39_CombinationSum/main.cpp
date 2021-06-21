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
    void dfs(int index, int &target, vector<int> &candidates)
    {
        if (target == 0)
        {
            result.push_back(tem);
            return;
        }

        for (int i = index; i < size; i++)
        {
            int num = candidates[i];
            if (num > target)
            {
                return;
            }
            else
            {
                tem.push_back(num);
                dfs(i, target -= num, candidates);
                target += num;
                tem.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        result.clear();
        tem.clear();
        size = candidates.size();
        dfs(0, target, candidates);
        return result;
    }
};

int main()
{
    Solution solu;
    vector<int> candidates{2, 3, 5};
    int target = 8;
    auto result = solu.combinationSum(candidates, target);
    cout << 222;
}