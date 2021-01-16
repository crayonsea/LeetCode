/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        do {
            ans.push_back(nums);
        } while (next_permutation(begin(nums), end(nums)));
        return ans;
    }
};
// @lc code=end

