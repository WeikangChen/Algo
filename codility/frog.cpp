#include <queue> 
#include <iostream>
#include <vector>


using namespace std;

int solution(int X, vector<int> &A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    const int D = 1;
    const int N = A.size();
    int cur = 0;
    if (cur + D > X) return 0;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] <= cur) continue;

        pq.push(A[i]);
        while (!pq.empty() && pq.top() <= cur + D) {
            cur = pq.top(); pq.pop();
        }
        
        if (cur + D > X) return i;
    }
    return -1;
}



int main(int argc, char *argv[])
{
    cout << "" << endl;
    return 0;
}

