#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s.insert(0, " ");
        p.insert(0, " ");
        int s_size = s.size(), p_size = p.size();
        vector<vector<bool>> dp(s_size, vector<bool>(p_size, false));
        dp[0][0] = true;
        int j = 1;
        while (j < p_size && p[j] == '*')
        {
            dp[0][j] = true;
            j++;
        }
        for (int i = 1; i < s_size; i++)
        {
            for (int j = 1; j < p_size; j++)
            {
                dp[i][j] = ((p[j] == s[i] || p[j] == '?') && dp[i - 1][j - 1]) || (p[j] == '*' && (dp[i][j - 1] || dp[i - 1][j]));
            }
        }
        return dp[s_size - 1][p_size - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;

    auto res = solu.isMatch("acdcb", "*a*b");
    cout << res << endl;

    return 0;
}
