#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> allNode;
        for (auto head : lists)
        {
            while (head != nullptr)
            {
                allNode.push_back(head);
                head = head->next;
            }
        }
        sort(allNode.begin(), allNode.end(), [](const ListNode *n1, const ListNode *n2) -> bool {
            return n1->val < n2->val;
        });
        for (size_t i = 0, j = 1; j < allNode.size(); i++, j++)
        {
            allNode[i]->next = allNode[j];
        }
        if (allNode.size() > 0)
        {
            allNode[allNode.size() - 1]->next = nullptr;
            return allNode[0];
        }
        else
        {
            return nullptr;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;

    return 0;
}
