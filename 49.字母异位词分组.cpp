/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mapper;
        
        int g_cnt = 0;
        
        for (auto str : strs) {
            string s = str;
            sort(begin(s), end(s));
            if (!mapper.count(s)) {
                mapper[s] = g_cnt++;
                ans.push_back({str});
            } else {
                ans[mapper[s]].push_back(str);
            }
        }

        return ans;
    }
};
// @lc code=end

