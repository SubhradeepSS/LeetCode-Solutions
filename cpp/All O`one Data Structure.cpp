class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mp;
    // unordered_map<int,string> mp2;
    // int min,max;
    AllOne() {
        mp.clear();
        // mp2.clear();
        // min=INT_MAX;
        // max=INT_MIN;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // mp2.erase(mp[key]);
        mp[key]++;
        // mp2[mp[key]]=key;
        // min=(mp[key]<min?mp[key]:min);
        // max=(mp[key]>max?:mp[key]:max);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp.find(key)==mp.end())
            return;
        if(mp[key]==1){
            // mp2.erase()
            mp.erase(key);
        }
        else if(mp[key]>1){
            mp[key]--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        // return mp2[max];
        int max=INT_MIN;
        string s="";
        
        for(auto i:mp){
            if(max<=i.second){
                max=i.second;
                s=i.first;
            }
        }
        return s;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        // return mp2[min];
        int min=INT_MAX;
        string s="";
        
        for(auto i:mp){
            if(min>=i.second){
                min=i.second;
                s=i.first;
            }
        }
        return s;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */