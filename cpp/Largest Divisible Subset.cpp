class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        
        vector<int> div(n,1);
        vector<int> prev(n,-1);
        int l=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&div[j]+1>div[i]){
                    prev[i]=j;
                    div[i]=div[j]+1;
                }
            }
            if(div[l]<div[i])
                l=i;
        }
        
        vector<int> ans;
        
        while(l>=0){
            ans.push_back(nums[l]);
            l=prev[l];
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};