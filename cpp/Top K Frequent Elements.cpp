bool f(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        
        vector<int> ans;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
        
        while(k--){
            auto p=pq.top();
            pq.pop();
            
            ans.push_back(p.second);
        }
        
        return ans;
    }
};