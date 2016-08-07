/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 16-07-06 21:37
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        if (L.empty()) return 0;
        
        int max_len = 0;
        for (auto x: L)
            max_len = max(max_len, x);
            
        int l = 0;
        int r = max_len;
        while (l < r) {
            int m = l + (r - l ) / 2.0 + 0.5;
            int j = 0;
            for (auto x : L) 
                j += x / m;
            if (j < k)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }
};