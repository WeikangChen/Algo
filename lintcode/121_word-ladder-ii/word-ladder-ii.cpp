/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-ladder-ii
@Language: C++
@Datetime: 16-07-19 01:25
*/

class Solution {
    
    unordered_map<string, unordered_set<string>> parent;
            
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        const int n = start.size();
        if (n != end.size()) return {};
        dict.erase(end);
        dict.insert(start);
        
        parent.clear();
        unordered_set<string> visited, vst1, vst2;
        unordered_set<string> *pPre = &vst1;
        unordered_set<string> *pCur = &vst2;
        
        pPre->insert(end);
        visited.insert(end);
        bool found = false;
        
        while (!pPre->empty()) {
            for (auto cur: *pPre) {
                for (int i = 0; i < n; ++i) {
                    string can = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (cur[i] == c) continue;
                        can[i] = c;
                        if (dict.find(can) != dict.end() && visited.find(can) == visited.end()) {
                            if (can == start) found = true;
                            parent[can].insert(cur);
                            pCur->insert(can);
                        }
                    }
                }
            }
            if (found) break;
            visited.insert(pCur->begin(), pCur->end());
            swap(pCur, pPre);
            pCur->clear();
        }
        if (pPre->empty()) return {};
        vector<vector<string>> res;
        vector<string> one(1, start);
        util(end, one, res);
        return res;
    }
    
    void util(string end, vector<string> &one, vector<vector<string>> &res) {

        string cur = one.back();
        if (cur == end) {
            res.push_back(vector<string>(one.begin(), one.end()));
            return;
        }
        for (auto it = parent[cur].begin(); it != parent[cur].end(); ++it) {
            one.push_back(*it);
            util(end, one, res);
            one.pop_back();
        }
    }
};