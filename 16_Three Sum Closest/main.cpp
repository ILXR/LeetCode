#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    int len = nums.size();
    sort(nums.begin(), nums.end());

    int subDiff = INT_MAX, sign = 1, temDiff;
    for (size_t i = 0; i < len - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1, right = len - 1;
        temDiff = nums[left] + nums[right] + nums[i] - target;
        while (left < right)
        {
            int tem = nums[left] + nums[right] + nums[i] - target;
            if (tem == 0)
            {
                return target;
            }
            else if (tem > 0)
            {
                right--;
                while (left <= right && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
            else
            {
                left++;
                while (left <= right && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
            if (abs(tem) < temDiff)
            {
                temDiff = subDiff;
                sign = (tem < 0) ? -1 : 1;
            }
            if ((tem ^ temDiff) >> 31)
            {
                // 符号相反
                break;
            }
            temDiff = tem;
        }
    }
    return target + (sign * subDiff);
}

int main()
{
    vector<int> nums{0, 2, 1, -3};
    cout << threeSumClosest(nums, 1) << endl;
}