#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int N;
    int result;
    vector<bool> row, column, line1, line2;

    void dfs(int index)
    {
        if (index == N)
        {
            result += 1;
            return;
        }
        for (int j = 0; j < N; j++)
        {
            int index1 = j - index + N - 1, index2 = index + j;
            if (!row[index] && !column[j] && !line1[index1] & !line2[index2])
            {

                row[index] = column[j] = line1[index1] = line2[index2] = true;
                dfs(index + 1);
                row[index] = column[j] = line1[index1] = line2[index2] = false;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        N = n;
        result = 0;
        row = vector<bool>(N, false);
        column = vector<bool>(N, false);
        line1 = vector<bool>(2 * N - 1, false);
        line2 = vector<bool>(2 * N - 1, false);
        dfs(0);
        return result;
    }
};