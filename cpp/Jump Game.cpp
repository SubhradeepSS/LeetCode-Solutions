class Solution {
public:
    bool canJump(vector<int>& nums) {
        int first_good=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=first_good)
                first_good=i;
        }
        return (first_good==0);
    }
};