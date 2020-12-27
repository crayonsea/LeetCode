/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    bool compare_all(vector<string>& strs, int cur) {
        if (cur >= strs[0].length()) return false;

        char ch = strs[0][cur];
        for (int i = 1; i < strs.size(); i++) {
            if (cur >= strs[i].length() || ch != strs[i][cur]) return false;
        }
        return true;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";

        string ans;
        int cur = 0;
        
        while (true) {
            if (compare_all(strs, cur)) {
                ans.push_back(strs[0][cur++]);
                continue;
            }
            break;
        }

        return ans;
    }
};
// @lc code=end

