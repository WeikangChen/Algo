/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-04-20 18:39
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        unordered_map<char, int> dict;
        for (auto c : A) dict[c]++;
        for (auto c : B) if (dict[c]-- == 0) return false;
        return true;
    }
};
