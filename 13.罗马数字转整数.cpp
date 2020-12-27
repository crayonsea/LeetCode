/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
private:
    void init_mapper(map<char, int> &mapper) {
        mapper['I'] = 1;
        mapper['V'] = 5;
        mapper['X'] = 10;
        mapper['L'] = 50;
        mapper['C'] = 100;
        mapper['D'] = 500;
        mapper['M'] = 1000;
    }

public:
    int romanToInt(string s) {
        map<char, int> mapper;
        init_mapper(mapper);

        vector<int> digits;
        for (auto ch : s) digits.push_back(mapper[ch]);

        // deal special conditions
        int ans = 0;
        for (int i = 0; i < digits.size()-1; i++) {
            // d * 5 = d << 2 + d
            // d * 10 = d << 3 + d + d
            if (digits[i+1] > digits[i]) {
                ans -= digits[i];
            } else {
                ans += digits[i];
            }
        }
        ans += digits.back();

        return ans;
    }
};
// @lc code=end

