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
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size();

        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = size - 1;
            while (j > i && nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    Solution solu;
    vector<int> nums({2, 3, 1});
    solu.nextPermutation(nums);
    cout << "result:" << endl;
    for (auto res : nums)
    {
        cout << res << endl;
    }
    cout << "end" << endl;
}