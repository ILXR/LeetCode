#include <iostream>
#include <string>

using namespace std;
int reverse(int x)
{
    int max_tem = INT_MAX / 10, max_cur = INT_MAX - max_tem * 10;
    int result = 0, sign = x < 0 ? -1 : 1, cur;
    x = abs(x);
    while (x > 0)
    {
        cur = x % 10;
        if ((result > max_tem || (result == max_tem && cur >= max_cur)))
        {
            return 0;
        }
        x /= 10;
        result = result * 10 + cur;
    }
    if ((result >> 31) & 1)
    {
        return 0;
    }
    return result * sign;
}

int reverse2(int x)
{
    bool sign = x < 0;
    char c;
    string s = to_string(x), max_int = to_string(INT_MAX);
    if (s[0] == '-')
    {
        s.erase(0, 1);
    }
    int size = s.size(), index;
    for (size_t i = 0; i < (size / 2); i++)
    {
        index = size - 1 - i;
        c = s[i];
        s[i] = s[index];
        s[index] = c;
    }
    try
    {
        return sign ? stoi(s) * -1 : stoi(s);
    }
    catch (exception e)
    {
        return 0;
    }
    // if (size == max_int.size() && s > max_int)
    // {
    //     return 0;
    // }
    // return sign ? stoi(s) * -1 : stoi(s);
}

int main()
{
    cout << reverse2(-2147483648) << endl;
}