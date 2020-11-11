/*
 * @Date: 2020-11-10 22:01:44
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-11 09:37:34
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/8.字符串转换整数-atoi.cpp
 */
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <climits>
#include <string>
using namespace std;
class Solution
{
  public:
    int myAtoi(string s)
    {
        long long int res = 0;
        bool flag = true;
        int sign = 1;
        bool hasSign = false;
        bool hasValue = false;
        for (auto c : s)
        {
            if (c == ' ' and flag)
                continue;
            flag = false;
            if (c == '-' and (res != 0 or hasValue))
                break;
            if (c == '-' and not hasSign)
            {
                sign = -1 * sign;
                hasSign = true;
                continue;
            }
            if (c == '+' and (res != 0 or hasValue))
                break;
            if (c == '+' and not hasSign)
            {
                hasSign = true;
                continue;
            }

            if (not(c >= '0' and c <= '9'))
                break;

            res *= 10;
            res += int(c) - 48;
            hasValue = true;
            if (sign * res > INT_MAX)
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;
        }

        return sign * res;
    }
};
// @lc code=end
