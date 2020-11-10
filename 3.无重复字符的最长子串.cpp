/*
 * @Date: 2020-11-06 09:25:03
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 16:35:33
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<char> appear;
    bool check(char c)
    {
        if (find(appear.begin(), appear.end(), c) != appear.end()) //find
            return false;
        return true;
    }
    void shift(char c)
    {
        appear.erase(appear.begin(), find(appear.begin(), appear.end(), c) + 1);
    }
    void printVector()
    {
        for (auto i : appear)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        for (auto c : s)
        {
            if (!check(c))
                shift(c);
            appear.emplace_back(c);
            if (appear.size() > res)
                res = appear.size();
        }
        return res;
    }
};
// @lc code=end
