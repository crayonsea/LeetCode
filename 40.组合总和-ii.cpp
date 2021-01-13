/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            if (i > cur_pos && candidates[i] == candidates[i-1]) continue;
            
            cur.push_back(candidates[i]);
            dfs(candidates, target, cur, sum + candidates[i], i + 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, cur, 0, 0);
        return ans;
    }
};
// @lc code=end

