#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct seq {
    vector<int> data;
    int len;
    seq() : data(), len(0) {}
};

class solution {
public:
    vector<int> method1(vector<int> &va, vector<int> &vb) {
	const int m = va.size();
	const int n = vb.size();
        vector<vector<seq>> dp(m+1, vector<seq>(n+1, seq()));
        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (va[i-1] == vb[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    dp[i][j].len ++;
                    dp[i][j].data.push_back(va[i-1]);
                }
                else { 
                    if (dp[i-1][j].len >= dp[i][j-1].len)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i][j-1];
                }
            
            }
        }
        return  dp[m][n].data;
    }

    vector<int> method2(vector<int> &va, vector<int> &vb) {
	const int m = va.size();
	const int n = vb.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<vector<int>> pre(m+1, vector<int>(n+1, 0));
	
	for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
		if (va[i-1] == vb[j-1]) {
		    dp[i][j] = dp[i-1][j-1] + 1;
		    pre[i][j] = 1;
		}
		else {
		    if (dp[i-1][j] > dp[i][j-1]) {
			dp[i][j] = dp[i-1][j];
			pre[i][j] = 2;
		    } else {
			dp[i][j] = dp[i][j-1];
			pre[i][j] = 3;
		    }
		    
		}
	    }
	}
	cout << dp[m][n] << endl;
	vector<int> res;
	int i = m, j = n;
	while (i > 0 && j > 0) {
	    if (pre[i][j] == 1) {
		res.push_back(va[i-1]);
		i--; j--;
	    } else if (pre[i][j] == 2) {
		i--;
	    } else if (pre[i][j] == 3) {
		j--;
	    }
		
	}
	return res;
    }
};

int main() {
    int m, n, tmp;
    vector<int> va, vb;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        va.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vb.push_back(tmp);
    }

    solution sol;
    vector<int> res1 = sol.method1(va, vb);
    for(int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;
    vector<int> res2 = sol.method2(va, vb);
    for(int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    cout << endl;
    return 0;
}
