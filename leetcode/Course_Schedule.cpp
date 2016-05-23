

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {

public:
    /*
      bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      if(numCourses <= 0) return true;
      vector<unordered_set<int> > graph(numCourses);
      vector<bool> visited(numCourses, false);
      vector<bool> onpath(numCourses, false);

      for(auto pre: prerequisites)
      graph[pre.second].insert(pre.first);
            
      for(int i = 0; i < numCourses; ++i)
      if(dfs_find_cycle(i, visited, onpath, graph)) 
      return false;

      return true;
      }
    
      bool dfs_find_cycle(int n, vector<bool> &visited, vector<bool> &onpath, vector<unordered_set<int> > &graph) {
      cout << visited[n] << ":" << onpath[n] << endl;
      if(visited[n]) return false;
      visited[n] = onpath[n] = true; 
      unordered_set<int>::iterator it;
      for(it = graph[n].begin(); it != graph[n].end(); ++it) {
      if(onpath[*it] || dfs_find_cycle(*it, visited, onpath, graph))
      return true;
      }
      return onpath[n] = false;
      }
    */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisities) {
        if(numCourses <= 0) return true;
        vector<vector<int> > graph(numCourses);
        vector<bool> visited(numCourses);
        vector<bool> onpath(numCourses);

        for (auto pre: prerequisities)
            graph[pre.second].push_back(pre.first);

        for (int i = 0; i < numCourses; ++i)
            if (!visited[i] && dfs_find_cycle(i, graph, visited, onpath)) return false;
                
        return true;
    }
    
    bool dfs_find_cycle(int p, vector<vector<int> > &graph, vector<bool> &visited, vector<bool> &onpath) {
        visited[p] = onpath[p] = true;
        vector<int> &adj = graph[p];
        for (int i = 0; i < adj.size(); ++i) {
            int j = adj[i];
            if(onpath[j]) return true;
            if(!visited[j] && dfs_find_cycle(j, graph, visited, onpath)) return true;
        }
        return onpath[p] = false;
    };

    vector<int> findOrder1(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> topsort;
        if(numCourses <= 0) return topsort;
        vector<unordered_set<int> > graph(numCourses);
        vector<int> pre_cnt(numCourses, 0);
        
        for(auto pre: prerequisites) {
            graph[pre.second].insert(pre.first);
            pre_cnt[pre.first]++;
        }
        
        queue<int> que;
        for(int i = 0; i < numCourses; ++i)
            if(pre_cnt[i] == 0) que.push(i);
        
        while(!que.empty()) {
            int cur = que.front(); que.pop();
            topsort.push_back(cur);
            for(auto i: graph[cur]) 
                if(--pre_cnt[i] == 0) que.push(i);
        }

        return topsort;
    }
};



struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution1 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        const int n = graph.size();
        vector<DirectedGraphNode*> res;
        vector<bool> visited(n, false);
        for (auto pNode : graph) {
            if (!visited[pNode->label])
                dfs(pNode, graph, visited, res);
        }
        return res;
    }

    void dfs(DirectedGraphNode* ptr, vector<DirectedGraphNode*> &graph,
             vector<bool> &visited, vector<DirectedGraphNode*> &res) {
        visited[ptr->label] = true;
        vector<DirectedGraphNode *> &neigh = ptr->neighbors;
        for (auto pNode : neigh) {
            if (!visited[pNode->label])
                dfs(pNode, graph, visited, res);
        }
        res.push_back(ptr);
    }
};

int main(int argc, char ** argv)
{
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(0,1));
    Solution sol;
    sol.canFinish(2, prerequisites);

    char *s = new char[10];
    strcpy(s, "hello");
    printf("%s\n", s);
    delete s;
    printf("%s\n", s);
    printf("%s\n", s);
    return 0;
}

