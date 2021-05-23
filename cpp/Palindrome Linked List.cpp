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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode *t=head;
        stack<int> s;
        while(t){
            s.push(t->val);
            t=t->next;
        }
        t=head;
        while(t){
            if(t->val!=s.top())
                return false;
            s.pop();
            t=t->next;
        }
        return true;
    }
};