#include <iostream>
#include <vector>

using namespace std;


int cnt_merge(int *A, int l, int m, int r) {
    const int n1 = m - l + 1;
    const int n2 = r - m;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = A[l+i]; 
    for(int j = 0; j < n2; j++)
        R[j] = A[m+1+j]; 

    int cnt = 0;
    int i = 0, j = 0, k = 0;;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            A[l+k] = L[i];
            k++; i++;
        }
        else {
            A[l+k] = R[j];
            k++; j++;
            cnt += (n1 - i);
        }
    }

    while(i < n1) {
        A[l+k] = L[i];
        k++; i++;
    }
    while(j < n2) {
        A[l+k] = R[j];
        k++; j++;
        cnt += (n1 - i);
    }

    return cnt;
}


int cnt_reverse(int* A, int l, int r)
{
    int cnt = 0;
    if(l < r) {
        int m = l + (r-l) / 2;
        cnt += cnt_reverse(A, l, m);
        cnt += cnt_reverse(A, m+1, r);
        cnt += cnt_merge(A, l, m, r);
    }
    return cnt;
}


void merge(int *A, int l, int m, int r) {
    const int n1 = m - l + 1;
    const int n2 = r - m;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = A[l+i]; 
    for(int j = 0; j < n2; j++)
        R[j] = A[m+1+j]; 

    int i = 0, j = 0, k = 0;;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            A[l+k] = L[i];
            k++; i++;
        }
        else {
            A[l+k] = R[j];
            k++; j++;
        }
    }

    while(i < n1) {
        A[l+k] = L[i];
        k++; i++;
    }
    while(j < n2) {
        A[l+k] = R[j];
        k++; j++;
    }

    return;
}


void mergesort(int* A, int l, int r)
{
    if(l < r) {
        int m = l + (r-l) / 2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, m, r);
    }
}

int main(int argc, char ** argv)
{
    //int A[] = {6, 3, 5, 7, 2, 4, 1, 9, 8};
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int N = sizeof(A)/sizeof(int);
    int reverse = cnt_reverse(A, 0, N);

    for(int i = 0; i < N; ++i)
    {
        cout << A[i] << ", ";
    }
    cout << endl;

    cout << "revese # = " << reverse << endl;

    try
    {
        int* myarray= new int[100000000000000];
    }
    catch (exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }


    for(int i = 0; i < N; ++i)
    {
        cout << A[i] << ", ";
    }
    cout << endl;

    cout << "revese # = " << reverse << endl;
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    bool bl = false;
    cout << "sizeof(bool variable) = " << sizeof(bl) << endl;
    
    vector<bool> test(3);
    for(int i = 0; i < test.size(); ++i) {
        cout << test[i] << " " << sizeof(test[i]) << endl;;
    }


    
    bool barr[] = {true, true, true, true};

    for(int i = 0; i < 3; ++i)
        cout << barr[i] << endl;

    int abc[] = {1,2,3,4,5};
    int x = 1;

    
    char *ptr1 = (char *)barr;
    for(int i = 0; i < 4; ++i) {
        cout << (void*)(ptr1) << " --> " << *ptr1+'0' << endl;
        ptr1++;
    }

    return 0;

}
