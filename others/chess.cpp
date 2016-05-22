#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int move_x[] = {2, 2, 1, -1};
int move_y[] = {-1, 1, 2, 2};

int main() {
    vector<vector<bool> > dp(16, vector<bool>(16, false));
    vector<vector<bool> > visited(16, vector<bool>(16, false));

    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));
    que.push(make_pair(1, 2));
    que.push(make_pair(2, 1));
    que.push(make_pair(2, 2));
    visited[1][1] = visited[1][2] = visited[2][1] = visited[2][2] = true;

    while(que.size()) {
	//cout << que.size() << "," ;
        pair<int, int> p = que.front(); que.pop();
        int x = p.first;
        int y = p.second;
        bool cur = dp[x][y];
        for(int i = 0; i < 4; ++i) {
            int nx = x + move_x[i];
            int ny = y + move_y[i];
	    cout << nx << "," << ny << endl;
            if(nx < 1 || nx > 15) continue;
            if(ny < 1 || ny > 15) continue;

            if(!cur)
                dp[nx][ny] = true;
            else
                dp[nx][ny] = dp[nx][ny] || false;

            //if(visited[nx][ny]) continue;
            que.push(make_pair(nx, ny));
	    visited[nx][ny] = true;
        }
    }
    
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int x, y;
        cin >> x >> y;
        cout << (dp[x][y] ? "First" : "Second") << endl;
    }
    for (int x = 1; x < 16; ++x) {
	for (int y = 1; y < 16; ++y) {
	    cout << dp[x][y] << " ";
	}
	cout << endl;
    }
    return 0;
}
