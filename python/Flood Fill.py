class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        R=len(image)
        C=len(image[0])
        OLD=image[sr][sc]
        visited=[[False for _ in range(C)] for __ in range(R)]
        
        def safe(i,j):
            return i>=0 and j>=0 and i<R and j<C and image[i][j]==OLD and visited[i][j]==False
        
        def util(r,c):
            if safe(r,c):
                image[r][c]=newColor
                visited[r][c]=True
                util(r,c-1)
                util(r,c+1)
                util(r-1,c)
                util(r+1,c)
            else:
                return
        
        util(sr,sc)
        
        return image