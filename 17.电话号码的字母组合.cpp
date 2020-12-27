/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> mapper = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &digits, vector<string> &ans, string &cur, int cur_pos) {

        if (cur_pos == (int)digits.size()) {
            if (cur != "") ans.push_back(cur);
            return;
        }

        int digit = digits[cur_pos] - '0';
        string next_states = mapper[digit];
        
        for (char ch : next_states) {
            cur.push_back(ch);
            dfs(digits, ans, cur, cur_pos+1);
            cur.pop_back();
        }

        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        
        dfs(digits, ans, cur, 0);

        return ans;
    }
};
// @lc code=end

