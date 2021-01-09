/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        // std::reverse
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int lena = a.size(), lenb = b.size();
        int len = max(lena, lenb);

        int i = 0, sum = 0, addon = 0;
        while (i < len || addon) {
            int aa = i < lena? a[i] - '0': 0;
            int bb = i < lenb? b[i] - '0': 0;
            sum = aa + bb + addon;
            // addon = sum & 2;
            addon = sum >> 1;
            ans.push_back((sum & 1) + '0');
            i++;
        }
        
        // std::reverse
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
// @lc code=end

