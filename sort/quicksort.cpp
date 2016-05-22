#include <iostream>
#include <vector>

using namespace std;

int partition(int* A, int l, int r)
{
    int t = 1.0 * rand() / RAND_MAX * (r-l+1) + l;
    int x = A[t];
    swap(A[t], A[r]);

    int p = l;
    for(int i = l; i < r; ++i)
    {
        if(A[i] < x)
            swap(A[i], A[p++]);
    }
    swap(A[p], A[r]);
    return p;
}


void quicksort(int *A, int l, int r)
{
    if(l < r)
    {
        int p = partition(A, l, r);
        quicksort(A, l, p-1);
        quicksort(A, p+1, r);
    }

}

int main(int argc, char ** argv)
{
    int A[] = {6, 3, 5, 7, 2, 4, 1, 9, 8};
    int N = sizeof(A)/sizeof(int);
    quicksort(A, 0, N-1);

    for(int i = 0; i < N; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
