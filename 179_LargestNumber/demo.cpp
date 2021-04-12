#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int len = nums.size();
        vector<string> vsn;

        for (int i = 0; i < len; i++)
        {
            vsn.push_back(to_string(nums[i]));
        }

        int count = 0;

        sort(vsn.begin(), vsn.begin()+vsn.size(), [&count](string &a, string &b) -> bool {
            cout << ++count << endl;
            if (count == 100)
            {
                cout << 233 << endl;
            }
            int len = max(a.size(), b.size());
            for (int i = 0, j = 0; i < len || j < len; i++, j++)
            {
                if (!a[i])
                    i = 0;
                if (!b[j])
                    j = 0;

                if (a[i] != b[j])
                    return a[i] > b[j];
            }
            return false;
        });

        if (vsn[0][0] == '0')
            return "0";

        ostringstream oss;
        for (auto i : vsn)
        {
            oss << i;
        }

        return oss.str();
    }
};

int main()
{
    Solution s;
    vector<int> a{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << s.largestNumber(a);
}