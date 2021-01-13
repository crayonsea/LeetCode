/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
private:
    void dfs(const vector<int>& candidates, const int target, vector<int>& cur, int sum, int cur_pos) {
        if (sum > target) return;

        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = cur_pos; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            dfs(candidates, target, cur, sum + candidates[i], i);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, target, cur, 0, 0);
        return ans;
    }
};
// @lc code=end

