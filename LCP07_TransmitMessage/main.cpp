#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ipair;

class Solution
{
public:
    int numWays(int n, vector<vector<int>> &relation, int k)
    {
        vector<vector<int>> new_relation(n, vector<int>{});
        for (auto list : relation)
        {
            new_relation[list[0]].push_back(list[1]);
        }
        deque<ipair> que{make_pair(0, k)};
        k++;
        while (k > 0 && que.size() > 0)
        {
            auto [people, step] = que.front();
            if (step < k)
            {
                k--;
                continue;
            }
            for (auto next : new_relation[people])
            {
                que.push_back(make_pair(next, step - 1));
            }
            que.pop_front();
        }
        int result = 0;
        for (auto [people, step] : que)
        {
            if (people == n - 1 && step == 0)
                result++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> relation{{0, 2}, {2, 1}, {3, 4}, {2, 3}, {1, 4}, {2, 0}, {0, 4}};
    Solution solu;
    int res = solu.numWays(5, relation, 3);
    cout << sizeof(int) << endl;
    return 0;
}
