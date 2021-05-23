# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        v = []
        curr = head
        while curr:
            v.append(curr.val)
            curr = curr.next
        
        v.sort()
        i = 0
        curr = head
        while curr:
            curr.val = v[i]
            i += 1
            curr = curr.next
        return head