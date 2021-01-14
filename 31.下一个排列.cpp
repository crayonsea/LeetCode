/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start

// <use library>
// next_permutation(begin(nums), end(nums));

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, j, len = nums.size();
        
        // pos i
        for (i = len - 2; i >= 0 && nums[i] >= nums[i+1]; i--);

        if (i >= 0) {
            // pos j
            for (j = len - 1; j >= 0 && nums[j] <= nums[i]; j--);
            // swap
            swap(nums[i], nums[j]);
        }

        // reverse
        reverse(begin(nums) + i + 1, end(nums));

    }
};
// @lc code=end

