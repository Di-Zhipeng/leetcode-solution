/*
 * @Date: 2020-11-06 08:54:43
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-11 08:17:58
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = ht.find(target - nums[i]);
            if (it != ht.end())
            {
                return {it->second, i};
            }
            ht[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
