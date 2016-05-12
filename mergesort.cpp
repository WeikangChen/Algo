#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &l, vector<int> &r)
{
    vector<int> res;
    int m = l.size();
    int n = r.size();
    int i = 0;
    int j = 0;

    while(i < m && j < n)
    {
        if(l[i] < r[j])
            res.push_back(l[i++]);
        else
            res.push_back(r[j++]);
    }

    if(i < m)
        res.insert(res.end(), l.begin()+i, l.end());
    else
        res.insert(res.end(), r.begin()+j, r.end());

    return res;

}

void mergesort(vector<int> &A)
{
    int n = A.size();
    if(n < 2) return;

    vector<int> l(A.begin(), A.begin()+n/2);
    vector<int> r(A.begin()+n/2, A.end());
    mergesort(l);
    mergesort(r);
    A = merge(l, r);
    return;
}

int solution(vector<int> &A) {
    mergesort(A);

    int N= A.size();
    int r1 = A[N-1] * A[N-2] * A[N-3];
    int r2 = A[0] * A[1] * A[2];
    int r3 = A[0] * A[1] * A[N-1];

    return max(max(r1, r2), r3);
}

int main(int argc, char ** argv)
{
    int a[] = {5, 2, 7, 4, 6, 1, 8, 3, 9};
    vector<int> A(a, a+sizeof(a)/sizeof(4));

    cout << "Before Sort:\t";
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    mergesort(A);

    cout << "After Sort:\t";
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
