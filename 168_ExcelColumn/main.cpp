#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int a0 = (columnNumber - 1) % 26 + 1;
            ans += a0 - 1 + 'A';
            columnNumber = (columnNumber - a0) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    string res = solu.convertToTitle(701);
    cout << res << endl;
    return 0;
}
