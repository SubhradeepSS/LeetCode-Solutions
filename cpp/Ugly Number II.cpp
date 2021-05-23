class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=0,i3=0,i5=0;
        int m2=2,m3=3,m5=5;
        
        int dp[n];
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            dp[i]=min(m2,min(m3,m5));
            if(dp[i]==m2){
                i2++;
                m2=2*dp[i2];
            }
            if(dp[i]==m3){
                i3++;
                m3=3*dp[i3];
            }
            if(dp[i]==m5){
                i5++;
                m5=5*dp[i5];
            }
        }
        return dp[n-1];
    }
};