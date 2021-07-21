#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int N;
    vector<vector<string>> result;
    vector<string> tem;
    vector<bool> row, column, line1, line2;

    void dfs(int index)
    {
        if (index == N)
        {
            result.push_back(tem);
            return;
        }
        for (int j = 0; j < N; j++)
        {
            if (!row[index] && !column[j] && !line1[j - index + N - 1] & !line2[index + j])
            {
                tem[index][j] = 'Q';
                row[index] = column[j] = line1[j - index + N - 1] = line2[index + j] = true;
                dfs(index + 1);
                tem[index][j] = '.';
                row[index] = column[j] = line1[j - index + N - 1] = line2[index + j] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        tem = vector<string>(N, string(N, '.'));
        row = vector<bool>(N, false);
        column = vector<bool>(N, false);
        line1 = vector<bool>(2 * N - 1, false);
        line2 = vector<bool>(2 * N - 1, false);
        dfs(0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;

    auto res = solu.solveNQueens(4);

    return 0;
}
