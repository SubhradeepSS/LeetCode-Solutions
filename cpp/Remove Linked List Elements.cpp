/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *t=head,*prev=nullptr;
        while(t){
            if(t->val==val){
                if(prev==nullptr)
                    head=t->next;
                else
                    prev->next=t->next;
            }
            else
                prev=t;
            t=t->next;
        }
        return head;
    }
};