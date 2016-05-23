#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<pair<int, int> > > dp(n);

	    int d00 = dungeon[0][0];
	    dp[0].push_back(make_pair(d00, d00));

        for(int j = 1; j < n; ++j)
        {
	        int dp2 = dungeon[0][j] + dp[j-1][0].second;
	        int dp1 = min(dp2, dp[j-1][0].first);
            dp[j].push_back(make_pair(dp1, dp2));
        }

        for(int i = 1; i < m; ++i)
        {
            int dp2 = dungeon[i][0] + dp[0][0].second;
	        int dp1 = min(dp2, dp[0][0].first);
            dp[0][0] = make_pair(dp1, dp2);
            for(int j = 1; j < n; ++j)
            {
                dp[j] = merge(dp[j-1], dp[j]);
		        for(int k = 0; k < dp[j].size(); ++k)
        		{
        		    dp[j][k].second += dungeon[i][j];
        		    dp[j][k].first = min(dp[j][k].second, dp[j][k].first);
        		}
            }
        }

        int res = INT_MIN;
        for(vector<pair<int, int> > :: iterator it = dp[n-1].begin(); it != dp[n-1].end(); ++it)
        {
            int tmp = min(it->first, it->second);
            res = max(tmp, res);
        }

	    return max(1, 1-res);
    }

    vector<pair<int, int> > merge(vector<pair<int, int> > &l1, vector<pair<int, int> > &l2)
    {
    	int s1 = l1.size();
    	int s2 = l2.size();

    	for(int i = 0; i < s1; ++i)
    	{
    	    bool succ = true;
    	    for(int j = 0; j < s2; ++j)
    	    {
    		    if(l1[i].first < l2[j].first || l1[i].second < l2[j].second)
        		{
        		    succ = false;
        		    break;
        		}
    	    }
    	    if(succ) return l1;
    	}

    	for(int j = 0; j < s2; ++j)
    	{
    	    bool succ = true;
    	    for(int i = 0; i < s1; ++i)
    	    {
    		    if(l2[j].first < l1[i].first || l2[j].second < l1[i].second)
    		    {
    		        succ = false;
    		        break;
    		    }
    	    }
    	    if(succ) return l2;
    	}

    	l1.insert(l1.end(), l2.begin(), l2.end());
    	return l1;
    }
};



int main() {

    Solution mySol;
    vector<vector<int> > matrix(100, vector<int>(100, -1));


    cout << mySol.calculateMinimumHP(matrix) << endl;


    return 0;
}
