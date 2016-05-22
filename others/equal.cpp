#include <vector>
#include <iostream>
using namespace std;


int main(int ac, char ** argv)
{
	int array[] =  {1, 2, 1, 2, 2, 1, 2, 2, 2, 1};

	int t = 1;

	int n = 10;
	vector<int> eqs(n, 0);
	vector<int> neq(n, 0);

	int cur1 = 0, cur2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(t == array[i]) cur1++;
		eqs[i] = cur1;
		int j = n - 1 - i;
		if(t != array[j]) cur2++;
		neq[j] = cur2;
	} 

	for(int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
		cout << eqs[i] << " ";
	cout << endl;

	int res = -1;
	for(int i = 0; i < n; i++)
	{
		if(eqs[i] == neq[i]) res  = i;
		cout << neq[i] << " ";
	}
	cout << endl;
	cout << "res = " << res << endl;
	
	int l = 0, r = n - 1;
	int cl = 0, cr = 0;
	while(l < r - 1)
	{
		if(cl < cr) {
			if(t == array[l]) cl++;
			l++;
		}
		else {
			if(t != array[r]) cr++;
			r--;
		}
	}
	if(cl == cr) 
		res = l;
	else 
		res = -1;

	cout << "res = " << res << endl;

	return 0;
}
