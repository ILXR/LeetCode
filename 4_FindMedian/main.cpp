#include <iostream>
#include <vector>

using namespace std;

// 切后面一半
void removeBack(vector<int> &nums, int &len)
{
    if (len % 2 == 0)
    {
        len /= 2;
    }
    else
    {
        len = len / 2 + 1;
    }
}

// 切前面一半
void removeFront(vector<int> &nums, int &len)
{
    copy(nums.begin() + len / 2, nums.begin() + len, nums.begin());
    if (len % 2 == 0)
    {
        len /= 2;
    }
    else
    {
        len = len / 2 + 1;
    }
}

double getMiddleNum(vector<int> &nums, int len)
{
    int middle = len / 2;
    if (len % 2 == 0)
    {
        return double(nums[middle] + nums[middle - 1]) / 2;
    }
    else
    {
        return double(nums[middle]);
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int N1 = nums1.size(), N2 = nums2.size();
    double mid1, mid2;
    if (N1 == 0)
    {
        return getMiddleNum(nums2, N2);
    }
    if (N2 == 0)
    {
        return getMiddleNum(nums1, N1);
    }
    while (N1 > 1 || N2 > 1)
    {
        mid1 = getMiddleNum(nums1, N1);
        mid2 = getMiddleNum(nums2, N2);
        if (mid1 == mid2)
        {
            return mid1;
        }
        if (mid1 > mid2) // mid1 大
        {
            // 中间数大的切后面，中间数小的切前面
            if (N1 > N2)
            {
                // 切mid1后面，只修改长度就行
                removeBack(nums1, N1);
            }
            else
            {
                // 切mid2前面
                removeFront(nums2, N2);
            }
        }
        else // mid2 大
        {
            // 中间数大的切后面，中间数小的切前面
            if (N1 > N2)
            {
                removeFront(nums1, N1);
            }
            else
            {
                removeBack(nums2, N2);
            }
        }
    }
    return double(nums1[0] + nums2[0]) / 2;
}

int main()
{
    int al[4] = {2, 2, 4, 4}, bl[4] = {2, 2, 4, 4};
    vector<int> a(al, al + 4), b(bl, bl + 4);
    cout << getMiddleNum(a, 2) << " " << getMiddleNum(b, 1) << endl;
    cout << findMedianSortedArrays(a, b) << endl;
}