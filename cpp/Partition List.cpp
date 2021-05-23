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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode* t=head;
        vector<int> util1;
        vector<int> util2;
        while(t){
            if(t->val<x)
                util1.push_back(t->val);
            else
                util2.push_back(t->val);
            t=t->next;
        }
        t=head;
        for(int x:util1){
            t->val=x;
            t=t->next;
        }
        for(int x:util2){
            t->val=x;
            t=t->next;
        }
        return head;
    }
};