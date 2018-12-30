#include <iostream>
#include <vector>
#include <unordered_map>
/*
Reference:
  http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
  http://thbecker.net/articles/rvalue_references/section_01.html
  http://www.cplusplus.com/articles/y8hv0pDG/
  http://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php
*/
using namespace std;

template<typename T>
class ArrayWrapper
{
    T *p_vals_;
    size_t size_;
public:
    ArrayWrapper() // default constructor
        : p_vals_(nullptr),
          size_(0)
    {
        cout << "calling default constructor(0)" << endl;
    }
    
    ArrayWrapper(size_t n)  // defautl constructor with one arg  
        : p_vals_(new int[n]),
          size_(n)
    {
        cout << "calling default constructor(" << n << ")"<< endl;
        for (size_t i = 0; i < size_; ++i) {
            p_vals_[i] = i;
        }
    }

    ArrayWrapper(const ArrayWrapper & other) // copy constructor
        : p_vals_(new int[other.size_]),
          size_(other.size_)
    {
        cout << "calling copy constructor" << endl;
        for (size_t i = 0; i < size_; ++i) {
            p_vals_[i] = other.p_vals_[i];
        }
    }

    ArrayWrapper(ArrayWrapper && other) // move constructor
        : p_vals_(other.p_vals_),
          size_(other.size_)
    {
        cout << "calling move constructor" << endl;
        other.p_vals_ = nullptr;
    }

    ArrayWrapper& operator=(const ArrayWrapper& rhs)
    {
        cout << "calling regular assignment " << endl;
        if(&rhs == this)
            return *this;
        delete[] p_vals_;
        p_vals_ =  new T[rhs.size_];
        size_ = rhs.size_;
        for (size_t i = 0; i < size_; ++i) {
            p_vals_[i] = rhs.p_vals_[i];
        }
        return *this;
    }

    void print() const
    {
        if (!size_) return;
        cout << "  print: " << p_vals_[0];
        for (size_t i = 1; i < size_; ++i) {
            cout << ", " << p_vals_[i];
        }
        cout << endl;
    }

    T& operator[] (const size_t id) {return p_vals_[id];}
    const T& operator[] (const size_t id) const {return p_vals_[id];} 
    size_t size() const {return size_;}
};


typedef int32_t FUNC(int32_t);
typedef ArrayWrapper<int32_t> IntArr;

IntArr transfer(FUNC f, const IntArr& aw)
{
    size_t sz = aw.size();
    IntArr ret(sz);
    for (size_t i = 0; i < sz; ++i) {
        ret[i] = f(aw[i]);
    }
    return ret;
}

int32_t mydouble(int32_t x) {return 2 * x;}

IntArr copyValues (const IntArr& v)
{
    cout << "copyValues()" << endl;
    IntArr new_values(v);
    return new_values;
}

string getName ()
{
    return "Alex";
}
void printReference (const string& str)
{
    cout << "lvalue const string " << str << endl;
}
/*
void printReference (string&& str)
{
    cout << "rvalue reference string "<< str << endl;
}
*/

void f(const int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }

int getValue()
{
    int ii = 10;
    return ii;
}


IntArr getArray(int n)
{
    IntArr array(n);
    return array;
}


vector<IntArr> getVecArray() {
    vector<IntArr> via;
    via.reserve(5);
    via.push_back(IntArr(1));
    via.push_back(IntArr(2));
    via.push_back(IntArr(3));
    via.push_back(IntArr(4));
    return via;
}

class factory {
    IntArr array;
public:
    factory(int n): array(n) {}
    IntArr getArray()
    {
        return move(array);
    }

};

struct A {};

void show_a(A& a) {cout << "A & " << endl;}
// void show_a(const A& a) {cout << "const A & " << endl;}
 void show_a(A&& a) {cout << "A && " << endl;}


int main(int argc, char ** argv)
{
    A a;
    show_a(a);

    // const A ac;
    // show_a(ac);

    show_a(A());
    
    /*  
    string name = "alex";
    printReference (name);
    printReference (move(name));
    printReference ("abcdefg");
    printReference (getName());

    IntArr aw1(1);
    aw1.print();
    
    IntArr aw2(IntArr(3));
    aw2.print();

    IntArr aw3(move(IntArr(2)));
    aw3.print();


    IntArr aw4 = transfer(
        [](auto x){return 2 * x;},
        aw3);
    aw4.print();


    IntArr aw5;
    aw5 = transfer(mydouble, IntArr(4));
    aw5.print();

    IntArr aw6 (transfer(mydouble, aw5));
    aw6.print();

    IntArr aw7 (move(transfer(mydouble, aw6)));
    aw7.print();

    IntArr aw8;
    aw8 = copyValues(aw6);


    IntArr aws = getArray(3);
    IntArr awp = IntArr(4);
    IntArr awq (getArray(5));

    cout << "--------------" << endl;
    */
    IntArr awx(7);
    IntArr awy(8);
    IntArr awz(9);
    /*
    vector<IntArr> vib;
    vib.reserve(5);
    vib.push_back(awx);
    vib.push_back(move(awy));
    vib.emplace_back(move(awz));
    */
    /*
    unordered_map<int, IntArr> mp;
    mp.reserve(4);
    factory f(20);
    auto a = f.getArray();

    mp.insert(make_pair(1, awx));
    mp.insert(make_pair(2, awy));
    mp.insert(make_pair(3, awz));

    for (auto& it: mp) {
        it.second.print();
    }

    vib.push_back(IntArr(2));
    vib.emplace_back(4);
    cout << "vib:----------" << endl;
    for (const auto& a: vib)
        a.print();
    cout << "vix:-----------" << endl;
    vector<IntArr> vix = move(vib);
    for (const auto& a: vix)
        a.print();
    cout << "vib:-----------" << endl;
    for (const auto& a: vib)
        a.print();

    cout << "--------------" << endl;
    vector<IntArr> via;
    via.reserve(5);
    via.push_back(aw1);
    via.push_back(move(aw2));
    via.emplace_back(move(aw3));
    via.emplace_back(4);

    
    for (const auto &v : via)
        v.print();

    vector<IntArr> vib = move(via);
    for (const auto &v : vib)
        v.print();
    for (const auto &v : via)
        v.print();
    */
    /*
    vector<IntArr> vib;
    for (int i = 1; i < 2; ++i) {
        cout << "NO." << i << endl;
        vib.push_back(aw5);
    }

    int i = 77;
    f(i);    // lvalue ref called
    f(99);         // rvalue ref called
    f(getValue());
    const int& t = getValue();
    cout << t << endl;
    int&& tt = getValue();
    cout << tt << endl;
    */
    return 0;
}
