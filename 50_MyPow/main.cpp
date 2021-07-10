#include <bits/stdc++.h>

using namespace std;

class Solution
{
    double pow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        double temp = myPow(x, n / 2);
        return n % 2 == 0 ? temp * temp : temp * temp * x;
    }

public:
    double myPow(double x, int n)
    {
        bool neg = (n < 0);
        n = abs(n);
        return neg ? 1 / pow(x, n) : pow(x, n);
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    auto res = solu.myPow(2, 3);
    cout << res << endl;
    return 0;
}
