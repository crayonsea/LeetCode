/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int pos, len = s.length();

        // skip blank
        for (pos = 0; pos < len && isblank(s[pos]); pos++);

        if (pos > len) return 0;
        if (!(isdigit(s[pos]) || s[pos] == '-' || s[pos] == '+')) return 0;
        
        // deal with '-'
        int flip = 1;
        if (s[pos] == '-') {
            flip = -1; pos++;
        } else if (s[pos] == '+') {
            pos++;
        }

        // convert
        int digit_len = 0;
        long long cur = 0;
        // -- skip front '0'
        while (pos < len && s[pos] == '0') pos++;
        // -- start convert
        while (pos < len && isdigit(s[pos])) {
            cur = cur * 10 + (s[pos] - '0');
            if (++digit_len > 10) break;
            pos++;
        }

        // '-'
        cur = cur * flip;

        if (cur < INT_MIN) return INT_MIN;
        else if (cur > INT_MAX) return INT_MAX;
        else return (int)cur;
    }
};
// @lc code=end

