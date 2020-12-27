/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.size(), max_len = 0;
        int pos_i, pos_j;
        string ans;
        vector<vector<char>> P(n+1, vector<char>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j <= n; j++) {
                if (j - i <= 2) P[i+1][j-1] = 1;
                P[i][j] = P[i+1][j-1] && (s[i] == s[j-1]);

                if (P[i][j] && (j - i > max_len)) {
                	pos_i = i, pos_j = j;
                	max_len = max(max_len, j-i);
				}
                // cout << s.substr(i, j-i) << ' ' << P[i][j] << endl;
            }
        }
        ans = s.substr(pos_i, pos_j-pos_i);
        
        return ans;
    }
};
// @lc code=end


/*
// 1. loop
private:
    bool isloopstr(string s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len-i-1]) return false;
        }
        
        return true;
    }
public:
    string longestPalindrome(string s) {
        int length = s.size(), max_len = 0;
        string ans;

        for (int i = 0; i < length; i++) {
            for (int j = i + 2; j <= length; j++) {
                if (isloopstr(s.substr(i, j-i))) {
                    if (j-i > max_len) {
                        max_len = j-i;
                        ans = s.substr(i, j-i);
                    }
                }
            }
        }

        if (max_len == 0) ans = s[0];
        
        return ans;
    }
*/