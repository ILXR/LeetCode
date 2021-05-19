/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int sign =( dividend >> 31) ^ (divisor >> 31);
        dividend = abs(dividend);
        divisor = abs(divisor);
        int count = 0;
        while (dividend > divisor)
        {
            dividend -= divisor;
            count++;
        }
        sign = sign<<31;
        return count | sign;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solu;
    int result = solu.divide(7, -3);
    cout << result << endl;
    return 0;
}
