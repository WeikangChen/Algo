#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void bfs_shortest(int S, int N, vector<unordered_set<int>> graph)
{
    vector<int> distance(N+1, -1);
    queue<int> que;
    que.push(S);
    int cnt = 1;
    int lvl = 1;
    while (que.size()) {
        int cur = que.front();
        que.pop();
        cnt--;
        for (auto &i : graph[cur]) {
            if(distance[i] < 0)
                distance[i] = 6 * lvl;
                que.push(i);
        }
        if (cnt == 0) {
            cnt = que.size();
            lvl++;
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        if (i != S)
            cout << distance[i] << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv)
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M, S;
        cin >> N >> M;
        vector<unordered_set<int>> graph(N+1, unordered_set<int>());
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        cin >> S;
        cout << N << M << S << endl;
        bfs_shortest(S, N, graph);
    }
    return 0;
}
