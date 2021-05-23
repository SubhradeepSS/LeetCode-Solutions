class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0||m==n)
            return m;
        int x=log(m+1)/log(2);
        int y=log(n)/log(2);
        
        if(x!=y)
            return 0;
        int ans=m;
        for(long long int i=m+1;i<=n;i++)
            ans&=i;
        return ans;
    }
};