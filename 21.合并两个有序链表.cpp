// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @Date: 2021-01-27 18:53:34
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-29 11:45:26
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/21.合并两个有序链表.cpp
 */

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

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
#include <iostream>
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
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
        if (l1 == nullptr)
        {
            cur->next = l2;
        }
        else if (l2 == nullptr)
        {
            cur->next = l1;
        }
        else{
            cur->next = nullptr;
        }
        return head->next;
    }
};
// @lc code=end
