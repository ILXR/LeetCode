#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int size;
    bool *flags;
    vector<vector<int>> result;
    void dfs(int index, vector<int> &nums, vector<int> &tem)
    {
        if (index == size)
        {
            result.push_back(tem);
            return;
        }
        for (int i = 0; i < size; i++)
        {
            if (flags[i])
            {
                tem.push_back(nums[i]);
                flags[i] = false;
                dfs(index + 1, nums, tem);
                flags[i] = true;
                tem.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        size = nums.size();
        flags = (bool *)malloc(size * sizeof(bool));
        memset(flags, true, sizeof(bool) * size);
        vector<int> tem;
        dfs(0, nums, tem);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
