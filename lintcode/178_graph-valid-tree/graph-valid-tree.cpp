/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/graph-valid-tree
@Language: C++
@Datetime: 16-07-23 03:39
*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n <= 0) return true;
        if (n - 1 != edges.size()) return false;
        vector<set<int>> adjs(n);
        for (auto e : edges) {
            adjs[e[0]].insert(e[1]);
            adjs[e[1]].insert(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (auto i: adjs[cur]) {
                q.push(i);
                if (visited[i]) return false;
                visited[i] = true;
                adjs[i].erase(cur);
            }
        }
        
        for (int i = 0; i < n; ++i)
            if (!visited[i]) return false;
        return true;
    }
};