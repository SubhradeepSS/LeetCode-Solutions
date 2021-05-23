# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ''
        s=''
        q=[]
        q.append(root)
        s+=str(root.val)+','
        while len(q)>0:
            node=q[0]
            if node.left is not None:
                s+=str(node.left.val)+','
                q.append(node.left)
            else:
                s+='n'+','
            if node.right is None:
                s+='n'+','
            else:
                q.append(node.right)
                s+=str(node.right.val)+','
            q.pop(0)
        ans=s[:len(s)-1]
        return ans
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data)==0:
            return None
        if data[0]=='-':
            u=0
            i=1
            while i<len(data) and data[i]!=',':
                u=u*10+int(data[i])
                i+=1
            root=TreeNode(u)
            root.val*=-1
            
        else:
            i=0
            u=0
            while i<len(data) and data[i]!=',':
                u=u*10+int(data[i])
                i+=1
            root=TreeNode(u)
        i+=1
        q=[]
        q.append(root)
        n=len(data)
        while i<len(data):
            node=q[0]
            
            if data[i]==',':
                i+=1
            
            if i>=n:
                break
            
            f=1
            if data[i]=='-':
                i+=1
                f=-1
            
            if i>=n:
                break
            
            if data[i]=='n':
                node.left=None
            else:
                u=0
                while i<n and data[i]!=',':
                    u=u*10+int(data[i])
                    i+=1
                node.left=TreeNode(f*u)
                q.append(node.left)
                
            i+=1
            f=1
            
            if i>=n:
                break
            
            if data[i]==',':
                i+=1
                
            if i>=n:
                break 
            
            if data[i]=='-':
                i+=1
                f=-1
            
            if i>=n:
                break
            
            if data[i]=='n':
                node.right=None
            else:
                u=0
                while i<n and data[i]!=',':
                    u=u*10+int(data[i])
                    i+=1
                node.right=TreeNode(f*u)
                q.append(node.right)
            i+=1
            
            if i>=n:
                break
            
            q.pop(0)
            
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))