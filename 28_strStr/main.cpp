#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int len_h = haystack.size(), len_n = needle.size();
        if (len_n == 0)
            return 0;
        if (len_h == 0 || len_h < len_n)
            return -1;
        vector<int> next(len_n, -1);
        int i, j;
        for (i = 0, j = -1; i < len_n - 1;)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
        for (i = 0, j = 0; i < len_h && j < len_n;)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == len_n)
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution solu;
    int result = solu.strStr("aaaaa", "bba");
    cout << result << endl;
    cout << "hello world" << endl;
}