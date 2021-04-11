#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int romanToInt1(string s)
{
    int len = s.size(), result = 0;
    unordered_map<char, int> dict{
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    auto curNum = [s, dict](int index) -> int {
        char c = s[index], next_c = s[index + 1];
        int sign = 1;
        switch (c)
        {
        case 'I':
        {
            if (next_c == 'V' || next_c == 'X')
            {
                sign = -1;
            }
            break;
        }
        case 'X':
        {
            if (next_c == 'L' || next_c == 'C')
            {
                sign = -1;
            }
            break;
        }
        case 'C':
        {
            if (next_c == 'D' || next_c == 'M')
            {
                sign = -1;
            }
            break;
        }
        default:
        {
            break;
        }
        }
        return sign * dict.at(c);
    };
    for (size_t i = 0; i < len - 1; i++)
    {
        result += curNum(i);
    }
    result += dict.at(s[len - 1]);
    return result;
}
int romanToInt(string s)
{
    unordered_map<char, int> dict{
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

    int len = s.size(), result = 0, cur_num = 0;
    int pre_num = dict.at(s[0]);

    for (size_t i = 1; i < len; i++)
    {
        cur_num = dict.at(s[i]);
        if (cur_num > pre_num)
        {
            result -= pre_num;
        }
        else
        {
            result += pre_num;
        }
        pre_num = cur_num;
    }
    result += pre_num;
    return result;
}
int main()
{
    cout << romanToInt("CMXCIX") << endl;
}