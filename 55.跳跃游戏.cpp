/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        
        int maxp = 0, len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (maxp < i) return false;
            maxp = max(maxp, i + nums[i]);
            if (maxp >= len - 1) return true;
        }

        return false;
    }
};
// @lc code=end

