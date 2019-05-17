/*
#include <cstdint>
#include <iostream>

using namespace std;

template <typename T>
class smart_ptr final {
    T* data_ptr_;
    uint32_t* ref_cnt_;

 public:
    smart_ptr(T* ptr) : data_ptr_{ptr}, ref_cnt_{new uint32_t(1)} {
        cout << "created smart_ptr with ref_cnt=" << *ref_cnt_ << endl;
    }
    smart_ptr(const smart_ptr& rhs) {
        if (this == &rhs)
            return;
        data_ptr_ = rhs.data_ptr_;
        ref_cnt_ = rhs.ref_cnt_;
        (*ref_cnt_)++;
        cout << "copy constructor called with ref_cnt=" << *ref_cnt_ << endl;
    }
    smart_ptr(smart_ptr&& rhs) = delete;
    smart_ptr& operator=(const smart_ptr& rhs) = delete;
    smart_ptr& operator=(smart_ptr&& rhs) = delete;
    ~smart_ptr() {
        cout << "desctructor call with ref_cnt=" << *ref_cnt_ << endl;
        if (--(*ref_cnt_) == 0) {
            cout << "deleted data_ptr id=" << data_ptr_->id << endl;
            delete data_ptr_;
            delete ref_cnt_;
        }
    }
    T& operator* () {
        return *data_ptr_;
    }
    T* operator->() {
        return data_ptr_;
    }
};

class A {
    static uint32_t seq;
 public:
    uint32_t id;
    A() {
        id = ++seq;
        cout << "constructing A()" << endl;
    }
    void show() {
        cout << "A->show() id=" << id << endl;
    }
};

uint32_t A::seq = 0;

int main(int argc, char** argv) {
    smart_ptr<A> ptr1 = new A;
    smart_ptr<A> ptr2 = new A;
    auto ptr3 = ptr2;
    ptr3->show();
}
*/

#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother{
  ~Mother(){
    std::cout << "Mother gone" << std::endl;
  }
  void setSon(const std::shared_ptr<Son> s ){
    mySon=s;
  }
  void setDaughter(const std::shared_ptr<Daughter> d ){
    myDaughter=d;
  }
  std::shared_ptr<const Son> mySon;
  std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
  Son(std::shared_ptr<Mother> m):myMother(m){}
  ~Son(){
    std::cout << "Son gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

struct Daughter{
  Daughter(std::shared_ptr<Mother> m):myMother(m){}
  ~Daughter(){
    std::cout << "Daughter gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

int main(){
  std::cout << std::endl;
  {
    std::shared_ptr<Mother> mother= std::shared_ptr<Mother>( new Mother);
    std::shared_ptr<Son> son= std::make_shared<Son>(mother);
    std::shared_ptr<Daughter> daughter= std::make_shared<Daughter>(mother);
    mother->setSon(son);
    mother->setDaughter(daughter);
  }
  std::cout << std::endl;
}
