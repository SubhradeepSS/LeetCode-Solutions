class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int incl=nums[0],excl=0;
        for(int i=1;i<nums.size();i++){
            int old_excl=excl;
            excl=max(incl,old_excl);
            incl=max(incl,old_excl+nums[i]);
        }
        return max(excl,incl);
    }
};