/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 16-04-24 16:51
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        const int n = A.size();
        if (B.size() != n) return 2.0;
        double inner_prod = 0.0;
        double lensq_A = 0.0;
        double lensq_B = 0.0;
        for (int i = 0; i < n; ++i) {
            inner_prod += A[i] * B[i];
            lensq_A += A[i] * A[i];
            lensq_B += B[i] * B[i];
        }
        if (lensq_A == 0.0 || lensq_B == 0.0)
            return 2.0;
        return inner_prod / (sqrt(lensq_A) * sqrt(lensq_B));
    }
};
