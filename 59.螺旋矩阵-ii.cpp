/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    int g_n;
    bool can_reach(vector<vector<int>>& matrix, int i, int j) {
        return (0 <= i && i < g_n) && (0 <= j && j < g_n) && (matrix[i][j] == 0);
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        g_n = n;
        int total = n * n, cnt = 0, cur = 1;
        int cur_i = 0, cur_j = 0, d_i = 0, d_j = 1;
        
        while (cnt < total) {
            ans[cur_i][cur_j] = cur;
            cur++; cnt++;

            if (!can_reach(ans, cur_i + d_i, cur_j + d_j)) {
                swap(d_i, d_j);
                if (!can_reach(ans, cur_i + d_i, cur_j + d_j)) {
                    d_i = -d_i; d_j = -d_j;
                }
            }

            cur_i += d_i; cur_j += d_j;
        }

        return ans;
    }
};
// @lc code=end

