#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


string div(int aa, int bb)
{
    int a = 0;a = (aa >= 0 ? aa : -aa);
    int b = 0;b = (bb >= 0 ? bb : -bb);
    if(b==0) return "Inf";

    stringstream ss;
    if ((aa<0&&bb>0) || (aa>0&&bb<0)) ss << "-";
    ss << (a/b);
    
    a = a % b;
    if(!a) return ss.str();

    vector<int> rem(b, 0);
    string frac;

    int d_pos = 1;
    while(a && !rem[a])
    {
	rem[a] = d_pos++;
	a = 10 * a;
	frac.push_back(a/b+'0');
	a = a % b;
    }
    
    if(a) {frac.insert(rem[a]-1, "("); frac += ")";}
    ss << "." << frac;
    return ss.str();
}

int main(int argc, char ** argv)
{
    cout << div(10, 0) << endl;
    cout << div(10, 5) << endl;
    cout << div(1, 3) << endl;
    cout << div(22, 7) << endl;
    cout << div(1, 77) << endl;
    while(true) {
	int a, b;
	cin >> a >> b;
	cout << div (a, b) << endl;
    }
}
