class Solution {
public:
    bool f(int r,int c,int w,string word,vector<vector<char>>& board){
        if(w==word.length())
            return true;
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||word[w]!=board[r][c])
            return false;
        char t=board[r][c];
        board[r][c]='0';
        if(f(r+1,c,w+1,word,board)||f(r-1,c,w+1,word,board)||f(r,c+1,w+1,word,board)||f(r,c-1,w+1,word,board)){
            board[r][c]=t;
            return true;
        }
        board[r][c]=t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]==word[0]&&f(i,j,0,word,board))
                    return true;
        return false;
    }
};