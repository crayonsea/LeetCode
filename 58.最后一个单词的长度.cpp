/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {

        // skip blank
        int cur, len = s.length();
        for (cur = len-1; cur >= 0 && s[cur] == ' '; cur--);

        // count
        int cnt = 0;
        while (cur >= 0 && isalpha(s[cur])) {
            cur--; cnt++;
        }
        
        return cnt;
    }
};
// @lc code=end

