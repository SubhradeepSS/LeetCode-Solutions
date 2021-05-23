# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res=-float('inf')
        
        def util(node):
            if not node:
                return 0
            
            l=util(node.left)
            r=util(node.right)
            m1 = max(l,r)
            m2 = max(m1+node.val,node.val)
            m3 = max(m2,l+r+node.val)
            self.res = max(self.res,m3)
            return m2
        
        util(root)
        return self.res
            