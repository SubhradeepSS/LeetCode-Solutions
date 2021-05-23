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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* ans=new ListNode(min(l1->val,l2->val));
        ListNode* head=ans;
        if(l2->val>l1->val)
            l1=l1->next;
        else
            l2=l2->next;
        while(l1&&l2){
            if(l1->val<l2->val){
                ans->next=new ListNode(l1->val);
                l1=l1->next;
                ans=ans->next;
            }
            else{
                ans->next=new ListNode(l2->val);
                l2=l2->next;
                ans=ans->next;
            }
        }
        while(l1){
            ans->next=new ListNode(l1->val);
                l1=l1->next;
            ans=ans->next;
        }
        while(l2){
          ans->next=new ListNode(l2->val);
                l2=l2->next; 
            ans=ans->next;
        }
        return head;
    }
};