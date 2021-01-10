/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n) {
            if (n & 1) {
                cnt++;
                if (cnt > 1) return false;
            }
            n = (n >> 1);
        }

        if (cnt == 1) return true;
        else return false;
    }
};
// @lc code=end

