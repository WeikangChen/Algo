/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-04-29 16:53
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        const int k = 3;
        const int n = nums.size();
        vector<int> maj(k-1);
        vector<int> cnt(k-1, 0);
        for (int i = 0; i < k-1; ++i) maj[i] = i;
        for (auto n : nums) {
            int i = 0;
            for (; i < k-1; ++i) {
                if (cnt[i] == 0) {
                    maj[i] = n;
                    cnt[i] = 1;
                    break;
                } else if (maj[i] == n) {
                    cnt[i]++;
                    break;
                }
            }
            if (i == k-1) {
                for (i = 0; i < k-1; ++i) cnt[i]--;
            }
        }

        int req = n / k;
        int res = -1;
        for (int i = 0; i < k-1; i++) {
            cnt[i] = 0;
        }
        for (auto n : nums) {
            for (int i = 0; i < k-1; i++) {
                if (maj[i] == n) cnt[i]++;
            }
        }
        for (int i = 0; i < k-1; i++) {
            if (cnt[i] > req) return maj[i];
        }
        return -1;
    }
};
