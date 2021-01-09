/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        
        // sign of result
        int sign = (dividend ^ divisor) >> 31;

        long long dividend_l = dividend > 0? dividend: -(long long)dividend;
        long long divisor_l = divisor > 0? divisor: -(long long)divisor;

        long long sum = divisor_l, result = 1;
        while (sum < dividend_l) {
            sum += sum;
            result += result;
        }

        if (sum != dividend_l) {
            sum -= dividend_l;
            while (sum > 0) {
                sum -= divisor_l;
                result -= 1;
            }
        }
        
        if (sign) result = -result;
        
        return result;
    }
};
// @lc code=end

