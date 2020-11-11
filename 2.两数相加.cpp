/*
 * @Date: 2020-11-06 09:02:31
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 22:51:16
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/2.两数相加.cpp
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <algorithm>
class Solution {
public:
  int getValue(ListNode *L1) { return L1 == nullptr ? 0 : L1->val; }
  ListNode *nextNode(ListNode *L1) {
    return L1 == nullptr ? nullptr : L1->next;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode;
    head->next = nullptr;
    ListNode *curNode = head;

    int cur = 0;
    int carry = 0;
    while (1) {
      curNode->val = (getValue(l1) + getValue(l2) + carry) % 10;
      carry = (getValue(l1) + getValue(l2) + carry) / 10;
      l1 = nextNode(l1);
      l2 = nextNode(l2);
      if (l1 == nullptr and l2 == nullptr and carry == 0)
        break;
      curNode->next = new ListNode;
      curNode = curNode->next;
      curNode->next = nullptr;
    }
    return head;
  }
};
// @lc code=end
