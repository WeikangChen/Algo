/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 16-07-12 14:50
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> one;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        util(candidates, 0, target, one, res);
        return res;
    }
    
    void util(vector<int> &can, int p, int tar, 
    vector<int> &one, vector<vector<int>> &res) {
        if (tar < 0)
            return;
        if (tar == 0) {
            res.push_back(one);
            return;
        }
        
        for (int i = p; i < can.size(); ++i) {
            one.push_back(can[i]);
            util(can, i, tar-can[i], one, res);
            one.pop_back();
        }
    }
    
    
};