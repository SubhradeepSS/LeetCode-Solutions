# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        q = [(root,0)]
        ans = 1
        
        while q:
            left,l = q[0]
            right,r = q[-1]
            
            ans = max(r-l+1,ans)
            
            curr = len(q)
            
            while curr:
                top,level = q[0]
                
                if top.left:
                    q.append((top.left,2*level+1))
                if top.right:
                    q.append((top.right,2*level+2))
                
                q.pop(0)
                curr -= 1
        
        return ans