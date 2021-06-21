#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        if (size < 3)
            return 0;
        int *l_max = (int *)malloc(sizeof(int) * size);
        memset(l_max, 0, sizeof(l_max));
        int *r_max = (int *)malloc(sizeof(int) * size);
        memset(r_max, 0, sizeof(r_max));

        l_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            l_max[i] = max(l_max[i - 1], height[i]);
        }
        r_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            r_max[i] = max(r_max[i + 1], height[i]);
        }

        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result += min(l_max[i], r_max[i]) - height[i];
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<int> height{4, 2, 0, 3, 2, 5};
    int result = solu.trap(height);
    cout << result << endl;
    return 0;
}
