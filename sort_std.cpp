#include <iostream>
#include <vector>

using namespace std;

bool mycompare(int i, int j)
{
    return i > j;
}

int main(int argc, char ** argv)
{
    int A[] = {6, 3, 5, 7, 9, 2, 4, 1, 8, 5};
    const int n = sizeof(A)/sizeof(int);
    vector<int> va(A, A + n);

    sort(va.begin(), va.end(), mycompare);
    for(int i = 0; i < n; ++i)
    {
        cout << va[i] << " ";
    }
    cout << endl;
    return 0;
}
