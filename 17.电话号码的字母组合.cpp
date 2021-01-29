/*
 * @Date: 2021-01-27 17:14:54
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-27 17:48:11
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/17.电话号码的字母组合.cpp
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
        vector<vector<string>> digit_to_char = {{"a", "b", "c"}, {"d", "e", "f"},     {"g", "h", "i"},
                                                {"j", "k", "l"}, {"m", "n", "o"},     {"p", "q", "r", "s"},
                                                {"t", "u", "v"}, {"w", "x", "y", "z"}};
        auto dc_map = [&](char num) { return digit_to_char[num - 50]; };
        auto mult = [](vector<string> x, vector<string> y) {
            vector<string> res;
            for (auto &i : x)
            {
                for (auto &j : y)
                {
                    res.emplace_back(i + j);
                }
            }
            return res;
        };
        vector<string>res = {""};
        for(auto &i :digits){
            res = mult(res, dc_map(i));
        }
        return res;
    }
};
// @lc code=end
