/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int i = 0, j = len - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }
        return true;
    }
};
// @lc code=end

