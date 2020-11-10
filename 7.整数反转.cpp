/*
 * @Date: 2020-11-10 21:33:50
 * @LastEditors: Di-Zhipeng
 * @LastEditTime: 2020-11-10 21:58:46
 * @Description: ZJU@CS - Tenderness
 * @FilePath: /LeetCode/7.整数反转.cpp
 */
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <iostream>
using namespace std;
#define UPPER_BOUND 2147483647

class Solution
{
public:
    int reverse(int x)
    {
        int sign = 1;
        long long int res = 0;

        if (x == -2147483648)
            return 0;
        if (x < 0)
        {
            sign = -1;
            x = -1 * x;
        }
        while (1)
        {
            cout << res << endl;
            res += x % 10;
            x /= 10;

            if (x == 0 && res <= UPPER_BOUND)
                break;
            if (res > UPPER_BOUND / 10)
                return 0;
            res *= 10;
        }
        cout << res << endl;
        return sign * res;
    }
};
// int main()
// {
//     return 0;
// }
// @lc code=end
