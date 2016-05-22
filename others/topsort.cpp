#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public: 
    vector<int> findOrder(int num, vector<pair<int, int> > &requests) {
	vector<unordered_set<int> > graph(num, unordered_set<int>());
	vector<bool> visited(num, false);
	vector<int> topsort;

	for(int i = 0; i < requests.size(); ++i)
	    graph[requests[i].first].insert(requests[i].second);

	for(int i = 0; i < num; ++i) {
	    if(!visited[i]) dfs(i, visited, graph, topsort);
	}

	return topsort;
    }

    void dfs(int node, vector<bool> &visited, vector<unordered_set<int> > &graph, vector<int> &topsort) {
	visited[node] = true;

	unordered_set<int>::iterator it;

	for(it = graph[node].begin(); it != graph[node].end(); ++it) {
	    if(!visited[*it])
		dfs(*it, visited, graph, topsort);
	}

	topsort.push_back(node);

    }

};

// Course Schedule II
// prerequisities: to take course 0 one must first take course 1: [0, 1] == 1 -> 0
int main(int argc, char *argv[])
{
    const int n = 6;
    vector<pair<int, int> > requests;

    requests.push_back(make_pair(5, 2));
    requests.push_back(make_pair(5, 0));
    requests.push_back(make_pair(4, 0));
    requests.push_back(make_pair(4, 1));
    requests.push_back(make_pair(2, 3));
    requests.push_back(make_pair(3, 1));

    Solution sol;
    vector<int> topsort = sol.findOrder(n, requests);
    reverse(topsort.begin(), topsort.end());
    for(int i = 0; i < topsort.size(); ++i)
    {
	cout << topsort[i] << " ";
    }
    cout << "" << endl;

    return 0;
}
