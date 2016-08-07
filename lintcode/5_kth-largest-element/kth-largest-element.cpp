/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 16-05-03 14:51
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        k -= 1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int p = partition(nums, l, r);
            if (p == k)
                return nums[p];
            else if (p < k)
                l = p + 1;
            else
                r = p - 1;
        }
        return nums[l];
    }
    
    int partition(vector<int> &nums, int l, int r) {
        int q = l + 1.0 * rand() / RAND_MAX * (r - l + 1);
        int x = nums[q];
        swap(nums[q], nums[r]);
        int p = l;
        for (int i = l; i < r; ++i)
            if (nums[i] > x) swap(nums[p++], nums[i]);
        swap(nums[p], nums[r]);
        return p;
    }
};