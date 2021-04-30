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

ListNode *vec2node(vector<int> nums)
{
    ListNode *HEAD = new ListNode();
    ListNode *head = HEAD;
    for (size_t i = 0; i < nums.size(); i++)
    {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return HEAD->next;
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k <= 1)
        {
            return head;
        }
        ListNode *HEAD = new ListNode();
        HEAD->next = head;
        ListNode *cur_head = HEAD;
        while (true)
        {
            int count = k;
            head = cur_head->next;
            while (head != nullptr && count > 0)
            {
                head = head->next;
                count--;
            }
            if (count)
            {
                break;
            }
            ListNode *pre = cur_head->next;
            head = pre->next;
            for (count = k - 1; count;)
            {
                ListNode *next = head->next;
                head->next = pre;
                pre = head;
                head = next;
                count--;
                if (!count)
                {
                    cur_head->next->next = head;
                    next = cur_head->next;
                    cur_head->next = pre;
                    cur_head = next;
                }
            }
        }
        return HEAD->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    ListNode * result = solu.reverseKGroup(vec2node(vector<int>{1,2,3,4,5}),2);

    return 0;
}
