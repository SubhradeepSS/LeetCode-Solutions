# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def util(node):
            if not node:
                return None

            if node.val==p.val or node.val==q.val:
                return node

            l=util(node.left)
            r=util(node.right)
            
            if l and r:
                return node
            
            return l if l else r
        return util(root)