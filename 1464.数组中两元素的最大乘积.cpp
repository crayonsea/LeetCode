/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 0, q = 0, maxv = -1;

        for (int i = 0; i < nums.size(); i++) if (nums[i] > maxv) {
            maxv = nums[i]; p = i;
        }
        
        maxv = -1;
        for (int i = 0; i < nums.size(); i++) if (i != p && nums[i] > maxv) {
            maxv = nums[i]; q = i;
        }
        
        return (nums[p] - 1) * (nums[q] - 1);
    }
};
// @lc code=end

// 使用 sort
// -------------------------------------
// sort(nums.rbegin(), nums.rend());
// return (nums[0] - 1) * (nums[1] - 1);
