#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int plus_one(int i) 
{
    static unordered_map<int, int> dict = {{0, 1}, {1, 6}, {6, 8}, {8, 9}};
    const int d = i % 10;
    if (d != 9) {
        return 10 * (i / 10) + dict[d];
    } else {
        return 10 * plus_one(i / 10);
    }
}

int rev(int i) {
    int res = 0;
    while (i) {
        res *= 10;
        res += i % 10;
        i /= 10;
    } 
    return res;
}

int main() {
    int n;
    cin >> n;
    int t = 1; 
    while (t <= n) {
        if (t % 10 && rev(t) <= n)
            cout << t << " ";
        t = plus_one(t);
    }    

    cout << endl;
    return 0;
}

