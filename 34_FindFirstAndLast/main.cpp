#include <iostream>
#include <string>
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
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l, r, size = nums.size();
        vector<int> result = {-1, -1};
        if (size == 0 || target<nums[0] || target>nums[size-1])
        {
            return result;
        }
        // First
        l = -1, r = size - 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            int mid_val = nums[mid];
            if (mid_val >= target)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if (nums[r] == target)
        {
            result[0] = r;
        }else{
            return result;
        }
        // Last
        l = 0, r = size;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            int mid_val = nums[mid];
            if (mid_val <= target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (nums[l] == target)
        {
            result[1] = l;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<int> nums({5});
    int target = 5;
    vector<int> result = solu.searchRange(nums, target);
    cout << "result: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
