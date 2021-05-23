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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode *t=head;
        while(t){
            if(s.find(t)!=s.end())
                return t;
            s.insert(t);
            t=t->next;
        }
        return t;
    }
};