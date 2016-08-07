/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-ladder
@Language: C++
@Datetime: 16-07-08 01:22
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        const int n = start.size();
        if (n != end.size()) return -1;
        queue<string> q;
        q.push(start);
        dict.erase(start);
        dict.insert(end);
        int cnt = 1;
        int lvl = 1;
        while(q.size()) {
            string cur = q.front();
            q.pop(); 
            cnt--;
            if (cur == end) return lvl;
            for (int i = 0; i < n; i++) {
                char bak = cur[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == bak) continue;
                    cur[i] = c;
                    if(dict.find(cur) != dict.end()) {
                        dict.erase(cur);
                        q.push(cur);
                    }
                }
                cur[i] = bak;
            }
            
            if (cnt == 0) { 
                cnt = q.size();
                lvl ++;
            }
        }
        
        return -1;
    }
};