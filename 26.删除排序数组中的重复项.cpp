/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;

        int curNum = 0;
        int p = 0, q = 0, len = nums.size();

        while (q < len) {
            while (q < len && nums[p] == nums[q]) q++;
            nums[curNum++] = nums[p];
            p = q;
        }

        nums.resize(curNum);

        return curNum;
    }
};
// @lc code=end

// 或者使用一次遍历, 逻辑更清楚一些, 直接在应有的位置上更新就行 
// int j = 0;
// for(int i = 0; i < nums.length; i++) {
//     if(nums[i] != nums[j])
//         nums[++j] = nums[i];
// }