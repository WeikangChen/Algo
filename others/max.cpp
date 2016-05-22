#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_int(int a, int b)
{
    return a + (b-a)*(double)rand()/RAND_MAX;
}

void test();

int main(int ac, char ** argv)
{
    srand(time(NULL));
    for(int i = 0; i <10000; ++i)
    {
	test();
    }
}

void test() {

    const int n = 10;
    int array[n];

    for(int i = 0; i < n; i++) 
    {	
	array[i] = random_int(1, 20);
	//cout << array[i] << " ";
    }
    //cout << endl;

    int pp1, pp2;
    int mm1, mm2;
    pp1 = pp2 = mm1 = mm2 = -1;
    int ppi, mmi;

    for(int i = 0; i < n; i++) 
    {
	int pp = array[i] + i;
	int mm = array[i] - i;

	if(pp > pp2) {
	    if(pp < pp1) 
		pp2 = pp;
	    else {
		pp2 = pp1;
		pp1 = pp;
		ppi = i;
	    }
	}

	if(mm > mm2) {
	    if(mm < mm1) 
		mm2 = mm;
	    else {
		mm2 = mm1;
		mm1 = mm;
		mmi = i;
	    }
	}
    }
	
    int res1;
    if(mmi != ppi) 
	res1 = pp1 + mm1;
    else
	res1 = max(pp1+mm2, pp2+mm1);

    int res2 = 0;
    for(int i = 0; i < n; i++) 
    {
	for(int j = 0; j < i; j++) { 
	    int pp = array[i] + i;
	    int mm = array[j] - j;
	    res2 = max(res2, pp+mm);
	}
    }
    if(res1 != res2) {
	cout << "Method 1 res1 = " << res1 << "\t";
	cout << "Method 2 res2 = " << res2 << endl;
    }


}
