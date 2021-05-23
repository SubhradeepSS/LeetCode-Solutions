class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ans++;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(l==2){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=(dp[i+1][j-1]&&s[i]==s[j]);
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};