class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> prime(n+1, true);
        for(int i=2; i*i<=n; i++){
            for(int j=i*2;j<=n;j+=i){
                prime[j]=false;
            }
        }
        for(int i=2;i<n;i++){
            ans+=prime[i];
        }
        return ans;
    }
};