/*
 * @Date: 2020-11-06 08:54:43
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 16:35:59
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j] == target) && (i != j))
                {
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
