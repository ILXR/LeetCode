#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string largestNumber(vector<int> &nums)
{
    vector<string> str_nums;
    int len = nums.size();
    for (size_t i = 0; i < len; i++)
    {
        str_nums.push_back(to_string(nums[i]));
    }
    sort(str_nums.begin(), str_nums.end(), [](string &a, string &b) -> bool {
        return a + b > b + a;
    });
    string result = "";
    for (size_t i = 0; i < len; i++)
    {
        result += str_nums[i];
    }
    if (result.size() == 0 || result[0] == '0')
    {
        return "0";
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
}