#include <iostream>
#include <vector>

using namespace std;


class Solution1 {
    int m;
    int n;
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (visited[i][j] || grid[i][j] != '1') return;
        visited[i][j] = true;
        dfs(grid, i-1, j, visited);
        dfs(grid, i+1, j, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);
    }
};


vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Island {
private:
    int M;
    int N;
    vector<vector<int>> matrix;
    int is_cnt;
    vector<int> parent;

    int find(int idx) {
        if (idx >= M*N) {
            cout << "error idx=" << idx << endl;
            return -1;
        }

        if (parent[idx] == idx)
            return idx;
        return parent[idx] = find(parent[idx]);;
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pb < pa) swap(pa, pb);
        parent[pb] = pa;
        is_cnt --;
    }

public:
    Island(int m, int n):M(m), N(n), matrix(m, vector<int>(n, 0)), is_cnt(0), parent(m*n, -1) { }
    
    void AddIsland(int x, int y) {
        
        if (x < 0 || x >= M) return;
        if (y < 0 || y >= N) return;
        if (matrix[x][y]) return;

        matrix[x][y] = 1;
        is_cnt ++;
        int idx = N * x + y;
        parent[idx] = idx;

        for (auto &d: dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx < 0 || nx >= M) continue;
            if (ny < 0 || ny >= N) continue;
            if (!matrix[nx][ny]) continue;
            int n_idx = N * nx + ny;
            if (find(idx) != find(n_idx)) unite(idx, n_idx);
        }
        
        for(int i = 0; i < 4; ++i)
            cout << parent[i];
        cout << endl;
    }

    int CountIsland() {
        return is_cnt;
    }
};

int main(int argc, char *argv[])
{
    Island is(2, 2);
    is.AddIsland(0, 1);
    cout << is.CountIsland() << endl;
    is.AddIsland(1, 0);
    cout << is.CountIsland() << endl;
    is.AddIsland(1, 1);
    cout << is.CountIsland() << endl;
    is.AddIsland(0, 0);
    cout << is.CountIsland() << endl;

    return 0;
}
