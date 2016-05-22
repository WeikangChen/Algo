#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> m_arr;
    int N;
public:
    Heap(vector<int> arr) {
	N = arr.size();
	m_arr.clear();
	m_arr = arr;
	for(int i = N/2; i >= 0; --i)
	    heapify(i, N);
    }

    void heapify(int i, int n)
    {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int p = i;
	if(l < n && m_arr[l] > m_arr[p]) p = l;
	if(r < n && m_arr[r] > m_arr[p]) p = r;
	if(p != i) {
	    swap(m_arr[p], m_arr[i]);
	    heapify(p, n);
	}
    }

    int push(int val)
    {
	N++;
	m_arr.insert(m_arr.begin(), val);
	heapify(0, N);
    }

    void sort()
    {
	for(int i = N-1; i > 0; --i)
	{
	    swap(m_arr[0], m_arr[i]);
	    heapify(0, i-1);
	}
    }

    int top() {return m_arr[0];}
    int pop() {
	swap(m_arr[0], m_arr[m_arr.size()-1]);
	heapify(0, --N);
	m_arr.erase(m_arr.end());
    }
    
    void print()
    {
	for(int i = 0; i < N; ++i)
	    cout << m_arr[i] << " ";
	cout << endl;
    }
};


int main(int argc, char *argv[])
{
    int a[] = {4, 7, 1, 9, 3, 5, 8, 6, 2};
    vector<int> arr(a, a+sizeof(a)/sizeof(int));

    Heap h(arr);
    h.print();
    h.sort();
    h.print();
    h.push(10);
    h.push(11);
    h.push(12);
    h.print();
    h.sort();
    h.print();
    h.pop();
    h.print();
    return 0;
}
