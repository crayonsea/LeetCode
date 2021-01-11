/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
private:
    // int table[256] = {
    //     0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    //     1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    //     1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    //     1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    //     2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    //     3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    //     3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    //     4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
    // };

    // int count(int x) {
    //     int cnt = 0;
    //     while (x) { cnt += x & 1; x >>= 1; }
    //     return cnt;
    // }

    // int gen_table(int size) {
    //     for (int i = 0; i < (1 << size); i++) {
    //         if (i % 16 == 0) cout << endl;
    //         cout << count(i) << ',' << ' ';
    //     }
    //     return 0;
    // }

    // int gen_d(const int& a, const int& b) {
    //     int c = a ^ b;
    //     return table[c & 0xff] + table[(c >> 8) & 0xff] + table[(c >> 16) & 0xff] + table[(c >> 24) & 0xff];
    // }



public:
    int totalHammingDistance(vector<int>& nums) {        
        
        int bits[32];
        memset(bits, 0, sizeof(bits));
        
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int cur = nums[i];
            for (int pos = 0; cur; pos++) {
                bits[pos] += cur & 0x01;
                cur >>= 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < 32; i++) {
            sum += bits[i] * (len - bits[i]);
        }

        return sum;
    }
};
// @lc code=end

