#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <type_traits>

using namespace std;

vector<string> names;

template<typename Clock, typename Duration>
std::ostream& operator<<(std::ostream& stream,
  const std::chrono::time_point<Clock, Duration> &time_point)
{
  const time_t time = Clock::to_time_t(time_point);
#if __GNUC__ > 4 || \
    ((__GNUC__ == 4) && __GNUC_MINOR__ > 8 && __GNUC_REVISION__ > 1)
  // Maybe the put_time will be implemented later?
  struct tm tm;
  localtime_r(&time, &tm);
  return stream << std::put_time(&tm, "%c"); // Print standard date&time
#else
  char buffer[26];
  ctime_r(&time, buffer);
  buffer[24] = '\0';  // Removes the newline that is added
  return stream << buffer;
#endif
}

string nameFromIdx(int idx)
{
    string ret = "idx_name_";
    return ret +  to_string(idx);
}

template<typename T>
void logAndAddImpl(T&& name, std::false_type)
{
    auto now = std::chrono::system_clock::now();
    cout << now << ": logAndAdd_string: " << name << endl;
    names.emplace_back(std::forward<T>(name));
}

void logAndAddImpl(int idx, std::true_type)
{
    auto now = std::chrono::system_clock::now();
    cout << now << ": logAndAdd_int_idx: " << idx << endl;
    names.emplace_back(nameFromIdx(idx));
}

template<typename T>
void logAndAdd(T&& t)
{
    logAndAddImpl(
        std::forward<T>(t),
        std::is_integral<remove_reference_t<T>>()
        );
}

template<typename T>
void gn(T&& t)
{
    cout << "gn: template"
         << (is_const<T>::value ? " const" : "")
         << (is_lvalue_reference<T>::value ? " lvalue ref " :
             (is_rvalue_reference<T>::value ? " rvalue ref " : " non-ref "))
         << typeid(T).name()<< " value=" << t << endl;
}

template<typename T>
void fn(T&& t)
{
    cout << "fn: template"
         << (is_const<T>::value ? " const" : "")
         << (is_lvalue_reference<T>::value ? " lvalue ref " :
             (is_rvalue_reference<T>::value ? " rvalue ref " : " non-ref "))
         << typeid(T).name() << " value=" << t << endl;
    gn(forward<T>(t));
}


int main(int argc, char ** argv)
{
    string name = "John";
    logAndAdd(name);
    logAndAdd(string("Alice"));
    logAndAdd("Peter");
    logAndAdd(1);
    logAndAdd(2u);
    int i = 3;
    logAndAdd(i);
    cout << std::is_integral<int>::value << endl;
    for(const auto& name: names) {
        cout << "name:" << name << endl;
    }
    
    const int c = 2;
    int k = 3;
    fn(1);
    fn(k);
    fn(c);
    
    return 0;
}
