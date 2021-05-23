class RecentCounter {
public:
    vector<int> calls;
    RecentCounter() {
        calls.clear();
    }
    
    int ping(int t) {
        calls.push_back(t);
        int l=lower_bound(calls.begin(),calls.end(),t-3000)-calls.begin();
        return calls.size()-l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */