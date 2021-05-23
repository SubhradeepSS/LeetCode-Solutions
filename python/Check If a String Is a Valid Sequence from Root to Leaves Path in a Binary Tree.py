# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidSequence(self, root, arr):
        """
        :type root: TreeNode
        :type arr: List[int]
        :rtype: bool
        """
        n=len(arr)
    
        def f(node,i):
            if node == None:
                return n==0

            if i==n-1 and node.left==None and node.right==None and node.val==arr[i]:
                return True

            return i<n and node.val==arr[i] and (f(node.left,i+1) or f(node.right,i+1))
        
        return f(root,0)