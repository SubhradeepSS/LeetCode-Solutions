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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s,c=0;
        ListNode* r,*prev=NULL,*t;
        while(l1||l2){
            s=(l1?l1->val:0)+(l2?l2->val:0)+c;
            c=(s>=10)?1:0;
            s%=10;
            t=new ListNode(s);
            if(!prev)
                r=t;
            else
                prev->next=t;
            prev=t;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(c>0)
            prev->next=new ListNode(c);
        return r;
    }
};