class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        d={}
        m=len(board)
        n=len(board[0])
        for i in range(m):
            for j in range(n):
                d[(i,j)]=board[i][j]
        
        def safe1(r,c):
            return r>=0 and c>=0 and r<m and c<n and board[r][c]==1
        
        dr=[-1,-1,-1,0,0,1,1,1]
        dc=[-1,0,1,-1,1,-1,0,1]
        
        def count1(r,c):
            count_1=0
            for k in range(8):
                if safe1(r+dr[k],c+dc[k]):
                    count_1+=1
            return count_1
        
        for i in range(m):
            for j in range(n):
                count_1=count1(i,j)
                if board[i][j]==0 and count_1==3:
                    d[(i,j)]=1
                elif board[i][j]==1:
                    if count_1>3 or count_1<2:
                        d[(i,j)]=0
        
        for i in range(m):
            for j in range(n):
                board[i][j]=d[(i,j)]