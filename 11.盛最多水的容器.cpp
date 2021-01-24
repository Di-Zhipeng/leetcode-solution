/*
 * @Date: 2021-01-23 15:12:20
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2021-01-23 16:52:21
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/11.盛最多水的容器.cpp
 */
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{

  public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (true)
        {
            if (left == right)
                break;

            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end
