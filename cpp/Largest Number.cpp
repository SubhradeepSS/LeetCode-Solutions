bool f(int a,int b){
    string a_s=to_string(a),b_s=to_string(b);
    return a_s+b_s>b_s+a_s;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool all_zero=true;
        for(int i:nums){
            if(i!=0){
                all_zero=false;
                break;
            }
        }
        if(all_zero)
            return "0";
        sort(nums.begin(),nums.end(),f);
        string ans="";
        for(int i:nums)
            ans += to_string(i);
        return ans;
    }
};