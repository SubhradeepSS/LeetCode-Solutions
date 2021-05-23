class Solution {
public:
    int util(vector<int>& nums,int l,int h){
        int incl=nums[l],excl=0;
        for(int i=l+1;i<=h;i++){
            int old=excl;
            excl=max(incl,excl);
            incl=max(old+nums[i],incl);
        }
        return max(excl,incl);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        return max(util(nums,0,n-2),util(nums,1,n-1));
    }
};