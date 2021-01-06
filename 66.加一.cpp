/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addon = 1;
        
        for (int i = digits.size()-1; i >= 0; i--) {
            digits[i] += addon;
            addon = digits[i] / 10;
            if (addon) digits[i] %= 10;
        }
        
        if (addon) digits.insert(digits.begin(), addon);

        return digits;
    }
};
// @lc code=end

