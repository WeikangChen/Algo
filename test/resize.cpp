#include <iostream>
#include <vector>

using namespace std;

class A {
  static uint32_t cp_ctor;
  static uint32_t df_ctor;
public:
  A() {
    cout << "df_ctor=" << ++df_ctor << endl;
  }
  A(const A& a) {
    cout << "cp_ctor = " << ++cp_ctor <<  endl;
  }
};

// 1 + (1+1) + (2+1) + 1 + (4+1) + 1 +1 +1 + (8+1) + 1 
// = 1 + 2 + 4 + 4 + 4 +8 + 2
// = 10 + 1 + 2 + 4 + 8
uint32_t A::cp_ctor = 0;
uint32_t A::df_ctor = 0;

// To execute C++, please define "int main()"
int main() {
    vector<A> va(5000);
  
  for (int i = 0; i < -10; ++i)
  {
    cout << "i = " << i << endl;
    auto a = A();
    va.push_back(a);
  }
  
  return 0;
}
