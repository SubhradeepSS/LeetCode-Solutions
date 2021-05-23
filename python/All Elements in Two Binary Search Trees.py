# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        l1, l2 = [], []
        
        def traverse(node, l):
            if not node:
                return
            
            traverse(node.left, l)
            
            l.append(node.val)
            
            traverse(node.right, l)
            
        traverse(root1, l1)
        traverse(root2, l2)
        
        ans = []
        
        i,j = 0,0
        
        while i<len(l1) and j<len(l2):
            if l1[i] < l2[j]:
                ans.append(l1[i])
                i += 1
            else:
                ans.append(l2[j])
                j += 1
        
        while i<len(l1):
            ans.append(l1[i])
            i += 1
        
        while j<len(l2):
            ans.append(l2[j])
            j += 1
        
        return ans