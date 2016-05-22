#include <iostream>
#include <vector>

using namespace std;


int maxProfit1(vector<int>& prices) {
    int profit = 0;
    int lowest = prices[0];

    for(int i = 1; i < prices.size(); ++i)
    {
	lowest = min(lowest, prices[i]);
	profit = max(profit, prices[i]-lowest);
    }
    return profit;
}

int maxProfit2(int k, vector<int>& prices) {
    int profit = 0;

    for(int i = 1; i < prices.size(); ++i)
    {
	profit += max(prices[i]-prices[i-1], 0);
    }
    return profit;
}

int maxProfit(int k, vector<int>& prices) {
    const int n = prices.size();
    vector<vector<int> > f(n , vector<int>(k+1, 0));
    vector<int> g(k+1, 0);

    for(int i = 1; i < n; ++i)
    {
	int diff = prices[i] - prices[i-1];
	int k0 = min(i, k);
	for(int j = k0; j > 0; --j)
	{
	    int tmp = 0;
	    for(int t = j-1; t <= i-1; ++t)
		tmp = max(tmp, f[t][j-1]);
	    f[i][j] = max(f[i-1][j], tmp) + diff;
	    g[j] = max(g[j], f[i][j]);
	}
    }
    return g[k];
}

int maxProfit_dp(int k, vector<int>& prices) {
    const int n = prices.size();
    vector<int> f(k+1, 0);
    vector<int> g(k+1, 0);

    for(int i = 1; i < n; ++i)
    {
	int diff = prices[i] - prices[i-1];
	int k0 = min(i, k);
	for(int j = k0; j > 0; --j)
	{
	    f[j] = max(f[j], g[j-1]) + diff;
	    g[j] = max(g[j], f[j]);
	}
    }
    return g[k];
}

int main(int argc, char *argv[])
{
    int p[]= {1,4,2};
    vector<int> prices(p, p+sizeof(p)/sizeof(int));
    cout << "max Profit = " << maxProfit(2, prices) << endl;
    cout << "max Profit1 = " << maxProfit1(prices) << endl;
    cout << "" << endl;
    return 0;
}
