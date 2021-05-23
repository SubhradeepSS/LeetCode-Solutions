class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> prev=cells;
        const int n=8;
        vector<int> ans(n);
        
        for(int i=0;i<min(14,N);i++){
            ans[0]=0;
                for(int i=1;i<n-1;i++){
                    ans[i]=!(prev[i-1]^prev[i+1]);
                }
                ans[n-1]=0;
                prev=ans;
        }
        if(N<14)
            return ans;
        
        N%=14;
        
        while(N--){
            // for(int i=0;i<n;i++)
            //     cout<<prev[i]<<" ";
            // cout<<endl;
            
            ans[0]=0;
            for(int i=1;i<n-1;i++){
                ans[i]=!(prev[i-1]^prev[i+1]);
            }
            ans[n-1]=0;
            prev=ans;
            
        }
        
        return ans;
    }
};