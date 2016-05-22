#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> generate(int m, int n)
{
    vector<int> res;
    int select = m;
    int remain = n;
    for(int i = 1; i <= n; ++i)
    {
	if(rand() % remain < select)
	{
	    res.push_back(i);
	    select--;
	}
	remain--;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int m = 10; 
    int n = 20;
    
    vector<int> res;
    vector<int> stat(n+1, 0);

    for(int t = 0; t < 500000; t++)
    {
	res = generate(m, n);
	for(int i = 0; i < res.size(); ++i)
	    stat[res[i]]++;
    }

    for (int i = 0; i <= n; i++) {
	cout << stat[i] << " " ;	
    }
    cout << endl;

    return 0;
}
