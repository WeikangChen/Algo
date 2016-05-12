#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        const int s = nums.size();
        vector<bool> good(n, false);
        int add = 0;
        
        dfs(nums, 0, s, 0, n, good);
	
	cout << good[2] << endl;
        for(int i = 1; i <= n; ++i)
        {
            if(!good[i-1]) 
            {
                add ++; //add i here
                i += (i-1);
            }
        }
        
        return add;
    }
    
    void dfs(vector<int>& nums, int p, int s, int c, int n,  vector<bool> &good)
    {
        if(c > n) return;
        if(c > 0) good[c-1] = true;
        for(int i = p; i < s; ++i)
            dfs(nums, i+1, s, c+nums[i], n, good);
    }
};

int main() {

    Solution mySol;
    int arr[] = {1, 2, 4};
    int n = 21;
    vector<int> var(arr, arr+sizeof(arr)/sizeof(int));
    mySol.minPatches(var, n);

    return 0;
}
