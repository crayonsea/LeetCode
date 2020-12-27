/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <unordered_set>
#include <algorithm>

class Solution {
private:
    unordered_set<char> lookup;

public:
    int lengthOfLongestSubstring(string s) {
        lookup.clear();
        int max_length = 0, left_pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left_pos]);
                left_pos++;
            }

            // add char
            lookup.insert(s[i]);
            
            // count lenght
            // max_length = max((int)lookup.size(), max_length);
            max_length = max(i + 1 - left_pos, max_length);
        }

        return max_length;
    }
};
// @lc code=end

