#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> one;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; ++i) 
        {
            int ni = nums[i];
            for(int j = i+1; j < n-2; ++j)
            {
                int nj = nums[j];
                int l = j+1;
                int r = n-1;
                while(l < r) {
                    int sum = ni + nj + nums[l] + nums[r];
                    if(sum < target)
                        l++;
                    else if(sum > target)
                        r--;
                    else {
                        vector<int> one = {ni, nj, nums[l], nums[r]};
                        res.push_back(one);
                        l++; r--;
                        while(l<r && nums[l-1] == nums[l]) l++;
                        while(l<r && nums[r+1] == nums[r]) r--;
                    }
                }
                while(j < n-3 && nums[j] == nums[j+1]) j++;
            }
            while(i < n-4 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};

int main(int argc, char ** argv)
{
    int arr[] =  {1, 0, -1, 0, -2, 2};
    vector<int> varr(arr, arr+sizeof(arr)/sizeof(int));
    Solution sol;
    sol.fourSum(varr, 0);
    return 0;
}
