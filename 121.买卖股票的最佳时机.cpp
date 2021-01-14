/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int maxp = 0, minp = prices[0];

        for (auto p : prices) {
            maxp = max(maxp, p - minp);
            minp = min(minp, p);
        }
        
        return maxp;
    }
};
// @lc code=end

