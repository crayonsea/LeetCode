/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int p = abs(x);
        int flag = x > 0? 1: -1;
        long long ans = 0;
        // 反转数字
        while (p) {
            ans = ans * 10 + p % 10;
            p = p / 10;
        }
        // 检查溢出
        if (ans < (int)0x80000000 || ans > 0x7fffffff) return 0;
        else return (int)ans * flag;
    }
};
// @lc code=end

