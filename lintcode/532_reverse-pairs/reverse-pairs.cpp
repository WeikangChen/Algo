/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 16-05-19 14:24
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long rev_pairs = 0;
        int n = A.size();
        if (n < 2) return 0;
        mergesort(A, 0, n - 1, rev_pairs);
        return rev_pairs;
    }

    void mergesort(vector<int>& A, int l, int r, long long &rev_pairs) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergesort(A, l, m, rev_pairs);
        mergesort(A, m+1, r, rev_pairs);
        merge(A, l, m, r, rev_pairs);
    }

    void merge(vector<int>& A, int l, int m, int r, long long &rev_pairs) {
        vector<int> vl(A.begin() + l, A.begin() + m + 1);
        vector<int> vr(A.begin() + m + 1, A.begin() + r + 1);
        const int sl = m - l + 1;
        const int sr = r - m;
        int i = 0, j = 0, k = l;
        while (i < sl && j < sr) {
            if (vl[i] <= vr[j]) {
                A[k++] = vl[i++];
            } else {
                A[k++] = vr[j++];
                rev_pairs += sl - i;
            }
        }
        while (i < sl)
            A[k++] = vl[i++];
        while (j < sr)
            A[k++] = vr[j++];
    }
};