#include <iostream>
#include <vector>

using namespace std;

bool partition1(vector<int> nums, int n, int target)
{
    if(target == 0) 
	return true;
    if(target < 0 || n <= 0)
	return false;

    return partition1(nums, n-1, target) || partition1(nums, n-1, target-nums[n-1]);
}

void recur(vector<int> nums, int p, int tar, vector<int> &one, vector<vector<int> > &res) 
{
    if(tar == 0) 
	res.push_back(one);
    else if(tar > 0 && p > -1) {
	recur(nums, p-1, tar, one, res);
	one.push_back(nums[p]);
	recur(nums, p-1, tar-nums[p], one, res);
	one.pop_back();
    }
}

vector<vector<int> > partition2(vector<int> nums, int n, int target)
{
    vector<vector<int> > res;
    vector<int> one;
    recur(nums, n-1, target, one, res);
    return res;
}


bool partition3(vector<int> nums, const int n, const int target) 
{
    if(target == 0) 
	return true;

    if(target < 0 || n <= 0)
	return false;

    vector<vector<bool> > dp(n+1, vector<bool>(target+1, false));


    for(int i = 0; i <= n; ++i)
	dp[i][0] = true;

    for(int j = 1; j <= target; ++j)
	dp[0][j] = false;

    for(int i = 1; i <= n; ++i)
    {	for(int j = 1; j <= target; ++j)
	{
	    dp[i][j] = dp[i-1][j];
	    if(j >= nums[i-1])
		dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
	}
    }
    return dp[n][target];
}

int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n); 
    int tar = 34;
    cout << "partition sum = " << tar << "? " << partition3(nums, n, tar) << endl;
    vector<vector<int> > parts = partition2(nums, n, tar);
    for(int i = 0; i < parts.size(); ++i) {
	vector<int>::iterator it = parts[i].begin();
	cout << " \t " << tar << " = " << *it++;
	for(; it != parts[i].end(); ++it)
	    cout << "+" << *it;
	cout << endl;
    }

    return 0;
}
