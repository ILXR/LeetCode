#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
vector<int> maxVec(vector<int> nums1, vector<int> nums2)
{
    int len_1 = nums1.size();
    if (len_1 != nums2.size())
    {
        return nums1;
    }
    for (size_t i = 0; i < len_1; i++)
    {
        if (nums1[i] > nums2[i])
        {
            return nums1;
        }
        else if (nums2[i] > nums1[i])
        {
            return nums2;
        }
        else
        {
            continue;
        }
    }
    return nums1;
}

int compare(vector<int> &one, int index1, vector<int> &two, int index2)
{
    int x = one.size(), y = two.size();
    while (index1 < x && index2 < y)
    {
        int tag = one[index1++] - two[index2++];
        if (tag != 0)
            return tag;
    }
    return (x - index1) - (y - index2);
}

vector<int> merge(vector<int> nums1, vector<int> nums2)
{
    vector<int> result;
    int len_1 = nums1.size(), len_2 = nums2.size();
    if (len_1 == 0)
        return nums2;
    if (len_2 == 0)
        return nums1;

    for (size_t i = 0, j = 0; i < len_1 || j < len_2;)
    {
        if (i == len_1)
        {
            result.push_back(nums2[j]);
            j++;
            continue;
        }
        if (j == len_2)
        {
            result.push_back(nums1[i]);
            i++;
            continue;
        }

        // if (compare(one, a, two, b) > 0)
        //     res[i++] = one[a++];
        // else
        //     res[i++] = two[b++];
    }
    return result;
}

vector<int> getStack(vector<int> &nums, int k)
{
    stack<int> upStack;
    vector<int> result(k);
    vector<int>::iterator iter;
    if (k == 0)
    {
        return result;
    }

    int len = nums.size(), needPop = len - k;
    upStack.push(nums[0]);
    for (size_t i = 1; i < len; i++)
    {
        if (upStack.size() == k)
        {
            break;
        }
        if (nums[i] > upStack.top() && needPop > 0)
        {
            upStack.pop();
            needPop--;
        }
        upStack.push(nums[i]);
    }
    for (int i = upStack.size() - 1; i >= 0; i--)
    {
        result[i] = upStack.top();
        upStack.pop();
    }
    return result;
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int len_1 = nums1.size(), len_2 = nums2.size();
    if (len_1 == 0)
    {
        return getStack(nums2, k);
    }
    if (len_2 == 0)
    {
        return getStack(nums1, k);
    }

    vector<int> result(k, 0);
    int min_1 = k - min(k, len_2), max_1 = min(k, len_1);
    for (size_t num_1 = min_1; num_1 <= max_1; num_1++)
    {
        int num_2 = k - num_1;
        vector<int> temNum1(getStack(nums1, num_1));
        vector<int> temNum2(getStack(nums2, num_2));
        vector<int> temResult(merge(temNum1, temNum2));
        result = maxVec(result, temResult);
    }

    return result;
}

int main()
{
    vector<int> a = {6, 7};
    vector<int> b = {6, 0, 4};
    vector<int> max = maxNumber(a, b, 5);
    for (size_t i = 0; i < max.size(); i++)
    {
        cout << max[i];
        cout << endl;
    }
}