/*
 * @Date: 2021-01-29 10:43:18
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-29 11:49:57
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/23.合并k个升序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <vector>
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
using namespace std;
// @lc code=start

class Solution
{
  public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummynode(0);
        ListNode *head = &dummynode;
        ListNode *cur = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = (l1 == nullptr) ? l2 : l1;
        return head->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        for (auto l : lists)
        {
            head = merge(head, l);
        }
        return head;
    }
};
// @lc code=end
