#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        
        perm(num, 0, res);
        return res;
    }
    
    void perm(vector<int> &num, int p, vector<vector<int> > &res)
    {
        if(p == num.size()) {
            res.push_back(num);
	    for(int i = 0; i < num.size(); ++i)
		cout << num[i] << " ";
	    cout << endl;
            return;
        }
        
        for(int i = p; i < num.size(); ++i)
        {
            swap(num[p], num[i]);
            perm(num, p+1, res);
            swap(num[p], num[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        
        permU(num, num.size()-1, res);
        return res;
    }
    
    void permU(vector<int> &num, int p, vector<vector<int> > &res) {
        if(p == -1 ){
            res.push_back(num);
	    for(int i = 0; i < num.size(); ++i)
		cout << num[i] << " ";
	    cout << endl;
            return;
        }
        
        for(int i = p; i < num.size(); ++i) {
            if(i != p && num[i] == num[p]) break;
            swap(num[i], num[p]);
            permU(num, p-1, res);
            swap(num[i], num[p]);
        }
    }
};

int main(int argc, char *argv[])
{

    Solution s;
    int a[] = {1,2,3,4,4};
    vector<int> as(a, a+sizeof(a)/4);
    
    s.permute(as);
    cout << endl;
    s.permuteUnique(as);

    return 0;
}
