/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void util(TreeNode* root){
        if(!root)
            return;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        while(curr){
            if(curr->left==NULL)
               { v.push_back(curr->val);
                curr=curr->right;}
            else{
                prev=curr->left;
                while(prev->right&&prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                        prev->right=curr;
                        curr=curr->left;
                    }
                    else{
                        prev->right=NULL;
                        v.push_back(curr->val);
                        curr=curr->right;
                    }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
            util(root);
        return v;
    }
};