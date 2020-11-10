/*
 * @Date: 2020-11-09 13:08:38
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 16:49:23
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/5.最长回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
// #define DEBUG
class Solution
{
public:
    int min(int a, int b) { return a < b ? a : b; }
    string extend(string proto_str, int idx)
    {
#ifdef DEBUG
        cout << "proto: " << proto_str << " center: " << proto_str[idx] << endl;
#endif
        int max_radius = min(idx, proto_str.size() - idx - 1);
        string cur_str;
        cur_str += proto_str[idx];
        for (int i = 1; i <= max_radius; i++)
        {
            if (proto_str[idx - i] == proto_str[idx + i])
            {
                cur_str.insert(cur_str.begin(), proto_str[idx - i]);
                cur_str.insert(cur_str.end(), proto_str[idx + i]);
            }
            else
            {
                break;
            }
        }
#ifdef DEBUG
        cout << "res: " << cur_str << endl;
#endif
        return cur_str;
    }
    string fillSharp(string s)
    {
        string res;
        for (int i = 0; i < 2 * s.size() - 1; i++)
        {
            if (i % 2 == 0)
                res += s[i / 2];
            else
                res += '#';
        }
        return res;
    }
    string filterSharp(string s)
    {
        string res;
        int flag = (s[0] == '#') ? 1 : 0;
        for (int i = 0; i < s.size(); i++)
        {

            if (i % 2 == flag)
                res += s[i];
        }
        return res;
    }
    int check(string s)
    {
        int flag = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] != s[i])
                flag = 0;
        }
        return flag;
    }
    string longestPalindrome(string s)
    {
        if (check(s))
            return s;
        int even = s.size();
        if (even)
            s = fillSharp(s);
        string cur_str;
        string max_str;
        int max_size = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur_str = extend(s, i);
            cur_str = filterSharp(cur_str);
            if (cur_str.size() > max_size)
            {
                max_str = cur_str;
                max_size = cur_str.size();
            }
        }

        return max_str;
    }
};
// #ifdef DEBUG
int main()
{
    Solution solution;
    cout << "res" << solution.longestPalindrome("ababacbcbcb") << endl;
}
// #endif
// @lc code=end
