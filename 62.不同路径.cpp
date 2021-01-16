/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    
    // C_n_r
    int C(int n, int r) {
        long long up = 1, down = 1;
        for (int i = n; i >= n-r+1; i--) up *= i;
        for (int i = r; i >= 1; i--) down *= i;
        return up / down;
    }
public:
    int uniquePaths(int m, int n) {
        // 把路径考虑成一个完整序列, 而不是分隔开的
        // 高中数学问题
        // 总共需要走的步数中, 有 x 步是向 xx 方向的
        if (m < n) swap(m, n);
        return C(m+n-2, n-1);
    }
};
// @lc code=end

