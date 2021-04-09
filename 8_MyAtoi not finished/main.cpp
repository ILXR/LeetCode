#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s)
{
    int statusSwitch[3][4] = {{0, 1, 2, 3}, {3, 3, 2, 3}, {3, 3, 2, 3}};
    short status = 0, sign = 1;
    long result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (status == 3)
        {
            // 结束
            break;
        }
        char chr = s[i];
        if (chr == ' ')
        {
            status = statusSwitch[status][0];
        }
        else if (chr == '+' || chr == '-')
        {
            if (chr == '-' && status == 0)
            {
                sign = -1;
            }
            status = statusSwitch[status][1];
        }
        else if (chr >= '0' && chr <= '9')
        {
            int num = chr - '0';
            result = result * 10 + num;
            if (result > INT_MAX && sign == 1)
            {
                return INT_MAX;
            }
            if (result - 1 > INT_MAX && sign == -1)
            {
                return INT_MIN;
            }
            status = statusSwitch[status][2];
        }
        else
        {
            status = statusSwitch[status][3];
        }
    }

    return result * sign;
}

int main()
{
    cout << myAtoi("00000-42a1234") << endl;
}