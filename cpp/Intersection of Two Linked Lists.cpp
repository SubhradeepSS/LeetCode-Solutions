/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode *t=headA;
        while(t){
            mp[t]++;
            t=t->next;
        }
        t=headB;
        while(t){
            if(mp[t]==1)
                return t;
            t=t->next;
        }
        return NULL;
    }
};