/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
private:
    void gen_edge(int x, vector<int>& edges, vector<int>& cuts) {
        for (int i = 0; i < cuts.size(); i++) {
            if (i == 0) {
                edges.push_back(cuts[i]);
                continue;
            }
            edges.push_back(cuts[i] - cuts[i-1]);
        }
        edges.push_back(x - cuts.back());
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        vector<int> hedge, vedge;
        gen_edge(h, hedge, horizontalCuts);
        gen_edge(w, vedge, verticalCuts);

        int maxh = *max_element(hedge.begin(), hedge.end());
        int maxv = *max_element(vedge.begin(), vedge.end());
        long long ans = (long long) maxh * maxv;
        
        return ans % int(1e9 + 7);
    }
};
// @lc code=end

