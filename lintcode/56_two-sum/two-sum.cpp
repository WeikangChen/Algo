/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-05-03 23:54
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hs;
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (hs.find(need) != hs.end()) {
                vector<int> res;
                res.push_back(hs[need]+1);
                res.push_back(i+1);
                return res;
            } else {
                hs[nums[i]] = i;
            }
        }
        
        return vector<int>();
    }
};
