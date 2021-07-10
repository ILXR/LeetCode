#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size(), max_sub = INT32_MAX, sum;
        for (int i = 0; i < size - 2; i++)
        {
            int cur = nums.at(i), left = i + 1, right = size - 1;
            while (left < right)
            {
                int tem = cur + nums.at(left) + nums.at(right);
                int tem_sub = abs(tem - target);
                if (tem_sub < max_sub)
                {
                    max_sub = tem_sub;
                    sum = tem;
                }
                if (tem == target)
                    return target;
                if (tem > target)
                    right--;
                else
                    left++;
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<int> nums{-1, 2, 1, -4};
    auto res = solu.threeSumClosest(nums, 1);
    return 0;
}
