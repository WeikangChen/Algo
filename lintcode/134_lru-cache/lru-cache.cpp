/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/lru-cache
@Language: C++
@Datetime: 16-07-24 03:17
*/

#include<list>

class LRUCache{
    struct Node {
        int key;
        int val;
        Node(int k, int v): key(k), val(v) {}
    };
    list<Node> m_list;
    int m_capacity;
    unordered_map<int, list<Node>::iterator> m_map;
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) return -1;
        
        auto is = it->second;
        int val = is->val;
        m_list.erase(is);
        m_list.push_front(Node(key, val));
        m_map[key] = m_list.begin();
        return val;
    }

    void set(int key, int value) {
        auto it = m_map.find(key);
        if (it == m_map.end()) {
            if (m_list.size() == m_capacity) {
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
        } else {
            auto is = it->second;
            m_list.erase(is);
        }
        m_list.push_front(Node(key, value));
        m_map[key] = m_list.begin();
    }
};