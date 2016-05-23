#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

unordered_set<char> found;

int minPos(string &s, int l, int r) {
    int minInd;
    char minChar = 'z';
    for(int i = l; i <= r; ++i) {
        char c = s[i];
        if(found.find(c) == found.end() && c < minChar) {
            minChar = c;
            minInd = i;
        }
    }
    return minInd;
}

string removeDuplicateLetters(string s) {
    set<char> visited;
    set<char> unique(s.begin(), s.end());
    int target = 0;
    const int n = s.size();
    int l = 0;
    int r = n-1;
    string res;
        
    for(char c: unique) target += c;
        
    while(res.size() < unique.size()) {


        int sum = 0;
        visited.clear();
        for(int i = n-1; i >= l; --i) {
            char c = s[i];
            if(visited.find(c) == visited.end() && found.find(c) == found.end()) {
                visited.insert(c);
                sum += c;
            }
                
            if(sum == target) {
                r = i;
                break;

            }
        }
            
        cout << l << ", " << r << ", ";
        int p = minPos(s, l, r);
        l = p+1;

        char tmp = s[p];
        cout << tmp << endl;
        target -= tmp;
        res += tmp;
        found.insert(tmp);

    }
    return res;
}
    


int main(int argc, char ** argv)
{
    cout << removeDuplicateLetters("abacb") << endl;
    return 0;
}
