/*
 * @Date: 2021-01-23 17:29:33
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-24 10:17:30
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/13.罗马数字转整数.cpp
 */
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
  public:
    int romanToInt(string s)
    {
        int i = 0;
        int res = 0;
        int pos = 0;
        vector<pair<int, string>> symbol_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
            {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"},
        };

        while (true)
        {
            auto p = s.find(symbol_map[i].second, pos);
            if(p == pos){
                pos = p + symbol_map[i].second.size();
                res += symbol_map[i].first;
            }
            else
            {
                i++;
            }
            if(pos == s.size()){
                break;
            }
        }
        return res;
    }
};
// @lc code=end
