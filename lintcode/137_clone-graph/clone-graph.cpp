/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: C++
@Datetime: 16-07-24 21:22
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if (!node) return NULL;
        
        UndirectedGraphNode* cp_head = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hs;
        hs[node] = cp_head;
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        unordered_set<UndirectedGraphNode*> visited;
        visited.insert(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* cur = q.front(); q.pop();
            UndirectedGraphNode* cp_cur = hs[cur];
            for (auto &one: cur->neighbors) {
                auto it = hs.find(one);
                if (it == hs.end()) 
                    it = hs.insert(make_pair(one, new UndirectedGraphNode(one->label))).first;
                cp_cur->neighbors.push_back(it->second);
                
                if (visited.insert(one).second) q.push(one);
            }
        }
        
        return cp_head;
    }
};