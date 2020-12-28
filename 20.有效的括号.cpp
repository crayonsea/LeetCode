/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> pairs;
        pairs[')'] = '(';
        pairs['}'] = '{';
        pairs[']'] = '[';
        pairs['('] = 'x';
        pairs['{'] = 'x';
        pairs['['] = 'x';

        for (char ch : s) {
            if (!stk.empty() && stk.top() == pairs[ch]) stk.pop();
            else stk.push(ch);
        }

        if (stk.empty()) return true;
        else return false;
    }
};
// @lc code=end

