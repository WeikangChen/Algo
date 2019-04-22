#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

template <typename T, size_t CAP>
class queue {
    static constexpr const char* full_error = "ERROR: queue is full";
    static constexpr const char* empty_error = "ERROR: queue is empty";
    unique_ptr<T[]> data;
    size_t head = 0;
    size_t tail = 0;
    size_t size = 0;

 public:
    queue() : data{make_unique<T[]>(CAP)} {}
    queue(const queue& rhs) = delete;
    queue(queue&& rhs) = delete;
    void operator=(const queue& rhs) = delete;
    void operator=(queue&& rhs) = delete;
    ~queue() = default;

    bool empty() const { return size == 0; }

    bool full() const { return size == CAP; }

    void push(const T& val) {
        if (full())
            throw full_error;
        data[tail++] = val;
        tail %= CAP;
        ++size;
    }

    void pop() {
        if (empty())
            throw empty_error;
        ++head;
        head %= CAP;
        --size;
    }

    T& front() const {
        if (empty())
            throw empty_error;
        return data[head];
    }

    std::string repr() const {
        if (empty())
            return {};
        ostringstream oss;
        auto i = head;
        oss << data[i];
        i = (i + 1) % CAP;
        while (i != tail) {
            oss << "," << data[i];
            i = (i + 1) % CAP;
        }
        oss << " size=" << size;
        oss << " head=" << head;
        oss << " tail=" << tail;
        return oss.str();
    }
};

int main(int argc, char** argv) {
    queue<double, 5> q;
    try {
        q.pop();
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    for (int i = 1; i < 10; ++i) {
        try {
            while (q.full())
                q.pop();
            q.push(1.1 * i);
            cout << "i=" << i << ": q.repr=" << q.repr() << endl;
        } catch (const char* msg) {
            cerr << msg << endl;
        }
    }

    try {
        q.push(12.34);
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << "final: q.repr=" << q.repr() << endl;
    return 0;
}
