class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n=nums.size();
        if(!n || target<nums[0] || target>nums[n-1]){
            ans={-1,-1};
            return ans;
        }
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        ans[0] = (l>=0 && l<n && nums[l]==target)?l:-1;
        ans[1] = (r>=0 && r<=n && nums[r-1]==target)?r-1:-1;
        
        return ans;
    }
};