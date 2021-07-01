#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> match = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    unordered_set<string> deadBoard;
    deque<pair<string, int>> boards;
    string end = "123450";

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string start = getBoardStr(board);
        if (start == end)
        {
            return 0;
        }
        boards.push_back(pair<string, int>(start, 0));
        while (!boards.empty())
        {
            auto [str, step] = boards.front();

            int pre = str.find('0');
            for (int i = 0; i < match[pre].size(); i++)
            {
                int next = match[pre][i];
                if (next >= 0)
                {
                    swap(str[pre], str[next]);
                    if (!deadBoard.count(str))
                    {
                        if (str == end)
                        {
                            return step + 1;
                        }
                        boards.push_back(pair<string, int>(str, step + 1));
                        deadBoard.insert(str);
                    }
                    swap(str[pre], str[next]);
                }
            }
            boards.pop_front();
        }
        return -1;
    }
    string getBoardStr(vector<vector<int>> &board)
    {
        string res = "123450";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                res[i * 3 + j] = board[i][j] + '0';
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<vector<int>> board{{1, 2, 3}, {4, 0, 5}};
    int res = solu.slidingPuzzle(board);
    cout << 232323232 << endl;
    return 0;
}
