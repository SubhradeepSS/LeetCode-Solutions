class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m=len(matrix)
        n=len(matrix[0])
        r=0
        c=0
        for i in range(m):
            for j in range(n):
                if i==0 and matrix[i][j]==0:
                    r=1
                if j==0 and matrix[i][j]==0:
                    c=1
                if matrix[i][j]==0:
                    matrix[0][j]=0
                    matrix[i][0]=0
        
        for i in range(1,m):
            for j in range(1,n):
                if matrix[0][j]==0 or matrix[i][0]==0:
                    matrix[i][j]=0
        
        if r==1:
            for i in range(n):
                matrix[0][i]=0
        if c==1:
            for i in range(m):
                matrix[i][0]=0