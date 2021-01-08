/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start

class Solution {
private:
    void build_graph(vector<vector<int>>& edges, 
        vector<vector<int>>& from, vector<vector<int>>& to) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            from[u].push_back(v); to[v].push_back(u);
        }
    }

    void print(const vector<vector<int>>& pic) {
        for (int i = 0; i < pic.size(); i++) {
            cout << i << ',' << ' ';
            for (int j = 0; j < pic[i].size(); j++) {
                cout << pic[i][j] << ' ';
            }
            cout << endl;
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // build Graph - first: from; second: to;
        vector<int> vis(n, 0);
        vector<vector<int>> from(n), to(n);
        build_graph(connections, from, to);
        pair<vector<vector<int>>&, vector<vector<int>>&> g(from, to);
        // print(g.first); print(g.second);
        
        // cnt number
        int cnt = 0;
        queue<int> q;

        // start BFS
        q.push(0); vis[0] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // from u to v
            for (auto v : g.first[u]) if (!vis[v]) { 
                q.push(v); cnt++; vis[v] = 1;
            }
            // from uu to u
            for (auto uu : g.second[u]) if (!vis[uu]) {
                q.push(uu); vis[uu] = 1;
            }
        }

        return cnt;
    }
};
// @lc code=end
