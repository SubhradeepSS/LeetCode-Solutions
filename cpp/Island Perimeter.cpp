class Solution {
public:
    int count;
    vector<pair<int,int>> ones;
    int dr[4]={-1,0,0,1};
    int dc[4]={0,-1,1,0};
    
    bool valid(vector<vector<int>>& grid,int r,int c){
        return (
          r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&grid[r][c]==1 
        );
    }
    
    int ans_f(vector<vector<int>>& grid){
        for(auto p:ones){
            for(int k=0;k<4;k++){
                int nx=p.first+dr[k],ny=p.second+dc[k];
                if(valid(grid,nx,ny))
                    count--;
            }
        }
        
        return count;
    }
    
    bool safe(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& vis){
        return (
          r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&grid[r][c]==1&&!vis[r][c]  
        );
    }
    
    void solve(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& vis){
        count+=4;
        ones.push_back(make_pair(r,c));
        
        vis[r][c]=true;
        
        for(int k=0;k<4;k++){
            if(safe(grid,r+dr[k],c+dc[k],vis))
                solve(grid,r+dr[k],c+dc[k],vis);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        count=0;
        ones.clear();
        
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    solve(grid,i,j,vis);
                    return ans_f(grid);
                }         
            }
        }
        
        return 0;
    }
};