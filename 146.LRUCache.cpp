class LRUCache {
private:
    int cap = capacity;
    list<pair<int, int>> l;
    //unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if (it==m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        // if (it != m.end()) m.erase(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, value));  // push的是pair类型的元素
        m[key] = l.begin();  // 赋值给map的是指向元素的迭代器
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};

// LRUCache object will be instantiated and calld as :
LRUCache* obj = new LRUCache(capacity);
int param_1 = obj->get(key);
obj->put(key, value);
