#include <list>
#include <vector>
#include <map>
#include "container_printer.h"

using namespace std;


struct S {
    int x;
    int y;
    int z;
    char t;
    double value() {return x + y + z;}
};

int main(int argc, char ** argv)
{
    S s{1, 2, 3, 'l'};
    cout << s.x << "," << s.y << "," << s.z << "," << s.t << endl;

    S t{2, 4, 6, 's'};
    cout << t.x << "," << t.y << "," << t.z << "," << t.t << endl;
    
    cout << mult (1, 2.3) << endl;
    
    // string s = "abcdefghijklmnopqrstuvwxyz";
    // cout << s << endl;

    // map<int, string> mp = {{1, "abcde"}};
    // cout << mp << endl;
    // std::list<int> li{1, 2, 3};
    // print_container(cout, li);
    // cout << li << endl;

    // vector<int> vec{1, 2, 3, 4, 5};
    // print_container(cout, vec);
    // cout << vec << endl;

    // map<string, int> msi{{"foo", 42}, {"bar", 81}, {"bazzo", 4}};
    // print_container(cout, msi);
    // cout << msi << endl;
    return 0;
}
