/*
 * @Date: 2021-01-23 16:46:42
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-23 17:28:11
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/12.整数转罗马数字.cpp
 */
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
// @lc code=start
#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
  public:
    string intToRoman(int num)
    {
        string res;
        vector<pair<int, string>> symbol_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
            {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"},
        };
        int i = 0;

        while (true)
        {
            if (num < symbol_map[i].first)
            {
                i++;
                cout << symbol_map[i].first << endl;
                continue;
            }
  
            num = num - symbol_map[i].first;
            res += symbol_map[i].second;
            if (num == 0)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
