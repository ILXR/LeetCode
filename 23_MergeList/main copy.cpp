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
    ListNode *head;

private:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a || !b)
        {
            return a ? a : b;
        }
        ListNode *tail = head;

        while (a && b)
        {
            if (a->val < b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head->next;
    }

public:
    Solution()
    {
        this->head = new ListNode();
    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};