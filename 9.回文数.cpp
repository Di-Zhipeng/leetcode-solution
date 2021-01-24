/*
 * @Date: 2020-11-11 09:41:35
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-11 09:47:36
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/9.回文数.cpp
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <climits>
class Solution
{
  public:
    int getReverse(int x)
    {
        int res = 0;
        while (1)
        {
            if (x == 0)
                break;
            if (res > INT_MAX / 10)
                break;
            res *= 10;
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        return x == getReverse(x);
    }
};
// @lc code=end
