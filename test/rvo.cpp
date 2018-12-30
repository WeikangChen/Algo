#include <iostream>
#include <vector>

using namespace std;

#define SHOWME { cout << __PRETTY_FUNCTION__ << endl; }

// https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move?lang=en

// g++ -std=c++11 rvo.cpp -fno-elide-constructors
// g++ -std=c++11 rvo.cpp

class Big {
public:
    int val;
    Big(int v=0) : val{v} {
        cout << "Big::cstr(v==" << val << ")" << endl;
    }
    ~Big() {
        cout << "Big::dstr() for val = " << val << endl;
    }
    Big(const Big& b) {
        val = b.val * 2;
        cout << "Big::cp_cstr(v==" << b.val << ") => " << val << endl;
    }
    Big(Big && b) {
        val = b.val * 3;
        cout << "Big::mv_cstr(v==" << b.val << ") => " << val << endl;
    }
    void display() {
        cout << "Big::dispaly() for val = " << val << endl;
    }
};

Big make_big(int x)
{
    SHOWME;
    Big big1(x), big2(10);
    if (x < 10) {
        return move(big1);
    } else {
        return move(big2);
    }
    cout << "END of make_big()" << endl;
}


Big make_big_rvo(int x)
{
    SHOWME;
    Big big(x);
    cout << "return big.val = " << big.val << endl;
    //return move(big); this will return Big&& casuing RVO stop
    return big;
}


// https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
Big x = 99;

void printAddress (const Big& v) // const ref to allow binding to rvalues
{
    cout << reinterpret_cast<const void*>( & v ) << endl;
}

Big getBig ()
{
    // Big x = 10;
    printAddress( x );
    return x;
}
 
Big && getRvalueBig ()
{
    // Big x = 10;
    printAddress( x );
    // notice that it's fine to move a primitive type--remember, std::move is just a cast
    return std::move( x );
}

int main(int argc, char ** argv)
{
    cout << "--------------- test move cstr -----------" << endl;
    Big big_mv = make_big(5);
    big_mv.display();
    
    cout << "--------------- test rvo -----------------" << endl;
    Big big_rvo = make_big_rvo(22);
    big_rvo.display();

    cout << "--------------- test address -------------" << endl;
    printAddress( getBig() ); 
    printAddress( x );

    cout << "--------------- test address -------------" << endl;
    printAddress( getRvalueBig() ); 
    printAddress( x );
    
    cout << "------------------ End -------------------" << endl;
    return 0;
}


