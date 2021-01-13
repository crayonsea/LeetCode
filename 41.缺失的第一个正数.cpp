/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
    void print(vector<int>& nums) {
        for (auto v : nums) cout << v << ' ';
        cout << endl;
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        // 原地 hash
        // 但是对这个空间复杂度有疑问, 复杂度应该是 O(n), 尽管使用了 nums 的空间
        int maxn = nums.size();

        // negative
        for (int i = 0; i < maxn; i++) {
            if (nums[i] <= 0) nums[i] = maxn + 1;
        }

        // print(nums);
        
        // tag: negative
        int pos;
        for (int i = 0; i < maxn; i++) {
            if (abs(nums[i]) <= maxn) {
                pos = abs(nums[i]) - 1;     // note !! abs(nums[i])
                if (nums[pos] > 0) nums[pos] = -nums[pos];
            }
        }

        // print(nums);


        // view negative
        for (int i = 0; i < maxn; i++) if (nums[i] > 0) {
            return i + 1;
        }

        return maxn + 1;
    }
};
// @lc code=end

