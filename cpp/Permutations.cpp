class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> n=nums;
        vector<vector<int>> v;
        sort(n.begin(),n.end());
        do{
            v.push_back(n);
        }while(next_permutation(n.begin(),n.end()));
        return v;
    }
};