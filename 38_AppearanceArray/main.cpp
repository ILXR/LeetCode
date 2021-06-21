#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string str = "1";
        stringstream stream;
        while (n > 1)
        {
            int index = 0, len = str.length();
            while (index < len)
            {
                char cur_num = str[index];
                int cur_count = 0;
                while (str[index] == cur_num && index < len)
                {
                    index++;
                    cur_count++;
                }
                stream << cur_count << cur_num;
            }
            str = stream.str();
            stream.str("");
            n--;
        }
        return str;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    int num = 10;
    string result = solu.countAndSay(num);
    cout << "result:" << endl;
    cout << result << endl;
    cout << "end" << endl;
    return 0;
}
