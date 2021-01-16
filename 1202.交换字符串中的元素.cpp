/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
const int maxn = 100000 + 5;

int f[maxn];

void reset() { for (int i = 0; i < maxn; i++) f[i] = i; }

// 递归不要写错 !!! f[x] = find(f[x]) 才有递归优化过程 !!!
int find(int x) { return f[x] == x? x: f[x] = find(f[x]); }

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    f[fa] = fb;
}

// reset, find, merge, check_group_num

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        reset();
        for (auto p : pairs) merge(p[0], p[1]);

        string ans;
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mapper;

        for (int i = 0; i < s.length(); i++) {
            int fa = find(i);
            mapper[fa].push(s[i]);
        }
        
        // for (auto it = mapper.begin(); it != mapper.end(); it++) {
        //     sort((*it).second.begin(), (*it).second.end(), greater<char>());
        // }
        
        for (int i = 0; i < s.length(); i++) {
            int fa = find(i);
            ans.push_back(mapper[fa].top());
            mapper[fa].pop();
            
            // <mutiset>
            // see: https://www.cnblogs.com/lakeone/p/5600494.html
            // multiset.earse(value) OR multiset.earse(iterator)
        }
        
        return ans;
    }
};
// @lc code=end

