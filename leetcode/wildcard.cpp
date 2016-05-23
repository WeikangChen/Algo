#include <iostream>
#include <vector>

using namespace std;

bool isMatch(char* s, char* p) {
    
    char *star = NULL;
    char *ss = s; 
    
    while(*s) {
        cout << *s << ", " <<  *p << " -- " << *ss << endl;
        if(*p == *s || *p == '?') {p++; s++;}
        else if(*p == '*') {star = p++; ss = s;}
        else if(star) {s = ++ss; p = star + 1;}
        else return false;
    }
    while(*p == '*') p++;
    return !*p;
}

int main(int argc, char ** argv)
{
    cout << isMatch("aabc", "a*ab") << endl;
    return 0;
}
