#include <iostream>
#include <string>

using namespace std;
void getPalindromeSize(int index, bool mid, string &s, int &max_len, int &start_)
{
    int start(mid ? index - 1 : index), end(index), len(s.size());
    while (s[start] == s[end] && start > 0 && end < len)
    {
        start--;
        end++;
    }
    if (s[start] == s[end])
    {
        // 因为碰到了边界而停止
        int size = end - start + 1;
        if (size > max_len)
        {
            start_ = start;
            max_len = size;
        }
    }
    else
    {
        // 因为不相等而停止
        int size = end - start - 1;
        if (size > max_len)
        {
            start_ = start + 1;
            max_len = size;
        }
    }
}
string longestPalindrome(string s)
{
    int len(s.size()), max_len(0), start(0);
    if (len <= 1)
        return s;
    bool mid(true);
    for (size_t i = 1; i < len; i++)
    {
        int max = (len - i) * 2;
        if (max < max_len)
            break;
        mid = true;
        getPalindromeSize(i, mid, s, max_len, start);
        mid = false;
        getPalindromeSize(i, mid, s, max_len, start);
    }
    return s.substr(start, max_len);
}

int main()
{
    string s = "abcdbbfcba";
    cout << longestPalindrome(s) << endl;
    // cout << s.substr(0, 1) << " " << s.substr(0, 2) << endl;
}