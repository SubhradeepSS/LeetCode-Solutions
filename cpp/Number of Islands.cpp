class Solution {
public:
    vector<vector<bool>> v;
    bool safe(int R,int C,int i,int j,vector<vector<char>>& grid){
        return (
            i>=0&&j>=0&&i<R&&j<C&&!v[i][j]&&(grid[i][j]=='1')
        );
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        v[i][j]=true;
        static int R[]={-1,0,0,1};
        static int C[]={0,-1,1,0};
        for(int k=0;k<4;k++){
            if(safe(grid.size(),grid[0].size(),i+R[k],j+C[k],grid))
                dfs(grid,i+R[k],j+C[k]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(),c,count=0;
        if(r)
            c=grid[0].size();
        v=vector<vector<bool>>(r,vector<bool>(c,false));
        //memset(v,0,sizeof(v));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'&&!(v[i][j])){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};