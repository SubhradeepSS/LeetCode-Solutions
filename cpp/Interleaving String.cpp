class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       int m=s1.size(),n=s2.size();
        if(m+n!=s3.size())
            return false;
        bool t[m+1][n+1];
        t[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0&&j>0)
                    t[i][j]=((s2[j-1]==s3[j-1])?t[i][j-1]:false);
                else if(j==0 && i>0)
                    t[i][j]=((s1[i-1]==s3[i-1])?t[i-1][j]:false);
                else if(i>0&&j>0)
                {
                    if((t[i-1][j]&&s3[i+j-1]==s1[i-1])||(t[i][j-1]&&s3[i+j-1]==s2[j-1]))
                        t[i][j]=true;
                    else
                        t[i][j]=false;
                }
             
            }
        }
        return t[m][n];
    }
};