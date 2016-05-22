#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef vector<vector<int>>  PART;

const int mod = 1000000007;
const int ncat = 10001;
vector<int> catalan(ncat, 0);

void cal_catalan() {
    catalan[0] = 1;
    for (int i = 1; i < ncat; ++i) {
	int tmp = 0;
	for (int j = 0; j < i; j++) {
	    tmp += catalan[j] * catalan[i-1-j];
	}
	catalan[i] = tmp;
    } 
}

long long binomial(int n, int k) {
    long long res = 1;
    k = min(k, n - k); // Since C(n, k) = C(n, n-k)
    for (int i = 0; i < k; ++i) {
	res *= (n - i);
	res /= (i + 1);
    }
    return res;
}

void partitionUtil(int p, int n, vector<int> &one, vector<vector<int> > &res) {
    if (n < 0) return;
    if (n == 0) {
	res.push_back(one);
	return;
    }
    for (int i = p; i <= n; ++i) {
	one.push_back(i);
	partitionUtil(i, n-i, one, res);
	one.pop_back();
    }
}

PART partition(int n) {
    PART res;
    vector<int> one;
    partitionUtil(1, n, one, res);
    return res;
}




int main(){

    int X = 3, Y = 20;
    //cal_catalan();


    cout << binomial(5, 2) << endl;

/*
    auto all_parts = partition(Y);
    for (auto it = all_parts.begin(); it != all_parts.end(); ++it) {
	vector<int> part = *it;
	for(int i = 0; i < part.size(); ++i) {
	    cout << part[i] << " ";
	}
	cout << endl;
    }
*/
    //for (int i = 0; i < 10; i++)
    //cout << " cata " << catalan[i] << endl;
    


    return 0;
}
