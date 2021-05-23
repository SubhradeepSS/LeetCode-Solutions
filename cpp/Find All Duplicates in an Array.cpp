class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> c(n,0);
        for(int i:nums)
            c[i-1]++;
        for(int i=0;i<n;i++){
            if(c[i]>1)
                ans.push_back(i+1);
        }
        return ans;
    }
};