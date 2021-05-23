class Solution {
public:
    int maxCoins(vector<int>& nums) {

        vector<int> v=nums;
        v.insert(v.begin(),1);
        v.push_back(1);
                    
        int n=v.size();
        int dp[n][n];
        
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        
        for(int l=2;l<n;l++){
            for(int i=1;i<n-l+1;i++){
                int j=i+l-1;
                dp[i][j]=INT_MIN;
                
                for(int k=i;k<j;k++){
                    dp[i][j]=max(dp[i][j], dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
                }
            }
        }
        return dp[1][n-1];
    }
};