/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    void dfs(int n, vector<string> &ans, stack<char> &s, string &cur, int cur_pos) {

        if (!s.empty() && s.top() == ')') return;
        
        if (cur_pos == n) {
            if (s.empty()) {
                ans.push_back(cur);
            }
            return;
        }

        stack<char> tmp;
        // '('
        tmp = s;
        s.push('(');
        cur.push_back('(');
        
        dfs(n, ans, s, cur, cur_pos+1);

        s = tmp;
        cur.pop_back();
        
        // ')'
        tmp = s;
        if (!s.empty() && s.top() == '(') s.pop();
        else s.push(')');
        cur.push_back(')');

        dfs(n, ans, s, cur, cur_pos+1);
        
        s = tmp;
        cur.pop_back();
        
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        string cur;
        stack<char> s;
        vector<string> ans;

        dfs(n << 1, ans, s, cur, 0);

        return ans;
    }
};
// @lc code=end

