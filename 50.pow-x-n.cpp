/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    double mypow(double x, int n) {
        if (n == 0) return 1.0;
        else if (n == 1) return x;
        else {
            auto t = myPow(x, n / 2);
            return n & 1? t*t*x: t*t;
        }
    }
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / (mypow(x, -(n + 1)) * x);
        else return mypow(x, n);
    }
};
// @lc code=end

