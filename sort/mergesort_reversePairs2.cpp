#include <iostream>
#include <vector>

using namespace std;


    
void merge(vector<int>& A, int l, int m, int r, long long &rev_pairs) {
    cout << l << m << r << endl;
    vector<int> vl(A.begin()+l, A.begin()+m+1);
    vector<int> vr(A.begin()+m+1, A.begin()+r+1);
    const int sl = m - l + 1;
    const int sr = r - m;
    int i = 0, j = 0, k = l;
        
    while(i < sl && j < sr) {
        if(vl[i] <= vr[j]) {
            A[k++] = vl[i++];
        }
        else { 
            A[k++] = vr[j++];
            rev_pairs += sl - i;
        }
    }
    while(i < sl)
        A[k++] = vl[i++];
    while(j < sr)
        A[k++] = vr[j++];
        
}

    
void mergeUtil(vector<int>& A, int l, int r, long long &rev_pairs) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeUtil(A, l, m, rev_pairs);
    mergeUtil(A, m+1, r, rev_pairs);
    merge(A, l, m, r, rev_pairs);
}

long long reversePairs(vector<int>& A) {
    const int n = A.size();
    if (n < 2) return 0;
    long long rev_pairs = 0;
    mergeUtil(A, 0, n-1, rev_pairs);
    return rev_pairs;
}

int main(int argc, char ** argv)
{
    vector<int> A = {8,7,6};
    cout << "Reverse Pair = " << reversePairs(A) << endl;
    return 0;
}
