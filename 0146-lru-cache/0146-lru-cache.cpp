class LRUCache {
public:
    unordered_map<int, int> mp; 
    unordered_map<int, list<int>::iterator> pos; 
    list<int> lru; 
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        lru.erase(pos[key]);      
        lru.push_front(key);      
        pos[key] = lru.begin();

        return mp[key];
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            lru.erase(pos[key]);
        }
        else if (mp.size() == cap) {
            int oldKey = lru.back();
            lru.pop_back();
            mp.erase(oldKey);
            pos.erase(oldKey);
        }

        lru.push_front(key);
        pos[key] = lru.begin();
        mp[key] = value;
    }
};