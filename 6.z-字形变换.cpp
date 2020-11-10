/*
 * @Date: 2020-11-10 20:50:15
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 21:32:38
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/6.z-字形变换.cpp
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

#define DEBUG

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string res;
        vector<vector<char>> map;
        map.resize(numRows);
        if (numRows == 1)
        {
            return s;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (i % (2 * numRows - 2) < numRows)
            {
                map[i % (2 * numRows - 2)].emplace_back(s[i]);
            }
            else
            {
                map[2 * numRows - 2 - i % (2 * numRows - 2)].emplace_back(s[i]);
            }
        }
        for (auto row : map)
        {
            for (auto val : row)
            {
                res += val;
            }
        }
        return res;
    }
};
// @lc code=end
