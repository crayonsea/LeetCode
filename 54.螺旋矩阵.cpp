/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    static const int VIS = INT_MAX;
    int g_m, g_n;
    bool can_reach(vector<vector<int>>& matrix, int i, int j) {
        if ((0 <= i && i < g_m) && (0 <= j && j < g_n) && matrix[i][j] != VIS) return true;
        else return false;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        g_m = m, g_n = n;

        int cnt = 0, total = m * n;
        vector<int> ans; ans.reserve(total);
        
        int cur_i = 0, cur_j = 0, d_i = 0, d_j = 1;
        while (cnt < total) {
            ans.push_back(matrix[cur_i][cur_j]);
            matrix[cur_i][cur_j] = VIS;
            if (!can_reach(matrix, cur_i + d_i, cur_j + d_j)) {
                swap(d_i, d_j);
                if (!can_reach(matrix, cur_i + d_i, cur_j + d_j)) {
                    d_i = -d_i; d_j = -d_j;
                }
            }
            cur_i += d_i; cur_j += d_j;
            cnt++;
        }

        return ans;
    }
};
// @lc code=end

