/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), s = 0;
        int p = 0, q = n-1, max_s = 0;

        while (p < q) {
            s = (q-p) * min(height[p], height[q]);
            max_s = max(max_s, s);
            
            if (height[p] < height[q]) p++; else q--;
        }

        return max_s;
    }
};
// @lc code=end

/*
int n = height.size();
int s = 0, max_s = 0;

for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
        s = (j-i) * min(height[i], height[j]);
        max_s = max(max_s, s);
    }
}

return max_s;
*/