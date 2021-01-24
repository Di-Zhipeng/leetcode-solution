/*
 * @Date: 2021-01-24 10:26:41
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-24 11:56:17
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/15.三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        auto check = [&](int a, int b, int c) {
            if ((a + b + c) == 0)
            {
                res.push_back({a, b, c});
            }
        };
        sort(nums.begin(), nums.end());
        if(nums.size()==0){
            return {};
        }
        if(*nums.begin() == *(nums.end() - 1) && nums.size() >=3 && nums[0]==0){
            return {{ nums[0],nums[0],nums[0]}};
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int k = nums.size() - 1; k > i; k--)
            {
                int val = (-1) * (nums[i] + nums[k]);
                auto iter = lower_bound(nums.begin() + i + 1, nums.begin() + k, val);
                int j = distance(nums.begin(), iter);
                if (i != j && j != k && k != i && j > i && j < k)
                {
                    check(nums[i], nums[j], nums[k]);
                }
            }
        }

        set<vector<int>> temp(res.begin(), res.end());
        res.assign(temp.begin(), temp.end());
        return res;
    }
};
// @lc code=end
