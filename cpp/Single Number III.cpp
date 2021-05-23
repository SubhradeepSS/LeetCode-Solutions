class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i:nums)
            x^=i;
        x=x&~(x-1);
        
        vector<int> ans(2,0);
        
        for(int i:nums){
            if(x&i)
                ans[0]^=i;
            else
                ans[1]^=i;
        }
        return ans;
    }
};