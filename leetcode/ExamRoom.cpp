#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

struct Seg
{
    int a;
    int b;
    int d;
    int p;

    Seg(int x, int y): a{x}, b{y} {
        if (a == -1) {
            d = abs(b);
            p = 0;
        } else if (b < 0) {
            d = -b - a - 1;
            p = -b - 1;
        } else {
            d = (b - a) / 2;
            p = a + d;
        }
    }
    bool operator<(const Seg& rhs) {
        return d == rhs.d ? p > rhs.p : d < rhs.d;
    }

    string to_string() {
        stringstream ss;
        ss << "(" << a << ", " << b  << ")[" << d << "]";
        return ss.str();
    }
};

class HashHeap
{
    vector<Seg> vs_;

    Seg top() { return vs_[0]; }
    void pop() { remove(0); }
    string to_string() {
        stringstream ss;
        for (auto s: vs_) {
            ss << s.to_string() << " ";
        }
        return ss.str();
    }

    int find_l_id(int p)
    {
        for (size_t i = 0; i < vs_.size(); ++i)
            if (vs_[i].b == p) return i;
        return -1;
    }

    int find_r_id(int p)
    {
        for (size_t i = 0; i < vs_.size(); ++i)
            if (vs_[i].a == p) return i;
        return -1;
    }
    
    Seg remove(size_t i) {
        auto ret = vs_[i];
        const auto n1 = vs_.size() - 1;
        if (i != n1) {
            swap(vs_[i], vs_[n1]);
            vs_.pop_back();
            heapify_dn(i);
        } else {
            vs_.pop_back();
        }
        return ret;
    }

    size_t heapify_up(size_t i) {
        if (i == 0) return i;
        auto p = (i - 1) / 2;
        auto res = i;
        if (vs_[p] < vs_[i]) {
            swap(vs_[p], vs_[i]);
            res = heapify_up(p);
        }
        return res;
    }
    
    size_t heapify_dn(size_t p) {
        const auto n = vs_.size();
        auto l = 2 * p + 1;
        auto r = 2 * p + 2;
        auto m = p;

        if (l < n && vs_[m] < vs_[l]) m = l;
        if (r < n && vs_[m] < vs_[r]) m = r;

        auto res = p;
        if (m != p) {
            swap(vs_[m], vs_[p]);
            res = heapify_dn(m);
        }
        return res;
    }
    
public:
    size_t add(Seg s) {
        auto pos = vs_.size();
        vs_.push_back(s);
        return heapify_up(pos);
    }
    
    int split_top() {
        auto t = top(); pop();
        if (t.a != t.p)
            add(Seg(t.a, t.p));
        if (t.p != t.b)
            add(Seg(t.p, t.b));
        cout << "+ " << t.p << " --> " << to_string() << endl;
        return t.p;
    }
    
    void remove_merge(int p) {
        auto l_id = find_l_id(p);
        auto l_seg = remove(l_id);
        auto r_id = find_r_id(p);
        auto r_seg = remove(r_id);
        add(Seg(l_seg.a, r_seg.b));
        cout << "- " << p << " --> " << to_string() << endl;
    }
};

class ExamRoom {
    HashHeap H;
public:
    ExamRoom(int N) {
        H.add(Seg(-1, -N));
    }
    
    int seat() {
        return H.split_top();
    }
    
    void leave(int p) {
        H.remove_merge(p);
    }
};


int main(int argc, char ** argv)
{
    ExamRoom H(10);
//    string ops = "sss40sssssssss04ss7s3s3s9s08ss08ss2";
//    string ops = "ssss4s";
    string ops = "sss04sssssssss04ss7s3s3s9s08ss08ss2";

    for (auto c: ops) {
        if (c == 's') {
            int p = H.seat();
            // cout << p << endl;
        } else {
            H.leave(c-'0');
        }
    }
    return 0;
}
