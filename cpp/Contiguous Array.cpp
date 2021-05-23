class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> a(nums.size());
        for(int i=0;i<nums.size();i++)
            a[i]=(nums[i]==0?-1:1);
        unordered_map<int,int> mp;
        int max=0;
        int sum=0;
        int n=a.size();
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum==0)
                max=i+1;
            if(mp.find(sum+n)!=mp.end()){
                if(i-mp[sum+n]>max)
                    max=i-mp[sum+n];
            }
            else
            mp[sum+n]=i;
        }
        return max;
    }
};