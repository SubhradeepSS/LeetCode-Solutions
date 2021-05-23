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
    int v,c=0;
    void util(TreeNode* node,int k){
        if(!node||c>k)
            return;
        util(node->left,k);
        c++;
        if(c==k)
        {
            v=node->val;
            return;
        }
        util(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        util(root,k);
        return v;
    }
};