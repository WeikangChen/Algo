#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

typedef pair<int, int> node;

class Comparator
{
public:
    int operator() ( const pair<int,float>& p1, const pair<int,float> &p2)
    {
        return p1.second>p2.second;
    }
};


bool comparator(node a, node b) {
    return a.second > b.second;
}

void bfs_shortest(int S, int N, vector<vector<node> > graph)
{

    vector<int> distance(N+1, INT_MAX);
    vector<int> previous(N+1, -1);
    vector<bool> visited(N+1, false);

    visited[S] = true;
    distance[S] = 0;
    previous[S] = S;

    //priority_queue<node, vector<node>, decltype(&comparator) > Q;
    priority_queue<node, vector<node>, Comparator > Q;
    Q.push(make_pair(S, distance[S]));

    while(Q.size()) {
        node one = Q.top();
        Q.pop();
        int u = one.first;
        visited[u] = true;
        cout << u << ":" << one.second << endl;
        for (int i = 0; i < graph[u].size(); ++i) {

            int v = graph[u][i].first;

            int d = one.second + graph[u][i].second;
            cout << "1usize:" << graph[u].size() << ", v = " << v << ", d = " <<d<< endl;
            if (d < distance[v]) {
                distance[v] = d;
                previous[v] = u;
                cout << "2usize:" << graph[u].size() << ", v = " << v << ", d = " <<d<< endl;
                Q.push(make_pair(v, d));
                cout << "3usize:" << graph[u].size() << ", v = " << v << ", d = " <<d<< endl;
            }

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
        vector<vector<node> > graph(N+1, vector<node>());
        for (int i = 0; i < M; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            graph[x].push_back(make_pair(y, r));
            graph[y].push_back(make_pair(x, r));
        }
        cin >> S;
        bfs_shortest(S, N, graph);
    }
    return 0;
}
