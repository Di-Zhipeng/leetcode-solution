/*
 * @Date: 2020-11-09 11:40:26
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-09 13:07:55
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/4.寻找两个正序数组的中位数.cpp
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
  public:
    double midVal(vector<int> nums)
    {
        int size = nums.size();
        if (size % 2 == 0)
            return (nums[size / 2] + nums[size / 2 - 1]) / 2.;
        return nums[size / 2];
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res_vec(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res_vec.begin());
        return midVal(res_vec);
    }
};
// @lc code=end
