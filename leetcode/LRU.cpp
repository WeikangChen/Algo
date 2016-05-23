#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key;
        int val;
        Node(int k, int v): key(k), val(v) {}
    };
    list<Node> m_cacheList;
    int m_capacity;
    unordered_map<int, list<Node>::iterator> m_hsMap;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        unordered_map<int, list<Node>::iterator>::iterator it = m_hsMap.find(key);        
        if (it == m_hsMap.end()) return -1;

        list<Node>::iterator is = it->second;
        int val = is->val;
        m_cacheList.push_front(Node(key, val));
        m_cacheList.erase(is);
        m_hsMap[key] = m_cacheList.begin();
        return val;
    }

    void set(int key, int value) {
        unordered_map<int, list<Node>::iterator>::iterator it = m_hsMap.find(key);
        if (it != m_hsMap.end())
            m_cacheList.erase(it->second);
        else if (m_capacity == m_cacheList.size()) {
            m_hsMap.erase(m_cacheList.back().key);
            m_cacheList.pop_back();
        }
        m_cacheList.push_front(Node(key, value));
        m_hsMap[key] = m_cacheList.begin();

    }
};

int main() {

    LRUCache myLRU(1);
    myLRU.set(2, 1);
    cout << myLRU.get(2) << endl;
    myLRU.set(3, 2);
    cout << myLRU.get(2) << endl;
    cout << myLRU.get(3) << endl;

    /*
    for(int i = 1; i < 10; ++i) {
        myLRU.set(i,2*i);
        cout << myLRU.get(i) << endl;
        cout << myLRU.get(1) << endl;
    }
    

    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4

    for (int i=1; i<=3; ++i)
        mylist2.push_back(i*10);   // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                          // points to 2
    
    mylist1.splice (it, mylist2 );
    mylist2.splice (mylist2.begin(), mylist1, it);
    
    std::cout << "mylist1 contains:";
    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "mylist2 contains:";
    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    */
    return 0;
}
