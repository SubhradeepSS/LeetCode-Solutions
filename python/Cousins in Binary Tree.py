# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        mp={}
        q=[]
        q.append(root)
        mp[root.val]=(-1,0)
        
        while q:
            top=q[0]
            q.pop(0)
            
            if top.left:
                q.append(top.left)
                mp[top.left.val]=(top.val,mp[top.val][1]+1)
            if top.right:
                q.append(top.right)
                mp[top.right.val]=(top.val,mp[top.val][1]+1)
        
        a,b=mp[x],mp[y]
        
        return a[1]==b[1] and a[0]!=b[0]