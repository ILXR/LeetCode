#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool all_rows[9][9] = {false};
        bool all_columns[9][9] = {false};
        bool all_area[9][9] = {false};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char s = board[i][j];
                if (s == '.')
                {
                    continue;
                }
                int num = s - '1';
                int area = (i / 3) * 3 + (j / 3);
                if (all_rows[num][i] || all_columns[num][j] || all_area[num][area])
                {
                    return false;
                }
                all_rows[num][i] = true;
                all_columns[num][j] = true;
                all_area[num][area] = true;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<vector<char>> board{{'1', '2', '3'}, {'1', '2', '3'}, {'1', '2', '3'}};
    bool result = solu.isValidSudoku(board);
    if (result)
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
    /* code */
    return 0;
}
