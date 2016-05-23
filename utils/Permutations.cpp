#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
       
    void uniquePermutation(vector<int> &num, int step, vector<int> &visited, vector<int> &solution, vector<vector<int> > &res)
    {
        if(step==num.size()) {
                res.push_back(solution);
                return;
        }
        
        for(int i=0; i<num.size(); i++)
        {
            if(visited[i]==0)
            {
                if(i>0 && num[i]==num[i-1] && visited[i-1] == 1 ) continue;
                visited[i]=1;
                solution.push_back(num[i]);
                uniquePermutation(num, step+1, visited, solution, res);
                solution.pop_back();
                visited[i]=0;
                //while( i > 0 && num[i]==num[i-1] ) i++;
            }
        }
        
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        vector<int> visited(num.size(), 0), solution;
        vector<vector<int> > res;
        if(num.empty()) return res;

        sort(num.begin(), num.end());
        uniquePermutation(num, 0, visited, solution, res);

        return res;
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        perm(num, 0, visited, res);
        return res;
    }

    void perm(vector<int> &s, int p, vector<int> &visited, vector<vector<int> > &res)
    {
        if( p < s.size() ) {
            int pre = INT_MIN;
            for( int i = p; i < s.size(); i++) {    //we should always loop from p, which is unaltered the order
                if( s[i] == pre || (s[i] == s[p] && i>p) ) continue;
                pre = s[i];
                swap(s[p], s[i]);
                perm(s, p+1, visited, res);
                swap(s[p], s[i]);
            }
        }
        else 
            res.push_back(s);
        
    }
};


int main() {

    const int s = 4;
    int myArr[s] = {1, 2, 2, 3};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.permuteUnique(myv);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    return 0;
}
