#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heap {
    vector<long> m_arr;
public:
    Heap() {}
    void push(int num) {
        m_arr.push_back(num);
        heapify_up(m_arr.size()-1);
    }

    void heapify_up(int i)
    {
        if(i == 0) return;
        int p = (i-1) / 2;
        if(m_arr[p] < m_arr[i])
        {
            swap(m_arr[p], m_arr[i]);
            heapify_up(p);
        }
    }

    void pop() {
        if(m_arr.empty()) return;
        swap(m_arr[0], m_arr[m_arr.size()-1]);
        m_arr.pop_back();
        heapify_down(0);
    }

    void heapify_down(int i)
    {
        const int n = m_arr.size();
        int l = 2*i + 1;
        int r = 2*i + 2;
        int p = i;
        if(l < n && m_arr[l] > m_arr[p]) p = l;
        if(r < n && m_arr[r] > m_arr[p]) p = r;
        if(p != i) {
            swap(m_arr[i], m_arr[p]);
            heapify_down(p);
        }
    }

    int top() {return m_arr[0];}
    int size() {return m_arr.size();}

};


class MedianFinder {
    Heap max_heap;
    Heap min_heap;
public:
    void addNum(int num) {
        if(max_heap.size() <= min_heap.size()) {
            min_heap.push(-num);
            max_heap.push(-min_heap.top());
            min_heap.pop();
        }
        else {
            max_heap.push(num);
            min_heap.push(-max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        if(max_heap.size() > min_heap.size())
            return max_heap.top();
        cout << "doube" << max_heap.top() << min_heap.top() << endl;
        return 0.5 * (max_heap.top() - min_heap.top());
    }
};

int main(int argc, char ** argv)
{
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);

    cout << "Median = "<< mf.findMedian() << endl;

    return 0;
}
