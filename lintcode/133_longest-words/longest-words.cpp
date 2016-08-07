/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 16-05-12 00:34
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> res;
        int longest = 0;
        for (auto &word : dictionary) {
            if (word.size() > longest) {
                longest = word.size();
                res.clear();
                res.push_back(word);
            } else if (word.size() == longest) {
                res.push_back(word);
            }
        }
        return res;
    }
};