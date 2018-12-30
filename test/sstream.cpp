#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class test {
private:
    vector<int> m_arr;
public:
    test() : m_arr(10, 20){
        vector<int> ::iterator it = m_arr.begin();
        for(; it != m_arr.end(); ++it)
        {
            cout << *it << endl;
        }
    }
};

int main(int argc, char ** argv)
{
    test att;
    float a;
    int b;
    char c;
    stringstream ss;


    ss.str("11.12");
    ss.clear();
    ss >> a;
    cout << a << " <--"<< ss.str() << endl;

    ss.str("12345");
    ss.clear();
    ss >> b;
    
    cout << b << " <--"<< ss.str() << endl;

    ss.str("t");
    ss.clear();
    ss >> c;
    cout << c << "<--"<< ss.str() << endl;

    return 0;
}
