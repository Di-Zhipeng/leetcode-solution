/*
 * @Date: 2020-11-11 09:52:14
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-23 15:08:33
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/10.正则表达式匹配.cpp
 */
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:

    bool isMatch(string s, string p)
    {

        const int n = s.size();
        const int m = p.size();
        auto match = [&](int i, int j) { return (i != 0) && (s[i - 1] == p[j - 1] || p[j - 1] == '.'); };
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j-1] != '*')
                {
                    f[i][j] = match(i, j) ? f[i - 1][j - 1] : false;
                }
                else
                {
                    f[i][j] = match(i, j - 1) ? (f[i][j - 2] || f[i - 1][j]) : f[i][j - 2];
                }
            }
        }
        return f[n][m];
    }
};

// @lc code=end
