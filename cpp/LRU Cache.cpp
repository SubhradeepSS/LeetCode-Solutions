class LRUCache {
public:
    int size;
    list<int> q;
    unordered_map<int,int> mp;
    LRUCache(int capacity) {
        size=capacity;
        q.clear();
        mp.clear();
    }
    
    int get(int key) {
        if(find(q.begin(),q.end(),key)==q.end())
            return -1;
        q.erase(find(q.begin(),q.end(),key));
        q.push_back(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        // storing key, value pair
        if(q.size()<size){
            auto it=find(q.begin(),q.end(),key);
            if(it==q.end()){
                q.push_back(key);
            }
            else{
                q.erase(it);
                q.push_back(key);
            }
        }
        else{
            auto it=find(q.begin(),q.end(),key);
            if(it==q.end()){
                q.pop_front();
                q.push_back(key);
            }
            else{
                q.erase(it);
                q.push_back(key);
            }
        }
        mp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */