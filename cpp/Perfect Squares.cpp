class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=i;
        
        for(int i=2;i<=n;i++){
            for(int x=1;x*x<=i;x++)
            {
                int t=x*x;
                if(t>i)
                    break;
                dp[i]=min(dp[i],1+dp[i-t]);
            }
        }
        return dp[n];
    }
};