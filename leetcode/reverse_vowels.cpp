#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

string reverseVowels(string s) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int l = 0;
    int r = s.size() - 1;
    while(l < r) {
        while(l < r && vowels.find(s[l]) == vowels.end()) l++;
        while(l < r && vowels.find(s[r]) == vowels.end()) r--;
        swap(s[l++], s[r--]);
        cout << l << ", "<< r << endl;
    }
    return s;
}

int main(int argc, char ** argv)
{
    string str("leetcode");
    cout << reverseVowels(str) << endl;
    
    return 0;
}
