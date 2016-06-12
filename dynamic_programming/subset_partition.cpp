
#include <iostream>
#include <vector>

using namespace std;

bool partition(vector<int> arr) {
    if (arr.empty()) return false;
    const int n = arr.size();

    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += arr[i];
    //cout << sum << endl;
    if (sum & 1) return false;
    int tar = sum / 2;
    //cout << tar << endl;

    vector<vector<bool> > dp(n, vector<bool>(tar+1, false));
    dp[0][0] = dp[0][arr[0]] = true;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = true;
        for (int j = 0; j <= tar; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j - arr[i] >= 0)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
        }
    }

    return dp[n-1][tar];
}

int main(int argc, char *argv[])
{
    int a[] = {5, 4, 9};
    vector<int> arr(a, a+sizeof(a)/sizeof(int));
    bool p = partition(arr);
    cout << (p ? "True" : "False") << endl;
    return 0;
}
