#include <iostream>
#include <vector>

using namespace std;

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
    int N1 = nums1.size(), N2 = nums2.size(), Num = N1 + N2, index, cur1, cur2, begin1 = 0, begin2 = 0;

    if (N1 == 0)
    {
        return getMiddleNum(nums2, N2);
    }
    if (N2 == 0)
    {
        return getMiddleNum(nums1, N1);
    }

    bool twoNum = (Num % 2 == 0);
    Num /= 2;
    if (!twoNum)
    {
        Num++;
    }

    while (Num > 1 && N1 > 0 && N2 > 0)
    {
        index = min(Num / 2, min(N1, N2)) - 1;
        cur1 = nums1[index + begin1];
        cur2 = nums2[index + begin2];
        if (cur1 < cur2)
        {
            begin1 += (index + 1);
            N1 -= (index + 1);
        }
        else
        {
            begin2 += (index + 1);
            N2 -= (index + 1);
        }
        Num -= (index + 1);
    }
    if (N1 == 0)
    {
        if (twoNum)
        {
            return double(nums2[begin2 + Num - 1] + nums2[begin2 + Num]) / 2;
        }
        else
        {
            return double(nums2[begin2 + Num-1]);
        }
    }
    if (N2 == 0)
    {
        if (twoNum)
        {
            return double(nums1[begin1 + Num - 1] + nums1[begin1 + Num]) / 2;
        }
        else
        {
            return double(nums1[begin1 + Num-1]);
        }
    }
    if (Num == 1)
    {
        if (twoNum)
        {
            int result = 0, count = 2;
            while (count > 0)
            {
                if (N1 == 0 || (N1 > 0 && N2 > 0 && nums2[begin2] <= nums1[begin1]))
                {
                    result += nums2[begin2];
                    begin2++;
                    N2--;
                }
                else if (N2 == 0 || (N1 > 0 && N2 > 0 && nums1[begin1] <= nums2[begin2]))
                {
                    result += nums1[begin1];
                    begin1++;
                    N1--;
                }
                count--;
            }
            return double(result) / 2;
        }
        else
            return double(min(nums1[begin1], nums2[begin2]));
    }
}

int main()
{
    int al[] = {1}, bl[] = {2, 3};
    vector<int> a(al, al + 1), b(bl, bl + 2);
    cout << findMedianSortedArrays(a, b) << endl;
}