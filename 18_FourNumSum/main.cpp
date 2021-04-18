#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
class Solution
{
public:
    void search(vector<int> &nums, vector<vector<int>> &result, int end, int &target)
    {
        int endNum = nums[end];

        for (size_t i = 0; i < end - 2;)
        {
            int left = i + 1, right = end - 1;
            while (left < right)
            {
                int temTar = nums[i] + endNum + nums[left] + nums[right];
                int res = temTar - target;
                if (res == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right], endNum});
                }
                if (res >= 0)
                {
                    right--;
                    while (right < end - 1 && left < right && nums[right] == nums[right + 1])
                        right--;
                }
                if (res <= 0)
                {
                    left++;
                    while (left > i + 1 && left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }
            i++;
            if (i > 0)
            {
                while (i < end - 2 && nums[i] == nums[i - 1])
                    i++;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 4)
        {
            return result;
        }

        sort(nums.begin(), nums.end());
        for (size_t i = len - 1; i >= 3;)
        {
            search(nums, result, i--, target);
            if (i < len - 1)
            {
                while (i > 2 && nums[i] == nums[i + 1])
                {
                    i--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = solution.fourSum(nums, 0);
    cout << "eeee" << endl;
    for (size_t i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}