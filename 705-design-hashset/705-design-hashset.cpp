class MyHashSet {
    
     vector<int> v ;
    
public:
    MyHashSet() {
       
    }
    
    void add(int key) {
        
        bool flag = false ;
        for(int i=0 ;i<v.size();i++){
            if(v[i]==key)
                flag = true;
        }
        
        if(!flag)
            v.push_back(key);
    }
    
    void remove(int key) {
        v.erase(std::remove(v.begin(), v.end(), key), v.end());
    }
    
    bool contains(int key) {
         for(int i=0 ;i<v.size();i++){
            if(v[i]==key)
                return true ; 
        }
        return false ;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */