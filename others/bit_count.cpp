#include <iostream>
#include <vector>

using namespace std;

int BitCount1(unsigned int n)
{
    unsigned int c =0 ; // 计数器
    for (c =0; n; n >>=1) // 循环移位
        c += n &1 ; // 如果当前位是1，则计数器加1
    return c ;
}


int BitCount2(unsigned int n)
{
    unsigned int c =0 ;
    for (c =0; n; ++c)
    {
        n &= (n -1) ; // 清除最低位的1
    }
    return c ;
}

int BitCount3(unsigned int n) 
{ 
    // 建表
    unsigned char BitsSetTable256[256] = {0} ; 

    // 初始化表 
    for (int i =0; i <256; i++) 
    { 
        BitsSetTable256[i] = (i &1) + BitsSetTable256[i /2]; 
    } 

    unsigned int c =0 ; 

    // 查表
    unsigned char* p = (unsigned char*) &n ; 

    c = BitsSetTable256[p[0]] + 
        BitsSetTable256[p[1]] + 
        BitsSetTable256[p[2]] + 
        BitsSetTable256[p[3]]; 

    return c ; 
}

int main(int argc, char *argv[])
{

    for(int i = 1; i < 10; ++i) {
	cout << i << "'s bits # =" << BitCount1(i) << endl;
	cout << i << "'s bits # =" << BitCount2(i) << endl;
	cout << i << "'s bits # =" << BitCount3(i) << endl;
	cout << endl;
    }
    return 0;
}
