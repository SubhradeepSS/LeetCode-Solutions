# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x, y):
#        """
#        :type x : int, y : int
#        :rtype int
#        """
#
#    def dimensions:
#        """
#        :rtype list[]
#        """

class Solution(object):
    def leftMostColumnWithOne(self, binaryMatrix):
        """
        :type binaryMatrix: BinaryMatrix
        :rtype: int
        """
        l=binaryMatrix.dimensions()
        n,m=l[0],l[1]
        
        r,c=0,m-1
        ans=-1
        while r<n and c>=0:
            if binaryMatrix.get(r,c)==1:
                ans=c
                c-=1
            else:
                r+=1
        return ans
            