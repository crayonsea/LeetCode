/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
    map<int, string> mapper = {
        {1000, "M"},
        {2000, "MM"},
        {3000, "MMM"},
        
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},

        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},

        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},

        {0, ""}
    };

public:
    string intToRoman(int num) {
        string ans;

        int bits[] = {num / 1000, num % 1000 / 100, num % 100 / 10, num % 10};
        
        ans += mapper[bits[0] * 1000];
        ans += mapper[bits[1] * 100];
        ans += mapper[bits[2] * 10];
        ans += mapper[bits[3] * 1];

        return ans;
    }
};
// @lc code=end

