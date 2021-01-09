/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
private:
    inline int count(int num) {
        // (odd - 1) / 2 --> (odd + 1 - 2) >> 1
        // (even - 2) / 2 --> (even - 2) >> 1
        return ((num + (num & 1)) - 2) >> 1;
    }

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // deal with 0 at Begin or End
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        int cnt = 0, sum_n = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i]) {
                if (cnt) {
                    sum_n += count(cnt);
                    cnt = 0; 
                }
            } else {
                cnt++;
            }
        }
        if (cnt) sum_n += count(cnt);
        
        return sum_n >= n;
    }
};
// @lc code=end

