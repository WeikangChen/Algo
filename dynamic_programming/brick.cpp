#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long game(vector<int> &arr) {
    const int n = arr.size();
    if(n == 0) return 0;
    vector<long long> A1(n, 0);
    vector<long long> A2(n, INT_MIN);
    vector<long long> A3(n, INT_MIN);
    vector<long long> B1(n, INT_MIN);
    vector<long long> B2(n, INT_MIN);
    vector<long long> B3(n, INT_MIN);
    long long sum = arr[0];
    A1[0] = arr[0];
    for(int i = 1; i < n; ++i){
        sum += arr[i];
        A1[i] = min(B1[i-1], min(B2[i-1], B3[i-1])) + arr[i];
        A2[i] = A1[i-1] + arr[i];
        A3[i] = A2[i-1] + arr[i];
        B1[i] = max(A1[i-1], max(A2[i-1], A3[i-1])) - arr[i];
        B2[i] = B1[i-1] - arr[i];
        B3[i] = B2[i-1] - arr[i];
    }
    
    long long maxA = max(A1[n-1], max(A2[n-1], A3[n-1]));
    long long maxB = max(B1[n-1], max(B2[n-1], B3[n-1]));

    cout << "\t" << A1[n-1] << endl;
    cout << "\t" << A2[n-1] << endl;
    cout << "\t" << A3[n-1] << endl;
    cout << "\t" << B1[n-1] << endl;
    cout << "\t" << B2[n-1] << endl;
    cout << "\t" << B3[n-1] << endl;
    
    return  (max(maxA, maxB) + sum)/2;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        int N, tmp;
        vector<int> arr;
        cin >> N;
        for(int i = 0; i < N; ++i) {
            cin >> tmp;
            arr.push_back(tmp);
        }
        cout << game(arr) << endl;
    }
    
    
    return 0;
}
