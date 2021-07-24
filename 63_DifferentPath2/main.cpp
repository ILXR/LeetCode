#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        string test = "123";
        int m = obstacleGrid.size(), n = obstacleGrid[0].size(), i, j;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution solu;
    auto res = solu.uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    return 0;
}
