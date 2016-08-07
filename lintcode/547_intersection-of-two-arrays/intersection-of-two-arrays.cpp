/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-07-24 02:31
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        const int m = nums1.size();
        const int n = nums2.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums2[j] < nums1[i]) {
                j++;
            }
            else {
                if (res.empty() || nums1[i] != res.back())
                    res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
        
    }
};