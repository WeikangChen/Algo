/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: C++
@Datetime: 16-05-05 03:09
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
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
        reverse(res.begin(), res.end());
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