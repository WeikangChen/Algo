/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 16-07-12 14:54
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> one;
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        util(num, 0, target, one, res);
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
            if (i > p && can[i] == can[i-1]) continue;
            one.push_back(can[i]);
            util(can, i+1, tar-can[i], one, res);
            one.pop_back();
        }
    }
    
};