#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class queue {
    static constexpr const char* full_error = "ERROR: queue is full";
    static constexpr const char* empty_error = "ERROR: queue is empty";
    T* data = nullptr;
    size_t capacity;
    size_t head = 0;
    size_t tail = 0;
    size_t size = 0;
public:
    queue(size_t cap) : capacity{cap} {
        data = new T[capacity];
    }
    queue(const queue& rhs) = delete;
    queue(queue&& rhs) = delete;
    void operator=(const queue& rhs) = delete;
    void operator=(queue&& rhs) = delete;
    ~queue() { delete[] data; }

    bool empty() const {
        return size == 0;
    }

    bool full() const {
        return size == capacity;
    }

    void push(const T& val) {
        if (size == capacity) 
            throw full_error;
        data[tail++] = val;
        tail %= capacity;
        ++size;
    }

    void pop() {
        if (empty())
            throw empty_error;
        ++head;
        head %= capacity;
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
        i = (i + 1) % capacity;
        while (i != tail) {
            oss << "," << data[i];
            i = (i + 1) % capacity;
        }
        oss << " size=" << size;
        oss << " head=" << head;
        oss << " tail=" << tail;
        return oss.str();
    }
};

int main(int argc, char** argv) {
    queue<double> q(5);
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
