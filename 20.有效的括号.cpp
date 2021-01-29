/*
 * @Date: 2021-01-27 18:18:27
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-27 18:48:45
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/20.有效的括号.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    bool isValid(string s)
    {
        vector<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack.emplace_back(s[i]);
            }
            if (s[i] == ')')
            {
                if (stack.empty())
                    return false;
                if (stack[stack.size() - 1] == '(')
                    stack.pop_back();
                else
                    return false;
            }
            if (s[i] == ']')
            {
                if (stack.empty())
                    return false;
                if (stack[stack.size() - 1] == '[')
                    stack.pop_back();
                else
                    return false;
            }
            if (s[i] == '}')
            {
                if (stack.empty())
                    return false;
                if (stack[stack.size() - 1] == '{')
                    stack.pop_back();
                else
                    return false;
            }
        }
        if (stack.empty())
            return true;
        return false;
    }
};
// @lc code=end
