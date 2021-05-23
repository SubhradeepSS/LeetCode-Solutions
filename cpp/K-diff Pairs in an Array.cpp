class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i:nums){
            if(k==0&&mp[i]==1)
                ans++;
            else if(mp[i]==0)
                {   
                    if(mp[i-k]>0)
                        ans++;
                    if(mp[i+k]>0)
                        ans++;
                    // cout<<i<<" ";
                }
            mp[i]++;
        }
        return ans;
    }
};