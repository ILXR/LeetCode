#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int end = 0, cur_max = 0, step = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            cur_max = max(cur_max, i + nums[i]);
            if (i == end)
            {
                step++;
                end = cur_max;
            }
        }
        return step;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    auto nums = new vector<int>({2,1});
    int res = solu.jump(*nums);
    cout << res << endl;
    return 0;
}
