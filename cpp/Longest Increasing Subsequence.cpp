class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int len=1;
        vector<int> v(nums.size(),0);
        v[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            auto it=lower_bound(v.begin(),v.begin()+len,x);
            if(it==v.begin()+len)
                v[len++]=x;
            else
                *it=x;
        }
        return len;
    }
};