/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        // int m = A.size(), n = A[0].size();
        // vector<vector<int>> ans(n);
        // // for (auto a : ans) a.resize(m);
        // for (int i = 0; i < ans.size(); i++) ans[i].resize(m);

        int m = A.size(), n = A[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = A[i][j];
            }
        }
        
        return ans;
    }
};
// @lc code=end

