/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> p;
        p.resize(numRows);

        int cur_row = 0, inc = -1;
        for (int i = 0; i < s.length(); i++) {
            p[cur_row].push_back(s[i]);
            if (i % (numRows-1) == 0) inc = -inc;
            cur_row += inc;
        }

        string ans;
        for (int i = 0; i < p.size(); i++) ans += p[i];

        return ans;
    }
};
// @lc code=end

