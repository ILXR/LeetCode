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
    int findMid(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, first = nums[0];
        if (nums.size() == 1 || first <= nums[r])
        {
            return -1;
        }
        while (r - l > 1)
        {
            int mid = (l + r) / 2, mid_val = nums[mid];
            if (mid_val > first)
            {
                l = mid;
            }
            else if (mid_val < first)
            {
                r = mid;
            }
        }
        return l;
    }
    int find(vector<int> &nums, int &target, int left, int right)
    {
        while (right > left + 1)
        {
            int mid = (left + right) / 2, mid_val = nums[mid];
            if (mid_val == target)
            {
                return mid;
            }
            else if (mid_val > target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
    int search(vector<int> &nums, int target)
    {
        int mid = findMid(nums),size = nums.size();
        if (mid == -1)
        {
            return find(nums, target, 0, size);
        }
        else if (target >= nums[0])
        {
            return find(nums, target, 0, mid + 1);
        }
        else
        {
            return find(nums, target, mid + 1, size);
        }
    }
};

int main()
{
    Solution solu;
    vector<int> nums({4, 5, 6, 7, 0, 1, 2});
    int target = 2;
    int result = solu.search(nums, target);
    cout << "result:" << endl;
    cout << result << endl;
    cout << "end" << endl;
}