#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(), *cur_1 = l1, *cur_2 = l2, *cur_re = result;
        int flag = 0, sum;
        while (cur_1 != nullptr || cur_2 != nullptr || flag != 0)
        {
            sum = flag;
            flag = 0;
            if (cur_1 != nullptr)
            {
                sum += cur_1->val;
                cur_1 = cur_1->next;
            }
            if (cur_2 != nullptr)
            {
                sum += cur_2->val;
                cur_2 = cur_2->next;
            }
            flag = sum / 10;
            sum = sum % 10;
            cur_re->val = sum;
            if (cur_1 != nullptr || cur_2 != nullptr || flag != 0)
            {
                cur_re->next = new ListNode();
                cur_re = cur_re->next;
            }
        }
        delete cur_1,cur_2,cur_re;
        return result;
    }
};

ListNode *toNode(int num)
{

    int cur = num % 10;
    num /= 10;
    ListNode *result = new ListNode(cur), *curNode = result;
    while (num > 0)
    {
        cur = num % 10;
        num /= 10;
        curNode->next = new ListNode(cur);
        curNode = curNode->next;
    }
    return result;
}

void print(ListNode *node)
{
    ListNode *cur = node;
    int num = 0, mul = 1;
    while (cur != nullptr)
    {
        num += cur->val * mul;
        mul *= 10;
        cur = cur->next;
    }
    cout << num << endl;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode(), *cur_1 = l1, *cur_2 = l2, *cur_re = result;
    int flag = 0, sum;
    while (cur_1 != nullptr || cur_2 != nullptr || flag != 0)
    {
        sum = flag;
        flag = 0;
        if (cur_1 != nullptr)
        {
            sum += cur_1->val;
            cur_1 = cur_1->next;
        }
        if (cur_2 != nullptr)
        {
            sum += cur_2->val;
            cur_2 = cur_2->next;
        }
        flag = sum / 10;
        sum = sum % 10;
        cur_re->val = sum;
        cur_re->next = new ListNode();
        cur_re = cur_re->next;
    }
    return result;
}

int main()
{
    ListNode *num1 = toNode(1234), *num2 = toNode(12345);
    ListNode *sum = addTwoNumbers(num1, num2);
    print(sum);
}