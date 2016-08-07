/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 16-04-24 18:02
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        stringstream ss(s);
        string one;
        int res = 0;
        while (ss >> one) res = one.size();
        return res;
    }
};