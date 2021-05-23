class Solution {
public:
    bool s(int i,int j,int R,int C,vector<vector<bool>>& safe,vector<vector<char>>& board){
        return (
            i>=0&&j>=0&&i<R&&j<C&&safe[i][j]==false&&board[i][j]=='O'
        );
    }
    
    void f(vector<vector<char>>& board,int r,int c,vector<vector<bool>>& safe,int R,int C){
        safe[r][c]=true;
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        for(int k=0;k<4;k++){
            if(s(r+dr[k],c+dc[k],R,C,safe,board))
                f(board,r+dr[k],c+dc[k],safe,R,C);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int R=board.size();
        if(R==0)
            return;
        int C=board[0].size();
        if(C==0)
            return;
        vector<vector<bool>> safe(R,vector<bool>(C,false));
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         if(board[i][j]=='X')
        //             safe[i][j]=true;
        //         else if(i==0||j==0||i==R-1||j==C-1)
        //             safe[i][j]=true;
        //     }
        // }
        for(int i=0;i<C;i++){
            if(board[0][i]=='O')
                f(board,0,i,safe,R,C);
        }
        for(int i=1;i<R;i++){
            if(board[i][C-1]=='O')
                f(board,i,C-1,safe,R,C);
        }
            
        for(int i=0;i<C-1;i++){
            if(board[R-1][i]=='O')
                f(board,R-1,i,safe,R,C);
        }
            
        for(int i=R-2;i>=1;i--){
            if(board[i][0]=='O')
                f(board,i,0,safe,R,C);
        }
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i][j]=='O'&&!safe[i][j])
                    board[i][j]='X';
                cout<<safe[i][j]<<" ";
            }
        }
    }
};