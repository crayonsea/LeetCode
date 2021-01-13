/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int len = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        int min_d = abs(ans - target);

        for (int i = 0; i < len; i++) {
            
            int j = i + 1, k = len - 1;
            for (j = i + 1; j < k; j++) {

                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int distance = abs(sum - target);
                    
                    if (distance < min_d) {
                        min_d = distance;
                        ans = sum;
                    }

                    if (sum < target) {
                        // 当前就是最接近的
                        break;
                    }
                    k--;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

