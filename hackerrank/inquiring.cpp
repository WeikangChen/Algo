#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct order {
    int id;
    int price;
    int time;
    order(int p, int t): price(p), time(t) {}

    friend bool operator> (const order &a, const order &b) {
        return a.price > b.price;
    }

    friend bool operator< (const order &a, const order &b) {
        return a.price < b.price;
    }
};

struct listHeap {
private:
    list<order> m_list;
    vector<list<order>::iterator> m_heap;

    void heapify_up(int i) {
        if(i == 0) return;
        int p = (i-1) / 2;
        if(*m_heap[i] > *m_heap[p]) {
            swap(m_heap[i], m_heap[p]);
            m_heap[i]->id = i;
            m_heap[p]->id = p;
            heapify_up(p);
        }
    }

    void heapify_down(int i) {
        const int n = m_heap.size();
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int p = i;
        if (l < n && *m_heap[p] < *m_heap[l]) p = l;
        if (r < n && *m_heap[p] < *m_heap[r]) p = r;
        if(p != i) {
            swap(m_heap[i], m_heap[p]);
            m_heap[i]->id = i;
            m_heap[p]->id = p;
            heapify_down(p);
        }
    }

public:
    void insert(order one) {
        one.id = m_heap.size();
        m_list.push_front(one);
        m_heap.push_back(m_list.begin());
        heapify_up(m_heap.size()-1);
    }

    int inquiry(int time) {
        while (m_list.size() && m_list.back().time < time - 59) 
        {
            int i = m_list.back().id;
            if(i != m_heap.size() - 1) {
                swap(m_heap[i], m_heap[m_heap.size() - 1]);
                m_heap[i]->id = i;
            }
            m_heap.pop_back();
            heapify_down(i);
            m_list.pop_back();
        }

        if (m_heap.size())
            return m_heap[0]->price;
        return -1;
    }
};


int main(int argc, char *argv[])
{
    int N;
    cin >> N;
    listHeap lh;

    for (int i = 0; i < N; ++i) {
        int type, price, time;
        cin >> type;
        if (type == 1) {
            cin >> price >> time;
            lh.insert(order(price, time));
        } else {
            cin >> time;
            cout << lh.inquiry(time) << endl;
        }
    }
    return 0;
}
