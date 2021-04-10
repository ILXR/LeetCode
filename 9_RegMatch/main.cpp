#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool charMatch(char &s, char &r)
{
    return s == r || r == '.';
}

bool isMatch(string str, string reg)
{
    str = " " + str;
    reg = " " + reg;
    int s_len = str.size(), r_len = reg.size();
    vector<vector<bool>> dp(s_len, vector<bool>(r_len));

    dp[0][0] = true;

    for (size_t i = 0; i < s_len; i++)
    {
        for (size_t j = 1; j < r_len; j++)
        {
            if (reg[j] == '*')
            {
                if (charMatch(str[i], reg[j - 1]))
                {
                    // 匹配当前，扔掉str末尾
                    if (i > 0)
                    {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }

                    // 不匹配当前，扔掉*
                    dp[i][j] = dp[i][j] | dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2];
                }
            }
            else
            {
                // 一般情况
                if (charMatch(str[i], reg[j]))
                {
                    if (i > 0)
                    {
                        dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                    }
                }
            }
        }
    }
    return dp[s_len - 1][r_len - 1];
}

int main()
{
    cout << isMatch("ab", ".*") << endl;
}