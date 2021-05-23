class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r=A.size(),c=A[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=!A[i][c-j-1];
            }
        }
        return ans;
    }
};