class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> v(matrix.size());
        for(int i=0;i<matrix.size();i++)
            v[i]=vector<int>(matrix[i].size());
        for(int i=0;i<matrix.size();i++)
            v[i][0]=matrix[i][0]-'0';
        for(int i=0;i<v[0].size();i++)
            v[0][i]=matrix[0][i]-'0';
        
        for(int i=1;i<v.size();i++){
            for(int j=1;j<v[i].size();j++){
                if(matrix[i][j]=='1')
                    v[i][j]=min(v[i-1][j-1],min(v[i-1][j],v[i][j-1]))+1;
                else
                    v[i][j]=0;
            }
        }
        int ans=*max_element(v[0].begin(),v[0].end());
        for(int i=1;i<v.size();i++)
            ans=max(ans,*max_element(v[i].begin(),v[i].end()));
        return ans*ans;
    }
};