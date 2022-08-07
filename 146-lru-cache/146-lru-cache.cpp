class LRUCache {
public:
    
    // map to store the address if node so we don't need to traverse the whole node
       unordered_map<int , list<int> :: iterator > address ; 
    
       unordered_map<int,int> mp ;
    list<int> l ;
    int size ; // size of cache
    int cap ; 
    
    LRUCache(int capacity) {
        
        cap = capacity ;
        size = 0 ;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end())
            return -1 ; 
        

        list<int> :: iterator it = address[key] ; 
        
        // delete the key from back and add it to front to maintain lru
        l.erase(it);
        // remove the key from address book
        address.erase(key) ;
        
        l.push_front(key);
        
        // add new address in address book
        address[key] = l.begin() ; 
        
        return mp[key] ; 
    }
    
    void put(int key, int value) {
        
        // if key is already present just update its value
        if(mp.find(key) != mp.end()){
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            size--;
        }
        
        // If lru capacity is full : delete the node from last
        if(size == cap){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            mp.erase(k);
            size--;
        }
        
        size++;
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */