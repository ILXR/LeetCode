#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string intToRoman(int num)
{
    int all_num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    auto int_roman = [](int num) -> string {
        switch (num)
        {
        case 1000:
            return "M";
        case 900:
            return "CM";
        case 500:
            return "D";
        case 400:
            return "CD";
        case 100:
            return "C";
        case 90:
            return "XC";
        case 50:
            return "L";
        case 40:
            return "XL";
        case 10:
            return "X";
        case 9:
            return "IX";
        case 5:
            return "V";
        case 4:
            return "IV";
        case 1:
            return "I";
        default:
            return "";
        }
    };
    stringstream result_stream;
    for (size_t i = 0; i < 13; i++)
    {
        int cur_num = all_num[i];
        if (cur_num > num)
        {
            continue;
        }
        while (num >= cur_num)
        {
            num -= cur_num;
            result_stream << int_roman(cur_num);
        }
    }
    return result_stream.str();
}

int main()
{
    cout << intToRoman(1994) << endl;
}