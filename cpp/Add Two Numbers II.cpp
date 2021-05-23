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
    ListNode* reverse(ListNode *head){
    ListNode *curr=head,*prev=NULL,*next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        
    first=reverse(first);
    second=reverse(second);
    int sum,carry=0;
    ListNode *result,*prev=NULL;
    while(first||second){
        sum=carry+(first?first->val:0)+(second?second->val:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        ListNode *t=new ListNode(sum);
        if(!prev){
            result=t;
        }
        else{
            prev->next=t;
        }
        prev=t;
        if(first)
            first=first->next;
        if(second)
            second=second->next;
    }
    if(carry>0)
        prev->next=new ListNode(carry);
    return reverse(result);
    }
};