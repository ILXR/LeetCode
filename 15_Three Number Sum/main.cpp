#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int len = nums.size();
    vector<vector<int>> result;
    if (len < 3)
    {
        return result;
    }

    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < len - 2 && nums[i] <= 0; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1, right = len - 1;
        while (left < right)
        {
            if (nums[i] + nums[left] > 0)
            {
                break;
            }
            if (left != i + 1 && nums[left] == nums[left - 1])
            {
                left++;
                continue;
            }
            int tem = nums[left] + nums[right] + nums[i];
            if (tem == 0)
            {
                vector<int> temVec = {nums[i], nums[left], nums[right]};
                result.push_back(temVec);
                left++;
                right--;
            }
            else if (tem > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(n1);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}