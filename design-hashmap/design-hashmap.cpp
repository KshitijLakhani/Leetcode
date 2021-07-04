class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashMap_.insert_or_assign(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        // Is key present ?
        auto iterMap = hashMap_.find(key);
        if(iterMap != hashMap_.end())
        {
            return hashMap_.at(key);
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        // Is key present ?
        auto iterMap = hashMap_.find(key);
        if(iterMap != hashMap_.end())
        {
            hashMap_.erase(key);
        }
        
    }
private:
    std::unordered_map<int, int> hashMap_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */