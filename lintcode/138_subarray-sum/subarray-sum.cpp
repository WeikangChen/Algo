/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-05-01 15:57
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> hsSumInd;
        int sum = 0;
        hsSumInd[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto it = hsSumInd.find(sum);
            if (it != hsSumInd.end()) {
                vector<int> res;
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }
            hsSumInd[sum] = i+1;
        }
        return vector<int>();
    }
};