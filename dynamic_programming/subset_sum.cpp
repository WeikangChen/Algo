#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int tar) {
    if (tar < 0) return false;
    if (n == 0) return tar == 0; 

    vector<vector<bool> > dp(n + 1, vector<bool>(tar + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = true;
        for (int j = 1; j <= tar; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j - arr[i-1] >= 0)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n-1][tar];
}

int main(int argc, char *argv[])
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 15;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
      cout << "Found a subset with given sum" << endl;
  else
      cout << "No subset with given sum" << endl;
  return 0;
}
