/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, t = nums.size(), mid;

        while (s < t) {
            mid = (s+t) >> 1;
            if (nums[mid] < target) {
                s = mid + 1;
            } else if (nums[mid] > target) {
                t = mid;
            } else {
                return mid;
            }
        }
        
        return s;
    }
};
// @lc code=end

