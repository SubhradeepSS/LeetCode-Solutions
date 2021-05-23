class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size();

        if(k==1)
        {
            for(int i=0;i<n;i++)
                v.push_back(nums[i]);
            return v;
        }
        int p=0,q=k-1,t=p,max=nums[q];
        while(q<n){
            if(nums[p]>max)
                max=nums[p];
            p++;
            
            if(q==p&&p!=n){
                v.push_back(max);
                q++;
                p=++t;
                if(q<n)
                    max=nums[q];
            }
        }
        return v;
    }
};