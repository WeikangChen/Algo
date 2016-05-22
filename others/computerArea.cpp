#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class AA
{
private:
    int t;
public:
    AA(int a) : t(a) {}
    void print() {cout << "t = " << t << endl;}
};

#include<algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution1(vector<int> &A) {

    int N = A.size();

    if(N<=1)
        return 0;

    sort(A.begin(),A.end());

    int count = 0;
    int status = 1;
    for(int i = 1;i < N;i++){
        if(A[i]==A[i-1]){
            status += 1;
        }
        else if(status > 1)
        {
            count += status*(status-1)/2;
            status = 1;
        }
    }

    if(status > 1)
            count += status*(status-1)/2;
    if (count>1000000000)
        count = 1000000000;

    return count;
}

int C(int m, int n) {

    long long ft, fs;
    int bg, sm, tt;

    bg = max(m-n, n);
    sm = min(m-n, n);
    tt = m;

    ft = fs = 1;
    while(tt > bg) fs *= tt--;
    while(sm > 0)  ft *= sm--;

    return fs / ft;
}

int solution(vector<int> &A)
{
    unordered_map<int, int> hs;
    int N = A.size();
    for(int i = 0; i < N; ++i)
    {
        int a = A[i];
        if(hs.find(a) == hs.end())
            hs[a] = 1;
        else
            hs[a] += 1;
    }

    int res = 0;
    unordered_map<int, int>:: iterator it;
    for(it = hs.begin(); it != hs.end(); ++it)
    {
        if(it->second >=2 )
            res += C(it->second, 2);
    }
    return res;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w1 = abs(A-C);
        int h1 = abs(B-D);
        int w2 = abs(E-G);
        int h2 = abs(F-H);

        int test1 = (w1 + w2) - abs((A+C) - (E+G));
        int test2 = (h1 + h2) - abs((B+D) - (F+H));

        float w3 = test1 > 0 ? test1 * 0.5 : 0;
        float h3 = test2 > 0 ? test2 * 0.5 : 0;

        cout << test1 << endl;
        cout << test2 << endl;

        return w1 * h1 + w2 * h2 ;

}

int main(int argc, char ** argv)
{
    char cs[] =  {'1', '2', '\0'};
    cout << strlen(cs) << endl;
    int ls[] = {3,5,6,3,3,5};
    vector<int> A(ls, ls+sizeof(ls)/sizeof(int));
    cout << solution1(A) << endl;
    cout << computeArea(0,0,0,0,-1,-1,1,1) << endl;
    cout << -8 % 10 << endl;

    AA a[3] = {AA(111), AA(12), 13};
    a[0].print();
    a[1].print();
    a[2].print();

    unordered_map<double, int> test;
    return 0;
}
