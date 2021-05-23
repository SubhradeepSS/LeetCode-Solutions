class Solution {
public:
    unordered_map<string,multiset<string>> mp;
    vector<string> ans;
    
    void dfs(string curr){
        while(!mp[curr].empty()){
            auto it=mp[curr].begin();
            string dest=*it;
            mp[curr].erase(it);
            dfs(dest);
        }    
        ans.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        ans.clear();
        for(auto t:tickets)
            mp[t[0]].insert(t[1]);
        
        dfs("JFK");
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};