/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* getnextright(Node *p){
        Node *t=p->next;
        while(t){
            if(t->left)
                return t->left;
            if(t->right)
                return t->right;
            t=t->next;
        }
        return NULL;
    }
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node *p=root;
        while(p){
            Node *q=p;
            while(q){
                if(q->left){
                    if(q->right){
                        q->left->next=q->right;
                        q->right->next=getnextright(q);
                    }
                    else{
                        q->left->next=getnextright(q);
                    }
                }
                else if(q->right)
                    q->right->next=getnextright(q);
                q=q->next;
            }
            if(p->left)
                p=p->left;
            else if(p->right)
                p=p->right;
            else p=getnextright(p);
        }
        return root;
    }
};