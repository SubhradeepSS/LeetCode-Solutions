class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],min_pdt=nums[0],max_pdt=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(min_pdt,max_pdt);
            min_pdt=min(nums[i],nums[i]*min_pdt);
            max_pdt=max(nums[i],nums[i]*max_pdt);
            ans=max(ans,max_pdt);
        }
        return ans;
    }
};