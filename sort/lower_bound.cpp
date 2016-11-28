#include <iostream>
#include <vector>

using namespace std;

bool mycompare(int i, int j)
{
    return i > j;
}

int main(int argc, char ** argv)
{
    int A[] = {1, 2, 3, 3, 3, 4, 5, 6};
    const int n = sizeof(A)/sizeof(int);
    vector<int> va(A, A + n);
    vector<int> vb;
    /*
    sort(va.begin(), va.end(), mycompare);
    for(int i = 0; i < n; ++i)
    {
        cout << va[i] << " ";
    }
    cout << endl;
    */

    for (int i = 0; i < n; ++i)
    {
        auto it1 = lower_bound(vb.begin(), vb.end(), va[i]);
        auto it2 = upper_bound(vb.begin(), vb.end(), va[i]);

        cout << it1 - vb.begin()<< ", " << it2 -vb.begin() << endl;
        vb.insert(it1, va[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        cout << vb[i] << " ";
    }
    cout << endl;
    
    return 0;
}
