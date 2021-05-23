"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head:
            return None
        
        curr = head
        
        while curr.next or curr.child:
            if not curr.next:
                curr.next = curr.child
                curr.child.prev = curr
                curr.child = None
                
            elif curr.next and curr.child:
                Next = curr.next
                
                curr.next = curr.child
                curr.child.prev = curr
                curr.child = None
                
                temp = curr.next
                
                while temp.next:
                    temp = temp.next
                
                temp.next = Next
                Next.prev = temp
            
            curr = curr.next
        
        return head