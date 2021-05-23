class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i:nums){
            a[i]++;
        }
        for(int i=0;i<=nums.size();i++){
            if(!a[i])
                return i;
        }
        return -1;
    }
};