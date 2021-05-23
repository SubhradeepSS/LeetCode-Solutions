class Solution {
public:
    int f(vector<int>& nums,int l,int h,int x){
        if(l>h)
            return -1;
        int m=(l+h)/2;
        if(nums[m]==x)
            return m;
        if(nums[m]>x)
            return f(nums,l,m-1,x);
        return f(nums,m+1,h,x);
    }
    int search(vector<int>& nums, int target) {
        return f(nums,0,nums.size()-1,target);
    }
};