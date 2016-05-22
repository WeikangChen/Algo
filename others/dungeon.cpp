#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <cmath>
#include <climits>

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
            int d0j = dungeon[0][j];
	        int dp2 = d0j + dp[j-1][0].second;
	        int dp1 = min(dp2, dp[j-1][0].first);
            dp[j].push_back(make_pair(dp1, dp2));
        }
        
        for(int i = 1; i < m; ++i)
        {
	        int di0 = dungeon[i][0];
            int dp2 = di0 + dp[0][0].second;
	        int dp1 = min(dp2, dp[0][0].first);
            dp[0][0] = make_pair(dp1, dp2);
            for(int j = 1; j < n; ++j)
            {
                vector<pair<int, int> > lu = dp[j];
                vector<pair<int, int> > ll = dp[j-1];
                dp[j] = merge(dp[j], dp[j-1]);
		        int dij = dungeon[i][j];
		        for(int s = 0; s < dp[j].size(); ++s)
        		{
        		    dp[j][s].first += dij;
        		    dp[j][s].second += dij;
        		}
            }
        }
        
        vector<pair<int, int> > :: iterator it, it_min;
        int min1 = INT_MIN;
        int min2 = INT_MIN;
        for(it = dp[n-1].begin(); it != dp[n-1].end(); ++it)
        {
            if(it->first == min1) {
                min2 = max(it->second, min2);
            }
            else if(it->first > min1) {
                min1 = it->first;
                min2 = it->second;
            } 
            
        }
        
	return min2<0? 1-min2 : 1;

    }

    vector<pair<int, int> > merge(vector<pair<int, int> > &l1, vector<pair<int, int> > &l2)
    {
    	int s1 = l1.size();
    	int s2 = l2.size();
    	bool l1_better, l2_better;
    	l1_better = l2_better =  false;
                
    	for(int i = 0; i < s1; ++i)
    	{
    	    bool succ = true;
    	    for(int j = 0; j < s2; ++j)
    	    {
    		    if(l1[i].first > l2[j].first || l1[i].second > l2[j].second)
        		{
        		    succ = false;
        		    break;   
        		}
    	    }
    	    if(succ) {l1_better = true; break;}
    	}
    	if(l1_better) return l1;
    	
    	for(int j = 0; j < s2; ++j)
    	{
    	    bool succ = true;
    	    for(int i = 0; i < s1; ++i)
    	    {
    		    if(l2[j].first > l1[i].first || l2[j].second > l1[i].second)
    		    {
    		        succ = false;
    		        break;   
    		    }
    	    }
    	    if(succ) {l2_better = true; break;}
    	}
    	if(l2_better) return l2;

    	l1.insert(l1.end(), l2.begin(), l2.end());
    	return l1;

    }
};


int main(int argc, char ** argv)
{
    Solution s;
    vector<vector<int> > dun(10, vector<int>(10, -1));
    cout << s.calculateMinimumHP(dun) << endl;

    return 0;
}

