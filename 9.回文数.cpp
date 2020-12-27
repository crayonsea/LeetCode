/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        int tx = x;
        long long t = 0;
        while (tx) {
            t = t*10 + tx % 10;
            tx /= 10;
        }
        
        return (int)t == x;
    }
};
// @lc code=end

