#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size(), num = 1;
        if (len < 2)
        {
            return len;
        }
        for (size_t l = 0, r = 1; r < len;)
        {
            if (nums[l] != nums[r])
            {
                l = r;
                num++;
            }
            while (nums[r] == nums[l] && r < len)
            {
                r++;
            }
        }
        return num;

        // int pre = nums[0];
        // for (auto iter = nums.begin() + 1; iter != nums.end();)
        // {
        //     int cur = *iter;
        //     if (cur == pre)
        //     {
        //         iter = nums.erase(iter);
        //     }
        //     else
        //     {
        //         pre = cur;
        //         iter++;
        //     }
        // }
        // return nums.size();
    }
};

int main()
{
    Solution solu;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solu.removeDuplicates(nums) << endl;
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}