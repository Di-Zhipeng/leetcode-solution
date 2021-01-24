/*
 * @Date: 2021-01-24 10:17:56
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-24 10:26:14
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/14.最长公共前缀.cpp
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
    
  public:
    string strand(string a, string b){
        int i = 0;
        int min_size = min(a.size(), b.size());
        for (i = 0; i < min_size; i++)
        {
            if(a[i]!=b[i])
                break;
        }
        return a.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string res = strs[0];
        for (auto &s : strs)
        {
            res = strand(res, s);
        }
        return res;
    }
};
// @lc code=end

