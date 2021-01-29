/*
 * @Date: 2021-01-28 10:20:37
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-29 10:37:19
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/22.括号生成.cpp
 */

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<string> res;
    bool check(string cur)
    {
        int balance = 0;
        for (auto &c : cur)
        {
            if (c == '(')
                balance++;
            if (c == ')')
                balance--;
            if (balance < 0)
                return false;
        }
        return balance == 0;
    }
    void backtrace(string cur, int pos, int n)
    {
        if (cur.size() == 2 * n)
        {
            if (check(cur))
            {
                res.emplace_back(cur);
            }
            return;
        }

        cur += "(";
        backtrace(cur, pos + 1, n);
        cur[pos] = ')';
        backtrace(cur, pos + 1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        backtrace("", 0, n);
        return res;
    }
};
// @lc code=end
