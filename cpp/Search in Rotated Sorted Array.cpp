class Solution {
public:
    int f(vector<int> nums,int l,int h,int k){
        if(l>h)
            return -1;
        int m=(l+h)/2;
        if(nums[m]==k)
            return m;
        if(nums[l]<=nums[m]){
            if(k>=nums[l]&&k<nums[m])
                return f(nums,l,m-1,k);
            return f(nums,m+1,h,k);
        }
        if(k>=nums[m]&&k<=nums[h])
            return f(nums,m+1,h,k);
        return f(nums,l,m-1,k);
    }
    int search(vector<int>& nums, int target) {
        return f(nums,0,nums.size()-1,target);
    }
};