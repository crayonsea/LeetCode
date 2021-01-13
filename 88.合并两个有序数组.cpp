/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        for (; i < m; i++) temp.push_back(nums1[i]);
        for (; j < n; j++) temp.push_back(nums2[j]);

        nums1 = temp;
    }
};
// @lc code=end

