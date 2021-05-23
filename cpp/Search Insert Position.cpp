class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i= upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i>0&&nums[i-1]==target)
            return i-1;
        return i;
    }
};