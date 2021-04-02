#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
    }
};

int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    if (len <= 1)
    {
        return len;
    }
    unordered_set<char> allChar;
    int begin = 0, max_len = 0, cur_len;
    for (int i = 0; i < s.size(); i++)
    {
        // end在set中，需要不断后移begin，直到end不在set中
        while (allChar.find(s[i]) != allChar.end())
        {
            allChar.erase(s[begin]);
            begin++;
        }
        // end不在set中，将end添加到set，并检索下一个
        allChar.insert(s[i]);

        cur_len = allChar.size();
        max_len = max_len > cur_len ? max_len : cur_len;
    }
    return max_len;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring("") << endl;
}