class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> q;
        k=k%nums.size();
        while(k--){
            q.push(nums.back());
            nums.pop_back();
        }
        while(!q.empty()){
            nums.insert(nums.begin(),q.front());
            q.pop();
        }
    }
};