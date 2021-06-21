#include <iostream>
#include <string>
#include <string.h>
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
private:
    bool rows[9][9];
    bool columns[9][9];
    bool blocks[9][9];
    bool succeed;
    vector<pair<int, int>> spaces;

    void DFS(vector<vector<char>> &board, int index)
    {
        if (index == spaces.size())
        {
            succeed = true;
            return;
        }
        auto [i, j] = spaces[index];
        int area = (i / 3) * 3 + (j / 3);
        for (int num = 0; num < 9 && !succeed; num++)
        {
            if (rows[i][num] && columns[j][num] && blocks[area][num])
            {
                board[i][j] = '0' + num + 1;
                rows[i][num] = columns[j][num] = blocks[area][num] = false;
                DFS(board, index + 1);
                rows[i][num] = columns[j][num] = blocks[area][num] = true;
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        succeed = false;
        memset(rows, true, sizeof(rows));
        memset(columns, true, sizeof(columns));
        memset(blocks, true, sizeof(blocks));
        spaces.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    spaces.push_back(pair(i, j));
                }
                else
                {
                    int num = c - '0' - 1;
                    int area = (i / 3) * 3 + (j / 3);
                    rows[i][num] = columns[j][num] = blocks[area][num] = false;
                }
            }
        }
        DFS(board,0);
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<vector<char>> board{{'1', '2', '3'}, {'1', '2', '3'}, {'1', '2', '3'}};
    solu.solveSudoku(board);
    /* code */
    return 0;
}
