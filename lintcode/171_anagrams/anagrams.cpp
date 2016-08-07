/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-07-01 17:36
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> dict;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            auto it = dict.find(tmp);
            if (it != dict.end()) {
                res.push_back(strs[i]);
                if (it->second >= 0) {
                    res.push_back(strs[it->second]);
                    it->second = -1;
                }
            } else {
                dict[tmp] = i;
            }
        }
        return res;
    }
};
