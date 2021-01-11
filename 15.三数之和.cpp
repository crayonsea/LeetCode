/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int i = 0; i < len - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int k = len - 1;
            // k 是可以在 j 循环过程中累计变化的! 因为 随着 j↑, 需要 k↓, k
            for (int j = i + 1; j < len - 1 && nums[i] + nums[j] <= 0; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                while (j < k && nums[i] + nums[j] + nums[k] > 0) k--;
                if (j == k) break;

                // 因为 nums[j] 一定会增大 (continue 语句)
                // 所以不需要显示比较, nums[k] 是否和上一次 (nums[k+1]) 相等
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
       
        return ans;
    }
};
// @lc code=end

