/*
 * @Date: 2021-01-27 18:03:11
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-27 18:17:00
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/19.删除链表的倒数第n个节点.cpp
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

// @lc code=start

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1, *p2;
        int i = 0;
        p1 = head;
        p2 = head;
        while (true)
        {
            p1 = p1->next;
            if (p1 == nullptr)
                break;

            if (i == n)
            {
                p2 = p2->next;
            }
            else
            {
                i++;
            }
        }
        
        if (p2 == head && i != n)
            return p2->next;
        if (p2->next != nullptr)
        {
            p2->next = p2->next->next;
        }
        return head;
    }
};
// @lc code=end
