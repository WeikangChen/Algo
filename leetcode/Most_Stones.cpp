class Solution {
    vector<vector<int>> _stones;
    unordered_map<int, int> row2gp;
    unordered_map<int, int> col2gp;
    
    pair<int, int> find_row_group(int r) {
        auto gp = row2gp[r];
        auto r1 =  r;
        if (r != _stones[gp][0]) {
            auto p = find_row_group(_stones[gp][0]);
            gp = row2gp[r] = p.second;
            r1 = p.first;
        }
        return {r1, gp};
    }
    
    pair<int, int> find_col_group(int c) {
        auto gp = col2gp[c];
        auto c1 = c;
        if (c != _stones[gp][1]) {
            auto p = find_col_group(_stones[gp][1]);
            gp = col2gp[c] = p.second;
            c1 = p.first;
        }
        return {c1, gp};
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        _stones = stones;
        const int N = stones.size();
        int cnt = N;
        for (int i = 0; i < N; ++i) {
            row2gp.insert(make_pair(stones[i][0], i));
            col2gp.insert(make_pair(stones[i][1], i));
            auto row_gp = find_row_group(stones[i][0]);
            auto col_gp = find_col_group(stones[i][1]);
            if (row_gp.second == col_gp.second) {
                if (row_gp.second != i)
                    cnt --;
                continue;
            }
            auto min_gp = min(row_gp.second, col_gp.second);
            auto max_gp = max(row_gp.second, col_gp.second);
            if (max_gp < i)
                cnt --;
            row2gp[stones[max_gp][0]] = col2gp[stones[max_gp][1]] = min_gp;
            cnt --;
        }
        return N - cnt;
    }
};
