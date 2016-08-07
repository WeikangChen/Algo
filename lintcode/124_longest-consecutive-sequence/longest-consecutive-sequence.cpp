/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-consecutive-sequence
@Language: C++
@Datetime: 16-07-19 23:33
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) return 0;
        int max_len = 1;
        unordered_set<int> nset(num.begin(), num.end());
        for (int n: num) {
            if (nset.find(n-1) == nset.end()) {
                int i = n + 1;
                while(nset.find(i) != nset.end()) ++i;
                max_len = max(max_len, i - n);
            }
        }
        return max_len;
    }
};