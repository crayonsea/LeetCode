/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, len = nums.size();
        for (i = 0; i < len; i++) {
            if (nums[i] != val) continue;
            for (int k = i + 1; k < len; k++) if (nums[k] != val) {
                swap(nums[i], nums[k]);
            }
            if (nums[i] == val) break;
        }
        return i;
    }
};
// @lc code=end

// use STL - remove <algorithm>
// -------------------------------------------------------
// view: https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
// int removeElement(vector<int>& nums, int val) {
//     nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
//     return nums.size();
// }