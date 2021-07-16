#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            max_sum = max(max_sum, nums[i]);
        }
        return max_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;

    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    auto res = solu.maxSubArray(nums);
    cout << res << endl;

    return 0;
}
