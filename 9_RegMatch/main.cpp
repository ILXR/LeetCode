#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
    int p_start = 0, p_end, p_len = p.size();
    int s_start = 0, s_end, s_len = s.size();
    while (p_start < p_len)
    {
        p_end = p.find('*', p_start); // *
        if (p_end != p.npos)
        {
            // 找到了*
            p_end--; // *前面的字符
            s_end = s_start + (p_end - p_start);
            if (s_end > s_len)
            {
                return false;
            }
            // 处理普通字符(包括.)
            for (size_t i = p_start, j = s_start; i < p_end; i++, j++)
            {
                if (p[i] == '.' || p[i] == s[j])
                {
                    continue;
                }
                return false;
            }
            // 处理 p[p_end]*
            size_t count = 0;
            while ((p[p_end] == '.' || s[s_end] == p[p_end]) && s_end < s_len)
            {
                s_end++;
                count++;
            }
            if (count != 1)
            { // *匹配成功
                s_start = s_end;
                p_start = p_end + 2;
            }
            else
            {
                return false;
            }
        }
        else // 没有*
        {
            if (p_len - p_start != s_len - s_start)
            {
                return false;
            }
            // 处理普通字符(包括.)
            for (size_t i = p_start, j = s_start; i < p_len; i++, j++)
            {
                if (p[i] == '.' || p[i] == s[j])
                {
                    continue;
                }
                return false;
            }
            return true;
        }
    }
    return s_start >= s_len;
}

int main()
{
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
}