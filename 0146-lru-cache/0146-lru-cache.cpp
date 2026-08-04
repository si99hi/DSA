class LRUCache {
public:
    unordered_map<int, int>map;
    unordered_map<int , list<int>::iterator>pos;
    list<int>lru;
    int cap;

    
    LRUCache(int capacity) {
        cap= capacity;
        
    }
    
    int get(int key) {

        //if you dont get key at end
        if(map.find(key)==map.end()){
            return -1;
        }
        lru.erase(pos[key]);
        lru.push_front(key);
        pos[key]=lru.begin();

        return map[key];
        
    }
    
    void put(int key, int value) {

        if(map.find(key)!=map.end()){
            lru.erase(pos[key]);

        } 
        else if(map.size()== cap){
            int oldKey= lru.back();
            lru.pop_back();
            map.erase(oldKey);
            pos.erase(oldKey);

        }

        lru.push_front(key);
        pos[key]= lru.begin();
        map[key]=value;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */