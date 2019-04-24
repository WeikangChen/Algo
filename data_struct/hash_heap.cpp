#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct quote {
    using key_t = string;
    key_t exch;
    int32_t qty;
    double prc;
    quote(string ex, const double p) : exch{std::move(ex)}, prc{p} {}
    friend ostream& operator<<(ostream& os, const quote& q) {
        return os << q.prc << "[" << q.exch << "]";
    }
};

struct bid : public quote {
    bid(string ex, const double p) : quote{std::move(ex), p} {}
    // bool operator<(const bid& rhs) const { return this->prc < rhs.prc; }
    friend bool operator<(const bid& lhs, const bid& rhs) {
        return lhs.prc < rhs.prc;
    }
    static const char* tinfo() { return "bid"; }
};

struct ask : public quote {
    ask(string ex, const double p) : quote{std::move(ex), p} {}
    // bool operator<(const ask& rhs) const { return this->prc > rhs.prc; }
    friend bool operator<(const ask& lhs, const ask& rhs) {
        return lhs.prc > rhs.prc;
    }
    static const char* tinfo() { return "ask"; }
};

template <typename T>
class hash_heap {
    unordered_map<typename T::key_t, size_t> dict_;
    vector<T> data_;
    size_t l_child(size_t i) { return 2 * i + 1; }
    size_t r_child(size_t i) { return 2 * i + 2; }
    size_t parent(size_t i) { return (i - 1) / 2; }

    void swap(size_t i, size_t j) {
        dict_[data_[i].exch] = j;
        dict_[data_[j].exch] = i;
        std::swap(data_[i], data_[j]);
    }
    void sift_dn(size_t i) {
        const auto N = data_.size();
        const auto l = l_child(i);
        const auto r = r_child(i);
        size_t m = i;
        if (l < N && data_[m] < data_[l])
            m = l;
        if (r < N && data_[m] < data_[r])
            m = r;
        if (m != i) {
            swap(m, i);
            sift_dn(m);
        }
    }
    void sift_up(size_t i) {
        if (!i)
            return;
        const auto p = parent(i);
        if (data_[p] < data_[i]) {
            swap(p, i);
            sift_up(p);
        }
    }

 public:
    hash_heap() = default;
    hash_heap(const hash_heap&) = delete;
    hash_heap(hash_heap&&) = delete;
    void operator=(const hash_heap&) = delete;
    void operator=(hash_heap&&) = delete;
    ~hash_heap() = default;

    void update_or_push(const T& one) {
        auto it = dict_.find(one.exch);
        if (it != dict_.end()) {  // update
            const auto idx = it->second;
            const auto pre = data_[idx];
            data_[idx] = one;
            if (one < pre)
                sift_dn(idx);
            else
                sift_up(idx);
        } else {  // push
            auto p = data_.size();
            dict_[one.exch] = p;
            data_.emplace_back(one);
            sift_up(data_.size() - 1);
        }
    }

    void pop() {
        swap(0, data_.size() - 1);
        dict_.erase(data_.back().exch);
        data_.pop_back();
        sift_dn(0);
    }

    T& top() { return data_[0]; }

    void make_heap() { std::make_heap(data_.begin(), data_.end()); }

    std::string repr() const {
        std::ostringstream oss;
        oss << std::fixed;
        oss << std::setprecision(2);
        oss << "-------- Hash_Heap ("
            << "type=" << T::tinfo()
            << " size=" << data_.size()
            << ") ---------\n";
        if (!data_.empty()) {
            auto it = data_.begin();
            oss << "\t" << *it++ << "\n";
            while (it != data_.end())
                oss << "\t" << *it++ << "\n";
        } else {
            oss << "\t empty \n";
        }
        return oss.str();
    }
};

void test_quote() {
    priority_queue<bid> pq_bid;
    priority_queue<ask> pq_ask;

    pq_bid.emplace("CBOE", 1.1);
    pq_bid.emplace("NSDQ", 1.2);
    pq_bid.emplace("BATS", 1.3);
    pq_bid.emplace("CBOE", 1.4);
    pq_ask.emplace("NSDQ", 1.5);
    pq_ask.emplace("CBOE", 1.6);
    pq_ask.emplace("BATS", 1.7);
    pq_ask.emplace("NSDQ", 1.8);

    while (!pq_bid.empty()) {
        cout << "bid=" << pq_bid.top() << " ";
        pq_bid.pop();
    }
    cout << endl;
    while (!pq_ask.empty()) {
        cout << "ask=" << pq_ask.top() << " ";
        pq_ask.pop();
    }
    cout << endl;
}

template <typename QT>
void test_hash_heap() {
    hash_heap<QT> hh_quote;
    hh_quote.update_or_push(QT("CBOE", 0.9));
    hh_quote.update_or_push(QT("NSDQ", 1.3));
    hh_quote.update_or_push(QT("AMEX", 1.8));
    hh_quote.update_or_push(QT("BATS", 2.1));
    hh_quote.update_or_push(QT("ARCA", 3.2));
    hh_quote.update_or_push(QT("XCME", 2.6));
    cout << hh_quote.repr() << endl;
    hh_quote.pop();
    hh_quote.update_or_push(QT("AMEX", 0.7));
    hh_quote.update_or_push(QT("ARCA", 3.0));
    hh_quote.update_or_push(QT("CBOE", 2.2));
    hh_quote.update_or_push(QT("XCME", 1.4));
    hh_quote.update_or_push(QT("CBOE", 2.3));
    hh_quote.update_or_push(QT("ITTO", 2.7));
    cout << hh_quote.repr() << endl;
}

int main(int argc, char** argv) {
    cout << "Testing bid hash heap" << endl;
    test_hash_heap<bid>();

    cout << "Testing ask hash heap" << endl;
    test_hash_heap<ask>();
}
