/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <cstring>

class Solution {
public:
    int strStr(string haystack, string needle) {
        // c strstr
        // const char *ans = strstr(haystack.c_str(), needle.c_str());
        // if (ans != NULL) return ans - haystack.c_str();
        // else return -1;

        // c++ string find
        return (int)haystack.find(needle);

        // if con't find, return value is string::npos
        // [static const size_type	npos = static_cast<size_type>(-1);]
        
        if (needle.length() == 0) return 0;

        int hl = haystack.length(), nl = needle.length();
        for (int i = 0; i < hl - nl + 1; i++) {
            if (haystack[i] == needle[0]) {
                bool find = true;
                for (int k = 1; k < nl; k++) {
                    if (haystack[i+k] != needle[k]) {
                        find = false; break;
                    }
                }
                if (find) return i;
            }
        }

        return -1;
    }
};
// @lc code=end

