/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
const int maxn = 10000 + 5;

int f[maxn];

void reset() { for (int i = 0; i < maxn; i++) f[i] = i; }

int find(int x) { return f[x] == x? x: x = find(f[x]); }

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    f[fa] = fb;
}

// reset, find, merge, check_group_num

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        pair<vector<vector<int>>, vector<vector<int>>> G;
        G.first.resize(maxn);
        G.second.resize(maxn);
        for (int i = 0; i < stones.size(); i++) {
            G.first[stones[i][0]].push_back(i);
            G.second[stones[i][1]].push_back(i);
        }

        reset();

        for (int i = 0; i < G.first.size(); i++) {
            vector<int>& row = G.first[i];
            if (row.size() <= 1) continue;
            for (int a = row[0], k = 1; k < row.size(); k++) {
                merge(a, row[k]);
            }
        }

        for (int j = 0; j < G.second.size(); j++) {
            vector<int>& col = G.second[j];
            if (col.size() <= 1) continue;
            for (int a = col[0], k = 1; k < col.size(); k++) {
                merge(a, col[k]);
            }
        }

        int cnt = 0;
        for (int i = 0; i < G.first.size(); i++) {
            if (f[i] != i) cnt++;
        }

        return cnt;
    }
};
// @lc code=end

