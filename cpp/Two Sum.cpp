class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(target-nums[i])!=s.end()){
                v.push_back(i);
                v.push_back(find(nums.begin(),nums.end(),target-nums[i])-nums.begin());
                break;
            }
            s.insert(nums[i]);
        }
        return v;
    }
};