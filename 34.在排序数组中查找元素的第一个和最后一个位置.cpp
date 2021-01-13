/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        // lower_bound, upper_bound
        
        // equal_range
        auto t = equal_range(nums.begin(), nums.end(), target);
        int p = t.first - nums.begin();
        int q = t.second - nums.begin();

        // p: begin; q: end
        // for (auto it = t.first; it != t.second; it++) every_*(it)_equals_to_target
        if (p == q) return {-1, -1};
        else return {p, q - 1};
    }
};
// @lc code=end

