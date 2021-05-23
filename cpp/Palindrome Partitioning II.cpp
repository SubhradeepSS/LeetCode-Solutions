class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        bool p[n][n];
        int c[n];
        for(int i=0;i<n;i++)
            p[i][i]=true;
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(l==2)
                    p[i][j]=(s[i]==s[j]);
                else
                    p[i][j]=(s[i]==s[j]&&p[i+1][j-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(p[0][i])
                c[i]=0;
            else{
                c[i]=INT_MAX;
                for(int j=0;j<i;j++){
                    if(p[j+1][i]&&c[j]+1<c[i])
                        c[i]=1+c[j];
                }
            }
        }
        return c[n-1];
    }
};