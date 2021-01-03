/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DP
        int dp = nums[0], maxv = dp;
        for (int i = 1; i < nums.size(); i++) {
            dp = max(dp + nums[i], nums[i]);
            maxv = max(maxv, dp);
        }
        
        return maxv;
    }
};
// @lc code=end


// 暴力求解
// vector<int> sums;
// int len = nums.size(), sum = 0;
// for (int i = 0; i < len; i++) {
//     sum += nums[i];
//     sums.push_back(sum);
// }

// int maxv = sums[0];
// for (int i = 0; i < len; i++) maxv = max(maxv, sums[i]);
// for (int i = 1; i < len; i++) {
//     for (int j = i+1; j <= len; j++) {
//         maxv = max(maxv, sums[j-1] - sums[i-1]);
//     }
// }

// return maxv;
